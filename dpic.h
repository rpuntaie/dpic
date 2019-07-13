#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define distmax         3.40282347e+38	/*assumes at least IEEE single */
#define MaxReal         distmax
#define mdistmax        (-distmax)
#define pi              3.1415926535897931
#define ln10            2.3025850929940459

#define maxint          2147483647L
#define randmax         maxint

#define HASHLIM         9	/* Hash array upper val for var names */
#ifndef true
#define true    1
#define false   0
#endif

#include	"lxvars.h"
#include	"VERSIONDATE.h"

/* #define Free(p)     (free((void)(p)), (p)=NULL) */
#define Free(p)	free(p)

/* Machine constants                  */
/* Assume simple ASCII; forget EBCDIC */
#define ordMINCH        0
#define ordMAXCH        127
#define ordNL           10
#define ordTAB          9
#define ordCR           13
#define ordETX          3
#define ordBSL          92

#define nlch            ((Char)ordNL)
#define tabch           ((Char)ordTAB)
#define crch            ((Char)ordCR)
#define etxch           ((Char)ordETX)
#define bslch           ((Char)ordBSL)

#define CHBUFSIZ        4095	/* upper limit of chbuf buffers       */

/* Lexical parameters                 */
#define FILENAMELEN     1024	/* max length of file names */

/* Lalr machine parameters            */
#define MAXERRCOUNT     3	/* max no of errors before giving up  */

                            /* Draw types                         */
#define MFpic           1
#define MPost           2
#define PDF             3
#define PGF             4
#define Pict2e          5
#define PS              6
#define PSfrag          7
#define PSTricks        8
#define SVG             9
#define TeX             10
#define tTeX            11
#define xfig            12

#define SPLT            0.551784	/* optimum spline tension for arcs    */

#define pointd          72
                            /* postprocessor constants (vars?)    */
#define xfigres         1200
#define xdispres        80
                            /* Text parameters (vars?)            */
#define DFONT           11	/* default svg font size, pt          */

#define Char char
typedef unsigned char uchar;
typedef unsigned char boolean;

                            /* Lexical types                      */
typedef short chbufinx;

typedef int symbol;

typedef short lxinx;

typedef uchar production;

typedef Char chbufarray[CHBUFSIZ + 1];
typedef Char mstring[FILENAMELEN];

                            /* Environment variable index         */
typedef uchar environx;

                            /* For storing names                  */
typedef struct nametype {
  double val;
  Char *segmnt;
  chbufinx seginx;
  int len;
  struct nametype *next_;
} nametype;

                            /* Lexical input for loops and macros */
typedef struct fbuffer {
  Char *carray;
  int savedlen, readx, attrib;
  struct fbuffer *higherb, *prevb, *nextb;
} fbuffer;

                            /* Macro argument list pointer        */
typedef struct arg {
  fbuffer *argbody;
  struct arg *highera, *nexta;
} arg;

                            /* Pic position                       */
typedef struct postype {
  double xpos, ypos;
} postype;

                            /* Data structures for drawn primitives */
#define PRIMbase \
  nametype *name, *textp, *outlinep, *shadedp; \
  struct primitive *parent, *son, *next_; \
  postype aat; \
  double lparam, lthick; \
  int direction, spec, ptype

#define PRIMbox \
    struct { double boxheight, boxwidth, boxfill, boxradius; } Ubox

#define PRIMblock \
    struct { \
      double blockheight, blockwidth; \
      postype here; \
      nametype *(vars[HASHLIM + 1]); \
      int nvars[HASHLIM + 1]; \
      double *env; \
    } UBLOCK

#define PRIMcircle \
    struct { double cfill, radius; } Ucircle

#define PRIMellipse \
    struct { double elheight, elwidth, efill; } Uellipse

#define PRIMline \
    struct { \
      postype endpos; \
      double height, width, lfill, aradius; \
      int atype; \
    } Uline

                            /* General and block primitives */
typedef struct primitive {
  PRIMbase;
  union {
    PRIMbox;
    PRIMblock;
    PRIMcircle;
    PRIMellipse;
    PRIMline;
  } Upr;
} primitive;

typedef struct XLboxprimitive {
  PRIMbase;
  union {
    PRIMbox;
  } Upr;
} XLboxprimitive;

typedef struct XLcircleprimitive {
  PRIMbase;
  union {
    PRIMcircle;
  } Upr;
} XLcircleprimitive;

typedef struct XLellipseprimitive {
  PRIMbase;
  union {
    PRIMellipse;
  } Upr;
} XLellipseprimitive;

typedef struct XLlineprimitive {
  PRIMbase;
  union {
    PRIMline;
  } Upr;
} XLlineprimitive;

typedef struct XLabelprimitive {
  PRIMbase;
} XLabelprimitive;

                            /* Parse stack production attributes */
typedef struct attribute {
  chbufinx chbufx;
  int toklen;
  primitive *prim, *internal;
  nametype *varname;
  double xval, yval, startchop, endchop;
  int lexval, state;
} attribute;

                            /* External files                 */
FILE *input, *output, *errout, *copyin, *redirect;

#ifdef DDEBUG
FILE *log_;
int oflag, debuglevel;	/* debug level and open logfile flag  */
arg *currentmacro;		/* last-found macro                   */
#endif

mstring infname;		/* name of current input file    */
mstring outfnam;		/* name of current output file   */

boolean inputeof;		/* end-of-input flag                  */
boolean forbufend;		/* end of for buffer                  */
int argct;			    /* argument counter for options   */
int drawmode;			/* output conversion                  */
boolean safemode;		/* disable sh and copy                */

                        /* Lexical analyzer character buffer  */
Char *chbuf;
chbufinx chbufi, oldbufi;	/* character buffer indices       */

                        /* Lexical variables                  */
Char ch;			    /* current character                  */
short newsymb;			/* current lexical symbol             */
int lexsymb;			/* lexical value                      */
int lexstate;			/* 0..4: <.PS; .PS; in pic; .PE; >.PE */
boolean inlogic;		/* set < to <compare> in context      */
boolean instr;			/* set while reading a string         */
double floatvalue;		/* numerical value of float read      */
fbuffer *inbuf, *savebuf, *freeinbuf, *topbuf;

int oldsymb;			/* last lexical symbol                */
arg *macros, *args, *freearg;	/* lists of macros and args   */

                        /* Error handling                     */
int errcount;			/* becomes nonzero when errors found  */
int lineno;			    /* current input line number          */
int currprod;			/* current production for error msgs  */

						/* Production variables               */
attribute forattr;      /* to set up for loop                 */
primitive *envblock;	/* block containing the current scope */
primitive *tail;		/* for tree branches                  */
primitive *globalenv;	/* the global environment block       */
double dptextratio;		/* text parameters for SVG,PDF,PS     */
double dpPPI;			/* pixels per inch                    */

double north, south, east, west;
double xfheight;		/* for calculating xfig and svg coords*/
Char *freeseg;			/* segment open to store strings      */
short freex;			/* next free location                 */
Char *tmpbuf;			/* buffer for snprintf or sprintf     */
Char *tmpfmt;			/* snprintf, findvar buffer           */
double scale, fsc;		/* scale factor and final scale factor*/
int splcount, spltot;	/* spline depth counter               */
int pdfobjcount;		/* pdf objects                        */
primitive *snode;		/* temporary node storage             */
boolean bfill;			/* fill flag for linear objects       */
double vfill;			/* fill value */
nametype *sshade, *soutline;	/* temp values for linear objects     */
double lastfillval;		/* last-used fill density             */
int printstate;			/* for passing output state info      */
/* graphics state parameters          */
boolean gsocolor, gsfcolor, gsgcolor;
    /* stroke, fill, gray fill flags      */
double gslinethick;		/* last-used line thickness           */
int gslinecap, gslinejoin;	/* 0 = butt                        */
double gsdashw, gsdashs;	/* line dash and space lengths        */
nametype *stream, *cx;		/* pdf stream storage and current seg */
int pdfoffs[8];			/* pdf output byte counts       */

attribute *pyylval;
