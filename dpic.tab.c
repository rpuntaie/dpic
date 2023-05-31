/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 37 "dpic.y" /* yacc.c:339  */

#define EXTRN extern
#include "dpic.h"
#define Rnd(x)	(x<0?(-(long)floor(-x+0.5)):((long)floor(x + 0.5)))

#define envinx(x)	blockparms.env[(int)(Rnd(x)-Xenvvar-1)]

void yyerror(char const *);

boolean hasoutline(int, boolean);
boolean hasshade(int, boolean);
boolean isprint_(Char);
boolean teststflag(int, int);
double findvar(char *, int);
double intpow(double, int);
double linlen(double, double);
double pheight(primitive *);
double pwidth(primitive *);
double venv(primitive *, int);
int bval(Char *);
int cmpstring(primitive *, primitive *);
int getstval(int);
int putstring(int, nametype *, Char *, chbufinx, chbufinx);
int varhash(Char *, chbufinx, chbufinx);
primitive *( findenv(primitive *));
primitive *( findplace(primitive *, Char *, chbufinx, chbufinx));
primitive *( sprintfstring( attribute *, attribute *, int ));
void addsuffix(Char *, chbufinx *, int *, double, int, double );
void appendthen(primitive **);
void appendstring(nametype *, Char *, chbufinx, chbufinx);
void attcopy(int,int);
void attreduce(int,int);
void checkjust(nametype *, boolean *, boolean *, boolean *, boolean *);
void clearchbuf(chbufinx, int);
void consoleflush(void);
void copyprim(primitive *, primitive **);
void copystr(nametype **, nametype *);
void corner(primitive *, int, double *, double *);
void deletefreeargs(arg **);
void deletefreeinbufs(fbuffer **);
void deletename(nametype **);
void deletestringbox(primitive **);
void deletetree(primitive **);
void dodefhead( attribute *);
void donamedobj(attribute *);
void mkOptionVars(void);
void doundefine( attribute * );
void eqop(double *, int, double);
void FindExitPoint(primitive *, postype *);
void getnesw(primitive *);
void getscale(double, double, primitive *, double *, double *);
void inheritenv(primitive *);
void initnesw(void);
void inittwo(void);
void lineardir(primitive *, double, double, int *);
void makevar(char *, int, double);
void markerror(int);
void marknotfound(int, Char *, chbufinx, chbufinx);
void nesw(primitive *);
void neswrec(primitive *);
void newbuf(fbuffer **);
void newprim(primitive **, int, primitive *);
void newstr(nametype **);
void putbval(Char *, int);
void queueprim( primitive *, primitive * );
void readfor(fbuffer *, int, fbuffer **, Char, boolean);

void resetenv(int, primitive *);
void resetscale(double, int, primitive *);
void scaleobj(primitive *, double);
void setangles(double *, double *, postype, double, double, double, double);
void setspec(int *, int);
void setstflag(int *, int);
void setstval(int *, int);
void setthen(int *);
void shift(primitive *, double, double);
void skipwhite(void);
void storestring(nametype *, Char *, chbufinx, chbufinx, int);
void wchar(FILE **, Char);
void wrbuf(fbuffer *, int);

#ifdef DDEBUG
int lspec(int);
void logaddr(fbuffer *);
void prattribute(char *, attribute *);
void printobject(primitive *);
void prvars(primitive *);
void snapname(Char *, chbufinx, chbufinx);
void wrbufaddr(fbuffer *, int);
extern void logpos(char *, postype );
extern void logspec(int );
extern int ordp(void *);
extern int odp(void *);
extern int ahnum(int);
extern void prtstval(int);
extern void snaptree(primitive *, int);
extern void snaptype(FILE **, int);
#endif

nametype *( findname(primitive *, Char *, chbufinx, chbufinx, nametype **,
  int *));
nametype *( glfindname(
  primitive *, Char *, chbufinx, chbufinx, nametype **, int *) );
primitive *( nthprimobj(primitive *, int, int) );

extern arg *(findmacro(arg *, Char *, chbufinx, chbufinx, arg **));
extern boolean isthen(primitive *);
extern boolean ismdistmax(double);
extern double datan(double, double);
extern double Max(double, double);
extern double Min(double, double);
extern double principal(double, double);
extern int ahlex(int);
extern int eqstring(Char *, chbufinx, chbufinx, Char *, chbufinx, chbufinx);
extern int Floor(double);
extern int pahlex(int, int);
extern int pahnum(int, int);
extern int yylex(attribute *);
extern postype arcend(primitive *);
extern postype arcstart(primitive *);
extern void backup(void);
extern void copyleft(fbuffer *mac, fbuffer **buf, int attr);
extern void disposeargs(arg **);
extern void disposebufs(fbuffer **);
extern void drawtree(double, double, double, double, primitive *);
extern void fatal(int);
extern void inchar(void);
extern void newarg(arg **);
extern void pointinput(nametype *);
extern void pointoutput(boolean, nametype *, int *);
extern void P__argv(char*, int, int);
extern void setjust(nametype *, int);
extern void skipcontinue(boolean);
extern void skiptobrace(void);
extern void skiptoend(void);
extern void wcoord(FILE **, double, double);
extern void wfloat(FILE **, double);
extern void wpair(FILE **, double, double);
extern void wstring(FILE **, nametype *);

typedef double envarray[Xlastenv - XXenvvar];

#line 185 "dpic.y" /* yacc.c:339  */

  nametype *lastvar, *namptr, *primtextp;
  fbuffer *lastm;
  arg *macp, *lastp;
  primitive *primp, *prp, *eb, *wprim;
  int i, j, k, gltstval, lj, nexprs, nwi;
  double r, s, t, x1, z1, dx, dy, ts;
  boolean bswitch;
  attribute *attribp;
  int FORLIM;
  char cy;

#line 222 "dpic.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    XEMPTY = 1,
    Xlt = 2,
    Xcw = 3,
    Xccw = 4,
    Xlparen = 5,
    Xrparen = 6,
    Xmult = 7,
    Xplus = 8,
    Xminus = 9,
    Xdiv = 10,
    Xpercent = 11,
    Xnewline = 12,
    Xcaret = 13,
    Xnot = 14,
    Xandand = 15,
    Xoror = 16,
    Xcomma = 17,
    Xcolon = 18,
    Xleftbrack = 19,
    Xrightbrack = 20,
    Xleftbrace = 21,
    Xrightbrace = 22,
    Xdot = 23,
    Xblock = 24,
    Xleftquote = 25,
    Xrightquote = 26,
    Xeq = 27,
    Xcoloneq = 28,
    Xpluseq = 29,
    Xminuseq = 30,
    Xmulteq = 31,
    Xdiveq = 32,
    Xremeq = 33,
    Xampersand = 34,
    Xfloat = 35,
    Xname = 36,
    Xlabel = 37,
    XLaTeX = 38,
    Xstring = 39,
    Xcomment = 40,
    Xarg = 41,
    DotPS = 42,
    DotPE = 43,
    Xht = 44,
    Xwid = 45,
    Xrad = 46,
    Xdiam = 47,
    Xthick = 48,
    Xscaled = 49,
    Xfrom = 50,
    Xto = 51,
    Xat = 52,
    Xwith = 53,
    Xby = 54,
    Xthen = 55,
    Xcontinue = 56,
    Xchop = 57,
    Xsame = 58,
    Xof = 59,
    Xthe = 60,
    Xway = 61,
    Xbetween = 62,
    Xand = 63,
    XHere = 64,
    Xnth = 65,
    Xlast = 66,
    Xfill = 67,
    Dotx = 68,
    Doty = 69,
    Xprint = 70,
    Xcopy = 71,
    Xreset = 72,
    Xexec = 73,
    Xsh = 74,
    Xcommand = 75,
    Xdefine = 76,
    Xundefine = 77,
    Xrand = 78,
    Xif = 79,
    Xelse = 80,
    Xfor = 81,
    Xdo = 82,
    Xendfor = 83,
    Xsprintf = 84,
    Xcorner = 85,
    Dotne = 86,
    Dotse = 87,
    Dotnw = 88,
    Dotsw = 89,
    Dotn = 90,
    Dots = 91,
    Dote = 92,
    Dotw = 93,
    Dotstart = 94,
    Dotend = 95,
    Dotc = 96,
    Xcompare = 97,
    Xeqeq = 98,
    Xneq = 99,
    Xge = 100,
    Xle = 101,
    Xgt = 102,
    Xparam = 103,
    Xheight = 104,
    Xwidth = 105,
    Xradius = 106,
    Xdiameter = 107,
    Xthickness = 108,
    Xlength = 109,
    Xfunc1 = 110,
    Xabs = 111,
    Xacos = 112,
    Xasin = 113,
    Xcos = 114,
    Xexp = 115,
    Xexpe = 116,
    Xint = 117,
    Xlog = 118,
    Xloge = 119,
    Xsign = 120,
    Xsin = 121,
    Xsqrt = 122,
    Xtan = 123,
    Xfloor = 124,
    Xfunc2 = 125,
    Xatan2 = 126,
    Xmax = 127,
    Xmin = 128,
    Xpmod = 129,
    Xlinetype = 130,
    Xsolid = 131,
    Xdotted = 132,
    Xdashed = 133,
    Xinvis = 134,
    Xcolrspec = 135,
    Xcolour = 136,
    Xoutlined = 137,
    Xshaded = 138,
    Xtextpos = 139,
    Xcenter = 140,
    Xljust = 141,
    Xrjust = 142,
    Xabove = 143,
    Xbelow = 144,
    Xarrowhd = 145,
    Xlefthead = 146,
    Xrighthead = 147,
    Xdoublehead = 148,
    Xdirecton = 149,
    Xup = 150,
    Xdown = 151,
    Xright = 152,
    Xleft = 153,
    Xprimitiv = 154,
    Xbox = 155,
    Xcircle = 156,
    Xellipse = 157,
    Xarc = 158,
    Xline = 159,
    Xarrow = 160,
    Xmove = 161,
    Xspline = 162,
    Xenvvar = 163,
    Xarcrad = 164,
    Xarrowht = 165,
    Xarrowwid = 166,
    Xboxht = 167,
    Xboxrad = 168,
    Xboxwid = 169,
    Xcirclerad = 170,
    Xdashwid = 171,
    Xellipseht = 172,
    Xellipsewid = 173,
    Xlineht = 174,
    Xlinewid = 175,
    Xmoveht = 176,
    Xmovewid = 177,
    Xtextht = 178,
    Xtextoffset = 179,
    Xtextwid = 180,
    Xarrowhead = 181,
    Xfillval = 182,
    Xlinethick = 183,
    Xmaxpsht = 184,
    Xmaxpswid = 185,
    Xscale = 186
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  attribute  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 460 "dpic.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   847

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  345

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   398,   398,   400,   416,   492,   494,   499,   501,   504,
     507,   511,   513,   521,   530,   532,   535,   540,   548,   595,
     619,   621,   624,   631,   633,   644,   646,   648,   650,   660,
     684,   690,   693,   713,   715,   719,   728,   731,   736,   743,
     756,   758,   762,   774,   787,   803,   806,   808,   810,   821,
     827,   834,   838,   843,   845,   848,   851,   855,   862,   866,
     876,   898,   929,   933,   987,  1014,  1016,  1019,  1021,  1024,
    1027,  1030,  1034,  1044,  1048,  1050,  1056,  1105,  1147,  1150,
    1154,  1156,  1161,  1163,  1181,  1201,  1204,  1208,  1233,  1240,
    1246,  1249,  1253,  1255,  1341,  1421,  1483,  1510,  1516,  1617,
    1679,  1700,  1723,  1768,  1786,  1798,  1832,  1858,  1985,  2017,
    2038,  2074,  2170,  2188,  2234,  2293,  2302,  2311,  2327,  2346,
    2357,  2525,  2530,  2582,  2591,  2593,  2596,  2608,  2610,  2626,
    2636,  2643,  2650,  2655,  2660,  2664,  2666,  2668,  2670,  2675,
    2680,  2686,  2693,  2696,  2701,  2703,  2708,  2717,  2720,  2723,
    2727,  2731,  2737,  2739,  2744,  2756,  2772,  2784,  2795,  2803,
    2805,  2808,  2812,  2814,  2820,  2828,  2837,  2843,  2845,  2847,
    2872,  2893,  2900,  2909,  2911,  2914,  2916,  2919,  2981,  2984,
    2989,  3039,  3059,  3062
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"blank\"", "\"<\"",
  "\"cw\"", "\"ccw\"", "\"(\"", "\")\"", "\"*\"", "\"+\"", "\"-\"",
  "\"/\"", "\"%\"", "\"end of line or ;\"", "\"^\"", "\"!\"", "\"&&\"",
  "\"||\"", "\",\"", "\":\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\".\"",
  "\"[]\"", "\"`\"", "\"'\"", "\"=\"", "\":=\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"%=\"", "\"&\"", "\"number\"", "\"identifier\"",
  "\"label\"", "\"LaTeX\"", "\"string\"", "\"#\"", "\"$ argument\"",
  "\".PS\"", "\"end of file or .PE\"", "\"ht\"", "\"wid\"", "\"rad\"",
  "\"diam\"", "\"thick\"", "\"scaled\"", "\"from\"", "\"to\"", "\"at\"",
  "\"with\"", "\"by\"", "\"then\"", "\"continue\"", "\"chop\"", "\"same\"",
  "\"of\"", "\"the\"", "\"way\"", "\"between\"", "\"and\"", "\"Here\"",
  "\"ordinal: st or rd or nd or th\"", "\"last\"", "\"fill\"", "\".x\"",
  "\".y\"", "\"print\"", "\"copy\"", "\"reset\"", "\"exec\"", "\"sh\"",
  "\"command\"", "\"define\"", "\"undef\"", "\"rand\"", "\"if\"",
  "\"else\"", "\"for\"", "\"do\"", "\"end of for {...} contents\"",
  "\"sprintf\"", "\"compass corner: .n .ne .center .end etc\"", "\".ne\"",
  "\".se\"", "\".nw\"", "\".sw\"", "\".top or .n\"", "\".bot or .s\"",
  "\".right or .e\"", "\".left or .w\"", "\"start\"", "\"end\"", "\".c\"",
  "\"logical operator\"", "\"==\"", "\"!=\"", "\">=\"", "\"<=\"", "\">\"",
  "\"attribute .ht .wid etc\"", "\".ht\"", "\".wid\"", "\".rad\"",
  "\".diam\"", "\".thick\"", "\".len\"", "\"function (1 arg)\"", "\"abs\"",
  "\"acos\"", "\"asin\"", "\"cos\"", "\"exp\"", "\"expe\"", "\"int\"",
  "\"log\"", "\"loge\"", "\"sign\"", "\"sin\"", "\"sqrt\"", "\"tan\"",
  "\"floor\"", "\"function (2 args)\"", "\"atan2\"", "\"max\"", "\"min\"",
  "\"pmod\"", "\"line type: dotted etc\"", "\"solid\"", "\"dotted\"",
  "\"dashed\"", "\"invisible\"", "\"color spec: colored outlined shaded\"",
  "\"coloured\"", "\"outlined\"", "\"shaded\"",
  "\"text position: ljust rjust above below center\"", "\"center\"",
  "\"ljust\"", "\"rjust\"", "\"above\"", "\"below\"",
  "\"arrowhead parameter: <- -> <->\"", "\"<-\"", "\"->\"", "\"<->\"",
  "\"direction: up down right left\"", "\"up\"", "\"down\"", "\"right\"",
  "\"left\"", "\"drawn object: box circle line etc\"", "\"box\"",
  "\"circle\"", "\"ellipse\"", "\"arc\"", "\"line\"", "\"arrow\"",
  "\"move\"", "\"spline\"", "\"environment variable\"", "\"arcrad\"",
  "\"arrowht\"", "\"arrowwid\"", "\"boxht\"", "\"boxrad\"", "\"boxwid\"",
  "\"circlerad\"", "\"dashwid\"", "\"ellipseht\"", "\"ellipsewid\"",
  "\"lineht\"", "\"linewid\"", "\"moveht\"", "\"movewid\"", "\"textht\"",
  "\"textoffset\"", "\"textwid\"", "\"arrowhead\"", "\"fillval\"",
  "\"linethick\"", "\"maxpsht\"", "\"maxpswid\"", "\"scale\"", "$accept",
  "input", "picture", "NL", "prestart", "psline", "elementlist", "term",
  "element", "lbrace", "namedobj", "suffix", "position", "assignlist",
  "command", "optnl", "ifpart", "elsehead", "for", "stringexpr", "string",
  "assignment", "assignrhs", "expression", "ifhead", "setlogic", "logexpr",
  "forhead", "forincr", "do", "by", "redirect", "resetlist", "systemcmd",
  "sprintf", "exprlist", "object", "openblock", "block", "optexp",
  "closeblock", "objectwith", "pair", "nth", "primobj", "shift",
  "location", "place", "factor", "placename", "ncount", "logprod",
  "logval", "lcompare", "primary", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -160

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -159,    32,  -159,    24,   -26,  -159,  -159,  -159,   612,    24,
     332,   576,   518,   518,    -7,    34,    34,  -159,  -159,    51,
     284,    71,    95,  -159,   482,   -17,    60,  -159,  -159,    20,
      54,   134,   632,   612,   612,    34,  -159,   -25,   177,   112,
     266,    46,   151,   211,  -159,  -159,   232,    86,   180,   183,
    -159,    60,   179,  -159,   108,  -159,   145,    80,   518,  -159,
    -159,   500,  -159,   150,   194,   518,   518,   612,   612,   612,
     266,   210,  -159,  -159,  -159,  -159,   612,   612,  -159,  -159,
     323,  -159,  -159,   167,   612,  -159,  -159,  -159,    34,    34,
    -159,  -159,   365,   -25,    72,   -25,   -25,   235,   242,  -159,
     -32,  -159,   518,   112,    50,  -159,   632,  -159,   225,  -159,
     159,   632,   -12,   237,   632,   365,   632,  -159,   696,   632,
    -159,   446,   266,   266,   226,   237,   -25,   554,  -159,   518,
    -159,   -32,   -25,   -25,   518,   612,   612,   518,   196,   518,
    -159,   365,  -159,  -159,    29,   365,   365,  -159,  -159,   238,
     161,  -159,   293,   194,   319,   147,  -159,  -159,  -159,  -159,
    -159,  -159,    34,   -17,  -159,  -159,   226,   244,   163,     0,
      16,   237,  -159,   249,   237,   237,  -159,  -159,  -159,  -159,
      18,   276,  -159,   632,   257,   126,   259,   126,  -159,  -159,
     632,   126,   175,    13,    33,  -159,  -159,   518,   518,   518,
     518,   518,   518,   518,   518,   518,  -159,   518,  -159,   518,
    -159,   518,   518,   -25,  -159,   518,   518,   237,    75,   283,
     341,   518,   222,   171,   254,   554,   144,  -159,  -159,   276,
     304,   386,  -159,   237,  -159,   295,   386,   266,   266,   276,
     255,   252,   179,   201,   201,  -159,   237,   276,  -159,   518,
    -159,  -159,  -159,   518,  -159,  -159,   299,    15,  -159,  -159,
    -159,   154,   518,  -159,  -159,   300,  -159,   307,    33,   309,
     518,   305,  -159,   276,   276,   276,   276,   276,   276,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   237,  -159,  -159,  -159,
    -159,    34,   -17,  -159,   518,   518,  -159,   518,  -159,   518,
     277,   518,   518,   155,     5,   155,   343,  -159,   696,   -25,
     237,  -159,    12,  -159,  -159,  -159,  -159,   276,  -159,  -159,
    -159,  -159,  -159,   195,  -159,   245,   518,  -159,  -159,   237,
     338,  -159,   326,   518,   518,  -159,   291,  -159,  -159,    42,
    -159,    29,   518,  -159,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     7,     1,     0,     0,     6,     5,     3,     8,     0,
       0,     0,     0,     0,   173,    33,    33,   151,   134,     0,
       0,     0,     0,   171,     9,     0,     0,   144,    14,   147,
       0,   152,    11,     0,     0,    33,    61,     0,     0,   171,
      67,     0,     0,   168,    59,    40,   167,     0,     0,     0,
      36,   139,    74,   162,   164,   153,     0,     0,     0,   172,
     155,     0,   159,     0,   149,     0,     0,     0,     0,     0,
      10,     0,   136,   137,   135,   156,     0,     0,   175,   176,
       0,   148,   177,   132,     0,   119,    30,   123,    33,    33,
      22,   118,     0,     0,    45,     0,     0,     0,     0,    73,
       0,    21,   124,     0,     0,    12,    11,    18,    20,    23,
      25,    11,     0,   121,    11,     0,    11,    47,    31,    11,
      92,     0,    68,    69,   172,    87,     0,     0,   142,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,     0,   183,    62,   131,     0,     0,   161,   160,     0,
       0,   178,     0,   150,     0,     0,    15,    16,    17,   138,
     145,   146,    33,     0,   133,   154,     0,     0,    82,    82,
      82,    48,    85,    46,    29,    28,    49,    50,    51,    52,
       0,   125,   120,    54,     0,     0,     0,     0,    27,    77,
      11,     0,   167,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,   104,   124,
     107,   124,   124,     0,   113,   124,   124,   108,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    66,    64,    65,
       0,     0,    41,   165,    60,     0,   166,    70,    71,   130,
       0,     0,    75,     0,     0,   163,   170,   169,    35,     0,
      34,   179,   180,     0,   157,   158,     0,     0,    43,    44,
      42,     0,     0,    13,     4,     0,    56,     0,     0,     0,
       0,     0,    57,    93,    94,    95,    96,    97,    98,   110,
     111,   112,   109,   101,   102,   100,   114,   103,    99,   126,
     122,    33,     0,   115,     0,     0,    63,     0,   143,     0,
       0,     0,     0,   140,   147,   141,     0,    19,    32,     0,
      83,    86,     0,    24,    26,    58,    55,   166,    72,   128,
     129,   116,   117,    90,    89,     0,     0,    37,   181,    84,
      80,    78,     0,     0,     0,   139,     0,    81,    76,     0,
      91,    39,     0,    79,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   220,  -159,  -159,   -70,     9,   178,  -159,
    -159,   -14,   -29,    -2,  -159,  -106,  -159,  -159,  -159,    -9,
     230,  -112,   133,     1,  -159,  -159,   251,  -159,  -159,  -159,
    -159,   125,  -159,   364,  -159,    43,   127,  -159,  -159,    41,
    -159,  -159,   261,   -77,  -158,    49,   -10,  -159,    84,   -13,
    -159,   246,   248,  -159,   378
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,   183,     4,     9,   104,    40,   105,   106,
     107,    59,    41,   108,   109,   184,   110,   111,   112,   113,
      44,    45,   228,   231,   114,   115,    47,   116,   190,   332,
     333,   258,   173,   117,    49,   324,   118,   119,   120,   182,
     219,   121,    50,    25,    75,   144,    26,    27,    28,    29,
      30,    52,    53,    54,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    43,    60,   163,    71,   255,    88,    64,    42,    72,
     133,    46,   188,    56,    57,   227,    36,    24,     8,   232,
     249,   124,   135,   136,    73,     5,   135,   136,   125,   149,
      80,   141,     2,    70,     5,   137,   185,   131,     6,   243,
     244,   187,   122,   123,   191,    80,   194,     6,    51,   218,
     153,     5,   135,   136,   128,    58,    36,   -53,    61,   150,
    -159,    38,   152,   168,     6,   129,   154,   155,   330,    76,
     271,   262,    77,   189,   166,   167,     5,   138,    65,   265,
     139,   267,    51,   169,   171,   269,   174,   175,   272,     6,
     135,   136,    81,   170,   140,   -53,   331,   -53,   180,   257,
     230,    38,    66,   181,   141,   235,    43,    81,   148,   217,
     241,    51,   289,   227,   309,   257,   192,   226,   -53,    51,
     268,    83,   223,   233,    51,    82,   343,     5,   229,    51,
      78,    79,    43,   103,   320,   236,    43,   246,   239,    74,
       6,   127,   192,   292,   237,   238,   192,   247,   254,    84,
     -53,   156,   157,   158,   133,   135,   136,   135,   136,   130,
     160,   161,   315,   297,    76,   249,   253,    77,   165,   147,
     131,   135,   136,    12,   279,   280,   281,    13,   282,   270,
     137,   135,   136,   250,   126,   135,   136,    62,   142,    16,
     137,   143,   293,    51,    51,    51,   145,    51,   273,   274,
     275,   276,   277,   278,   286,   135,   136,   146,   302,    64,
     181,    51,   181,   181,   334,   132,   181,   181,    18,    80,
     235,   133,   138,     7,    12,   139,   229,   307,    13,    32,
     304,   304,   159,   303,   305,   164,   134,   172,    62,    51,
      16,   186,   135,   136,   131,    12,    51,   133,   310,    13,
     283,   137,   284,   285,   306,   225,   287,   288,   240,    62,
     248,    16,   257,   312,   256,   321,   322,    17,   261,    18,
     325,   317,   327,   176,   177,    67,   294,   319,    68,    69,
     178,   179,   266,    63,    51,    51,   135,   136,    20,    51,
      18,    51,    51,   138,   259,   260,   139,   336,   323,   217,
     329,   251,   264,   135,   136,   290,    10,    12,   295,    33,
      34,    13,   298,   344,   299,    11,    51,   301,   300,   311,
      85,    62,    12,    16,   313,    87,    13,   252,   318,   135,
     136,   314,    51,   316,   339,   323,    14,    15,    16,    10,
      36,   326,    33,    34,   335,    63,    12,   337,    11,   338,
      13,   328,    18,   135,   136,    12,   342,    91,   296,    13,
      62,   263,   162,   234,    12,    17,   193,    18,    13,    14,
      35,    16,    10,    36,    48,    33,    34,   340,    62,    19,
     291,    11,   224,   308,   341,    38,    20,   242,    12,    55,
     249,    18,    13,   245,     0,     0,   135,   136,    17,     0,
      18,     0,    14,    15,    16,   137,    36,     0,    37,    18,
       0,    21,    19,     0,     0,     0,     0,     0,    38,    20,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,    17,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    19,     0,   138,     0,     0,
     139,    38,    20,    10,     0,   102,    33,    34,     0,    22,
       0,     0,    11,     0,    23,     0,     0,     0,     0,    12,
       0,   220,     0,    13,     0,     0,     0,    21,     0,     0,
       0,     0,     0,    14,    15,    16,     0,     0,     0,    10,
       0,    67,    22,     0,    68,    69,     0,    39,    11,     0,
     221,     0,     0,     0,     0,    12,     0,    10,   151,    13,
      33,    34,    17,     0,    18,     0,    11,     0,     0,    14,
      15,    16,     0,    12,     0,    10,    19,    13,    33,    34,
      23,     0,     0,   222,    11,     0,     0,    14,    15,    16,
       0,    12,     0,     0,     0,    13,     0,     0,    17,     0,
      18,     0,     0,     0,     0,    14,    15,    16,    21,     0,
       0,    10,    19,     0,    33,    34,    17,     0,    18,    20,
      11,     0,     0,    22,     0,     0,     0,    12,     0,     0,
      19,    13,     0,    10,    17,     0,    18,    20,     0,     0,
       0,    14,    35,    16,    21,     0,     0,     0,    19,    12,
       0,     0,     0,    13,     0,    20,     0,     0,     0,    22,
       0,    23,    21,    14,    15,    16,     0,     0,     0,    10,
      17,     0,    18,     0,     0,     0,     0,    22,    11,     0,
      21,     0,     0,     0,    19,    12,     0,     0,     0,    13,
       0,    20,    17,     0,    18,    22,     0,    23,     0,    14,
      15,    16,     0,    85,     0,    86,    19,     0,    87,     0,
       0,     0,     0,    20,     0,    23,    21,     0,     0,     0,
      88,    89,    90,    36,     0,     0,     0,     0,    17,     0,
      18,    22,     0,    23,     0,     0,     0,     0,    21,     0,
      91,     0,    19,     0,     0,     0,     0,     0,     0,    20,
       0,   195,   196,    22,    92,    93,    94,    95,    37,    96,
      97,    98,     0,    99,     0,   100,     0,     0,    38,    39,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    22,
       0,    23,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,     0,     0,     0,
       0,     0,     0,     0,     0,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,    38,   101,     0,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   212,     0,
       0,     0,     0,   213,     0,     0,     0,   214,     0,     0,
       0,     0,     0,   215,     0,     0,     0,   216
};

static const yytype_int16 yycheck[] =
{
      10,    10,    16,    80,    21,   163,    38,    20,    10,    26,
      10,    10,    24,    12,    13,   127,    41,     8,    44,   131,
       4,    35,    10,    11,    41,     1,    10,    11,    37,    58,
      25,    18,     0,    24,     1,    19,   106,    19,    14,    10,
      11,   111,    33,    34,   114,    25,   116,    14,    58,   119,
      63,     1,    10,    11,     8,    21,    41,    24,     7,    58,
      67,    86,    61,    92,    14,    19,    65,    66,    56,     9,
      57,    53,    12,    85,    88,    89,     1,    61,     7,   185,
      64,   187,    92,    92,    93,   191,    95,    96,   194,    14,
      10,    11,    87,    92,     8,    45,    84,    22,   100,    99,
     129,    86,     7,   102,    18,   134,   115,    87,    28,   118,
     139,   121,   218,   225,    99,    99,   115,   126,    85,   129,
     190,    67,   121,   132,   134,   105,    84,     1,   127,   139,
      70,    71,   141,   165,   292,   134,   145,   146,   137,   156,
      14,    29,   141,   220,   135,   136,   145,   146,   162,    15,
      24,    67,    68,    69,    10,    10,    11,    10,    11,     8,
      76,    77,   268,    19,     9,     4,    19,    12,    84,    24,
      19,    10,    11,    23,   203,   204,   205,    27,   207,     4,
      19,    10,    11,    22,     7,    10,    11,    37,     8,    39,
      19,     8,   221,   203,   204,   205,    17,   207,   197,   198,
     199,   200,   201,   202,   213,    10,    11,    99,     7,   222,
     209,   221,   211,   212,    19,     4,   215,   216,    68,    25,
     249,    10,    61,     3,    23,    64,   225,   256,    27,     9,
     243,   244,    22,   243,   244,    68,     4,   165,    37,   249,
      39,    82,    10,    11,    19,    23,   256,    10,   257,    27,
     209,    19,   211,   212,   253,    29,   215,   216,    62,    37,
      22,    39,    99,   262,    20,   294,   295,    66,    19,    68,
     299,   270,   301,    38,    39,     9,    54,   291,    12,    13,
      38,    39,    23,    61,   294,   295,    10,    11,    87,   299,
      68,   301,   302,    61,   169,   170,    64,   326,   297,   308,
     309,     8,    45,    10,    11,    22,     7,    23,    54,    10,
      11,    27,     8,   342,    19,    16,   326,    65,    63,   165,
      21,    37,    23,    39,    24,    26,    27,     8,    23,    10,
      11,    24,   342,    24,   333,   334,    37,    38,    39,     7,
      41,    64,    10,    11,    99,    61,    23,     9,    16,    23,
      27,     8,    68,    10,    11,    23,    65,    58,   225,    27,
      37,   183,    39,   133,    23,    66,   115,    68,    27,    37,
      38,    39,     7,    41,    10,    10,    11,   334,    37,    80,
      39,    16,   121,   256,   335,    86,    87,   141,    23,    11,
       4,    68,    27,   145,    -1,    -1,    10,    11,    66,    -1,
      68,    -1,    37,    38,    39,    19,    41,    -1,    76,    68,
      -1,   112,    80,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    80,    -1,    61,    -1,    -1,
      64,    86,    87,     7,    -1,   156,    10,    11,    -1,   127,
      -1,    -1,    16,    -1,   165,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,    27,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    -1,    -1,    -1,     7,
      -1,     9,   127,    -1,    12,    13,    -1,   165,    16,    -1,
      54,    -1,    -1,    -1,    -1,    23,    -1,     7,     8,    27,
      10,    11,    66,    -1,    68,    -1,    16,    -1,    -1,    37,
      38,    39,    -1,    23,    -1,     7,    80,    27,    10,    11,
     165,    -1,    -1,    87,    16,    -1,    -1,    37,    38,    39,
      -1,    23,    -1,    -1,    -1,    27,    -1,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    37,    38,    39,   112,    -1,
      -1,     7,    80,    -1,    10,    11,    66,    -1,    68,    87,
      16,    -1,    -1,   127,    -1,    -1,    -1,    23,    -1,    -1,
      80,    27,    -1,     7,    66,    -1,    68,    87,    -1,    -1,
      -1,    37,    38,    39,   112,    -1,    -1,    -1,    80,    23,
      -1,    -1,    -1,    27,    -1,    87,    -1,    -1,    -1,   127,
      -1,   165,   112,    37,    38,    39,    -1,    -1,    -1,     7,
      66,    -1,    68,    -1,    -1,    -1,    -1,   127,    16,    -1,
     112,    -1,    -1,    -1,    80,    23,    -1,    -1,    -1,    27,
      -1,    87,    66,    -1,    68,   127,    -1,   165,    -1,    37,
      38,    39,    -1,    21,    -1,    23,    80,    -1,    26,    -1,
      -1,    -1,    -1,    87,    -1,   165,   112,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    66,    -1,
      68,   127,    -1,   165,    -1,    -1,    -1,    -1,   112,    -1,
      58,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,     5,     6,   127,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    -1,    83,    -1,    -1,    86,   165,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,   127,
      -1,   165,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    -1,    86,   151,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   190,     0,   191,   193,     1,    14,   192,    44,   194,
       7,    16,    23,    27,    37,    38,    39,    66,    68,    80,
      87,   112,   127,   165,   196,   232,   235,   236,   237,   238,
     239,   243,   192,    10,    11,    38,    41,    76,    86,   165,
     196,   201,   202,   208,   209,   210,   212,   215,   222,   223,
     231,   235,   240,   241,   242,   243,   212,   212,    21,   200,
     200,     7,    37,    61,   238,     7,     7,     9,    12,    13,
     196,    21,    26,    41,   156,   233,     9,    12,    70,    71,
      25,    87,   105,    67,    15,    21,    23,    26,    38,    39,
      40,    58,    72,    73,    74,    75,    77,    78,    79,    81,
      83,   151,   156,   165,   195,   197,   198,   199,   202,   203,
     205,   206,   207,   208,   213,   214,   216,   222,   225,   226,
     227,   230,   196,   196,   200,   208,     7,    29,     8,    19,
       8,    19,     4,    10,     4,    10,    11,    19,    61,    64,
       8,    18,     8,     8,   234,    17,    99,    24,    28,   201,
     212,     8,   212,   238,   212,   212,   237,   237,   237,    22,
     237,   237,    39,   232,    68,   237,   200,   200,   201,   208,
     212,   208,   165,   221,   208,   208,    38,    39,    38,    39,
     202,   212,   228,   192,   204,   195,    82,   195,    24,    85,
     217,   195,   212,   215,   195,     5,     6,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    59,
      60,    69,   132,   137,   141,   147,   151,   208,   195,   229,
      25,    54,    87,   212,   231,    29,   208,   210,   211,   212,
     201,   212,   210,   208,   209,   201,   212,   196,   196,   212,
      62,   201,   240,    10,    11,   241,   208,   212,    22,     4,
      22,     8,     8,    19,   200,   233,    20,    99,   220,   220,
     220,    19,    53,   197,    45,   204,    23,   204,   195,   204,
       4,    57,   204,   212,   212,   212,   212,   212,   212,   201,
     201,   201,   201,   228,   228,   228,   208,   228,   228,   204,
      22,    39,   232,   201,    54,    54,   211,    19,     8,    19,
      63,    65,     7,   235,   238,   235,   212,   201,   225,    99,
     208,   165,   212,    24,    24,   204,    24,   212,    23,   200,
     233,   201,   201,   212,   224,   201,    64,   201,     8,   208,
      56,    84,   218,   219,    19,    99,   201,     9,    23,   212,
     224,   234,    65,    84,   201
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   189,   190,   190,   191,   192,   192,   193,   194,   194,
     194,   195,   195,   195,   196,   196,   196,   196,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     198,   199,   199,   200,   200,   200,   201,   201,   201,   201,
     202,   202,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   204,   204,   205,   206,   207,   207,   208,
     208,   209,   209,   210,   210,   211,   211,   212,   212,   212,
     212,   212,   213,   214,   215,   215,   216,   217,   218,   218,
     219,   219,   220,   220,   220,   221,   221,   222,   223,   223,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     227,   227,   227,   227,   228,   228,   229,   230,   230,   230,
     231,   231,   232,   232,   232,   233,   233,   233,   233,   234,
     234,   234,   235,   235,   235,   235,   235,   236,   236,   236,
     236,   236,   237,   237,   237,   238,   238,   238,   238,   239,
     239,   239,   240,   240,   241,   241,   241,   242,   242,   242,
     242,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     6,     1,     1,     0,     1,     2,
       3,     0,     1,     3,     1,     3,     3,     3,     1,     4,
       1,     1,     1,     1,     4,     1,     4,     2,     2,     2,
       1,     1,     4,     0,     3,     3,     1,     5,     8,     7,
       1,     3,     3,     3,     3,     1,     2,     1,     2,     2,
       2,     2,     2,     0,     1,     4,     3,     3,     4,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     2,     2,
       3,     3,     4,     1,     1,     3,     6,     1,     1,     3,
       1,     2,     0,     2,     3,     1,     3,     2,     3,     5,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     2,     3,     3,     4,     4,     1,     1,
       2,     1,     3,     1,     0,     1,     2,     2,     4,     4,
       3,     2,     2,     3,     1,     1,     1,     1,     2,     0,
       3,     3,     3,     5,     1,     3,     3,     1,     2,     2,
       3,     1,     1,     2,     3,     2,     2,     4,     4,     1,
       3,     3,     1,     3,     1,     3,     3,     1,     1,     3,
       3,     1,     2,     1,     3,     2,     2,     2,     3,     4,
       4,     6,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (pyylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 401 "dpic.y" /* yacc.c:1646  */
    { deletetree(&envblock);
    	  deletefreeargs(&freearg);
    	  deletefreeinbufs(&freeinbuf);
#ifdef DDEBUG
          if (debuglevel > 0) {
            fprintf(log_, "deletetree:\n");
	        fprintf(log_, "deletefreeargs: ");
	        fprintf(log_, "deletefreeinbufs: ");
	        fprintf(log_, "inittwo:\n"); }
#endif
    	  inittwo();
    	  if (envblock != NULL) { envblock->direction = Xright; }
		  }
#line 1935 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 417 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-4]);
		  if (envblock != NULL ) {
            getnesw(envblock->son);
#ifdef DDEBUG
	        if (debuglevel > 0) {
              snaptree(envblock->son,0);
		      fprintf(log_, " Global dimensions:\n");
              fprintf(log_, "(n,s)(e,w)=");
		      wpair(&log_, north, south); wpair(&log_, east, west);
              putc('\n', log_);
              fflush(log_); }
#endif
		    envblock->aat.xpos = (east + west) * 0.5;
		    envblock->aat.ypos = (north + south) * 0.5;
		    envblock->blockheight_ = north - south;
		    envblock->blockwidth_ = east - west;
	        if (drawmode == xfig) {
		      shift(envblock, -west, -south);
		      north -= south;
		      east -= west;
		      west = 0.0;
		      south = 0.0; }
            else if (((drawmode==SVG) || (drawmode==PDF) || (drawmode==PS)) &&
              (envblock->blockparms.env != NULL)) {
							/* linethick/2 in drawing units*/
		      r = (envblock->envinx(Xlinethick) / 2 / 72)
                  * envblock->envinx(Xscale);
#ifdef DDEBUG
		      if (debuglevel > 0) {
			    fprintf(log_,     " west="); wfloat(&log_, west);
			    fprintf(log_,     " south="); wfloat(&log_, south);
			    fprintf(log_,     " lthick/2="); wfloat(&log_, r);
			    fprintf(log_,     " shift=("); wfloat(&log_, r-west);
                putc(',', log_); wfloat(&log_, r-south);
                fprintf(log_, ")\n"); fflush(log_); }
#endif
							/* shift .sw to (r,r) */
		      shift(envblock, (2 * r) - west, (2 * r) - south);
		      north += (3 * r) - south;
		      east += (3 * r) - west;
		      west = r;
		      south = r;
	          }
	        xfheight = north;
	        getscale((yyval).xval, (yyval).yval, envblock, &scale, &fsc);
#ifdef DDEBUG
	        if (debuglevel > 0) {
		      fprintf(log_, "After shift:\n");
		      fprintf(log_, "xfheight="); wfloat(&log_, xfheight);
              putc('\n', log_);
		      printobject(envblock);
		      printobject(envblock->son);
		      fprintf(log_, "\nStarting drawtree ================= ");
		      if (((yyval).xval > 0.0) && (east > west)) {
		        fprintf(log_, "fsc="); wfloat(&log_, fsc); }
		      putc('\n', log_);
		      snaptree(envblock, 0);
		      putc('\n', log_); fflush(log_); }
#endif
		    if ((drawmode == SVG) || (drawmode == PDF) || (drawmode == PS)) {
		      dptextratio = findvar("dptextratio", 11);
		      if (dptextratio == 0) { dptextratio = 1.0; }
		      dpPPI = findvar("dpPPI", 5); }
            else if (drawmode == xfig) {
              xfigres = findvar("xfigres", 7);
              xdispres = findvar("xdispres", 8); }
	        drawtree(north, south, east, west, envblock);
#ifdef DDEBUG
	        if (debuglevel > 0) {
		      fprintf(log_, " drawtree done ================= \n"); }
#endif
	        }
	      }
#line 2013 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 495 "dpic.y" /* yacc.c:1646  */
    { yyerrok; /* yyclearin; */ }
#line 2019 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 499 "dpic.y" /* yacc.c:1646  */
    { mkOptionVars(); }
#line 2025 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 502 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 0; (yyval).yval = 0; }
#line 2031 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 505 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; (yyval).yval = 0; }
#line 2037 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 508 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; (yyval).yval = (yyvsp[0]).xval; }
#line 2043 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 514 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[0]).prim != NULL) && ((yyvsp[0]).lexval != Xcontinue)) {
            queueprim( (yyvsp[0]).prim, envblock ); }
#ifdef DDEBUG
          if (debuglevel > 0 ) { snaptree(envblock->son,0); }
#endif
    	  }
#line 2054 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 522 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[0]).prim != NULL) && ((yyvsp[0]).lexval != Xcontinue)) {
            queueprim( (yyvsp[0]).prim, envblock ); }
#ifdef DDEBUG
          if (debuglevel > 0 ) { snaptree(envblock->son,0); }
#endif
		  }
#line 2065 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 533 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval * (yyvsp[0]).xval; }
#line 2071 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 536 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { markerror(852); (yyval).xval = 0.0; }
    		else { (yyval).xval = (yyvsp[-2]).xval / (yyvsp[0]).xval; }
		  }
#line 2079 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 541 "dpic.y" /* yacc.c:1646  */
    { i = Rnd((yyvsp[-2]).xval);
    	  j = Rnd((yyvsp[0]).xval);
    	  if (j == 0) { markerror(852); (yyval).xval = 0.0; }
    	  else { (yyval).xval = i - ((i / j) * j); }
		  }
#line 2089 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 549 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			prp = (yyval).prim;
			if ((prp->ptype == Xspline) || (prp->ptype == Xmove) ||
			    (prp->ptype == Xarrow) || (prp->ptype == Xline)) {
			  if ((yyval).startchop != 0.0) {
				dx = prp->endpos_.xpos - prp->aat.xpos;
				dy = prp->endpos_.ypos - prp->aat.ypos;
				s = linlen(dx, dy);
#ifdef DDEBUG
				if (debuglevel == 2) { fprintf(log_, " element1 startchop=");
				  wfloat(&log_, (yyval).startchop);
				  fprintf(log_, " (dx,dy)="); wpair(&log_, dx, dy);
				  fprintf(log_, " s="); wfloat(&log_, s); putc('\n', log_); }
#endif
				if (s != 0.0) {
				  t = (yyval).startchop / s;
				  prp->aat.xpos += t * dx;
				  prp->aat.ypos += t * dy; }
			    }
			  while (prp->son != NULL) { prp = prp->son; }
			  if ((yyval).endchop != 0.0) {
				dx = prp->endpos_.xpos - prp->aat.xpos;
				dy = prp->endpos_.ypos - prp->aat.ypos;
				s = linlen(dx, dy);
#ifdef DDEBUG
				if (debuglevel == 2) { fprintf(log_, " element1 endchop=");
				  wfloat(&log_, (yyval).endchop);
				  fprintf(log_, " (dx,dy)="); wpair(&log_, dx, dy);
				  fprintf(log_, " s="); wfloat(&log_, s); putc('\n', log_); }
#endif
				if (s != 0.0) {
				  t = (yyval).endchop / s;
				  prp->endpos_.xpos -= t * dx;
				  prp->endpos_.ypos -= t * dy; }
			    }
			  }
			FindExitPoint(prp, &envblock->here_); }
#ifdef DDEBUG
			if (debuglevel > 0) { prattribute("element1", &(yyval));
			  fprintf(log_, " element1 Here=");
			  wpair(&log_, envblock->here_.xpos, envblock->here_.ypos);
              putc('\n', log_);
			  printobject((yyval).prim); }
#endif
			}
#line 2139 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 596 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != XEMPTY) {
		    addsuffix(chbuf, &(yyvsp[-3]).chbufx,&(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval);}
		  prp = findplace(envblock->son, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
		  if (prp == NULL) {
			newprim(&(yyval).prim, Xlabel, envblock);
			newstr(&(yyval).prim->name);
			storestring((yyval).prim->name, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, 1);
			prp = (yyval).prim; }
		  else if (prp->ptype != Xlabel) {
			newprim(&(yyval).prim, Xlabel, envblock);
			(yyval).prim->name = prp->name;
			prp->name = NULL;
			prp = (yyval).prim; }
		  clearchbuf((yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
		  prp->aat.xpos = (yyvsp[0]).xval;
		  prp->aat.ypos = (yyvsp[0]).yval;
#ifdef DDEBUG
          if (debuglevel>1) {
            prattribute("element2", &(yyval));
            if ((yyval).prim != NULL) printobject((yyval).prim); }
#endif
		  }
#line 2166 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 622 "dpic.y" /* yacc.c:1646  */
    { envblock->direction = (yyvsp[0]).lexval; }
#line 2172 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 625 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, XLaTeX, envblock);
    	  newstr(&(yyval).prim->textp);
    	  storestring((yyval).prim->textp, chbuf, (yyvsp[0]).chbufx, (yyvsp[0]).toklen, 1);
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen);
		  }
#line 2182 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 634 "dpic.y" /* yacc.c:1646  */
    { envblock->here_.xpos = (yyvsp[-3]).xval;
    	  envblock->here_.ypos = (yyvsp[-3]).yval;
    	  if (((yyvsp[-3]).state == Xright) || ((yyvsp[-3]).state == Xleft) ||
			  ((yyvsp[-3]).state == Xdown) || ((yyvsp[-3]).state == Xup)) {
			envblock->direction = (yyvsp[-3]).state; }
#ifdef DDEBUG
          if (debuglevel>1) { prattribute("element7", &(yyval)); }
#endif
		  }
#line 2196 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 651 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
			newprim(&(yyval).prim, XLaTeX, envblock);
			(yyval).prim->textp = (yyvsp[0]).prim->textp;
			(yyvsp[0]).prim->textp = NULL;
			if (envblock->son == (yyvsp[0]).prim) { envblock->son = (yyval).prim; }
			deletestringbox(&(yyvsp[0]).prim);
			}
		  }
#line 2209 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 661 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim == NULL) { }
          else if ((yyvsp[0]).prim->textp == NULL) { }
          else if ((yyvsp[0]).prim->textp->segmnt != NULL) {
			primtextp = (yyvsp[0]).prim->textp;
			newbuf(&lastm);      /* Temp buffer; put nlch into inbuf */
			lastm->carray[1] = nlch;
			lastm->savedlen = 1;
			copyleft(lastm, &inbuf, -1);
			FORLIM = primtextp->len;
	                  /*  Copy string to lastm then to inbuf */
			for (i = 1; i <= FORLIM; i++) {
			  lastm->carray[i] = primtextp->segmnt[primtextp->seginx + i - 1]; }
			lastm->savedlen = primtextp->len;
			copyleft(lastm, &inbuf, -1);
						  /*  Add nlch in inbuf */
			lastm->carray[1] = nlch;
			lastm->savedlen = 1;
			copyleft(lastm, &inbuf, -1);
			deletestringbox(&(yyvsp[0]).prim);
			disposebufs(&lastm); }
		  }
#line 2235 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 685 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = envblock->here_.xpos;
    	  (yyval).yval = envblock->here_.ypos;
    	  (yyval).state = envblock->direction; }
#line 2243 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 691 "dpic.y" /* yacc.c:1646  */
    { donamedobj(&(yyval)); }
#line 2249 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 694 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
		    if ((yyvsp[-2]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-3]).chbufx,
                  &(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval); }
			primp = findplace(envblock->son, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
			if (primp != NULL) {
	    	  (yyvsp[0]).prim->name = primp->name;
	    	  primp->name = NULL; }
			else {
	    	  wprim = (yyvsp[0]).prim;
	    	  newstr(&wprim->name);
	    	  storestring(wprim->name, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, 1); }
			(yyval) = (yyvsp[0]);
			donamedobj(&(yyval));
			}
		  clearchbuf((yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
		  }
#line 2270 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 713 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 2276 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 716 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).xval > maxint) { markerror(875); fatal(8); }
          else { (yyval).xval = (yyvsp[-1]).xval; } }
#line 2283 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 720 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = Xcomma;
    	  (yyval).xval = (yyvsp[-1]).xval;
    	  (yyval).yval = (yyvsp[-1]).yval;
    	  if ((fabs((yyvsp[-1]).xval) > maxint) || (fabs((yyvsp[-1]).yval) > maxint)) {
            markerror(875); fatal(8);}
		  }
#line 2294 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 729 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2300 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 732 "dpic.y" /* yacc.c:1646  */
    { r = (yyvsp[-4]).xval;
    	  (yyval).xval = (yyvsp[-2]).xval + (r * ((yyvsp[0]).xval - (yyvsp[-2]).xval));
    	  (yyval).yval = (yyvsp[-2]).yval + (r * ((yyvsp[0]).yval - (yyvsp[-2]).yval)); }
#line 2308 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 738 "dpic.y" /* yacc.c:1646  */
    {
    	  r = (yyvsp[-7]).xval;
    	  (yyval).xval = (yyvsp[-2]).xval + (r * ((yyvsp[0]).xval - (yyvsp[-2]).xval));
    	  (yyval).yval = (yyvsp[-2]).yval + (r * ((yyvsp[0]).yval - (yyvsp[-2]).yval)); }
#line 2317 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 745 "dpic.y" /* yacc.c:1646  */
    { r = (yyvsp[-6]).xval;
    	  (yyval).xval = (yyvsp[-4]).xval + (r * ((yyvsp[-2]).xval - (yyvsp[-4]).xval));
    	  (yyval).yval = (yyvsp[-4]).yval + (r * ((yyvsp[-2]).yval - (yyvsp[-4]).yval));
		  if ((yyvsp[-1]).lexval != Xgt) { markerror(869); }
		  else if ((yyvsp[0]).lexval != XEMPTY) {
	   	    (yyval).xval += (yyvsp[0]).xval;
	   	    (yyval).yval += (yyvsp[0]).yval;
			}
		  }
#line 2331 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 759 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; }
#line 2337 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 763 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval == XEMPTY) {
            wfloat(&errout, (yyvsp[-1]).xval); putc('\n', errout); }
    	  else if ((yyvsp[0]).state == 0) {
#ifndef SAFE_MODE
	  		wfloat(&redirect, (yyvsp[-1]).xval); putc('\n', redirect);
			if (redirect != NULL) { fclose(redirect); }
			redirect = NULL;
#endif
			}
		  }
#line 2352 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 775 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval == XEMPTY) {
	  		wpair(&errout, (yyvsp[-1]).xval, (yyvsp[-1]).yval); putc('\n', errout); }
    	  else if ((yyvsp[0]).state == 0) {
#ifndef SAFE_MODE
	  		wpair(&redirect, (yyvsp[-1]).xval, (yyvsp[-1]).yval);
			putc('\n', redirect);
			if (redirect != NULL) { fclose(redirect); }
			redirect = NULL;
#endif
			}
		  }
#line 2368 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 788 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval == XEMPTY) {
	      	wstring(&errout, (yyvsp[-1]).prim->textp);
			putc('\n', errout); }
    	  else if ((yyvsp[0]).state == 0) {
#ifndef SAFE_MODE
	  		if ((yyvsp[-1]).prim != NULL) {
			  wstring(&redirect, (yyvsp[-1]).prim->textp); }
			putc('\n', redirect);
			if (redirect != NULL) { fclose(redirect); }
			redirect = NULL;
#endif
			}
		  deletestringbox(&(yyvsp[-1]).prim);
		  }
#line 2387 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 804 "dpic.y" /* yacc.c:1646  */
    { resetenv(0, envblock); }
#line 2393 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 811 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
#ifdef SAFE_MODE
			markerror(901);
#else
			pointinput((yyvsp[0]).prim->textp);
#endif
			deletestringbox(&(yyvsp[0]).prim);
    		}
		  }
#line 2407 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 822 "dpic.y" /* yacc.c:1646  */
    { currprod = 4;
          (yyval) = (yyvsp[0]);
		  dodefhead( &(yyval) );
          }
#line 2416 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 828 "dpic.y" /* yacc.c:1646  */
    { currprod = 5;
          (yyval) = (yyvsp[0]);
		  dodefhead( &(yyval) );
          }
#line 2425 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 835 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); doundefine( &(yyvsp[0]) );
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen); }
#line 2432 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 839 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); doundefine( &(yyvsp[0]) );
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen); }
#line 2439 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 852 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval == 1.0) { currprod = 1; skiptobrace(); } }
#line 2445 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 856 "dpic.y" /* yacc.c:1646  */
    { forattr = (yyval);
#ifdef DDEBUG
		  if (debuglevel>0) prattribute("for1",&(yyval));
#endif
		  }
#line 2455 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 863 "dpic.y" /* yacc.c:1646  */
    { forattr = (yyval); }
#line 2461 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 867 "dpic.y" /* yacc.c:1646  */
    {
#ifdef DDEBUG
		  if (debuglevel>0) {
			prattribute("stringexpr1",&(yyval));
            printobject((yyval).prim);
  			fflush(log_); }
#endif
		  }
#line 2474 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 877 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) { prp = (yyvsp[0]).prim;
		  (yyval).prim->boxwidth_ += prp->boxwidth_;
		  (yyval).prim->boxheight_ = Max((yyvsp[-2]).prim->boxheight_, prp->boxheight_);
		  if (prp->textp != NULL) {
    	    if ((yyvsp[-2]).prim->textp == NULL) {
			  (yyval).prim->textp = prp->textp; prp->textp = NULL; }
    		else if (((yyvsp[-2]).prim->textp->segmnt == prp->textp->segmnt) &&
	     		((yyvsp[-2]).prim->textp->seginx + (yyvsp[-2]).prim->textp->len ==
	      		  prp->textp->seginx)) {
			  (yyval).prim->textp->len += prp->textp->len;
			  putbval((yyval).prim->textp->segmnt,
                bval((yyvsp[-2]).prim->textp->segmnt)-1);
			  prp->textp->segmnt = NULL;
    		  }
    		else { appendstring((yyval).prim->textp, prp->textp->segmnt,
		        prp->textp->seginx, prp->textp->len); }
		  }
		deletetree(&(yyvsp[0]).prim); }
		}
#line 2498 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 899 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, Xstring, envblock);
		  eb = findenv(envblock);
		  wprim = (yyval).prim;
		  wprim->boxheight_ = eb->envinx(Xtextht);
		  wprim->boxwidth_ = eb->envinx(Xtextwid);
		  if (wprim->boxwidth_ == 0.0) {
			switch (drawmode) {
		  	  case xfig:
							/* To keep xfig from crashing, assume text height
							   is 0.1 and a character is 0.1*0.75 wide */
		  	  	if ((yyval).prim->boxheight_ == 0.0) {
		  	      (yyval).prim->boxheight_ = 0.1 * eb->envinx(Xscale); }
		  	  	(yyval).prim->boxwidth_ = (yyval).prim->boxheight_ * (yyvsp[0]).toklen * 0.75;
		  	  	break;
		  	  case PDF:
		  	  	(yyval).prim->boxwidth_ = (yyval).prim->boxheight_ * (yyvsp[0]).toklen * 0.6;
		  	  	break;
		  	  }
		    }
		  newstr(&wprim->textp);
		  storestring(wprim->textp, chbuf, (yyvsp[0]).chbufx, (yyvsp[0]).toklen, 1);
#ifdef DDEBUG
		  if (debuglevel>1) {
            prattribute("string1",&(yyval));
            printobject((yyval).prim);
  			fflush(log_); }
#endif
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen);
		  }
#line 2532 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 934 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-3]).chbufx,
                &(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval); }
		    (yyval).varname = findname(envblock, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen,
			     &lastvar, &k);
		    if (((yyval).varname == NULL) && ((yyvsp[-1]).lexval != Xeq)) {
			  (yyval).varname = glfindname(envblock->parent, chbuf,
				 (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, &namptr, &gltstval); }
		    if ((yyval).varname == NULL) {
			  newstr(&(yyval).varname);
			  j = varhash(chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
			  storestring((yyval).varname, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, 1);
		#ifdef DDEBUG
			if (debuglevel > 1) {
			    fprintf(log_, "assignment: j=%d envblock=%d eqstr=%d\n",
				    j,ordp(envblock), k);
			    fprintf(log_, " lastvar=%d", ordp(lastvar));
			    if (lastvar != NULL) {
				  snapname(lastvar->segmnt, lastvar->seginx, lastvar->len); }
			    putc('\n', log_);
			    fprintf(log_, " varname=%d\n", ordp((yyvsp[-3]).varname));
			    prvars(envblock);
			    }
		#endif
			wprim = envblock;
			if (lastvar == NULL) { wprim->blockparms.vars[j] = (yyval).varname; }
			else if (k < 0) {
			  if (wprim->blockparms.vars[j]->nextname == NULL) {
			    wprim->blockparms.vars[j]->nextname = (yyval).varname; }
			  else {
				(yyval).varname->nextname = lastvar->nextname;
				lastvar->nextname = (yyval).varname; }
			    }
			else if (lastvar == wprim->blockparms.vars[j]) {
			  (yyval).varname->nextname = wprim->blockparms.vars[j];
			  wprim->blockparms.vars[j] = (yyval).varname; }
			else {
			  namptr = wprim->blockparms.vars[j];
							/* while (namptr^.next<>nil) and
							   (namptr^.next<>lastvar) do */
			  while (namptr->nextname != lastvar) { namptr = namptr->nextname; }
			  namptr->nextname = (yyval).varname;
			  (yyval).varname->nextname = lastvar;
			  }
			wprim->blockparms.nvars[j]++;
			(yyval).varname->val = 0.0;
		    }
		  if ((yyvsp[-1]).lexval == Xeq) { (yyval).varname->val = (yyvsp[0]).xval; }
		  else { eqop(&(yyval).varname->val, (yyvsp[-1]).lexval, (yyvsp[0]).xval); }
		  (yyval).xval = (yyval).varname->val;

		  clearchbuf((yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
          }
#line 2589 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 988 "dpic.y" /* yacc.c:1646  */
    { if (envblock != NULL) {
		    if (((yyvsp[-2]).lexval == Xarrowhead) && (drawmode == TeX) &&
		      ((yyvsp[0]).xval == 0.0)) { markerror(858); }
		    else {
		      if (envblock->blockparms.env == NULL) { inheritenv(envblock); }
		      if ((yyvsp[-2]).lexval == Xscale) {
			    resetscale((yyvsp[0]).xval, (yyvsp[-1]).lexval, envblock); }
		      else { eqop(&envblock->envinx((yyvsp[-2]).lexval), (yyvsp[-1]).lexval, (yyvsp[0]).xval); }
		      }
		    (yyval).xval = envblock->envinx((yyvsp[-2]).lexval);
#ifdef DDEBUG
		    if (debuglevel > 0) {
		      fprintf(log_, " Assignment3or4 envblock[%d]: lexval=%d value=",
			    ordp(envblock), (yyvsp[-2]).lexval);
		      wfloat(&log_, envblock->envinx((yyvsp[-2]).lexval)); putc('\n', log_); }
#endif
		    (yyval).startchop = (yyval).lexval;
		    if (((yyval).lexval == Xdashwid) || ((yyval).lexval == Xlinethick)) {
		      newprim(&((yyval).prim), XLaTeX, envblock);
		      if ((yyvsp[-2]).lexval == Xlinethick) { (yyval).prim->lthick = (yyval).xval; }
		      else { (yyval).prim->lparam = (yyval).xval; }
		      }
	        }
		  }
#line 2618 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1022 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; }
#line 2624 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1025 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = -(yyvsp[0]).xval; }
#line 2630 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1028 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval + (yyvsp[0]).xval; }
#line 2636 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1031 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval - (yyvsp[0]).xval; }
#line 2642 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1035 "dpic.y" /* yacc.c:1646  */
    { inlogic = false;
    	  (yyval).xval = (yyvsp[-2]).xval;
    	  if ((yyval).xval == 0.0) {
		    currprod = 2 /* ifhead1 */;
		    skiptobrace();
    	    }
		  }
#line 2654 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1045 "dpic.y" /* yacc.c:1646  */
    { inlogic = true; }
#line 2660 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1051 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval != 0.0) || ((yyvsp[0]).xval != 0.0)) { (yyval).xval = 1.0; }
    	  else { (yyval).xval = 0.0; }
		  }
#line 2668 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1057 "dpic.y" /* yacc.c:1646  */
    {
		  (yyval).xval = (yyvsp[-4]).xval;                     /* initial value  */
		  (yyval).yval = (yyvsp[-1]).xval;                          /* increment */
		  (yyval).endchop = (yyvsp[-2]).xval;                     /* final value */
		  (yyval).toklen = 0;                                  /* flags */
		  if ((yyval).xval == (yyval).endchop) {
			(yyval).toklen = -1;
			(yyval).yval = 1.0; }
		  else if ((yyvsp[-1]).lexval == Xmult) {
			t = 0.0;
			if ((yyval).xval == 0.0) { (yyval).toklen = 860; }
			else { t = (yyval).endchop * (yyval).xval; }
			if (t < 0.0) { (yyval).toklen = 862; }
			else if ((t == 0.0) && (fabs((yyval).yval * (yyval).xval) != 0.0)) {
			  (yyval).toklen = 860; }
			else if (((yyval).yval == 0.0) && (t != 0.0)) { (yyval).toklen = 860; }
			else if ((fabs((yyval).yval) == 1) &&
				 (fabs((yyval).xval) != fabs((yyval).endchop))) { (yyval).toklen = 860; }
			else { (yyval).toklen = 1; }
		    }
		  else if ((yyval).yval == 0.0) { (yyval).toklen = 860; }
		  else if (((yyval).endchop - (yyval).xval) * (yyval).yval > 0) { (yyval).toklen = -1; }
		  if ((yyval).toklen > 800) { markerror((yyval).toklen); (yyval).toklen = 0; }
							/* store loop variable */
		  (yyval).startchop = (yyvsp[-4]).startchop;
		  if ((yyval).startchop == 0.0) {
			(yyval).varname = (yyvsp[-4]).varname;
			(yyval).varname->val = (yyval).xval; }
		  else if ((Rnd((yyval).startchop)) != Xscale) {
			if (envblock->blockparms.env == NULL) { inheritenv(envblock); }
			envblock->envinx((yyval).startchop) = (yyval).xval; }
		  else { resetscale((yyval).xval, Xeq, envblock); }

		  currprod = 3 /* forhead1 */ ;
		  if ((yyval).toklen == 0) { skiptobrace(); }
          else { readfor(NULL, 1, &inbuf, '}', true); }
#ifdef DDEBUG
    	  if (debuglevel > 0) {
            fprintf(log_," forhead:\n");
		    wrbufaddr(inbuf,0);
		    fprintf(log_, "for: initial="); wfloat(&log_, (yyval).xval);
		    fprintf(log_, " final="); wfloat(&log_, (yyval).endchop);
		    fprintf(log_, " incr="); wfloat(&log_, (yyval).yval);
		    putc('\n', log_); }
#endif
		  }
#line 2719 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1106 "dpic.y" /* yacc.c:1646  */
    { (yyval) = forattr;
	    attribp = &(yyval);
#ifdef DDEBUG
		if (debuglevel>1) prattribute("forincr1 $$",&(yyval));
#endif
	    if (attribp->varname != NULL) { attribp->xval = attribp->varname->val; }
	    else { attribp->xval = envblock->envinx(attribp->startchop); }
	    bswitch = false;
	    if (attribp->toklen < 0) {
		  if (attribp->yval == 0) { bswitch = true; }
		  else {
		    attribp->xval += attribp->yval;
		    if (((attribp->yval > 0) && (attribp->xval > attribp->endchop)) ||
			    ((attribp->yval < 0) && (attribp->xval < attribp->endchop))) {
			  bswitch = true; }
		    }
	      }
	    else if (attribp->xval == 0) { bswitch = true; }
	    else {
		  attribp->xval *= attribp->yval;
		  if (((fabs(attribp->yval) >= 1.0) &&
		     (fabs(attribp->xval) > fabs(attribp->endchop))) ||
		    ((fabs(attribp->yval) < 1.0) &&
		     (fabs(attribp->xval) < fabs(attribp->endchop)))) { bswitch= true; }
	      }
	    if (attribp->varname != NULL) { attribp->varname->val = attribp->xval; }
	    else if ((Rnd(attribp->startchop)) != Xscale) {
		  envblock->envinx(attribp->startchop)= attribp->xval; }
	    else { resetscale(attribp->xval, Xeq, envblock); }
	    if (bswitch) {
		  while (inbuf->attrib < 0) {
		    lastm = inbuf;
		    inbuf = inbuf->higherb;
		    disposebufs(&lastm); }
		  lastm = inbuf;
		  inbuf = inbuf->higherb;
		  disposebufs(&lastm);
	      }
		}
#line 2763 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1148 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 1.0; }
#line 2769 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1151 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 2775 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1157 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = (yyvsp[0]).lexval; }
#line 2781 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1161 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 2787 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1164 "dpic.y" /* yacc.c:1646  */
    { attribp = &(yyvsp[0]);
		  (yyval).state = 1;
		  bswitch = false;
		  if (attribp->prim != NULL) {
			if (attribp->prim->textp == NULL) { markerror(861); }
			else if ((yyvsp[-1]).lexval != Xgt) { markerror(869); }
			else if (safemode) { markerror(901); }
			else { bswitch = true; }
		    }
#ifdef SAFE_MODE
		  if (bswitch) { markerror(901); }
#else
		  if (bswitch) { pointoutput(true,attribp->prim->textp, &(yyval).state); }
#endif
		  deletestringbox(&attribp->prim);
		  }
#line 2808 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1182 "dpic.y" /* yacc.c:1646  */
    { attribp = &(yyvsp[0]);
		  (yyval).state = 1;
		  bswitch = false;
		  if (attribp->prim != NULL) {
			if (attribp->prim->textp == NULL) { markerror(861); }
			else if (((yyvsp[-2]).lexval != Xgt) || ((yyvsp[-1]).lexval != Xgt)) {
			    markerror(869); }
			else if (safemode) { markerror(901); }
			else { bswitch = true; }
		    }
#ifdef SAFE_MODE
		  if (bswitch) { markerror(901); }
#else
		  if (bswitch) { pointoutput(false, attribp->prim->textp, &(yyval).state); }
#endif
		  deletestringbox(&attribp->prim);
		  }
#line 2830 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1202 "dpic.y" /* yacc.c:1646  */
    { resetenv((yyvsp[0]).lexval, envblock); }
#line 2836 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1205 "dpic.y" /* yacc.c:1646  */
    { resetenv((yyvsp[0]).lexval, envblock); }
#line 2842 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1209 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = -1.0;
	      attribp = &(yyvsp[0]);
	      if (attribp->prim != NULL) {
		    if (attribp->prim->textp != NULL) {
		      primtextp = attribp->prim->textp;
		      if (primtextp->segmnt != NULL) {
			    if (primtextp->seginx + primtextp->len >= CHBUFSIZ) {markerror(866); }
			    else if (safemode) { markerror(901); }
#ifndef SAFE_MODE
			    else {
			      primtextp->segmnt[primtextp->seginx + primtextp->len] = '\0';
			      (yyval).xval = system((char*)
                    &primtextp->segmnt[primtextp->seginx]); }
#endif
		        }
		      }
		    deletestringbox(&attribp->prim);
	        }
#ifdef DDEBUG
		  if (debuglevel>1) { prattribute("systemcmd1",&(yyval)); }
#endif
		  }
#line 2869 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1234 "dpic.y" /* yacc.c:1646  */
    { (yyval).prim = sprintfstring( &(yyvsp[0]), &(yyvsp[0]), 0 );
          (yyval).lexval = Xstring;
          }
#line 2877 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1241 "dpic.y" /* yacc.c:1646  */
    { (yyval).prim = sprintfstring( &(yyvsp[-2]), &(yyvsp[0]), (yyvsp[0]).state );
          (yyval).lexval = Xstring;
          }
#line 2885 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1247 "dpic.y" /* yacc.c:1646  */
    { (yyval).state = 1; }
#line 2891 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1250 "dpic.y" /* yacc.c:1646  */
    { (yyval).state = (yyvsp[0]).state + 1; }
#line 2897 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1256 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			wprim = (yyvsp[-2]).prim;
			switch (wprim->ptype) {
			  case Xbox:
			  case Xblock:
			    if (wprim->ptype == Xblock) {
			      r = 0.5 * ((yyvsp[0]).xval - wprim->blockheight_);
			      wprim->blockheight_ = (yyvsp[0]).xval; }
			    else {
			      r = 0.5 * ((yyvsp[0]).xval - wprim->boxheight_);
			      wprim->boxheight_ = (yyvsp[0]).xval; }
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (wprim->direction) {
			        case Xleft:
			        case Xright:
				      break; /* blank case */
			        case Xup:
				      shift((yyvsp[-2]).prim, 0.0, r);
				      break;
			        case Xdown:
				      shift((yyvsp[-2]).prim, 0.0, -r);
				      break;
			        }
			      }
			    break;
			  case Xstring:
	  			wprim->boxheight_ = (yyvsp[0]).xval;
	  			if ((drawmode == PDF) && (wprim->textp != NULL)) {
	      		  wprim->boxwidth_ = wprim->boxheight_ *
					wprim->textp->len * 0.6;
	  			  }
	  			break;
			  case Xcircle:
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (wprim->direction) {
			        case Xleft:
			        case Xright:
				      break; /* blank case */
			        case Xup:
				      wprim->aat.ypos += (0.5 * (yyvsp[0]).xval) - wprim->circleradius_;
				      break;
			        case Xdown:
				      wprim->aat.ypos += wprim->circleradius_ - (0.5 * (yyvsp[0]).xval);
				      break;
			        }
			      }
			    wprim->circleradius_ = (yyvsp[0]).xval * 0.5;
			    break;
			  case Xellipse:
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (wprim->direction) {
			        case Xleft:
			        case Xright:
				      break; /* blank case */
			        case Xup:
				      wprim->aat.ypos +=
				        0.5 * ((yyvsp[0]).xval - wprim->ellipseheight_);
				      break;
			        case Xdown:
				      wprim->aat.ypos +=
				        0.5 * (wprim->ellipseheight_ - (yyvsp[0]).xval);
				      break;
			        }
			      }
			    wprim->ellipseheight_ = (yyvsp[0]).xval;
			    break;
			  case Xline:
			  case Xarrow:
			  case Xmove:
			  case Xarc:
			  case Xspline:
			    prp = (yyvsp[-2]).prim;
			    while (prp != NULL) {
			      prp->lineheight_ = (yyvsp[0]).xval;
			      if (isthen(prp)) { prp = prp->parent; } else { prp = NULL; }
			      }
			    break;
			  case Xlabel:
			  case XLaTeX:
			    markerror(858);
			    break;
			    }
		      }
			}
#line 2986 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1342 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			wprim = (yyvsp[-2]).prim;
			switch (wprim->ptype) {
			  case Xbox:
			  case Xblock:
			    if (wprim->ptype == Xblock) {
			      r = 0.5 * ((yyvsp[0]).xval - wprim->blockwidth_);
			      wprim->blockwidth_ = (yyvsp[0]).xval; }
			  else {
			      r = 0.5 * ((yyvsp[0]).xval - wprim->boxwidth_);
			      wprim->boxwidth_ = (yyvsp[0]).xval; }
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
			    switch (wprim->direction) {
			      case Xup:
			      case Xdown:
				    break; /* blank case */
			      case Xright:
				    shift((yyvsp[-2]).prim, r, 0.0);
				    break;
			      case Xleft:
				    shift((yyvsp[-2]).prim, -r, 0.0);
				    break;
			      }
			    }
			  break;
			case Xstring:
			  wprim->boxwidth_ = (yyvsp[0]).xval;
			  break;
			case Xcircle:
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
			    switch (wprim->direction) {
			      case Xup:
			      case Xdown:
				    break; /* blank case */
			      case Xright:
				    wprim->aat.xpos += (0.5 * (yyvsp[0]).xval) - wprim->circleradius_;
				    break;
			      case Xleft:
				    wprim->aat.xpos += wprim->circleradius_ - (0.5 * (yyvsp[0]).xval);
				    break;
			      }
			    }
			  wprim->circleradius_ = (yyvsp[0]).xval * 0.5;
			  break;
			case Xellipse:
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
			    switch (wprim->direction) {
			      case Xup:
			      case Xdown:
				    break; /* blank case */
			      case Xright:
				    wprim->aat.xpos += 0.5 * ((yyvsp[0]).xval - wprim->ellipsewidth_);
				    break;
			      case Xleft:
				    wprim->aat.xpos += 0.5 * (wprim->ellipsewidth_ - (yyvsp[0]).xval);
				    break;
			      }
			    }
			  wprim->ellipsewidth_ = (yyvsp[0]).xval;
			  break;
			case Xline:
			case Xarrow:
			case Xmove:
			case Xarc:
			case Xspline:
			  prp = (yyvsp[-2]).prim;
			  while (prp != NULL) {
			    prp->linewidth_ = (yyvsp[0]).xval;
			    if (isthen(prp)) { prp = prp->parent; } else { prp = NULL; }
			    }
			  break;
			case Xlabel:
			case XLaTeX:
			  markerror(858);
			  break;
			  }
		    }
	 	  }
#line 3069 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1422 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			wprim = (yyvsp[-2]).prim;
			switch (wprim->ptype) {
			  case Xbox:
			    wprim->boxradius_ = (yyvsp[0]).xval;
			    break;
			  case Xarc:
			    t = (yyvsp[0]).xval;
			    if (wprim->direction == 0) {
			      (yyvsp[0]).xval = wprim->aat.xpos + (wprim->aradius_ *
                    cos( wprim->startangle_ + wprim->arcangle_));
			      (yyvsp[0]).yval = wprim->aat.ypos + (wprim->aradius_ *
                    sin( wprim->startangle_ + wprim->arcangle_));
			      r = cos(wprim->startangle_);
			      s = sin(wprim->startangle_);
			      wprim->aat.xpos += wprim->aradius_ * r;
			      wprim->aat.ypos += wprim->aradius_ * s;
			      wprim->aradius_ = t;
			      wprim->aat.xpos -= wprim->aradius_ * r;
			      wprim->aat.ypos -= wprim->aradius_ * s;
			      setstflag(&(yyvsp[-2]).state, Xradius);
			      goto object_xx;
			      }
			    else {
			      r = cos(wprim->startangle_);
			      s = sin(wprim->startangle_);
			      (yyval).prim->aat.xpos += wprim->aradius_ * r;
			      (yyval).prim->aat.ypos += wprim->aradius_ * s;
			      (yyval).prim->aradius_ = t;
			      (yyval).prim->aat.xpos -= wprim->aradius_ * r;
			      (yyval).prim->aat.ypos -= wprim->aradius_ * s;
			      setstflag(&(yyval).state, Xradius);
				  }
			    break;
			  case Xcircle:
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (wprim->direction) {
			        case Xleft:
				      wprim->aat.xpos += wprim->circleradius_ - (yyvsp[0]).xval;
				      break;
			        case Xright:
				      wprim->aat.xpos += (yyvsp[0]).xval - wprim->circleradius_;
				      break;
			        case Xup:
				      wprim->aat.ypos += (yyvsp[0]).xval - wprim->circleradius_;
				      break;
			        case Xdown:
				      wprim->aat.ypos += wprim->circleradius_ - (yyvsp[0]).xval;
				      break;
			        }
			      }
			    wprim->circleradius_ = (yyvsp[0]).xval;
			    setstflag(&(yyvsp[-2]).state, Xradius);
			    break;
			  default:
			    markerror(858);
			    break;
			  }
		    }
		  }
#line 3134 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1484 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			wprim = (yyvsp[-2]).prim;
			if (wprim->ptype == Xcircle) {
			  r = 0.5 * (yyvsp[0]).xval;
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
				switch (wprim->direction) {
				  case Xleft:
				    wprim->aat.xpos += wprim->circleradius_ - r;
				    break;
				  case Xright:
				    wprim->aat.xpos += r - wprim->circleradius_;
				    break;
				  case Xup:
				    wprim->aat.ypos += r - wprim->circleradius_;
				    break;
				  case Xdown:
				    wprim->aat.ypos += wprim->circleradius_ - r;
				    break;
				  }
			    }
			  wprim->circleradius_ = r;
			  }
			else { markerror(858); }
		    }
		  }
#line 3164 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1511 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) { wprim = (yyvsp[-2]).prim;
			if ((yyvsp[0]).xval >= 0.0) { wprim->lthick = (yyvsp[0]).xval; }
            else { wprim->lthick = venv(wprim,Xlinethick); } }   /*Error msg?*/
		  }
#line 3173 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1517 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).prim != NULL) && ((yyvsp[0]).lexval != XEMPTY)) {
			wprim = (yyval).prim;
			r = (yyvsp[0]).xval - 1;
			corner((yyvsp[-2]).prim, Dotc, &x1, &z1);
			switch (wprim->ptype) {
			  case Xbox:
			  case Xblock:
			  case Xstring:
			    if (teststflag((yyvsp[-2]).state, Xat)) {
			      dx = 0.0;
			      dy = 0.0;
			      }
			    else if (wprim->ptype == Xblock) {
			      dx = wprim->blockwidth_ * r / 2;
			      dy = wprim->blockheight_ * r / 2;
			      }
			    else {
			      dx = wprim->boxwidth_ * r / 2;
			      dy = wprim->boxheight_ * r / 2;
			      }
			    scaleobj((yyval).prim, (yyvsp[0]).xval);
			    switch (wprim->direction) {
			      case Xright: shift(
                    (yyval).prim, x1 - wprim->aat.xpos + dx, z1 - wprim->aat.ypos);
			        break;
			      case Xleft: shift(
                    (yyval).prim, x1 - wprim->aat.xpos - dx, z1 - wprim->aat.ypos);
			        break;
			      case Xup: shift(
                    (yyval).prim, x1 - wprim->aat.xpos, z1 - wprim->aat.ypos + dy);
			        break;
			      case Xdown: shift(
                    (yyval).prim, x1 - wprim->aat.xpos, z1 - wprim->aat.ypos - dy);
			        break;
			      }
			    break;
			  case Xcircle:
			    wprim->circleradius_ = (yyvsp[0]).xval * wprim->circleradius_;
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (wprim->direction) {
			        case Xup:
				      wprim->aat.xpos = x1;
				      wprim->aat.ypos = z1 + wprim->circleradius_;
				      break;
			        case Xdown:
				      wprim->aat.xpos = x1;
				      wprim->aat.ypos = z1 - wprim->circleradius_;
				      break;
			        case Xright:
				      wprim->aat.xpos = x1 + wprim->circleradius_;
				      wprim->aat.ypos = z1;
				      break;
			        case Xleft:
				      wprim->aat.xpos = x1 - wprim->circleradius_;
				      wprim->aat.ypos = z1;
				      break;
			        }
			      }
			    break;
			  case Xellipse:
			    wprim->ellipsewidth_ *= (yyvsp[0]).xval;
			    wprim->ellipseheight_ *= (yyvsp[0]).xval;
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (wprim->direction) {
			        case Xup:
				      wprim->aat.xpos = x1;
				      wprim->aat.ypos = z1 + (wprim->ellipseheight_ / 2);
				      break;
			        case Xdown:
				      wprim->aat.xpos = x1;
				      wprim->aat.ypos = z1 - (wprim->ellipseheight_ / 2);
				      break;
			        case Xright:
				      wprim->aat.xpos = x1 + (wprim->ellipsewidth_ / 2);
				      wprim->aat.ypos = z1;
				      break;
			        case Xleft:
				      wprim->aat.xpos = x1 - (wprim->ellipsewidth_ / 2);
				      wprim->aat.ypos = z1;
				      break;
			        }
			      }
			    break;
			  case Xline:
			  case Xarrow:
			  case Xmove:
			  case Xarc:
			  case Xspline:
			    scaleobj((yyval).prim, (yyvsp[0]).xval);
			    corner((yyval).prim, Dotc, &r, &s);
			    shift((yyval).prim, x1 - r, z1 - s);
			    break;
			  case Xlabel:
			  case XLaTeX:
			    markerror(858);
			    break;
			  }
		    }
		  }
#line 3277 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1618 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			wprim = (yyval).prim;
			if ((wprim->ptype == Xspline) || (wprim->ptype == Xarrow) ||
			    (wprim->ptype == Xmove) || (wprim->ptype == Xline) ||
			    (wprim->ptype == Xarc)) {
			  i = (yyvsp[-1]).lexval;
			  envblock->direction = i;
			  eb = findenv(envblock);
			  switch (wprim->ptype) {
			    case Xarc:
			      r = cos(wprim->startangle_);
			      s = sin(wprim->startangle_);
			      wprim->aat.xpos += wprim->aradius_ * r;
			      wprim->aat.ypos += wprim->aradius_ * s;
				  nwi = wprim->direction;
			      if (((nwi == Xup) && (i == Xleft)) ||
				      ((nwi == Xdown) && (i == Xright)) ||
				      ((nwi == Xright) && (i == Xup)) ||
				      ((nwi == Xleft) && (i == Xdown))) {
				    wprim->arcangle_ = pi * 0.5; }
			      else if (((nwi == Xup) && (i == Xright)) ||
				      ((nwi == Xdown) && (i == Xleft)) ||
				      ((nwi == Xright) && (i == Xdown)) ||
				      ((nwi == Xleft) && (i == Xup))) {
				    wprim->arcangle_ = (-pi) * 0.5; }
			      if ((yyvsp[0]).lexval != XEMPTY) {
				    wprim->aradius_ = (yyvsp[0]).xval; }
			      wprim->aat.xpos -= wprim->aradius_ * r;
			      wprim->aat.ypos -= wprim->aradius_ * s;
			      wprim->direction = i;
			      break;
			    case Xline:
			    case Xmove:
			    case Xarrow:
			    case Xspline:
			      wprim->direction = i;
			      if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; s = r; }
			      else { switch (wprim->ptype) {
				    case Xline:
				    case Xarrow:
				    case Xspline:
				      r = eb->envinx(Xlineht);
				      s = eb->envinx(Xlinewid);
				      break;
				    case Xmove:
				      r = eb->envinx(Xmoveht);
				      s = eb->envinx(Xmovewid);
				      break;
				      }
			        }
			      lineardir((yyval).prim, r, s, &(yyval).state);
			      break;
			      }
			  }
			else { markerror(858); }
		    }
#ifdef DDEBUG
	    if (debuglevel > 0) { printobject((yyval).prim); }
#endif
		  }
#line 3342 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1680 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			setspec(&(yyval).prim->spec, (yyvsp[-1]).lexval);
			if ((yyvsp[0]).lexval == XEMPTY) {
              if ((yyvsp[-1]).lexval == Xdashed) {
				eb = findenv(envblock);
                (yyval).prim->lparam = eb->envinx(Xdashwid); }
              }
            else if ((((yyvsp[-1]).lexval == Xsolid) || ((yyvsp[-1]).lexval == Xinvis))
               && (((yyvsp[-2]).prim->ptype == Xmove) || ((yyvsp[-2]).prim->ptype == Xspline)
                || ((yyvsp[-2]).prim->ptype == Xarrow) || ((yyvsp[-2]).prim->ptype == Xline))) {
			  lineardir((yyval).prim, (yyvsp[0]).xval, (yyvsp[0]).xval, &(yyval).state); }
			else if (((yyvsp[-1]).lexval == Xsolid) || ((yyvsp[-1]).lexval == Xinvis)) {
			  markerror(858); }
			else { (yyval).prim->lparam = (yyvsp[0]).xval; }
		    }
#ifdef DDEBUG
	    if (debuglevel > 0) { printobject((yyval).prim); }
#endif
		  }
#line 3366 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1701 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			if (((yyvsp[-2]).prim->ptype != Xspline) &&
			    ((yyvsp[-2]).prim->ptype != Xmove) &&
			    ((yyvsp[-2]).prim->ptype != Xarrow) && ((yyvsp[-2]).prim->ptype != Xline)) {
			  markerror(858); }
			else {
			  wprim = (yyvsp[-2]).prim;
			  if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; }
			  else {
				eb = findenv(envblock);
				r = eb->envinx(Xcirclerad);
			    }
			  if (teststflag((yyval).state, Xchop)) { (yyval).endchop = r; }
			  else {
				(yyval).startchop = r;
				(yyval).endchop = r;
				setstflag(&(yyval).state, Xchop);
			    }
			  }
		    }
		  }
#line 3392 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1724 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			wprim = (yyvsp[-2]).prim;
			if ((yyvsp[0]).lexval != XEMPTY) { s = (yyvsp[0]).xval; }
			else {
			  eb = findenv(envblock);
			  s = eb->envinx(Xfillval);
			  }
			prp = (yyval).prim;
			while (prp != NULL) {
			  switch (wprim->ptype) {
			    case Xbox:
			      prp->boxfill_ = s;
			      break;
			    case Xcircle:
			      prp->circlefill_ = s;
			      break;
			    case Xellipse:
			      prp->ellipsefill_ = s;
			      break;
			    default:
                  if ((drawmode == TeX) || (drawmode == tTeX) ||
                      (drawmode == Pict2e)) { markerror(858); }
			      else {
				    switch (wprim->ptype) {
				      case Xline:
				      case Xarrow:
				      case Xmove:
				      case Xspline:
				      case Xarc:
				        prp->linefill_ = s;
				        break;
				      default:
				        markerror(858);
				        break;
				      }
			        }
			      break;
			    }
			  if (isthen(prp)) { prp = prp->parent; }
			  else { prp = NULL; }
			  }
		    }
		  }
#line 3440 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1769 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			wprim = (yyval).prim;
			if ((wprim->ptype != Xspline) && (wprim->ptype != Xarc) &&
			    (wprim->ptype != Xarrow) && (wprim->ptype != Xline)) {
			  markerror(858); }
			else {
			  wprim->lineatype_ = pahlex(wprim->lineatype_,(yyvsp[-1]).lexval);
			  if ((yyvsp[0]).lexval != XEMPTY) { lj = Rnd((yyvsp[0]).xval); }
			  else {
				eb = findenv(envblock);
				lj = (long)floor(eb->envinx(Xarrowhead)+0.5);
			    }
			  wprim->lineatype_ = pahnum(wprim->lineatype_, lj);
			  }
		    }
		  }
#line 3461 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1787 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
#ifdef DDEBUG
		    if (debuglevel > 0) {
	          fprintf(log_, "lexical \"then\" found, ");
	          prtstval((yyvsp[-1]).state); putc('\n', log_); }
#endif
			appendthen(&(yyval).prim);
			if ((yyvsp[-1]).prim->ptype != Xarc) { setstflag(&(yyval).state, XEMPTY); }
		    }
		  }
#line 3476 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1799 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			wprim = (yyvsp[-1]).prim;
			if (wprim->ptype != Xarc) { markerror(858); }
			else {
			  if ((wprim->arcangle_ > 0.0) && (wprim->direction == 0)) {
				wprim->arcangle_ = -fabs(
				  principal((2.0 * pi) - wprim->arcangle_,2.0*pi));}
			  else if (wprim->direction != 0) {
				wprim->aat = arcstart((yyval).prim);
				switch (wprim->direction) {
				  case Xup:
				    wprim->aat.xpos += wprim->aradius_;
				    break;
				  case Xdown:
				    wprim->aat.xpos -= wprim->aradius_;
				    break;
				  case Xleft:
				    wprim->aat.ypos += wprim->aradius_;
				    break;
				  case Xright:
				    wprim->aat.ypos -= wprim->aradius_;
				    break;
				  }
				if (wprim->arcangle_ > 0.0) {
				  wprim->startangle_ =
                    principal(wprim->startangle_ + pi, pi); }
				  wprim->arcangle_ = -fabs(wprim->arcangle_);
			    }
			  setstflag(&(yyval).state, Xcw);
			  }
		    }
		  }
#line 3513 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1833 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			wprim = (yyvsp[-1]).prim;
			if (wprim->ptype != Xarc) { markerror(858); }
			else {
			  if ((wprim->arcangle_ < 0.0) && (wprim->direction == 0)) {
				wprim->arcangle_ =
                  fabs(principal(wprim->arcangle_ - (2.0 * pi),2.0*pi)); }
			  else if (wprim->direction != 0) {
				wprim->aat = arcstart((yyvsp[-1]).prim);
				switch (wprim->direction) {
				  case Xup: wprim->aat.xpos -= wprim->aradius_; break;
				  case Xdown: wprim->aat.xpos += wprim->aradius_; break;
				  case Xleft: wprim->aat.ypos -= wprim->aradius_; break;
				  case Xright: wprim->aat.ypos += wprim->aradius_; break;
				  }
				if (wprim->arcangle_ < 0.0) {
				  wprim->startangle_ =
                    principal( wprim->startangle_ + pi, pi); }
				  wprim->arcangle_ = fabs(wprim->arcangle_);
			    }
			  setstflag(&(yyvsp[-1]).state, Xccw);
			  }
		    }
		  }
#line 3542 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1859 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			prp = nthprimobj(envblock->son, 0, (yyvsp[-1]).prim->ptype);
			if (prp == NULL) { markerror(857); }
			else {
			  wprim = (yyvsp[-1]).prim;
			  wprim->lparam = prp->lparam;
			  wprim->lthick = prp->lthick;
			  wprim->direction = prp->direction;
			  wprim->spec = prp->spec;
			  if (hasoutline((yyvsp[-1]).lexval, false)) {
				copystr(&wprim->outlinep, prp->outlinep); }
			  if (hasshade((yyvsp[-1]).lexval, false)) {
				copystr(&wprim->shadedp, prp->shadedp); }
			  }
			if (prp != NULL) {
			  wprim = (yyvsp[-1]).prim;
			  switch (wprim->ptype) {
			    case Xbox:
			    case Xstring:
			      if (wprim->ptype == Xbox) {
				    switch (wprim->direction) {
				      case Xup:
				        wprim->aat.ypos += 0.5 *
					      (prp->boxheight_ - wprim->boxheight_);
				        break;
				      case Xdown:
				        wprim->aat.ypos -= 0.5 *
					      (prp->boxheight_ - wprim->boxheight_);
				        break;
				      case Xleft:
				        wprim->aat.xpos -=
				          0.5 * (prp->boxwidth_ - wprim->boxwidth_);
				        break;
				      case Xright:
				        wprim->aat.xpos +=
				          0.5 * (prp->boxwidth_-wprim->boxwidth_);
				        break;
				      }
			        }
			      wprim->boxfill_ = prp->boxfill_;
			      wprim->boxheight_ = prp->boxheight_;
			      wprim->boxwidth_ = prp->boxwidth_;
			      wprim->boxradius_ = prp->boxradius_;
			      break;
			    case Xblock:
			      markerror(858);
			      break;
			    case Xcircle:
			      switch (wprim->direction) {
			        case Xup:
				      wprim->aat.ypos +=
                        prp->circleradius_ - wprim->circleradius_;
				      break;
			        case Xdown:
				      wprim->aat.ypos +=
                        wprim->circleradius_ - prp->circleradius_;
				      break;
			        case Xleft:
				      wprim->aat.xpos +=
                        wprim->circleradius_ - prp->circleradius_;
				      break;
			        case Xright:
				      wprim->aat.xpos +=
                        prp->circleradius_ - wprim->circleradius_;
				      break;
			        }
			      wprim->circlefill_ = prp->circlefill_;
			      wprim->circleradius_ = prp->circleradius_;
			      break;
			    case Xellipse:
			      switch (wprim->direction) {
			        case Xup:
				      wprim->aat.ypos +=
				        0.5 * (prp->ellipseheight_ - wprim->ellipseheight_);
				      break;
			        case Xdown:
				      wprim->aat.ypos -=
				        0.5 * (prp->ellipseheight_ - wprim->ellipseheight_);
				      break;
			        case Xleft:
				      wprim->aat.xpos -=
				        0.5 * (prp->ellipsewidth_ - wprim->ellipsewidth_);
				      break;
			        case Xright:
				      wprim->aat.xpos +=
				        0.5 * (prp->ellipsewidth_ - wprim->ellipsewidth_);
				      break;
			        }
			      wprim->ellipsefill_ = prp->ellipsefill_;
			      wprim->ellipseheight_ = prp->ellipseheight_;
			      wprim->ellipsewidth_ = prp->ellipsewidth_;
			      break;
			    case Xarc:
			      x1 = wprim->aat.xpos +
                    (wprim->aradius_ * cos(wprim->startangle_));
			      z1 = wprim->aat.ypos + 
                    (wprim->aradius_ * sin(wprim->startangle_));
			      wprim->aradius_ = prp->aradius_;
			      wprim->startangle_ = prp->startangle_;
			      wprim->aat.xpos = x1 -
                    (wprim->aradius_ * cos(wprim->startangle_));
			      wprim->aat.ypos = z1 -
                    (wprim->aradius_ * sin(wprim->startangle_));
			      wprim->arcangle_ = prp->arcangle_;
			      break;
			    case Xline:
			    case Xarrow:
			    case Xmove:
			    case Xspline:
			      wprim->endpos_.xpos =
				    wprim->aat.xpos + prp->endpos_.xpos-prp->aat.xpos;
			      wprim->endpos_.ypos =
				    wprim->aat.ypos + prp->endpos_.ypos-prp->aat.ypos;
			      wprim->lineheight_ = prp->lineheight_;
			      wprim->linewidth_ = prp->linewidth_;
			      wprim->lineatype_ = prp->lineatype_;
			      break;
			    case Xlabel:
			    case XLaTeX:
			      markerror(858);
			      break;
			    }
			  }
		    }
		  }
#line 3672 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1986 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
			if ((yyvsp[-1]).prim != NULL) {
			  wprim = (yyvsp[-1]).prim;
			  if (wprim->textp == NULL) { wprim->textp = (yyvsp[0]).prim->textp; }
			  else {
				namptr = wprim->textp;
				i = 1;
				while (namptr->nextname != NULL) { namptr = namptr->nextname; i++; }
				namptr->nextname = (yyvsp[0]).prim->textp;
				if (wprim->ptype == Xstring) {
				  if (drawmode == SVG) {
					eb = findenv(envblock);
					if (eb != NULL) {
					  r = findvar("dptextratio", 11);
					  if (r == 0) { r = 1.0; }
					  wprim->boxheight_ += eb->envinx(Xtextht) / r;
					  }
				    }
				  else { wprim->boxheight_ *= ((i + 1) / i); }
				  }
			    }
			  if ((drawmode == PS) || (drawmode == PDF) ||
			      (drawmode == PSfrag)) { /* output contains text */
				printstate = ((printstate >> 1) * 2) + 1;
			    }
			  }
			(yyvsp[0]).prim->textp = NULL;
			deletestringbox(&(yyvsp[0]).prim);
		    }
		  }
#line 3707 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 2018 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval)  = (yyvsp[-2]);
			if (((yyvsp[-2]).prim->ptype == Xmove) || ((yyvsp[-2]).prim->ptype == Xspline) ||
			  ((yyvsp[-2]).prim->ptype == Xarrow) || ((yyvsp[-2]).prim->ptype == Xline) ||
			  ((yyvsp[-2]).prim->ptype == Xarc)) {
			    wprim = (yyvsp[-2]).prim;
			    x1 = (yyvsp[0]).xval + wprim->aat.xpos;
			    z1 = (yyvsp[0]).yval + wprim->aat.ypos;
			    if (wprim->ptype == Xarc) {
				  x1 += wprim->aradius_ * cos(wprim->startangle_);
				  z1 += wprim->aradius_ * sin(wprim->startangle_);
			      }
			    (yyvsp[0]).xval = x1;
			    (yyvsp[0]).yval = z1;
                goto object_xx;
			    }
			  else { markerror(858); }
		    }
		  }
#line 3731 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 2039 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			wprim = (yyval).prim;
			if ((wprim->ptype == Xmove) || (wprim->ptype == Xspline) ||
			  (wprim->ptype == Xarrow) || (wprim->ptype == Xline) ||
              (wprim->ptype == Xarc)) {
			  if (wprim->ptype == Xarc) {
                r = (yyvsp[0]).xval;
                s = (yyvsp[0]).yval;
				if (teststflag((yyvsp[-2]).state, Xto)) {
				  (yyvsp[0]).xval = wprim->aat.xpos + (wprim->aradius_ *
                    cos( wprim->startangle_ + wprim->arcangle_));
				  (yyvsp[0]).yval = wprim->aat.ypos + (wprim->aradius_ *
                    sin( wprim->startangle_ + wprim->arcangle_));
				  }
				wprim->aat.xpos = r -
                  (wprim->aradius_ * cos(wprim->startangle_));
				wprim->aat.ypos = s -
                  (wprim->aradius_ * sin(wprim->startangle_));
				if (teststflag((yyvsp[-2]).state, Xto)) { goto object_xx; }
			    }
			  else if (!teststflag((yyvsp[-2]).state, Xto)) {
				prp = (yyvsp[-2]).prim;
				while (isthen(prp)) { prp = prp->parent; }
				shift(prp, (yyvsp[0]).xval - prp->aat.xpos, (yyvsp[0]).yval - prp->aat.ypos);
			    }
			  else {
				wprim->aat.xpos = (yyvsp[0]).xval;
				wprim->aat.ypos = (yyvsp[0]).yval;
                }
			  setstflag(&(yyvsp[-2]).state, Xfrom);
			  }
			else { markerror(858); }
		    }
		  }
#line 3770 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2075 "dpic.y" /* yacc.c:1646  */
    {
          object_xx:
    	    if ((yyvsp[-2]).prim != NULL) {
    	      if (((yyvsp[-2]).prim->ptype == Xmove) || ((yyvsp[-2]).prim->ptype == Xspline) ||
    	        ((yyvsp[-2]).prim->ptype == Xarrow) || ((yyvsp[-2]).prim->ptype == Xline) ||
    	        ((yyvsp[-2]).prim->ptype == Xarc)) {
    	        if (((yyvsp[-2]).prim->ptype != Xarc) & teststflag((yyvsp[-2]).state, Xto)) {
#ifdef DDEBUG
    	    	  if (debuglevel > 0) {
    	    	    fprintf(log_, "\"then\" inserted, \n");
    	    	    prtstval((yyvsp[-2]).state); putc('\n', log_); }
#endif
    	    	  appendthen(&(yyval).prim);
    	    	  setstflag(&(yyval).state, XEMPTY);
    	          }
    	        wprim = (yyval).prim;
    	        if (wprim->ptype != Xarc) {
			      wprim->endpos_.xpos = (yyvsp[0]).xval;
			      wprim->endpos_.ypos = (yyvsp[0]).yval;
    	          }
    	        else {
    	    	  x1 = wprim->aat.xpos + (wprim->aradius_ *
                    cos(wprim->startangle_));
    	    	  z1 = wprim->aat.ypos + (wprim->aradius_ *
                    sin(wprim->startangle_));
    	    	  dx = (yyvsp[0]).xval - x1;
    	    	  dy = (yyvsp[0]).yval - z1;
    	    	  ts = (dx * dx) + (dy * dy);
    	    	  if (wprim->direction != 0) { i = wprim->direction; }
    	    	  else { i = (yyval).toklen; }
#ifdef DDEBUG
    	    	  if (debuglevel == 2) {
    	    	    fprintf(log_, " (x1,z1)="); wpair(&log_, x1, z1);
    	    	    fprintf(log_, " (dx,dy)="); wpair(&log_, dx, dy);
    	    	    fprintf(log_, " ts="); wfloat(&log_, ts);
    	    	    fprintf(log_, " i=%d", i); }
#endif
    	    	  if (ts == 0.0) { wprim->arcangle_ = 0.0; }
    	    	  else {
    	    	    t = sqrt(Max(0.0,(4.0 *
                          wprim->aradius_ * wprim->aradius_) - ts) / ts);
#ifdef DDEBUG
    	    	    if (debuglevel == 2) {
    	    		  fprintf(log_, " t="); wfloat(&log_, t);
    	    		  fprintf(log_, " |arcangle|=");
    	    		  wfloat(&log_, wprim->arcangle_ * 180 / pi);
    	    		  putc('\n', log_); }
#endif
    	    	    r = sqrt(ts);               /* t is always nonnegative  */
    	    	    if (t <= 0.0) { wprim->aradius_ = 0.5 * r; }
    	    	    switch (i) {
							/* Determine which of the two default arcs to
							   draw: */
    	    	    case Xup:
    	    	      if (wprim->arcangle_ * ((-dx) - (t * dy)) < 0.0) {t= -t; }
    	    	      break;
    	    	    case Xdown:
    	    	      if (wprim->arcangle_ * ((-dx) - (t * dy)) > 0.0) { t=-t; }
    	    	      break;
    	    	    case Xright:
    	    	      if (wprim->arcangle_ * (dy - (t * dx)) < 0.0) { t = -t; }
    	    	      break;
    	    	    case Xleft:
    	    	      if (wprim->arcangle_ * (dy - (t * dx)) > 0.0) { t = -t; }
    	    	      break;
    	    	      }
    	    	    wprim->aat.xpos = x1 + (0.5 * (dx + (t * dy)));
    	    	    wprim->aat.ypos = z1 + (0.5 * (dy - (t * dx)));
#ifdef DDEBUG
    	    	    if (debuglevel == 2) {
    	    		  fprintf(log_, " t="); wfloat(&log_, t);
    	    		  fprintf(log_, " aradius=");
    	    		  wfloat(&log_, wprim->aradius_);
    	    		  fprintf(log_, " aat=");
    	    		  wpair(&log_, wprim->aat.xpos, wprim->aat.ypos);
    	    		  putc('\n', log_);
    	    	      }
#endif
    	    	    setangles(&wprim->startangle_,
    	    		      &wprim->arcangle_, wprim->aat, x1, z1,
    	    		      (yyvsp[0]).xval, (yyvsp[0]).yval);
    	    	    }
							/* ratio centre-to-chord/half-chord */
    	    	  if (wprim->direction != 0) { (yyval).toklen = wprim->direction; }
    	    	  wprim->direction = 0;
    	          }
    	        setstflag(&(yyval).state, Xto);
#ifdef DDEBUG
    	        if (debuglevel > 0) { printobject((yyval).prim); }
#endif
    	        }
    	      else { markerror(858); }
    	      }
		   }
#line 3869 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2171 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			if ((drawmode != SVG) || (getstval((yyvsp[-2]).state) == 0)) {
			    setstval(&(yyval).state, Dotc); }
			setstflag(&(yyval).state, Xat);
#ifdef DDEBUG
		    if (debuglevel > 0) {
	    	  fprintf(log_, " (xval,yval)=");
	    	  wpair(&log_, (yyval).xval, (yyval).yval);
	    	  fprintf(log_, " state=%d val=%d flag=%d\n",
		      (yyval).state, (yyval).state >> 8, (yyval).state & 255);
		      }
#endif
		    }
		  }
#line 3890 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2189 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			namptr = (yyval).prim->textp;
			if (namptr == NULL) { markerror(861); }
            else {
			  while (namptr->nextname != NULL) { namptr = namptr->nextname; }
			  setjust(namptr, (yyvsp[0]).lexval);
			  if (drawmode == SVG) {
				wprim = (yyval).prim;
				if ((!teststflag((yyval).state, Xat)) &&
                    (wprim->ptype == Xstring)) {
				  (yyval).xval = wprim->aat.xpos;
				  (yyval).yval = wprim->aat.ypos;
				  setstflag(&(yyval).state, Xat); }
				setstflag(&(yyval).state, Xcw);
				i = getstval((yyval).state);
				if ((wprim->ptype != Xmove) && (wprim->ptype != Xspline) &&
				    (wprim->ptype != Xarrow) && (wprim->ptype != Xline)) {
				  switch ((yyvsp[0]).lexval) {
				    case Xljust:
				      if (i == Dotn) { setstval(&(yyval).state, Dotnw); }
				      else if (i == Dots) { setstval(&(yyval).state, Dotsw); }
				      else { setstval(&(yyval).state, Dotw); }
				      break;
				    case Xrjust:
				      if (i == Dotn) { setstval(&(yyval).state, Dotne); }
				      else if (i == Dots) { setstval(&(yyval).state, Dotse); }
				      else { setstval(&(yyval).state, Dote); }
				      break;
				    case Xbelow:
				      if (i == Dote) { setstval(&(yyval).state, Dotne); }
				      else if (i == Dotw) { setstval(&(yyval).state, Dotnw); }
				      else { setstval(&(yyval).state, Dotn); }
				      break;
				    case Xabove:
				      if (i == Dote) { setstval(&(yyval).state, Dotse); }
				      else if (i == Dotw) { setstval(&(yyval).state, Dotsw); }
				      else { setstval(&(yyval).state, Dots); }
				      break;
				    }
				  }
			    }
			  }
		    }
		  }
#line 3939 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2235 "dpic.y" /* yacc.c:1646  */
    {
#ifdef DDEBUG
          if (debuglevel > 0) {
      	    fprintf(log_, " object23: type=%d ", (yyvsp[-2]).lexval);
      	    switch ((yyvsp[-1]).lexval) {
      	    case Xshaded:
      	      fprintf(log_, "shaded \"str\"; hasshade=%s",
      		    hasshade((yyvsp[-2]).lexval, true) ? " TRUE" : "FALSE"); break;
      	    case Xoutlined:
      	      fprintf(log_, "outlined \"str\"; hasoutline=%s",
      		    hasoutline((yyvsp[-2]).lexval, true) ? " TRUE" : "FALSE"); break;
      	    case Xcolour:
      	      fprintf(log_, "colour \"str\"; hasoutline=%s; hashade=%s",
      		    hasoutline((yyvsp[-2]).lexval, true) ? " TRUE" : "FALSE",
      		    hasshade((yyvsp[-2]).lexval, false) ? " TRUE" : "FALSE"); break;
      	    default:
      	      fprintf(log_, "unknown "); break;
      	    }
      	    putc('\n', log_);
            }
#endif
		  if ((drawmode == Pict2e) || (drawmode == TeX) ||
		      (drawmode == tTeX) || (drawmode == xfig)) { markerror(858); }
		  else if (((yyvsp[0]).prim != NULL) && ((yyvsp[-2]).prim != NULL)) {
			wprim = (yyval).prim;
			switch ((yyvsp[-1]).lexval) {
			case Xshaded:
			  if (hasshade((yyvsp[-2]).lexval, true)) {
			    deletename(&wprim->shadedp);
			    wprim->shadedp = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
			    }
			  break;
			case Xoutlined:
			  if (hasoutline((yyvsp[-2]).lexval, true)) {
			    deletename(&wprim->outlinep);
			    wprim->outlinep = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
			    }
			  break;
			case Xcolour:
			  if (hasoutline((yyvsp[-2]).lexval, true)) {
			    deletename(&wprim->outlinep);
			    wprim->outlinep = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
				i = wprim->ptype;
			    if (((i != Xspline) && (i != Xarrow) && (i != Xline) &&
				   (i != Xarc)) & hasshade((yyvsp[-2]).lexval, false)) {
				  deletename(&wprim->shadedp);
				  copystr(&wprim->shadedp, wprim->outlinep);
			      }
			    }
			  break;
			  }
		    }
		    deletestringbox(&(yyvsp[0]).prim);
		  }
#line 4001 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2294 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			setstval(&(yyval).state, XEMPTY);
			setstflag(&(yyval).state, Xat);
		    }
		  }
#line 4013 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2303 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			setstval(&(yyval).state, (yyvsp[-2]).lexval);
			setstflag(&(yyval).state, Xat);
		    }
		  }
#line 4025 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2312 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
            i = (yyval).prim->ptype;
			if ((i != Xarc) && (i != Xellipse) && (i != Xcircle) &&
			  (i != Xblock) && (i != Xstring) && (i != Xbox)){markerror(858);}
			else {
			  (yyval).startchop = (yyvsp[-2]).xval;
			  (yyval).endchop = (yyvsp[-2]).yval;
			  setstval(&(yyval).state, Xfloat);
			  }
			setstflag(&(yyval).state, Xat);
		    }
		  }
#line 4044 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2328 "dpic.y" /* yacc.c:1646  */
    { primp = NULL;
	      prp = envblock->son;
	      while (prp != NULL) { i = prp->ptype;
		    if ( (i != XLaTeX) && (i != Xstring) && (i != Xblock)
			  && (i != Xlabel) ) { primp = prp; }
		    prp = prp->nextname; }
	      if (primp == NULL) { markerror(857); }
	      else {
		    while (primp->son != NULL) { primp = primp->son; }
		    (yyval).prim = primp;
		    if ((yyval).prim != NULL) {
			  appendthen(&(yyval).prim);
			  if ((yyval).prim->ptype != Xarc) { setstflag(&(yyval).state, XEMPTY); }
		      }
		    }
		  }
#line 4065 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2347 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, Xblock, envblock);
		  (yyval).prim->here_.xpos = 0.0;
		  (yyval).prim->here_.ypos = 0.0;
		  envblock = (yyval).prim;
		  tail = NULL;
		  (yyval).lexval = 0;
		  }
#line 4077 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2358 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-1]).lexval > Xprimitiv) && ((yyvsp[-1]).lexval < Xenvvar)) {
			newprim(&(yyval).prim, (yyvsp[-1]).lexval, envblock);
			eb = findenv(envblock);
			if ((yyvsp[-1]).lexval != Xmove) {
              if ((yyvsp[-1]).lexval == Xarc) { j = MPost; } else { j = drawmode; }
              switch (j) {
                case PGF:
                case PSTricks:
  			      (yyval).prim->lthick = -eb->envinx(Xlinethick); break;
                case MPost:
                case Pict2e:
                case PDF:
                case PS :
                case SVG:
                case PSfrag:
  			      (yyval).prim->lthick = eb->envinx(Xlinethick); break;
                default: break; }
              }
			if (((yyvsp[0]).lexval != XEMPTY) &&               /* check expr allowed */
			    ((yyvsp[-1]).lexval != Xmove) &&
			    ((yyvsp[-1]).lexval != Xspline) &&
			    ((yyvsp[-1]).lexval != Xarrow) &&
			    ((yyvsp[-1]).lexval != Xline)) { markerror(858); }
			wprim = (yyval).prim;
			switch ((yyvsp[-1]).lexval) {
			  case Xbox:
			    wprim->boxheight_ = eb->envinx(Xboxht);
			    wprim->boxwidth_ = eb->envinx(Xboxwid);
			    wprim->boxradius_ = eb->envinx(Xboxrad);
			    switch (wprim->direction) {
			      case Xup:
			        wprim->aat.ypos += wprim->boxheight_ * 0.5;
			        break;
			      case Xdown:
			        wprim->aat.ypos -= wprim->boxheight_ * 0.5;
			        break;
			      case Xleft:
			        wprim->aat.xpos -= wprim->boxwidth_ * 0.5;
			        break;
			      case Xright:
			        wprim->aat.xpos += wprim->boxwidth_ * 0.5;
			        break;
			      }
			    break;
			  case Xcircle:
			    wprim->circleradius_ = eb->envinx(Xcirclerad);
			    switch (wprim->direction) {
			      case Xup:
			        wprim->aat.ypos += wprim->circleradius_;
			        break;
			      case Xdown:
			        wprim->aat.ypos -= wprim->circleradius_;
			        break;
			      case Xleft:
			        wprim->aat.xpos -= wprim->circleradius_;
			        break;
			      case Xright:
			        wprim->aat.xpos += wprim->circleradius_;
			        break;
			      }
			    break;
			  case Xellipse:
			    wprim->ellipseheight_ = eb->envinx(Xellipseht);
			    wprim->ellipsewidth_ = eb->envinx(Xellipsewid);
			    switch (wprim->direction) {
			      case Xup:
			        wprim->aat.ypos += wprim->ellipseheight_ * 0.5;
			        break;
			      case Xdown:
			        wprim->aat.ypos -= wprim->ellipseheight_ * 0.5;
			        break;
			      case Xleft:
			        wprim->aat.xpos -= wprim->ellipsewidth_ * 0.5;
			        break;
			      case Xright:
			        wprim->aat.xpos += wprim->ellipsewidth_ * 0.5;
			        break;
			      }
			    break;
			  case Xarc:
			    wprim->aradius_ = eb->envinx(Xarcrad);
			    switch (wprim->direction) {
			      case Xup:
			        wprim->startangle_ = 0.0;
			        wprim->aat.xpos -= wprim->aradius_;
			        break;
			      case Xdown:
			        wprim->startangle_ = pi;
			        wprim->aat.xpos += wprim->aradius_;
			        break;
			      case Xleft:
			        wprim->startangle_ = 0.5 * pi;
			        wprim->aat.ypos -= wprim->aradius_;
			        break;
			      case Xright:
			        wprim->startangle_ = (-0.5) * pi;
			        wprim->aat.ypos += wprim->aradius_;
			        break;
			      }
			    wprim->lineheight_ = eb->envinx(Xarrowht);
			    wprim->linewidth_ = eb->envinx(Xarrowwid);
			    wprim->lineatype_ = pahnum(pahlex(0, XEMPTY),
			      Rnd(eb->envinx(Xarrowhead)));
			    wprim->arcangle_ = pi * 0.5;
			    break;
			  case Xline:
			  case Xarrow:
			  case Xspline:
			  case Xmove:
			    wprim->endpos_ = wprim->aat;
			    if ((wprim->ptype == Xspline) && ((yyvsp[0]).lexval != XEMPTY)) {
			      wprim->aradius_ = (yyvsp[0]).xval;
			      (yyvsp[0]).lexval = XEMPTY; }
			    if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; }
			    else if (wprim->ptype == Xmove) {
			      switch (wprim->direction) {
			        case Xup:
			        case Xdown:
				      r = eb->envinx(Xmoveht);
				      break;
			        case Xleft:
			        case Xright:
				      r = eb->envinx(Xmovewid);
				      break;
			        }
			      }
			    else {
			      switch (wprim->direction) {
			        case Xup:
			        case Xdown:
				      r = eb->envinx(Xlineht);
				      break;
			        case Xleft:
			        case Xright:
				      r = eb->envinx(Xlinewid);
				      break;
			        }
			      }
			    switch (wprim->direction) {
			      case Xup:
			        wprim->endpos_.ypos = wprim->aat.ypos + r;
			        break;
			      case Xdown:
			        wprim->endpos_.ypos = wprim->aat.ypos - r;
			        break;
			      case Xleft:
			        wprim->endpos_.xpos = wprim->aat.xpos - r;
			        break;
			      case Xright:
			        wprim->endpos_.xpos = wprim->aat.xpos + r;
			        break;
			      }
			    wprim->lineheight_ = eb->envinx(Xarrowht);
			    wprim->linewidth_ = eb->envinx(Xarrowwid);
			    if (wprim->ptype == Xarrow) {
			      wprim->lineatype_ = pahlex(0, Xrighthead); }
			    else { wprim->lineatype_ = pahlex(0, XEMPTY); }
			  wprim->lineatype_ = pahnum(wprim->lineatype_,
			    Rnd(eb->envinx(Xarrowhead)));
			  break;
			  }
		    }
#ifdef DDEBUG
			if (debuglevel > 0) { printobject((yyval).prim); }
#endif
		  }
#line 4248 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2526 "dpic.y" /* yacc.c:1646  */
    { if ((drawmode == PS) || (drawmode == PDF) || (drawmode == PSfrag)) {
			printstate = ((printstate >> 1) * 2) + 1; }
		  }
#line 4256 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2531 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			envblock = (yyvsp[-2]).prim->parent;
			tail = NULL;
			getnesw((yyvsp[-2]).prim->son);
			wprim = (yyvsp[-2]).prim;
			wprim->blockwidth_ = east - west;
			wprim->blockheight_ = north - south;
			wprim->aat.xpos = (east + west) * 0.5;
			wprim->aat.ypos = (north + south) * 0.5;
			dx = envblock->here_.xpos - wprim->aat.xpos;
			dy = envblock->here_.ypos - wprim->aat.ypos;
			switch (envblock->direction) {
			  case Xright: dx += wprim->blockwidth_ * 0.5; break;
			  case Xleft: dx -= wprim->blockwidth_ * 0.5; break;
			  case Xup: dy += wprim->blockheight_ * 0.5; break;
			  case Xdown: dy -= wprim->blockheight_ * 0.5; break;
			  }
			wprim->direction = envblock->direction;
#ifdef DDEBUG
			if ((debuglevel > 0) && ((yyvsp[-2]).prim->son != NULL)) {
			  printobject((yyvsp[-2]).prim->son);
			  if ((yyvsp[-2]).prim->son->nextname != NULL) {
                printobject((yyvsp[-2]).prim->son->nextname); }
			  }
#endif
			shift((yyvsp[-2]).prim, dx, dy);
#ifdef DDEBUG
			if (debuglevel > 0) {
			  wprim = (yyvsp[-2]).prim;
			  fprintf(log_, "Block3: (north,south),(west,east)");
			  wpair(&log_,wprim->aat.ypos + (wprim->blockheight_*0.5),
				  wprim->aat.ypos - (wprim->blockheight_ * 0.5));
			  wpair(&log_,wprim->aat.xpos -(wprim->blockwidth_*0.5),
				  wprim->aat.xpos + (wprim->blockwidth_ * 0.5));
			  fprintf(log_, " here=");
			  wpair(&log_,
				  wprim->here_.xpos, wprim->here_.ypos);
			  putc('\n', log_);
			  if ((yyvsp[-2]).prim->son != NULL) {
				printobject((yyvsp[-2]).prim->son);
				if ((yyvsp[-2]).prim->son->nextname != NULL) {
				  printobject((yyval).prim->son->nextname); }
			    }
			  (yyval).prim = (yyvsp[-2]).prim;
			  snaptree((yyval).prim, 0);
			  putc('\n', log_);
			  }
#endif
		    }
		  }
#line 4311 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2583 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, Xblock, envblock);
		  (yyval).prim->here_.xpos = 0.0;
		  (yyval).prim->here_.ypos = 0.0;
		  (yyval).lexval = 0;
		  }
#line 4321 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2591 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 4327 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2597 "dpic.y" /* yacc.c:1646  */
    { if (envblock->blockparms.env != NULL) {
			eb = findenv(envblock->parent);
			if (envblock->envinx(Xlinethick) != eb->envinx(Xlinethick)) {
		      newprim(&prp, XLaTeX, envblock);
			  prp->lthick = eb->envinx(Xlinethick);
              queueprim( prp, envblock );
              }
		    }
		  }
#line 4341 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2611 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[0]).lexval != XEMPTY) {
			  attribp = &(yyvsp[-1]);
			  addsuffix(chbuf, &attribp->chbufx, &attribp->toklen,
			    (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
			if ((yyval).internal == NULL) { prp = (yyval).prim; }
			else { prp = (yyval).internal; }
			(yyval).internal = findplace(prp->son, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
			if ((yyval).internal == NULL) {
			  marknotfound(855, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
			  deletetree(&(yyval).prim); }
		    }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4360 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2627 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[-3]).internal == NULL) { prp = (yyvsp[-3]).prim; }
			else { prp = (yyvsp[-3]).internal; }
			(yyval).internal = nthprimobj(prp->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
			if ((yyval).internal == NULL) { markerror(857); deletetree(&(yyval).prim); }
		    }
		  }
#line 4372 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2637 "dpic.y" /* yacc.c:1646  */
    { (yyval).yval = (yyvsp[0]).xval;
#ifdef DDEBUG
			if (debuglevel>1) prattribute("pair1",&(yyval));
#endif
			}
#line 4382 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2644 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) {
			(yyval).xval += (yyvsp[0]).xval;
			(yyval).yval += (yyvsp[0]).yval; }
		  }
#line 4391 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2651 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).xval <= 0.0) { markerror(856); }
		  else { (yyval).toklen = Rnd((yyvsp[-1]).xval); }
		  }
#line 4399 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2656 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval <= 0.0) { markerror(856); }
		  else { (yyval).toklen = -Rnd((yyvsp[-2]).xval); }
		  }
#line 4407 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 2661 "dpic.y" /* yacc.c:1646  */
    { (yyval).toklen = 0; }
#line 4413 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2671 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = Xblock; }
#line 4419 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2675 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 0.0;
		  (yyval).yval = 0.0;
		  (yyval).lexval = XEMPTY;
		  }
#line 4428 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2681 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval += (yyvsp[0]).xval;
		  (yyval).yval += (yyvsp[0]).yval;
		  (yyval).lexval = Xfloat;
		  }
#line 4437 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2687 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval -= (yyvsp[0]).xval;
		  (yyval).yval -= (yyvsp[0]).yval;
		  (yyval).lexval = Xfloat;
		  }
#line 4446 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2694 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4452 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 2697 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-3]).xval;
		  (yyval).yval = (yyvsp[-1]).yval;
		  }
#line 4460 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2704 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval *= (yyvsp[0]).xval;
		  (yyval).yval *= (yyvsp[0]).xval;
		  }
#line 4468 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2709 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { markerror(852); }
		  else {
			(yyval).xval /= (yyvsp[0]).xval;
			(yyval).yval /= (yyvsp[0]).xval;
		    }
		  }
#line 4479 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2718 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, XEMPTY, &(yyval).xval, &(yyval).yval); }
#line 4485 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2721 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[-1]).prim, (yyvsp[0]).lexval, &(yyval).xval, &(yyval).yval); }
#line 4491 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2724 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, (yyvsp[-1]).lexval, &(yyvsp[0]).xval, &(yyvsp[0]).yval);
 		  (yyval) = (yyvsp[0]); }
#line 4498 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2728 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, (yyvsp[-2]).lexval, &(yyvsp[0]).xval, &(yyvsp[0]).yval);
 		  (yyval) = (yyvsp[0]); }
#line 4505 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 2732 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = envblock->here_.xpos;
		  (yyval).yval = envblock->here_.ypos;
		  }
#line 4513 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2740 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { (yyval).xval = 1.0; }
    	  else { (yyval).xval = 0.0; }
		  }
#line 4521 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2745 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval == 0.0) && ((yyvsp[0]).xval < 0.0)) { markerror(852); }
		  else {
			j = Rnd((yyvsp[0]).xval);
			r = j;
			if (r == (yyvsp[0]).xval) { (yyval).xval = intpow((yyvsp[-2]).xval, j); }
			else if ((yyvsp[-2]).xval < 0.0) { markerror(863); (yyval).xval = 0.0; }
			else if ((yyvsp[-2]).xval != 0.0) { (yyval).xval = exp((yyvsp[0]).xval * log((yyvsp[-2]).xval));}
			}
    	  }
#line 4535 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2757 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-1]).chbufx, &(yyvsp[-1]).toklen,
                (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
		  prp = NULL;
		  primp = envblock;
		  while (primp != prp) {
		    prp = findplace(primp->son, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
			if (prp != NULL) { primp = prp; }
			else { primp = primp->parent; }
		    }
		  if (prp == NULL) {
			marknotfound(854, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen); }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  (yyval).prim = prp;
		  }
#line 4554 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2773 "dpic.y" /* yacc.c:1646  */
    { (yyval).prim = nthprimobj(envblock->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
		  if ((yyval).prim == NULL) { markerror(857); }
#ifdef DDEBUG
		  if (debuglevel > 0) {
            fprintf(log_, "\n placename2 %dth location:",(yyvsp[-1]).toklen);
	        wpair(&log_, (yyval).prim->aat.xpos, (yyval).prim->aat.ypos);
            putc('\n', log_); fflush(log_);
            }
#endif
		  }
#line 4569 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2785 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-1]).chbufx,
              &(yyvsp[-1]).toklen, (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
			primp = findplace((yyval).prim->son, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
			if (primp == NULL) { marknotfound(855, chbuf, (yyvsp[-1]).chbufx,(yyvsp[-1]).toklen);}
			(yyval).prim = primp;
		    }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4583 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 2796 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).prim = nthprimobj((yyvsp[-3]).prim->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
			if ((yyval).prim == NULL) { markerror(857); }
		    }
		  }
#line 4593 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 2806 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4599 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 2809 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4605 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 2815 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval == 0.0) || ((yyvsp[0]).xval == 0.0)) { (yyval).xval = 0.0; }
		  else { (yyval).xval = 1.0; }
		  }
#line 4613 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 2821 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval == Xstring) {
			markerror(869);
			(yyval).lexval = Xfloat;
			deletestringbox(&(yyvsp[0]).prim);
		    }
		  }
#line 4624 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 2829 "dpic.y" /* yacc.c:1646  */
    { i = cmpstring((yyvsp[-2]).prim, (yyvsp[0]).prim);
		  if (i < 0) { (yyval).xval = 1.0; }
		  else { (yyval).xval = 0.0; }
		  (yyval).lexval = Xfloat;
		  deletestringbox(&(yyvsp[0]).prim);
		  deletestringbox(&(yyvsp[-2]).prim);
		  }
#line 4636 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 2838 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval < (yyvsp[0]).xval) { (yyval).xval = 1.0; }
		  else { (yyval).xval = 0.0; }
		  }
#line 4644 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2848 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval == Xstring) {
			markerror(869);
			bswitch = false;
			deletestringbox(&(yyvsp[-2]).prim);
		    (yyval).lexval = XEMPTY;
		    }
		  else {
#ifdef DDEBUG
			if (debuglevel > 0) { fprintf(log_," compare %g %d %g\n",
              (yyvsp[-2]).xval,(yyvsp[-1]).lexval-Xcompare,(yyvsp[0]).xval); }
#endif
			switch ((yyvsp[-1]).lexval - Xcompare) {
			  case 0: bswitch = ((yyvsp[-2]).xval < (yyvsp[0]).xval); break;
			  case 1: bswitch = ((yyvsp[-2]).xval == (yyvsp[0]).xval); break;
			  case 2: bswitch = ((yyvsp[-2]).xval != (yyvsp[0]).xval); break;
			  case 3: bswitch = ((yyvsp[-2]).xval >= (yyvsp[0]).xval); break;
			  case 4: bswitch = ((yyvsp[-2]).xval <= (yyvsp[0]).xval); break;
			  case 5: bswitch = ((yyvsp[-2]).xval > (yyvsp[0]).xval); break;
			  default: bswitch = false; break;
			  }
		    }
		  if (bswitch) { (yyval).xval = 1.0; } else { (yyval).xval = 0.0; }
		  }
#line 4672 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2873 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != Xstring) { markerror(869); bswitch = false; }
		  else {
			i = cmpstring((yyvsp[-2]).prim, (yyvsp[0]).prim);
			switch ((yyvsp[-1]).lexval - Xcompare) {
			  case 0: bswitch = (i < 0); break;
			  case 1: bswitch = (i == 0); break;
			  case 2: bswitch = (i != 0); break;
			  case 3: bswitch = (i >= 0); break;
			  case 4: bswitch = (i <= 0); break;
			  case 5: bswitch = (i > 0); break;
			  default: bswitch = false; break;
			  }
			deletestringbox(&(yyval).prim);
		    }
		  if (bswitch) { (yyval).xval = 1.0; } else { (yyval).xval = 0.0; }
		  (yyval).lexval = Xfloat;
		  deletestringbox(&(yyvsp[0]).prim);
		  }
#line 4695 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2894 "dpic.y" /* yacc.c:1646  */
    { if (envblock != NULL) {
			eb = findenv(envblock);
			(yyval).xval = eb->envinx((yyvsp[0]).lexval);
		    }
		  }
#line 4705 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 2901 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf,
		    &(yyvsp[-1]).chbufx, &(yyvsp[-1]).toklen, (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
    	  namptr = glfindname(envblock,chbuf,(yyvsp[-1]).chbufx,(yyvsp[-1]).toklen, &lastvar, &k);
    	  if (namptr == NULL) { (yyval).xval = 0.0; }
    	  else { (yyval).xval = namptr->val; }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4717 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 2912 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4723 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2917 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).yval; }
#line 4729 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2920 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) { switch ((yyvsp[0]).lexval) {
			case Xheight:
			  (yyval).xval = pheight((yyval).prim);
			  break;
			case Xwidth:
			  (yyval).xval = pwidth((yyval).prim);
			  break;
			case Xradius:
			  wprim = (yyval).prim;
			  if (wprim->ptype == Xcircle) {(yyval).xval = wprim->circleradius_; }
			  else if (wprim->ptype == Xarc) {(yyval).xval = wprim->aradius_; }
			  else if (wprim->ptype == Xbox) {(yyval).xval = wprim->boxradius_; }
			  else { (yyval).xval = 0.0; markerror(858); }
			  break;
			case Xdiameter:
			  wprim = (yyvsp[-1]).prim;
			  if (wprim->ptype == Xcircle) {(yyval).xval = wprim->circleradius_*2; }
			  else if (wprim->ptype == Xarc) {(yyval).xval = wprim->aradius_*2; }
			  else { (yyval).xval = 0.0; markerror(858); }
			  break;
			case Xthickness:
			  wprim = (yyvsp[-1]).prim;
              switch (wprim->ptype) {
                case Xarc:
                case Xspline:
                case Xarrow:
                case Xline:
                case Xcircle:
                case Xellipse:
                case Xbox:
                  if (ismdistmax(wprim->lthick)) {
                    (yyval).xval = venv(wprim,Xlinethick); }
                  else { (yyval).xval = fabs(wprim->lthick); }
                  break;
                default:
                  (yyval).xval = 0.0; markerror(858);
                  break; }
			  break;
			case Xlength:
			  wprim = (yyvsp[-1]).prim; j = wprim->ptype;
              switch (j) {
  	            case Xspline:
                case Xmove:
                case Xarrow:
                case Xline:
  			      primp = (yyvsp[-1]).prim;
  			      while (primp->son != NULL) { primp = primp->son; }
  			      r = fabs(primp->endpos_.xpos - wprim->aat.xpos);
  			      s = fabs(primp->endpos_.ypos - wprim->aat.ypos);
  			      if (r == 0.0) { (yyval).xval = s; }
  			      else if (s == 0.0) { (yyval).xval = r; }
  			      else { (yyval).xval = sqrt((r * r) + (s * s)); }
                  break;
  			    default:
                  (yyval).xval = 0.0; markerror(858);
  			      break; }
			default:
              break; }
		    }
          }
#line 4794 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2982 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = ((double)random()) / randmax; }
#line 4800 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2985 "dpic.y" /* yacc.c:1646  */
    { srandom(Rnd((yyvsp[-1]).xval));
		  (yyval).xval = ((double)random()) / randmax;
		  }
#line 4808 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2990 "dpic.y" /* yacc.c:1646  */
    { switch ((yyval).lexval) {
		    case Xabs: (yyval).xval = fabs((yyvsp[-1]).xval);
		      break;
		    case Xacos:
		      t = (yyvsp[-1]).xval;
		      if (fabs(t) > 1.0) { markerror(868); }
		      else { (yyval).xval = datan(sqrt(1 - (t * t)), t); }
		      break;
		    case Xasin:
		      t = (yyvsp[-1]).xval;
		      if (fabs(t) > 1.0) { markerror(868); }
		      else { (yyval).xval = datan(t, sqrt(1 - (t * t))); }
		      break;
		    case Xcos: (yyval).xval = cos((yyvsp[-1]).xval);
		      break;
		    case Xexp: (yyval).xval = exp(log(10.0) * (yyvsp[-1]).xval);
		      break;
		    case Xexpe: (yyval).xval = exp((yyvsp[-1]).xval);
		      break;
		    case Xint: (yyval).xval = (long)(yyvsp[-1]).xval;
		      break;
		    case Xlog:
		      if ((yyvsp[-1]).xval <= 0.0) { markerror(867); }
		      else { (yyval).xval = log((yyvsp[-1]).xval) / log(10.0); }
		      break;
		    case Xloge:
		      if ((yyvsp[-1]).xval <= 0.0) { markerror(867); }
		      else { (yyval).xval = log((yyvsp[-1]).xval); }
		      break;
		    case Xsign:
		      if ((yyvsp[-1]).xval >= 0.0) { (yyval).xval = 1.0; }
		      else { (yyval).xval = -1.0; }
		      break;
		    case Xsin: (yyval).xval = sin((yyvsp[-1]).xval);
		      break;
		    case Xsqrt:
		      if ((yyvsp[-1]).xval < 0.0) { markerror(867); }
		      else { (yyval).xval = sqrt((yyvsp[-1]).xval); }
		      break;
		    case Xtan:
		      t = cos((yyvsp[-1]).xval);
		      if (t == 0.0) { markerror(868); (yyval).xval = distmax; }
		      else { (yyval).xval = sin((yyvsp[-1]).xval) / t; }
		      break;
		    case Xfloor: (yyval).xval = Floor((yyvsp[-1]).xval);
		      break;
		    }
		  }
#line 4861 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 3040 "dpic.y" /* yacc.c:1646  */
    { switch ((yyvsp[-5]).lexval) {
		    case Xatan2: (yyval).xval = datan((yyvsp[-3]).xval, (yyvsp[-1]).xval);
		      break;
		    case Xmax: (yyval).xval = Max((yyvsp[-3]).xval, (yyvsp[-1]).xval);
		      break;
		    case Xmin: (yyval).xval = Min((yyvsp[-3]).xval, (yyvsp[-1]).xval);
		      break;
		    case Xpmod:
		      t = (yyvsp[-3]).xval;
		      s = (yyvsp[-1]).xval;
		      if (s == 0) { markerror(871); }
		      else {
			    (yyval).xval = t - (s * Floor(t / s));
			    if ((yyval).xval < 0) { (yyval).xval += fabs(s); }
		        }
		      break;
		    }
		  }
#line 4884 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 3060 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4890 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 3063 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4896 "dpic.tab.c" /* yacc.c:1646  */
    break;


#line 4900 "dpic.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3066 "dpic.y" /* yacc.c:1906  */
 /* start of programs */

void
yyerror(char const *s)
{
  boolean cap;
  markerror(799);
  cap = (*s=='s');
  if (cap) s++;                      /* Capitalize "syntax" */
#ifdef DDEBUG
  if (debuglevel > 0) { if (cap) putc('S',log_); fprintf(log_, "%s\n",s); }
#endif
  if (cap) putc('S',errout);
  fprintf(errout, "%s\n",s);
  }

							/* Get and initialize a buffer from the
							   old-buffer stack or make a new one */
void
newbuf(fbuffer **buf)
{
  fbuffer *nwbuf;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, " newbuf"); }
#endif
  if (freeinbuf == NULL) {
    *buf = malloc(sizeof(fbuffer)); if (*buf==NULL){ fatal(9); }
    (*buf)->carray = malloc(sizeof(chbufarray));
    if ((*buf)->carray==NULL){ fatal(9); }
    }
  else {
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, " f"); }
#endif
    *buf = freeinbuf;
    freeinbuf = freeinbuf->nextb;
    }
  nwbuf = *buf;
  nwbuf->savedlen = 0;
  nwbuf->carray[0] = ' ';
  nwbuf->readx = 1;
  nwbuf->attrib = 0;
  nwbuf->higherb = NULL;
  nwbuf->prevb = NULL;
  nwbuf->nextb = NULL;
#ifdef DDEBUG
  if (debuglevel > 0) { logaddr(*buf); putc('\n', log_); }
#endif
}


							/* Clearing memory at end of diagram */
void
deletefreeargs(arg **a)
{
  arg *na;
  while ((*a) != NULL) {
    na = (*a)->nexta;
    disposebufs(&(*a)->argbody);
    Free(*a);
    *a = na; }
}


							/* Clearing memory at end of diagram */
void
deletefreeinbufs(fbuffer **p)
{
  fbuffer *q;
  while ((*p) != NULL) {
    q = (*p)->nextb;
    Free((*p)->carray);
    Free(*p);
    *p = q; }
}


							/* performed for each input diagram: */
void
inittwo(void)
{
  freeinbuf = NULL;
  freeseg = NULL;
  freex = 2;
  freearg = NULL;
  lastfillval = mdistmax;
  gslinethick = mdistmax;
  newprim(&envblock, Xblock, NULL);
  globalenv = envblock;
  tail = NULL;
  resetenv(0, envblock);
#ifdef DDEBUG
  if (debuglevel > 0) { printobject(envblock); }
#endif
  pyylval = &yylval;
}

void
preproduce(int p)
{
  switch (p) {
  case -2:
    inittwo();
    break;
  case -1:
    if (envblock != NULL) { envblock->direction = Xright; }
    inlogic = false;
    inbuf = NULL;
    break;
  }
}

							/* Integer power of x */
double
intpow(double x, int k)
{ /* 0^(-k) does not occur */
  /* 0^0 returns 1.0 */
  if (k == 0) { x = 1.0; return x; }
  if ((x == 0.0) || (k == 1)) { return x; }
  if (k < 0) { x = intpow(1.0 / x, -k); return x; }
							/* common enough to test for it */
  if (k == 2) { x *= x; return x; }
  if (k & 1) { x *= intpow(x, k - 1); }
  else { x = intpow(x, k >> 1); x *= x; }
  return x;
}

void
wrmacro(FILE **iou, arg *cm)
{
  fbuffer *body;
  int j, namlen;
  if (cm == NULL) { }
  else if (cm->argbody == NULL) { }
  else if (cm->argbody->carray != NULL) {
    body = cm->argbody;
    fprintf(*iou, "in macro \"");
    namlen = -(body->attrib);
    for (j = 1; j <= namlen; j++) { wchar(iou, body->carray[j]); }
    putc('"', *iou);
    }
  }
							/* Write error message with symbol found
							   and symbol expected if possible */
void
markerror(int emi) {
  int inx, i, j, k;
  fbuffer *thisbuf, *lastbuf;
  boolean scanning;
							/* Do not count warnings */
  if (emi < 900) { errcount++; }
  if (errcount > MAXERRCOUNT) { fatal(3); }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "*** Markerror");
    wrbuf(inbuf,3);
    fprintf(log_, " emi=%d, lexsymb=%d:\n", emi, lexsymb);
    wrmacro( &log_, currentmacro );
    putc('\n', log_);
    }
#endif
  fprintf(errout, "\n*** dpic ");
  if (emi < 900) { fprintf(errout, "ERROR: "); }
  else { fprintf(errout, "WARNING: "); }
  wrmacro(&errout, currentmacro);
  if (currentmacro != NULL) { fprintf(errout, ", "); }
  if (inbufdepth == 0) { P__argv((char *)infname, sizeof(mstring), argct); }
  j = 0; k = FILENAMELEN;
  while (j < k) {
    if ((infname[j]==' ') || (infname[j]=='\0')) { k = j; } else { j++; } }
  if (k == 0) { fprintf(errout, "\"stdin\""); }
  else {
    fprintf(errout, "file \"");
    for (j = 0; j < k; j++) { wchar(&errout, infname[j]); }
    putc('"', errout); }
  fprintf(errout, " line %d:\n", lineno[inbufdepth]);

  if (emi < 903) {
                            /* Skip back over white space */
    thisbuf = inbuf;
    inx = inbuf->readx - 1;
    scanning = true;
    while (scanning) {
      if (inx < 1) {
	    if (thisbuf->prevb == NULL) { scanning = false; }
        else {
	      thisbuf = thisbuf->prevb;
	      if (thisbuf->savedlen < CHBUFSIZ) { inx = thisbuf->savedlen; }
	      else { inx = CHBUFSIZ; } }
        }
      else if (thisbuf->carray[inx] == etxch) { inx++; scanning = false; }
      else if (thisbuf->carray[inx] <= ' ') { inx--; }
      else { scanning = false; } }
    lastbuf = thisbuf;
#ifdef DDEBUG
    if (debuglevel > 0) {
      fprintf(log_, "Skip back white to char=");
      wchar(&log_,thisbuf->carray[inx]);
      fprintf(log_, ", inx=%d\n", inx); }
#endif
                            /* Skip back over code or tabs */
    scanning = true;
    j = inx - 1;
    while (scanning) {
	  if (j < 1) {
	    if (thisbuf->prevb == NULL) { scanning = false; }
        else {
	      thisbuf = thisbuf->prevb;
	      if (thisbuf->savedlen < CHBUFSIZ) { j = thisbuf->savedlen; }
	      else { j = CHBUFSIZ; } }
          }
      else if (thisbuf->carray[j]==etxch) { j++; scanning = false; }
      else if (isprint_(thisbuf->carray[j])||(thisbuf->carray[j]==tabch)){j--;}
	  else { j++; scanning = false; }
      }
    if (j < 1) { j = 1; }
#ifdef DDEBUG
    if (debuglevel > 0) {
      fprintf(log_, "Skip back printable to char=");
      wchar(&log_,thisbuf->carray[j]);
      fprintf(log_, ", j=%d\n", j);
	  wrbuf(thisbuf, 3); }
#endif
                          /* Write out the line or lines */
    while (thisbuf != NULL) {
	  if (thisbuf == lastbuf) { k = inx; } else { k = thisbuf->savedlen; }
	  for (i = j; i <= k; i++) { wchar(&errout, thisbuf->carray[i]); }
	  if (thisbuf == lastbuf) { thisbuf = NULL; }
	  else { thisbuf = thisbuf->nextb; j = 1; }
      }
    putc('\n', errout);
    }

  switch (emi) {
           
  case 799:                 /* syntax error */
    break;
							/* lexical error messages */
  case 800:
    fprintf(errout, "Invalid character, ignored\n");
    break;

  case 802:
    fprintf(errout, "Invalid exponent character after e in a number\n");
    break;

  case 804:
  case 806:
    fprintf(errout, "End of file while reading ");
    if (emi == 806) { fprintf(errout, "string in "); }
    switch (currprod) {
      case 1 /* elsehead1 */:
        fprintf(errout, "else");
        break;
      case 2 /* ifhead1 */:
        fprintf(errout, "if");
        break;
      case 3 /* forhead1 */:
        fprintf(errout, "for");
        break;
      case 4 /* defhead1 */:
      case 5 /* defhead2 */:
        fprintf(errout, "define");
        break;
      }
    fprintf(errout, " {...} contents\n");
    break;
  case 805:
    fprintf(errout, "End of file while evaluating macro argument\n");
    break;
  case 807:
    fprintf(errout, "Bad macro argument number\n");
    break;
							/* context error messages */
  case 851:
    fprintf(errout, "Variable not found\n");
    break;
  case 852:
    fprintf(errout, "Zero divisor not allowed\n");
    break;
  case 853:
    fprintf(errout, "Only one copy file may be open at any time\n");
    break;
  case 854:
    fprintf(errout, "Place name not found\n");
    break;
  case 855:
    fprintf(errout, "Internal name not found\n");
    break;
  case 856:
    fprintf(errout, "Invalid non-positive value for object count\n");
    break;
  case 857:
    fprintf(errout, "Enumerated or previous object not found\n");
    break;
  case 858:
    fprintf(errout, "This usage is inapplicable in this context\n");
    break;
  case 859:
    fprintf(errout, "File not readable\n");
    break;
  case 860:
    fprintf(errout, "Infinite looping not allowed\n");
    break;
  case 861:
    fprintf(errout, "Missing or blank string\n");
    break;
  case 862:
    fprintf(errout, "For ... by *() limits must have the same sign\n");
    break;
  case 863:
    fprintf(errout, "Non-integer power of negative value\n");
    break;
  case 864:
    fprintf(errout, "Incorrect number of sprintf arguments\n");
    break;
  case 865:
    fprintf(errout, "Bad sprintf format: only e, f, g allowed\n");
    break;
  case 866:
    fprintf(errout, "String exceeds max length of 4095 characters\n");
    break;
  case 867:
    fprintf(errout, "Invalid log or sqrt argument\n");
    break;
  case 868:
    fprintf(errout, "Function argument out of range\n");
    break;
  case 869:
    fprintf(errout, "Improper use of logical operator\n");
    break;
  case 870:
    fprintf(errout, "Zero value of scale not allowed\n");
    break;
  case 871:
    fprintf(errout, "Zero second argument of pmod not allowed\n");
    break;
  case 872:
    fprintf(errout, "Buffer overflow while defining macro argument\n");
    break;
  case 873:
    fprintf(errout, "Format width too large\n");
    break;
  case 874:
    fprintf(errout, "System routine snprintf error: bad formatted value\n");
    break;
  case 875:
    fprintf(errout, "Subscript out of range\n");
    break;
  case 876:
    fprintf(errout, "Failed to open sprintf output file\n");
    break;
							/* warning messages */
  case 901:
    fprintf(errout, "Safe mode: sh, copy, and print to file disallowed\n");
    break;
  case 902:
    fprintf(errout, "Output number out of range: 10e32 used\n");
    break;
  case 903:
    fprintf(errout, "Picture size adjusted to maxpswid value\n");
    break;
  case 904:
    fprintf(errout, "Picture size adjusted to maxpsht value\n");
    break;
  default:
    fprintf(errout, "Unknown error\n");
    break;
  }

  consoleflush();
}  /* markerror */


							/* Flag an object not found and complain to
							   stderr */
void
marknotfound(int eno, Char *chb, chbufinx inx, chbufinx len)
{
  int i;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "Search failure %d", eno);
    if (chb != NULL) {
	  fprintf(log_, " for \"");
	  for (i = inx; i < (inx + len); i++) { wchar(&log_,chb[i]); }
	  putc('"', log_); }
    putc('\n', log_);
    }
#endif
  markerror(eno);
  fprintf(errout, "Search failure");
  if (chb != NULL) {
    fprintf(errout, " for \"");
    for (i = inx; i < (inx + len); i++) { wchar(&errout,chb[i]); }
    putc('"', errout);
    }
  putc('\n', errout);
}

							/* Hash of variable name:
   							   (ord(chr(1))+ord(chr(n-1))) mod (HASHLIM+1) */
int
varhash(Char *chb, chbufinx chbufx, chbufinx toklen)
{
  int idx;
  if (chb == NULL) { idx = 0; }
  else {
    idx = chb[chbufx];
    if (toklen > 2) { idx += chb[chbufx + toklen - 2]; }
    }
  return ((idx % (HASHLIM+1)));
}

							/* Binary search for name in chain of stored
							   names */
nametype *(
findname(primitive *eb, Char *chb, chbufinx chbufx, chbufinx toklen,
	 nametype **last, int *tstval))
{
  nametype *leftptr;
  nametype *rightptr = NULL;
  int left = 0, right = 0;
  int midpt, i, hashedx;
  nametype *testname;
  hashedx = varhash(chb, chbufx, toklen);
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, " findname|");
    for (i = chbufx; i < (chbufx + toklen); i++) { wchar(&log_,chb[i]); }
    fprintf(log_, "|:");
    if (eb == NULL) { fprintf(log_, " eb=nil"); }
    else {
      fprintf(log_, " nvars[%d]=%d", hashedx, eb->blockparms.nvars[hashedx]); }
    if (debuglevel > 1) { putc('\n', log_); }
    }
#endif
  *tstval = 1;
  *last = NULL;
  if (eb == NULL) { leftptr = NULL; }
  else {
    leftptr = eb->blockparms.vars[hashedx];
    *last = leftptr; }
							/* Check the first (highest) name */
  if (leftptr != NULL) {
    *tstval = eqstring(chb, chbufx, toklen, leftptr->segmnt, leftptr->seginx,
		    leftptr->len);
    if ((*tstval) < 0) {
	  left = 2;
	  leftptr = leftptr->nextname;
	  right = eb->blockparms.nvars[hashedx] + 1; }
    else { rightptr = leftptr; }
    }
  while (leftptr != rightptr) {
    midpt = (left + right) >> 1;
    *last = leftptr;
    for (i = left + 1; i <= midpt; i++) { *last = (*last)->nextname; }
    testname = *last;
    *tstval = eqstring(chb, chbufx, toklen,
      testname->segmnt, testname->seginx,testname->len);
    if ((*tstval) < 0) {
	  left = midpt + 1;
	  leftptr = (*last)->nextname;
	  continue; }
    if ((*tstval) == 0) {
	  leftptr = *last;
	  rightptr = leftptr; }
    else {
	  right = midpt;
	  rightptr = *last; }
    }
#ifdef DDEBUG
  if (debuglevel > 0) {
    if ((*tstval) == 0) { fprintf(log_," return leftptr;\n"); }
    else { fprintf(log_," return NULL;\n"); } }
#endif
  if ((*tstval) == 0) { return leftptr; }
  else { return NULL; }
}

							/* A minimal set of debug routines has been kept: */
#ifdef DDEBUG
void
logchar(Char c)
{
  fprintf(log_, "ch(%d)=\"", c);
  wchar(&log_, c);
  putc('"', log_);
}


void
wlogfl(char *nm, double v, int cr)
{
  fprintf(log_, " %s=", nm);
  if (MaxReal - fabs(v) < MaxReal * 1e-6) {
    if (v < 0) { fprintf(log_, "-MaxReal"); }
    else { fprintf(log_, "MaxReal"); }
    }
  else { wfloat(&log_, v); }
  if (cr != 0) { putc('\n', log_); }
}

void
logaddr(fbuffer *b)
{
  putc('[', log_);
  if (b != NULL) { fprintf(log_, "%d", odp(b)); }
  else { fprintf(log_, "nil"); }
  fprintf(log_, "]\n");
}

void
wrbufaddr(fbuffer *q, int job)
{
  fbuffer *r;
  boolean difa = false;
  if (q == NULL) { fprintf(log_, "[nil]"); return; }
  r = q;
  while (r->nextb != NULL) { r = r->nextb; }
  while (r->prevb != NULL) {
    difa = (difa || (r->attrib != r->prevb->attrib));
    r = r->prevb; }
  if (job <= 0) {
    r = q;
    while (r->prevb != NULL) { r = r->prevb; }
    while (r != q) {
	  fprintf(log_, "(%d", odp(r));
	  if (difa) { fprintf(log_, ":%d", r->attrib); }
	  r = r->nextb; }
    }
  fprintf(log_, "[%d:%d]", odp(q), q->attrib);
  if (job < 0) { return; }
  while (q->nextb != NULL) {
    q = q->nextb;
    fprintf(log_, "%d", odp(q));
    if (difa) { fprintf(log_, ":%d", q->attrib); }
    putc(')', log_);
    }
}

void
wrbuf(fbuffer *p, int job)
{
  int i, j, k, m;
  if (p == NULL) { fprintf(log_, " nil buffer "); return; }
  while (p != NULL) {
    if (job > 2) { fprintf(log_, " buf"); wrbufaddr(p, 0); }
    if (job > 1) {
	  fprintf(log_, " readx=%d savedlen=%d attrib=%d",
		  p->readx, p->savedlen, p->attrib); }
    j = p->readx;
    if (job > 0) { fprintf(log_, "(j=%d,savedlen=%d)", j, p->savedlen); }
    fprintf(log_, "\n|");
    if (p->carray == NULL) { fprintf(log_, "nil"); }
    else {
	  i = j;
	  while (i <= p->savedlen) {
	    if (p->carray[i] != 0) { wchar(&log_, p->carray[i]); }
	    else {
		  m = i;
		  k = p->savedlen + 1;
		  while (i < k) { if (p->carray[i] == 0) { i++; } else { k = i; } }
		  fprintf(log_, "(%dx", i - m);
		  wchar(&log_, '\0');
          fprintf(log_, ")");
		  i--; }
	    i++;
	    }
      }
    fprintf(log_, "|\n");
    p = p->nextb;
    }
  }


void
prtstval(int st)
{
  fprintf(log_, "state=%d", st);
  if ((st & 3) != 0) {
    switch (st & 3) {
      case 1: fprintf(log_, ",Xto"); break;
      case 2: fprintf(log_, ",Xfrom"); break;
      case 3: fprintf(log_, ",Xat"); break;
      }
    }
  if ((st >> 2) & 1) { fprintf(log_, ",Xchop"); }
  if ((st >> 3) & 1) { fprintf(log_, ",Xdirecton"); }
}


void
snapname(Char *chbu, chbufinx inx, chbufinx namelen)
{
  int j;
  fprintf(log_, " (%d inx=%d len=%d)|", ordp(chbu), inx, namelen);
  if (chbu == NULL) { fprintf(log_, "**nil string pointer**"); }
  else { for (j = inx; j < (inx + namelen); j++) {
    wchar(&log_,chbu[j]); } }
  putc('|', log_);
  fflush(log_);
}


void
snaptype(FILE **iou, int p)
{
  switch (p) {
    case Xbox: fprintf(*iou, "<box>"); break;
    case Xblock: fprintf(*iou, "<[]>"); break;
    case Xellipse: fprintf(*iou, "<ellipse>"); break;
    case Xcircle: fprintf(*iou, "<circle>"); break;
    case Xline: fprintf(*iou, "<line>"); break;
    case Xarrow: fprintf(*iou, "<arrow>"); break;
    case Xmove: fprintf(*iou, "<move>"); break;
    case Xspline: fprintf(*iou, "<spline>"); break;
    case Xarc: fprintf(*iou, "<arc>"); break;
    case Xstring: fprintf(*iou, "<<string>>"); break;
    case XLaTeX: fprintf(*iou, "<<LaTeX>>"); break;
    case Xlabel: fprintf(*iou, "<<Label>>"); break;
    default: fprintf(*iou, "Unknown type %3d", p); break;
    }
  fflush(*iou);
}


void
snaptree(primitive *pr, int indent)
{
  int i, j = /* 6 */ 0;
  while ((pr != NULL) && (indent <= 240)) {
    snaptype(&log_, pr->ptype);
	/* fprintf(log_,"[%d]",odp(pr)); */
    switch (pr->ptype) {
      case Xblock: i = 4; break;
      case Xbox:
      case Xarc: i = 5; break;
      case Xline:
      case Xmove: i = 6; break;
      case Xarrow: i = 7; break;
      case Xcircle:
      case Xspline: i = 8; break;
      case Xellipse:
      case XLaTeX: i = 9; break;
      case Xstring: i = 10; break;
      case Xlabel: i = 12; break;
      default: i = 3; break;
      }
    snaptree(pr->nextname, indent + i + j);
    j = 0;
    if (pr->son != NULL) { fprintf(log_, "\n%*c", indent, ' '); }
    pr = pr->son;
    }
}

void
printtext(nametype *namptr)
{
  while (namptr != NULL) {
      putc(' ', log_);
      wpair(&log_, ordp(namptr), ordp(namptr->nextname));
      fprintf(log_, " val=");
      wfloat(&log_, namptr->val);
      fflush(log_);
      snapname(namptr->segmnt, namptr->seginx, namptr->len);
      namptr = namptr->nextname;
      putc('\n', log_);
  }
}

void
printobject(primitive *primp)
{
  double xx, yy;
  int i;
  primitive *wprim;
  if (debuglevel != 0) {
    if (primp == NULL) { fprintf(log_, "Object is nil\n"); }
    else {
	  while (primp != NULL) {
	    wprim = primp;
	    fprintf(log_, "Object(%d) type=", ordp(primp));
	    snaptype(&log_, wprim->ptype);
	    fprintf(log_, "(%d)\n", wprim->ptype);
	    fprintf(log_, " Parent(%d", ordp(wprim->parent));
	    if (wprim->parent != NULL) {
		  fprintf(log_, ") Parent^.son(%d", ordp(wprim->parent->son)); }
	    fprintf(log_, ") Son(%d) Next(%d)\n",
		      ordp(wprim->son), ordp(wprim->nextname));
	    if (wprim->name != NULL) {
		  fprintf(log_, " name: ");
		  printtext(wprim->name); }
	    if (wprim->outlinep != NULL) {
		  fprintf(log_, " outline:");
		  printtext(wprim->outlinep); }
	    if (wprim->shadedp != NULL) {
		  fprintf(log_, " shaded:");
		  printtext(wprim->shadedp); }
	    if (wprim->textp != NULL) {
          fprintf(log_," textp->");
          printtext(wprim->textp); }
	    fprintf(log_, " aat");
	    wpair(&log_, wprim->aat.xpos, wprim->aat.ypos);
	    wlogfl("lparam", wprim->lparam, 0);
	    wlogfl("lthick", wprim->lthick, 0);
	    switch (wprim->direction) {
	      case Xup: fprintf(log_, " <up>"); break;
	      case Xdown: fprintf(log_, " <down>"); break;
	      case Xleft: fprintf(log_, " <left>"); break;
	      case Xright: fprintf(log_, " <right>"); break;
	      default: fprintf(log_, " dir =%d", wprim->direction); break;
	      }
	    fprintf(log_, " spec=%d(", wprim->spec);
        if (wprim->spec > 7) { fprintf(log_,"then,"); }
        logspec(wprim->spec);
        fprintf(log_,")\n");
	    fflush(log_);
	    switch (wprim->ptype) {
	      case Xbox:
	      case Xstring:
		    wlogfl("boxfill", wprim->boxfill_, 0);
		    wlogfl("boxheight", wprim->boxheight_, 0);
		    wlogfl("boxwidth", wprim->boxwidth_, 0);
		    wlogfl("boxrad", wprim->boxradius_, 0);
		    break;
	      case Xblock:
		    wlogfl("blockheight", wprim->blockheight_, 0);
		    wlogfl("blockwidth", wprim->blockwidth_, 0);
		    fprintf(log_, " here=");
		    wpair(&log_, wprim->here_.xpos, wprim->here_.ypos);
		    fprintf(log_, " vars=");
		    for (i = 0; i <= HASHLIM; i++) {
		      if (wprim->blockparms.vars[i] == NULL) {
				 fprintf(log_, " %d nil;", i);}
		      else {
				fprintf(log_, " %d %d;", i, ordp(wprim->blockparms.vars[i])); }
		      }
		    fprintf(log_, "\n env=");
		    if (wprim->blockparms.env == NULL) { fprintf(log_, "nil"); }
		    else { fprintf(log_, "%d", ordp(wprim->blockparms.env)); }
		    break;
	      case Xcircle:
		    wlogfl("cfill", wprim->circlefill_, 0);
		    wlogfl("radius", wprim->circleradius_, 0);
		    break;
	      case Xellipse:
		    wlogfl("efill", wprim->ellipsefill_, 0);
		    wlogfl("elheight", wprim->ellipseheight_, 0);
		    wlogfl("elwidth", wprim->ellipsewidth_, 0);
		    break;
	      case Xline:
	      case Xarrow:
	      case Xmove:
	      case Xspline:
		    fprintf(log_, " endpos=");
		    wpair(&log_, wprim->endpos_.xpos, wprim->endpos_.ypos);
		    wlogfl("height", wprim->lineheight_, 0);
		    wlogfl("width", wprim->linewidth_, 0);
		    wlogfl("lfill", wprim->linefill_, 0);
		    wlogfl("aradius", wprim->aradius_, 0);
		    fprintf(log_, "\n ahlex(atype)=%d", ahlex(wprim->lineatype_));
		    fprintf(log_, " ahnum(atype)=%d", ahnum(wprim->lineatype_));
		    break;
	      case Xarc:
		    fprintf(log_, " lspec=%d", lspec(wprim->spec));
		    wlogfl("lfill", wprim->linefill_, 0);
		    wlogfl("aradius", wprim->aradius_, 0);
		    fprintf(log_, " (startangle_,arcangle_)(deg)=");
		    wpair(&log_, wprim->startangle_ * 180.0 / pi,
		      wprim->arcangle_ * 180.0 / pi);
		    fprintf(log_, "\n (from)=");
		    xx = wprim->aat.xpos + (wprim->aradius_ * cos(wprim->startangle_));
		    yy = wprim->aat.ypos + (wprim->aradius_ * sin(wprim->startangle_));
		    wpair(&log_, xx, yy);
		    fprintf(log_, " (to)=");
		    xx = wprim->aat.xpos + (wprim->aradius_ *
              cos(wprim->startangle_ + wprim->arcangle_));
		    yy = wprim->aat.ypos + (wprim->aradius_ *
              sin(wprim->startangle_ + wprim->arcangle_));
		    wpair(&log_, xx, yy);
		    fprintf(log_, " ahlex(atype)=%d", ahlex(wprim->lineatype_));
		    fprintf(log_, " ahnum(atype)=%d", ahnum(wprim->lineatype_));
		    break;
	      case XLaTeX:
	      case Xlabel:
			/* blank case */
		    break;
	      default:
		    fprintf(log_, " Bad case in printobject; this cannot happen\n");
		    break;
	      }
	    putc('\n', log_);
	    fflush(log_);
	    if (wprim->ptype == Xblock) { primp = NULL; }
	    else { primp = wprim->son; }
	    }
      }
  }
  putc('\n', log_);
  fflush(log_);
}

void
prattribute(char *label, attribute *a)
{
  fprintf(log_, "attribute %s[%d]:", label, ordp(a));
  fprintf(log_, "\n lexval %4d", a->lexval);
  fprintf(log_, "  state %4d", a->state);
  fprintf(log_, "  chbufx %4d", a->chbufx);
  fprintf(log_, "  toklen %4d\n", a->toklen);
  if (a->varname != NULL) {
    fprintf(log_, " varname "); printtext(a->varname); }
  fprintf(log_, " xval %g", a->xval);
  fprintf(log_, " yval %g\n", a->yval);
  if (a->prim != NULL) {
    fprintf(log_, " prim[%d]",ordp(a->prim));
    fprintf(log_, " ptype : %4d ", a->prim->ptype);
    snaptype(&log_,a->prim->ptype); }
  putc('\n', log_);
  if (a->internal != NULL) {
    fprintf(log_, "intrtype: ");
    fprintf(log_, "%4d", a->internal->ptype);
    putc('\n', log_); }
}

void
prvars(primitive *eb)
{
  nametype *lv;
  int i = 0, x = HASHLIM + 1;
  if (eb == NULL) { fprintf(log_, "vars=nil: nil envblock"); return; }
  while (i < x) { if (eb->blockparms.vars[i] != NULL) { x = i; } else { i++; } }
  fprintf(log_, "vars=\n");
  if (x > HASHLIM) { fprintf(log_, "  None set\n"); return; }
  for (i = 0; i <= HASHLIM; i++) {
    fprintf(log_, "%d", i);
    lv = eb->blockparms.vars[i];
    if (lv == NULL) { fprintf(log_, " nil\n"); }
    while (lv != NULL) {
	  fprintf(log_, " (%d,%d)=", ordp(lv), ordp(lv->nextname));
	  snapname(lv->segmnt, lv->seginx, lv->len);
	  putc('=', log_);
	  wfloat(&log_, lv->val);
	  putc('\n', log_);
	  lv = lv->nextname;
      }
    }
  putc('\n', log_);
}
#endif

							/* Dispose of a tree of 1 or more objects */
void
deletetree(primitive **p)
{
  primitive *r, *wprim;
  int i;
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, "deletetree:\n"); }
#endif
  if ((*p) != NULL) { (*p)->parent = NULL; }
  while ((*p) != NULL) {
    while (((*p)->nextname != NULL) || ((*p)->son != NULL)) {
	  r = *p;
	  if ((*p)->nextname != NULL) { *p = (*p)->nextname; r->nextname = NULL; }
	  else { *p = (*p)->son; r->son = NULL; }
	  (*p)->parent = r;
      }
    r = (*p)->parent;
    deletename(&(*p)->shadedp);
    deletename(&(*p)->outlinep);
    deletename(&(*p)->textp);
    deletename(&(*p)->name);
    wprim = *p;
    if ((wprim->ptype) == Xblock) {
#ifdef DDEBUG
      if (debuglevel > 0) { fprintf(log_, "Xblock: "); }
#endif
	  for (i = HASHLIM; i >= 0; i--) { deletename(&wprim->blockparms.vars[i]);}
	  if (wprim->blockparms.env != NULL) { Free(wprim->blockparms.env); }
      }
#ifdef DDEBUG
    if (debuglevel > 0) {fprintf(log_, "*p free(%d)\n",odp(*p)); }
#endif
    free(*p);
    *p = r;
    }
  }


							/* Store arc strtang and arcang parameters */
void
setangles(double *strtang, double *arcang, postype ctr, double xs, double ys,
	  double xf, double yf)
{
  double ra;                       /* set arc angles given centre, start, end */
  *strtang = datan(ys - ctr.ypos, xs - ctr.xpos);
  ra = principal(datan(yf - ctr.ypos, xf - ctr.xpos) - (*strtang), pi);
  if ((ra < 0.0) && ((*arcang) > 0.0)) { ra += 2.0 * pi; }
  else if ((ra > 0.0) && ((*arcang) < 0.0)) { ra -= 2.0 * pi; }
  *arcang = ra;
}


							/* Perform assignment operator */
void
eqop(double *x, int op, double y)
{
  int i, j;

  switch (op) {
  case Xeq:
  case Xcoloneq:
    *x = y;
    break;
  case Xpluseq:
    *x += y;
    break;
  case Xminuseq:
    *x -= y;
    break;
  case Xmulteq:
    *x *= y;
    break;
  case Xdiveq:
    if (y == 0) { markerror(852); }
    else { *x /= y; }
    break;
  case Xremeq:
    i = Rnd((*x));
    j = Rnd(y);
    if (j == 0) { markerror(852); *x = 0.0; }
    else { *x = i - ((i / j) * j); }
    break;
  }
}

							/* Store int value in bits 9 and above */
void
setstval(int *st, int value)
{ *st = (value * 256) + ((*st) & 255);
}

							/* Recover int value from bits 9 and above */
int
getstval(int st)
{
  return (st >> 8);
}

							/* Record application of object attribute */
void
setstflag(int *st, int value)
{
  switch (value) {
  case XEMPTY:
    *st = ((*st) >> 6) * 64;
    break;
  case Xto:
    *st = (((*st) >> 1) * 2) + 1;
    break;
  case Xfrom:
    *st = (((*st) >> 2) * 4) + ((*st) & 1) + 2;
    break;
  case Xat:
    *st = (((*st) >> 3) * 8) + ((*st) & 3) + 4;
    break;
  case Xradius:
    *st = (((*st) >> 4) * 16) + ((*st) & 7) + 8;
    break;
  case Xcw:
    *st = (((*st) >> 5) * 32) + ((*st) & 15) + 16;
    break;
  case Xccw:
    *st = (((*st) >> 6) * 64) + ((*st) & 31) + 32;
    break;
  case Xchop:
    *st = (((*st) >> 7) * 128) + ((*st) & 63) + 64;
    break;
  case Xdirecton:
    *st = (((*st) >> 8) * 256) + ((*st) & 127) + 128;
    break;
  }
}


							/* Test if attribute has been applied */
boolean
teststflag(int st, int value)
{
  boolean b = false;

  switch (value) {
  case Xto:
    b = st & 1;
    break;
  case Xfrom:
    b = (st >> 1) & 1;
    break;
  case Xat:
    b = (st >> 2) & 1;
    break;
  case Xradius:
    b = (st >> 3) & 1;
    break;
  case Xcw:
    b = (st >> 4) & 1;
    break;
  case Xccw:
    b = (st >> 5) & 1;
    break;
  case Xchop:
    b = (st >> 6) & 1;
    break;
  case Xdirecton:
    b = (st >> 7) & 1;
    break;
  }
  return b;
}

							/* String equality of primitives */
int
cmpstring(primitive *p1, primitive *p2)
{
  if ((p1 == NULL) || (p2 == NULL)) { return maxint; }
  else if (p1->textp == NULL) { return maxint; }
  else if (p2->textp == NULL) { return (-maxint); }
  else { return (
          eqstring(p1->textp->segmnt, p1->textp->seginx, p1->textp->len,
		           p2->textp->segmnt, p2->textp->seginx, p2->textp->len)); }
}


							/* Match place name with stored places */
primitive *(
findplace(primitive *p, Char *chb, chbufinx inx, chbufinx toklen))
{
  primitive *pj = NULL;
  nametype *pname;
  while (p != pj) {
    if (p->name == NULL) { p = p->nextname; }
    else {
	  pname = p->name;
	  if (eqstring(pname->segmnt,pname->seginx,pname->len,
                   chb, inx,toklen) == 0) { pj = p; }
	  else { p = p->nextname; }
      }
    }
  return p;
}

							/* Get the value of a global variable */
double
findvar(char *s, int ln)
{
  int i, k;
  nametype *last, *np;
  chbufarray tmpfmt;

  for (i = 1; i <= ln; i++) { tmpfmt[i] = s[i-1]; }
  np = findname(globalenv, tmpfmt, 1, ln, &last, &k);
  if (np == NULL) { return 0.0; }
  else { return (np->val); }
}

							/* Search for variable in this and higer scope*/
nametype *(
glfindname(primitive *eb, Char *chb, chbufinx chbufx, chbufinx toklen,
	   nametype **last, int *k))
{
  nametype *np = NULL;
  primitive *pp = NULL;
  *k = 1;
  while (eb != pp) {
    np = findname(eb, chb, chbufx, toklen, last, k);
    if (np != NULL) { pp = eb; }
    else { eb = eb->parent; }
    }
  if (eb == NULL) { marknotfound(851, chb, chbufx, toklen); }
  return np;
}


							/* Append the int string to the name string*/
void
appendsuff(Char *buf, chbufinx inx, int *len, double x)
{
  int i, j, k;
  i = Rnd(x);
  if (i < 0) { buf[inx + (*len)] = '-'; (*len)++; i = -i; }
  k = i;
  do { (*len)++; k /= 10; } while (k != 0);
  if (inx + (*len) - 1 > CHBUFSIZ) { fatal(4); }
  j = (*len) - 1;
  do {
    k = i / 10;
    buf[inx + j] = i - (k * 10) + '0';
    i = k;
    j--;
  } while (i != 0);
}

							/* Append the suffix string to the name string
							   for one or two integers */
void
addsuffix(Char *buf, chbufinx *inx, int *len, double x, int lx, double y)
{
  int i, FORLIM;
  if (chbufi + (*len) - 1 > CHBUFSIZ) { fatal(4); }
  if ((*inx) + (*len) != chbufi) {
    FORLIM = *len;
    for (i = 0; i < FORLIM; i++) {
      buf[chbufi + i] = buf[(*inx) + i];
      buf[(*inx) + i] = '\0'; }
    *inx = chbufi; }
  if ((*inx) + (*len) + 2 > CHBUFSIZ) { fatal(4); }
  buf[(*inx) + (*len)] = '[';
  (*len)++;
  appendsuff(buf, *inx, len, x);
  if (lx == Xcomma) {
    buf[(*inx) + (*len)] = ',';
    (*len)++;
    appendsuff(buf, *inx, len, y); }
  buf[(*inx) + (*len)] = ']';
  (*len)++;
  chbufi = (*inx) + (*len);
}  /* addsuffix */


							/* Implement "then" or the "to" special case */
void
appendthen(primitive **pr) {
  primitive *prp, *prq;
  for (prq=(*pr); prq->son != NULL; prq = prq->son) {}
  copyprim(prq, &prp);
  prp->parent = prq;
  prp->son = NULL;
  prp->nextname = NULL;
  prp->name = NULL;
  prp->textp = NULL;
  prp->shadedp = NULL;
  if (prp->outlinep != NULL) {  /* We have to duplicate the stored string */
    copystr(&prp->outlinep, prq->outlinep); }
  FindExitPoint(prq, &prp->aat);
  prq->son = prp;
  setthen(&prp->spec);
  *pr = prp;
}

							/* Attribute up, down, left, right */
void
lineardir(primitive *pr, double dy, double dx, int *state) {
  if (!(teststflag(*state, Xto) | teststflag(*state, Xdirecton))) {
      pr->endpos_ = pr->aat; }
  switch (pr->direction) {
  case Xup:
    pr->endpos_.ypos += dy;
    break;
  case Xdown:
    pr->endpos_.ypos -= dy;
    break;
  case Xleft:
    pr->endpos_.xpos -= dx;
    break;
  case Xright:
    pr->endpos_.xpos += dx;
    break;
  }
  setstflag(state, Xdirecton);
}

							/* Test for outline for outlined "string" */
boolean
hasoutline(int lx, boolean warn) {
  boolean hs;
  hs = ((lx == Xspline) || (lx == Xarrow) || (lx == Xline) ||
	(lx == Xarc) || (lx == Xellipse) ||
	(lx == Xcircle) || (lx == Xbox));
  if (drawmode == SVG) { hs = (hs || (lx == Xstring)); }
  if ((!hs) && warn) { markerror(858); }
  return hs;
}


							/* Test for shade for shaded "string" */
boolean
hasshade(int lx, boolean warn) {
  boolean hs;
  if ((lx == Xellipse) || (lx == Xcircle) || (lx == Xbox)) { hs = true; }
  else if ((drawmode == Pict2e) || (drawmode == TeX) || (drawmode == tTeX) ||
           (drawmode == xfig)) { hs = false; }
  else { hs = ((lx == Xspline) || (lx == Xarrow) || (lx == Xline) ||
	    (lx == Xarc)); }
  if (drawmode == SVG) { hs = (hs || (lx == Xstring)); }
  if ((!hs) && warn) { markerror(858); }
  return hs;
}


							/* Create a string struct */
void
newstr(nametype **sp) {
  nametype *namestruct;
  *sp = malloc(sizeof(nametype)); if (*sp==NULL){ fatal(9); }
  namestruct = *sp;
  namestruct->val = 0.0;
  namestruct->segmnt = NULL;
  namestruct->seginx = 0;
  namestruct->len = 0;
  namestruct->nextname = NULL;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, "newstr[%d]\n", ordp(*sp)); }
#endif
}


							/* Copy a string into freeseg */
void
storestring(nametype *outstr,
  Char *srcbuf, chbufinx psrc, chbufinx lsrc, int job)
{ int i, j;
  boolean newseg;
  if ((freeseg == NULL) || (lsrc > (CHBUFSIZ - freex + 1))) { newseg = true; }
  else { newseg = false; }
  if (newseg) {
    freeseg = malloc(sizeof(chbufarray)); if (freeseg==NULL){ fatal(9); }
#ifdef DDEBUG
    if (debuglevel>0) { fprintf(log_,
      " storestring new[%d]\n lsrc=%d freex=%d space=%d\n",
        ordp(freeseg),lsrc,freex,CHBUFSIZ-freex+1); }
#endif
    putbval(freeseg, 0);
    freex = 2; }
  if (lsrc > (CHBUFSIZ - freex + 1)) { markerror(866); fatal(4); }
  for (i = 0; i < lsrc; i++) { freeseg[freex + i] = srcbuf[psrc + i]; }
  outstr->segmnt = freeseg;
  outstr->seginx = freex;
  outstr->len = lsrc;
  j = bval(freeseg);
  putbval(freeseg, j+1);
  freex += lsrc;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_,
	  "storestring to strptr %d: segmnt=%d seginx=%d links=%d freex=%d\n",
	  ordp(outstr), ordp(freeseg), outstr->seginx, bval(freeseg),
      freex);
  snapname(freeseg, outstr->seginx, outstr->len);
  fprintf(log_, " from:");
  snapname(srcbuf, psrc, lsrc);
  putc('\n', log_); }
#endif
  if (job != 0) { clearchbuf(psrc, lsrc); }
  }

							/* Duplicate a strptr and copy the body */
void
copystr(nametype **sp, nametype *ip)
{
  if (ip == NULL) { *sp = NULL; }
  else {
    newstr(sp);
    storestring(*sp, ip->segmnt, ip->seginx, ip->len, 0);
    }
}


							/* Append buf to *sp */
void
appendstring(nametype *sp, Char *buf, chbufinx px, chbufinx namelen)
{ int i, j;
  Char *tmpseg;
  int FORLIM;
  if ((sp == NULL) || (buf == NULL)) { return; }
  if ((sp->segmnt == freeseg) && (sp->seginx + sp->len == freex) &&
      (freex + namelen - 1 <= CHBUFSIZ)) {
                            /* New string fits; append to sp */
    for (i = 0; i < namelen; i++) { freeseg[freex + i] = buf[px + i]; }
    sp->len += namelen;
    freex += namelen;
    return;
    }
  if (sp->len + namelen + 2 > CHBUFSIZ) { markerror(866); return; }
  tmpseg = malloc(sizeof(chbufarray)); if (tmpseg==NULL){ fatal(9); }
                            /* Copy the existing string to tmpseg */
  FORLIM = sp->len;
  for (i = 0; i < FORLIM; i++) { tmpseg[i+2] = sp->segmnt[sp->seginx + i]; }
  j = bval(sp->segmnt);
  if (j > 1) {
    putbval(sp->segmnt, j-1);
    if ((sp->segmnt == freeseg) && (sp->seginx + sp->len == freex)) {
	  freex = sp->seginx;
	  j = 2;
	  while (freex > j) {
	    if (sp->segmnt[freex-1] == nlch) { freex--; }
	    else { j = freex; }
	    }
      }
    else {
	  FORLIM = sp->seginx + sp->len;
	  for (i = sp->seginx; i < FORLIM; i++) { sp->segmnt[i] = nlch; }
      }
    }
  else {
    if (sp->segmnt == freeseg) { freeseg = NULL; }
    Free(sp->segmnt);
    }
                            /* Append new string to tmpseg */
  if (sp->len + namelen + 1 > CHBUFSIZ) { fatal(4); }
  for (i = 0; i < namelen; i++) { tmpseg[sp->len + i + 2] = buf[px + i]; }
  freeseg = tmpseg;
  freex = sp->len + namelen + 2;
  putbval(freeseg, 1);
  sp->segmnt = freeseg;
  sp->seginx = 2;
  sp->len += namelen;
}


							/* Store or append string */
int
putstring(int ix, nametype *sp, Char *buf, chbufinx px, chbufinx namelen)
{
  if (ix <= 0) { storestring(sp, buf, px, namelen, 0); }
  else { appendstring(sp, buf, px, namelen); }
  return (ix + 1);
}


							/* Height of a primitive object */
double
pheight(primitive *pr)
{
  double ph;
  if (pr == NULL) { ph = 0.0; return ph; }
  switch (pr->ptype) {
  case Xbox:
    ph = pr->boxheight_;
    break;
  case Xstring:
    ph = pr->boxheight_;
    break;
  case Xblock:
    ph = pr->blockheight_;
    break;
  case Xellipse:
    ph = pr->ellipseheight_;
    break;
  case Xcircle:
    ph = 2.0 * pr->circleradius_;
    break;
  case Xline:
  case Xarrow:
  case Xmove:
  case Xspline:
    ph = pr->lineheight_;
    break;
  default:
    ph = 0.0;
    break;
  }
  return ph;
}


							/* Width of a primitive object */
double
pwidth(primitive *pr)
{
  double pw;

  if (pr == NULL) {
      pw = 0.0;
      return pw;
  }
  switch (pr->ptype) {

  case Xbox:
  case Xstring:
    pw = pr->boxwidth_;
    break;

  case Xblock:
    pw = pr->blockwidth_;
    break;

  case Xellipse:
    pw = pr->ellipsewidth_;
    break;

  case Xcircle:
    pw = 2.0 * pr->circleradius_;
    break;

  case Xline:
  case Xarrow:
  case Xmove:
  case Xspline:
    pw = pr->linewidth_;
    break;

  default:
    pw = 0.0;
    break;
  }
  return pw;
}


							/* The n, s, e, w values of a drawing tree */
void
neswrec(primitive *ptm)
{
  while (ptm != NULL) {
    nesw(ptm);
    if (ptm->ptype != Xblock) { neswrec(ptm->son); }
    ptm = ptm->nextname;
    }
  }


							/* Bounding box of a drawing tree */
void
getnesw(primitive *ptm)
{
  initnesw();
  neswrec(ptm);
  if (south > north) {
    south = 0.0;
    north = 0.0;
    }
  if (west > east) {
    west = 0.0;
    east = 0.0;
    }
}


							/* Test and return A(bove), B(elow),
							                   L(eft), R(ight) */
void
checkjust(nametype *tp, boolean *A, boolean *B, boolean *L, boolean *R)
{
  int i;

  if (tp == NULL) {
    *A = false;
    *B = false;
    *L = false;
    *R = false;
    return;
    }
  i = Rnd(tp->val);
  *R = i & 1;
  *L = (i >> 1) & 1;
  *B = (i >> 2) & 1;
  *A = (i >> 3) & 1;
}

							/* Return linespec, i.e.,
							   <solid>, <dotted>, <dashed>, <invis>
							   from lowest 3 bits */
int
lspec(int n)
{ /* if ((n div 16) mod 2) <> 0 then lspec := Xsolid
  else */
  return ((n & 7) + Xlinetype);
}

							/* Find the lowest block with environment
							   variables defined */
primitive *(
findenv(primitive *p))
{
  primitive *q = NULL;

  while (p != q) {
    if (p->ptype != Xblock) { p = p->parent; }
    else if (p->blockparms.env == NULL) { p = p->parent; }
    else { q = p; }
    }
  return p;
}


							/* Get the value of an environment variable */
double
venv(primitive *p, int ind)
{
  double v = 0.0;
  if ((ind <= XXenvvar) || (ind > Xlastenv)) { return v; }
  p = findenv(p);
  if (p != NULL) { v = p->blockparms.env[ind - XXenvvar - 1]; }
  return v;
}


							/* Get the value of an environment variable
							   if it has not been set locally */
double
qenv(primitive *p, int ind, double localval)
{
  double noval;
  switch (ind) {
  case Xfillval: noval = -1.0; break;
  case Xlinethick: noval = mdistmax; break;
  case Xdashwid: noval = mdistmax; break;
  default: noval = 0.0; break;
  }
  if (localval == noval) { return (venv(p, ind)); }
  else if (ind == Xlinethick) { return fabs(localval); }
  else { return localval; }
}


							/* Position from an affine transformation
							   orig + mat(cs) * [x,y]
							   Position cs is (cos t, sin t) */
postype
affine(double x, double y, postype orig, postype cs)
{
  postype tpos;

  tpos.xpos = orig.xpos + (cs.xpos * x) - (cs.ypos * y);
  tpos.ypos = orig.ypos + (cs.ypos * x) + (cs.xpos * y);
  return tpos;
}


							/* Get (cos t, sin t) of point wrt shaft */
postype
affang(postype point, postype shaft)
{
  double lgth;
  postype tpos;

  lgth = linlen(shaft.xpos - point.xpos, shaft.ypos - point.ypos);
  if (lgth == 0.0) {
    tpos.xpos = 1.0;
    tpos.ypos = 0.0; }
  else {
    tpos.xpos = (point.xpos - shaft.xpos) / lgth;
    tpos.ypos = (point.ypos - shaft.ypos) / lgth; }
  return tpos;
}

							/* Initialize parameters for routine nesw */
void
initnesw(void)
{
  south = distmax;
  north = -south;
  west = south;
  east = -west;
}


							/* Values north, south, west, east for a string
							   accounting for ljust rjust above below */
void
neswstring(primitive *pmp, double ht, double wd)
{
  boolean A, B, L, R;
  double x, y, offst;
  if (pmp == NULL) { return; }
  checkjust(pmp->textp, &A, &B, &L, &R);
  offst = venv(pmp, Xtextoffset);
  y = pmp->aat.ypos;
  if (A) { y += (ht * 0.5) + offst; }
  else if (B) { y += ((-ht) * 0.5) - offst; }
  x = pmp->aat.xpos;
  if (R) { x += ((-wd) * 0.5) - offst; }
  else if (L) { x += (wd * 0.5) + offst; }
  north = Max(north, y + (ht * 0.5));
  south = Min(south, y - (ht * 0.5));
  west = Min(west, x - (wd * 0.5));
  east = Max(east, x + (wd * 0.5));
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, " neswstring:");
    wlogfl("aat.xpos", pmp->aat.xpos, 0);
    wlogfl("x", x, 0);
    wlogfl("y", y, 1);
    wlogfl("east", east, 0);
    wlogfl("west", west, 0);
    wlogfl("wd", wd, 1);
    wlogfl("north", north, 0);
    wlogfl("south", south, 0);
    wlogfl("ht", ht, 1); }
#endif
}


							/* Values north, south, west, east for a line
							   or arrow */
void
neswline(primitive *pmp)
{
  double aht, awd;
  postype cs, cc, cd;
  int TEMP;
  if (pmp == NULL) { return; }
  west = Min(west, Min(pmp->aat.xpos, pmp->endpos_.xpos));
  east = Max(east, Max(pmp->aat.xpos, pmp->endpos_.xpos));
  south = Min(south, Min(pmp->aat.ypos, pmp->endpos_.ypos));
  north = Max(north, Max(pmp->aat.ypos, pmp->endpos_.ypos));
  TEMP = ahlex(pmp->lineatype_);
  if ((TEMP == Xlefthead) || (TEMP == Xdoublehead)) {
    cs = affang(pmp->endpos_, pmp->aat);
    awd = qenv(pmp, Xarrowht, pmp->linewidth_);
    aht = qenv(pmp, Xarrowwid, pmp->lineheight_);
    cc = affine(aht, awd / 2, pmp->aat, cs);
    cd = affine(aht, awd / (-2), pmp->aat, cs);
    west = Min(west, Min(cc.xpos, cd.xpos));
    east = Max(east, Max(cc.xpos, cd.xpos));
    south = Min(south, Min(cc.ypos, cd.ypos));
    north = Max(north, Max(cc.ypos, cd.ypos));
    }
  TEMP = ahlex(pmp->lineatype_);
  if (!((TEMP == Xrighthead) || (TEMP == Xdoublehead))) { return; }
  cs = affang(pmp->aat, pmp->endpos_);
  awd = qenv(pmp, Xarrowht, pmp->linewidth_);
  aht = qenv(pmp, Xarrowwid, pmp->lineheight_);
  cc = affine(aht, awd / 2, pmp->endpos_, cs);
  cd = affine(aht, awd / (-2), pmp->endpos_, cs);
  west = Min(west, Min(cc.xpos, cd.xpos));
  east = Max(east, Max(cc.xpos, cd.xpos));
  south = Min(south, Min(cc.ypos, cd.ypos));
  north = Max(north, Max(cc.ypos, cd.ypos));
}


							/* Test if angle is within an arc segment */
boolean
inarc(double strt, double fin, double ang, double arcang)
{
  boolean inarctmp;

  if (arcang >= 0.0) {
    while (fin < strt) { fin += 2.0 * pi; }
    while (ang < strt) { ang += 2.0 * pi; }
    if (ang <= fin) { inarctmp = true; }
    else { inarctmp = false; }
    }
  else {
    while (fin > strt) { fin -= 2.0 * pi; }
    while (ang > strt) { ang -= 2.0 * pi; }
    if (ang >= fin) { inarctmp = true; }
    else { inarctmp = false; }
    }
  return inarctmp;
}


							/* Values north, south, east, west of an obj */
void
nesw(primitive *ptmp)
{
  double hight, wdth, sang, eang;
  if (ptmp == NULL) { return; }
  switch (ptmp->ptype) {
    case Xstring:
      hight = ptmp->boxheight_;
      wdth = ptmp->boxwidth_;
      break;
    case Xbox:
      hight = ptmp->boxheight_;
      wdth = ptmp->boxwidth_;
      break;
    case Xblock:
      hight = ptmp->blockheight_;
      wdth = ptmp->blockwidth_;
      break;
    case Xcircle:
      hight = 2.0 * ptmp->circleradius_;
      wdth = hight;
      break;
    case Xellipse:
      hight = ptmp->ellipseheight_;
      wdth = ptmp->ellipsewidth_;
      break;
    default:
      hight = 0.0;
      wdth = 0.0;
      break;
    }
  switch (ptmp->ptype) {
  case Xbox:
  case Xblock:
  case Xcircle:
  case Xellipse:
    north = Max(north, ptmp->aat.ypos + (hight * 0.5));
    south = Min(south, ptmp->aat.ypos - (hight * 0.5));
    west = Min(west, ptmp->aat.xpos - (wdth * 0.5));
    east = Max(east, ptmp->aat.xpos + (wdth * 0.5));
    break;
  case Xstring:
    if (drawmode == SVG) {
	north = Max(north, ptmp->aat.ypos + (hight * 0.5));
	south = Min(south, ptmp->aat.ypos - (hight * 0.5));
	west = Min(west, ptmp->aat.xpos - (wdth * 0.5));
	east = Max(east, ptmp->aat.xpos + (wdth * 0.5));
    }
    else {
	neswstring(ptmp, hight, wdth);
    }
    break;
  case Xline:
  case Xarrow:
  case Xmove:
  case Xspline:
    neswline(ptmp);
    break;
  case XLaTeX:
  case Xlabel:
	/* blank case */
    break;
  case Xarc:
    sang = principal(ptmp->startangle_, pi);
    eang = ptmp->startangle_ + ptmp->arcangle_;
    if (inarc(sang, eang, 0.5 * pi, ptmp->arcangle_)) {
	  north = Max(north, ptmp->aat.ypos + ptmp->aradius_); }
    else { north = Max(north,
	  ptmp->aat.ypos + (ptmp->aradius_ * Max(sin(sang), sin(eang)))); }
    if (inarc(sang, eang, (-0.5) * pi, ptmp->arcangle_)) {
	  south = Min(south, ptmp->aat.ypos - ptmp->aradius_); }
    else { south = Min(south,
	  ptmp->aat.ypos + (ptmp->aradius_ * Min(sin(sang), sin(eang)))); }
    if (inarc(sang, eang, pi, ptmp->arcangle_)) {
	  west = Min(west, ptmp->aat.xpos - ptmp->aradius_); }
    else { west = Min(west,
	  ptmp->aat.xpos + (ptmp->aradius_ * Min(cos(sang),cos(eang)))); }
    if (inarc(sang, eang, 0.0, ptmp->arcangle_)) {
	  east = Max(east, ptmp->aat.xpos + ptmp->aradius_); }
    else { east = Max(east,
	  ptmp->aat.xpos + (ptmp->aradius_ * Max(cos(sang),cos(eang)))); }
    break;
  }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "nesw(%d) ptype=%d", odp(ptmp), ptmp->ptype);
    wlogfl("W", west, 0); wlogfl("S", south, 0);
    wlogfl("E", east, 0); wlogfl("N", north, 1); }
#endif
}

							/* Exit point of a primitive object */
void
FindExitPoint(primitive *pr, postype *pe)
{
  if (pr == NULL) {
      pe->xpos = 0.0;
      pe->ypos = 0.0;
      return;
  }
  if ((pr->ptype != Xblock) && (pr->son != NULL)) {
      FindExitPoint(pr->son, pe);
      return;
  }
  *pe = pr->aat;
  switch (pr->ptype) {
  case Xbox:
    switch (pr->direction) {
    case Xup:
      pe->ypos = pr->aat.ypos + (pr->boxheight_ * 0.5);
      break;
    case Xdown:
      pe->ypos = pr->aat.ypos - (pr->boxheight_ * 0.5);
      break;
    case Xleft:
      pe->xpos = pr->aat.xpos - (pr->boxwidth_ * 0.5);
      break;
    case Xright:
      pe->xpos = pr->aat.xpos + (pr->boxwidth_ * 0.5);
      break;
    }
    break;

  case Xstring:
    switch (pr->direction) {
    case Xup:
      pe->ypos = pr->aat.ypos + (pr->boxheight_ * 0.5);
      break;
    case Xdown:
      pe->ypos = pr->aat.ypos - (pr->boxheight_ * 0.5);
      break;
    case Xleft:
      pe->xpos = pr->aat.xpos - (pr->boxwidth_ * 0.5);
      break;
    case Xright:
      pe->xpos = pr->aat.xpos + (pr->boxwidth_ * 0.5);
      break;
    }
    break;

  case Xblock:
    switch (pr->direction) {
    case Xup:
      pe->ypos = pr->aat.ypos + (pr->blockheight_ * 0.5);
      break;
    case Xdown:
      pe->ypos = pr->aat.ypos - (pr->blockheight_ * 0.5);
      break;
    case Xleft:
      pe->xpos = pr->aat.xpos - (pr->blockwidth_ * 0.5);
      break;
    case Xright:
      pe->xpos = pr->aat.xpos + (pr->blockwidth_ * 0.5);
      break;
    }
    break;

  case Xcircle:
    switch (pr->direction) {
    case Xup:
      pe->ypos = pr->aat.ypos + pr->circleradius_;
      break;
    case Xdown:
      pe->ypos = pr->aat.ypos - pr->circleradius_;
      break;
    case Xleft:
      pe->xpos = pr->aat.xpos - pr->circleradius_;
      break;
    case Xright:
      pe->xpos = pr->aat.xpos + pr->circleradius_;
      break;
    }
    break;

  case Xellipse:
    switch (pr->direction) {
    case Xup:
      pe->ypos = pr->aat.ypos + (pr->ellipseheight_ * 0.5);
      break;
    case Xdown:
      pe->ypos = pr->aat.ypos - (pr->ellipseheight_ * 0.5);
      break;
    case Xleft:
      pe->xpos = pr->aat.xpos - (pr->ellipsewidth_ * 0.5);
      break;
    case Xright:
      pe->xpos = pr->aat.xpos + (pr->ellipsewidth_ * 0.5);
      break;
    }
    break;

  case Xarc:
    *pe = arcend(pr);
    break;

  case Xline:
  case Xarrow:
  case Xmove:
  case Xspline:
    *pe = pr->endpos_;
    break;

  case Xlabel:
  case XLaTeX:
	/* blank case */
    break;
  }
}

							/* Retrieve integer in first two buffer bytes */
int
bval(Char *buf)
{
  return (((int) buf[0]) << 8) + (int) buf[1] ;
}

							/* Store integer in first two buffer bytes */
void
putbval(Char *buf, int n)
{
  buf[0] = (n>>8); buf[1] = (n & 255);
}

							/* Free the space used by the name string */
void
deletename(nametype **head)
{ /*F(var head: strptr)F*/
  nametype *pn, *r;
  int j, FORLIM;
#ifdef DDEBUG
  if (debuglevel > 0) {fprintf(log_, "deletename:\n"); }
#endif
  while ((*head) != NULL) {
    pn = *head;
    r = pn;
    while (pn->nextname != NULL) { r = pn; pn = pn->nextname; }
    r->nextname = NULL;
    if (pn == (*head)) { *head = NULL; }
    if (pn->segmnt != NULL) {
	  if (bval(pn->segmnt) > 1) {
	    j = bval(pn->segmnt);
	    putbval(pn->segmnt, j - 1);
	    if ((pn->segmnt == freeseg) && (pn->seginx + pn->len == freex)) {
		  freex = pn->seginx;
		  j = 2;
		  while (freex > j) {
		    if (pn->segmnt[freex-1] == nlch) { freex--; }
		    else { j = freex; }
		    }
	      }
	    else {
		  FORLIM = pn->seginx + pn->len;
		  for (j = pn->seginx; j < FORLIM; j++) { pn->segmnt[j] = nlch; }
	      }
	    }
	  else if ((pn->segmnt == freeseg) && (freeseg != NULL)) {
#ifdef DDEBUG
        if (debuglevel > 0) {fprintf(log_, "freeseg free(%d)\n",odp(freeseg)); }
#endif
	    Free(freeseg);
	    freeseg = NULL;
	    }
	  else {
#ifdef DDEBUG
        if (debuglevel > 0) {
          fprintf(log_, "pn->segmnt free(%d)\n",odp(pn->segmnt)); }
#endif
	    Free(pn->segmnt);
        pn->segmnt = NULL;
	    }
      }
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, "pn free(%d)\n",odp(pn)); }
#endif
    Free(pn);
    }
}


							/* Store svalue in low 3 bits */
void
setspec(int *specv, int svalue)
{ *specv = (((*specv) >> 3) * 8) + svalue - Xlinetype;
							/* if svalue = Xsolid then
						     specv := (specv div 32)*32 + 16 + (specv mod 16) */
}

							/* Store svalue only in low 3 bits */
void
resetspec(int *specv, int svalue)
{ *specv = 0;
  setspec(specv, svalue);
}


							/* Set bit 4 to flag a segment with a parent */
void
setthen(int *specv)
{ *specv = (((*specv) >> 4) * 16) + ((*specv) & 7) + 8;
}

							/* Create and initialize a primitive object */
void
newprim(primitive **pr, int primtype, primitive *envblk)
{
  int i;
  primitive *wprim;
  switch (primtype) {
    case Xbox:
    case Xstring:
      *pr = malloc(sizeof(Xboxprimitive)); if (*pr==NULL){ fatal(9); }
      break;
    case Xblock:
      *pr = malloc(sizeof(primitive)); if (*pr==NULL){ fatal(9); }
      break;
    case Xcircle:
      *pr = malloc(sizeof(Xcircleprimitive)); if (*pr==NULL){ fatal(9); }
      break;
    case Xellipse:
      *pr = malloc(sizeof(Xellipseprimitive)); if (*pr==NULL){ fatal(9); }
      break;
    case Xline:
    case Xarc:
    case Xarrow:
    case Xmove:
    case Xspline:
      *pr = malloc(sizeof(Xlineprimitive)); if (*pr==NULL){ fatal(9); }
      break;
    case Xlabel:
    case XLaTeX:
      *pr = malloc(sizeof(Xlabelprimitive)); if (*pr==NULL){ fatal(9); }
      break;
    }

#ifdef DDEBUG
  if (debuglevel > 0) {fprintf(log_, "newprim");
  snaptype(&log_,primtype); fprintf(log_,"[%d]\n", ordp(*pr));
  }
#endif

  wprim = *pr;
  wprim->name = NULL;
  wprim->textp = NULL;
  wprim->outlinep = NULL;
  wprim->shadedp = NULL;
  wprim->son = NULL;
  wprim->nextname = NULL;
  if (envblk == NULL) {
    wprim->parent = NULL;
    wprim->aat.xpos = 0.0;
    wprim->aat.ypos = 0.0;
    wprim->direction = Xright;
    }
  else {
    wprim->parent = envblk;
    wprim->aat = envblk->here_;
    wprim->direction = envblk->direction;
    }
  wprim->lparam = mdistmax;
  wprim->lthick = mdistmax;
  if ((primtype == Xstring) || (primtype == Xspline) ||
    (primtype == Xarc) || (primtype == Xarrow) || (primtype == Xline) ||
    (primtype == Xellipse) || (primtype == Xcircle) ||
    (primtype == Xbox)) { resetspec(&wprim->spec, Xsolid); }
  else { resetspec(&wprim->spec, Xinvis); }
  wprim->ptype = primtype;
  switch (primtype) {
    case Xbox:
    case Xstring:
      wprim->boxfill_ = -1.0;
      wprim->boxheight_ = 0.0;
      wprim->boxwidth_ = 0.0;
      wprim->boxradius_ = 0.0;
      break;
    case Xblock:
      wprim->blockheight_ = 0.0;
      wprim->blockwidth_ = 0.0;
      wprim->here_ = wprim->aat;
      for (i = 0; i <= HASHLIM; i++) {
	    wprim->blockparms.vars[i]   = NULL;
	    wprim->blockparms.nvars[i]   = 0; }
      wprim->blockparms.env = NULL;
      break;
    case Xcircle:
      wprim->circlefill_ = -1.0;
      wprim->circleradius_ = 0.0;
      break;
    case Xellipse:
      wprim->ellipsefill_ = -1.0;
      wprim->ellipseheight_ = 0.0;
      wprim->ellipsewidth_ = 0.0;
      break;
    case Xline:
    case Xarrow:
    case Xmove:
    case Xarc:
    case Xspline:
      wprim->endpos_.xpos = 0.0;
      wprim->endpos_.ypos = 0.0;
      wprim->lineheight_ = 0.0;
      wprim->linewidth_ = 0.0;
      wprim->linefill_ = -1.0;
      wprim->aradius_ = mdistmax;
      wprim->lineatype_ = pahlex(0, XEMPTY);
      break;
    case Xlabel:
    case XLaTeX:
	/* blank case */
      break;
    }
}  /* newprim */

							/* Determine drawing direction at arc end */
void
arcenddir(primitive *pr)
{
  if (pr->arcangle_ > 0.0) {
    switch (pr->direction) {
    case 0: /* blank case */
	  break;
    case Xup:
	  envblock->direction = Xleft;
	  break;
    case Xdown:
	  envblock->direction = Xright;
	  break;
    case Xleft:
	  envblock->direction = Xdown;
	  break;
    case Xright:
	  envblock->direction = Xup;
	  break;
    }
    return;
  }
  switch (pr->direction) {
  case 0: /* blank case */
    break;
  case Xup:
    envblock->direction = Xright;
    break;
  case Xdown:
    envblock->direction = Xleft;
    break;
  case Xleft:
    envblock->direction = Xup;
    break;
  case Xright:
    envblock->direction = Xdown;
    break;
  }
}


#ifdef DDEBUG
primitive *(node[10001]);
int ijx;

int
scantree(primitive *p, primitive *r)
{
int j,k;
  while ( r != NULL) {
    j = 0; k = ijx;
    node[ijx] = r;
    while (j < k) { if (r==node[j]) { k = j; } else { j++; } }
    if ( j < k ) { return 0; }
    else {
      if ( scantree(p, r->nextname) == 0) { return 0; }
      if (ijx > 10000) { return 0; }
      r = r->son;
      ijx++;
      }
    }
  return 1;
  }

int
checktree( primitive *p )
{
  int ok;
  ijx = 0;
  node[ijx] = p;
  ok = scantree(p,p);
  fprintf(log_,"ok=%d ijx=%d\n",ok,ijx);
  return ok;
  }
#endif

							/* Shift a tree by (x,y) */
void
shift(primitive *pr, double x, double y)
{
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_,"\nshift[%d]=",ordp(pr));
    wpair(&log_, x, y); putc('\n', log_);
    snaptree(pr,0);
    fflush(log_); }
#endif
  if ((x == 0) && (y == 0)) { return; }
  while (pr != NULL) {
    pr->aat.xpos += x;
    pr->aat.ypos += y;
    if ((pr->ptype == Xspline) || (pr->ptype == Xmove) ||
	    (pr->ptype == Xarrow) || (pr->ptype == Xline)) {
	  pr->endpos_.xpos += x;
	  pr->endpos_.ypos += y; }
    if (pr->son != NULL) { shift(pr->son, x, y); }
    pr = pr->nextname;
    }
}


							/* Scale an object */
void
scaleobj(primitive *pr, double s)
{
  primitive *wprim;
  while (pr != NULL) {
    wprim = pr;
    wprim->aat.xpos *= s;
    wprim->aat.ypos *= s;
    if (wprim->ptype == Xbox) {
	  wprim->boxheight_ *= s;
	  wprim->boxwidth_ *= s;
	  wprim->boxradius_ *= s;
      }
    else if (wprim->ptype == Xblock) {
	  wprim->blockheight_ *= s;
	  wprim->blockwidth_ *= s;
      }
    else if (wprim->ptype == Xcircle) {
	  wprim->circleradius_ *= s;
      }
    else if (wprim->ptype == Xellipse) {
	  wprim->ellipseheight_ *= s;
	  wprim->ellipsewidth_ *= s;
      }
    else if (wprim->ptype == Xarc) {
	  wprim->aradius_ *= s;
      }
    else if ((wprim->ptype == Xspline) || (wprim->ptype == Xmove) ||
	       (wprim->ptype == Xarrow) || (wprim->ptype == Xline)) {
	  wprim->endpos_.xpos *= s;
	  wprim->endpos_.ypos *= s;
      }
    if (wprim->son != NULL) {
	  scaleobj(wprim->son, s);
      }
    pr = wprim->nextname;
    }
}

							/* corner(prim,<corner>,xval,yval); Put the
							   named-corner coordinates into xval,yval   */
void
corner(primitive *pr, int lexv, double *x, double *y)
{
  primitive *pe;
  boolean sb, A, B, L, R;
  if (pr == NULL) { return; }
  *x = pr->aat.xpos;
  *y = pr->aat.ypos;
  pe = pr;
  if ((lexv == XEMPTY) &&
      ((pr->ptype == Xspline) || (pr->ptype == Xmove) ||
       (pr->ptype == Xarrow) || (pr->ptype == Xline))) {
    while (pe->son != NULL) { pe = pe->son; }
    *x = 0.5 * (pr->aat.xpos + pe->endpos_.xpos);
    *y = 0.5 * (pr->aat.ypos + pe->endpos_.ypos);
    return;
    }
  if ((lexv == XEMPTY) && (pr->ptype != Xstring) && (pr->ptype != XLaTeX)) {
      return; }
  switch (pr->ptype) {
    case Xbox:
    case Xstring:
    case Xblock:
    case Xcircle:
    case Xellipse:
    case Xarc:
      *x = pr->aat.xpos;
      *y = pr->aat.ypos;
      initnesw();
      nesw(pr);
							/* Compass corners of justified strings not
							   implemented: */
		/* if ptype = Xstring then begin
         checkjust(textp,A,B,L,R);
         offst := venv(pr,Xtextoffset);
         if L then x := x+boxwidth/2 + offst
         else if R then x := x-boxwidth/2 - offst;
         if A then y := y+boxheight/2 + offst
         else if B then y := y-boxheight/2 - offst;
         end; */
      if ((pr->ptype == Xstring) && (drawmode == SVG)) {
	    switch (lexv) {
	      case Dotn: *y = north; break;
	      case Dots: *y = south; break;
	      case Dote: *x = east; break;
	      case Dotw: *x = west; break;
	      case Dotne: *y = north; *x = east; break;
	      case Dotse: *y = south; *x = east; break;
	      case Dotsw: *y = south; *x = west; break;
	      case Dotnw: *y = north; *x = west; break;
	      case Dotc: *y = pr->aat.ypos; *x = pr->aat.xpos; break;
	      case Dotstart:
	      case Dotend: markerror(858); break;
	      }
	    checkjust(pr->textp, &A, &B, &L, &R);
	    if (L) { pr->boxradius_ = (west - east) / 2; }
	    else if (R) { pr->boxradius_ = (east - west) / 2; }
        }
      else if (((pr->ptype == Xarc) || (pr->ptype == Xcircle) ||
	      (pr->ptype == Xellipse) || (pr->ptype == Xbox)) &&
	     ((lexv == Dotnw) || (lexv == Dotsw) || (lexv == Dotse) ||
	      (lexv == Dotne))) {
	    switch (pr->ptype) {
	    case Xbox:
	      *y = Min(pr->boxradius_, Min(fabs(pr->boxheight_),
		       fabs(pr->boxwidth_)) / 2) * (1 - (1 / sqrt(2.0)));
	      *x = (pr->boxwidth_ / 2) - (*y);
	      *y = (pr->boxheight_ / 2) - (*y);
	      break;
	    case Xellipse:
	      *x = pr->ellipsewidth_ * (0.5 / sqrt(2.0));
	      *y = pr->ellipseheight_ * (0.5 / sqrt(2.0));
	      break;
	    case Xarc:
	      *x = pr->aradius_ / sqrt(2.0);
	      *y = *x;
	      break;
	    case Xcircle:
	      *x = pr->circleradius_ / sqrt(2.0);
	      *y = *x;
	      break;
	    }
	    switch (lexv) {
	    case Dotne: /* blank case */ break;
	    case Dotse: *y = -*y; break;
	    case Dotnw: *x = -*x; break;
	    case Dotsw: *x = -*x; *y = -*y; break;
	    }
	    *x = pr->aat.xpos + (*x);
	    *y = pr->aat.ypos + (*y);
        }
      else if (pr->ptype == Xarc) {
	    switch (lexv) {
	    case Dotn: *y = pr->aat.ypos + pr->aradius_; break;
	    case Dots: *y = pr->aat.ypos - pr->aradius_; break;
	    case Dote: *x = pr->aat.xpos + pr->aradius_; break;
	    case Dotw: *x = pr->aat.xpos - pr->aradius_; break;
	    case Dotc: /* blank case */ break;
	    case Dotstart:
	      *x = pr->aat.xpos + (pr->aradius_ * cos(pr->startangle_));
	      *y = pr->aat.ypos + (pr->aradius_ * sin(pr->startangle_));
	      break;
	    case Dotend:
	      *x = pr->aat.xpos +
                 (pr->aradius_ * cos(pr->startangle_+pr->arcangle_));
	      *y = pr->aat.ypos +
                 (pr->aradius_ * sin(pr->startangle_+pr->arcangle_));
	      break;
	    } }
      else {
	    switch (lexv) {
	    case Dotn: *y = north; break;
	    case Dots: *y = south; break;
	    case Dote: *x = east; break;
	    case Dotw: *x = west; break;
	    case Dotne: *y = north; *x = east; break;
	    case Dotse: *y = south; *x = east; break;
	    case Dotsw: *y = south; *x = west; break;
	    case Dotnw: *y = north; *x = west; break;
	    case Dotc: *y = pr->aat.ypos; *x = pr->aat.xpos; break;
	    case Dotstart:
	    case Dotend: markerror(858); break;
	    } }
      break;

    case Xline:
    case Xarrow:
    case Xmove:
    case Xspline:
      if (lexv != Dotstart) {
	if (lexv == Dotend) {
	    while (pe->son != NULL) { pe = pe->son; }
	    *x = pe->endpos_.xpos;
	    *y = pe->endpos_.ypos; }
	else if (lexv == Dotc) {
	    while (pe->son != NULL) { pe = pe->son; }
	    *x = 0.5 * ((*x) + pe->endpos_.xpos);
	    *y = 0.5 * ((*y) + pe->endpos_.ypos); }
	else {
	    do {
		  sb = false;
		  switch (lexv) {
		  case Dotn:
		    sb = (pe->endpos_.ypos > (*y));
		    break;
		  case Dots:
		    sb = (pe->endpos_.ypos < (*y));
		    break;
		  case Dote:
		    sb = (pe->endpos_.xpos > (*x));
		    break;
		  case Dotw:
		    sb = (pe->endpos_.xpos < (*x));
		    break;
		  case Dotne:
		    sb = (((pe->endpos_.ypos > (*y)) && (pe->endpos_.xpos >= (*x))) ||
			  ((pe->endpos_.ypos >= (*y)) && (pe->endpos_.xpos > (*x))));
		    break;
		  case Dotse:
		    sb = (((pe->endpos_.ypos < (*y)) && (pe->endpos_.xpos >= (*x))) ||
			  ((pe->endpos_.ypos <= (*y)) && (pe->endpos_.xpos > (*x))));
		    break;
		  case Dotsw:
		    sb = (((pe->endpos_.ypos < (*y)) && (pe->endpos_.xpos <= (*x))) ||
			  ((pe->endpos_.ypos <= (*y)) && (pe->endpos_.xpos < (*x))));
		    break;
		  case Dotnw:
		    sb = (((pe->endpos_.ypos > (*y)) && (pe->endpos_.xpos <= (*x))) ||
			  ((pe->endpos_.ypos >= (*y)) && (pe->endpos_.xpos < (*x))));
		    break;
		  }
		  if (sb) {
		    *x = pe->endpos_.xpos;
		    *y = pe->endpos_.ypos; }
		  pe = pe->son;
	    } while (pe != NULL);
	  }
    }
    break;

  case Xlabel:
	/* blank case */
    break;

  case XLaTeX:
    markerror(858);
    break;
  }
}


							/* The nth (or nth last) enumerated object */
primitive *(
nthprimobj(primitive *primp, int nth, int objtype))
{
  primitive *prp = NULL;
  primitive *pp;
#ifdef DDEBUG
  if (debuglevel == 2) {
    fprintf(log_, "nthprimobj in [%s] nth=%d type=%d\n",
      (primp==NULL)?"NULL":"!NULL", nth, objtype);
	snaptree(primp,0); }
#endif
  if (nth == 0) { pp = primp;
    while (pp != NULL) {
	  if ((pp->ptype) == objtype) { prp = pp; }
	  pp = pp->nextname;
      }
    }
  else { pp = primp; i = 0;
    if (nth < 0) {
      while (pp != NULL) {
	    if (pp->ptype == objtype) { i++; }
	    pp = pp->nextname; }
      nth += i + 1;
      }
#ifdef DDEBUG
    if (debuglevel > 1) { fprintf(log_," nth=%d",nth); }
#endif
    pp = primp; i = 0; prp = NULL;
    while (pp != prp) {
      if (pp->ptype == objtype) { i++; }
      if (i == nth) { prp = pp; } else { pp = pp->nextname; }
      }
    }
  return prp;
  }


							/* Reset environment vars:
							   n=0: all
							   n<0: scaled variables only
							   n>0: one var given by its lexical val*/
void
resetenv(int envval, primitive *envbl)
{
  environx i, last;

  if (envbl == NULL) { return; }
  if (envval == 0) {
    envval = XXenvvar + 1;
    last = Xlastenv;
    }
  else if (envval < 0) {
    envval = XXenvvar + 1;
    last = Xlastsc;
    }
  else { last = envval; }
  if (envbl->blockparms.env == NULL) {
    envbl->blockparms.env = malloc(sizeof(envarray));
    if (envbl->blockparms.env==NULL){ fatal(9); }

#ifdef DDEBUG
    if (debuglevel > 0) {
	  fprintf(log_, "resetenv envarray[%d]\n", ordp(envbl->blockparms.env)); }
#endif
    }
  for (i = envval - 1; i <= (last - 1); i++) {
    switch (i + 1) {
							/* scaled environment vars (in) */
      case Xarcrad: envbl->blockparms.env[i - XXenvvar] = 0.25;
	    break;
      case Xarrowht: envbl->blockparms.env[i - XXenvvar] = 0.1;
	    break;
      case Xarrowwid: envbl->blockparms.env[i - XXenvvar] = 0.05;
	    break;
      case Xboxht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xboxrad: envbl->blockparms.env[i - XXenvvar] = 0.0;
	    break;
      case Xboxwid: envbl->blockparms.env[i - XXenvvar] = 0.75;
	    break;
      case Xcirclerad: envbl->blockparms.env[i - XXenvvar] = 0.25;
	    break;
      case Xdashwid: envbl->blockparms.env[i - XXenvvar] = 0.05;
	    break;
      case Xellipseht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xellipsewid: envbl->blockparms.env[i - XXenvvar] = 0.75;
	    break;
      case Xlineht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xlinewid: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xmoveht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xmovewid: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xtextht:
	    switch (drawmode) {
	      case PDF: envbl->blockparms.env[i - XXenvvar] = DFONT / 72.0;
	        break;
	      case SVG:
	        envbl->blockparms.env[i - XXenvvar] = (DFONT / 72.0) * 0.66;
	        break;
	      default:
	        envbl->blockparms.env[i - XXenvvar] = 0.0;
	        break;
	      }
	    break;
      case Xtextoffset: envbl->blockparms.env[i - XXenvvar] = 2.0 / 72;
	    break;
      case Xtextwid: envbl->blockparms.env[i - XXenvvar] = 0.0;
	    break;
							/* The following are unscaled */
      case Xarrowhead: envbl->blockparms.env[i - XXenvvar] = 1.0;
	    break;
      case Xfillval: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case Xlinethick: envbl->blockparms.env[i - XXenvvar] = 0.8;
	    break;
      case Xmaxpsht: envbl->blockparms.env[i - XXenvvar] = 11.0;
	    break;
      case Xmaxpswid: envbl->blockparms.env[i - XXenvvar] = 8.5;
	    break;
      case Xscale: envbl->blockparms.env[i - XXenvvar] = 1.0;
	    break;
      }
    }
}


							/* Copy env vars to current scope */
void
inheritenv(primitive *envbl)
{
  environx i;
  primitive *pr;

  pr = findenv(envbl);
  if (pr == NULL) { resetenv(0, envbl); return; }
  envbl->blockparms.env = malloc(sizeof(envarray));
  if (envbl->blockparms.env==NULL){ fatal(9); }
  for (i = XXenvvar; i <= (Xlastenv - 1); i++) {
      envbl->blockparms.env[i - XXenvvar] = pr->blockparms.env[i - XXenvvar];
  }
}


							/* Execute scale = x */
void
resetscale(double x, int opr, primitive *envbl)
{
  double r, s;
  int i;

  resetenv(-1, envbl);
  r = envbl->blockparms.env[Xscale - XXenvvar - 1];
  eqop(&envbl->blockparms.env[Xscale - XXenvvar - 1], opr, x);
  s = envbl->blockparms.env[Xscale - XXenvvar - 1];
  if (s == 0.0) {
      envbl->blockparms.env[Xscale - XXenvvar - 1] = r;
      s = 1.0;
      markerror(870);
  }
  else if (r == 0.0) {
      markerror(852);
  }
  else {
      s /= r;
  }
  for (i = XXenvvar; i < Xlastsc; i++) {
      eqop(&envbl->blockparms.env[i - XXenvvar], Xmulteq, s);
  }
}


							/* .PS xv yv
							   sfact = nominal scale factor set by scale = ...
							   xsc = effective scale factor to achieve correct
  							   max picture size
							   ie (size in inches)/(desired size in inches) */
void
getscale(double xv, double yv, primitive *lp, double *sfact, double *xsc)
{
  double gs = 1.0;
  int erno = 0;
  primitive *envp;

  *sfact = gs;
  if (lp != NULL) {
    if (lp->ptype == Xblock) {
	  envp = findenv(lp);
	  if (envp->blockparms.env[Xscale - XXenvvar - 1] > 0.0) {
	    *sfact = envp->blockparms.env[Xscale - XXenvvar - 1]; }
	  if ((east > west) &&
	    ((east - west) /
          (*sfact) > envp->blockparms.env[Xmaxpswid-XXenvvar-1]) &&
	    (envp->blockparms.env[Xmaxpswid - XXenvvar - 1] > 0.0)) {
	    erno = 903;
	    gs = (east - west) /
          envp->blockparms.env[Xmaxpswid - XXenvvar - 1];
	    }
	  if ((north > south) &&
	    ((north - south) /
          (*sfact)> envp->blockparms.env[Xmaxpsht-XXenvvar-1]) &&
	    (envp->blockparms.env[Xmaxpsht - XXenvvar - 1] > 0.0)) {
	    erno = 904;
	    gs = Max(gs,(north - south) /
          envp->blockparms.env[Xmaxpsht-XXenvvar-1]);
	    }
      }
    }
  if ((xv > 0.0) && (east > west)) {
    erno = 0;
    gs = (east - west) / (*sfact) / xv;
    }
  if ((yv > 0.0) && (north > south) &&
      ((xv == 0.0) || ((north - south) / gs > yv * (*sfact)))) {
    erno = 0;
    gs = (north - south) / (*sfact) / yv;
    }
  if (erno != 0) { markerror(erno); }
  *xsc = gs * (*sfact);
}

							/* Copy primitive for use by then or same */
void
copyprim(primitive *prin, primitive **prout)
{ /* Needed because assignment of variant records is unreliable */
  int i;
  if (prin == NULL) { return; }
  newprim(prout, prin->ptype, NULL);
  (*prout)->name = prin->name;
  (*prout)->textp = prin->textp;
  (*prout)->outlinep = prin->outlinep;
  (*prout)->shadedp = prin->shadedp;
  (*prout)->parent = prin->parent;
  (*prout)->son = prin->son;
  (*prout)->nextname = prin->nextname;
  (*prout)->aat = prin->aat;
  (*prout)->lparam = prin->lparam;
  (*prout)->lthick = prin->lthick;
  (*prout)->direction = prin->direction;
  (*prout)->spec = prin->spec;
  (*prout)->ptype = prin->ptype;
  switch (prin->ptype) {
  case Xbox:
  case Xstring:
    (*prout)->boxfill_ = prin->boxfill_;
    (*prout)->boxheight_ = prin->boxheight_;
    (*prout)->boxwidth_ = prin->boxwidth_;
    (*prout)->boxradius_ = prin->boxradius_;
    break;
  case Xblock:
    (*prout)->blockheight_ = prin->blockheight_;
    (*prout)->blockwidth_ = prin->blockwidth_;
    (*prout)->here_ = prin->here_;
    for (i = 0; i <= HASHLIM; i++) {
	  (*prout)->blockparms.vars[i] = prin->blockparms.vars[i];
	  (*prout)->blockparms.nvars[i] = prin->blockparms.nvars[i]; }
    if (prin->blockparms.env != NULL) {
	  (*prout)->blockparms.env = malloc(sizeof(envarray));
	  if ((*prout)->blockparms.env==NULL){ fatal(9); }
	  for (i = XXenvvar; i < Xlastenv; i++) {
	    (*prout)->blockparms.env[i - XXenvvar] =
          prin->blockparms.env[i - XXenvvar];
	    }
      }
    break;
  case Xcircle:
    (*prout)->circlefill_ = prin->circlefill_;
    (*prout)->circleradius_ = prin->circleradius_;
    break;
  case Xellipse:
    (*prout)->ellipsefill_ = prin->ellipsefill_;
    (*prout)->ellipseheight_ = prin->ellipseheight_;
    (*prout)->ellipsewidth_ = prin->ellipsewidth_;
    break;
  case Xline:
  case Xarrow:
  case Xmove:
  case Xarc:
  case Xspline:
    (*prout)->endpos_ = prin->endpos_;
    (*prout)->lineheight_ = prin->lineheight_;
    (*prout)->linewidth_ = prin->linewidth_;
    (*prout)->linefill_ = prin->linefill_;
    (*prout)->aradius_ = prin->aradius_;
    (*prout)->lineatype_ = prin->lineatype_;
    break;
  case Xlabel:
  case XLaTeX:
	/* blank case */
    break;
  }
}


							/* Delete temporary string */
void
deletestringbox(primitive **pr)
{
  primitive *prx;
  if ((*pr) == NULL) { }
  else if ((*pr)->parent == NULL) { }
  else if ((*pr)->parent->son != NULL) {
	if ((*pr)->parent->son == (*pr)) { (*pr)->parent->son = NULL; }
	else {
	  prx = (*pr)->parent->son;
	  while ((prx->nextname != NULL) && (prx->nextname != (*pr))) {
        prx = prx->nextname;}
	  prx->nextname = NULL; }
    }
#ifdef DDEBUG
    if (debuglevel > 0) {fprintf(log_, "deletestringbox tree\n"); }
#endif
  deletetree(pr);
}

void
mkOptionVars(void)
{
    makevar("dpicopt", 7, drawmode);
    if (safemode) { i = 1; } else { i = 0; }
    makevar("optsafe",      7, i);
    makevar("optMFpic",     8, MFpic);
    makevar("optMpost",     8, MPost);
    makevar("optPDF",       6, PDF);
    makevar("optPGF",       6, PGF);
    makevar("optPict2e",    9, Pict2e);
    makevar("optPS",        5, PS);
    makevar("optPSfrag",    9, PSfrag);
    makevar("optPSTricks", 11, PSTricks);
    makevar("optSVG",       6, SVG);
    makevar("optTeX",       6, TeX);
    makevar("opttTeX",      7, tTeX);
    makevar("optxfig",      7, xfig);
    if ((drawmode == SVG) || (drawmode == PDF) || (drawmode == PS)) {
	  makevar("dptextratio", 11, 0.66);
	  makevar("dpPPI",        5, 96.0);
      }
    else if (drawmode == xfig) {
	  makevar("xfigres",  7, 1200);
	  makevar("xdispres", 8, 80);
      }
}

							/* The program equivalent of var = number */
void
makevar(char *s, int ln, double varval)
{
  nametype *vn, *lastvar, *namptr;
  int j, tstval;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, "makevar chbufi=%d\n", chbufi); }
#endif
  if (chbufi+ln-1 > CHBUFSIZ) {fatal(4);}     /* This cannot happen now */
  for (j = 0; j < ln; j++) { chbuf[chbufi + j] = s[j]; }
  vn = findname(envblock, chbuf, chbufi, ln, &lastvar, &tstval);
  newstr(&vn);
  j = varhash(chbuf, chbufi, ln);
  storestring(vn, chbuf, chbufi, ln, 1);
#ifdef DDEBUG
  if (debuglevel > 1) {
    fprintf(log_, "makevar: envblock=%d eqstr val=%d\n",
      ordp(envblock), tstval);
    fprintf(log_, " lastvar=%d", ordp(lastvar));
    if (lastvar != NULL) {
	  snapname(lastvar->segmnt, lastvar->seginx, lastvar->len); }
    putc('\n', log_);
    fprintf(log_, " vn=%d\n", ordp(vn)); }
#endif
  if (lastvar == NULL) { envblock->blockparms.vars[j] = vn; }
  else if (tstval < 0) {
    if (envblock->blockparms.vars[j]->nextname == NULL) {
	  envblock->blockparms.vars[j]->nextname = vn; }
    else {
	  vn->nextname = lastvar->nextname;
	  lastvar->nextname = vn; }
    }
  else if (lastvar == envblock->blockparms.vars[j]) {
    vn->nextname = envblock->blockparms.vars[j];
    envblock->blockparms.vars[j] = vn;
    }
  else {
    namptr = envblock->blockparms.vars[j];
    while (namptr->nextname != lastvar) { namptr = namptr->nextname; }
    namptr->nextname = vn;
    vn->nextname = lastvar;
    }
  envblock->blockparms.nvars[j]++;
  vn->val = varval;
}

void                                       /* then, arc, deferred shift */
donamedobj(attribute *a1)
{
  if (a1->prim != NULL) {
	prp = a1->prim;
	while (isthen(a1->prim)) { a1->prim = a1->prim->parent; }
#ifdef DDEBUG
	if (debuglevel < 0) { fprintf(log_," donamedobj(%d):\n",ordp(a1->prim));
      if (checktree(envblock->son) == 0) {
        fprintf(errout," checktree failure ijx=%d\n",ijx);
        return; }
	  snaptree(a1->prim,0); }
#endif
	if (prp == a1->prim) { }
	else if ((a1->prim->name == NULL) && (prp->name != NULL)) {
	  a1->prim->name = prp->name;
	  prp->name = NULL; }
	if (a1->prim->ptype == Xarc) { arcenddir(prp); }
	if (teststflag(a1->state, Xat)) {    /* deferred shift */
	    wprim = a1->prim;
	    i = getstval(a1->state);
	    if (i == Xfloat) {  /* pair at */
		  getnesw(a1->prim);
		  dx = west + a1->startchop;
		  dy = south + a1->endchop;
	      }
	    else if (a1->internal != NULL) { corner(a1->internal, i, &dx, &dy); }
	    else { corner(a1->prim, i, &dx, &dy); }
	    a1->internal = NULL;
	    if ((drawmode == SVG) && (wprim->ptype == Xstring)) {
		  ts = venv(a1->prim, Xtextoffset);
		  if (teststflag(a1->state, Xcw)) {    /* shift by arg2,arg3 */
		    switch (i) {                                   /* textpos */
		      case Dote:  dx += ts; break;
		      case Dotne: dx += ts; dy += ts; break;
		      case Dotn:  dy += ts; break;
		      case Dotnw: dx -= ts; dy += ts; break;
		      case Dotw:  dx -= ts; break;
		      case Dotsw: dx -= ts; dy -= ts; break;
		      case Dots:  dy -= ts; break;
		      case Dotse: dx += ts; dy -= ts; break;
		      }
		    }
		  shift(a1->prim, a1->xval - dx, a1->yval - dy);
	      }
	    else if (wprim->ptype != Xarc) {
		  shift(a1->prim, a1->xval - dx, a1->yval - dy); }
	    else {
		  x1 = wprim->aat.xpos +
		     (wprim->aradius_ * cos(wprim->startangle_));
							/* from */
		  z1 = wprim->aat.ypos +
		     (wprim->aradius_ * sin(wprim->startangle_));
		  if (teststflag(a1->state, Xto)) {
							/* to X from Here|Y implied */
		    if ((i != XEMPTY) && (i != Dotc)) { markerror(858); }
		    r = wprim->aat.xpos + (wprim->aradius_ *
                  cos(wprim->startangle_ + wprim->arcangle_));
		    s = wprim->aat.ypos + (wprim->aradius_ *
                  sin(wprim->startangle_ + wprim->arcangle_));
		    wprim->aat.xpos = a1->xval;
		    wprim->aat.ypos = a1->yval;
		    wprim->aradius_ = linlen(r - wprim->aat.xpos, s - wprim->aat.ypos);
		    setangles(&wprim->startangle_,
			      &wprim->arcangle_, wprim->aat, x1, z1, r, s);
		    }
		  else if (teststflag(a1->state, Xfrom)) {
		    if ((i != XEMPTY) && (i != Dotc)) { markerror(858); }
		    wprim->aat.xpos = a1->xval;
		    wprim->aat.ypos = a1->yval;
		    t = datan(z1 - wprim->aat.ypos, x1 - wprim->aat.xpos);
		    r = wprim->aat.xpos + (wprim->aradius_ * cos(t + wprim->arcangle_));
		    s = wprim->aat.ypos + (wprim->aradius_ * sin(t + wprim->arcangle_));
		    wprim->aradius_ = linlen(x1 - wprim->aat.xpos,z1 - wprim->aat.ypos);
		    setangles(&wprim->startangle_, &wprim->arcangle_, wprim->aat,
               x1, z1, r, s);
			}
		  else { shift(a1->prim, a1->xval - dx, a1->yval - dy); }
	    }
	  }
    }
}

void
doundefine( attribute *a2 )
{
    macp = findmacro(macros, chbuf, a2->chbufx, a2->toklen, &lastp);
    if (macp != NULL) {
	  if (lastp != NULL) { lastp->nexta = macp->nexta; }
	  if (macp == macros) { macros = macp->nexta; }
	  disposebufs(&macp->argbody);
	  free(macp);
	  macp = NULL; }
}

							/* Stuff the body of a for loop or a macro body
							   into p2 */
void
readfor(fbuffer *p0, int attx, fbuffer **p2, Char endch, boolean isfor)
{ /* attx: -(name length)
     p0 <> nil: append the output to this buffer. */
  int j;
  int bracelevel = 1;
  fbuffer *p;
  fbuffer *p1 = NULL;
  boolean instring = false, moreinput = true;
  Char prevch = ' ';

#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "readfor: p0");
    if (p0 == NULL) { fprintf(log_, "=nil"); } else { fprintf(log_, "<>nil");}
    fprintf(log_, " attx(");
    if (attx < 0) { fprintf(log_, "-length)="); }
    else { fprintf(log_, "attx should be -ve):"); }
    fprintf(log_, "%5d\n", attx);
    fprintf(log_, "         p2");
    if ((*p2) == NULL) { fprintf(log_, "=nil"); }
    else { fprintf(log_, "<>nil"); }
    fprintf(log_, " endch=\"%c\" ch=\"%c\"\n", endch, ch);
    }
#endif
  if (!isfor) { inchar(); }
  while (moreinput) {
    if (p0 == NULL) { newbuf(&p); } else { p = p0; p0 = NULL; }
    p->attrib = attx;                   /* -(name length) */
    if (p1 != NULL) { p1->nextb = p; p->prevb = p1; }
    p->higherb = inbuf;
    p1 = p;
    j = CHBUFSIZ;
    if (endch == '}') { do { /* lbrace ... rbrace */
	  if (ch == bslch) { skipcontinue(instring); }
	  if (instring) {  /* do not check braces in strings */
		if ((ch == '"') && (prevch != bslch)) { instring = false; }
	    }
	  else if (ch == '#') { skiptoend(); ch = nlch; }
	  else if (ch == '{') { bracelevel++; }
	  else if (ch == '}') { bracelevel--; }
	  else if (ch == '"') { instring = true; }
	  if (bracelevel <= 0) {
		moreinput = false;
		j = p1->savedlen + 1;
		ch = nlch;
	    }
	  p1->savedlen++;
	  p1->carray[p1->savedlen] = ch;
	  prevch = ch;
	  if (moreinput) { inchar(); }
	  if (inputeof) {
        if (instring) { markerror(806); } else { markerror(804); }
		j = p1->savedlen;
		moreinput = false;
	    }
	  } while (p1->savedlen != j);
      }
    else { do { /* X ... X */
	  if (ch == bslch) { skipcontinue(instring); }
	  if (instring) {
	    if ((ch == '"') && (prevch != bslch)) { instring = false; }
	    }
	  else if (ch == endch) {
        moreinput = false; j = p1->savedlen + 1; ch = nlch; }
	  else if (ch == '#') { skiptoend(); ch = nlch; }
	  else if (ch == '"') { instring = true; }
	  p1->savedlen++;
	  p1->carray[p1->savedlen] = ch;
	  prevch = ch;
	  if (moreinput) { inchar(); }
	  if (inputeof) {
        if (instring) { markerror(806); } else { markerror(804); }
	    j = p1->savedlen;
	    moreinput = false;
	    }
      } while (p1->savedlen != j);
      }
    }
  while (p1->prevb != NULL) { p1 = p1->prevb; }
  if (isfor) { backup(); }
#ifdef DDEBUG
  if (debuglevel > 0) {
      fprintf(log_, "\nreadfor done: for/macro buffer"); wrbuf(p1, 3); }
#endif
  *p2 = p1;
}

void
queueprim(primitive *pr, primitive *envblk)
{
  primitive *pp;
  if (envblk->son == NULL) { envblk->son = pr; }
  else if (tail != NULL ) { tail->nextname = pr; }
  else {
    pp = envblk->son;
    while (pp->nextname != NULL) { pp = pp->nextname; }
    pp->nextname = pr;
    }
  tail = pr;
  }


void
clearchbuf(chbufinx bi, int ln) /* Needed in the C version */
{
  int i,j;
  if ((bi+ln) == chbufi) {
    i = bi-1; j = -1;
    while (i > j) { if (chbuf[i] == '\0') { i--; } else { j = i; } }
    chbufi = i+1; }
  else { for (i=0; i<ln; i++) { chbuf[bi+i] = '\0'; } }
  }

void
dodefhead( attribute *a0 )
{
  fbuffer *macargbody;
  Char lastc;
  macp = findmacro(macros, chbuf, a0->chbufx, a0->toklen, &lastp);
  if (macp == NULL) {
	newarg(&macp);
	if (lastp == NULL) { macros = macp; } else { lastp->nexta = macp; }
    }
  disposebufs(&(macp->argbody));
  newbuf(&(macp->argbody));
  macargbody = macp->argbody;
							/* copy the macro name */
  FORLIM = a0->toklen;
  for (i = 1; i <= FORLIM; i++) {
    macargbody->carray[i] = chbuf[a0->chbufx + i - 1]; }
  macargbody->savedlen = a0->toklen;
  macargbody->readx = a0->toklen + 1;
  clearchbuf(a0->chbufx, a0->toklen);
  skipwhite();
  if (ch == '{') { lastc = '}'; } else { lastc = ch; }
							/* append the body */
  readfor(macp->argbody, -(a0->toklen), &macp->argbody, lastc, false);
  lastm = macp->argbody;
  while (lastm->nextb != NULL) { lastm = lastm->nextb; }
  lastm->carray[lastm->savedlen] = etxch;
#ifdef DDEBUG
  if (debuglevel > 1) { putc('\n', log_);
	if (currprod == 4 /* defhead1 */) { fprintf(log_, "defhead1"); }
	else { fprintf(log_, "defhead2"); }
	wrbuf(macp->argbody, 3); }
#endif
  }

                            /* Xsprintf Xlparen stringexpr Xcomma exprlist
                               Construct the sprintf result string */
primitive *(
sprintfstring( attribute *a3, attribute *a5, int nexprs ))
{
  int exprcount, substrstart, substrend, putcount, brk;
  primitive *a0prim;
  nametype *formatstr;
  Char *fsegmnt;
  int fseginx, flen, numberlen, i;
  char fmtch;
  chbufarray tmpbuf, tmpfmt;
                            /* The output string primitive */
  newprim(&a0prim, Xstring, envblock);
  newstr(&a0prim->textp);

  eb = findenv(envblock);
#ifdef DDEBUG
  if (debuglevel > 0) {
	fprintf(log_,"\nsprintf: nexprs=%d; format string:\n",nexprs);
	printobject(a3->prim); }
#endif
  a0prim->boxheight_ = eb->envinx(Xtextht);
  a0prim->boxwidth_ = eb->envinx(Xtextwid);
  exprcount = 0;
  substrstart = 0;
  substrend = 0;
  putcount = 0;
  if (a3->prim == NULL) { /* nil */ }
  else if (a3->prim->textp == NULL) { /* nil */ }
  else {  /*-- */
	formatstr = a3->prim->textp;
    fsegmnt = formatstr->segmnt;
    fseginx = formatstr->seginx;
    flen = formatstr->len;
	while (substrend < flen) {
      if (fsegmnt[fseginx + substrend] != '%') {
        substrend++;
        if (substrend == flen) {
          putcount = putstring(putcount, a0prim->textp,
            fsegmnt, fseginx + substrstart, substrend - substrstart); }
        continue;
        }
      if (fsegmnt[fseginx + substrend + 1] == '%') {   /* %% prints %*/
        putcount = putstring(putcount, a0prim->textp,
          fsegmnt, fseginx + substrstart, substrend - substrstart + 1);
        substrend += 2;
        substrstart = substrend;
        continue;
        }
      if (exprcount >= nexprs) {  /* not enough exprs */
        markerror(864); substrend = flen; continue; }
      if (substrend > substrstart) {
        putcount = putstring(putcount, a0prim->textp,
          fsegmnt, fseginx + substrstart, substrend - substrstart);
        substrstart = substrend; }
      brk = flen;
      substrend++;
      if (fsegmnt[fseginx+substrend] == '-') { substrend++; }
      while (substrend < brk) {
	    fmtch = fsegmnt[fseginx + substrend];
        if ((fmtch=='g') || (fmtch=='f') || (fmtch=='e')) { brk = substrend; }
        else if ((fmtch=='.') || isdigit(fmtch)) { substrend++; }
        else { substrend = brk; }
        }
      if (brk == flen) { markerror(865); continue; }
      substrend++;
      if (substrend - substrstart + 1 > CHBUFSIZ) {
        markerror(873); numberlen = 0; substrend = flen; }
      else {
        for (i = substrstart; i <= (substrend - 2); i++) {
          tmpfmt[i - substrstart] = fsegmnt[fseginx + i]; }
        tmpfmt[substrend - 1 - substrstart] = 'L';
        tmpfmt[substrend - substrstart] = fsegmnt[fseginx + substrend - 1];
        tmpfmt[substrend + 1 - substrstart] = '\0';
        numberlen = snprintf((char *)tmpbuf,
          CHBUFSIZ,(char *)tmpfmt, (long double) a5->xval);
	    a5++; a5++;
        }
      if (numberlen < 0) { markerror(874); substrend = flen; }
      else if (numberlen > CHBUFSIZ) {
        markerror(874); numberlen = CHBUFSIZ; substrend = flen; }
							/* Copy tmpbuf to the string */
      if (numberlen > 0) {
        putcount = putstring(putcount, a0prim->textp, tmpbuf, 0, numberlen); }
      exprcount++;
      substrstart = substrend;
	  }
    } /*  --*/
  if (nexprs > exprcount) { markerror(864); }
  if ((drawmode == xfig) && (a0prim->boxwidth_ == 0.0)) {
	if (a0prim->boxheight_ == 0.0) {
      a0prim->boxheight_ = 0.1 * eb->envinx(Xscale); }
    if (a0prim->textp != NULL) {
      a0prim->boxwidth_ = a0prim->boxheight_ * a0prim->textp->len * 0.75; }
	}
  else if ((drawmode == PDF) && (a0prim->textp != NULL)) {
	a0prim->boxwidth_ = a0prim->boxheight_ * a0prim->textp->len * 0.6; }

  if (envblock->son == a3->prim) { envblock->son = a0prim; }
  deletestringbox(&(a3->prim));

#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_,"\nsprintf result: \n"); printobject(a0prim); }
#endif
  return a0prim;
}

#ifdef DDEBUG
int ordp(void *p)       { return (p==NULL)?(int) 0 : (int) abs((long)p); }
#endif
