							/* Main routines */
#include "dpic.h"

extern boolean inarc (double, double, double, double);
extern double posangle (postype, postype);
extern double qenv (primitive *, int, double);
extern double venv (primitive *, int);
extern int lspec (int);
extern postype affang (postype, postype);
extern postype affine (double, double, postype, postype);
extern primitive *(findenv (primitive *));
extern void checkjust (nametype *, boolean *, boolean *, boolean *, boolean *);
extern void getlinespec (primitive *, int *, primitive **);
extern void initnesw (void);
extern void markerror (int);
extern void neswline (primitive *);
extern void nesw (primitive *);
extern void neswstring (primitive *, double, double);
extern void newbuf (fbuffer **);
extern void preproduce (int);
extern void wpos (postype);

#ifdef DDEBUG
extern int ordp (void *);
extern void logaddr (fbuffer *);
extern void logchar (Char);
extern void snapname (Char *, chbufinx, chbufinx);
extern void wlogfl (Char *, double, int);
extern void wrbufaddr (fbuffer *, int);
extern void wrbuf (fbuffer *, int, int);
arg *currentmacro;		    /* last-found macro                   */
#endif

							/* the parser                         */
#include "dpic.tab.h"

							/* Lexical tables                     */
symbol entrytv[ordMAXCH + 1] = {
#include "entrytv.h"
};

lxinx entryhp[ordMAXCH + 1] = {
#include "entryhp.h"
};

symbol lxtv[lxmax + 1] = {
#include "lxtv.h"
};

lxinx lxhp[lxmax + 1] = {
#include "lxhp.h"
};

lxinx lxnp[lxmax + 1] = {
#include "lxnp.h"
};

Char lxch[lxmax + 1] = {
#include "lxch.h"
};

int P_argc;
char **P_argv;

							/* Parser variables */
int oldsymb;			    /* last lexical symbol                */
arg *macros, *args, *freearg;	/* macro and macro argument list      */

#ifdef DDEBUG
int
odp (void *p) {
  return (ordp (p) % 10000);
}
#endif

/*--------------------------------------------------------------------*/
							/* Numerical utilities: */
double
principal (double x, double r) {
  while (x > r) {
    x -= 2 * r;
  }
  while (x < (-r)) {
    x += 2 * r;
  }
  return x;
}

double
Max (double x, double y) {
  if (y > x) {
    return y;
  } else {
    return x;
  }
}

double
Min (double x, double y) {
  if (y < x) {
    return y;
  } else {
    return x;
  }
}

int
Floor (double x) {
  if ((x >= 0) || (((long) x) == x)) {
    return ((long) x);
  } else {
    return (((long) x) - 1);
  }
}

int
Ceil (double x) {
  if ((x < 0) || (((long) x) == x)) {
    return ((long) x);
  } else {
    return (((long) x) + 1);
  }
}

boolean
isdistmax (double x) {
  return (fabs ((x / distmax) - 1.0) < 1e-6);
}

boolean
ismdistmax (double x) {
  return (fabs ((x / mdistmax) - 1.0) < 1e-6);
}

double
datan (double y, double x) {
  double r;

  r = atan2 (y, x);
  return r;
}

							/* like hypot()                     */
double
linlen (double x, double y) {
  double xm, ym;
							/* linlen := sqrt( x*x + y*y ) */
  if (fabs (x) > fabs (y)) {
    xm = fabs (x);
    ym = y / xm;
    return (xm * sqrt (1.0 + (ym * ym)));
  }
  if (y == 0.0) {
    xm = 0.0;
    ym = 0.0;
  } else {
    xm = fabs (y);
    ym = x / xm;
  }
  return (xm * sqrt (1.0 + (ym * ym)));
}

/*--------------------------------------------------------------------*/
							/* Some common utilities */ 
							/* Substrings common to one or more postprocessor */
void
controls (void) {
  printf ("\n ..controls ");
}

void
wrand (void) {
  printf (" and ");
}

void
ddot (void) {
  printf ("\n ..");
}

void
ddash (void) {
  printf ("\n --");
}

							/* Arrowhead location or EMPTY in bit 4 ... */
int
ahlex (int atyp) {
  return (atyp >> 3);
}

							/* Arrowhead number in lower 3 bits */
int
ahnum (int atyp) {
  return (atyp & 7);
}

							/* Store arrowhead location or EMPTY */
int
pahlex (int atyp, int alex) {
  return ((atyp & 7) + (alex * 8));
}

							/* Store arrowhead number */
int
pahnum (int atyp, int anum) {
  return (((atyp >> 3) * 8) + (anum & 7));	/* 0 < anum < 7 */
}

							/* Output float with trailing zeros trimmed in
                               the fraction part */
void
wfloat (FILE ** iou, double y) {
  char buf[CHBUFSIZ];
  int i;
  if (fabs (y) >= distmax)
    fprintf (*iou, "%.6g", y);
  else {
    if (y >= 0.0)
      snprintf (buf, CHBUFSIZ, "%24.6f", floor (1000000 * y + 0.5)/1000000.0);
    else
      snprintf (buf, CHBUFSIZ, "%24.6f", -floor (-1000000 * y + 0.5)/1000000.0);
    for (i = 23; buf[i] == '0';)
      i--;
    if (buf[i] == '.')
      buf[i] = (char) 0;
    else
      buf[i + 1] = (char) 0;
    for (; (i >= 0) && (buf[i] != ' ');)
      i--;
    fprintf (*iou, "%s", &buf[i + 1]);
    }
}

							/* Output a string of characters from a strptr*/
void
wstring (FILE ** iou, nametype * p) {
  int i, FORLIM;

  if (p == NULL) {
    return;
  }
  if (p->segmnt != NULL) {
    FORLIM = p->seginx + p->len;
    for (i = p->seginx; i < FORLIM; i++) {
      putc (p->segmnt[i], *iou);
    }
  }
}

							/* Store ljust rjust in bits 1, 2 and
                                     below above in bits 3, 4 */
void
setjust (nametype * tp, int v) {
  int i;

  if (tp == NULL) {
    return;
  }
  i = (long) floor (tp->val + 0.5);
  switch (v) {

  case XLrjust:
    tp->val = ((i >> 2) * 4.0) + 1;
    break;

  case XLljust:
    tp->val = ((i >> 2) * 4.0) + 2;
    break;

  case XLbelow:
    tp->val = ((i >> 4) * 16.0) + (i & 3) + 4;
    break;

  case XLabove:
    tp->val = ((i >> 4) * 16.0) + (i & 3) + 8;
    break;

  case XLcenter:
    tp->val = (i >> 4) * 16.0;
    break;
  }
}

							/* Position P2 = (a*P1 + b*P2)/c (for arrows) */
void
pprop (postype p1, postype * p2, double a, double b, double c) {
  if (c != 0.0) {
    p2->xpos = ((a * p1.xpos) + (b * p2->xpos)) / c;
    p2->ypos = ((a * p1.ypos) + (b * p2->ypos)) / c;
  }
}

							/* Test (bit 4) if this segment has a parent */
boolean
isthen (primitive * pr) {
  if (pr == NULL) {
    return false;
  } else {
    return (((pr->spec >> 3) & 1) != 0);
  }
}

							/* Draw arc in segments for arc arrowheads */
void
popgwarc (postype Ctr, double radius, double startangle, double endangle,
	  double ccw) {
  int narcs, i;
  double c, s, cc, ss, arcangle;
  postype Q;

  if ((ccw > 0) && (endangle < startangle)) {
    endangle += 2 * pi;
  } else if ((ccw < 0) && (endangle > startangle)) {
    endangle -= 2 * pi;
  }
  narcs = (long) (1.0 + (fabs (endangle - startangle) / pi));
  arcangle = (endangle - startangle) / narcs;
  c = cos (arcangle / 2);
  s = sin (arcangle / 2);
  cc = (4 - c) / 3;
  if (s != 0.0) {
    ss = (1.0 - (c * cc)) / s;
  } else {
    ss = 0.0;
  }
  for (i = 1; i <= narcs; i++) {
    controls ();
    Q.xpos = cos (startangle + ((i - 0.5) * arcangle));
    Q.ypos = sin (startangle + ((i - 0.5) * arcangle));
    wpos (affine (radius * cc, -radius * ss, Ctr, Q));
    wrand ();
    wpos (affine (radius * cc, radius * ss, Ctr, Q));
    ddot ();
    Q.xpos = Ctr.xpos + (radius * cos (startangle + (i * arcangle)));
    Q.ypos = Ctr.ypos + (radius * sin (startangle + (i * arcangle)));
    wpos (Q);
  }
}

/*--------------------------------------------------------------------*/

							/* We are finished */
void
epilog (void) {
  Free (chbuf);
}

void
consoleflush (void) {
}

							/* Unrecoverable errors */
void
fatal (int t) {
  if (t != 0) {
    fprintf (errout, " *** dpic: ");
  }
  switch (t) {
  case 0:
							/* blank case */
    break;
  case 1:
    fprintf (errout, "input file not readable\n");
    break;
  case 2:
    fprintf (errout, "copy file not readable\n");
    break;
  case 3:
    fprintf (errout, "maximum error count exceeded\n");
    break;
  case 4:
    fprintf (errout,
	     "character buffer overflow: \"CHBUFSIZ\" (%ld) exceeded\n",
	     (long) CHBUFSIZ);
    break;
  case 5:
    fprintf (errout, "end of file encountered on input\n");
    break;
  case 8:
    fprintf (errout, "error recovery abandoned\n");
    break;
  case 9:
    fprintf (errout, "subscript out of range\n");
    break;
  case 10:
    fprintf (errout, "failed to open sprintf output file\n");
    break;
  default:
    fprintf (errout, "unclassified fatal error\n");
    break;
  }

  epilog ();
  if (input != NULL)
    fclose (input);
  if (output != NULL)
    fclose (output);
  if (errout != NULL)
    fclose (errout);
#ifdef DDEBUG
  if (log_ != NULL)
    fclose (log_);
#endif
  exit (EXIT_FAILURE);
}

#ifdef DDEBUG
							/* The log file is only for debugging */
void
openlogfile (void) {
  if (log_ != NULL) {
    log_ = freopen ("dpic.log", "w", log_);
  } else {
    log_ = fopen ("dpic.log", "w");
  }
  if (log_ == NULL) {
    fatal (1);
  }
  fprintf (log_, "Dpic log file\n");
  fflush (log_);
  if (oflag <= 0) {
    oflag = 1;
  }
}
#endif

							/* Check if a file is accessible */
int
checkfile (Char * ifn, boolean isverbose) {
  int cf;
  int i = 0, j = FILENAMELEN;

  while (j > i) {
    if (ifn[j - 1] == ' ') {
      j--;
    } else {
      i = j;
    }
  }
  if (j < FILENAMELEN) {
    j++;
  } else {
    fatal (1);
  }
  ifn[j - 1] = '\0';
  cf = access (ifn, 4);
  if (!(isverbose && (cf != 0))) {
    return cf;
  }
  fprintf (errout, " *** dpic: Searching for file \"");
  for (i = 0; i <= (j - 2); i++) {
    putc (ifn[i], errout);
  }
  fprintf (errout, "\" returns %d\n", cf);
  return cf;
}

							/* Open the error stream */
void
openerror (void) {
  errout = stderr;
}

							/* Printable character */
boolean
isprint_ (Char ch) {
  return ((ch >= 32) && (ch <= 126));
}

							/* Output a character as printable */
void
wchar (FILE ** iou, Char c) {
  if (isprint_ (c)) {
    putc (c, *iou);
    return;
  }
  if (c == nlch) {
    putc ('\n', *iou);
    return;
  }
  if (c == crch) {
    fprintf (*iou, "\\r");
    return;
  }
  if (c == tabch) {
    fprintf (*iou, "\\t");
    return;
  }
  if (c < 32) {
    fprintf (*iou, "^%c", c + 64);
  } else {
    fprintf (*iou, "\\%d%d%d", (c >> 6) & 7, (c >> 3) & 7, c & 7);
  }
}

/*--------------------------------------------------------------------*/

							/* Initialize random number routine */
void
initrandom (void) {
  time_t seed;
  srandom (time (&seed));
}

							/* Store buffers on top of old-buffer stack */
void
disposebufs (fbuffer ** buf) {
  fbuffer *bu;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "\ndisposebufs");
    wrbufaddr (*buf, 1);
    putc ('\n', log_);
  }
#endif
  if ((*buf) == NULL) {
    return;
  }
  bu = *buf;
  while (bu->nextb != NULL) {
    bu = bu->nextb;
  }
  bu->nextb = freeinbuf;
  freeinbuf = *buf;
  *buf = NULL;
}

void
disposeargs (arg ** ar) {
  arg *aa;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "disposeargs[%d]\n", odp (*ar));
  }
#endif
  if ((*ar) == NULL) {
    return;
  }
  aa = *ar;
  disposebufs (&aa->argbody);
  while (aa->nexta != NULL) {
    aa = aa->nexta;
    disposebufs (&aa->argbody);
  }
  aa->nexta = freearg;
  freearg = *ar;
  *ar = NULL;
}

							/* End of macro found */
void
exitmacro (void) {
  arg *aa;
#ifdef DDEBUG
  int i;
  fbuffer *With;
  int FORLIM;
  if (debuglevel > 0) {
    fprintf (log_, " exitmacro ");
    if (currentmacro == NULL) {
    } else if (currentmacro->argbody == NULL) {
    } else if (currentmacro->argbody->carray != NULL) {
      With = currentmacro->argbody;
      FORLIM = -With->attrib;
      for (i = 1; i <= FORLIM; i++) { wchar (&log_, With->carray[i]); }
    }
    putc ('\n', log_);
    currentmacro = NULL;
  }
#endif
  aa = args;
  if (args != NULL) {
    args = args->highera;
  }
  disposeargs (&aa);
}

							/* Read a line from the input */
void
readline (FILE ** infname) {
  int ll, c;
  if (feof (*infname)) {
    inputeof = true;
    return;
  }
  c = ' ';
  for (ll = CHBUFSIZ - 1; inbuf->savedlen < ll;) {
    c = getc (*infname);
    if ((char) c == '\n')
      ll = inbuf->savedlen;
    else if ((char) c == '\r') {
      if ((char) (c = getc (*infname)) != '\n') {
	if (c != EOF)
	  ungetc (c, *infname);
	else if (inbuf->savedlen == 0) {
	  inputeof = true;
	  return;
	}
	c = '\n';
      }
      ll = inbuf->savedlen;
    } else if (c != EOF) {
      inbuf->savedlen++;
      inbuf->carray[inbuf->savedlen] = (char) c;
    } else if (inbuf->savedlen == 0) {
      inputeof = true;
      return;
    } else
      ll = inbuf->savedlen;
  }
  if ((ll == CHBUFSIZ - 1) && ((char) c != '\n') && (c != EOF)) {
    inbuf->savedlen++;
    inbuf->carray[inbuf->savedlen] = bslch;
  } else if (inbuf->carray[inbuf->savedlen] != bslch || lexstate != 2) {
    inbuf->savedlen++;
    inbuf->carray[inbuf->savedlen] = nlch;
  }
}

							/* Get the next line and set lexstate */
void
nextline (Char lastchar) {
  int i;
  fbuffer *With;
  int FORLIM;

  With = inbuf;
  With->readx = 1;
  With->savedlen = 0;
  do {
    if (savebuf != NULL) {
      readline (&copyin);
      if (inputeof) {
	inputeof = false;
	while (inbuf->prevb != NULL) {
	  inbuf = inbuf->prevb;
	}
	disposebufs (&inbuf);
	inbuf = savebuf;
	savebuf = NULL;
      }
    } else {
      if (!inputeof) {
	lineno++;
      }
      readline (&input);
    }
							/* Check for .PS, .PE, and zero length */
    With = inbuf;

    if (With->savedlen >= 1) {
      if (With->carray[1] == '.') {
	if (lexstate != 2) {
	  if ((With->savedlen >= 4) && (With->carray[2] == 'P')) {
	    if (savebuf != NULL) {
	      With->savedlen = 0;	/* skip .P* lines */
	    } else if ((With->carray[3] == 'F') || (With->carray[3] == 'S')) {
	      lexstate = 1;
	      With->readx = 4;
	    } else if (With->carray[3] == 'E') {
	      lexstate = 3;
	      With->readx = 4;
	    }
	  }
	} else if (lastchar != bslch) {
	  if ((With->savedlen < 4) || (With->carray[2] != 'P') ||
	      (savebuf != NULL)) {
	    With->savedlen = 0;	/* skip . lines */
	  } else if ((With->carray[3] == 'F') || (With->carray[3] == 'S')) {
	    lexstate = 1;
	    With->readx = 4;
	  } else if (With->carray[3] == 'E') {
	    lexstate = 3;
	    With->readx = 4;
	  } else {
	    With->savedlen = 0;
	  }
	}
      }
    }
							/* Dump the line if not between .PS and .PE */
    if ((lexstate == 0) && (!inputeof)) {
      With = inbuf;
      FORLIM = With->savedlen;
      for (i = 1; i < FORLIM; i++) {
	putchar (With->carray[i]);
      }
      if (With->carray[With->savedlen] != bslch) {
	putchar ('\n');
      }
      With->savedlen = 0;
    }
  } while (!((inbuf->savedlen > 0) || inputeof));
}

							/* Read the next char into ch, accounting for
                               strings and end of buffer */
void
inchar (void) {
  fbuffer *tp;
  boolean endofbuf;
  fbuffer *With;
  if (inbuf == NULL) {
#ifdef DDEBUG
    if (debuglevel == 2) {
      fprintf (log_, " new inbuf");
    }
#endif
    newbuf (&inbuf);
    inbuf->attrib = -1;
    topbuf = inbuf;
  }
#ifdef DDEBUG
  if (debuglevel == 2) {
    With = inbuf;
    fprintf (log_, "\ninchar");
    wrbufaddr (inbuf, 0);
    fprintf (log_, ": instr=%c readx=%d", instr ? 'T' : 'F', With->readx);
  }
#endif
  endofbuf = (inbuf->readx >= inbuf->savedlen);
  while (endofbuf) {
    With = inbuf;
    if ((With->readx < With->savedlen) || inputeof) {
      endofbuf = false;
    } else if (With->readx > With->savedlen) {	/* nil */
    } else if ((With->carray[With->readx] != bslch) || (With->nextb != NULL)) {
      endofbuf = false;
    } else if (instr) {
      if (With->savedlen < CHBUFSIZ) {
	With->savedlen++;
	With->carray[With->savedlen] = nlch;
      } else if (With->attrib > 0) {
	newbuf (&tp);
	tp->attrib = inbuf->attrib;
	tp->prevb = inbuf;
	tp->savedlen = 1;
	tp->carray[1] = nlch;
	With->nextb = tp;
      } else {
	With->readx--;
	With->carray[With->readx] = bslch;
	With->carray[With->savedlen] = nlch;
      }
      endofbuf = false;
    }
    if (endofbuf) {
      if (inbuf->nextb != NULL) {
	inbuf = inbuf->nextb;
      } else if (inbuf->attrib > 0) {	/* for buf */
#ifdef DDEBUG
	if (debuglevel == 2) {
	  fprintf (log_, " For detected, ");
	  logchar (ch);
	  putc (' ', log_);
	}
#endif
	inbuf->readx = 1;
	while (inbuf->prevb != NULL) {
	  inbuf = inbuf->prevb;
	  inbuf->readx = 1;
	}
	forbufend = true;
      } else {
#ifdef DDEBUG
	if (debuglevel == 2) {
	  fprintf (log_, " Not for, ");
	  logchar (ch);
	  putc (' ', log_);
	}
#endif
	while (inbuf->prevb != NULL) {
	  inbuf = inbuf->prevb;
	}
	if (inbuf->nextb != NULL) {
	  disposebufs (&inbuf->nextb);
	}
	if (inbuf->higherb != NULL) {
	  tp = inbuf->higherb;
	  disposebufs (&inbuf);
	  inbuf = tp;
	} else if (!inputeof) {
	  With = inbuf;
	  if ((With->savedlen < 1) || (inbuf != topbuf)) {
	    nextline (' ');
	  } else {
	    nextline (With->carray[With->savedlen]);
	  }
	}
      }
    }
  }
							/* This is not a loop */
  if (forbufend || inputeof) {
    ch = nlch;
  } else {
    With = inbuf;
    ch = With->carray[With->readx];
    With->readx++;
  }
#ifdef DDEBUG
  if (debuglevel == 2) {
    With = inbuf;
    fprintf (log_, " savedlen=%d ", With->savedlen);
    if (inputeof) {
      fprintf (log_, "inputeof ");
    }
    logchar (ch);
  }
#endif
}				/* inchar */

							/* skip to end of the current input line */
void
skiptoend (void) {
  boolean skip = true;
  fbuffer *With;
  while (skip) {
    if (inbuf == NULL) {
      skip = false;
      break;
    }
    With = inbuf;
    if (With->readx <= With->savedlen) {
      if (With->carray[With->readx] == nlch) {
	skip = false;
      } else if (With->carray[With->readx] == etxch) {
	exitmacro ();
      }
    }
    With->readx++;
    if (With->readx > With->savedlen) {
      if (inbuf->nextb != NULL) {
	inbuf = inbuf->nextb;
      } else {
	skip = false;
      }
    }
  }
}

							/* Move back in chbuf */
void
backup (void) {
  fbuffer *With;
  With = inbuf;
  With->readx--;
  ch = ' ';
}

/*--------------------------------------------------------------------*/

							/* Copy ch char into chbuf and get new ch */
void
pushch (void) {
  chbuf[chbufi] = ch;
  if (chbufi < CHBUFSIZ) {
    chbufi++;
  } else {
    fatal (4);
  }
							/* Leave 1 location free at the end of chbuf^ */
  inchar ();
}				/*pushch */

							/* Read complete line into chbuf */
void
readlatex (void) {
  while (ch != nlch) {
    pushch ();
  }
  newsymb = XLaTeX;
}

							/* Value of $+ */
int
argcount (arg * a) {
  int i = 0;
  if (a == NULL) {
    markerror (805);
  }
  while (a != NULL) {
    if (a->argbody != NULL) {
      i++;
    }
    a = a->nexta;
  }
  return i;
}

							/* Find the k-th argument */
arg *(findarg (arg * arlst, int k)) {
  arg *ar;
  int i = 1;
  int j;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "\nfindarg(");
    if (arlst == NULL) {
      fprintf (log_, "nil");
    } else {
      fprintf (log_, "%d", odp (arlst));
    }
    fprintf (log_, ",%d):", k);
  }
#endif
  if (k > 0) {
    ar = arlst;
  } else {
    ar = NULL;
  }
  j = k;
  while (i < j) {
    if (ar != NULL) {
      ar = ar->nexta;
      i++;
    } else {
      j = i;
    }
  }
#ifdef DDEBUG
  if (debuglevel > 0) {
    if ((i != k) || (ar == NULL)) {
      fprintf (log_, "not found\n");
    } else {
      wrbuf (ar->argbody, 2, 1);
    }
  }
#endif
  return ar;
}

Char *
trimname (Char * fn, int len) {
  static Char fnbuf[256];
  Char *cp = fnbuf;
  while (--len >= 0 && *fn && !isspace (*fn))
    *cp++ = *fn++;
  *cp = 0;
  return fnbuf;
}

							/* Start reading from file for copy "file" */
#ifndef SAFE_MODE
void
pointinput (nametype * txt) {
  int i;
  Char c = ' ';
  int FORLIM;
  if (txt == NULL) {
    return;
  }
  if (txt->segmnt == NULL) {
    return;
  }
  if (txt->len >= FILENAMELEN) {
    txt->len = FILENAMELEN - 1;
  }
  FORLIM = txt->len;
  for (i = 0; i < FORLIM; i++) {
    infname[i] = txt->segmnt[txt->seginx + i];
  }
  for (i = txt->len; i < FILENAMELEN; i++) {
    infname[i] = c;
  }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "Pointinput(segmnt %d, len %d) ", txt->seginx, txt->len);
    FORLIM = txt->len;
    for (i = 0; i < FORLIM; i++) {
      putc (infname[i], log_);
    }
    putc ('\n', log_);
  }
#endif
  if (savebuf != NULL) {
    markerror (853);
    return;
  }
  if (checkfile (infname, true) != 0) {
    markerror (859);
    return;
  }
  if (copyin != NULL) {
    copyin = freopen (trimname (infname, sizeof (mstring)), "r", copyin);
  } else {
    copyin = fopen (trimname (infname, sizeof (mstring)), "r");
  }
  if (copyin == NULL) {
    fatal (1);
  }
  backup ();
  ch = nlch;
  savebuf = inbuf;
  inbuf = NULL;
}

							/* Redirect output for print .. > "file" */
void
pointoutput (boolean create, nametype * txt, int *ier) {
  int i, FORLIM;
  if (txt == NULL) {
    *ier = 1;
    markerror (861);
    return;
  } else if (txt->segmnt == NULL) {
    *ier = 1;
    markerror (861);
    return;
  }
  *ier = 0;
  if (txt->len >= FILENAMELEN) {
    txt->len = FILENAMELEN - 1;
  }
  FORLIM = txt->len;
  for (i = 0; i < FORLIM; i++) {
    outfnam[i] = txt->segmnt[txt->seginx + i];
    if ((*ier) == 0) {
      if (!(isprint_ (outfnam[i]) && (outfnam[i] != ' '))) {
	*ier = 1;
      }
    }
  }
  outfnam[txt->len] = '\0';
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "Pointoutput(%s segmnt %d, len %d) \"",
	     create ? " TRUE" : "FALSE", txt->seginx, txt->len);
    FORLIM = txt->len;
    for (i = 0; i < FORLIM; i++) {
      putc (outfnam[i], log_);
    }
    fprintf (log_, "\"\n");
    fflush (log_);
  }
#endif
  if ((*ier) != 0) {
    markerror (861);
    return;
  }
  if (create) {
    if (redirect != NULL) {
      redirect =
	freopen (trimname (outfnam, sizeof (mstring)), "w", redirect);
    } else {
      redirect = fopen (trimname (outfnam, sizeof (mstring)), "w");
    }
    if (redirect == NULL) {
      fatal (10);
    }
    return;
  }
  if (redirect != NULL) {
    redirect = freopen (trimname (outfnam, sizeof (mstring)), "a", redirect);
  } else {
    redirect = fopen (trimname (outfnam, sizeof (mstring)), "a");
  }
  if (redirect == NULL) {
    fatal (10);
  }
}

#endif

							/* Read string terminal into chbuf */
void
readstring (void) {
  int n;
  arg *ar;
  fbuffer *abuf;
  Char c;
  fbuffer *With;
  int FORLIM;
#ifdef DDEBUG
  int j;
  if (debuglevel > 0) {
    fprintf (log_, "\nreadstring ");
    j = chbufi;
  }
#endif
  instr = true;
  do {
    c = ch;
    pushch ();
    if ((c == bslch) && (ch == '"')) {
      chbufi--;
      pushch ();
    } else if (c == '$') {
      n = 0;
      if (args != NULL) {
	while (isdigit (ch) != 0) {
	  n = (n * 10) + ch - '0';
	  inchar ();
	}
      }
      if (n > 0) {
	ar = findarg (args, n);
	chbufi--;
	if (ar != NULL) {
	  abuf = ar->argbody;
	  while (abuf != NULL) {
	    With = abuf;
	    FORLIM = With->savedlen;
	    for (n = With->readx; n <= FORLIM; n++) {
	      chbuf[chbufi] = With->carray[n];
	      if (chbufi < CHBUFSIZ) {
		chbufi++;
	      } else {
		fatal (4);
	      }
	    }
	    abuf = abuf->nextb;
	  }
	}
      }
    }
  } while (!((c == '"') || inputeof));
  if (!inputeof) {
    chbufi--;
  }
  instr = false;
#ifdef DDEBUG
  if (debuglevel > 0) {
    putc ('\n', log_);
    fprintf (log_, " readstring done, chbufi=%d |", chbufi);
    while (j < chbufi) {
      putc (chbuf[j], log_);
      j++;
    }
    fprintf (log_, "| ");
    if (inputeof) {
      fprintf (log_, "inputeof ");
    }
    wchar (&log_, ch);
    putc ('\n', log_);
  }
#endif
}

							/* Read exponent part of number */
void
readexponent (void) {
  boolean neg;
  int k = 0;

  pushch ();
  if (ch == '-') {
    neg = true;
    pushch ();
  } else if (ch == '+') {
    neg = false;
    pushch ();
  } else {
    neg = false;
  }
  if (isdigit (ch) == 0) {
    markerror (802);
    return;
  }
  do {
    k = (k * 10) + ch - '0';
    pushch ();
  } while (isdigit (ch) != 0);
  if (neg) {
    floatvalue *= exp (-k * ln10);
  } else {
    floatvalue *= exp (k * ln10);
  }
}				/* readexponent */

							/* Read fraction part of number */
void
readfraction (void) {
  double x = 10.0;

  while (isdigit (ch) != 0) {
    floatvalue += (ch - '0') / x;
    x *= 10;
    pushch ();
  }
}				/* readfraction */

							/* Read number integer, fraction, exponent */
void
readconst (Char initch) {
  floatvalue = 0.0;
  if (initch == '.') {
    readfraction ();
  } else {
    while (isdigit (ch) != 0) {
      floatvalue = (10 * floatvalue) + ch - '0';
      pushch ();
    }
    if (ch == '.') {
      pushch ();
      readfraction ();
    }
  }
  if ((ch == 'e') || (ch == 'E')) {
    readexponent ();
  }
							/* A rather odd way to allow inch units */
  if (ch == 'i') {
    pushch ();
  }
  newsymb = XLfloat;
}

#ifdef DDEBUG
void
prlex (boolean acc) {
  int i, FORLIM;
  if (debuglevel <= 0) {
    return;
  }
  fprintf (log_, "\nLEXICAL(oldsymb=%d newsymb=%d)", oldsymb, newsymb);
  if (newsymb != XLaTeX) {
    fprintf (log_, " chbuf(%d:%d)=\"", oldbufi, chbufi - 1);
    FORLIM = chbufi;
    for (i = oldbufi; i < FORLIM; i++) {
      putc (chbuf[i], log_);
    }
    putc ('"', log_);
  } else {
    fprintf (log_, "=<LaTeX>");
  }
  if (newsymb == XLfloat) {
    wlogfl ("value", floatvalue, 0);
  }
  putc (' ', log_);
  logchar (ch);
  if (!acc) {
    fprintf (log_, " not accepted");
  }
  putc ('\n', log_);
  consoleflush ();
}
#endif

							/* Prepend a buffer on the left of current buf*/
fbuffer *(prebuf (fbuffer * buf)) {
  fbuffer *With;

  if (buf->prevb == NULL) {
    newbuf (&buf->prevb);
  }
  With = buf->prevb;
  With->attrib = buf->attrib;
  With->higherb = buf->higherb;
  With->savedlen = CHBUFSIZ;
  With->readx = CHBUFSIZ + 1;
  With->nextb = buf;
  return (buf->prevb);
}

							/* Push macro or arg or string from mac into
   the head of the input stream */
void
copyleft (fbuffer * mac, fbuffer ** buf, int attr) {
  fbuffer *ml;
  int i, k;
  boolean newflag;
  boolean copied = false;
  fbuffer *With;
  int FORLIM;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "copyleft(%d", odp (mac));
    fprintf (log_, ",%d,%d):\n", odp (*buf), attr);
  }
  if (debuglevel > 1) {
    fprintf (log_, " input string");
    wrbuf (mac, 3, 1);
    fprintf (log_, " output");
    wrbuf (*buf, 3, 1);
  }
#endif
  if (mac != NULL) {
    while (mac->nextb != NULL) {
      mac = mac->nextb;
    }
  }
  while (mac != NULL) {
    if (mac->carray != NULL) {
      if (mac->savedlen >= mac->readx) {
	copied = true;
	if ((*buf) == NULL) {
	  newflag = true;
	} else if ((*buf)->attrib >= 0) {
	  newflag = true;
	} /* for */
	else {
	  newflag = false;
	}
	if (newflag) {
	  newbuf (&ml);
	  if (attr == 0) {
	    ml->attrib = mac->attrib;
	  } else {
	    ml->attrib = attr;
	  }
	  ml->savedlen = CHBUFSIZ;
	  ml->readx = CHBUFSIZ + 1;
	  ml->higherb = *buf;
	  *buf = ml;
	}
      }
      k = mac->savedlen;
      if ((*buf)->readx < (k - mac->readx + 2)) {
	With = *buf;
	while (With->readx > 1) {	/* fill the left part of buf */
	  With->readx--;
	  With->carray[With->readx] = mac->carray[k];
	  k--;
	}
	*buf = prebuf (*buf);
      }
      With = *buf;
      FORLIM = mac->readx;
      for (i = k; i >= FORLIM; i--) {
	With->readx--;
	With->carray[With->readx] = mac->carray[i];
      }
    }
    mac = mac->prevb;
  }
  if (!copied) {
    return;
  }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, " copyleft result\n");
    wrbuf (*buf, 3, 1);
  }
#endif
  if ((*buf)->readx <= 1) {
    *buf = prebuf (*buf);
  }
  With = *buf;
  With->carray[With->readx - 1] = nlch;
}

							/*  $n has been seen in a macro argument;
   							copy the body into the tail of the input buffer */
void
copyright (fbuffer * mac, fbuffer ** buf) {
  fbuffer *ml;
  int i, k;
  fbuffer *With;
  int FORLIM;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "copyright:\n input");
    wrbuf (mac, 3, 1);
    fprintf (log_, " output");
    wrbuf (*buf, 3, 0);
  }
#endif
  while (mac != NULL) {
    if ((*buf) == NULL) {
      newbuf (buf);
      With = *buf;
      With->attrib = -1;
      With->savedlen = 0;
      With->readx = 1;
    }
    k = mac->readx;
    if (CHBUFSIZ - (*buf)->savedlen <= mac->savedlen - k) {
      With = *buf;
      while (With->savedlen < CHBUFSIZ) {
	With->savedlen++;
	With->carray[With->savedlen] = mac->carray[k];
	k++;
      }
      newbuf (&ml);
      ml->attrib = (*buf)->attrib;
      ml->prevb = *buf;
      (*buf)->nextb = ml;
      *buf = ml;
    }
    With = *buf;
    FORLIM = mac->savedlen;
    for (i = k; i <= FORLIM; i++) {
      With->savedlen++;
      With->carray[With->savedlen] = mac->carray[i];
    }
    mac = mac->nextb;
  }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, " result");
    wrbuf (*buf, 3, 0);
  }
#endif
}

							/* Check the current char for line continuation */
void
skipcontinue (boolean instrg) {
  Char c;
  fbuffer *With;
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, "\n skipcontinue readx=%d ", inbuf->readx);
  }
#endif
  c = ch;
  while (c == bslch) {
    With = inbuf;
    if (With->readx <= With->savedlen) {
      c = With->carray[With->readx];
    } else if (With->nextb == NULL) {
      inchar ();
      c = ch;
    } else {
      c = With->nextb->carray[With->nextb->readx];
    }
    if (c == nlch) {
      inchar ();
      inchar ();
      c = ch;
      continue;
    }
    if ((c != '#') || instrg) {
      c = ' ';
      break;
    }
    skiptoend ();
    inchar ();
    c = ch;
  }
}

							/* Skip white space characters */
void
skipwhite (void) {		/* D if debuglevel = 2 then writeln(log, 'skipwhite: ' ); D */
  while ((ch == etxch) || (ch == nlch) || (ch == tabch) || (ch == ' ')) {
    if (ch == etxch) {
      exitmacro ();
    }
    inchar ();
    if (ch == bslch) {
      skipcontinue (false);
    }
  }
}

							/* Stash the current argument into the arg
   struct*/
void
defineargbody (int *parenlevel, fbuffer ** p2) {
  int j, n;
  arg *ar;
  fbuffer *p;
  fbuffer *p1 = NULL;
  boolean inarg, instring;
  Char prevch;
  fbuffer *With;

  skipwhite ();
  if ((*parenlevel) >= 0) {
    inarg = true;
  } else {
    inarg = false;
  }
  while (inarg) {
    newbuf (&p);
    p->attrib = -1;
    if (p1 != NULL) {
      p1->nextb = p;
      p->prevb = p1;
    }
    p1 = p;
    j = CHBUFSIZ;
    instring = false;
    prevch = ' ';
    do {
      With = p1;
      if (prevch != bslch) {
	if (instring && (ch == '"')) {
	  instring = false;
	} else if (ch == '"') {
	  instring = true;
	}
      }
      if (!instring) {
	if (ch == '(') {
	  (*parenlevel)++;
	} else if (ch == ')') {
	  (*parenlevel)--;
	}
      }
      if ((!instring) && (((*parenlevel) < 0) ||
			  (((*parenlevel) == 0) && (ch == ',')))) {
	j = With->savedlen;
	inarg = false;
      } else if (ch != '$') {
	prevch = ch;
	if (With->savedlen < CHBUFSIZ) {
	  With->savedlen++;
	} else {
	  markerror (872);
	}
	With->carray[With->savedlen] = ch;
	inchar ();
      } else {
	prevch = ch;
	inchar ();
	if (isdigit (ch) != 0) {
	  n = 0;
	  do {
	    n = (n * 10) + ch - '0';
	    inchar ();
	  } while (isdigit (ch) != 0);
	  ar = findarg (args, n);
	  if (ar != NULL) {
	    copyright (ar->argbody, &p1);
	  }
	} else {
	  if (With->savedlen < CHBUFSIZ) {
	    With->savedlen++;
	  } else {
	    markerror (872);
	  }
	  With->carray[With->savedlen] = prevch;
	}
      }
      /* $ found in a macro arg */
      if (inputeof) {
	markerror (806);
	j = With->savedlen;
	inarg = false;
	*parenlevel = -1;
      }
    } while (p1->savedlen != j);
  }
  if (p1 != NULL) {
    while (p1->prevb != NULL) {
      p1 = p1->prevb;
    }
  }
  ch = ' ';
  *p2 = p1;
}

							/* String equality:
							   0: identical
							   +k: string1 > string2 or len1 > len2
							   -k: string1 < string2 or len1 < len2
							   maxint: nil string or strings */
int
eqstring (Char * seg1, chbufinx inx1, chbufinx len1, Char * seg2,
	  chbufinx inx2, chbufinx len2) {
  int i = 0;
  int j, k;
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, " eqstring:\n");
    if (seg1 == NULL)
      fprintf (log_, " seg1 == NULL");
    if (seg2 == NULL)
      fprintf (log_, " seg2 == NULL");
  }
#endif
  if ((seg1 == NULL) || (seg2 == NULL)) {
    k = maxint;
    return k;
  }
  k = 0;
  if (len1 < len2) {
    j = len1;
  } else {
    j = len2;
  }
  while (i < j) {
#ifdef DDEBUG
    if (debuglevel == 2) {
      fprintf (log_, "(%c%c)", seg1[inx1 + i], seg2[inx2 + i]);
    }
#endif
    k = seg1[inx1 + i] - seg2[inx2 + i];
    if (k == 0) {
      i++;
    } else {
      j = i;
    }
  }
  if (k != 0) {
    return k;
  }
  if (len1 > len2) {
    k = seg1[inx1 + i];
  } else if (len1 < len2) {
    k = -seg2[inx2 + i];
#ifdef DDEBUG
    if (debuglevel == 2) {
      fprintf (log_, " i=%d j=%d eqstring=%d\n", i, j, k);
    }
#endif
  }
  return k;
}

							/* Look for given macro name */
arg
  *(findmacro
    (arg * p, Char * chb, chbufinx inx, chbufinx toklen, arg ** last)) {
  arg *pj = NULL;
  arg *With;
  *last = NULL;
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, "findmacro:");
    snapname (chb, inx, toklen);
    putc ('\n', log_);
    fflush (log_);
  }
#endif
  if (p != NULL) {
    while (p != pj) {
      With = p;
      if (With->argbody == NULL) {
	*last = p;
	p = p->nexta;
      } else
	if (eqstring
	    (With->argbody->carray, 1, -With->argbody->attrib, chb, inx,
	     toklen) == 0) {
	pj = p;
      } else {
	*last = p;
	p = p->nexta;
      }
    }
  }
  return p;
}

							/* Get and initialize an arg from the
   								old-arg stack or make a new one */
void
newarg (arg ** ar) {
  arg *With;
  if (freearg == NULL) {
    *ar = malloc (sizeof (arg));
  } else {
    *ar = freearg;
    freearg = freearg->nexta;
  }
  With = *ar;
  With->argbody = NULL;
  With->highera = NULL;
  With->nexta = NULL;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, " newarg[%d]\n", odp (*ar));
  }
#endif
}

							/* Check for macro name */
boolean
ismacro (Char * chb, chbufinx obi, chbufinx chbi) {
  arg *mac, *lastp, *ar;
  arg *lastarg = NULL, *firstarg = NULL;
  int level;
  boolean ism = false;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "\nismacro[");
    for (level = obi; level < chbi; level++) {
      putc (chb[level], log_);
    }
    fprintf (log_, "]:");
  }
#endif
  if (oldsymb == XLdefine) {
    skipwhite ();
    return ism;
  }
  if (oldsymb == XLundefine) {
    return ism;
  }
  mac = findmacro (macros, chb, obi, chbi - obi, &lastp);
  if (mac == NULL) {
    return ism;
  }
#ifdef DDEBUG
  currentmacro = mac;
#endif
  ism = true;
  if (ch == '(') {
    level = 0;
  } else {
    backup ();
    level = -1;
  }
  do {
    newarg (&ar);
    ar->highera = args;
    if (lastarg == NULL) {
      firstarg = ar;
    } else {
      lastarg->nexta = ar;
    }
    if (level >= 0) {
      inchar ();
      defineargbody (&level, &ar->argbody);
    }
    lastarg = ar;
  } while (level >= 0);
  args = firstarg;
  copyleft (mac->argbody, &inbuf, 0);
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "\nismacro returning:%5s\n", ism ? "TRUE" : "FALSE");
  }
#endif
  return ism;
}

							/* Push an argument to the left of the
   								input stream */
void
copyarg (Char * chb, chbufinx chbs, chbufinx chbi) {
  int n = 0;
  int i;
  arg *ar;

  for (i = chbs + 1; i < chbi; i++) {
    n = (n * 10) + chb[i] - '0';
  }
  ar = findarg (args, n);
  backup ();
  if (ar != NULL) {
    if (ar->argbody != NULL) {
      copyleft (ar->argbody, &inbuf, -1);
    }
  }
}

							/* Check for $+ or copy arg */
boolean
insertarg (void) {
  int icx;

  pushch ();
  if (ch == '+') {
    backup ();
    ch = '$';
    chbufi--;
    return false;
  } else {
    icx = chbufi - 1;
    while (isdigit (ch) != 0) {
      pushch ();
    }
    copyarg (chbuf, icx, chbufi);
    chbufi = icx;
    inchar ();
    return true;
  }
}

							/* Find the next terminal.
   								Set lexsymb (terminal lexical value),
   								newsymb (terminal number used for parsing),
   								and float value.
   								Identify and generate all terminals
   								of the form <...> in the grammar.
   								Reads one character after the terminal end */
int
yylex (attribute * a0) {
  int lxix;
  Char firstch;
  boolean terminalaccepted, looping;
  fbuffer *With;

							/* argstruct: argp;
     j,k: integer;
     varptr,lastp: strptr; */

							/* floatvalue = 0.0; */
  lexsymb = -1;
  do {
    terminalaccepted = true;
    oldbufi = chbufi;		/* first char of current terminal in chbuf */
    while ((ch == ' ') || (ch == tabch)) {
      inchar ();
    }
	/* lexstate is
       0 before .PS or after .PE
       1 when .PS found
       2 between .PS and .PE
       3 when .PE found
       4 to process .PE */
    if (lexstate == 1) {
      newsymb = XSTART;
      lexstate = 2;
    } else if (lexstate == 3) {
      newsymb = XEND;
      lexstate = 4;
    } else if (lexstate == 4) {
      newsymb = XNL;
      skiptoend ();
      ch = ' ';
      lexstate = 0;
    } else if (inputeof) {
      newsymb = 0;
    } else if (forbufend) {
      newsymb = XLendfor;
      forbufend = false;
      ch = ' ';
    } else if (ch == nlch) {
      newsymb = XNL;
      ch = ' ';
      if ((oldsymb == XLelse) || (oldsymb == XLBRACE) ||
	  (oldsymb == XLthen) || (oldsymb == XCOLON) || (oldsymb == XNL)) {
	terminalaccepted = false;
      }
    } else if (isdigit (ch) != 0) {
      readconst (ch);
    } else if (ch == etxch) {
      exitmacro ();
      inchar ();
      terminalaccepted = false;
    }

							/* Use the lexical tables to identify
       							terminals, checking for macro names */
    else {
      firstch = ch;
      pushch ();
							/* Continuation, comment, constant, latex */
      With = inbuf;
      if (firstch == bslch) {
	if ((ch == nlch) || (ch == '#')) {
	  if (ch == '#') {
	    skiptoend ();
	  }
	  ch = ' ';
	  newsymb = -2;		/* flag for test below */
	  terminalaccepted = false;
	} else {
	  readlatex ();
	}
      } else if ((firstch == '.') && (isdigit (ch) != 0)) {
	readconst (firstch);
      } else if ((firstch == '.') && (With->readx == 3) &&
		 (inbuf->prevb == NULL) && (newsymb != (-2))) {
	readlatex ();
      } else {			    /* Search in the lexical tree */
	newsymb = entrytv[abs (firstch)];
	lxix = entryhp[abs (firstch)];
	while (lxix != 0) {
	  if (ch == '$') {
	    if (!insertarg ()) {
	      lxix = 0;
	    }
	    continue;
	  }
	  if (lxch[lxix] == ch) {
	    newsymb = lxtv[lxix];
	    lxix = lxhp[lxix];
	    pushch ();
	  } else {
	    lxix = lxnp[lxix];
	  }
	}
							/* Insert argument or macro */
	if ((isupper (firstch) != 0) &&
	    ((isalnum (ch) != 0) || (ch == '_') || (ch == '$'))) {
							/* Label */
	  looping = true;
	  while (looping) {
	    if (ch == '$') {
	      looping = insertarg ();
	    } else if ((isalnum (ch) != 0) || (ch == '_')) {
	      pushch ();
	    } else {
	      looping = false;
	    }
	  }
	  if (ismacro (chbuf, oldbufi, chbufi)) {
	    terminalaccepted = false;
	  } else {
	    newsymb = XLabel;
	  }
	} else if (((isalnum (firstch) != 0) || (firstch == '_')) &&
		   ((isalnum (ch) != 0) || (ch == '_') || (ch == '$'))) {
							/* variable name */
	  looping = true;
	  while (looping) {
	    if (ch == '$') {
	      looping = insertarg ();
	    } else if ((isalnum (ch) != 0) || (ch == '_')) {
	      pushch ();
	    } else {
	      looping = false;
	    }
	  }
	  if (ismacro (chbuf, oldbufi, chbufi)) {
	    terminalaccepted = false;
	  } else {
	    newsymb = XLname;
	  }
	} else if (newsymb == XLstring) {
	  chbufi--;
	  readstring ();
	} else if (newsymb == XCOMMENT) {
	  skiptoend ();
	  ch = nlch;
	  terminalaccepted = false;
	}
							/* Skip after designated terminals */
	else if ((newsymb == XNL) &&
		 ((oldsymb == XLelse) || (oldsymb == XLBRACE) ||
		  (oldsymb == XLthen) || (oldsymb == XCOLON) ||
		  (oldsymb == XNL))) {
	  terminalaccepted = false;
	} else if ((newsymb == XLT) && inlogic) {
	  lexsymb = XLcompare;
	  newsymb = XLcompare;
	} else if ((newsymb > XEQ) && (newsymb <= XLremeq)) {
	  lexsymb = newsymb;
	  newsymb = XEQ;
	}
							/* Multiple-valued terminals */
	else if (newsymb > XLcorner) {
	  lexsymb = newsymb;
	  if (newsymb > XLenvvar) {
	    newsymb = XLenvvar;
	  } else if (newsymb > XLprimitiv) {
	    newsymb = XLprimitiv;
	  } else if (newsymb > XLdirecton) {
	    newsymb = XLdirecton;
	  } else if (newsymb > XLarrowhd) {
	    newsymb = XLarrowhd;
	  } else if (newsymb > XLtextpos) {
	    newsymb = XLtextpos;
	  } else if (newsymb > XLcolrspec) {
	    newsymb = XLcolrspec;
	  } else if (newsymb > XLlinetype) {
	    newsymb = XLlinetype;
	  } else if (newsymb > XLfunc2) {
	    newsymb = XLfunc2;
	  } else if (newsymb > XLfunc1) {
	    newsymb = XLfunc1;
	  } else if (newsymb > XLparam) {
	    newsymb = XLparam;
	  } else if (newsymb > XLcompare) {
	    newsymb = XLcompare;
	  } else {
	    newsymb = XLcorner;
	  }
	} else if (newsymb == XLarg) {
	  if (ch == '+') {	/* $+ */
	    floatvalue = argcount (args);
	    newsymb = XLfloat;
	    inchar ();
	  } else if (isdigit (ch) != 0) {	/* $<integer> */
	    do {
	      pushch ();
	    } while (isdigit (ch) != 0);
	    copyarg (chbuf, oldbufi, chbufi);
	    terminalaccepted = false;
	  } else {
	    markerror (805);
	  }
	} else if (newsymb == XLdo) {
	  skipwhite ();
	}
#ifdef DDEBUG
	else if (newsymb == XAND) {
	  chbufi = oldbufi;
	  if (debuglevel > 0) {
	    consoleflush ();
	  }
	  if (ch >= 'A') {	/* linesignal = ch - 'A' + 1; */
	  } else if (ch > '0') {
	    if (oflag <= 0) {
	      openlogfile ();
	    }
	    debuglevel = ch - '0';
	  } else if (ch == '0') {
	    debuglevel = 0;
	  }
	  fprintf (log_, "Debuglevel = %d\n", debuglevel);
	  consoleflush ();
	  inchar ();
	  terminalaccepted = false;
	}
#endif
	else if ((newsymb == 0) && (isupper (firstch) != 0)) {
							/* Label, second possibility */
	  if (ismacro (chbuf, oldbufi, chbufi)) {
	    terminalaccepted = false;
	  } else {
	    newsymb = XLabel;
	  }
	} else if ((newsymb == 0) &&
		   ((isalnum (firstch) != 0) || (firstch == '_'))) {
							/* name, second possibility */
	  if (ismacro (chbuf, oldbufi, chbufi)) {
	    terminalaccepted = false;
	  } else {
	    newsymb = XLname;
	  }
	} else if (newsymb == 0) {	/* char not recognized */
#ifdef DDEBUG
	  if (debuglevel > 0) {
	    fprintf (log_,
		     "\nMarking 800:ord(firstch)=%12d ord(ch)=%12d\n", firstch,
		     ch);
	  }
#endif
	  fprintf (errout, "Char chr(%d)", firstch);
	  putc ('"', errout);
	  wchar (&errout, firstch);
	  putc ('"', errout);
	  fprintf (errout, " unknown\n");
	  markerror (800);
	  terminalaccepted = false;
	}
      }
    }				/*lookahead terminals */
#ifdef DDEBUG
    prlex (terminalaccepted);
#endif
    if ((newsymb != XLaTeX) && (newsymb != XLstring) &&
	(newsymb != XLabel) && (newsymb != XLname)) {
      chbufi = oldbufi;
    }
  } while (!terminalaccepted);
  if (lexsymb == (-1)) {
    lexsymb = newsymb;
  }
  oldsymb = newsymb;

							/* create the attribute */
  a0->chbufx = oldbufi;
  a0->toklen = chbufi - oldbufi;
  a0->prim = NULL;
  a0->internal = NULL;
  a0->varname = NULL;
  a0->xval = floatvalue;
  a0->yval = 0.0;
  a0->startchop = 0.0;
  a0->endchop = 0.0;
  a0->state = 0;
  a0->lexval = lexsymb;

  return (newsymb);
}				/* yylex */

/*--------------------------------------------------------------------*/

							/* Skip white to next left brace, accounting
  								 for strings */
void
skiptobrace (void) {
  int bracelevel = 1;
  boolean instring = false;
  Char prevch = ' ';
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, "\nskiptobrace: \n");
  }
#endif
  while (bracelevel > 0) {
    if (ch == bslch) {
      skipcontinue (instring);
    }
    if (ch == etxch) {
      exitmacro ();
    }
    if (instring) {
      if ((ch == '"') && (prevch != bslch)) {
	instring = false;
      }
    } else if (ch == '{') {
      bracelevel++;
    } else if (ch == '}') {
      bracelevel--;
    } else if (ch == '"') {
      instring = true;
    }
    if (bracelevel <= 0) {
      break;
    }
    if (inputeof) {
      bracelevel = 0;
      if (instring) {
	markerror (807);
      } else {
	markerror (804);
      }
    } else {
      prevch = ch;
      inchar ();
    }
  }
}

/*--------------------------------------------------------------------*/

							/* De-allocate buffer memory */
void
deletebufs (fbuffer ** buf) {
  fbuffer *bu;

  if ((*buf) != NULL) {
    while ((*buf)->prevb != NULL) {
      *buf = (*buf)->prevb;
    }
  }
  while ((*buf) != NULL) {
    bu = (*buf)->nextb;
    Free ((*buf)->carray);
    Free (*buf);
    *buf = bu;
  }
}

							/* Open required input and outputs */

void
P_sun_argv (char *s, int len, int n) {
  char *cp;
  if ((unsigned) n < P_argc)
    cp = P_argv[n];
  else
    cp = "";
  while (*cp && --len >= 0)
    *s++ = *cp++;
  while (--len >= 0)
    *s++ = ' ';
}

void
openfiles (void) {
#ifdef DDEBUG
  int i = 1, j = FILENAMELEN;
#endif
  savebuf = NULL;
  output = stdout;
  input = stdin;
  if (argct >= P_argc) {
    return;
  }
  P_sun_argv (infname, sizeof (mstring), argct);
  if (checkfile (infname, true) != 0) {
    fatal (1);
  }
  if (input != NULL) {
    input = freopen (trimname (infname, sizeof (mstring)), "r", input);
  } else {
    input = fopen (trimname (infname, sizeof (mstring)), "r");
  }
  if (input == NULL) {
    fatal (1);
  }
#ifdef DDEBUG
  if (oflag <= 0) {
    return;
  }
  openlogfile ();
  debuglevel = oflag;
  fprintf (log_, "Input file: ");
  while (j >= i) {
    if ((infname[j - 1] == ' ') || (infname[j - 1] == '\0')) {
      j--;
    } else {
      i = j + 1;
    }
  }
  for (i = 0; i < j; i++) {
    putc (infname[i], log_);
  }
  putc ('\n', log_);
#endif
}

							/* Separate out the option character */
Char
optionchar (Char * fn) {
  int j = 1, k = FILENAMELEN + 1;
  while (j < k) {
    if (fn[j - 1] == ' ') {
      j++;
    } else {
      k = j;
    }
  }
  if (j >= FILENAMELEN) {
    return '\0';
  } else if (fn[j - 1] == '-') {
    return (fn[j]);
	/* if fn[j+2] <> ' ' then for k:=j+2 to FILENAMELEN do fn[k-j-1] := fn[k] */
  } else {
    return '\0';
  }
}

							/* Set safe mode and one of 12 output formats.
   The version date is set during
   preprocessing */

void
getoptions (void) {
  Char cht;
  int istop;

#ifdef DDEBUG
  oflag = 0;
#endif
  argct = 1;
  istop = P_argc;
  while (argct < istop) {
    P_sun_argv (infname, sizeof (mstring), argct);
    cht = optionchar (infname);
    if (cht == 0) {
      istop = argct;
      continue;
    }
    if (cht == 'd') {
      drawmode = PDF;
    } else if (cht == 'e') {
      drawmode = Pict2e;
    } else if (cht == 'f') {
      drawmode = PSfrag;
    } else if (cht == 'g') {
      drawmode = PGF;
    } else if (cht == 'm') {
      drawmode = MFpic;
    } else if (cht == 'p') {
      drawmode = PSTricks;
    } else if (cht == 'r') {
      drawmode = PS;
    } else if (cht == 's') {
      drawmode = MPost;
    } else if (cht == 't') {
      drawmode = tTeX;
    } else if (cht == 'v') {
      drawmode = SVG;
    } else if (cht == 'x') {
      drawmode = xfig;
    } else if (cht == 'z') {
      safemode = true;
    }
#ifdef DDEBUG
    else if (isdigit (cht)) {
      oflag = cht - '0';
    }
#endif
    else if ((cht == 'h') || (cht == '-')) {
      fprintf (errout, " *** dpic version %s\n",VERSIONDATE);
#ifdef DDEBUG
      fprintf (errout, " Debug is enabled\n");
#endif
      fprintf (errout, " Options:\n");
      fprintf (errout, "     (none) LaTeX picture output\n");
      fprintf (errout, "     -d PDF output\n");
      fprintf (errout, "     -e Pict2e output\n");
      fprintf (errout, "     -f Postscript output, psfrag strings\n");
      fprintf (errout, "     -g PGF-TikZ output\n");
      fprintf (errout, "     -h write this message and quit\n");
      fprintf (errout, "     -m mfpic output\n");
      fprintf (errout, "     -p PSTricks output\n");
      fprintf (errout, "     -r Postscript output\n");
      fprintf (errout, "     -s MetaPost output\n");
      fprintf (errout, "     -t eepicemu output\n");
      fprintf (errout, "     -v SVG output\n");
      fprintf (errout, "     -x xfig output\n");
      fprintf (errout,
	       "     -z safe mode (disable sh, copy, and print to file)\n");
      fatal (0);
    } else {
      fprintf (errout, " *** dpic terminating: Unknown option ");
      if (isprint_ (cht)) {
	fprintf (errout, "\"%c\"\n", cht);
      } else {
	fprintf (errout, "\"char(%d)\"\n", cht);
      }
      fatal (0);
    }
    argct++;
  }
}				/* getoptions */

int
main (int argc, Char * argv[]) {
  P_argc = argc;
  P_argv = argv;
  redirect = NULL;
  copyin = NULL;
  errout = NULL;
  output = NULL;
  input = NULL;
  openerror ();
  drawmode = TeX;

#ifdef SAFE_MODE
  safemode = true;
#else
  safemode = false;
#endif
  getoptions ();
  openfiles ();
							/* Initialize the semantic actions, the
     							parse state, and the lexical state */
  inputeof = false;
  tmpbuf = NULL;
  tmpfmt = NULL;
  initrandom ();

  chbuf = malloc (sizeof (chbufarray));
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "new(chbuf)[%d]\n", odp (chbuf));
  }
#endif
  entrytv[ordNL] = XNL;
  entrytv[ordCR] = XNL;		/* treat ^M as line end */

  errcount = 0;
							/* change for debugging */
							/* linesignal := 0; */

  preproduce (-2);
  printstate = 0;

							/* lexical initializations, see also
     							production -1 */
  ch = ' ';
  lineno = 0;
  chbufi = 0;
  oldbufi = 0;
  newsymb = XNL;
  oldsymb = XNL;
  lexstate = 0;
  macros = NULL;
  args = NULL;
#ifdef DDEBUG
  currentmacro = NULL;
#endif

  forbufend = false;
  instr = false;

  preproduce (-1);

  int yyparse ();
  int yyyperr;
  yyyperr = yyparse ();

  epilog ();
  if (input != NULL) {
    fclose (input);
  }
  if (output != NULL) {
    fclose (output);
  }
  if (errout != NULL) {
    fclose (errout);
  }
  if (copyin != NULL) {
    fclose (copyin);
  }
  if (redirect != NULL) {
    fclose (redirect);
  }
#ifdef DDEBUG
  if (log_ != NULL) {
    fclose (log_);
  }
#endif
  if ((errcount == 0) && (yyyperr == 0)) {
    exit (EXIT_SUCCESS);
  } else
    exit (EXIT_FAILURE);
}				/* dpic */

