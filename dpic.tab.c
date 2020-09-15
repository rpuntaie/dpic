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
#line 36 "dpic.y" /* yacc.c:339  */

#define EXTRN extern
#include "dpic.h"
#define Rnd(x)	((long)floor(x + 0.5))

#define envinx(x)	blockparms.env[(int)(Rnd(x)-Xenvvar-1)]

void yyerror(char const *);

boolean hasoutline(int, boolean);
boolean hasshade(int, boolean);
boolean isprint_(Char);
boolean teststflag(int, int);
double findvar(Char *, int);
double intpow(double, int);
double linlen(double, double);
double pheight(primitive *);
double pwidth(primitive *);
int bval(Char *);
int cmpstring(primitive *, primitive *);
int getstval(int);
int putstring(int, nametype *, Char *, chbufinx, chbufinx);
int varhash(Char *, chbufinx, chbufinx);
primitive *( findenv(primitive *));
primitive *( findplace(primitive *, Char *, chbufinx, chbufinx));
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
void dosprintf( attribute *, attribute *, attribute *, int );
void dostart(void);
void doundefine( attribute * );
void eqop(double *, int, double);
void FindExitPoint(primitive *, postype *);
void getnesw(primitive *);
void getscale(double, double, primitive *, double *, double *);
void inheritenv(primitive *);
void initnesw(void);
void inittwo(void);
void lineardir(primitive *, double, double, int *);
void makevar(Char *, int, double);
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
void wrbuf(fbuffer *, int, int);

#ifdef DDEBUG
int lspec(int);
void logaddr(fbuffer *);
void prattribute(char *, attribute *);
void printobject(primitive *);
void prvars(primitive *);
void snapname(Char *, chbufinx, chbufinx);
void wrbufaddr(fbuffer *, int);
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
extern void P_sun_argv(char*, int, int);
extern void setjust(nametype *, int);
extern void skipcontinue(boolean);
extern void skiptobrace(void);
extern void skiptoend(void);
extern void wcoord(FILE **, double, double);
extern void wfloat(FILE **, double);
extern void wpair(FILE **, double, double);
extern void wstring(FILE **, nametype *);

typedef double envarray[Xlastenv - XXenvvar];

#line 180 "dpic.y" /* yacc.c:339  */

  nametype *lastvar, *namptr;
  fbuffer *lastm;
  arg *macp, *lastp;
  primitive *primp, *prp, *eb;
  int i, j, k, kk, lj, ll, nexprs, nwi;
  double r, s, t, x1, z1, dx, dy, ts;
  boolean bswitch;
  attribute *With, *With1;
  primitive *With2;
  nametype *With4;
  int FORLIM;
  char cy;

#line 220 "dpic.tab.c" /* yacc.c:339  */

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
    XDotPS = 42,
    XDotPE = 43,
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
    XDotx = 68,
    XDoty = 69,
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
    XDotne = 86,
    XDotse = 87,
    XDotnw = 88,
    XDotsw = 89,
    XDotn = 90,
    XDots = 91,
    XDote = 92,
    XDotw = 93,
    XDotstart = 94,
    XDotend = 95,
    XDotc = 96,
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

#line 458 "dpic.tab.c" /* yacc.c:358  */

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
#define YYLAST   850

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  344

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
       0,   393,   393,   395,   411,   486,   488,   492,   495,   498,
     502,   504,   512,   521,   523,   526,   531,   539,   586,   610,
     612,   615,   622,   624,   635,   637,   639,   641,   651,   675,
     681,   684,   704,   706,   710,   719,   722,   727,   734,   747,
     749,   753,   765,   778,   794,   797,   799,   801,   812,   818,
     825,   829,   834,   836,   839,   842,   846,   853,   857,   867,
     888,   919,   923,   977,  1004,  1006,  1009,  1011,  1014,  1017,
    1020,  1024,  1034,  1038,  1040,  1046,  1095,  1137,  1140,  1144,
    1146,  1151,  1153,  1171,  1191,  1194,  1198,  1222,  1225,  1229,
    1232,  1236,  1238,  1324,  1404,  1466,  1493,  1504,  1605,  1667,
    1688,  1711,  1756,  1774,  1786,  1820,  1846,  1973,  2005,  2026,
    2061,  2157,  2175,  2221,  2259,  2268,  2277,  2293,  2312,  2323,
    2481,  2486,  2538,  2547,  2549,  2552,  2564,  2566,  2582,  2592,
    2599,  2606,  2611,  2616,  2620,  2622,  2624,  2626,  2631,  2636,
    2642,  2649,  2652,  2657,  2659,  2664,  2673,  2676,  2679,  2683,
    2687,  2693,  2695,  2700,  2712,  2728,  2740,  2751,  2759,  2761,
    2764,  2768,  2770,  2776,  2784,  2793,  2799,  2801,  2803,  2827,
    2848,  2855,  2864,  2866,  2869,  2871,  2874,  2929,  2932,  2937,
    2987,  3007,  3010
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
  "input", "picture", "NL", "start", "elementlist", "term", "element",
  "lbrace", "namedobj", "suffix", "position", "assignlist", "command",
  "optnl", "ifpart", "elsehead", "for", "stringexpr", "string",
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

#define YYTABLE_NINF -159

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -159,    28,  -159,   615,    67,    67,   335,   579,   521,   521,
     -46,    37,    37,  -159,  -159,    72,   119,    92,   109,  -159,
     485,    -4,    98,  -159,  -159,   -13,    57,   147,  -159,  -159,
    -159,   635,   615,   615,    37,  -159,   -26,   159,   146,   284,
      40,   136,    32,  -159,  -159,   180,   203,   181,   184,  -159,
      98,   177,  -159,   111,  -159,   198,   143,   521,  -159,  -159,
     503,  -159,   149,   193,   521,   521,   615,   615,   615,   284,
     204,  -159,  -159,  -159,  -159,   615,   615,  -159,  -159,   223,
    -159,  -159,   160,   615,  -159,  -159,  -159,    37,    37,  -159,
    -159,   368,   -26,    70,   -26,   -26,   260,   282,  -159,   -29,
    -159,   521,   146,   116,  -159,   635,  -159,   219,  -159,   170,
     635,    10,   235,   635,   368,   635,  -159,   699,   635,  -159,
     449,   284,   284,   225,   235,   -26,   557,  -159,   521,  -159,
     -29,   -26,   -26,   521,   615,   615,   521,   199,   521,  -159,
     368,  -159,  -159,   342,   368,   368,  -159,  -159,   243,   163,
    -159,   268,   193,   296,   237,  -159,  -159,  -159,  -159,  -159,
    -159,    37,    -4,  -159,  -159,   225,   251,   182,    -2,    19,
     235,  -159,   267,   235,   235,  -159,  -159,  -159,  -159,    75,
     355,  -159,   635,   263,   169,   288,   169,  -159,  -159,   635,
     169,   279,     7,    26,  -159,  -159,   521,   521,   521,   521,
     521,   521,   521,   521,   521,  -159,   521,  -159,   521,  -159,
     521,   521,   -26,  -159,   521,   521,   235,    53,   283,   287,
     521,   216,   248,   261,   557,    16,  -159,  -159,   355,   309,
     221,  -159,   235,  -159,   303,   221,   284,   284,   355,   264,
     266,   177,    34,    34,  -159,   235,   355,  -159,   521,  -159,
    -159,  -159,   521,  -159,  -159,   302,   -23,  -159,  -159,  -159,
     171,   521,  -159,  -159,   310,  -159,   320,    26,   326,   521,
     331,  -159,   355,   355,   355,   355,   355,   355,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,   235,  -159,  -159,  -159,  -159,
      37,    -4,  -159,   521,   521,  -159,   521,  -159,   521,   295,
     521,   521,   125,    18,   125,   322,  -159,   699,   -26,   235,
    -159,    45,  -159,  -159,  -159,  -159,   355,  -159,  -159,  -159,
    -159,  -159,   253,  -159,   262,   521,  -159,  -159,   235,   354,
    -159,   344,   521,   521,  -159,   304,  -159,  -159,     9,  -159,
     342,   521,  -159,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,     0,     0,     0,     0,     0,
     172,    32,    32,   150,   133,     0,     0,     0,     0,   170,
       8,     0,     0,   143,    13,   146,     0,   151,     6,     5,
       3,    10,     0,     0,    32,    60,     0,     0,   170,    66,
       0,     0,   167,    58,    39,   166,     0,     0,     0,    35,
     138,    73,   161,   163,   152,     0,     0,     0,   171,   154,
       0,   158,     0,   148,     0,     0,     0,     0,     0,     9,
       0,   135,   136,   134,   155,     0,     0,   174,   175,     0,
     147,   176,   131,     0,   118,    29,   122,    32,    32,    21,
     117,     0,     0,    44,     0,     0,     0,     0,    72,     0,
      20,   123,     0,     0,    11,    10,    17,    19,    22,    24,
      10,     0,   120,    10,     0,    10,    46,    30,    10,    91,
       0,    67,    68,   171,    86,     0,     0,   141,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,   182,    61,   130,     0,     0,   160,   159,     0,     0,
     177,     0,   149,     0,     0,    14,    15,    16,   137,   144,
     145,    32,     0,   132,   153,     0,     0,    81,    81,    81,
      47,    84,    45,    28,    27,    48,    49,    50,    51,     0,
     124,   119,    53,     0,     0,     0,     0,    26,    76,    10,
       0,   166,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   103,   123,   106,
     123,   123,     0,   112,   123,   123,   107,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    65,    63,    64,     0,
       0,    40,   164,    59,     0,   165,    69,    70,   129,     0,
       0,    74,     0,     0,   162,   169,   168,    34,     0,    33,
     178,   179,     0,   156,   157,     0,     0,    42,    43,    41,
       0,     0,    12,     4,     0,    55,     0,     0,     0,     0,
       0,    56,    92,    93,    94,    95,    96,    97,   109,   110,
     111,   108,   100,   101,    99,   113,   102,    98,   125,   121,
      32,     0,   114,     0,     0,    62,     0,   142,     0,     0,
       0,     0,   139,   146,   140,     0,    18,    31,     0,    82,
      85,     0,    23,    25,    57,    54,   165,    71,   127,   128,
     115,   116,    89,    88,     0,     0,    36,   180,    83,    79,
      77,     0,     0,     0,   138,     0,    80,    75,     0,    90,
      38,     0,    78,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   376,  -159,   -66,    13,   189,  -159,  -159,
     -10,   -25,    -1,  -159,  -102,  -159,  -159,  -159,    -5,   245,
    -120,   166,     5,  -159,  -159,   269,  -159,  -159,  -159,  -159,
     217,  -159,   381,  -159,    59,   138,  -159,  -159,   -51,  -159,
    -159,   274,   -76,  -158,    62,    -6,  -159,   281,    -9,  -159,
     257,   254,  -159,   392
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,   182,     5,   103,    39,   104,   105,   106,
      58,    40,   107,   108,   183,   109,   110,   111,   112,    43,
      44,   227,   230,   113,   114,    46,   115,   189,   331,   332,
     257,   172,   116,    48,   323,   117,   118,   119,   181,   218,
     120,    49,    21,    74,   143,    22,    23,    24,    25,    26,
      51,    52,    53,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    42,    59,   162,   254,    41,   226,    63,   132,    87,
     231,    45,    79,    55,    56,    35,    20,    70,    35,   134,
     135,  -158,    71,   248,   123,   140,   132,    28,     2,   134,
     135,   124,   148,    69,   187,   296,   131,    72,   136,   184,
      29,   301,   132,    79,   186,   121,   122,   190,   127,   193,
     -52,    50,   217,   152,    28,   134,   135,     8,    57,   128,
      37,     9,   149,    37,   270,   151,   167,    29,    28,   153,
     154,    61,     3,    12,    80,   -52,   308,   165,   166,    60,
     137,    29,   264,   138,   266,    50,   168,   170,   268,   173,
     174,   271,    81,   342,   130,   188,   169,   256,   179,    64,
      13,   329,    14,   229,   226,    80,   180,    75,   234,    42,
      76,   -52,   216,   240,    50,   288,    65,    28,   256,   191,
     225,    16,    50,   267,    82,   222,   232,    50,   261,   330,
      29,   228,    50,   319,    75,    42,   102,    76,   235,    42,
     245,   238,     8,   291,   129,   191,     9,   236,   237,   191,
     246,   253,    73,   134,   135,   130,    61,   282,    12,   283,
     284,   -52,    83,   286,   287,   314,   125,   248,    77,    78,
      28,   147,     8,   134,   135,   126,     9,   278,   279,   280,
      62,   281,   136,    29,   133,   249,    61,    14,    12,   141,
     134,   135,   142,   -52,   144,   292,    50,    50,    50,   136,
      50,   272,   273,   274,   275,   276,   277,   285,   134,   135,
     145,   139,    63,   180,    50,   180,   180,    14,    79,   180,
     180,   140,   146,   234,   137,   248,   158,   138,   163,   228,
     306,   134,   135,   303,   303,   171,   302,   304,   130,     8,
     136,   137,    50,     9,   138,   132,     8,   134,   135,    50,
       9,   309,   185,    61,   224,    12,   252,   305,   134,   135,
      61,   239,   161,   134,   135,   247,   311,   136,   320,   321,
     293,   255,   333,   324,   316,   326,   250,    62,   134,   135,
     318,   256,   137,   269,    14,   138,   260,    50,    50,   134,
     135,    14,    50,    66,    50,    50,    67,    68,   175,   176,
     335,   322,   216,   328,   251,   289,   134,   135,   263,     6,
       8,   265,    32,    33,     9,   294,   343,   297,     7,    50,
     177,   178,   298,    84,    61,     8,   290,   299,    86,     9,
     327,   300,   134,   135,   312,    50,   310,   338,   322,    10,
      11,    12,     6,    35,   313,    32,    33,   155,   156,   157,
     315,     7,   242,   243,   317,    14,   159,   160,     8,   325,
      90,   334,     9,   336,   164,   134,   135,   337,    13,   341,
      14,   262,    10,    34,    12,     6,    35,   233,    32,    33,
      30,    31,    15,   192,     7,   258,   259,    47,    37,    16,
     295,     8,   339,   307,   223,     9,   340,   241,   244,    54,
       0,    13,     0,    14,     0,    10,    11,    12,     0,    35,
       0,    36,     0,     0,    17,    15,     0,     0,     0,     0,
       0,    37,    16,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    15,     0,
       0,     0,     0,     0,    37,    16,     6,     0,   101,    32,
      33,     0,    18,     0,     0,     7,     0,    19,     0,     0,
       0,     0,     8,     0,   219,     0,     9,     0,     0,     0,
      17,     0,     0,     0,     0,     0,    10,    11,    12,     0,
       0,     0,     6,     0,    66,    18,     0,    67,    68,     0,
      38,     7,     0,   220,     0,     0,     0,     0,     8,     0,
       6,   150,     9,    32,    33,    13,     0,    14,     0,     7,
       0,     0,    10,    11,    12,     0,     8,     0,     6,    15,
       9,    32,    33,    19,     0,     0,   221,     7,     0,     0,
      10,    11,    12,     0,     8,     0,     0,     0,     9,     0,
       0,    13,     0,    14,     0,     0,     0,     0,    10,    11,
      12,    17,     0,     0,     6,    15,     0,    32,    33,    13,
       0,    14,    16,     7,     0,     0,    18,     0,     0,     0,
       8,     0,     0,    15,     9,     0,     6,    13,     0,    14,
      16,     0,     0,     0,    10,    34,    12,    17,     0,     0,
       0,    15,     8,     0,     0,     0,     9,     0,    16,     0,
       0,     0,    18,     0,    19,    17,    10,    11,    12,     0,
       0,     0,     6,    13,     0,    14,     0,     0,     0,     0,
      18,     7,     0,    17,     0,     0,     0,    15,     8,     0,
       0,     0,     9,     0,    16,    13,     0,    14,    18,     0,
      19,     0,    10,    11,    12,     0,    84,     0,    85,    15,
       0,    86,     0,     0,     0,     0,    16,     0,    19,    17,
       0,     0,     0,    87,    88,    89,    35,     0,     0,     0,
       0,    13,     0,    14,    18,     0,    19,     0,     0,     0,
       0,    17,     0,    90,     0,    15,     0,     0,     0,     0,
       0,     0,    16,     0,   194,   195,    18,    91,    92,    93,
      94,    36,    95,    96,    97,     0,    98,     0,    99,     0,
       0,    37,    38,     0,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,    18,     0,    19,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    37,   100,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   211,     0,     0,     0,     0,   212,     0,     0,     0,
     213,     0,     0,     0,     0,     0,   214,     0,     0,     0,
     215
};

static const yytype_int16 yycheck[] =
{
       6,     6,    12,    79,   162,     6,   126,    16,    10,    38,
     130,     6,    25,     8,     9,    41,     3,    21,    41,    10,
      11,    67,    26,     4,    34,    18,    10,     1,     0,    10,
      11,    36,    57,    20,    24,    19,     4,    41,    19,   105,
      14,     7,    10,    25,   110,    32,    33,   113,     8,   115,
      24,    57,   118,    62,     1,    10,    11,    23,    21,    19,
      86,    27,    57,    86,    57,    60,    91,    14,     1,    64,
      65,    37,    44,    39,    87,    22,    99,    87,    88,     7,
      61,    14,   184,    64,   186,    91,    91,    92,   190,    94,
      95,   193,   105,    84,    19,    85,    91,    99,    99,     7,
      66,    56,    68,   128,   224,    87,   101,     9,   133,   114,
      12,    85,   117,   138,   120,   217,     7,     1,    99,   114,
     125,    87,   128,   189,    67,   120,   131,   133,    53,    84,
      14,   126,   138,   291,     9,   140,   165,    12,   133,   144,
     145,   136,    23,   219,     8,   140,    27,   134,   135,   144,
     145,   161,   156,    10,    11,    19,    37,   208,    39,   210,
     211,    45,    15,   214,   215,   267,     7,     4,    70,    71,
       1,    28,    23,    10,    11,    29,    27,   202,   203,   204,
      61,   206,    19,    14,     4,    22,    37,    68,    39,     8,
      10,    11,     8,    24,    17,   220,   202,   203,   204,    19,
     206,   196,   197,   198,   199,   200,   201,   212,    10,    11,
      99,     8,   221,   208,   220,   210,   211,    68,    25,   214,
     215,    18,    24,   248,    61,     4,    22,    64,    68,   224,
     255,    10,    11,   242,   243,   165,   242,   243,    19,    23,
      19,    61,   248,    27,    64,    10,    23,    10,    11,   255,
      27,   256,    82,    37,    29,    39,    19,   252,    10,    11,
      37,    62,    39,    10,    11,    22,   261,    19,   293,   294,
      54,    20,    19,   298,   269,   300,     8,    61,    10,    11,
     290,    99,    61,     4,    68,    64,    19,   293,   294,    10,
      11,    68,   298,     9,   300,   301,    12,    13,    38,    39,
     325,   296,   307,   308,     8,    22,    10,    11,    45,     7,
      23,    23,    10,    11,    27,    54,   341,     8,    16,   325,
      38,    39,    19,    21,    37,    23,    39,    63,    26,    27,
       8,    65,    10,    11,    24,   341,   165,   332,   333,    37,
      38,    39,     7,    41,    24,    10,    11,    66,    67,    68,
      24,    16,    10,    11,    23,    68,    75,    76,    23,    64,
      58,    99,    27,     9,    83,    10,    11,    23,    66,    65,
      68,   182,    37,    38,    39,     7,    41,   132,    10,    11,
       4,     5,    80,   114,    16,   168,   169,     6,    86,    87,
     224,    23,   333,   255,   120,    27,   334,   140,   144,     7,
      -1,    66,    -1,    68,    -1,    37,    38,    39,    -1,    41,
      -1,    76,    -1,    -1,   112,    80,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    80,    -1,
      -1,    -1,    -1,    -1,    86,    87,     7,    -1,   156,    10,
      11,    -1,   127,    -1,    -1,    16,    -1,   165,    -1,    -1,
      -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      -1,    -1,     7,    -1,     9,   127,    -1,    12,    13,    -1,
     165,    16,    -1,    54,    -1,    -1,    -1,    -1,    23,    -1,
       7,     8,    27,    10,    11,    66,    -1,    68,    -1,    16,
      -1,    -1,    37,    38,    39,    -1,    23,    -1,     7,    80,
      27,    10,    11,   165,    -1,    -1,    87,    16,    -1,    -1,
      37,    38,    39,    -1,    23,    -1,    -1,    -1,    27,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    37,    38,
      39,   112,    -1,    -1,     7,    80,    -1,    10,    11,    66,
      -1,    68,    87,    16,    -1,    -1,   127,    -1,    -1,    -1,
      23,    -1,    -1,    80,    27,    -1,     7,    66,    -1,    68,
      87,    -1,    -1,    -1,    37,    38,    39,   112,    -1,    -1,
      -1,    80,    23,    -1,    -1,    -1,    27,    -1,    87,    -1,
      -1,    -1,   127,    -1,   165,   112,    37,    38,    39,    -1,
      -1,    -1,     7,    66,    -1,    68,    -1,    -1,    -1,    -1,
     127,    16,    -1,   112,    -1,    -1,    -1,    80,    23,    -1,
      -1,    -1,    27,    -1,    87,    66,    -1,    68,   127,    -1,
     165,    -1,    37,    38,    39,    -1,    21,    -1,    23,    80,
      -1,    26,    -1,    -1,    -1,    -1,    87,    -1,   165,   112,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    66,    -1,    68,   127,    -1,   165,    -1,    -1,    -1,
      -1,   112,    -1,    58,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,     5,     6,   127,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    83,    -1,
      -1,    86,   165,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,   127,    -1,   165,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    86,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
     151
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   190,     0,    44,   191,   193,     7,    16,    23,    27,
      37,    38,    39,    66,    68,    80,    87,   112,   127,   165,
     195,   231,   234,   235,   236,   237,   238,   242,     1,    14,
     192,   192,    10,    11,    38,    41,    76,    86,   165,   195,
     200,   201,   207,   208,   209,   211,   214,   221,   222,   230,
     234,   239,   240,   241,   242,   211,   211,    21,   199,   199,
       7,    37,    61,   237,     7,     7,     9,    12,    13,   195,
      21,    26,    41,   156,   232,     9,    12,    70,    71,    25,
      87,   105,    67,    15,    21,    23,    26,    38,    39,    40,
      58,    72,    73,    74,    75,    77,    78,    79,    81,    83,
     151,   156,   165,   194,   196,   197,   198,   201,   202,   204,
     205,   206,   207,   212,   213,   215,   221,   224,   225,   226,
     229,   195,   195,   199,   207,     7,    29,     8,    19,     8,
      19,     4,    10,     4,    10,    11,    19,    61,    64,     8,
      18,     8,     8,   233,    17,    99,    24,    28,   200,   211,
       8,   211,   237,   211,   211,   236,   236,   236,    22,   236,
     236,    39,   231,    68,   236,   199,   199,   200,   207,   211,
     207,   165,   220,   207,   207,    38,    39,    38,    39,   201,
     211,   227,   192,   203,   194,    82,   194,    24,    85,   216,
     194,   211,   214,   194,     5,     6,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    60,
      69,   132,   137,   141,   147,   151,   207,   194,   228,    25,
      54,    87,   211,   230,    29,   207,   209,   210,   211,   200,
     211,   209,   207,   208,   200,   211,   195,   195,   211,    62,
     200,   239,    10,    11,   240,   207,   211,    22,     4,    22,
       8,     8,    19,   199,   232,    20,    99,   219,   219,   219,
      19,    53,   196,    45,   203,    23,   203,   194,   203,     4,
      57,   203,   211,   211,   211,   211,   211,   211,   200,   200,
     200,   200,   227,   227,   227,   207,   227,   227,   203,    22,
      39,   231,   200,    54,    54,   210,    19,     8,    19,    63,
      65,     7,   234,   237,   234,   211,   200,   224,    99,   207,
     165,   211,    24,    24,   203,    24,   211,    23,   199,   232,
     200,   200,   211,   223,   200,    64,   200,     8,   207,    56,
      84,   217,   218,    19,    99,   200,     9,    23,   211,   223,
     233,    65,    84,   200
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   189,   190,   190,   191,   192,   192,   193,   193,   193,
     194,   194,   194,   195,   195,   195,   195,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   197,
     198,   198,   199,   199,   199,   200,   200,   200,   200,   201,
     201,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   203,   203,   204,   205,   206,   206,   207,   207,
     208,   208,   209,   209,   210,   210,   211,   211,   211,   211,
     211,   212,   213,   214,   214,   215,   216,   217,   217,   218,
     218,   219,   219,   219,   220,   220,   221,   222,   222,   223,
     223,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   225,   226,
     226,   226,   226,   227,   227,   228,   229,   229,   229,   230,
     230,   231,   231,   231,   232,   232,   232,   232,   233,   233,
     233,   234,   234,   234,   234,   234,   235,   235,   235,   235,
     235,   236,   236,   236,   237,   237,   237,   237,   238,   238,
     238,   239,   239,   240,   240,   240,   241,   241,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     5,     1,     1,     1,     2,     3,
       0,     1,     3,     1,     3,     3,     3,     1,     4,     1,
       1,     1,     1,     4,     1,     4,     2,     2,     2,     1,
       1,     4,     0,     3,     3,     1,     5,     8,     7,     1,
       3,     3,     3,     3,     1,     2,     1,     2,     2,     2,
       2,     2,     0,     1,     4,     3,     3,     4,     1,     3,
       1,     2,     4,     3,     1,     1,     1,     2,     2,     3,
       3,     4,     1,     1,     3,     6,     1,     1,     3,     1,
       2,     0,     2,     3,     1,     3,     2,     3,     5,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     2,     3,     3,     4,     4,     1,     1,     2,
       1,     3,     1,     0,     1,     2,     2,     4,     4,     3,
       2,     2,     3,     1,     1,     1,     1,     2,     0,     3,
       3,     3,     5,     1,     3,     3,     1,     2,     2,     3,
       1,     1,     2,     3,     2,     2,     4,     4,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     1,     3,     3,
       1,     2,     1,     3,     2,     2,     2,     3,     4,     4,
       6,     3,     3
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
#line 396 "dpic.y" /* yacc.c:1646  */
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
#line 412 "dpic.y" /* yacc.c:1646  */
    { if (envblock != NULL ) { getnesw(envblock->son);
#ifdef DDEBUG
	      if (debuglevel > 0) {
            snaptree(envblock->son,0);
		    fprintf(log_, " Global dimensions:\n");
            fprintf(log_, "(n,s)(e,w)=");
		    wpair(&log_, north, south); wpair(&log_, east, west);
		    fprintf(log_, " envblock<>nil:%s\n",
              (envblock != NULL) ? " TRUE" : "FALSE"); fflush(log_); }
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
	      else if ((envblock != NULL) &&
	        ((drawmode == SVG) || (drawmode == PDF) || (drawmode == PS))) {
							/* linethick/2 in drawing units*/
		    r = (envblock->envinx(Xlinethick) / 2 / 72)
                * envblock->envinx(Xscale);
#ifdef DDEBUG
		    if (debuglevel > 0) {
			  fprintf(log_,     " west="); wfloat(&log_, west);
			  fprintf(log_,     " south="); wfloat(&log_, south);
			  fprintf(log_,     " r="); wfloat(&log_, r);
			  fprintf(log_,     " shift=("); wfloat(&log_, r-west);
              putc(',', log_);
			  wfloat(&log_,     r - south);
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
#line 2012 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 489 "dpic.y" /* yacc.c:1646  */
    { yyerrok; /* yyclearin; */ }
#line 2018 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 493 "dpic.y" /* yacc.c:1646  */
    { dostart(); (yyval).xval = 0; (yyval).yval = 0;}
#line 2024 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 496 "dpic.y" /* yacc.c:1646  */
    { dostart(); (yyval).xval = (yyvsp[0]).xval; (yyval).yval = 0; }
#line 2030 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 499 "dpic.y" /* yacc.c:1646  */
    { dostart(); (yyval).xval = (yyvsp[-1]).xval; (yyval).yval = (yyvsp[0]).xval; }
#line 2036 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 505 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[0]).prim != NULL) && ((yyvsp[0]).lexval != Xcontinue)) {
            queueprim( (yyvsp[0]).prim, envblock ); }
#ifdef DDEBUG
          if (debuglevel > 0 ) { snaptree(envblock->son,0); }
#endif
    	  }
#line 2047 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 513 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[0]).prim != NULL) && ((yyvsp[0]).lexval != Xcontinue)) {
            queueprim( (yyvsp[0]).prim, envblock ); }
#ifdef DDEBUG
          if (debuglevel > 0 ) { snaptree(envblock->son,0); }
#endif
		  }
#line 2058 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 524 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval * (yyvsp[0]).xval; }
#line 2064 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 527 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { markerror(852); (yyval).xval = 0.0; }
    		else { (yyval).xval = (yyvsp[-2]).xval / (yyvsp[0]).xval; }
		  }
#line 2072 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 532 "dpic.y" /* yacc.c:1646  */
    { i = Rnd((yyvsp[-2]).xval);
    	  j = Rnd((yyvsp[0]).xval);
    	  if (j == 0) { markerror(852); (yyval).xval = 0.0; }
    	  else { (yyval).xval = i - ((i / j) * j); }
		  }
#line 2082 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 540 "dpic.y" /* yacc.c:1646  */
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
#line 2132 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 587 "dpic.y" /* yacc.c:1646  */
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
#line 2159 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 613 "dpic.y" /* yacc.c:1646  */
    { envblock->direction = (yyvsp[0]).lexval; }
#line 2165 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 616 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, XLaTeX, envblock);
    	  newstr(&(yyval).prim->textp);
    	  storestring((yyval).prim->textp, chbuf, (yyvsp[0]).chbufx, (yyvsp[0]).toklen, 1);
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen);
		  }
#line 2175 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 625 "dpic.y" /* yacc.c:1646  */
    { envblock->here_.xpos = (yyvsp[-3]).xval;
    	  envblock->here_.ypos = (yyvsp[-3]).yval;
    	  if (((yyvsp[-3]).state == Xright) || ((yyvsp[-3]).state == Xleft) ||
			  ((yyvsp[-3]).state == Xdown) || ((yyvsp[-3]).state == Xup)) {
			envblock->direction = (yyvsp[-3]).state; }
#ifdef DDEBUG
          if (debuglevel>1) { prattribute("element7", &(yyval)); }
#endif
		  }
#line 2189 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 642 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
			newprim(&(yyval).prim, XLaTeX, envblock);
			(yyval).prim->textp = (yyvsp[0]).prim->textp;
			(yyvsp[0]).prim->textp = NULL;
			if (envblock->son == (yyvsp[0]).prim) { envblock->son = (yyval).prim; }
			deletestringbox(&(yyvsp[0]).prim);
			}
		  }
#line 2202 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 652 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim == NULL) { }
          else if ((yyvsp[0]).prim->textp == NULL) { }
          else if ((yyvsp[0]).prim->textp->segmnt != NULL) {
			With4 = (yyvsp[0]).prim->textp;
			newbuf(&lastm);      /* Temp buffer; put nlch into inbuf */
			lastm->carray[1] = nlch;
			lastm->savedlen = 1;
			copyleft(lastm, &inbuf, -1);
			FORLIM = With4->len;
	                  /*  Copy string to lastm then to inbuf */
			for (i = 1; i <= FORLIM; i++) {
			  lastm->carray[i] = With4->segmnt[With4->seginx + i - 1]; }
			lastm->savedlen = With4->len;
			copyleft(lastm, &inbuf, -1);
						  /*  Add nlch in inbuf */
			lastm->carray[1] = nlch;
			lastm->savedlen = 1;
			copyleft(lastm, &inbuf, -1);
			deletestringbox(&(yyvsp[0]).prim);
			disposebufs(&lastm); }
		  }
#line 2228 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 676 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = envblock->here_.xpos;
    	  (yyval).yval = envblock->here_.ypos;
    	  (yyval).state = envblock->direction; }
#line 2236 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 682 "dpic.y" /* yacc.c:1646  */
    { donamedobj(&(yyval)); }
#line 2242 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 685 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
		    if ((yyvsp[-2]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-3]).chbufx,
                  &(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval); }
			primp = findplace(envblock->son, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
			if (primp != NULL) {
	    	  (yyvsp[0]).prim->name = primp->name;
	    	  primp->name = NULL; }
			else {
	    	  With2 = (yyvsp[0]).prim;
	    	  newstr(&With2->name);
	    	  storestring(With2->name, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, 1); }
			(yyval) = (yyvsp[0]);
			donamedobj(&(yyval));
			}
		  clearchbuf((yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
		  }
#line 2263 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 704 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 2269 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 707 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).xval > maxint) { markerror(875); fatal(8); }
          else { (yyval).xval = (yyvsp[-1]).xval; } }
#line 2276 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 711 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = Xcomma;
    	  (yyval).xval = (yyvsp[-1]).xval;
    	  (yyval).yval = (yyvsp[-1]).yval;
    	  if ((fabs((yyvsp[-1]).xval) > maxint) || (fabs((yyvsp[-1]).yval) > maxint)) {
            markerror(875); fatal(8);}
		  }
#line 2287 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 720 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2293 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 723 "dpic.y" /* yacc.c:1646  */
    { r = (yyvsp[-4]).xval;
    	  (yyval).xval = (yyvsp[-2]).xval + (r * ((yyvsp[0]).xval - (yyvsp[-2]).xval));
    	  (yyval).yval = (yyvsp[-2]).yval + (r * ((yyvsp[0]).yval - (yyvsp[-2]).yval)); }
#line 2301 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 729 "dpic.y" /* yacc.c:1646  */
    {
    	  r = (yyvsp[-7]).xval;
    	  (yyval).xval = (yyvsp[-2]).xval + (r * ((yyvsp[0]).xval - (yyvsp[-2]).xval));
    	  (yyval).yval = (yyvsp[-2]).yval + (r * ((yyvsp[0]).yval - (yyvsp[-2]).yval)); }
#line 2310 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 736 "dpic.y" /* yacc.c:1646  */
    { r = (yyvsp[-6]).xval;
    	  (yyval).xval = (yyvsp[-4]).xval + (r * ((yyvsp[-2]).xval - (yyvsp[-4]).xval));
    	  (yyval).yval = (yyvsp[-4]).yval + (r * ((yyvsp[-2]).yval - (yyvsp[-4]).yval));
		  if ((yyvsp[-1]).lexval != Xgt) { markerror(869); }
		  else if ((yyvsp[0]).lexval != XEMPTY) {
	   	    (yyval).xval += (yyvsp[0]).xval;
	   	    (yyval).yval += (yyvsp[0]).yval;
			}
		  }
#line 2324 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 750 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; }
#line 2330 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 754 "dpic.y" /* yacc.c:1646  */
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
#line 2345 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 766 "dpic.y" /* yacc.c:1646  */
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
#line 2361 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 779 "dpic.y" /* yacc.c:1646  */
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
#line 2380 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 795 "dpic.y" /* yacc.c:1646  */
    { resetenv(0, envblock); }
#line 2386 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 802 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
#ifdef SAFE_MODE
			markerror(901);
#else
			pointinput((yyvsp[0]).prim->textp);
#endif
			deletestringbox(&(yyvsp[0]).prim);
    		}
		  }
#line 2400 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 813 "dpic.y" /* yacc.c:1646  */
    { currprod = 4;
          (yyval) = (yyvsp[0]);
		  dodefhead( &(yyval) );
          }
#line 2409 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 819 "dpic.y" /* yacc.c:1646  */
    { currprod = 5;
          (yyval) = (yyvsp[0]);
		  dodefhead( &(yyval) );
          }
#line 2418 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 826 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); doundefine( &(yyvsp[0]) );
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen); }
#line 2425 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 830 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); doundefine( &(yyvsp[0]) );
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen); }
#line 2432 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 843 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval == 1.0) { currprod = 1; skiptobrace(); } }
#line 2438 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 847 "dpic.y" /* yacc.c:1646  */
    { forattr = (yyval);
#ifdef DDEBUG
		  if (debuglevel>0) prattribute("for1",&(yyval));
#endif
		  }
#line 2448 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 854 "dpic.y" /* yacc.c:1646  */
    { forattr = (yyval); }
#line 2454 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 858 "dpic.y" /* yacc.c:1646  */
    {
#ifdef DDEBUG
		  if (debuglevel>0) {
			prattribute("stringexpr1",&(yyval));
            printobject((yyval).prim);
  			fflush(log_); }
#endif
		  }
#line 2467 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 868 "dpic.y" /* yacc.c:1646  */
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
			  putbval((yyval).prim->textp->segmnt,bval((yyvsp[-2]).prim->textp->segmnt)-1);
			  prp->textp->segmnt = NULL;
    		  }
    		else { appendstring((yyval).prim->textp, prp->textp->segmnt,
		        prp->textp->seginx, prp->textp->len); }
		  }
		deletetree(&(yyvsp[0]).prim); }
		}
#line 2490 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 889 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, Xstring, envblock);
		  eb = findenv(envblock);
		  With2 = (yyval).prim;
		  With2->boxheight_ = eb->envinx(Xtextht);
		  With2->boxwidth_ = eb->envinx(Xtextwid);
		  if (With2->boxwidth_ == 0.0) {
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
		  newstr(&With2->textp);
		  storestring(With2->textp, chbuf, (yyvsp[0]).chbufx, (yyvsp[0]).toklen, 1);
#ifdef DDEBUG
		  if (debuglevel>1) {
            prattribute("string1",&(yyval));
            printobject((yyval).prim);
  			fflush(log_); }
#endif
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen);
		  }
#line 2524 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 924 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-3]).chbufx,
                &(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval); }
		    (yyval).varname = findname(envblock, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen,
			     &lastvar, &k);
		    if (((yyval).varname == NULL) && ((yyvsp[-1]).lexval != Xeq)) {
			  (yyval).varname = glfindname(envblock->parent, chbuf,
				 (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, &namptr, &kk); }
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
			With2 = envblock;
			if (lastvar == NULL) { With2->blockparms.vars[j] = (yyval).varname; }
			else if (k < 0) {
			  if (With2->blockparms.vars[j]->nextname == NULL) {
			    With2->blockparms.vars[j]->nextname = (yyval).varname; }
			  else {
				(yyval).varname->nextname = lastvar->nextname;
				lastvar->nextname = (yyval).varname; }
			    }
			else if (lastvar == With2->blockparms.vars[j]) {
			  (yyval).varname->nextname = With2->blockparms.vars[j];
			  With2->blockparms.vars[j] = (yyval).varname; }
			else {
			  namptr = With2->blockparms.vars[j];
							/* while (namptr^.next<>nil) and
							   (namptr^.next<>lastvar) do */
			  while (namptr->nextname != lastvar) { namptr = namptr->nextname; }
			  namptr->nextname = (yyval).varname;
			  (yyval).varname->nextname = lastvar;
			  }
			With2->blockparms.nvars[j]++;
			(yyval).varname->val = 0.0;
		    }
		  if ((yyvsp[-1]).lexval == Xeq) { (yyval).varname->val = (yyvsp[0]).xval; }
		  else { eqop(&(yyval).varname->val, (yyvsp[-1]).lexval, (yyvsp[0]).xval); }
		  (yyval).xval = (yyval).varname->val;

		  clearchbuf((yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
          }
#line 2581 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 978 "dpic.y" /* yacc.c:1646  */
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
#line 2610 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1012 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; }
#line 2616 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1015 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = -(yyvsp[0]).xval; }
#line 2622 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1018 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval + (yyvsp[0]).xval; }
#line 2628 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1021 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval - (yyvsp[0]).xval; }
#line 2634 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1025 "dpic.y" /* yacc.c:1646  */
    { inlogic = false;
    	  (yyval).xval = (yyvsp[-2]).xval;
    	  if ((yyval).xval == 0.0) {
		    currprod = 2 /* ifhead1 */;
		    skiptobrace();
    	    }
		  }
#line 2646 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1035 "dpic.y" /* yacc.c:1646  */
    { inlogic = true; }
#line 2652 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1041 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval != 0.0) || ((yyvsp[0]).xval != 0.0)) { (yyval).xval = 1.0; }
    	  else { (yyval).xval = 0.0; }
		  }
#line 2660 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1047 "dpic.y" /* yacc.c:1646  */
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
#line 2711 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1096 "dpic.y" /* yacc.c:1646  */
    { (yyval) = forattr;
	    With1 = &(yyval);
#ifdef DDEBUG
		if (debuglevel>1) prattribute("forincr1 $$",&(yyval));
#endif
	    if (With1->varname != NULL) { With1->xval = With1->varname->val; }
	    else { With1->xval = envblock->envinx(With1->startchop); }
	    bswitch = false;
	    if (With1->toklen < 0) {
		  if (With1->yval == 0) { bswitch = true; }
		  else {
		    With1->xval += With1->yval;
		    if (((With1->yval > 0) && (With1->xval > With1->endchop)) ||
			    ((With1->yval < 0) && (With1->xval < With1->endchop))) {
			  bswitch = true; }
		    }
	      }
	    else if (With1->xval == 0) { bswitch = true; }
	    else {
		  With1->xval *= With1->yval;
		  if (((fabs(With1->yval) >= 1.0) &&
		     (fabs(With1->xval) > fabs(With1->endchop))) ||
		    ((fabs(With1->yval) < 1.0) &&
		     (fabs(With1->xval) < fabs(With1->endchop)))) { bswitch= true; }
	      }
	    if (With1->varname != NULL) { With1->varname->val = With1->xval; }
	    else if ((Rnd(With1->startchop)) != Xscale) {
		  envblock->envinx(With1->startchop)= With1->xval; }
	    else { resetscale(With1->xval, Xeq, envblock); }
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
#line 2755 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1138 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 1.0; }
#line 2761 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1141 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 2767 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1147 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = (yyvsp[0]).lexval; }
#line 2773 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1151 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 2779 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1154 "dpic.y" /* yacc.c:1646  */
    { With1 = &(yyvsp[0]);
		  (yyval).state = 1;
		  bswitch = false;
		  if (With1->prim != NULL) {
			if (With1->prim->textp == NULL) { markerror(861); }
			else if ((yyvsp[-1]).lexval != Xgt) { markerror(869); }
			else if (safemode) { markerror(901); }
			else { bswitch = true; }
		    }
#ifdef SAFE_MODE
		  if (bswitch) { markerror(901); }
#else
		  if (bswitch) { pointoutput(true,With1->prim->textp, &(yyval).state); }
#endif
		  deletestringbox(&With1->prim);
		  }
#line 2800 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1172 "dpic.y" /* yacc.c:1646  */
    { With1 = &(yyvsp[0]);
		  (yyval).state = 1;
		  bswitch = false;
		  if (With1->prim != NULL) {
			if (With1->prim->textp == NULL) { markerror(861); }
			else if (((yyvsp[-2]).lexval != Xgt) || ((yyvsp[-1]).lexval != Xgt)) {
			    markerror(869); }
			else if (safemode) { markerror(901); }
			else { bswitch = true; }
		    }
#ifdef SAFE_MODE
		  if (bswitch) { markerror(901); }
#else
		  if (bswitch) { pointoutput(false, With1->prim->textp, &(yyval).state); }
#endif
		  deletestringbox(&With1->prim);
		  }
#line 2822 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1192 "dpic.y" /* yacc.c:1646  */
    { resetenv((yyvsp[0]).lexval, envblock); }
#line 2828 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1195 "dpic.y" /* yacc.c:1646  */
    { resetenv((yyvsp[0]).lexval, envblock); }
#line 2834 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1199 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = -1.0;
	      With1 = &(yyvsp[0]);
	      if (With1->prim != NULL) {
		    if (With1->prim->textp != NULL) {
		      With4 = With1->prim->textp;
		      if (With4->segmnt != NULL) {
			    if (With4->seginx + With4->len >= CHBUFSIZ) {markerror(866); }
			    else if (safemode) { markerror(901); }
#ifndef SAFE_MODE
			    else {
			      With4->segmnt[With4->seginx + With4->len] = '\0';
			      (yyval).xval = system(&With4->segmnt[With4->seginx]); }
#endif
		        }
		      }
		    deletestringbox(&With1->prim);
	        }
#ifdef DDEBUG
		  if (debuglevel>1) { prattribute("systemcmd1",&(yyval)); }
#endif
		  }
#line 2860 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1223 "dpic.y" /* yacc.c:1646  */
    { dosprintf( &(yyval), &(yyvsp[0]), &(yyvsp[0]), 0 ); }
#line 2866 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1226 "dpic.y" /* yacc.c:1646  */
    { dosprintf( &(yyval), &(yyvsp[-2]), &(yyvsp[0]), (yyvsp[0]).state ); }
#line 2872 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1230 "dpic.y" /* yacc.c:1646  */
    { (yyval).state = 1; }
#line 2878 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1233 "dpic.y" /* yacc.c:1646  */
    { (yyval).state = (yyvsp[0]).state + 1; }
#line 2884 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1239 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			switch (With2->ptype) {
			  case Xbox:
			  case Xblock:
			    if (With2->ptype == Xblock) {
			      r = 0.5 * ((yyvsp[0]).xval - With2->blockheight_);
			      With2->blockheight_ = (yyvsp[0]).xval; }
			    else {
			      r = 0.5 * ((yyvsp[0]).xval - With2->boxheight_);
			      With2->boxheight_ = (yyvsp[0]).xval; }
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (With2->direction) {
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
	  			With2->boxheight_ = (yyvsp[0]).xval;
	  			if ((drawmode == PDF) && (With2->textp != NULL)) {
	      		  With2->boxwidth_ = With2->boxheight_ *
					With2->textp->len * 0.6;
	  			  }
	  			break;
			  case Xcircle:
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (With2->direction) {
			        case Xleft:
			        case Xright:
				      break; /* blank case */
			        case Xup:
				      With2->aat.ypos += (0.5 * (yyvsp[0]).xval) - With2->circleradius_;
				      break;
			        case Xdown:
				      With2->aat.ypos += With2->circleradius_ - (0.5 * (yyvsp[0]).xval);
				      break;
			        }
			      }
			    With2->circleradius_ = (yyvsp[0]).xval * 0.5;
			    break;
			  case Xellipse:
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (With2->direction) {
			        case Xleft:
			        case Xright:
				      break; /* blank case */
			        case Xup:
				      With2->aat.ypos +=
				        0.5 * ((yyvsp[0]).xval - With2->ellipseheight_);
				      break;
			        case Xdown:
				      With2->aat.ypos +=
				        0.5 * (With2->ellipseheight_ - (yyvsp[0]).xval);
				      break;
			        }
			      }
			    With2->ellipseheight_ = (yyvsp[0]).xval;
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
#line 2973 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1325 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			switch (With2->ptype) {
			  case Xbox:
			  case Xblock:
			    if (With2->ptype == Xblock) {
			      r = 0.5 * ((yyvsp[0]).xval - With2->blockwidth_);
			      With2->blockwidth_ = (yyvsp[0]).xval; }
			  else {
			      r = 0.5 * ((yyvsp[0]).xval - With2->boxwidth_);
			      With2->boxwidth_ = (yyvsp[0]).xval; }
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
			    switch (With2->direction) {
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
			  With2->boxwidth_ = (yyvsp[0]).xval;
			  break;
			case Xcircle:
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
			    switch (With2->direction) {
			      case Xup:
			      case Xdown:
				    break; /* blank case */
			      case Xright:
				    With2->aat.xpos += (0.5 * (yyvsp[0]).xval) - With2->circleradius_;
				    break;
			      case Xleft:
				    With2->aat.xpos += With2->circleradius_ - (0.5 * (yyvsp[0]).xval);
				    break;
			      }
			    }
			  With2->circleradius_ = (yyvsp[0]).xval * 0.5;
			  break;
			case Xellipse:
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
			    switch (With2->direction) {
			      case Xup:
			      case Xdown:
				    break; /* blank case */
			      case Xright:
				    With2->aat.xpos += 0.5 * ((yyvsp[0]).xval - With2->ellipsewidth_);
				    break;
			      case Xleft:
				    With2->aat.xpos += 0.5 * (With2->ellipsewidth_ - (yyvsp[0]).xval);
				    break;
			      }
			    }
			  With2->ellipsewidth_ = (yyvsp[0]).xval;
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
#line 3056 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1405 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			switch (With2->ptype) {
			  case Xbox:
			    With2->boxradius_ = (yyvsp[0]).xval;
			    break;
			  case Xarc:
			    t = (yyvsp[0]).xval;
			    if (With2->direction == 0) {
			      (yyvsp[0]).xval = With2->aat.xpos + (With2->aradius_ *
                    cos( With2->startangle_ + With2->arcangle_));
			      (yyvsp[0]).yval = With2->aat.ypos + (With2->aradius_ *
                    sin( With2->startangle_ + With2->arcangle_));
			      r = cos(With2->startangle_);
			      s = sin(With2->startangle_);
			      With2->aat.xpos += With2->aradius_ * r;
			      With2->aat.ypos += With2->aradius_ * s;
			      With2->aradius_ = t;
			      With2->aat.xpos -= With2->aradius_ * r;
			      With2->aat.ypos -= With2->aradius_ * s;
			      setstflag(&(yyvsp[-2]).state, Xradius);
			      goto object_xx;
			      }
			    else {
			      r = cos(With2->startangle_);
			      s = sin(With2->startangle_);
			      (yyval).prim->aat.xpos += With2->aradius_ * r;
			      (yyval).prim->aat.ypos += With2->aradius_ * s;
			      (yyval).prim->aradius_ = t;
			      (yyval).prim->aat.xpos -= With2->aradius_ * r;
			      (yyval).prim->aat.ypos -= With2->aradius_ * s;
			      setstflag(&(yyval).state, Xradius);
				  }
			    break;
			  case Xcircle:
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (With2->direction) {
			        case Xleft:
				      With2->aat.xpos += With2->circleradius_ - (yyvsp[0]).xval;
				      break;
			        case Xright:
				      With2->aat.xpos += (yyvsp[0]).xval - With2->circleradius_;
				      break;
			        case Xup:
				      With2->aat.ypos += (yyvsp[0]).xval - With2->circleradius_;
				      break;
			        case Xdown:
				      With2->aat.ypos += With2->circleradius_ - (yyvsp[0]).xval;
				      break;
			        }
			      }
			    With2->circleradius_ = (yyvsp[0]).xval;
			    setstflag(&(yyvsp[-2]).state, Xradius);
			    break;
			  default:
			    markerror(858);
			    break;
			  }
		    }
		  }
#line 3121 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1467 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			if (With2->ptype == Xcircle) {
			  r = 0.5 * (yyvsp[0]).xval;
			  if (!teststflag((yyvsp[-2]).state, Xat)) {
				switch (With2->direction) {
				  case Xleft:
				    With2->aat.xpos += With2->circleradius_ - r;
				    break;
				  case Xright:
				    With2->aat.xpos += r - With2->circleradius_;
				    break;
				  case Xup:
				    With2->aat.ypos += r - With2->circleradius_;
				    break;
				  case Xdown:
				    With2->aat.ypos += With2->circleradius_ - r;
				    break;
				  }
			    }
			  With2->circleradius_ = r;
			  }
			else { markerror(858); }
		    }
		  }
#line 3151 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1494 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			if ((yyvsp[0]).xval < 0.0) {
			  eb = findenv(envblock);
			  With2->lthick = eb->envinx(Xlinethick);
			  }
			else { With2->lthick = (yyvsp[0]).xval; }
		    }
		  }
#line 3165 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1505 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).prim != NULL) && ((yyvsp[0]).lexval != XEMPTY)) {
			With2 = (yyval).prim;
			r = (yyvsp[0]).xval - 1;
			corner((yyvsp[-2]).prim, XDotc, &x1, &z1);
			switch (With2->ptype) {
			  case Xbox:
			  case Xblock:
			  case Xstring:
			    if (teststflag((yyvsp[-2]).state, Xat)) {
			      dx = 0.0;
			      dy = 0.0;
			      }
			    else if (With2->ptype == Xblock) {
			      dx = With2->blockwidth_ * r / 2;
			      dy = With2->blockheight_ * r / 2;
			      }
			    else {
			      dx = With2->boxwidth_ * r / 2;
			      dy = With2->boxheight_ * r / 2;
			      }
			    scaleobj((yyval).prim, (yyvsp[0]).xval);
			    switch (With2->direction) {
			      case Xright: shift(
                    (yyval).prim, x1 - With2->aat.xpos + dx, z1 - With2->aat.ypos);
			        break;
			      case Xleft: shift(
                    (yyval).prim, x1 - With2->aat.xpos - dx, z1 - With2->aat.ypos);
			        break;
			      case Xup: shift(
                    (yyval).prim, x1 - With2->aat.xpos, z1 - With2->aat.ypos + dy);
			        break;
			      case Xdown: shift(
                    (yyval).prim, x1 - With2->aat.xpos, z1 - With2->aat.ypos - dy);
			        break;
			      }
			    break;
			  case Xcircle:
			    With2->circleradius_ = (yyvsp[0]).xval * With2->circleradius_;
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (With2->direction) {
			        case Xup:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 + With2->circleradius_;
				      break;
			        case Xdown:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 - With2->circleradius_;
				      break;
			        case Xright:
				      With2->aat.xpos = x1 + With2->circleradius_;
				      With2->aat.ypos = z1;
				      break;
			        case Xleft:
				      With2->aat.xpos = x1 - With2->circleradius_;
				      With2->aat.ypos = z1;
				      break;
			        }
			      }
			    break;
			  case Xellipse:
			    With2->ellipsewidth_ *= (yyvsp[0]).xval;
			    With2->ellipseheight_ *= (yyvsp[0]).xval;
			    if (!teststflag((yyvsp[-2]).state, Xat)) {
			      switch (With2->direction) {
			        case Xup:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 + (With2->ellipseheight_ / 2);
				      break;
			        case Xdown:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 - (With2->ellipseheight_ / 2);
				      break;
			        case Xright:
				      With2->aat.xpos = x1 + (With2->ellipsewidth_ / 2);
				      With2->aat.ypos = z1;
				      break;
			        case Xleft:
				      With2->aat.xpos = x1 - (With2->ellipsewidth_ / 2);
				      With2->aat.ypos = z1;
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
			    corner((yyval).prim, XDotc, &r, &s);
			    shift((yyval).prim, x1 - r, z1 - s);
			    break;
			  case Xlabel:
			  case XLaTeX:
			    markerror(858);
			    break;
			  }
		    }
		  }
#line 3269 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1606 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			With2 = (yyval).prim;
			if ((With2->ptype == Xspline) || (With2->ptype == Xarrow) ||
			    (With2->ptype == Xmove) || (With2->ptype == Xline) ||
			    (With2->ptype == Xarc)) {
			  i = (yyvsp[-1]).lexval;
			  envblock->direction = i;
			  eb = findenv(envblock);
			  switch (With2->ptype) {
			    case Xarc:
			      r = cos(With2->startangle_);
			      s = sin(With2->startangle_);
			      With2->aat.xpos += With2->aradius_ * r;
			      With2->aat.ypos += With2->aradius_ * s;
				  nwi = With2->direction;
			      if (((nwi == Xup) && (i == Xleft)) ||
				      ((nwi == Xdown) && (i == Xright)) ||
				      ((nwi == Xright) && (i == Xup)) ||
				      ((nwi == Xleft) && (i == Xdown))) {
				    With2->arcangle_ = pi * 0.5; }
			      else if (((nwi == Xup) && (i == Xright)) ||
				      ((nwi == Xdown) && (i == Xleft)) ||
				      ((nwi == Xright) && (i == Xdown)) ||
				      ((nwi == Xleft) && (i == Xup))) {
				    With2->arcangle_ = (-pi) * 0.5; }
			      if ((yyvsp[0]).lexval != XEMPTY) {
				    With2->aradius_ = (yyvsp[0]).xval; }
			      With2->aat.xpos -= With2->aradius_ * r;
			      With2->aat.ypos -= With2->aradius_ * s;
			      With2->direction = i;
			      break;
			    case Xline:
			    case Xmove:
			    case Xarrow:
			    case Xspline:
			      With2->direction = i;
			      if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; s = r; }
			      else { switch (With2->ptype) {
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
#line 3334 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1668 "dpic.y" /* yacc.c:1646  */
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
#line 3358 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1689 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			if (((yyvsp[-2]).prim->ptype != Xspline) &&
			    ((yyvsp[-2]).prim->ptype != Xmove) &&
			    ((yyvsp[-2]).prim->ptype != Xarrow) && ((yyvsp[-2]).prim->ptype != Xline)) {
			  markerror(858); }
			else {
			  With2 = (yyvsp[-2]).prim;
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
#line 3384 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1712 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			if ((yyvsp[0]).lexval != XEMPTY) { s = (yyvsp[0]).xval; }
			else {
			  eb = findenv(envblock);
			  s = eb->envinx(Xfillval);
			  }
			prp = (yyval).prim;
			while (prp != NULL) {
			  switch (With2->ptype) {
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
				    switch (With2->ptype) {
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
#line 3432 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1757 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			With2 = (yyval).prim;
			if ((With2->ptype != Xspline) && (With2->ptype != Xarc) &&
			    (With2->ptype != Xarrow) && (With2->ptype != Xline)) {
			  markerror(858); }
			else {
			  With2->lineatype_ = pahlex(With2->lineatype_,(yyvsp[-1]).lexval);
			  if ((yyvsp[0]).lexval != XEMPTY) { lj = Rnd((yyvsp[0]).xval); }
			  else {
				eb = findenv(envblock);
				lj = (long)floor(eb->envinx(Xarrowhead)+0.5);
			    }
			  With2->lineatype_ = pahnum(With2->lineatype_, lj);
			  }
		    }
		  }
#line 3453 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1775 "dpic.y" /* yacc.c:1646  */
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
#line 3468 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1787 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			With2 = (yyvsp[-1]).prim;
			if (With2->ptype != Xarc) { markerror(858); }
			else {
			  if ((With2->arcangle_ > 0.0) && (With2->direction == 0)) {
				With2->arcangle_ = -fabs(
				  principal((2.0 * pi) - With2->arcangle_,2.0*pi));}
			  else if (With2->direction != 0) {
				With2->aat = arcstart((yyval).prim);
				switch (With2->direction) {
				  case Xup:
				    With2->aat.xpos += With2->aradius_;
				    break;
				  case Xdown:
				    With2->aat.xpos -= With2->aradius_;
				    break;
				  case Xleft:
				    With2->aat.ypos += With2->aradius_;
				    break;
				  case Xright:
				    With2->aat.ypos -= With2->aradius_;
				    break;
				  }
				if (With2->arcangle_ > 0.0) {
				  With2->startangle_ =
                    principal(With2->startangle_ + pi, pi); }
				  With2->arcangle_ = -fabs(With2->arcangle_);
			    }
			  setstflag(&(yyval).state, Xcw);
			  }
		    }
		  }
#line 3505 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1821 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			With2 = (yyvsp[-1]).prim;
			if (With2->ptype != Xarc) { markerror(858); }
			else {
			  if ((With2->arcangle_ < 0.0) && (With2->direction == 0)) {
				With2->arcangle_ =
                  fabs(principal(With2->arcangle_ - (2.0 * pi),2.0*pi)); }
			  else if (With2->direction != 0) {
				With2->aat = arcstart((yyvsp[-1]).prim);
				switch (With2->direction) {
				  case Xup: With2->aat.xpos -= With2->aradius_; break;
				  case Xdown: With2->aat.xpos += With2->aradius_; break;
				  case Xleft: With2->aat.ypos -= With2->aradius_; break;
				  case Xright: With2->aat.ypos += With2->aradius_; break;
				  }
				if (With2->arcangle_ < 0.0) {
				  With2->startangle_ =
                    principal( With2->startangle_ + pi, pi); }
				  With2->arcangle_ = fabs(With2->arcangle_);
			    }
			  setstflag(&(yyvsp[-1]).state, Xccw);
			  }
		    }
		  }
#line 3534 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1847 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			prp = nthprimobj(envblock->son, 0, (yyvsp[-1]).prim->ptype);
			if (prp == NULL) { markerror(857); }
			else {
			  With2 = (yyvsp[-1]).prim;
			  With2->lparam = prp->lparam;
			  With2->lthick = prp->lthick;
			  With2->direction = prp->direction;
			  With2->spec = prp->spec;
			  if (hasoutline((yyvsp[-1]).lexval, false)) {
				copystr(&With2->outlinep, prp->outlinep); }
			  if (hasshade((yyvsp[-1]).lexval, false)) {
				copystr(&With2->shadedp, prp->shadedp); }
			  }
			if (prp != NULL) {
			  With2 = (yyvsp[-1]).prim;
			  switch (With2->ptype) {
			    case Xbox:
			    case Xstring:
			      if (With2->ptype == Xbox) {
				    switch (With2->direction) {
				      case Xup:
				        With2->aat.ypos += 0.5 *
					      (prp->boxheight_ - With2->boxheight_);
				        break;
				      case Xdown:
				        With2->aat.ypos -= 0.5 *
					      (prp->boxheight_ - With2->boxheight_);
				        break;
				      case Xleft:
				        With2->aat.xpos -=
				          0.5 * (prp->boxwidth_ - With2->boxwidth_);
				        break;
				      case Xright:
				        With2->aat.xpos +=
				          0.5 * (prp->boxwidth_-With2->boxwidth_);
				        break;
				      }
			        }
			      With2->boxfill_ = prp->boxfill_;
			      With2->boxheight_ = prp->boxheight_;
			      With2->boxwidth_ = prp->boxwidth_;
			      With2->boxradius_ = prp->boxradius_;
			      break;
			    case Xblock:
			      markerror(858);
			      break;
			    case Xcircle:
			      switch (With2->direction) {
			        case Xup:
				      With2->aat.ypos +=
                        prp->circleradius_ - With2->circleradius_;
				      break;
			        case Xdown:
				      With2->aat.ypos +=
                        With2->circleradius_ - prp->circleradius_;
				      break;
			        case Xleft:
				      With2->aat.xpos +=
                        With2->circleradius_ - prp->circleradius_;
				      break;
			        case Xright:
				      With2->aat.xpos +=
                        prp->circleradius_ - With2->circleradius_;
				      break;
			        }
			      With2->circlefill_ = prp->circlefill_;
			      With2->circleradius_ = prp->circleradius_;
			      break;
			    case Xellipse:
			      switch (With2->direction) {
			        case Xup:
				      With2->aat.ypos +=
				        0.5 * (prp->ellipseheight_ - With2->ellipseheight_);
				      break;
			        case Xdown:
				      With2->aat.ypos -=
				        0.5 * (prp->ellipseheight_ - With2->ellipseheight_);
				      break;
			        case Xleft:
				      With2->aat.xpos -=
				        0.5 * (prp->ellipsewidth_ - With2->ellipsewidth_);
				      break;
			        case Xright:
				      With2->aat.xpos +=
				        0.5 * (prp->ellipsewidth_ - With2->ellipsewidth_);
				      break;
			        }
			      With2->ellipsefill_ = prp->ellipsefill_;
			      With2->ellipseheight_ = prp->ellipseheight_;
			      With2->ellipsewidth_ = prp->ellipsewidth_;
			      break;
			    case Xarc:
			      x1 = With2->aat.xpos +
                    (With2->aradius_ * cos(With2->startangle_));
			      z1 = With2->aat.ypos + 
                    (With2->aradius_ * sin(With2->startangle_));
			      With2->aradius_ = prp->aradius_;
			      With2->startangle_ = prp->startangle_;
			      With2->aat.xpos = x1 -
                    (With2->aradius_ * cos(With2->startangle_));
			      With2->aat.ypos = z1 -
                    (With2->aradius_ * sin(With2->startangle_));
			      With2->arcangle_ = prp->arcangle_;
			      break;
			    case Xline:
			    case Xarrow:
			    case Xmove:
			    case Xspline:
			      With2->endpos_.xpos =
				    With2->aat.xpos + prp->endpos_.xpos-prp->aat.xpos;
			      With2->endpos_.ypos =
				    With2->aat.ypos + prp->endpos_.ypos-prp->aat.ypos;
			      With2->lineheight_ = prp->lineheight_;
			      With2->linewidth_ = prp->linewidth_;
			      With2->lineatype_ = prp->lineatype_;
			      break;
			    case Xlabel:
			    case XLaTeX:
			      markerror(858);
			      break;
			    }
			  }
		    }
		  }
#line 3664 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1974 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
			if ((yyvsp[-1]).prim != NULL) {
			  With2 = (yyvsp[-1]).prim;
			  if (With2->textp == NULL) { With2->textp = (yyvsp[0]).prim->textp; }
			  else {
				namptr = With2->textp;
				i = 1;
				while (namptr->nextname != NULL) { namptr = namptr->nextname; i++; }
				namptr->nextname = (yyvsp[0]).prim->textp;
				if (With2->ptype == Xstring) {
				  if (drawmode == SVG) {
					eb = findenv(envblock);
					if (eb != NULL) {
					  r = findvar("dptextratio", 11);
					  if (r == 0) { r = 1.0; }
					  With2->boxheight_ += eb->envinx(Xtextht) / r;
					  }
				    }
				  else { With2->boxheight_ *= ((i + 1) / i); }
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
#line 3699 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 2006 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval)  = (yyvsp[-2]);
			if (((yyvsp[-2]).prim->ptype == Xmove) || ((yyvsp[-2]).prim->ptype == Xspline) ||
			  ((yyvsp[-2]).prim->ptype == Xarrow) || ((yyvsp[-2]).prim->ptype == Xline) ||
			  ((yyvsp[-2]).prim->ptype == Xarc)) {
			    With2 = (yyvsp[-2]).prim;
			    x1 = (yyvsp[0]).xval + With2->aat.xpos;
			    z1 = (yyvsp[0]).yval + With2->aat.ypos;
			    if (With2->ptype == Xarc) {
				  x1 += With2->aradius_ * cos(With2->startangle_);
				  z1 += With2->aradius_ * sin(With2->startangle_);
			      }
			    (yyvsp[0]).xval = x1;
			    (yyvsp[0]).yval = z1;
                goto object_xx;
			    }
			  else { markerror(858); }
		    }
		  }
#line 3723 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 2027 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyval).prim;
			if ((With2->ptype == Xmove) || (With2->ptype == Xspline) ||
			  (With2->ptype == Xarrow) || (With2->ptype == Xline) ||
              (With2->ptype == Xarc)) {
			    if (With2->ptype == Xarc) {
				 r = (yyvsp[0]).xval;
				 s = (yyvsp[0]).yval;
				if (teststflag((yyvsp[-2]).state, Xto)) {
				  (yyvsp[0]).xval = With2->aat.xpos + (With2->aradius_ *
                    cos( With2->startangle_ + With2->arcangle_));
				  (yyvsp[0]).yval = With2->aat.ypos + (With2->aradius_ *
                    sin( With2->startangle_ + With2->arcangle_));
				  }
				With2->aat.xpos = r -
                  (With2->aradius_ * cos(With2->startangle_));
				With2->aat.ypos = s -
                  (With2->aradius_ * sin(With2->startangle_));
				if (teststflag((yyvsp[-2]).state, Xto)) { goto object_xx; }
			    }
			  else if (!teststflag((yyvsp[-2]).state, Xto)) {
				prp = (yyvsp[-2]).prim;
				while (isthen(prp)) { prp = prp->parent; }
				shift(prp, (yyvsp[0]).xval - prp->aat.xpos, (yyvsp[0]).yval - prp->aat.ypos);
			    }
			  else {
				With2->aat.xpos = (yyvsp[0]).xval;
				With2->aat.ypos = (yyvsp[0]).yval; }
			  setstflag(&(yyvsp[-2]).state, Xfrom);
			  }
			else { markerror(858); }
		    }
		  }
#line 3761 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 2062 "dpic.y" /* yacc.c:1646  */
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
    	        With2 = (yyval).prim;
    	        if (With2->ptype != Xarc) {
    	    	  With2->startangle_ = (yyvsp[0]).xval;
    	    	  With2->arcangle_ = (yyvsp[0]).yval;
    	          }
    	        else {
    	    	  x1 = With2->aat.xpos + (With2->aradius_ *
                    cos(With2->startangle_));
    	    	  z1 = With2->aat.ypos + (With2->aradius_ *
                    sin(With2->startangle_));
    	    	  dx = (yyvsp[0]).xval - x1;
    	    	  dy = (yyvsp[0]).yval - z1;
    	    	  ts = (dx * dx) + (dy * dy);
    	    	  if (With2->direction != 0) { i = With2->direction; }
    	    	else { i = (yyval).toklen; }
#ifdef DDEBUG
    	    	if (debuglevel == 2) {
    	    	  fprintf(log_, " (x1,z1)="); wpair(&log_, x1, z1);
    	    	  fprintf(log_, " (dx,dy)="); wpair(&log_, dx, dy);
    	    	  fprintf(log_, " ts="); wfloat(&log_, ts);
    	    	  fprintf(log_, " i=%d", i); }
#endif
    	    	if (ts == 0.0) { With2->arcangle_ = 0.0; }
    	    	else {
    	    	    t = sqrt(Max(0.0,(4.0 *
                          With2->aradius_ * With2->aradius_) - ts) / ts);
#ifdef DDEBUG
    	    	    if (debuglevel == 2) {
    	    		  fprintf(log_, " t="); wfloat(&log_, t);
    	    		  fprintf(log_, " |arcangle|=");
    	    		  wfloat(&log_, With2->arcangle_ * 180 / pi);
    	    		  putc('\n', log_); }
#endif
    	    	    r = sqrt(ts);               /* t is always nonnegative  */
    	    	    if (t <= 0.0) { With2->aradius_ = 0.5 * r; }
    	    	    switch (i) {
							/* Determine which of the two default arcs to
							   draw: */
    	    	    case Xup:
    	    	      if (With2->arcangle_ * ((-dx) - (t * dy)) < 0.0) {t= -t; }
    	    	      break;
    	    	    case Xdown:
    	    	      if (With2->arcangle_ * ((-dx) - (t * dy)) > 0.0) { t=-t; }
    	    	      break;
    	    	    case Xright:
    	    	      if (With2->arcangle_ * (dy - (t * dx)) < 0.0) { t = -t; }
    	    	      break;
    	    	    case Xleft:
    	    	      if (With2->arcangle_ * (dy - (t * dx)) > 0.0) { t = -t; }
    	    	      break;
    	    	      }
    	    	    With2->aat.xpos = x1 + (0.5 * (dx + (t * dy)));
    	    	    With2->aat.ypos = z1 + (0.5 * (dy - (t * dx)));
#ifdef DDEBUG
    	    	    if (debuglevel == 2) {
    	    		  fprintf(log_, " t="); wfloat(&log_, t);
    	    		  fprintf(log_, " aradius=");
    	    		  wfloat(&log_, With2->aradius_);
    	    		  fprintf(log_, " aat=");
    	    		  wpair(&log_, With2->aat.xpos, With2->aat.ypos);
    	    		  putc('\n', log_);
    	    	      }
#endif
    	    	    setangles(&With2->startangle_,
    	    		      &With2->arcangle_, With2->aat, x1, z1,
    	    		      (yyvsp[0]).xval, (yyvsp[0]).yval);
    	    	    }
							/* ratio centre-to-chord/half-chord */
    	    	  if (With2->direction != 0) { (yyval).toklen = With2->direction; }
    	    	  With2->direction = 0;
    	          }
    	        setstflag(&(yyval).state, Xto);
#ifdef DDEBUG
    	        if (debuglevel > 0) { printobject((yyval).prim); }
#endif
    	        }
    	      else { markerror(858); }
    	      }
		   }
#line 3860 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2158 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			if ((drawmode != SVG) || (getstval((yyvsp[-2]).state) == 0)) {
			    setstval(&(yyval).state, XDotc); }
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
#line 3881 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2176 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			namptr = (yyval).prim->textp;
			if (namptr != NULL) {
			  while (namptr->nextname != NULL) { namptr = namptr->nextname; }
			  setjust(namptr, (yyvsp[0]).lexval);
			  if (drawmode == SVG) {
				With2 = (yyval).prim;
				if ((!teststflag((yyval).state, Xat)) &&
                    (With2->ptype == Xstring)) {
				  (yyval).xval = With2->aat.xpos;
				  (yyval).yval = With2->aat.ypos;
				  setstflag(&(yyval).state, Xat); }
				setstflag(&(yyval).state, Xcw);
				i = getstval((yyval).state);
				if ((With2->ptype != Xmove) && (With2->ptype != Xspline) &&
				    (With2->ptype != Xarrow) && (With2->ptype != Xline)) {
				  switch ((yyvsp[0]).lexval) {
				    case Xljust:
				      if (i == XDotn) { setstval(&(yyval).state, XDotnw); }
				      else if (i == XDots) { setstval(&(yyval).state, XDotsw); }
				      else { setstval(&(yyval).state, XDotw); }
				      break;
				    case Xrjust:
				      if (i == XDotn) { setstval(&(yyval).state, XDotne); }
				      else if (i == XDots) { setstval(&(yyval).state, XDotse); }
				      else { setstval(&(yyval).state, XDote); }
				      break;
				    case Xbelow:
				      if (i == XDote) { setstval(&(yyval).state, XDotne); }
				      else if (i == XDotw) { setstval(&(yyval).state, XDotnw); }
				      else { setstval(&(yyval).state, XDotn); }
				      break;
				    case Xabove:
				      if (i == XDote) { setstval(&(yyval).state, XDotse); }
				      else if (i == XDotw) { setstval(&(yyval).state, XDotsw); }
				      else { setstval(&(yyval).state, XDots); }
				      break;
				    }
				  }
			    }
			  }
			else { markerror(861); }
		    }
		  }
#line 3930 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2222 "dpic.y" /* yacc.c:1646  */
    { if ((drawmode == Pict2e) || (drawmode == TeX) ||
		      (drawmode == tTeX) || (drawmode == xfig)) { markerror(858); }
		  else if (((yyvsp[0]).prim != NULL) && ((yyvsp[-2]).prim != NULL)) {
			With2 = (yyval).prim;
			switch ((yyvsp[-1]).lexval) {
			case Xshaded:
			  if (hasshade((yyvsp[-2]).lexval, true)) {
			    deletename(&With2->shadedp);
			    With2->shadedp = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
			    }
			  break;
			case Xoutlined:
			  if (hasoutline((yyvsp[-2]).lexval, true)) {
			    deletename(&With2->outlinep);
			    With2->outlinep = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
			    }
			  break;
			case Xcolour:
			  if (hasoutline((yyvsp[-2]).lexval, true)) {
			    deletename(&With2->outlinep);
			    With2->outlinep = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
				i = With2->ptype;
			    if (((i != Xspline) && (i != Xarrow) && (i != Xline) &&
				   (i != Xarc)) & hasshade((yyvsp[-2]).lexval, false)) {
				  deletename(&With2->shadedp);
				  copystr(&With2->shadedp, With2->outlinep);
			      }
			    }
			  break;
			  }
		    }
		    deletestringbox(&(yyvsp[0]).prim);
		  }
#line 3971 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2260 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			setstval(&(yyval).state, XEMPTY);
			setstflag(&(yyval).state, Xat);
		    }
		  }
#line 3983 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2269 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			setstval(&(yyval).state, (yyvsp[-2]).lexval);
			setstflag(&(yyval).state, Xat);
		    }
		  }
#line 3995 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2278 "dpic.y" /* yacc.c:1646  */
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
#line 4014 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2294 "dpic.y" /* yacc.c:1646  */
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
#line 4035 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2313 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, Xblock, envblock);
		  (yyval).prim->here_.xpos = 0.0;
		  (yyval).prim->here_.ypos = 0.0;
		  envblock = (yyval).prim;
		  tail = NULL;
		  (yyval).lexval = 0;
		  }
#line 4047 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2324 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-1]).lexval > Xprimitiv) && ((yyvsp[-1]).lexval < Xenvvar)) {
			newprim(&(yyval).prim, (yyvsp[-1]).lexval, envblock);
			eb = findenv(envblock);
			if (( ((yyvsp[-1]).lexval != Xmove) && ((drawmode == MPost) ||
			      (drawmode == Pict2e) || (drawmode == PDF) ||
			      (drawmode == PS) || (drawmode == SVG) ||
			      (drawmode == PSfrag)) ) || ((yyvsp[-1]).lexval == Xarc)) {
			  (yyval).prim->lthick = eb->envinx(Xlinethick); }
			if (((yyvsp[0]).lexval != XEMPTY) &&               /* check expr allowed */
			    ((yyvsp[-1]).lexval != Xmove) &&
			    ((yyvsp[-1]).lexval != Xspline) &&
			    ((yyvsp[-1]).lexval != Xarrow) &&
			    ((yyvsp[-1]).lexval != Xline)) { markerror(858); }
			With2 = (yyval).prim;
			switch ((yyvsp[-1]).lexval) {
			  case Xbox:
			    With2->boxheight_ = eb->envinx(Xboxht);
			    With2->boxwidth_ = eb->envinx(Xboxwid);
			    With2->boxradius_ = eb->envinx(Xboxrad);
			    switch (With2->direction) {
			      case Xup:
			        With2->aat.ypos += With2->boxheight_ * 0.5;
			        break;
			      case Xdown:
			        With2->aat.ypos -= With2->boxheight_ * 0.5;
			        break;
			      case Xleft:
			        With2->aat.xpos -= With2->boxwidth_ * 0.5;
			        break;
			      case Xright:
			        With2->aat.xpos += With2->boxwidth_ * 0.5;
			        break;
			      }
			    break;
			  case Xcircle:
			    With2->circleradius_ = eb->envinx(Xcirclerad);
			    switch (With2->direction) {
			      case Xup:
			        With2->aat.ypos += With2->circleradius_;
			        break;
			      case Xdown:
			        With2->aat.ypos -= With2->circleradius_;
			        break;
			      case Xleft:
			        With2->aat.xpos -= With2->circleradius_;
			        break;
			      case Xright:
			        With2->aat.xpos += With2->circleradius_;
			        break;
			      }
			    break;
			  case Xellipse:
			    With2->ellipseheight_ = eb->envinx(Xellipseht);
			    With2->ellipsewidth_ = eb->envinx(Xellipsewid);
			    switch (With2->direction) {
			      case Xup:
			        With2->aat.ypos += With2->ellipseheight_ * 0.5;
			        break;
			      case Xdown:
			        With2->aat.ypos -= With2->ellipseheight_ * 0.5;
			        break;
			      case Xleft:
			        With2->aat.xpos -= With2->ellipsewidth_ * 0.5;
			        break;
			      case Xright:
			        With2->aat.xpos += With2->ellipsewidth_ * 0.5;
			        break;
			      }
			    break;
			  case Xarc:
			    With2->aradius_ = eb->envinx(Xarcrad);
			    switch (With2->direction) {
			      case Xup:
			        With2->startangle_ = 0.0;
			        With2->aat.xpos -= With2->aradius_;
			        break;
			      case Xdown:
			        With2->startangle_ = pi;
			        With2->aat.xpos += With2->aradius_;
			        break;
			      case Xleft:
			        With2->startangle_ = 0.5 * pi;
			        With2->aat.ypos -= With2->aradius_;
			        break;
			      case Xright:
			        With2->startangle_ = (-0.5) * pi;
			        With2->aat.ypos += With2->aradius_;
			        break;
			      }
			    With2->lineheight_ = eb->envinx(Xarrowht);
			    With2->linewidth_ = eb->envinx(Xarrowwid);
			    With2->lineatype_ = pahnum(pahlex(0, XEMPTY),
			      Rnd(eb->envinx(Xarrowhead)));
			    With2->arcangle_ = pi * 0.5;
			    break;
			  case Xline:
			  case Xarrow:
			  case Xspline:
			  case Xmove:
			    With2->endpos_ = With2->aat;
			    if ((With2->ptype == Xspline) && ((yyvsp[0]).lexval != XEMPTY)) {
			      With2->aradius_ = (yyvsp[0]).xval;
			      (yyvsp[0]).lexval = XEMPTY; }
			    if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; }
			    else if (With2->ptype == Xmove) {
			      switch (With2->direction) {
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
			      switch (With2->direction) {
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
			    switch (With2->direction) {
			      case Xup:
			        With2->endpos_.ypos = With2->aat.ypos + r;
			        break;
			      case Xdown:
			        With2->endpos_.ypos = With2->aat.ypos - r;
			        break;
			      case Xleft:
			        With2->endpos_.xpos = With2->aat.xpos - r;
			        break;
			      case Xright:
			        With2->endpos_.xpos = With2->aat.xpos + r;
			        break;
			      }
			    With2->lineheight_ = eb->envinx(Xarrowht);
			    With2->linewidth_ = eb->envinx(Xarrowwid);
			    if (With2->ptype == Xarrow) {
			      With2->lineatype_ = pahlex(0, Xrighthead); }
			    else { With2->lineatype_ = pahlex(0, XEMPTY); }
			  With2->lineatype_ = pahnum(With2->lineatype_,
			    Rnd(eb->envinx(Xarrowhead)));
			  break;
			  }
		    }
#ifdef DDEBUG
			if (debuglevel > 0) { printobject((yyval).prim); }
#endif
		  }
#line 4208 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2482 "dpic.y" /* yacc.c:1646  */
    { if ((drawmode == PS) || (drawmode == PDF) || (drawmode == PSfrag)) {
			printstate = ((printstate >> 1) * 2) + 1; }
		  }
#line 4216 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2487 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			envblock = (yyvsp[-2]).prim->parent;
			tail = NULL;
			getnesw((yyvsp[-2]).prim->son);
			With2 = (yyvsp[-2]).prim;
			With2->blockwidth_ = east - west;
			With2->blockheight_ = north - south;
			With2->aat.xpos = (east + west) * 0.5;
			With2->aat.ypos = (north + south) * 0.5;
			dx = envblock->here_.xpos - With2->aat.xpos;
			dy = envblock->here_.ypos - With2->aat.ypos;
			switch (envblock->direction) {
			  case Xright: dx += With2->blockwidth_ * 0.5; break;
			  case Xleft: dx -= With2->blockwidth_ * 0.5; break;
			  case Xup: dy += With2->blockheight_ * 0.5; break;
			  case Xdown: dy -= With2->blockheight_ * 0.5; break;
			  }
			With2->direction = envblock->direction;
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
			  With2 = (yyvsp[-2]).prim;
			  fprintf(log_, "Block3: (north,south),(west,east)");
			  wpair(&log_,With2->aat.ypos + (With2->blockheight_*0.5),
				  With2->aat.ypos - (With2->blockheight_ * 0.5));
			  wpair(&log_,With2->aat.xpos -(With2->blockwidth_*0.5),
				  With2->aat.xpos + (With2->blockwidth_ * 0.5));
			  fprintf(log_, " here=");
			  wpair(&log_,
				  With2->here_.xpos, With2->here_.ypos);
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
#line 4271 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2539 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, Xblock, envblock);
		  (yyval).prim->here_.xpos = 0.0;
		  (yyval).prim->here_.ypos = 0.0;
		  (yyval).lexval = 0;
		  }
#line 4281 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2547 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 4287 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2553 "dpic.y" /* yacc.c:1646  */
    { if (envblock->blockparms.env != NULL) {
			eb = findenv(envblock->parent);
			if (envblock->envinx(Xlinethick) != eb->envinx(Xlinethick)) {
		      newprim(&prp, XLaTeX, envblock);
			  prp->lthick = eb->envinx(Xlinethick);
              queueprim( prp, envblock );
              }
		    }
		  }
#line 4301 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2567 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[0]).lexval != XEMPTY) {
			  With1 = &(yyvsp[-1]);
			  addsuffix(chbuf, &With1->chbufx, &With1->toklen,
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
#line 4320 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2583 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[-3]).internal == NULL) { prp = (yyvsp[-3]).prim; }
			else { prp = (yyvsp[-3]).internal; }
			(yyval).internal = nthprimobj(prp->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
			if ((yyval).internal == NULL) { markerror(857); deletetree(&(yyval).prim); }
		    }
		  }
#line 4332 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2593 "dpic.y" /* yacc.c:1646  */
    { (yyval).yval = (yyvsp[0]).xval;
#ifdef DDEBUG
			if (debuglevel>1) prattribute("pair1",&(yyval));
#endif
			}
#line 4342 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2600 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) {
			(yyval).xval += (yyvsp[0]).xval;
			(yyval).yval += (yyvsp[0]).yval; }
		  }
#line 4351 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2607 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).xval <= 0.0) { markerror(856); }
		  else { (yyval).toklen = Rnd((yyvsp[-1]).xval); }
		  }
#line 4359 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2612 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval <= 0.0) { markerror(856); }
		  else { (yyval).toklen = -Rnd((yyvsp[-2]).xval); }
		  }
#line 4367 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2617 "dpic.y" /* yacc.c:1646  */
    { (yyval).toklen = 0; }
#line 4373 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 2627 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = Xblock; }
#line 4379 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2631 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 0.0;
		  (yyval).yval = 0.0;
		  (yyval).lexval = XEMPTY;
		  }
#line 4388 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2637 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval += (yyvsp[0]).xval;
		  (yyval).yval += (yyvsp[0]).yval;
		  (yyval).lexval = Xfloat;
		  }
#line 4397 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2643 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval -= (yyvsp[0]).xval;
		  (yyval).yval -= (yyvsp[0]).yval;
		  (yyval).lexval = Xfloat;
		  }
#line 4406 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2650 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4412 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2653 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-3]).xval;
		  (yyval).yval = (yyvsp[-1]).yval;
		  }
#line 4420 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2660 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval *= (yyvsp[0]).xval;
		  (yyval).yval *= (yyvsp[0]).xval;
		  }
#line 4428 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2665 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { markerror(852); }
		  else {
			(yyval).xval /= (yyvsp[0]).xval;
			(yyval).yval /= (yyvsp[0]).xval;
		    }
		  }
#line 4439 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2674 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, XEMPTY, &(yyval).xval, &(yyval).yval); }
#line 4445 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2677 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[-1]).prim, (yyvsp[0]).lexval, &(yyval).xval, &(yyval).yval); }
#line 4451 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2680 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, (yyvsp[-1]).lexval, &(yyvsp[0]).xval, &(yyvsp[0]).yval);
 		  (yyval) = (yyvsp[0]); }
#line 4458 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2684 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, (yyvsp[-2]).lexval, &(yyvsp[0]).xval, &(yyvsp[0]).yval);
 		  (yyval) = (yyvsp[0]); }
#line 4465 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2688 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = envblock->here_.xpos;
		  (yyval).yval = envblock->here_.ypos;
		  }
#line 4473 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 2696 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { (yyval).xval = 1.0; }
    	  else { (yyval).xval = 0.0; }
		  }
#line 4481 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2701 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval == 0.0) && ((yyvsp[0]).xval < 0.0)) { markerror(852); }
		  else {
			j = Rnd((yyvsp[0]).xval);
			r = j;
			if (r == (yyvsp[0]).xval) { (yyval).xval = intpow((yyvsp[-2]).xval, j); }
			else if ((yyvsp[-2]).xval < 0.0) { markerror(863); (yyval).xval = 0.0; }
			else if ((yyvsp[-2]).xval != 0.0) { (yyval).xval = exp((yyvsp[0]).xval * log((yyvsp[-2]).xval));}
			}
    	  }
#line 4495 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2713 "dpic.y" /* yacc.c:1646  */
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
#line 4514 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2729 "dpic.y" /* yacc.c:1646  */
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
#line 4529 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2741 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-1]).chbufx,
              &(yyvsp[-1]).toklen, (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
			primp = findplace((yyval).prim->son, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
			if (primp == NULL) { marknotfound(855, chbuf, (yyvsp[-1]).chbufx,(yyvsp[-1]).toklen);}
			(yyval).prim = primp;
		    }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4543 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2752 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).prim = nthprimobj((yyvsp[-3]).prim->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
			if ((yyval).prim == NULL) { markerror(857); }
		    }
		  }
#line 4553 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 2762 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4559 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 2765 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4565 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 2771 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval == 0.0) || ((yyvsp[0]).xval == 0.0)) { (yyval).xval = 0.0; }
		  else { (yyval).xval = 1.0; }
		  }
#line 4573 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 2777 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval == Xstring) {
			markerror(869);
			(yyval).lexval = Xfloat;
			deletestringbox(&(yyvsp[0]).prim);
		    }
		  }
#line 4584 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 2785 "dpic.y" /* yacc.c:1646  */
    { i = cmpstring((yyvsp[-2]).prim, (yyvsp[0]).prim);
		  if (i < 0) { (yyval).xval = 1.0; }
		  else { (yyval).xval = 0.0; }
		  (yyval).lexval = Xfloat;
		  deletestringbox(&(yyvsp[0]).prim);
		  deletestringbox(&(yyvsp[-2]).prim);
		  }
#line 4596 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 2794 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval < (yyvsp[0]).xval) { (yyval).xval = 1.0; }
		  else { (yyval).xval = 0.0; }
		  }
#line 4604 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 2804 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval == Xstring) {
			markerror(869);
			bswitch = false;
			deletestringbox(&(yyvsp[-2]).prim);
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
#line 4631 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2828 "dpic.y" /* yacc.c:1646  */
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
#line 4654 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2849 "dpic.y" /* yacc.c:1646  */
    { if (envblock != NULL) {
			eb = findenv(envblock);
			(yyval).xval = eb->envinx((yyvsp[0]).lexval);
		    }
		  }
#line 4664 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2856 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf,
		    &(yyvsp[-1]).chbufx, &(yyvsp[-1]).toklen, (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
    	  namptr = glfindname(envblock,chbuf,(yyvsp[-1]).chbufx,(yyvsp[-1]).toklen, &lastvar, &k);
    	  if (namptr == NULL) { (yyval).xval = 0.0; }
    	  else { (yyval).xval = namptr->val; }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4676 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2867 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4682 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2872 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).yval; }
#line 4688 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2875 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			switch ((yyvsp[0]).lexval) {
			  case Xheight:
			    (yyval).xval = pheight((yyval).prim);
			    break;
			  case Xwidth:
			    (yyval).xval = pwidth((yyval).prim);
			    break;
			  case Xradius:
			    With2 = (yyval).prim;
			    if (With2->ptype == Xcircle) {(yyval).xval = With2->circleradius_; }
			    else if (With2->ptype == Xarc) {(yyval).xval = With2->aradius_; }
			    else if (With2->ptype == Xbox) {(yyval).xval = With2->boxradius_; }
			    else {
			      (yyval).xval = 0.0;
			      markerror(858); }
			    break;
			case Xdiameter:
			  With2 = (yyvsp[-1]).prim;
			  if (With2->ptype == Xcircle) {(yyval).xval = With2->circleradius_*2; }
			  else if (With2->ptype == Xarc) {(yyval).xval = With2->aradius_*2; }
			  else {
			    (yyval).xval = 0.0;
			    markerror(858); }
			  break;
			case Xthickness:
			  With2 = (yyvsp[-1]).prim; j = With2->ptype;
			  if ((j == Xarc) || (j == Xspline) || (j == Xarrow) ||
                (j == Xline) || (j == Xcircle) || (j == Xellipse) ||
			      (j == Xbox)) { (yyval).xval = With2->lthick; }
			  else {
			    (yyval).xval = 0.0;
			    markerror(858); }
			  break;
			case Xlength:
			  With2 = (yyvsp[-1]).prim; j = With2->ptype;
			  if ((j == Xspline) || (j == Xmove) || (j == Xarrow) ||
                (j == Xline)) {
			    primp = (yyvsp[-1]).prim;
			    while (primp->son != NULL) { primp = primp->son; }
			    r = fabs(primp->endpos_.xpos - With2->aat.xpos);
			    s = fabs(primp->endpos_.ypos - With2->aat.ypos);
			    if (r == 0.0) { (yyval).xval = s; }
			    else if (s == 0.0) { (yyval).xval = r; }
			    else { (yyval).xval = sqrt((r * r) + (s * s)); }
			    }
			  else {
			    (yyval).xval = 0.0;
			    markerror(858); }
			  break;
			  }
		    }
		  }
#line 4746 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2930 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = ((double)random()) / randmax; }
#line 4752 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2933 "dpic.y" /* yacc.c:1646  */
    { srandom(Rnd((yyvsp[-1]).xval));
		  (yyval).xval = ((double)random()) / randmax;
		  }
#line 4760 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2938 "dpic.y" /* yacc.c:1646  */
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
#line 4813 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2988 "dpic.y" /* yacc.c:1646  */
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
#line 4836 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 3008 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4842 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 3011 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4848 "dpic.tab.c" /* yacc.c:1646  */
    break;


#line 4852 "dpic.tab.c" /* yacc.c:1646  */
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
#line 3014 "dpic.y" /* yacc.c:1906  */
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
{ fbuffer *With;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, " newbuf"); }
#endif
  if (freeinbuf == NULL) {
    *buf = malloc(sizeof(fbuffer));
    (*buf)->carray = malloc(sizeof(chbufarray));
    }
  else {
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, " f"); }
#endif
    *buf = freeinbuf;
    freeinbuf = freeinbuf->nextb;
    }
  With = *buf;
  With->savedlen = 0;
  With->carray[0] = ' ';
  With->readx = 1;
  With->attrib = 0;
  With->higherb = NULL;
  With->prevb = NULL;
  With->nextb = NULL;
#ifdef DDEBUG
  if (debuglevel > 0) { logaddr(*buf); putc('\n', log_); }
#endif
}


							/* Clearing memory at end of diagram */
void
deletefreeargs(arg **a)
{ arg *na;
  while ((*a) != NULL) {
    na = (*a)->nexta;
    disposebufs(&(*a)->argbody);
    Free(*a);
    *a = na; }
}


							/* Clearing memory at end of diagram */
void
deletefreeinbufs(fbuffer **p)
{ fbuffer *q;
  while ((*p) != NULL) {
    q = (*p)->nextb;
    Free((*p)->carray);
    Free(*p);
    *p = q; }
}


							/* performed for each input diagram: */
void
inittwo(void)
{ freeinbuf = NULL;
  freeseg = NULL;
  freex = 0;
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
{ int j;
  fbuffer *With;
  int FORLIM;
  if (cm == NULL) { }
  else if (cm->argbody == NULL) { }
  else if (cm->argbody->carray != NULL) {
    With = cm->argbody;
    fprintf(*iou, "in macro \"");
    FORLIM = -With->attrib;
    for (j = 1; j <= FORLIM; j++) { wchar(iou, With->carray[j]); }
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
    fprintf(log_, "*** markerror");
    wrbufaddr(inbuf, 0);
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
  if (inbufdepth == 0) { P_sun_argv(infname, sizeof(mstring), argct); }
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
      else if (thisbuf->carray[inx] <= ' ') { inx--; }
      else { scanning = false; } }
    lastbuf = thisbuf;
#ifdef DDEBUG
    if (debuglevel > 0) {
	  fprintf(log_, "Skip white back, inx=%d\n", inx);
	  wrbuf(thisbuf, 3, 0); }
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
      else if (isprint_(thisbuf->carray[j]) || (thisbuf->carray[j]==tabch)){
        j--; }
	  else { j++; scanning = false; }
      }
    if (j < 1) { j = 1; }
#ifdef DDEBUG
    if (debuglevel > 0) {
	  fprintf(log_, "Skip back, j=%d\n", j);
	  wrbuf(thisbuf, 3, 0); }
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
    fprintf(errout, "Character not recognized: ignored\n");
    break;

  case 802:
    fprintf(errout, "Invalid exponent character after e in a number\n");
    break;

  case 804:
  case 807:
    fprintf(errout, "End of file while reading ");
    if (emi == 807) { fprintf(errout, "string in "); }
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
    fprintf(errout, "Bad macro argument number\n");
    break;
  case 806:
    fprintf(errout, "End of file while evaluating macro argument\n");
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
{ int i;
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, "Search failure %d", eno);
    if (chb != NULL) {
	  fprintf(log_, " for \"");
	  for (i = inx; i < (inx + len); i++) { putc(chb[i], log_); }
	  putc('"', log_); }
    putc('\n', log_);
    }
#endif
  markerror(eno);
  fprintf(errout, "Search failure");
  if (chb != NULL) {
    fprintf(errout, " for \"");
    for (i = inx; i < (inx + len); i++) { putc(chb[i], errout); }
    putc('"', errout);
    }
  putc('\n', errout);
}

							/* Hash of variable name:
   							   (ord(chr(1))+ord(chr(n-1))) mod 10 */
int
varhash(Char *chb, chbufinx chbufx, chbufinx toklen)
{ int idx;

  if (chb == NULL) {
    idx = 0;
    return (idx - ((idx / (HASHLIM + 1)) * (HASHLIM + 1))); }
  idx = chb[chbufx];
  if (toklen > 2) { idx += chb[chbufx + toklen - 2]; }
  return (idx - ((idx / (HASHLIM + 1)) * (HASHLIM + 1)));
}

							/* Binary search for name in chain of stored
							   names */
nametype *(
findname(primitive *eb, Char *chb, chbufinx chbufx, chbufinx toklen,
	 nametype **last, int *k))
{ nametype *leftptr;
  nametype *rightptr = NULL;
  int left = 0, right = 0;
  int midpt, i, idx;
  nametype *With;
  idx = varhash(chb, chbufx, toklen);
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, " findname|");
    for (i = chbufx; i < (chbufx + toklen); i++) { putc(chb[i], log_); }
    fprintf(log_, "|:");
    if (eb == NULL) { fprintf(log_, " eb=nil"); }
    else { fprintf(log_, " nvars[%d]=%d", idx, eb->blockparms.nvars[idx]); }
    if (debuglevel > 1) { putc('\n', log_); }
    }
#endif
  *k = 1;
  *last = NULL;
  if (eb == NULL) { leftptr = NULL; }
  else {
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, " eb!=NULL: k=%d idx=%d ", *k,idx); }
#endif
    leftptr = eb->blockparms.vars[idx];
    *last = leftptr; }
#ifdef DDEBUG
    if (debuglevel > 0) {
      if (leftptr==NULL) { fprintf(log_," leftptr == NULL "); }
      else { fprintf(log_, "leftptr!=NULL[%d] k=%d", ordp(leftptr), *k); } }
#endif
							/* Check the first (highest) name */
  if (leftptr != NULL) {
    *k = eqstring(chb, chbufx, toklen, leftptr->segmnt, leftptr->seginx,
		    leftptr->len);
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, "leftptr!=NULL: k=%d", *k); }
#endif
    if ((*k) < 0) {
	  left = 2;
	  leftptr = leftptr->nextname;
	  right = eb->blockparms.nvars[idx] + 1; }
    else { rightptr = leftptr; }
    }
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, "leftptr!=rightptr: %d",
      (int) (leftptr!=rightptr)); }
#endif
  while (leftptr != rightptr) {
    midpt = (left + right) >> 1;
    *last = leftptr;
    for (i = left + 1; i <= midpt; i++) { *last = (*last)->nextname; }
    With = *last;
    *k = eqstring(chb, chbufx, toklen, With->segmnt, With->seginx,With->len);
#ifdef DDEBUG
    if (debuglevel > 0) { fprintf(log_, "while: k=%d", *k); }
#endif
    if ((*k) < 0) {
	  left = midpt + 1;
	  leftptr = (*last)->nextname;
	  continue; }
    if ((*k) == 0) {
	  leftptr = *last;
	  rightptr = leftptr; }
    else {
	  right = midpt;
	  rightptr = *last; }
    }
#ifdef DDEBUG
  if (debuglevel > 0) {
    if ((*k) == 0) { fprintf(log_," return leftptr;\n"); }
    else { fprintf(log_," return NULL;\n"); } }
#endif
  if ((*k) == 0) { return leftptr; }
  else { return NULL; }
}

							/* A minimal set of debug routines has been kept: */
#ifdef DDEBUG
void
logchar(Char c)
{ fprintf(log_, "ch(%d)=\"", c);
  wchar(&log_, c);
  putc('"', log_);
}


void
wlogfl(Char *nm, double v, int cr)
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
{ fbuffer *r;
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
wrbuf(fbuffer *p, int job, int r)
{ int i, j, k, m;
  fbuffer *With;
  if (p == NULL) { fprintf(log_, " nil buffer "); return; }
  while (p != NULL) {
    With = p;
    if (job > 2) { fprintf(log_, " buf"); wrbufaddr(p, 0); }
    if (job > 1) {
	  fprintf(log_, " readx=%d savedlen=%d attrib=%d",
		  With->readx, With->savedlen, With->attrib); }
    if (r == 0) { j = 1; }
    else if (r < 0) { j = -r; }
    else { j = With->readx; }
    if (job > 0) { fprintf(log_, "(%d,%d)", j, With->savedlen); }
    fprintf(log_, "\n|");
    if (With->carray == NULL) { fprintf(log_, "nil"); }
    else {
	  i = j;
	  while (i <= With->savedlen) {
	    if (With->carray[i] != 0) { wchar(&log_, With->carray[i]); }
	    else {
		  m = i;
		  k = With->savedlen + 1;
		  while (i < k) { if (With->carray[i] == 0) { i++; } else { k = i; } }
		  fprintf(log_, "(%d)x", i - m);
		  wchar(&log_, '\0');
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
{ fprintf(log_, "state=%d", st);
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
snapname(Char *chbu, chbufinx inx, chbufinx ll)
{ int j;
  fprintf(log_, " (%d inx=%d len=%d)|", ordp(chbu), inx, ll);
  if (chbu == NULL) { fprintf(log_, "**nil string pointer**"); }
  else { for (j = inx; j < (inx + ll); j++) { putc(chbu[j], log_); } }
  putc('|', log_);
  fflush(log_);
}


void
snaptype(FILE **iou, int p)
{ switch (p) {
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
{ int i, j = /* 6 */ 0;
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
{ nametype *With;

  while (namptr != NULL) {
      With = namptr;
      putc(' ', log_);
      wpair(&log_, ordp(namptr), ordp(With->nextname));
      fprintf(log_, " val=");
      wfloat(&log_, With->val);
      fflush(log_);
      snapname(With->segmnt, With->seginx, With->len);
      namptr = With->nextname;
      putc('\n', log_);
  }
}

void
printobject(primitive *primp)
{ double xx, yy;
  int i;
  primitive *With;
  if (debuglevel != 0) {
    if (primp == NULL) { fprintf(log_, "Object is nil\n"); }
    else {
	  while (primp != NULL) {
	    With = primp;
	    fprintf(log_, "Object(%d) type=", ordp(primp));
	    snaptype(&log_, With->ptype);
	    fprintf(log_, "(%d)\n", With->ptype);
	    fprintf(log_, " Parent(%d", ordp(With->parent));
	    if (With->parent != NULL) {
		  fprintf(log_, ") Parent^.son(%d", ordp(With->parent->son)); }
	    fprintf(log_, ") Son(%d) Next(%d)\n",
		      ordp(With->son), ordp(With->nextname));
	    if (With->name != NULL) {
		  fprintf(log_, " name: ");
		  printtext(With->name); }
	    if (With->outlinep != NULL) {
		  fprintf(log_, " outline:");
		  printtext(With->outlinep); }
	    if (With->shadedp != NULL) {
		  fprintf(log_, " shaded:");
		  printtext(With->shadedp); }
	    if (With->textp != NULL) { printtext(With->textp); }
	    fprintf(log_, " aat");
	    wpair(&log_, With->aat.xpos, With->aat.ypos);
	    wlogfl("lparam", With->lparam, 0);
	    wlogfl("lthick", With->lthick, 0);
	    switch (With->direction) {
	      case Xup: fprintf(log_, " <up>"); break;
	      case Xdown: fprintf(log_, " <down>"); break;
	      case Xleft: fprintf(log_, " <left>"); break;
	      case Xright: fprintf(log_, " <right>"); break;
	      default: fprintf(log_, " dir =%d", With->direction); break;
	      }
	    fprintf(log_, " spec=%d\n", With->spec);
	    fflush(log_);
	    switch (With->ptype) {
	      case Xbox:
	      case Xstring:
		    wlogfl("boxfill", With->boxfill_, 0);
		    wlogfl("boxheight", With->boxheight_, 0);
		    wlogfl("boxwidth", With->boxwidth_, 0);
		    wlogfl("boxrad", With->boxradius_, 0);
		    break;
	      case Xblock:
		    wlogfl("blockheight", With->blockheight_, 0);
		    wlogfl("blockwidth", With->blockwidth_, 0);
		    fprintf(log_, " here=");
		    wpair(&log_, With->here_.xpos, With->here_.ypos);
		    fprintf(log_, " vars=");
		    for (i = 0; i <= HASHLIM; i++) {
		      if (With->blockparms.vars[i] == NULL) {
				 fprintf(log_, " %d nil;", i);}
		      else {
				fprintf(log_, " %d %d;", i, ordp(With->blockparms.vars[i])); }
		      }
		    fprintf(log_, "\n env=");
		    if (With->blockparms.env == NULL) { fprintf(log_, "nil"); }
		    else { fprintf(log_, "%d", ordp(With->blockparms.env)); }
		    break;
	      case Xcircle:
		    wlogfl("cfill", With->circlefill_, 0);
		    wlogfl("radius", With->circleradius_, 0);
		    break;
	      case Xellipse:
		    wlogfl("efill", With->ellipsefill_, 0);
		    wlogfl("elheight", With->ellipseheight_, 0);
		    wlogfl("elwidth", With->ellipsewidth_, 0);
		    break;
	      case Xline:
	      case Xarrow:
	      case Xmove:
	      case Xspline:
		    fprintf(log_, " endpos=");
		    wpair(&log_, With->endpos_.xpos, With->endpos_.ypos);
		    wlogfl("height", With->lineheight_, 0);
		    wlogfl("width", With->linewidth_, 0);
		    wlogfl("lfill", With->linefill_, 0);
		    wlogfl("aradius", With->aradius_, 0);
		    fprintf(log_, "\n ahlex(atype)=%d", ahlex(With->lineatype_));
		    fprintf(log_, " ahnum(atype)=%d", ahnum(With->lineatype_));
		    break;
	      case Xarc:
		    fprintf(log_, " lspec=%d", lspec(With->spec));
		    wlogfl("lfill", With->linefill_, 0);
		    wlogfl("aradius", With->aradius_, 0);
		    fprintf(log_, " (startangle_,arcangle_)(deg)=");
		    wpair(&log_, With->startangle_ * 180.0 / pi,
		      With->arcangle_ * 180.0 / pi);
		    fprintf(log_, "\n (from)=");
		    xx = With->aat.xpos + (With->aradius_ * cos(With->startangle_));
		    yy = With->aat.ypos + (With->aradius_ * sin(With->startangle_));
		    wpair(&log_, xx, yy);
		    fprintf(log_, " (to)=");
		    xx = With->aat.xpos + (With->aradius_ *
              cos(With->startangle_ + With->arcangle_));
		    yy = With->aat.ypos + (With->aradius_ *
              sin(With->startangle_ + With->arcangle_));
		    wpair(&log_, xx, yy);
		    fprintf(log_, " ahlex(atype)=%d", ahlex(With->lineatype_));
		    fprintf(log_, " ahnum(atype)=%d", ahnum(With->lineatype_));
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
	    if (With->ptype == Xblock) { primp = NULL; }
	    else { primp = With->son; }
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
{ nametype *lv;
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
{ primitive *r;
  int i;
  primitive *With;
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
    With = *p;
    if ((With->ptype) == Xblock) {
	  for (i = HASHLIM; i >= 0; i--) { deletename(&With->blockparms.vars[i]);}
	  if (With->blockparms.env != NULL) { Free(With->blockparms.env); }
      }
    else { Free(*p); }
    *p = r;
    }
  }


							/* Store arc strtang and arcang parameters */
void
setangles(double *strtang, double *arcang, postype ctr, double xs, double ys,
	  double xf, double yf)
{ double ra;                       /* set arc angles given centre, start, end */
  *strtang = datan(ys - ctr.ypos, xs - ctr.xpos);
  ra = principal(datan(yf - ctr.ypos, xf - ctr.xpos) - (*strtang), pi);
  if ((ra < 0.0) && ((*arcang) > 0.0)) { ra += 2.0 * pi; }
  else if ((ra > 0.0) && ((*arcang) < 0.0)) { ra -= 2.0 * pi; }
  *arcang = ra;
}


							/* Perform assignment operator */
void
eqop(double *x, int op, double y)
{ int i, j;

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
{ return (st >> 8);
}

							/* Record application of object attribute */
void
setstflag(int *st, int value)
{ switch (value) {
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
{ boolean b = false;

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
{ if ((p1 == NULL) || (p2 == NULL)) { return maxint; }
  else if (p1->textp == NULL) { return maxint; }
  else if (p2->textp == NULL) { return (-maxint); }
  else { return (
          eqstring(p1->textp->segmnt, p1->textp->seginx, p1->textp->len,
		           p2->textp->segmnt, p2->textp->seginx, p2->textp->len)); }
}


							/* Match place name with stored places */
primitive *(
findplace(primitive *p, Char *chb, chbufinx inx, chbufinx toklen))
{ primitive *pj = NULL;
  nametype *With;

  while (p != pj) {
    if (p->name == NULL) { p = p->nextname; }
    else {
	  With = p->name;
	  if (eqstring(With->segmnt,With->seginx,With->len, chb, inx,toklen) == 0) {
	      pj = p; }
	  else { p = p->nextname; }
      }
    }
  return p;
}

							/* Get the value of a global variable */
double
findvar(Char *s, int ln)
{ int i, k;
  nametype *last, *np;

  if (tmpfmt == NULL) { tmpfmt = malloc(sizeof(chbufarray)); }
  for (i = 1; i <= ln; i++) { tmpfmt[i] = s[i-1]; }
  np = findname(globalenv, tmpfmt, 1, ln, &last, &k);
  if (np == NULL) { return 0.0; }
  else { return (np->val); }
}

							/* Search for variable in this and higer scope*/
nametype *(
glfindname(primitive *eb, Char *chb, chbufinx chbufx, chbufinx toklen,
	   nametype **last, int *k))
{ nametype *np = NULL;
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
{ int i, j, k;
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
{ int i, FORLIM;
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
appendthen(primitive **pr)
{ primitive *prp, *prq;
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
lineardir(primitive *pr, double dy, double dx, int *state)
{ if (!(teststflag(*state, Xto) | teststflag(*state, Xdirecton))) {
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
hasoutline(int lx, boolean warn)
{ boolean hs;
  hs = ((lx == Xspline) || (lx == Xarrow) || (lx == Xline) ||
	(lx == Xarc) || (lx == Xellipse) ||
	(lx == Xcircle) || (lx == Xbox));
  if (drawmode == SVG) { hs = (hs || (lx == Xstring)); }
  if ((!hs) && warn) { markerror(858); }
  return hs;
}


							/* Test for shade for shaded "string" */
boolean
hasshade(int lx, boolean warn)
{ boolean hs;
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
newstr(nametype **sp)
{
  nametype *With;
  *sp = malloc(sizeof(nametype));
  With = *sp;
  With->val = 0.0;
  With->segmnt = NULL;
  With->seginx = 0;
  With->len = 0;
  With->nextname = NULL;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, "newstr[%d]\n", ordp(*sp)); }
#endif
}


							/* Copy a string into freeseg */
void
storestring(nametype *outstr,Char *srcbuf,chbufinx psrc,chbufinx lsrc,int job)
{ int i, j;
  boolean newseg;
  if ((freeseg == NULL) || (lsrc > (CHBUFSIZ - freex + 1))) { newseg = true; }
  else { newseg = false; }
  if (newseg) {
    freeseg = malloc(sizeof(chbufarray));
#ifdef DDEBUG
    if (debuglevel>0) { fprintf(log_, "storestring new[%d]\n", ordp(freeseg));}
#endif
    putbval(freeseg, 0);
    freex = 3; }
  for (i = 0; i < lsrc; i++) { freeseg[freex + i] = srcbuf[psrc + i]; }
  outstr->segmnt = freeseg;
  outstr->seginx = freex;
  outstr->len = lsrc;
  j = bval(freeseg);
  putbval(freeseg, j + 1);
  freex += lsrc;
#ifdef DDEBUG
  if (debuglevel > 0) {
  fprintf(log_,
	  "storestring to strptr %d: segmnt=%d seginx=%d links=%d freex=%d\n",
	  ordp(outstr), ordp(freeseg), outstr->seginx, bval(freeseg), freex);
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
{ if (ip == NULL) { *sp = NULL; }
  else {
    newstr(sp);
    storestring(*sp, ip->segmnt, ip->seginx, ip->len, 0);
    }
}


							/* Append buf to *sp */
void
appendstring(nametype *sp, Char *buf, chbufinx px, chbufinx ll)
{
  int i;
  int j;
  Char *tmpseg;
  int FORLIM;
  if ((sp == NULL) || (buf == NULL)) { return; }
  if ((sp->segmnt == freeseg) && (sp->seginx + sp->len == freex) &&
      (freex + ll - 1 <= CHBUFSIZ)) {
    for (i = 0; i < ll; i++) { freeseg[freex + i] = buf[px + i]; }
    sp->len += ll;
    freex += ll;
    return;
    }
  if (sp->len + ll + 2 > CHBUFSIZ) { markerror(866); return; }
  tmpseg = malloc(sizeof(chbufarray));
  FORLIM = sp->len;
  for (i = 0; i < FORLIM; i++) { tmpseg[i+3] = sp->segmnt[sp->seginx + i]; }
  j = bval(sp->segmnt);
  if (j > 1) {
    putbval(sp->segmnt, j - 1);
    if ((sp->segmnt == freeseg) && (sp->seginx + sp->len == freex)) {
	  freex = sp->seginx;
	  j = 3;
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
  for (i = 0; i < ll; i++) { tmpseg[sp->len + i + 3] = buf[px + i]; }
  freeseg = tmpseg;
  freex = sp->len + ll + 3;
  putbval(freeseg, 1);
  sp->segmnt = freeseg;
  sp->seginx = 3;
  sp->len += ll;
}


							/* Store or append string */
int
putstring(int ix, nametype *sp, Char *buf, chbufinx px, chbufinx ll)
{ if (ix <= 0) { storestring(sp, buf, px, ll, 0); }
  else { appendstring(sp, buf, px, ll); }
  return (ix + 1);
}


							/* Height of a primitive object */
double
pheight(primitive *pr)
{ double ph;
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
{ double pw;

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
{ while (ptm != NULL) {
    nesw(ptm);
    if (ptm->ptype != Xblock) { neswrec(ptm->son); }
    ptm = ptm->nextname;
    }
  }


							/* Bounding box of a drawing tree */
void
getnesw(primitive *ptm)
{ initnesw();
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
{ int i;

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
{ primitive *q = NULL;

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
{ double v = 0.0;
  if ((ind <= XXenvvar) || (ind > Xlastenv)) { return v; }
  p = findenv(p);
  if (p != NULL) { v = p->blockparms.env[ind - XXenvvar - 1]; }
  return v;
}


							/* Get the value of an environment variable
							   if it has not been set locally */
double
qenv(primitive *p, int ind, double localval)
{ double noval;
  switch (ind) {
  case Xfillval: noval = -1.0; break;
  case Xlinethick: noval = mdistmax; break;
  case Xdashwid: noval = mdistmax; break;
  default: noval = 0.0; break;
  }
  if (localval != noval) { return localval; }
  else { return (venv(p, ind)); }
}


							/* Position from an affine transformation
							   orig + mat(cs) * [x,y]
							   Position cs is (cos t, sin t) */
postype
affine(double x, double y, postype orig, postype cs)
{ postype tpos;

  tpos.xpos = orig.xpos + (cs.xpos * x) - (cs.ypos * y);
  tpos.ypos = orig.ypos + (cs.ypos * x) + (cs.xpos * y);
  return tpos;
}


							/* Get (cos t, sin t) of point wrt shaft */
postype
affang(postype point, postype shaft)
{ double lgth;
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
{ south = distmax;
  north = -south;
  west = south;
  east = -west;
}


							/* Values north, south, west, east for a string
							   accounting for ljust rjust above below */
void
neswstring(primitive *pmp, double ht, double wd)
{ boolean A, B, L, R;
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
{ double aht, awd;
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
{ boolean inarctmp;

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
{ double hight, wdth, sang, eang;
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
{ if (pr == NULL) {
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
{ return (((int) buf[0]) << 7) + (int) buf[1] ;
}

							/* Store integer in first two buffer bytes */
void
putbval(Char *buf, int n)
{
  buf[0] = (Char)(n>>7); buf[1] = (Char)(n % 128);
}

							/* Free the space used by the name string */
void
deletename(nametype **head)
{ /*F(var head: strptr)F*/
  nametype *pn, *r;
  int j, FORLIM;
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
		  j = 3;
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
	    Free(freeseg);
	    freeseg = NULL;
	    }
	  else {
	    Free(pn->segmnt);
        pn->segmnt = NULL;
	    }
      }
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
{ int i;
  primitive *With;
  switch (primtype) {
    case Xbox:
    case Xstring:
      *pr = malloc(sizeof(Xboxprimitive));
      break;
    case Xblock:
      *pr = malloc(sizeof(primitive));
      break;
    case Xcircle:
      *pr = malloc(sizeof(Xcircleprimitive));
      break;
    case Xellipse:
      *pr = malloc(sizeof(Xellipseprimitive));
      break;
    case Xline:
    case Xarc:
    case Xarrow:
    case Xmove:
    case Xspline:
      *pr = malloc(sizeof(Xlineprimitive));
      break;
    case Xlabel:
    case XLaTeX:
      *pr = malloc(sizeof(Xlabelprimitive));
      break;
    }

#ifdef DDEBUG
  if (debuglevel > 0) {fprintf(log_, "newprim");
  snaptype(&log_,primtype); fprintf(log_,"[%d]\n", ordp(*pr));
  }
#endif

  With = *pr;
  With->name = NULL;
  With->textp = NULL;
  With->outlinep = NULL;
  With->shadedp = NULL;
  With->son = NULL;
  With->nextname = NULL;
  if (envblk == NULL) {
    With->parent = NULL;
    With->aat.xpos = 0.0;
    With->aat.ypos = 0.0;
    With->direction = Xright;
    }
  else {
    With->parent = envblk;
    With->aat = envblk->here_;
    With->direction = envblk->direction;
    }
  With->lparam = mdistmax;
  With->lthick = mdistmax;
  if ((primtype == Xstring) || (primtype == Xspline) ||
    (primtype == Xarc) || (primtype == Xarrow) || (primtype == Xline) ||
    (primtype == Xellipse) || (primtype == Xcircle) ||
    (primtype == Xbox)) { resetspec(&With->spec, Xsolid); }
  else { resetspec(&With->spec, Xinvis); }
  With->ptype = primtype;
  switch (primtype) {
    case Xbox:
    case Xstring:
      With->boxfill_ = -1.0;
      With->boxheight_ = 0.0;
      With->boxwidth_ = 0.0;
      With->boxradius_ = 0.0;
      break;
    case Xblock:
      With->blockheight_ = 0.0;
      With->blockwidth_ = 0.0;
      With->here_ = With->aat;
      for (i = 0; i <= HASHLIM; i++) {
	    With->blockparms.vars[i]   = NULL;
	    With->blockparms.nvars[i]   = 0; }
      With->blockparms.env = NULL;
      break;
    case Xcircle:
      With->circlefill_ = -1.0;
      With->circleradius_ = 0.0;
      break;
    case Xellipse:
      With->ellipsefill_ = -1.0;
      With->ellipseheight_ = 0.0;
      With->ellipsewidth_ = 0.0;
      break;
    case Xline:
    case Xarrow:
    case Xmove:
    case Xarc:
    case Xspline:
      With->endpos_.xpos = 0.0;
      With->endpos_.ypos = 0.0;
      With->lineheight_ = 0.0;
      With->linewidth_ = 0.0;
      With->linefill_ = -1.0;
      With->aradius_ = mdistmax;
      With->lineatype_ = pahlex(0, XEMPTY);
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
{ if (pr->arcangle_ > 0.0) {
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
{ primitive *With;

  while (pr != NULL) {
    With = pr;
    With->aat.xpos *= s;
    With->aat.ypos *= s;
    if (With->ptype == Xbox) {
	  With->boxheight_ *= s;
	  With->boxwidth_ *= s;
	  With->boxradius_ *= s;
      }
    else if (With->ptype == Xblock) {
	  With->blockheight_ *= s;
	  With->blockwidth_ *= s;
      }
    else if (With->ptype == Xcircle) {
	  With->circleradius_ *= s;
      }
    else if (With->ptype == Xellipse) {
	  With->ellipseheight_ *= s;
	  With->ellipsewidth_ *= s;
      }
    else if (With->ptype == Xarc) {
	  With->aradius_ *= s;
      }
    else if ((With->ptype == Xspline) || (With->ptype == Xmove) ||
	       (With->ptype == Xarrow) || (With->ptype == Xline)) {
	  With->endpos_.xpos *= s;
	  With->endpos_.ypos *= s;
      }
    if (With->son != NULL) {
	  scaleobj(With->son, s);
      }
    pr = With->nextname;
    }
}

							/* corner(prim,<corner>,xval,yval); Put the
							   named-corner coordinates into xval,yval   */
void
corner(primitive *pr, int lexv, double *x, double *y)
{ primitive *pe;
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
	      case XDotn: *y = north; break;
	      case XDots: *y = south; break;
	      case XDote: *x = east; break;
	      case XDotw: *x = west; break;
	      case XDotne: *y = north; *x = east; break;
	      case XDotse: *y = south; *x = east; break;
	      case XDotsw: *y = south; *x = west; break;
	      case XDotnw: *y = north; *x = west; break;
	      case XDotc: *y = pr->aat.ypos; *x = pr->aat.xpos; break;
	      case XDotstart:
	      case XDotend: markerror(858); break;
	      }
	    checkjust(pr->textp, &A, &B, &L, &R);
	    if (L) { pr->boxradius_ = (west - east) / 2; }
	    else if (R) { pr->boxradius_ = (east - west) / 2; }
        }
      else if (((pr->ptype == Xarc) || (pr->ptype == Xcircle) ||
	      (pr->ptype == Xellipse) || (pr->ptype == Xbox)) &&
	     ((lexv == XDotnw) || (lexv == XDotsw) || (lexv == XDotse) ||
	      (lexv == XDotne))) {
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
	    case XDotne: /* blank case */ break;
	    case XDotse: *y = -*y; break;
	    case XDotnw: *x = -*x; break;
	    case XDotsw: *x = -*x; *y = -*y; break;
	    }
	    *x = pr->aat.xpos + (*x);
	    *y = pr->aat.ypos + (*y);
        }
      else if (pr->ptype == Xarc) {
	    switch (lexv) {
	    case XDotn: *y = pr->aat.ypos + pr->aradius_; break;
	    case XDots: *y = pr->aat.ypos - pr->aradius_; break;
	    case XDote: *x = pr->aat.xpos + pr->aradius_; break;
	    case XDotw: *x = pr->aat.xpos - pr->aradius_; break;
	    case XDotc: /* blank case */ break;
	    case XDotstart:
	      *x = pr->aat.xpos + (pr->aradius_ * cos(pr->startangle_));
	      *y = pr->aat.ypos + (pr->aradius_ * sin(pr->startangle_));
	      break;
	    case XDotend:
	      *x = pr->aat.xpos +
                 (pr->aradius_ * cos(pr->startangle_+pr->arcangle_));
	      *y = pr->aat.ypos +
                 (pr->aradius_ * sin(pr->startangle_+pr->arcangle_));
	      break;
	    } }
      else {
	    switch (lexv) {
	    case XDotn: *y = north; break;
	    case XDots: *y = south; break;
	    case XDote: *x = east; break;
	    case XDotw: *x = west; break;
	    case XDotne: *y = north; *x = east; break;
	    case XDotse: *y = south; *x = east; break;
	    case XDotsw: *y = south; *x = west; break;
	    case XDotnw: *y = north; *x = west; break;
	    case XDotc: *y = pr->aat.ypos; *x = pr->aat.xpos; break;
	    case XDotstart:
	    case XDotend: markerror(858); break;
	    } }
      break;

    case Xline:
    case Xarrow:
    case Xmove:
    case Xspline:
      if (lexv != XDotstart) {
	if (lexv == XDotend) {
	    while (pe->son != NULL) { pe = pe->son; }
	    *x = pe->endpos_.xpos;
	    *y = pe->endpos_.ypos; }
	else if (lexv == XDotc) {
	    while (pe->son != NULL) { pe = pe->son; }
	    *x = 0.5 * ((*x) + pe->endpos_.xpos);
	    *y = 0.5 * ((*y) + pe->endpos_.ypos); }
	else {
	    do {
		  sb = false;
		  switch (lexv) {
		  case XDotn:
		    sb = (pe->endpos_.ypos > (*y));
		    break;
		  case XDots:
		    sb = (pe->endpos_.ypos < (*y));
		    break;
		  case XDote:
		    sb = (pe->endpos_.xpos > (*x));
		    break;
		  case XDotw:
		    sb = (pe->endpos_.xpos < (*x));
		    break;
		  case XDotne:
		    sb = (((pe->endpos_.ypos > (*y)) && (pe->endpos_.xpos >= (*x))) ||
			  ((pe->endpos_.ypos >= (*y)) && (pe->endpos_.xpos > (*x))));
		    break;
		  case XDotse:
		    sb = (((pe->endpos_.ypos < (*y)) && (pe->endpos_.xpos >= (*x))) ||
			  ((pe->endpos_.ypos <= (*y)) && (pe->endpos_.xpos > (*x))));
		    break;
		  case XDotsw:
		    sb = (((pe->endpos_.ypos < (*y)) && (pe->endpos_.xpos <= (*x))) ||
			  ((pe->endpos_.ypos <= (*y)) && (pe->endpos_.xpos < (*x))));
		    break;
		  case XDotnw:
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
{ primitive *prp = NULL;
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
{ environx i, last;

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
{ environx i;
  primitive *pr;

  pr = findenv(envbl);
  if (pr == NULL) { resetenv(0, envbl); return; }
  envbl->blockparms.env = malloc(sizeof(envarray));
  for (i = XXenvvar; i <= (Xlastenv - 1); i++) {
      envbl->blockparms.env[i - XXenvvar] = pr->blockparms.env[i - XXenvvar];
  }
}


							/* Execute scale = x */
void
resetscale(double x, int opr, primitive *envbl)
{ double r, s;
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
{ double gs = 1.0;
  int erno = 0;
  primitive *qp;

  *sfact = gs;
  if (lp != NULL) {
      if (lp->ptype == Xblock) {
	  qp = findenv(lp);
	  if (qp->blockparms.env[Xscale - XXenvvar - 1] > 0.0) {
	      *sfact = qp->blockparms.env[Xscale - XXenvvar - 1];
	  }
	  if ((east > west) &&
	      ((east - west) / (*sfact) >
	       qp->blockparms.env[Xmaxpswid - XXenvvar - 1]) &&
	      (qp->blockparms.env[Xmaxpswid - XXenvvar - 1] > 0.0)) {
	      erno = 903;
	      gs = (east - west) / qp->blockparms.env[Xmaxpswid - XXenvvar - 1];
	  }
	  if ((north > south) &&
	      ((north - south) / (*sfact) >
	       qp->blockparms.env[Xmaxpsht - XXenvvar - 1]) &&
	      (qp->blockparms.env[Xmaxpsht - XXenvvar - 1] > 0.0)) {
	      erno = 904;
	      gs = Max(gs,
		  (north - south) / qp->blockparms.env[Xmaxpsht - XXenvvar - 1]);
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
  if (erno != 0) {
      markerror(erno);
  }
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
	  while ((prx->nextname != NULL) && (prx->nextname != (*pr))) { prx = prx->nextname;}
	  prx->nextname = NULL; }
    }
  deletetree(pr);
}

void
dostart(void)
{
    makevar("dpicopt", 7, drawmode);
    if (safemode) { i = 1; } else { i = 0; }
    makevar("optsafe", 7, i);
    makevar("optMFpic", 8, MFpic);
    makevar("optMpost", 8, MPost);
    makevar("optPDF", 6, PDF);
    makevar("optPGF", 6, PGF);
    makevar("optPict2e", 9, Pict2e);
    makevar("optPS", 5, PS);
    makevar("optPSfrag", 9, PSfrag);
    makevar("optPSTricks", 11, PSTricks);
    makevar("optSVG", 6, SVG);
    makevar("optTeX", 6, TeX);
    makevar("opttTeX", 7, tTeX);
    makevar("optxfig", 7, xfig);
    if ((drawmode == SVG) || (drawmode == PDF) || (drawmode == PS)) {
	  makevar("dptextratio", 11, 0.66);
	  makevar("dpPPI", 5, 96.0);
      }
    else if (drawmode == xfig) {
	  makevar("xfigres", 7, 1200);
	  makevar("xdispres", 8, 80);
      }
}

							/* The program equivalent of var = number */
void
makevar(Char *s, int ln, double varval)
{ nametype *vn, *lastvar, *namptr;
  int j, k;
  primitive *With;
  for (j = 0; j < ln; j++) { chbuf[chbufi + j] = s[j]; }
  vn = findname(envblock, chbuf, chbufi, ln, &lastvar, &k);
  newstr(&vn);
  j = varhash(chbuf, chbufi, ln);
  storestring(vn, chbuf, chbufi, ln, 1);
#ifdef DDEBUG
  if (debuglevel > 1) {
    fprintf(log_, "makevar: envblock=%d eqstr val=%d\n", ordp(envblock), k);
    fprintf(log_, " lastvar=%d", ordp(lastvar));
    if (lastvar != NULL) {
	  snapname(lastvar->segmnt, lastvar->seginx, lastvar->len); }
    putc('\n', log_);
    }
#endif
  With = envblock;
#ifdef DDEBUG
  if (debuglevel > 1) { fprintf(log_, " vn=%d\n", ordp(vn)); }
#endif
  if (lastvar == NULL) { With->blockparms.vars[j] = vn; }
  else if (k < 0) {
    if (With->blockparms.vars[j]->nextname == NULL) {
	  With->blockparms.vars[j]->nextname = vn; }
    else {
	  vn->nextname = lastvar->nextname;
	  lastvar->nextname = vn; }
    }
  else if (lastvar == With->blockparms.vars[j]) {
    vn->nextname = With->blockparms.vars[j];
    With->blockparms.vars[j] = vn;
    }
  else {
    namptr = With->blockparms.vars[j];
    while (namptr->nextname != lastvar) { namptr = namptr->nextname; }
    namptr->nextname = vn;
    vn->nextname = lastvar;
    }
  With->blockparms.nvars[j]++;
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
	    With2 = a1->prim;
	    i = getstval(a1->state);
	    if (i == Xfloat) {  /* pair at */
		  getnesw(a1->prim);
		  dx = west + a1->startchop;
		  dy = south + a1->endchop;
	      }
	    else if (a1->internal != NULL) { corner(a1->internal, i, &dx, &dy); }
	    else { corner(a1->prim, i, &dx, &dy); }
	    a1->internal = NULL;
	    if ((drawmode == SVG) && (With2->ptype == Xstring)) {
		  ts = venv(a1->prim, Xtextoffset);
		  if (teststflag(a1->state, Xcw)) {    /* shift by arg2,arg3 */
		    switch (i) {                                   /* textpos */
		      case XDote:  dx += ts; break;
		      case XDotne: dx += ts; dy += ts; break;
		      case XDotn:  dy += ts; break;
		      case XDotnw: dx -= ts; dy += ts; break;
		      case XDotw:  dx -= ts; break;
		      case XDotsw: dx -= ts; dy -= ts; break;
		      case XDots:  dy -= ts; break;
		      case XDotse: dx += ts; dy -= ts; break;
		      }
		    }
		  shift(a1->prim, a1->xval - dx, a1->yval - dy);
	      }
	    else if (With2->ptype != Xarc) {
		  shift(a1->prim, a1->xval - dx, a1->yval - dy); }
	    else {
		  x1 = With2->aat.xpos +
		     (With2->aradius_ * cos(With2->startangle_));
							/* from */
		  z1 = With2->aat.ypos +
		     (With2->aradius_ * sin(With2->startangle_));
		  if (teststflag(a1->state, Xto)) {
							/* to X from Here|Y implied */
		    if ((i != XEMPTY) && (i != XDotc)) { markerror(858); }
		    r = With2->aat.xpos + (With2->aradius_ *
                  cos(With2->startangle_ + With2->arcangle_));
		    s = With2->aat.ypos + (With2->aradius_ *
                  sin(With2->startangle_ + With2->arcangle_));
		    With2->aat.xpos = a1->xval;
		    With2->aat.ypos = a1->yval;
		    With2->aradius_ = linlen(r - With2->aat.xpos, s - With2->aat.ypos);
		    setangles(&With2->startangle_,
			      &With2->arcangle_, With2->aat, x1, z1, r, s);
		    }
		  else if (teststflag(a1->state, Xfrom)) {
		    if ((i != XEMPTY) && (i != XDotc)) { markerror(858); }
		    With2->aat.xpos = a1->xval;
		    With2->aat.ypos = a1->yval;
		    t = datan(z1 - With2->aat.ypos, x1 - With2->aat.xpos);
		    r = With2->aat.xpos + (With2->aradius_ * cos(t + With2->arcangle_));
		    s = With2->aat.ypos + (With2->aradius_ * sin(t + With2->arcangle_));
		    With2->aradius_ = linlen(x1 - With2->aat.xpos,z1 - With2->aat.ypos);
		    setangles(&With2->startangle_, &With2->arcangle_, With2->aat,
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
        if (instring) { markerror(807); } else { markerror(804); }
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
        if (instring) { markerror(807); } else { markerror(804); }
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
      fprintf(log_, "\nreadfor done: for/macro buffer"); wrbuf(p1, 3, 0); }
#endif
  *p2 = p1;
}

void
queueprim(primitive *pr, primitive *envblk)
{ primitive *pp;
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
clearchbuf(chbufinx bi, int ln)
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
{ fbuffer *Withargbody;
  Char lastc;
  macp = findmacro(macros, chbuf, a0->chbufx, a0->toklen, &lastp);
  if (macp == NULL) {
	newarg(&macp);
	if (lastp == NULL) { macros = macp; } else { lastp->nexta = macp; }
    }
  disposebufs(&(macp->argbody));
  newbuf(&(macp->argbody));
  Withargbody = macp->argbody;
							/* copy the macro name */
  FORLIM = a0->toklen;
  for (i = 1; i <= FORLIM; i++) {
    Withargbody->carray[i] = chbuf[a0->chbufx + i - 1]; }
  Withargbody->savedlen = a0->toklen;
  Withargbody->readx = a0->toklen + 1;
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
	wrbuf(macp->argbody, 3, 0); }
#endif
  }

void
dosprintf( attribute *a0, attribute *a3, attribute *a5, int nexprs )
{ newprim(&a0->prim, Xstring, envblock);
  With2 = a0->prim;
  eb = findenv(envblock);
#ifdef DDEBUG
  if (debuglevel > 0) {
	fprintf(log_,"sprintf nexprs=%d\n",nexprs);
	printobject(a3->prim);
	if (eb == NULL) { fprintf(log_, " ! sprintf_i: eb=nil\n"); }
	else if (eb->blockparms.env == NULL) {
	    fprintf(log_, " ! sprintf_i: env=nil\n"); } }
#endif
  With2->boxheight_ = eb->envinx(Xtextht);
  With2->boxwidth_ = eb->envinx(Xtextwid);
  With2->boxradius_ = 0.0;
  newstr(&With2->textp);
  if (tmpbuf == NULL) { tmpbuf = malloc(sizeof(chbufarray)); }
  if (tmpfmt == NULL) { tmpfmt = malloc(sizeof(chbufarray)); }
  i = 0;                                        /* expression count */
  j = 0;                                /* end of current substring */
  lj = j;                             /* start of current substring */
  kk = 0;                                        /* substring count */
  if (a3->prim == NULL) { /* nil */ }
  else if (a3->prim->textp == NULL) { /* nil */ }
  else {  /*-- */
	With4 = a3->prim->textp;
	while (j < With4->len) {
#ifdef DDEBUG
	  if (debuglevel > 0) {
        fprintf(log_,
                  " nexprs=%d expr no i=%d string start=%d len=%d\n",
          nexprs,i,lj,With4->len);
		fprintf(log_," sprintf looping, j=%4d c=\"%c\"\n",
		  j, With4->segmnt[With4->seginx + j]);
	  fflush(log_); }
#endif
      if (With4->segmnt[With4->seginx + j] != '%') {
        j++;
        if (j == With4->len) { kk = putstring(kk, a0->prim->textp,
      	  With4->segmnt, With4->seginx + lj, j - lj); }
        continue;
        }
      if (With4->segmnt[With4->seginx + j + 1] == '%') {/* %% prints %*/
        kk = putstring(kk, a0->prim->textp, With4->segmnt,
      	  With4->seginx + lj, j - lj + 1);
        j += 2;
        lj = j;
        continue;
        }
      if (i >= nexprs) {  /* not enough exprs */
        markerror(864); j = With4->len; continue; }
      if (j > lj) {
        kk = putstring(kk, a0->prim->textp, With4->segmnt,
      	  With4->seginx + lj, j - lj);
        lj = j; }
      k = With4->len;
      j++;
      if (With4->segmnt[With4->seginx + j] == '-') { j++; }
      while (j < k) {
	    cy = With4->segmnt[With4->seginx + j];
        if ((cy=='g') || (cy=='f') || (cy=='e')) { k = j; }
        else if ((cy=='.') || isdigit(cy)) { j++; }
        else { j = k; }
        }
      ts = a5->xval;
	  a5++; a5++;
      if (k == With4->len) { markerror(865); continue; }
      j++;
#ifdef DDEBUG
      if (debuglevel > 0) { int kv;
        fprintf(log_, "format=\"");
        for (kv = lj; kv < j; kv++) {
          putc(With4->segmnt[With4->seginx + kv], log_); }
        fprintf(log_, "\" nexprs=%2d Numerical print value=", nexprs);
        wfloat(&log_, ts); putc('\n', log_); fflush(log_); }
#endif
      if (j - lj + 1 > CHBUFSIZ) {
        markerror(873); ll = 0; j = With4->len; }
      else {
        for (ll = lj; ll <= (j - 2); ll++) {
          tmpfmt[ll - lj] = With4->segmnt[With4->seginx + ll]; }
        tmpfmt[j - lj - 1] = 'L';
        tmpfmt[j - lj] = With4->segmnt[With4->seginx + j - 1];
        tmpfmt[j - lj + 1] = '\0';
        ll = snprintf(tmpbuf,CHBUFSIZ,tmpfmt, (long double) ts);
        }
      if (ll < 0) { markerror(874); j = With4->len; }
      else if (ll > CHBUFSIZ) { markerror(874);
                ll = CHBUFSIZ; j = With4->len; }
#ifdef DDEBUG
      if (debuglevel > 0) { int kv;
        fprintf(log_, " ll=%d", ll);
        if (ll > 0) {
          fprintf(log_, " tmpbuf(0:%d)=", ll - 1);
          for (kv = 0; kv < ll; kv++) { putc(tmpbuf[kv], log_); } }
        putc('\n', log_); fflush(log_); }
#endif
							/* Copy tmpbuf to the string */
      if (ll > 0) { kk = putstring(kk, a0->prim->textp, tmpbuf, 0, ll);}
      i++;
      lj = j;
	  }
    } /*  --*/
  if (nexprs > i) { markerror(864); }               /* Too many exprs */
  if (drawmode == xfig) {
	With2 = a0->prim;
	if (With2->boxwidth_ == 0.0) {
	  if (With2->boxheight_ == 0.0) {
		With2->boxheight_ =
		  0.1 * eb->envinx(Xscale); }
	  if (With2->textp != NULL) {
		With2->boxwidth_ = With2->boxheight_ *
					  With2->textp->len * 0.75; }
	  }
    }
  else if ((drawmode == PDF) && (With2->textp != NULL)) {
	  With2->boxwidth_ = With2->boxheight_ *
				      With2->textp->len * 0.6; }
  if (envblock->son == a3->prim) { envblock->son = a0->prim; }
  deletestringbox(&(a3->prim));
}

#ifdef DDEBUG
int ordp(void *p)       { return (p==NULL)?(int) 0 : (int) abs((long)p); }
#endif
