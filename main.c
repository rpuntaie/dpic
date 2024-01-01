							/* Main routines */
#define EXTRN
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
extern void wlogfl (char *, double, int);
extern void wrbufaddr (fbuffer *, int);
extern void wrbuf (fbuffer *, int);
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
  while (x > r) { x -= 2 * r; }
  while (x < (-r)) { x += 2 * r; }
  return x;
}

double
Max (double x, double y) {
  if (y > x) { return y; } else { return x; }
}

double
Min (double x, double y) {
  if (y < x) { return y; } else { return x; }
}

int
Floor (double x) {
  if ((x >= 0) || (((long) x) == x)) { return ((long) x); }
  else { return (((long) x) - 1); }
}

int
Ceil (double x) {
  if ((x < 0) || (((long) x) == x)) { return ((long) x); }
  else { return (((long) x) + 1); }
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
    ym = 0.0; }
  else {
    xm = fabs (y);
    ym = x / xm;
    }
  return (xm * sqrt (1.0 + (ym * ym)));
}

double
distance(postype A, postype B)
{ return (linlen(A.xpos - B.xpos, A.ypos - B.ypos)); }

/*--------------------------------------------------------------------*/
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
                               the fraction part (upper bound 10e32) */
void
wfloat (FILE ** iou, double y) {
   char buf[CHBUFSIZ];
   int i;
   if (y < 0) { putc('-', *iou); y = -y; }
   if (y > 10e32) { y = 10e32; }
   i = snprintf(buf, CHBUFSIZ, "%33.6f", floor(y*1000000+0.5)/1000000.0 );
   for (i--; buf[i]=='0'; ) { i--; }
   if (buf[i]=='.') { buf[i] = (char)0; } else { buf[i+1] = (char)0; }
   for (i--; (i>=0) && (buf[i]!=' '); ) { i--; }
   i++;
   fprintf( *iou, "%s", &buf[i] );
}

							/* Output a string of characters from a strptr*/
void
wstring (FILE ** iou, nametype * p) {
  int i, FORLIM;
  if (p == NULL) { return; }
  if (p->segmnt != NULL) {
    FORLIM = p->seginx + p->len;
    for (i = p->seginx; i < FORLIM; i++) { putc (p->segmnt[i], *iou); }
    }
}

							/* Store ljust rjust in bits 1, 2 and
                                     below above in bits 3, 4 */
void
setjust (nametype * tp, int v) {
  int i;

  if (tp == NULL) { return; }
  i = (long) floor (tp->val + 0.5);
  switch (v) {
  case Xrjust: tp->val = ((i >> 2) * 4.0) + 1; break;
  case Xljust: tp->val = ((i >> 2) * 4.0) + 2; break;
  case Xbelow: tp->val = ((i >> 4) * 16.0) + (i & 3) + 4; break;
  case Xabove: tp->val = ((i >> 4) * 16.0) + (i & 3) + 8; break;
  case Xcenter: tp->val = (i >> 4) * 16.0; break;
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
  if (pr == NULL) { return false; }
  else { return (((pr->spec >> 3) & 1) != 0); }
}

							/* Draw arc in segments for arc arrowheads */
void
popgwarc (postype Ctr, postype A, postype B, double radjust, double ccw) {
  int narcs, i;
  double c, s, cc, ss, radius, startangle, endangle, arcangle;
  postype Q;
  radius = distance(B,Ctr)+radjust;
  startangle = posangle(A,Ctr);
  endangle = posangle(B,Ctr);
  if ((ccw > 0) && (endangle < startangle)) { endangle += 2 * pi; }
  else if ((ccw < 0) && (endangle > startangle)) { endangle -= 2 * pi; }
  narcs = (long) (1.0 + (fabs (endangle - startangle) / (pi/2)));
  arcangle = (endangle - startangle) / narcs;
  c = cos (arcangle / 2);
  s = sin (arcangle / 2);
  cc = (4 - c) / 3;
  if (s != 0.0) { ss = (1.0 - (c * cc)) / s; }
  else { ss = 0.0; }
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
  fflush(errout);
#ifdef DDEBUG
  if (debuglevel > 0) { fflush(log_); }
#endif
}

							/* Unrecoverable errors */
void
fatal (int t) {
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf (log_, "\nfatal(%d)\n",t); fflush(log_); }
#endif
  if (t != 0) { fprintf (errout, "\n*** dpic terminating: "); }
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
							/* case 6 and 7: pascal only, parse overflow */
  case 8:
    fprintf (errout, "error recovery abandoned\n");
    break;
  case 9:
    fprintf (errout, "malloc failed: insufficient available memory\n");
    break;
  default:
    fprintf (errout, "unclassified fatal error\n");
    break;
  }

  epilog ();
  if (input != NULL) { fclose (input); }
  if (output != NULL) { fclose (output); }
  if (errout != NULL) { fclose (errout); }
#ifdef DDEBUG
  if (log_ != NULL) { fclose (log_); }
#endif
  exit (EXIT_FAILURE);
}

#ifdef DDEBUG
							/* The log file is only for debugging */
void
openlogfile (void) {
  if (log_ != NULL) { log_ = freopen ("dpic.log", "w", log_); }
  else { log_ = fopen ("dpic.log", "w"); }
  if (log_ == NULL) { fatal (1); }
  fprintf (log_, "Dpic log file\n");
  fflush (log_);
  if (oflag <= 0) { oflag = 1; }
}
#endif

							/* Printable character */
boolean
isprint_ (Char ch) {
  return ((ch >= 32) && (ch <= 126));
}

							/* Output a character as printable */
void
wchar (FILE ** iou, Char c) {
  if (isprint_ (c)) { putc (c, *iou); }
  else if (c == nlch) { putc ('\n', *iou); }
  else if (c == crch) { fprintf (*iou, "\\r"); }
  else if (c == tabch) { fprintf (*iou, "\\t"); }
  else if (c < 32) { fprintf (*iou, "^%c", c + 64); }
  else { fprintf (*iou, "\\%d%d%d", (c >> 6) & 3, (c >> 3) & 7, c & 7); }
}

							/* Check if a file is accessible */
int
checkfile (Char * ifn, boolean isverbose) {
  int cf, i;
  cf = access ((char *)ifn, 4);
  if (!(isverbose && (cf != 0))) { return cf; }
  fprintf (errout, " *** dpic: Searching for file \"");
  for (i = 0; ifn[i] != '\0'; i++) { wchar(&errout,ifn[i]); }
  fprintf (errout, "\" returns %d\n", cf);
  return cf;
}

							/* Open the error stream */
void
openerror (void) {
  errout = stderr;
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
    fprintf (log_, "\ndisposebufs"); wrbufaddr (*buf, 1);
    putc ('\n', log_); }
#endif
  if ((*buf) == NULL) { return; }
  bu = *buf;
  while (bu->nextb != NULL) { bu = bu->nextb; }
  bu->nextb = freeinbuf;
  freeinbuf = *buf;
  *buf = NULL;
}

void
disposeargs (arg ** ar) {
  arg *aa;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf (log_, "disposeargs[%d]\n", odp (*ar)); }
#endif
  if ((*ar) == NULL) { return; }
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
  fbuffer *mbody;
  if (debuglevel > 0) {
    fprintf (log_, " exitmacro ");
    if (currentmacro == NULL) { }
    else if (currentmacro->argbody == NULL) { }
    else if (currentmacro->argbody->carray != NULL) {
      mbody = currentmacro->argbody;
      for (i = 1; i <= -(mbody->attrib); i++) {
        wchar (&log_,  mbody->carray[i]); } }
    putc ('\n', log_); }
#endif
  currentmacro = NULL;
  aa = args;
  if (args != NULL) { args = args->highera; }
  disposeargs (&aa);
}

							/* Read a line from the input */
void
readline (FILE ** infname) {
  int ll, c;
  if (feof (*infname)) { inputeof = true; return; }
  c = ' ';
  for (ll = CHBUFSIZ - 1; inbuf->savedlen < ll;) {
    c = getc (*infname);
    if ((char) c == '\n') { ll = inbuf->savedlen; }
    else if ((char) c == '\r') {
      if ((char) (c = getc (*infname)) != '\n') {
	    if (c != EOF) { ungetc (c, *infname); }
	    else if (inbuf->savedlen == 0) { inputeof = true; return; }
	    c = '\n'; }
      ll = inbuf->savedlen; }
    else if (c != EOF) {
      inbuf->savedlen++;
      inbuf->carray[inbuf->savedlen] = (char) c; }
    else if (inbuf->savedlen == 0) { inputeof = true; return; }
    else { ll = inbuf->savedlen; }
    }
  if ((ll == CHBUFSIZ - 1) && ((char) c != '\n') && (c != EOF)) {
    inbuf->savedlen++;
    inbuf->carray[inbuf->savedlen] = bslch; }
  else if (inbuf->carray[inbuf->savedlen] != bslch || lexstate != 2) {
    inbuf->savedlen++;
    inbuf->carray[inbuf->savedlen] = nlch;
    }
}

							/* Get the next line and set lexstate */
void
nextline (Char lastchar) {
  int i;
  int FORLIM;
  inbuf->readx = 1;
  inbuf->savedlen = 0;
  do {
    if (inbufdepth > 0) {
	  if (!inputeof) { lineno[inbufdepth]++; }
      readline (&copyin);
      if (inputeof) {
	    inputeof = false;
	    while (inbuf->prevb != NULL) { inbuf = inbuf->prevb; }
	    disposebufs (&inbuf);
	    inbuf = higherinbuf;
	    higherinbuf = NULL;
        inbufdepth = 0;
        }
      }
    else {
      if (!inputeof) { lineno[inbufdepth]++; }
      readline (&input);
      }
							/* Check for .PS, .PE, and zero length */
    if (inbuf->savedlen >= 1) {
      if (inbuf->carray[1] == '.') {
	    if (lexstate != 2) {
	      if ((inbuf->savedlen >= 4) && (inbuf->carray[2] == 'P')) {
	        if (higherinbuf != NULL){ inbuf->savedlen = 0; /* skip .P* lines */ }
            else if ((inbuf->carray[3] == 'F') || (inbuf->carray[3] == 'S')) {
	          lexstate = 1;
	          inbuf->readx = 4; }
            else if (inbuf->carray[3] == 'E') {
	          lexstate = 3;
	          inbuf->readx = 4;
	          }
	        }
	      }
        else if (lastchar != bslch) {
	      if ((inbuf->savedlen < 4) || (inbuf->carray[2] != 'P') ||
	          (higherinbuf != NULL)) { inbuf->savedlen = 0;	/* skip . lines */ }
          else if ((inbuf->carray[3] == 'F') || (inbuf->carray[3] == 'S')) {
	        lexstate = 1;
	        inbuf->readx = 4; }
          else if (inbuf->carray[3] == 'E') {
	        lexstate = 3;
	        inbuf->readx = 4; }
          else { inbuf->savedlen = 0; }
	      }
        }
      }
							/* Dump the line if not between .PS and .PE */
    if ((lexstate == 0) && (!inputeof)) {
      FORLIM = inbuf->savedlen;
      for (i = 1; i < FORLIM; i++) { putchar (inbuf->carray[i]); }
      if (inbuf->carray[inbuf->savedlen] != bslch) { putchar ('\n'); }
      inbuf->savedlen = 0;
      }
  } while (!((inbuf->savedlen > 0) || inputeof));
}

							/* Read the next char into ch, accounting for
                               strings and end of buffer */
void
inchar (void) {
  fbuffer *tp;
  boolean endofbuf;
  if (inbuf == NULL) {
#ifdef DDEBUG
    if (debuglevel == 2) { fprintf (log_, " new inbuf"); }
#endif
    newbuf (&inbuf);
    inbuf->attrib = -1;
    topbuf = inbuf;
    }
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, "\ninchar");
    wrbufaddr (inbuf, 0);
    fprintf (log_, ": instr=%c readx=%d", instr ? 'T' : 'F', inbuf->readx);
    }
#endif
  endofbuf = (inbuf->readx >= inbuf->savedlen);
  while (endofbuf) {
    if ((inbuf->readx < inbuf->savedlen) || inputeof) { endofbuf = false; }
    else if (inbuf->readx > inbuf->savedlen) {	/* nil */ }
    else if ((inbuf->carray[inbuf->readx] != bslch) || (inbuf->nextb != NULL)) {
      endofbuf = false; }
    else if (instr) {
      if (inbuf->savedlen < CHBUFSIZ) {
	    inbuf->savedlen++;
	    inbuf->carray[inbuf->savedlen] = nlch; }
      else if (inbuf->attrib > 0) {
	    newbuf (&tp);
	    tp->attrib = inbuf->attrib;
	    tp->prevb = inbuf;
	    tp->savedlen = 1;
	    tp->carray[1] = nlch;
	    inbuf->nextb = tp; }
      else {
	    inbuf->readx--;
	    inbuf->carray[inbuf->readx] = bslch;
	    inbuf->carray[inbuf->savedlen] = nlch; }
      endofbuf = false;
      }
    if (endofbuf) {
      if (inbuf->nextb != NULL) { inbuf = inbuf->nextb; }
      else if (inbuf->attrib > 0) {	/* for buf */
#ifdef DDEBUG
	    if (debuglevel == 2) {
	      fprintf (log_, " For detected, ");
	      logchar (ch); putc (' ', log_); }
#endif
	    inbuf->readx = 1;
	    while (inbuf->prevb != NULL) {
	      inbuf = inbuf->prevb;
	      inbuf->readx = 1;
	      }
	    forbufend = true; }
      else {
#ifdef DDEBUG
	    if (debuglevel == 2) {
	      fprintf (log_, " Not for, ");
	      logchar (ch); putc (' ', log_); }
#endif
	    while (inbuf->prevb != NULL) { inbuf = inbuf->prevb; }
	    if (inbuf->nextb != NULL) { disposebufs (&inbuf->nextb); }
	    if (inbuf->higherb != NULL) {
	      tp = inbuf->higherb;
	      disposebufs (&inbuf);
	      inbuf = tp; }
        else if (!inputeof) {
	      if ((inbuf->savedlen < 1) || (inbuf != topbuf)) { nextline (' '); }
          else { nextline (inbuf->carray[inbuf->savedlen]); }
	      }
        }
      }
    }
							/* Done with endofbuf; not a loop */
  if (forbufend || inputeof) { ch = nlch; }
  else {
    ch = inbuf->carray[inbuf->readx];
    inbuf->readx++;
    }
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, " savedlen=%d ", inbuf->savedlen);
    if (inputeof) { fprintf (log_, "inputeof "); }
    logchar (ch); }
#endif
}				/* inchar */

							/* skip to end of the current input line */
void
skiptoend (void) {
  boolean skip = true;
  while (skip) {
    if (inbuf == NULL) {
      skip = false;
      break;
      }
    if (inbuf->readx <= inbuf->savedlen) {
      if (inbuf->carray[inbuf->readx] == nlch) { skip = false; }
      else if (inbuf->carray[inbuf->readx] == etxch) { exitmacro (); }
      }
    inbuf->readx++;
    if (inbuf->readx > inbuf->savedlen) {
      if (inbuf->nextb != NULL) { inbuf = inbuf->nextb; }
      else { skip = false; }
      }
    }
}

							/* Move back in chbuf */
void
backup (void) {
  inbuf->readx--;
  ch = ' ';
}

/*--------------------------------------------------------------------*/

							/* Copy ch char into chbuf and get new ch */
void
pushch (void) {
  chbuf[chbufi] = ch;
  if (chbufi < CHBUFSIZ) { chbufi++; } else { fatal (4); }
							/* Leave 1 location free at the end of chbuf^ */
  inchar ();
}				/*pushch */

							/* Read complete line into chbuf */
void
readlatex (void) {
  while (ch != nlch) { pushch (); }
  newsymb = XLaTeX;
}

							/* Value of $+ */
int
argcount (arg * a) {
  int i = 0;
  if (a == NULL) { markerror (807); }
  while (a != NULL) {
    if (a->argbody != NULL) { i++; }
    a = a->nexta; }
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
    if (arlst == NULL) { fprintf (log_, "nil"); }
    else { fprintf (log_, "%d", odp (arlst)); }
    fprintf (log_, ",%d):", k);
  }
#endif
  if (k > 0) { ar = arlst; }
  else { ar = NULL; }
  j = k;
  while (i < j) { if (ar != NULL) { ar = ar->nexta; i++; } else { j = i; }
  }
#ifdef DDEBUG
  if (debuglevel > 0) {
    if ((i != k) || (ar == NULL)) { fprintf (log_, "not found\n"); }
    else { wrbuf (ar->argbody, 2); }
  }
#endif
  return ar;
}

							/* Start reading from file for copy "file" */
#ifndef SAFE_MODE
void
pointinput (nametype * txt) {
  int i;
  int FORLIM;
  if (txt == NULL) { return; }
  if (txt->segmnt == NULL) { return; }
  if (txt->len >= FILENAMELEN) { txt->len = FILENAMELEN - 1; }
  FORLIM = txt->len;
  for (i = 0; i < FORLIM; i++) { infname[i] = txt->segmnt[txt->seginx + i]; }
  infname[txt->len] = '\0';
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "Pointinput(segmnt %d, len %d) ", txt->seginx, txt->len);
    FORLIM = txt->len;
    for (i = 0; i < FORLIM; i++) { wchar(&log_,infname[i]); }
    putc ('\n', log_);
    }
#endif
  if (higherinbuf != NULL) { markerror (853); return; }
  if (checkfile(infname, true) != 0) {
    fprintf(errout, "Attempting to read file \"");
    FORLIM = txt->len;
    for (i = 0; i < FORLIM; i++) { wchar(&errout, infname[i]); }
    fprintf(errout, "\"\n");
    markerror(859);
    return;
    }
  if (copyin != NULL) { copyin = freopen ((char *) infname, "r", copyin); }
  else { copyin = fopen ((char *) infname, "r"); }
  if (copyin == NULL) { fatal (1); }
  backup ();
  ch = nlch;
  higherinbuf = inbuf;
  inbuf = NULL;
  inbufdepth = 1;
  lineno[1] = 0;
}

							/* Redirect output for print .. > "file" */
void
pointoutput (boolean create, nametype * txt, int *ier) {
  int i, FORLIM;
  if (txt == NULL) { *ier = 1; markerror (861); return; }
  else if (txt->segmnt == NULL) { *ier = 1; markerror (861); return; }
  *ier = 0;
  if (txt->len >= FILENAMELEN) { txt->len = FILENAMELEN - 1; }
  FORLIM = txt->len;
  for (i = 0; i < FORLIM; i++) {
    outfnam[i] = txt->segmnt[txt->seginx + i];
    if ((*ier) == 0) {
      if (!(isprint_ (outfnam[i]) && (outfnam[i] != ' '))) { *ier = 1; }
      }
    }
  outfnam[txt->len] = '\0';
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "Pointoutput(%s segmnt %d, len %d) \"",
	     create ? " TRUE" : "FALSE", txt->seginx, txt->len);
    FORLIM = txt->len;
    for (i = 0; i < FORLIM; i++) { wchar (&log_, outfnam[i]); }
    fprintf (log_, "\"\n");
    fflush (log_);
    }
#endif
  if ((*ier) != 0) { markerror (861); return; }
  if (create) {
    if (redirect != NULL) { redirect=freopen((char *) outfnam, "w", redirect);}
    else { redirect =  fopen ((char *)outfnam, "w"); }
    if (redirect == NULL) { markerror(876); fatal (8); }
    return; }
  if (redirect != NULL) { redirect=freopen((char *)outfnam, "a", redirect); }
  else { redirect =   fopen ((char *)outfnam, "a"); }
  if (redirect == NULL) { markerror(876); fatal (8); }
}

#endif

							/* Read string terminal into chbuf */
void
readstring (void) {
  int n;
  arg *ar;
  fbuffer *abuf;
  Char c;
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
      pushch (); }
    else if (c == '$') {
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
	        FORLIM = abuf->savedlen;
	        for (n = abuf->readx; n <= FORLIM; n++) {
	          chbuf[chbufi] = abuf->carray[n];
	          if (chbufi < CHBUFSIZ) { chbufi++; } else { fatal (4); }
	          }
	        abuf = abuf->nextb;
	        }
	      }
        }
      }
    } while (!((c == '"') || inputeof));
  if (!inputeof) { chbufi--; }
  instr = false;
#ifdef DDEBUG
  if (debuglevel > 0) {
    putc ('\n', log_);
    fprintf (log_, " readstring done, chbufi=%d |", chbufi);
    while (j < chbufi) {
      wchar(&log_,chbuf[j]);
      j++;
      }
    fprintf (log_, "| ");
    if (inputeof) { fprintf (log_, "inputeof "); }
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
    pushch (); }
  else if (ch == '+') {
    neg = false;
    pushch (); }
  else { neg = false; }
  if (isdigit (ch) == 0) { markerror (802); return; }
  do {
    k = (k * 10) + ch - '0';
    pushch ();
  } while (isdigit (ch) != 0);
  if (neg) { floatvalue *= exp (-k * ln10); }
  else { floatvalue *= exp (k * ln10); }
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
  if (initch == '.') { readfraction (); }
  else {
    while (isdigit (ch) != 0) {
      floatvalue = (10 * floatvalue) + ch - '0';
      pushch ();
      }
    if (ch == '.') {
      pushch ();
      readfraction ();
      }
    }
  if ((ch == 'e') || (ch == 'E')) { readexponent (); }
							/* A rather odd way to allow inch units */
  if (ch == 'i') { pushch (); }
  newsymb = Xfloat;
}

#ifdef DDEBUG
void
prlex (boolean acc) {
  int i, FORLIM;
  if (debuglevel <= 0) { return; }
  fprintf (log_, "\nLEXICAL(oldsymb=%d newsymb=%d)", oldsymb, newsymb);
  if (newsymb != XLaTeX) {
    fprintf (log_, " chbuf(%d:%d)=\"", oldbufi, chbufi - 1);
    FORLIM = chbufi;
    for (i = oldbufi; i < FORLIM; i++) { wchar(&log_,chbuf[i]); }
    putc ('"', log_); }
  else { fprintf (log_, "=<LaTeX>"); }
  if (newsymb == Xfloat) { wlogfl ("value", floatvalue, 0); }
  putc (' ', log_);
  logchar (ch);
  if (!acc) { fprintf (log_, " not accepted"); }
  putc ('\n', log_);
  consoleflush ();
}
#endif

			                /* Prepend a buffer to the left of current buf */
fbuffer *(prependbuffer (fbuffer * buf)) {
  fbuffer *prior;
  if (buf->prevb == NULL) { newbuf (&buf->prevb); }
  prior = buf->prevb;
  prior->attrib = buf->attrib;
  prior->higherb = buf->higherb;
  prior->savedlen = CHBUFSIZ;
  prior->readx = CHBUFSIZ + 1;
  prior->nextb = buf;
  return (buf->prevb);
}

                            /* Push macro or arg or string (from mac) into
                               the head of the input stream */
void
copyleft (fbuffer * mac, fbuffer ** buf, int macattr) {
  fbuffer *ml;
  int i, macix, neededspace;
  boolean neednewbuffer;
  boolean copied = false;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "copyleft(%d,%d,%d):\n", odp(mac), odp(*buf), macattr); }
  if (debuglevel > 1) {
    fprintf (log_, " input string"); wrbuf (mac, 3);
    fprintf (log_, " output"); wrbuf (*buf, 3); }
#endif
  if (mac != NULL) { while (mac->nextb != NULL) { mac = mac->nextb; } }
  while (mac != NULL) {
    if (mac->carray != NULL) {
      if (mac->savedlen >= mac->readx) {
	    copied = true;
	    if ((*buf) == NULL) { neednewbuffer = true; }
        else if ((*buf)->attrib >= 0) { neednewbuffer = true; } /* for */
	    else { neednewbuffer = false; }
	    if (neednewbuffer) {
	      newbuf (&ml);
	      if (macattr == 0) { ml->attrib = mac->attrib; }
          else { ml->attrib = macattr; }
	      ml->savedlen = CHBUFSIZ;
	      ml->readx = CHBUFSIZ + 1;
	      ml->higherb = *buf;
	      *buf = ml; }
        }
      macix = mac->savedlen;
      neededspace = (mac->savedlen - mac->readx + 1);
      if (neededspace > (*buf)->readx - 1) {
	    while ((*buf)->readx > 1) {
	      (*buf)->readx--;
	      (*buf)->carray[(*buf)->readx] = mac->carray[macix];
	      macix--; }
	    *buf = prependbuffer (*buf);
        }
      for (i = macix; i >= mac->readx; i--) {
	    (*buf)->readx--;
	    (*buf)->carray[(*buf)->readx] = mac->carray[i];
        }
      }
    mac = mac->prevb;
    }
  if (copied) {
#ifdef DDEBUG
    if (debuglevel > 0) {
      fprintf (log_, " copyleft result\n"); wrbuf (*buf, 3); }
#endif
                            /* precede the leftmost char with an ETX */
    if ((*buf)->readx <= 1) { *buf = prependbuffer (*buf); }
    (*buf)->carray[(*buf)->readx - 1] = etxch;
    }
}

							/* $n has been seen in a macro argument; append the
   							   body to the tail of the input stream */
void
copyright (fbuffer * mac, fbuffer ** buf) {
  fbuffer *ml;
  int i, macreadx, spaceneeded;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "copyright:\n input"); wrbuf (mac, 3);
    fprintf (log_, " output"); wrbuf (*buf, 3); }
#endif
  while (mac != NULL) {
    if ((*buf) == NULL) {
      newbuf (buf);
      (*buf)->attrib = -1;
      (*buf)->savedlen = 0;
      (*buf)->readx = 1;
      }
    macreadx = mac->readx;
    spaceneeded = mac->savedlen - macreadx + 1;
    if (spaceneeded > CHBUFSIZ - (*buf)->savedlen) {
      while ((*buf)->savedlen < CHBUFSIZ) {
	    (*buf)->savedlen++;
	    (*buf)->carray[(*buf)->savedlen] = mac->carray[macreadx];
	    macreadx++; }
      newbuf (&ml);
      ml->attrib = (*buf)->attrib;
      ml->prevb = *buf;
      (*buf)->nextb = ml;
      *buf = ml;
      }
    for (i = macreadx; i <= mac->savedlen; i++) {
      (*buf)->savedlen++;
      (*buf)->carray[(*buf)->savedlen] = mac->carray[i];
      }
    mac = mac->nextb;
    }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, " result"); wrbuf (*buf, 3); }
#endif
}

							/* Check the current char for line continuation */
void
skipcontinue (boolean instrg) {
  Char c;
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, "\n skipcontinue readx=%d ", inbuf->readx); }
#endif
  c = ch;
  while (c == bslch) {
    if (inbuf->readx <= inbuf->savedlen) { c = inbuf->carray[inbuf->readx]; }
    else if (inbuf->nextb == NULL) {
      inchar ();
      c = ch; }
    else { c = inbuf->nextb->carray[inbuf->nextb->readx]; }
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
skipwhite (void) {/* D if debuglevel = 2 then writeln(log, 'skipwhite: ' ); D */
  while ((ch == etxch) || (ch == nlch) || (ch == tabch) || (ch == ' ')) {
    if (ch == etxch) { exitmacro (); }
    inchar ();
    if (ch == bslch) { skipcontinue (false); }
    }
}

							/* Stash the arg body into the arg struct */
void
copyargbody (int *parenlevel, fbuffer ** p2) {
  int j, n, bracketlevel;
  arg *ar;
  fbuffer *p;
  fbuffer *p1 = NULL;
  boolean inarg, instring;
  Char prevch;

  skipwhite ();
  bracketlevel = 0;
  if ((*parenlevel) >= 0) { inarg = true; } else { inarg = false; }
  while (inarg) {
    newbuf (&p);
    p->attrib = -1;
    if (p1 != NULL) { p1->nextb = p; p->prevb = p1; }
    p1 = p;
    j = CHBUFSIZ;
    instring = false;
    prevch = ' ';
    do {
      if (prevch != bslch) {
	    if (instring && (ch == '"')) { instring = false; }
        else if (ch == '"') { instring = true; }
        }
      if (!instring) {
	    if (ch == '[') { bracketlevel++; }
        else if (ch == ']') { bracketlevel--; }
	    else if (ch == '(') { (*parenlevel)++; }
        else if (ch == ')') { (*parenlevel)--; }
        }
      if ((!instring) && (bracketlevel == 0) && 
          (((*parenlevel) < 0) || (((*parenlevel) == 0) && (ch == ',')))) {
	    j = p1->savedlen; inarg = false; }
      else if (ch != '$') {
	    prevch = ch;
        p1->savedlen++; 
	    p1->carray[p1->savedlen] = ch;
	    inchar ();
        }
      else {                /* $ found in a macro arg */
    	prevch = ch;
    	inchar ();
    	if (isdigit (ch) != 0) {
    	  n = 0;
    	  do {
    	    n = (n * 10) + ch - '0';
    	    inchar ();
    	  } while (isdigit (ch) != 0);
    	  ar = findarg (args, n);
    	  if (ar != NULL) { copyright (ar->argbody, &p1); }
          }
        else {
          p1->savedlen++; 
    	  p1->carray[p1->savedlen] = prevch;
    	  }
        }
      if (inputeof) {
	    markerror (805);
	    j = p1->savedlen;
	    inarg = false;
	    *parenlevel = -1;
        }
    } while (p1->savedlen != j);
    }
  if (p1 != NULL) { while (p1->prevb != NULL) { p1 = p1->prevb; } }
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
    if (seg1 == NULL) { fprintf (log_, " seg1 == NULL"); }
    if (seg2 == NULL) { fprintf (log_, " seg2 == NULL"); }
    }
#endif
  if ((seg1 == NULL) || (seg2 == NULL)) {
    k = maxint;
    return k;
    }
  k = 0;
  if (len1 < len2) { j = len1; } else { j = len2; }
  while (i < j) {
#ifdef DDEBUG
    if (debuglevel == 2) {
      fprintf (log_, "(%c%c)", seg1[inx1 + i], seg2[inx2 + i]); }
#endif
    k = seg1[inx1 + i] - seg2[inx2 + i];
    if (k == 0) { i++; } else { j = i; }
    }
  if (k != 0) { return k; }
  if (len1 > len2) { k = seg1[inx1 + i]; }
  else if (len1 < len2) { k = -seg2[inx2 + i]; }
#ifdef DDEBUG
  if (debuglevel == 2) { fprintf (log_, " i=%d j=%d eqstring=%d\n", i, j, k); }
#endif
  return k;
}

							/* Look for given macro name */
arg
  *(findmacro (arg * p, Char * chb, chbufinx inx, chbufinx toklen,
      arg ** last)) {
  arg *pj = NULL;
  *last = NULL;
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf (log_, "findmacro:");
    snapname (chb, inx, toklen); putc ('\n', log_);
    fflush (log_); }
#endif
  if (p != NULL) {
    while (p != pj) {
      if (p->argbody == NULL) { *last = p; p = p->nexta; }
      else if (eqstring(p->argbody->carray, 1, -(p->argbody->attrib),
                        chb, inx, toklen) == 0) { pj = p; }
      else { *last = p; p = p->nexta; }
      }
    }
  return p;
}

							/* Get and initialize an arg from the
   								old-arg stack or make a new one */
void
newarg (arg ** ar) {
  if (freearg == NULL) { *ar = malloc (sizeof (arg));
    if (*ar==NULL){ fatal(9); } }
  else { *ar = freearg; freearg = freearg->nexta; }
  (*ar)->argbody = NULL;
  (*ar)->highera = NULL;
  (*ar)->nexta = NULL;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf (log_, " newarg[%d]\n", odp (*ar)); }
#endif
}

							/* Check for macro name */
boolean
ismacro (Char * chb, chbufinx obi, chbufinx chbi) {
  arg *mac, *lastp, *ar;
  arg *lastarg = NULL, *firstarg = NULL;
  int argdepth;
  boolean ism = false;
#ifdef DDEBUG
  int i;
  if (debuglevel > 0) {
    fprintf (log_, "\nismacro[");
    for (i = obi; i < chbi; i++) { wchar (&log_,chb[i]); }
    fprintf (log_, "]:"); }
#endif
  if (oldsymb == Xdefine) { skipwhite (); }
  else if (oldsymb != Xundefine) {
    mac = findmacro (macros, chb, obi, chbi - obi, &lastp);
    if (mac != NULL) {
      ism = true;
      if (ch == '(') { argdepth = 0; }
      else { backup (); argdepth = -1; } /* this macro has no arguments */
      do {
        newarg (&ar);
        ar->highera = args;
        if (lastarg == NULL) { firstarg = ar; } else { lastarg->nexta = ar; }
        if (argdepth >= 0) {
          inchar ();
          copyargbody (&argdepth, &ar->argbody);
          }
        lastarg = ar;
      } while (argdepth >= 0);
      args = firstarg;
      copyleft (mac->argbody, &inbuf, 0);
      }
    }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf (log_, "\nismacro returning:%5s\n", ism ? "TRUE" : "FALSE"); }
#endif
  if (ism) { currentmacro = mac; }
  return ism;
}

                            /* Push an argument to the left of the
                               input stream */
void
expandarg (Char * chb, chbufinx chbs, chbufinx chbi) {
  int n = 0;
  int i;
  arg *ar;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "\nexpandarg(");
    for (i = chbs; i < chbi; i++) { wchar(&log_,chb[i]); }
    fprintf(log_, ") "); }
#endif
  for (i = chbs + 1; i < chbi; i++) { n = (n * 10) + chb[i] - '0'; }
  ar = findarg (args, n);
  backup ();
  if (ar != NULL) {
    if (ar->argbody != NULL) { copyleft (ar->argbody, &inbuf, -1); } }
}

							/* Check for $+ or else copy arg */
boolean
insertarg (void) {
  int icx;

  pushch ();
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, "\n insertarg $"); wchar(&log_, ch);
    putc('\n', log_); }
#endif
  if (ch == '+') {
    backup ();
    ch = '$';
    chbufi--;
    return false;
    }
  else {
    icx = chbufi - 1;
    while (isdigit (ch) != 0) { pushch (); }
    expandarg (chbuf, icx, chbufi);
    chbufi = icx;
    inchar ();
    return true;
    }
}

boolean
illegalchar(Char c) {
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "Marking 800: chr(%d)\"", c);
    wchar(&log_, c);
    fprintf(log_, "\" invalid\n");
    }
#endif
  fprintf(errout, "Character chr(%d)\"", c);
  wchar(&errout, c);
  fprintf(errout, "\" invalid\n");
  markerror(800);
  return false;
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
  fbuffer *currbuf;

  lexsymb = -1;
  do {
    terminalaccepted = true;
    oldbufi = chbufi;		     /* first char of current terminal in chbuf */
    while ((ch == ' ') || (ch == tabch)) { inchar (); }
	/* lexstate is
       0 before .PS or after .PE
       1 when .PS found
       2 between .PS and .PE
       3 when .PE found
       4 to process .PE */
    if (lexstate == 1) {
      newsymb = DotPS;
      lexstate = 2; }
    else if (lexstate == 3) {
      newsymb = DotPE;
      lexstate = 4; }
    else if (lexstate == 4) {
      newsymb = Xnewline;
      skiptoend ();
      ch = ' ';
      lexstate = 0; }
    else if (inputeof) {
      newsymb = 0; }
    else if (forbufend) {
      newsymb = Xendfor;
      forbufend = false;
      ch = ' '; }
    else if (ch == nlch) {
      newsymb = Xnewline;
      ch = ' ';
      if ((oldsymb == Xelse) || (oldsymb == Xleftbrace) ||
	    (oldsymb == Xthen) || (oldsymb == Xcolon) || (oldsymb == Xnewline)) {
	    terminalaccepted = false; } }
    else if (isdigit (ch) != 0) {
      readconst (ch); }
    else if (ch == etxch) {
      exitmacro ();
      inchar ();
      terminalaccepted = false; }

    else {
      firstch =  ch;
      pushch ();
							/* Continuation, comment, constant, latex */
      currbuf = inbuf;
      if (firstch == bslch) {
	    if ((ch == nlch) || (ch == '#')) {
	      if (ch == '#') { skiptoend (); }
	      ch = ' ';
	      newsymb = -2;		/* flag for test below */
	      terminalaccepted = false; }
        else { readlatex (); } }
      else if ((firstch == '.') && (isdigit (ch) != 0)) {
	    readconst (firstch); }
      else if ((firstch == '.') && (currbuf->readx == 3) &&
		 (inbuf->prevb == NULL) && (newsymb != (-2))) {
	    readlatex (); }
							/* Use the lexical tables to identify
       							terminals, checking for macro names */
      else {
	    newsymb = entrytv[firstch];
	    lxix = entryhp[firstch];
	    while (lxix != 0) {
	      if (ch == '$') {
            if (!insertarg ()) { lxix = 0; }
	        continue;
	        }
	      if (lxch[lxix] == ch) {
	        newsymb = lxtv[lxix];
	        lxix = lxhp[lxix];
	        pushch (); }
          else { lxix = lxnp[lxix]; }
	      }
							/* Check for Label or macro */
	if ((isupper (firstch) != 0) &&
	    ((isalnum (ch) != 0) || (ch == '_') || (ch == '$'))) {
	  looping = true;
	  while (looping) {
	    if (ch == '$') { looping = insertarg (); }
        else if ((isalnum (ch) != 0) || (ch == '_')) { pushch (); }
        else { looping = false; }
	    }
	  if (ismacro (chbuf, oldbufi, chbufi)) { terminalaccepted = false; }
      else { newsymb = Xlabel; } }

							/* Check for name or macro */
    else if (((isalnum (firstch) != 0) || (firstch == '_')) &&
		   ((isalnum (ch) != 0) || (ch == '_') || (ch == '$'))) {
	  looping = true;
	  while (looping) {
	    if (ch == '$') { looping = insertarg (); }
        else if ((isalnum (ch) != 0) || (ch == '_')) { pushch (); }
        else { looping = false; }
	    }
	  if (ismacro (chbuf, oldbufi, chbufi)) { terminalaccepted = false; }
      else { newsymb = Xname; } }

    else if (newsymb == Xstring) {
	  chbufi--;
	  readstring (); }
    else if (newsymb == Xcomment) {
	  skiptoend ();
	  ch = nlch;
	  terminalaccepted = false;
	  }
    else if ((newsymb == Xlt) && inlogic) {
	  lexsymb = Xcompare;
	  newsymb = Xcompare; }
							/* Skip after designated terminals */
	else if ((newsymb == Xnewline) &&
		 ((oldsymb == Xelse) || (oldsymb == Xleftbrace) ||
		  (oldsymb == Xthen) || (oldsymb == Xcolon) ||
		  (oldsymb == Xnewline))) {
	  terminalaccepted = false; }
							/* Multiple-valued terminals */
    else if ((newsymb > Xeq) && (newsymb <= Xremeq)) {
	  lexsymb = newsymb;
	  newsymb = Xeq; }
	else if (newsymb > Xcorner) {
	  lexsymb = newsymb;
	  if (newsymb > Xenvvar) { newsymb = Xenvvar; }
      else if (newsymb > Xprimitiv) { newsymb = Xprimitiv; }
      else if (newsymb > Xdirecton) { newsymb = Xdirecton; }
      else if (newsymb > Xarrowhd) { newsymb = Xarrowhd; }
      else if (newsymb > Xtextpos) { newsymb = Xtextpos; }
      else if (newsymb > Xcolrspec) { newsymb = Xcolrspec; }
      else if (newsymb > Xlinetype) { newsymb = Xlinetype; }
      else if (newsymb > Xfunc2) { newsymb = Xfunc2; }
      else if (newsymb > Xfunc1) { newsymb = Xfunc1; }
      else if (newsymb > Xparam) { newsymb = Xparam; }
      else if (newsymb > Xcompare) { newsymb = Xcompare; }
      else { newsymb = Xcorner; } }

    else if (newsymb == Xarg) {
	  if (ch == '+') {	/* $+ */
	    floatvalue = argcount (args);
	    newsymb = Xfloat;
	    inchar (); }
      else if (isdigit (ch) != 0) {	/* $<integer> */
	    do { pushch (); } while (isdigit (ch) != 0);
	    expandarg (chbuf, oldbufi, chbufi);
	    terminalaccepted = false; }
      else { markerror (807); } }

    else if (newsymb == Xdo) { skipwhite (); }
#ifdef DDEBUG
	else if (newsymb == Xampersand) {
	  chbufi = oldbufi;
	  if (ch >= 'A') { /* linesignal = ch - 'A' + 1; */ }
      else if (ch > '0') {
	    if (oflag <= 0) { openlogfile (); }
	    debuglevel = ch - '0'; }
      else if (ch == '0') { debuglevel = 0; }
	  fprintf (log_, "Debuglevel = %d\n", debuglevel);
	  consoleflush ();
	  inchar ();
	  terminalaccepted = false;
	  }
#endif
							/* Label, second possibility */
	else if ((newsymb == 0) && (isupper (firstch) != 0)) {
	  if (ismacro (chbuf, oldbufi, chbufi)) { terminalaccepted = false; }
      else { newsymb = Xlabel; } }
							/* name, second possibility */
      else if ((newsymb == 0) &&
		   ((isalnum (firstch) != 0) || (firstch == '_'))) {
	    if (ismacro (chbuf, oldbufi, chbufi)) { terminalaccepted = false; }
        else { newsymb = Xname; } }
	                        /* char not recognized */
      else if (newsymb == 0) { terminalaccepted = illegalchar(firstch); }
      }
    }				/* end of lookahead terminals */
#ifdef DDEBUG
    prlex (terminalaccepted);
#endif
    if ((newsymb != XLaTeX) && (newsymb != Xstring) &&
	  (newsymb != Xlabel) && (newsymb != Xname)) { chbufi = oldbufi; }
  } while (!terminalaccepted);

  if (lexsymb == (-1)) { lexsymb = newsymb; }
  oldsymb = newsymb;
							/* construct the attribute */
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
  if (debuglevel == 2) { fprintf (log_, "\nskiptobrace: \n"); }
#endif
  while (bracelevel > 0) {
    if (ch == bslch) { skipcontinue (instring); }
    if (ch == etxch) { exitmacro (); }
    if (instring) {
      if ((ch == '"') && (prevch != bslch)) { instring = false; } }
    else if (ch == '{') { bracelevel++; }
    else if (ch == '}') { bracelevel--; }
    else if (ch == '"') { instring = true; }
    if (bracelevel <= 0) { break; }
    if (inputeof) {
      bracelevel = 0;
      if (instring) { markerror (806); } else { markerror (804); } }
    else {
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
    while ((*buf)->prevb != NULL) { *buf = (*buf)->prevb; } }
  while ((*buf) != NULL) {
    bu = (*buf)->nextb;
    if (((*buf)->carray) != NULL) { Free ((*buf)->carray); }
    Free (*buf);
    *buf = bu;
    }
}

                            /* Get the file name from the command
                               line argument                   */
void
P__argv (char *s, int len, int n) {
  char *cp;
  if ((unsigned) n < P_argc) { cp = P_argv[n]; } else { cp = ""; }
  while (*cp && --len >= 0) { *s++ = *cp++; }
  while (--len >= 0) { *s++ = ' '; }
}

void
openfiles (void) {
  int i = 1, j = FILENAMELEN+1;
  higherinbuf = NULL;
  output = stdout; input = stdin;
  if (argct >= P_argc) { return; }
  P__argv ((char *)infname, sizeof (mstring), argct);
  while (i < j) { if (infname[i-1] != ' ') { i++; } else { j = i; } }
  infname[i-1] = '\0';
                            /* Open the main input file        */
  if (checkfile (infname, true) != 0) { fatal (1); }
  if (input != NULL) { input = freopen ((char *)infname, "r", input); }
  else { input = fopen ((char *)infname, "r"); }
  if (input == NULL) { fatal (1); }
#ifdef DDEBUG
  if (oflag <= 0) { return; }
  openlogfile ();
  debuglevel = oflag;
  fprintf (log_, "Input file: ");
  i = 1;
  j = FILENAMELEN;
  while (j >= i) {
    if ((infname[j - 1] == ' ') || (infname[j - 1] == '\0')) { j--; }
    else { i = j + 1; }
    }
  for (i = 0; i < j; i++) { putc (infname[i], log_); }
  putc ('\n', log_);
#endif
}

							/* Separate out the option character */
Char
optionchar (Char * fn) {
  int j = 1, k = FILENAMELEN + 1;
  while (j < k) { if (fn[j - 1] == ' ') { j++; } else { k = j; } }
  if (j >= FILENAMELEN) { return '\0'; }
  else if (fn[j - 1] == '-') { return (fn[j]);
	/* if fn[j+2] <> ' ' then for k:=j+2 to FILENAMELEN do fn[k-j-1] := fn[k] */
    }
  else { return '\0'; }
}

							/* Set safe mode and one of 12 output formats.
                               The version date is set during preprocessing */
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
    P__argv ((char *)infname, sizeof (mstring), argct);
    cht = optionchar (infname);
    if (cht == 0) {
      istop = argct;
      continue;
      }
    if (cht == 'd') { drawmode = PDF; }
    else if (cht == 'e') { drawmode = Pict2e; }
    else if (cht == 'f') { drawmode = PSfrag; }
    else if (cht == 'g') { drawmode = PGF; }
    else if (cht == 'm') { drawmode = MFpic; }
    else if (cht == 'p') { drawmode = PSTricks; }
    else if (cht == 'r') { drawmode = PS; }
    else if (cht == 's') { drawmode = MPost; }
    else if (cht == 't') { drawmode = tTeX; }
    else if (cht == 'v') { drawmode = SVG; }
    else if (cht == 'x') { drawmode = xfig; }
    else if (cht == 'z') { safemode = true; }
#ifdef DDEBUG
    else if (isdigit (cht)) { oflag = cht - '0'; }
#endif
    else if ((cht == 'h') || (cht == '-')) {
      fprintf (errout, " *** dpic version %s\n",VERSIONDATE);
#ifdef DDEBUG
      openlogfile ();
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
      fatal (0); }
    else {
      fprintf (errout, " *** dpic terminating: Unknown option ");
      if (isprint_ (cht)) { fprintf (errout, "\"%c\"\n", cht); }
      else { fprintf (errout, "\"char(%d)\"\n", cht); }
#ifdef DDEBUG
      openlogfile ();
#endif
      fatal (0);
      }
    argct++;
    }
}				/* getoptions */

int
main (int argc, char * argv[]) {
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
  initrandom ();

  chbuf = malloc (sizeof (chbufarray)); if (chbuf==NULL){ fatal(9); }
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf (log_, "new(chbuf)[%d]\n", odp (chbuf)); }
#endif
  entrytv[ordNL] = Xnewline;
  entrytv[ordCR] = Xnewline;		/* treat ^M as line end */

  errcount = 0;
							/* change for debugging */
							/* linesignal := 0; */

  preproduce (-2);
  printstate = 0;

							/* lexical initializations, see also
     							production -1 */
  ch = ' ';
  inbufdepth = 0;
  lineno[0] = 0;
  chbufi = 0;
  oldbufi = 0;
  newsymb = Xnewline;
  oldsymb = Xnewline;
  lexstate = 0;
  macros = NULL;
  args = NULL;
  currentmacro = NULL;
  forbufend = false;
  instr = false;

  preproduce (-1);

  int yyparse ();
  int yyyperr;
  yyyperr = yyparse ();

  epilog ();
  if (input != NULL) { fclose (input); }
  if (output != NULL) { fclose (output); }
  if (errout != NULL) { fclose (errout); }
  if (copyin != NULL) { fclose (copyin); }
  if (redirect != NULL) { fclose (redirect); }
#ifdef DDEBUG
  if (log_ != NULL) { fclose (log_); }
#endif
  if ((errcount == 0) && (yyyperr == 0)) { exit (EXIT_SUCCESS); }
  else { exit (EXIT_FAILURE); }
}				/* dpic */

