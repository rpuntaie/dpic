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
#line 34 "dpic.y" /* yacc.c:339  */

#define EXTRN extern
#include "dpic.h"
#define Rnd(x)	((long)floor(x + 0.5))

#define envinx(x)	blockparms.env[(int)(Rnd(x)-XLenvvar-1)]

int yyerror(char*);

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
extern void setjust(nametype *, int);
extern void skipcontinue(boolean);
extern void skiptobrace(void);
extern void skiptoend(void);
extern void wcoord(FILE **, double, double);
extern void wfloat(FILE **, double);
extern void wpair(FILE **, double, double);
extern void wstring(FILE **, nametype *);

typedef double envarray[XLlastenv - XXenvvar];

#line 176 "dpic.y" /* yacc.c:339  */

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

#line 219 "dpic.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    XEOF = 1,
    XEMPTY = 2,
    XERROR = 3,
    XLT = 4,
    XLcw = 5,
    XLccw = 6,
    Xlparen = 7,
    Xrparen = 8,
    Xmult = 9,
    Xplus = 10,
    Xminus = 11,
    Xdiv = 12,
    Xpercent = 13,
    XNL = 14,
    Xcaret = 15,
    XNOT = 16,
    XANDAND = 17,
    XOROR = 18,
    Xcomma = 19,
    XCOLON = 20,
    XBRACKETL = 21,
    XBRACKETR = 22,
    XLBRACE = 23,
    XRBRACE = 24,
    Xdot = 25,
    XBLOCK = 26,
    XSLQ = 27,
    XSRQ = 28,
    XEQ = 29,
    XLcoloneq = 30,
    XLpluseq = 31,
    XLminuseq = 32,
    XLmulteq = 33,
    XLdiveq = 34,
    XLremeq = 35,
    XAND = 36,
    XLfloat = 37,
    XLname = 38,
    XLabel = 39,
    XLaTeX = 40,
    XLstring = 41,
    XCOMMENT = 42,
    XLarg = 43,
    XSTART = 44,
    XEND = 45,
    XLht = 46,
    XLwid = 47,
    XLrad = 48,
    XLdiam = 49,
    XLthick = 50,
    XLscaled = 51,
    XLfrom = 52,
    XLto = 53,
    XLat = 54,
    XLwith = 55,
    XLby = 56,
    XLthen = 57,
    XLcontinue = 58,
    XLchop = 59,
    XLsame = 60,
    XLof = 61,
    XLthe = 62,
    XLway = 63,
    XLbetween = 64,
    XLand = 65,
    XLHere = 66,
    XLnth = 67,
    XLlast = 68,
    XLfill = 69,
    XLdx = 70,
    XLdy = 71,
    XLprint = 72,
    XLcopy = 73,
    XLreset = 74,
    XLexec = 75,
    XLsh = 76,
    XLcommand = 77,
    XLdefine = 78,
    XLundefine = 79,
    XLrand = 80,
    XLif = 81,
    XLelse = 82,
    XFOR = 83,
    XLdo = 84,
    XLendfor = 85,
    XLsprintf = 86,
    XLcorner = 87,
    XDne = 88,
    XDse = 89,
    XDnw = 90,
    XDsw = 91,
    XDn = 92,
    XDs = 93,
    XDe = 94,
    XDw = 95,
    XDstart = 96,
    XDend = 97,
    XDc = 98,
    XLcompare = 99,
    XEQEQ = 100,
    XNEQ = 101,
    XGE = 102,
    XLE = 103,
    XGT = 104,
    XLparam = 105,
    XLheight = 106,
    XLwidth = 107,
    XLradius = 108,
    XLdiameter = 109,
    XLthickness = 110,
    XLlength = 111,
    XLfunc1 = 112,
    XLabs = 113,
    XLacos = 114,
    XLasin = 115,
    XLcos = 116,
    XLexp = 117,
    XLexpe = 118,
    XLint = 119,
    XLlog = 120,
    XLloge = 121,
    XLsign = 122,
    XLsin = 123,
    XLsqrt = 124,
    XLtan = 125,
    XLfloor = 126,
    XLfunc2 = 127,
    XLatan2 = 128,
    XLmax = 129,
    XLmin = 130,
    XLpmod = 131,
    XLlinetype = 132,
    XLsolid = 133,
    XLdotted = 134,
    XLdashed = 135,
    XLinvis = 136,
    XLcolrspec = 137,
    XLcolour = 138,
    XLoutlined = 139,
    XLshaded = 140,
    XLtextpos = 141,
    XLcenter = 142,
    XLljust = 143,
    XLrjust = 144,
    XLabove = 145,
    XLbelow = 146,
    XLarrowhd = 147,
    XLEFTHEAD = 148,
    XRIGHTHEAD = 149,
    XDOUBLEHEAD = 150,
    XLdirecton = 151,
    XLup = 152,
    XLdown = 153,
    XLright = 154,
    XLleft = 155,
    XLprimitiv = 156,
    XLbox = 157,
    XLcircle = 158,
    XLellipse = 159,
    XLarc = 160,
    XLline = 161,
    XLarrow = 162,
    XLmove = 163,
    XLspline = 164,
    XLenvvar = 165,
    XLarcrad = 166,
    XLarrowht = 167,
    XLarrowwid = 168,
    XLboxht = 169,
    XLboxrad = 170,
    XLboxwid = 171,
    XLcirclerad = 172,
    XLdashwid = 173,
    XLellipseht = 174,
    XLellipsewid = 175,
    XLlineht = 176,
    XLlinewid = 177,
    XLmoveht = 178,
    XLmovewid = 179,
    XLtextht = 180,
    XLtextoffset = 181,
    XLtextwid = 182,
    XLarrowhead = 183,
    XLfillval = 184,
    XLlinethick = 185,
    XLmaxpsht = 186,
    XLmaxpswid = 187,
    XLscale = 188
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
#define YYNTOKENS  191
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
     182,   183,   184,   185,   186,   187,   188,   189,   190,     2,
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
       0,   390,   390,   392,   408,   483,   485,   489,   492,   495,
     499,   501,   509,   518,   520,   523,   528,   536,   583,   607,
     609,   612,   619,   621,   632,   634,   636,   638,   648,   672,
     678,   681,   701,   703,   706,   714,   717,   722,   729,   742,
     744,   748,   760,   773,   789,   792,   794,   796,   807,   813,
     820,   824,   829,   831,   834,   837,   841,   848,   852,   862,
     883,   914,   918,   972,   999,  1001,  1004,  1006,  1009,  1012,
    1015,  1019,  1029,  1033,  1035,  1041,  1090,  1132,  1135,  1139,
    1141,  1146,  1148,  1166,  1186,  1189,  1193,  1217,  1220,  1224,
    1227,  1231,  1233,  1319,  1399,  1461,  1488,  1499,  1600,  1662,
    1683,  1706,  1751,  1769,  1781,  1815,  1841,  1968,  2000,  2021,
    2056,  2152,  2170,  2216,  2254,  2263,  2272,  2288,  2307,  2318,
    2476,  2481,  2533,  2542,  2544,  2547,  2559,  2561,  2577,  2587,
    2594,  2601,  2606,  2611,  2615,  2617,  2619,  2621,  2626,  2631,
    2637,  2644,  2647,  2652,  2654,  2659,  2668,  2671,  2674,  2678,
    2682,  2688,  2690,  2695,  2707,  2723,  2735,  2746,  2754,  2756,
    2759,  2763,  2765,  2771,  2779,  2788,  2794,  2796,  2798,  2822,
    2843,  2850,  2859,  2861,  2864,  2866,  2869,  2924,  2927,  2932,
    2982,  3002,  3005
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "XEOF", "XEMPTY", "XERROR", "XLT",
  "XLcw", "XLccw", "Xlparen", "Xrparen", "Xmult", "Xplus", "Xminus",
  "Xdiv", "Xpercent", "XNL", "Xcaret", "XNOT", "XANDAND", "XOROR",
  "Xcomma", "XCOLON", "XBRACKETL", "XBRACKETR", "XLBRACE", "XRBRACE",
  "Xdot", "XBLOCK", "XSLQ", "XSRQ", "XEQ", "XLcoloneq", "XLpluseq",
  "XLminuseq", "XLmulteq", "XLdiveq", "XLremeq", "XAND", "XLfloat",
  "XLname", "XLabel", "XLaTeX", "XLstring", "XCOMMENT", "XLarg", "XSTART",
  "XEND", "XLht", "XLwid", "XLrad", "XLdiam", "XLthick", "XLscaled",
  "XLfrom", "XLto", "XLat", "XLwith", "XLby", "XLthen", "XLcontinue",
  "XLchop", "XLsame", "XLof", "XLthe", "XLway", "XLbetween", "XLand",
  "XLHere", "XLnth", "XLlast", "XLfill", "XLdx", "XLdy", "XLprint",
  "XLcopy", "XLreset", "XLexec", "XLsh", "XLcommand", "XLdefine",
  "XLundefine", "XLrand", "XLif", "XLelse", "XFOR", "XLdo", "XLendfor",
  "XLsprintf", "XLcorner", "XDne", "XDse", "XDnw", "XDsw", "XDn", "XDs",
  "XDe", "XDw", "XDstart", "XDend", "XDc", "XLcompare", "XEQEQ", "XNEQ",
  "XGE", "XLE", "XGT", "XLparam", "XLheight", "XLwidth", "XLradius",
  "XLdiameter", "XLthickness", "XLlength", "XLfunc1", "XLabs", "XLacos",
  "XLasin", "XLcos", "XLexp", "XLexpe", "XLint", "XLlog", "XLloge",
  "XLsign", "XLsin", "XLsqrt", "XLtan", "XLfloor", "XLfunc2", "XLatan2",
  "XLmax", "XLmin", "XLpmod", "XLlinetype", "XLsolid", "XLdotted",
  "XLdashed", "XLinvis", "XLcolrspec", "XLcolour", "XLoutlined",
  "XLshaded", "XLtextpos", "XLcenter", "XLljust", "XLrjust", "XLabove",
  "XLbelow", "XLarrowhd", "XLEFTHEAD", "XRIGHTHEAD", "XDOUBLEHEAD",
  "XLdirecton", "XLup", "XLdown", "XLright", "XLleft", "XLprimitiv",
  "XLbox", "XLcircle", "XLellipse", "XLarc", "XLline", "XLarrow", "XLmove",
  "XLspline", "XLenvvar", "XLarcrad", "XLarrowht", "XLarrowwid", "XLboxht",
  "XLboxrad", "XLboxwid", "XLcirclerad", "XLdashwid", "XLellipseht",
  "XLellipsewid", "XLlineht", "XLlinewid", "XLmoveht", "XLmovewid",
  "XLtextht", "XLtextoffset", "XLtextwid", "XLarrowhead", "XLfillval",
  "XLlinethick", "XLmaxpsht", "XLmaxpswid", "XLscale", "$accept", "input",
  "picture", "NL", "start", "elementlist", "term", "element", "lbrace",
  "namedobj", "suffix", "position", "assignlist", "command", "optnl",
  "ifpart", "elsehead", "for", "stringexpr", "string", "assignment",
  "assignrhs", "expression", "ifhead", "setlogic", "logexpr", "forhead",
  "forincr", "do", "by", "redirect", "resetlist", "systemcmd", "sprintf",
  "exprlist", "object", "openblock", "block", "optexp", "closeblock",
  "objectwith", "pair", "nth", "primobj", "shift", "location", "place",
  "factor", "placename", "ncount", "logprod", "logval", "lcompare",
  "primary", YY_NULLPTR
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
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188
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
    -159,    21,  -159,   613,    59,    59,   333,   577,   519,   519,
      24,    41,    41,  -159,  -159,    92,   219,    96,   108,  -159,
     483,    -3,    22,  -159,  -159,    -8,    52,   130,  -159,  -159,
    -159,   633,   613,   613,    41,  -159,   -15,   125,   145,   152,
      58,   149,   182,  -159,  -159,   233,    36,   179,   200,  -159,
      22,   173,  -159,   121,  -159,    98,   141,   519,  -159,  -159,
     501,  -159,   123,   197,   519,   519,   613,   613,   613,   152,
     208,  -159,  -159,  -159,  -159,   613,   613,  -159,  -159,   238,
    -159,  -159,   165,   613,  -159,  -159,  -159,    41,    41,  -159,
    -159,   366,   -15,    71,   -15,   -15,    89,   144,  -159,   -23,
    -159,   519,   145,    25,  -159,   633,  -159,   205,  -159,   163,
     633,   -11,   228,   633,   366,   633,  -159,   697,   633,  -159,
     447,   152,   152,   225,   228,   -15,   555,  -159,   519,  -159,
     -23,   -15,   -15,   519,   613,   613,   519,   195,   519,  -159,
     366,  -159,  -159,   252,   366,   366,  -159,  -159,   247,   162,
    -159,   240,   197,   271,   148,  -159,  -159,  -159,  -159,  -159,
    -159,    41,    -3,  -159,  -159,   225,   254,   177,    -4,    17,
     228,  -159,   269,   228,   228,  -159,  -159,  -159,  -159,    37,
     273,  -159,   633,   246,   156,   280,   156,  -159,  -159,   633,
     156,   249,    -2,    11,  -159,  -159,   519,   519,   519,   519,
     519,   519,   519,   519,   519,  -159,   519,  -159,   519,  -159,
     519,   519,   -15,  -159,   519,   519,   228,    47,   287,   285,
     519,   117,   178,   259,   555,    38,  -159,  -159,   273,   307,
     387,  -159,   228,  -159,   299,   387,   152,   152,   273,   262,
     263,   173,   202,   202,  -159,   228,   273,  -159,   519,  -159,
    -159,  -159,   519,  -159,  -159,   300,   -27,  -159,  -159,  -159,
     164,   519,  -159,  -159,   306,  -159,   308,    11,   310,   519,
     319,  -159,   273,   273,   273,   273,   273,   273,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,   228,  -159,  -159,  -159,  -159,
      41,    -3,  -159,   519,   519,  -159,   519,  -159,   519,   267,
     519,   519,   207,    18,   207,   294,  -159,   697,   -15,   228,
    -159,    42,  -159,  -159,  -159,  -159,   273,  -159,  -159,  -159,
    -159,  -159,   196,  -159,   251,   519,  -159,  -159,   228,   339,
    -159,   328,   519,   519,  -159,   292,  -159,  -159,    30,  -159,
     252,   519,  -159,  -159
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
    -159,  -159,  -159,   293,  -159,   -66,     2,   172,  -159,  -159,
     -10,   -25,     3,  -159,  -102,  -159,  -159,  -159,    -5,   229,
    -120,   139,     5,  -159,  -159,   253,  -159,  -159,  -159,  -159,
     153,  -159,   359,  -159,    33,   114,  -159,  -159,   209,  -159,
    -159,   257,   -76,  -158,    46,    -6,  -159,   281,    -9,  -159,
     231,   237,  -159,   376
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
      50,    42,    59,   162,   254,    20,   226,    63,   132,    41,
     231,    45,    28,    55,    56,   187,    35,    87,   140,    79,
      70,     2,    69,   248,   123,    71,    28,    29,    35,   134,
     135,   124,   148,    75,   121,   122,    76,   -52,   136,   184,
      72,    29,   134,   135,   186,    79,   139,   190,    28,   193,
     132,    50,   217,   152,   134,   135,   140,   270,   130,   296,
      28,    37,   149,    29,    57,   151,   167,     3,   127,   153,
     154,   -52,   -52,    37,   308,    29,   188,   165,   166,   128,
     137,    80,   264,   138,   266,    50,   168,   170,   268,   173,
     174,   271,   261,  -158,    77,    78,   169,   256,   -52,    81,
     329,    60,   179,   229,   226,    64,   180,    80,   234,    42,
     134,   135,   216,   240,    50,   288,   342,    65,   256,   191,
     225,    82,    50,   267,   146,   222,   232,    50,   330,   175,
     176,   228,    50,   319,   125,    42,   236,   237,   235,    42,
     245,   238,     8,   291,   102,   191,     9,    83,     8,   191,
     246,   253,     9,   134,   135,    73,    61,    28,    12,   129,
     134,   135,    61,    66,    12,   314,    67,    68,   248,   252,
     130,   147,    29,   293,   134,   135,   126,   278,   279,   280,
      62,   281,   -52,   136,   177,   178,   249,    14,   131,   141,
     134,   135,   144,    14,   132,   292,    50,    50,    50,   136,
      50,   272,   273,   274,   275,   276,   277,   285,   134,   135,
     142,   301,    63,   180,    50,   180,   180,   333,    75,   180,
     180,    76,   145,   234,    79,   137,   130,     8,   138,   228,
     306,     9,   158,   303,   303,   163,   302,   304,   171,   133,
     132,    61,    50,    12,     8,   134,   135,   185,     9,    50,
     250,   309,   134,   135,   136,   269,   224,   305,    61,   239,
      12,   134,   135,     8,   242,   243,   311,     9,   320,   321,
      13,   247,    14,   324,   316,   326,   255,    61,   256,   161,
     318,   251,    62,   134,   135,   134,   135,    50,    50,    14,
     260,    16,    50,   263,    50,    50,   137,    30,    31,   138,
     335,   322,   216,   328,   327,   265,   134,   135,    14,     6,
       8,   289,    32,    33,     9,   294,   343,   297,     7,    50,
     298,   258,   259,    84,    61,     8,   290,   299,    86,     9,
     300,   310,   312,   325,   313,    50,   315,   338,   322,    10,
      11,    12,     6,    35,   317,    32,    33,   155,   156,   157,
     336,     7,   334,   337,   262,    14,   159,   160,     8,   341,
      90,   233,     9,   295,   164,    47,   339,   192,    13,   307,
      14,   241,    10,    34,    12,     6,    35,   223,    32,    33,
     340,   244,    15,    54,     7,     0,     0,     0,    37,    16,
       0,     8,     0,   248,     0,     9,     0,     0,     0,   134,
     135,    13,     0,    14,     0,    10,    11,    12,   136,    35,
       0,    36,     0,     0,    17,    15,     0,   282,     0,   283,
     284,    37,    16,   286,   287,     0,     0,     0,     0,    18,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    15,     0,
     137,     0,     0,   138,    37,    16,     6,     0,   101,    32,
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
       6,     6,    12,    79,   162,     3,   126,    16,    12,     6,
     130,     6,     1,     8,     9,    26,    43,    40,    20,    27,
      23,     0,    20,     6,    34,    28,     1,    16,    43,    12,
      13,    36,    57,    11,    32,    33,    14,    26,    21,   105,
      43,    16,    12,    13,   110,    27,    10,   113,     1,   115,
      12,    57,   118,    62,    12,    13,    20,    59,    21,    21,
       1,    88,    57,    16,    23,    60,    91,    46,    10,    64,
      65,    24,    47,    88,   101,    16,    87,    87,    88,    21,
      63,    89,   184,    66,   186,    91,    91,    92,   190,    94,
      95,   193,    55,    69,    72,    73,    91,   101,    87,   107,
      58,     9,    99,   128,   224,     9,   101,    89,   133,   114,
      12,    13,   117,   138,   120,   217,    86,     9,   101,   114,
     125,    69,   128,   189,    26,   120,   131,   133,    86,    40,
      41,   126,   138,   291,     9,   140,   134,   135,   133,   144,
     145,   136,    25,   219,   167,   140,    29,    17,    25,   144,
     145,   161,    29,    12,    13,   158,    39,     1,    41,    10,
      12,    13,    39,    11,    41,   267,    14,    15,     6,    21,
      21,    30,    16,    56,    12,    13,    31,   202,   203,   204,
      63,   206,    26,    21,    40,    41,    24,    70,     6,    10,
      12,    13,    19,    70,    12,   220,   202,   203,   204,    21,
     206,   196,   197,   198,   199,   200,   201,   212,    12,    13,
      10,     9,   221,   208,   220,   210,   211,    21,    11,   214,
     215,    14,   101,   248,    27,    63,    21,    25,    66,   224,
     255,    29,    24,   242,   243,    70,   242,   243,   167,     6,
      12,    39,   248,    41,    25,    12,    13,    84,    29,   255,
      10,   256,    12,    13,    21,     6,    31,   252,    39,    64,
      41,    12,    13,    25,    12,    13,   261,    29,   293,   294,
      68,    24,    70,   298,   269,   300,    22,    39,   101,    41,
     290,    10,    63,    12,    13,    12,    13,   293,   294,    70,
      21,    89,   298,    47,   300,   301,    63,     4,     5,    66,
     325,   296,   307,   308,    10,    25,    12,    13,    70,     9,
      25,    24,    12,    13,    29,    56,   341,    10,    18,   325,
      21,   168,   169,    23,    39,    25,    41,    65,    28,    29,
      67,   167,    26,    66,    26,   341,    26,   332,   333,    39,
      40,    41,     9,    43,    25,    12,    13,    66,    67,    68,
      11,    18,   101,    25,   182,    70,    75,    76,    25,    67,
      60,   132,    29,   224,    83,     6,   333,   114,    68,   255,
      70,   140,    39,    40,    41,     9,    43,   120,    12,    13,
     334,   144,    82,     7,    18,    -1,    -1,    -1,    88,    89,
      -1,    25,    -1,     6,    -1,    29,    -1,    -1,    -1,    12,
      13,    68,    -1,    70,    -1,    39,    40,    41,    21,    43,
      -1,    78,    -1,    -1,   114,    82,    -1,   208,    -1,   210,
     211,    88,    89,   214,   215,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    82,    -1,
      63,    -1,    -1,    66,    88,    89,     9,    -1,   158,    12,
      13,    -1,   129,    -1,    -1,    18,    -1,   167,    -1,    -1,
      -1,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    -1,     9,    -1,    11,   129,    -1,    14,    15,    -1,
     167,    18,    -1,    56,    -1,    -1,    -1,    -1,    25,    -1,
       9,    10,    29,    12,    13,    68,    -1,    70,    -1,    18,
      -1,    -1,    39,    40,    41,    -1,    25,    -1,     9,    82,
      29,    12,    13,   167,    -1,    -1,    89,    18,    -1,    -1,
      39,    40,    41,    -1,    25,    -1,    -1,    -1,    29,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    39,    40,
      41,   114,    -1,    -1,     9,    82,    -1,    12,    13,    68,
      -1,    70,    89,    18,    -1,    -1,   129,    -1,    -1,    -1,
      25,    -1,    -1,    82,    29,    -1,     9,    68,    -1,    70,
      89,    -1,    -1,    -1,    39,    40,    41,   114,    -1,    -1,
      -1,    82,    25,    -1,    -1,    -1,    29,    -1,    89,    -1,
      -1,    -1,   129,    -1,   167,   114,    39,    40,    41,    -1,
      -1,    -1,     9,    68,    -1,    70,    -1,    -1,    -1,    -1,
     129,    18,    -1,   114,    -1,    -1,    -1,    82,    25,    -1,
      -1,    -1,    29,    -1,    89,    68,    -1,    70,   129,    -1,
     167,    -1,    39,    40,    41,    -1,    23,    -1,    25,    82,
      -1,    28,    -1,    -1,    -1,    -1,    89,    -1,   167,   114,
      -1,    -1,    -1,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    68,    -1,    70,   129,    -1,   167,    -1,    -1,    -1,
      -1,   114,    -1,    60,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,     7,     8,   129,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    85,    -1,
      -1,    88,   167,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,   129,    -1,   167,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    -1,    -1,    -1,    88,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
     153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   192,     0,    46,   193,   195,     9,    18,    25,    29,
      39,    40,    41,    68,    70,    82,    89,   114,   129,   167,
     197,   233,   236,   237,   238,   239,   240,   244,     1,    16,
     194,   194,    12,    13,    40,    43,    78,    88,   167,   197,
     202,   203,   209,   210,   211,   213,   216,   223,   224,   232,
     236,   241,   242,   243,   244,   213,   213,    23,   201,   201,
       9,    39,    63,   239,     9,     9,    11,    14,    15,   197,
      23,    28,    43,   158,   234,    11,    14,    72,    73,    27,
      89,   107,    69,    17,    23,    25,    28,    40,    41,    42,
      60,    74,    75,    76,    77,    79,    80,    81,    83,    85,
     153,   158,   167,   196,   198,   199,   200,   203,   204,   206,
     207,   208,   209,   214,   215,   217,   223,   226,   227,   228,
     231,   197,   197,   201,   209,     9,    31,    10,    21,    10,
      21,     6,    12,     6,    12,    13,    21,    63,    66,    10,
      20,    10,    10,   235,    19,   101,    26,    30,   202,   213,
      10,   213,   239,   213,   213,   238,   238,   238,    24,   238,
     238,    41,   233,    70,   238,   201,   201,   202,   209,   213,
     209,   167,   222,   209,   209,    40,    41,    40,    41,   203,
     213,   229,   194,   205,   196,    84,   196,    26,    87,   218,
     196,   213,   216,   196,     7,     8,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      71,   134,   139,   143,   149,   153,   209,   196,   230,    27,
      56,    89,   213,   232,    31,   209,   211,   212,   213,   202,
     213,   211,   209,   210,   202,   213,   197,   197,   213,    64,
     202,   241,    12,    13,   242,   209,   213,    24,     6,    24,
      10,    10,    21,   201,   234,    22,   101,   221,   221,   221,
      21,    55,   198,    47,   205,    25,   205,   196,   205,     6,
      59,   205,   213,   213,   213,   213,   213,   213,   202,   202,
     202,   202,   229,   229,   229,   209,   229,   229,   205,    24,
      41,   233,   202,    56,    56,   212,    21,    10,    21,    65,
      67,     9,   236,   239,   236,   213,   202,   226,   101,   209,
     167,   213,    26,    26,   205,    26,   213,    25,   201,   234,
     202,   202,   213,   225,   202,    66,   202,    10,   209,    58,
      86,   219,   220,    21,   101,   202,    11,    25,   213,   225,
     235,    67,    86,   202
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   191,   192,   192,   193,   194,   194,   195,   195,   195,
     196,   196,   196,   197,   197,   197,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   199,
     200,   200,   201,   201,   201,   202,   202,   202,   202,   203,
     203,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   207,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   214,   215,   216,   216,   217,   218,   219,   219,   220,
     220,   221,   221,   221,   222,   222,   223,   224,   224,   225,
     225,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   227,   228,
     228,   228,   228,   229,   229,   230,   231,   231,   231,   232,
     232,   233,   233,   233,   234,   234,   234,   234,   235,   235,
     235,   236,   236,   236,   236,   236,   237,   237,   237,   237,
     237,   238,   238,   238,   239,   239,   239,   239,   240,   240,
     240,   241,   241,   242,   242,   242,   243,   243,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244
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
#line 393 "dpic.y" /* yacc.c:1646  */
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
    	  if (envblock != NULL) { envblock->direction = XLright; }
		  }
#line 1927 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 409 "dpic.y" /* yacc.c:1646  */
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
		    r = (envblock->envinx(XLlinethick) / 2 / 72)
                * envblock->envinx(XLscale);
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
#line 2004 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 486 "dpic.y" /* yacc.c:1646  */
    { yyerrok; yyclearin; }
#line 2010 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 490 "dpic.y" /* yacc.c:1646  */
    { dostart(); (yyval).xval = 0; (yyval).yval = 0;}
#line 2016 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 493 "dpic.y" /* yacc.c:1646  */
    { dostart(); (yyval).xval = (yyvsp[0]).xval; (yyval).yval = 0; }
#line 2022 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 496 "dpic.y" /* yacc.c:1646  */
    { dostart(); (yyval).xval = (yyvsp[-1]).xval; (yyval).yval = (yyvsp[0]).xval; }
#line 2028 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 502 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[0]).prim != NULL) && ((yyvsp[0]).lexval != XLcontinue)) {
            queueprim( (yyvsp[0]).prim, envblock ); }
#ifdef DDEBUG
          if (debuglevel > 0 ) { snaptree(envblock->son,0); }
#endif
    	  }
#line 2039 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 510 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[0]).prim != NULL) && ((yyvsp[0]).lexval != XLcontinue)) {
            queueprim( (yyvsp[0]).prim, envblock ); }
#ifdef DDEBUG
          if (debuglevel > 0 ) { snaptree(envblock->son,0); }
#endif
		  }
#line 2050 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 521 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval * (yyvsp[0]).xval; }
#line 2056 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 524 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { markerror(852); (yyval).xval = 0.0; }
    		else { (yyval).xval = (yyvsp[-2]).xval / (yyvsp[0]).xval; }
		  }
#line 2064 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 529 "dpic.y" /* yacc.c:1646  */
    { i = Rnd((yyvsp[-2]).xval);
    	  j = Rnd((yyvsp[0]).xval);
    	  if (j == 0) { markerror(852); (yyval).xval = 0.0; }
    	  else { (yyval).xval = i - ((i / j) * j); }
		  }
#line 2074 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 537 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			prp = (yyval).prim;
			if ((prp->ptype == XLspline) || (prp->ptype == XLmove) ||
			    (prp->ptype == XLarrow) || (prp->ptype == XLline)) {
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
#line 2124 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 584 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != XEMPTY) {
		    addsuffix(chbuf, &(yyvsp[-3]).chbufx,&(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval);}
		  prp = findplace(envblock->son, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
		  if (prp == NULL) {
			newprim(&(yyval).prim, XLabel, envblock);
			newstr(&(yyval).prim->name);
			storestring((yyval).prim->name, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen, 1);
			prp = (yyval).prim; }
		  else if (prp->ptype != XLabel) {
			newprim(&(yyval).prim, XLabel, envblock);
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
#line 2151 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 610 "dpic.y" /* yacc.c:1646  */
    { envblock->direction = (yyvsp[0]).lexval; }
#line 2157 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 613 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, XLaTeX, envblock);
    	  newstr(&(yyval).prim->textp);
    	  storestring((yyval).prim->textp, chbuf, (yyvsp[0]).chbufx, (yyvsp[0]).toklen, 1);
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen);
		  }
#line 2167 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 622 "dpic.y" /* yacc.c:1646  */
    { envblock->here_.xpos = (yyvsp[-3]).xval;
    	  envblock->here_.ypos = (yyvsp[-3]).yval;
    	  if (((yyvsp[-3]).state == XLright) || ((yyvsp[-3]).state == XLleft) ||
			  ((yyvsp[-3]).state == XLdown) || ((yyvsp[-3]).state == XLup)) {
			envblock->direction = (yyvsp[-3]).state; }
#ifdef DDEBUG
          if (debuglevel>1) { prattribute("element7", &(yyval)); }
#endif
		  }
#line 2181 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 639 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
			newprim(&(yyval).prim, XLaTeX, envblock);
			(yyval).prim->textp = (yyvsp[0]).prim->textp;
			(yyvsp[0]).prim->textp = NULL;
			if (envblock->son == (yyvsp[0]).prim) { envblock->son = (yyval).prim; }
			deletestringbox(&(yyvsp[0]).prim);
			}
		  }
#line 2194 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 649 "dpic.y" /* yacc.c:1646  */
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
#line 2220 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 673 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = envblock->here_.xpos;
    	  (yyval).yval = envblock->here_.ypos;
    	  (yyval).state = envblock->direction; }
#line 2228 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 679 "dpic.y" /* yacc.c:1646  */
    { donamedobj(&(yyval)); }
#line 2234 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 682 "dpic.y" /* yacc.c:1646  */
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
#line 2255 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 701 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 2261 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 704 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).xval > maxint) { fatal(9); } else { (yyval).xval = (yyvsp[-1]).xval; } }
#line 2267 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 707 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = Xcomma;
    	  (yyval).xval = (yyvsp[-1]).xval;
    	  (yyval).yval = (yyvsp[-1]).yval;
    	  if ((fabs((yyvsp[-1]).xval) > maxint) || (fabs((yyvsp[-1]).yval) > maxint)) {fatal(9);}
		  }
#line 2277 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 715 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2283 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 718 "dpic.y" /* yacc.c:1646  */
    { r = (yyvsp[-4]).xval;
    	  (yyval).xval = (yyvsp[-2]).xval + (r * ((yyvsp[0]).xval - (yyvsp[-2]).xval));
    	  (yyval).yval = (yyvsp[-2]).yval + (r * ((yyvsp[0]).yval - (yyvsp[-2]).yval)); }
#line 2291 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 724 "dpic.y" /* yacc.c:1646  */
    {
    	  r = (yyvsp[-7]).xval;
    	  (yyval).xval = (yyvsp[-2]).xval + (r * ((yyvsp[0]).xval - (yyvsp[-2]).xval));
    	  (yyval).yval = (yyvsp[-2]).yval + (r * ((yyvsp[0]).yval - (yyvsp[-2]).yval)); }
#line 2300 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 731 "dpic.y" /* yacc.c:1646  */
    { r = (yyvsp[-6]).xval;
    	  (yyval).xval = (yyvsp[-4]).xval + (r * ((yyvsp[-2]).xval - (yyvsp[-4]).xval));
    	  (yyval).yval = (yyvsp[-4]).yval + (r * ((yyvsp[-2]).yval - (yyvsp[-4]).yval));
		  if ((yyvsp[-1]).lexval != XGT) { markerror(869); }
		  else if ((yyvsp[0]).lexval != XEMPTY) {
	   	    (yyval).xval += (yyvsp[0]).xval;
	   	    (yyval).yval += (yyvsp[0]).yval;
			}
		  }
#line 2314 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 745 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; }
#line 2320 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 749 "dpic.y" /* yacc.c:1646  */
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
#line 2335 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 761 "dpic.y" /* yacc.c:1646  */
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
#line 2351 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 774 "dpic.y" /* yacc.c:1646  */
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
#line 2370 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 790 "dpic.y" /* yacc.c:1646  */
    { resetenv(0, envblock); }
#line 2376 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 797 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
#ifdef SAFE_MODE
			markerror(901);
#else
			pointinput((yyvsp[0]).prim->textp);
#endif
			deletestringbox(&(yyvsp[0]).prim);
    		}
		  }
#line 2390 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 808 "dpic.y" /* yacc.c:1646  */
    { currprod = 4;
          (yyval) = (yyvsp[0]);
		  dodefhead( &(yyval) );
          }
#line 2399 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 814 "dpic.y" /* yacc.c:1646  */
    { currprod = 5;
          (yyval) = (yyvsp[0]);
		  dodefhead( &(yyval) );
          }
#line 2408 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 821 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); doundefine( &(yyvsp[0]) );
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen); }
#line 2415 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 825 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); doundefine( &(yyvsp[0]) );
		  clearchbuf((yyvsp[0]).chbufx, (yyvsp[0]).toklen); }
#line 2422 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 838 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval == 1.0) { currprod = 1; skiptobrace(); } }
#line 2428 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 842 "dpic.y" /* yacc.c:1646  */
    { forattr = (yyval);
#ifdef DDEBUG
		  if (debuglevel>0) prattribute("for1",&(yyval));
#endif
		  }
#line 2438 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 849 "dpic.y" /* yacc.c:1646  */
    { forattr = (yyval); }
#line 2444 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 853 "dpic.y" /* yacc.c:1646  */
    {
#ifdef DDEBUG
		  if (debuglevel>0) {
			prattribute("stringexpr1",&(yyval));
            printobject((yyval).prim);
  			fflush(log_); }
#endif
		  }
#line 2457 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 863 "dpic.y" /* yacc.c:1646  */
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
#line 2480 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 884 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, XLstring, envblock);
		  eb = findenv(envblock);
		  With2 = (yyval).prim;
		  With2->boxheight_ = eb->envinx(XLtextht);
		  With2->boxwidth_ = eb->envinx(XLtextwid);
		  if (With2->boxwidth_ == 0.0) {
			switch (drawmode) {
		  	  case xfig:
							/* To keep xfig from crashing, assume text height
							   is 0.1 and a character is 0.1*0.75 wide */
		  	  	if ((yyval).prim->boxheight_ == 0.0) {
		  	      (yyval).prim->boxheight_ = 0.1 * eb->envinx(XLscale); }
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
#line 2514 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 919 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-3]).chbufx,
                &(yyvsp[-3]).toklen, (yyvsp[-2]).xval,(yyvsp[-2]).lexval,(yyvsp[-2]).yval); }
		    (yyval).varname = findname(envblock, chbuf, (yyvsp[-3]).chbufx, (yyvsp[-3]).toklen,
			     &lastvar, &k);
		    if (((yyval).varname == NULL) && ((yyvsp[-1]).lexval != XEQ)) {
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
		  if ((yyvsp[-1]).lexval == XEQ) { (yyval).varname->val = (yyvsp[0]).xval; }
		  else { eqop(&(yyval).varname->val, (yyvsp[-1]).lexval, (yyvsp[0]).xval); }
		  (yyval).xval = (yyval).varname->val;

		  clearchbuf((yyvsp[-3]).chbufx, (yyvsp[-3]).toklen);
          }
#line 2571 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 973 "dpic.y" /* yacc.c:1646  */
    { if (envblock != NULL) {
		    if (((yyvsp[-2]).lexval == XLarrowhead) && (drawmode == TeX) &&
		      ((yyvsp[0]).xval == 0.0)) { markerror(858); }
		    else {
		      if (envblock->blockparms.env == NULL) { inheritenv(envblock); }
		      if ((yyvsp[-2]).lexval == XLscale) {
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
		    if (((yyval).lexval == XLdashwid) || ((yyval).lexval == XLlinethick)) {
		      newprim(&((yyval).prim), XLaTeX, envblock);
		      if ((yyvsp[-2]).lexval == XLlinethick) { (yyval).prim->lthick = (yyval).xval; }
		      else { (yyval).prim->lparam = (yyval).xval; }
		      }
	        }
		  }
#line 2600 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1007 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[0]).xval; }
#line 2606 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1010 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = -(yyvsp[0]).xval; }
#line 2612 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1013 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval + (yyvsp[0]).xval; }
#line 2618 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1016 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-2]).xval - (yyvsp[0]).xval; }
#line 2624 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1020 "dpic.y" /* yacc.c:1646  */
    { inlogic = false;
    	  (yyval).xval = (yyvsp[-2]).xval;
    	  if ((yyval).xval == 0.0) {
		    currprod = 2 /* ifhead1 */;
		    skiptobrace();
    	    }
		  }
#line 2636 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1030 "dpic.y" /* yacc.c:1646  */
    { inlogic = true; }
#line 2642 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1036 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval != 0.0) || ((yyvsp[0]).xval != 0.0)) { (yyval).xval = 1.0; }
    	  else { (yyval).xval = 0.0; }
		  }
#line 2650 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1042 "dpic.y" /* yacc.c:1646  */
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
		  else if ((Rnd((yyval).startchop)) != XLscale) {
			if (envblock->blockparms.env == NULL) { inheritenv(envblock); }
			envblock->envinx((yyval).startchop) = (yyval).xval; }
		  else { resetscale((yyval).xval, XEQ, envblock); }

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
#line 2701 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1091 "dpic.y" /* yacc.c:1646  */
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
	    else if ((Rnd(With1->startchop)) != XLscale) {
		  envblock->envinx(With1->startchop)= With1->xval; }
	    else { resetscale(With1->xval, XEQ, envblock); }
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
#line 2745 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1133 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 1.0; }
#line 2751 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1136 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 2757 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1142 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = (yyvsp[0]).lexval; }
#line 2763 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1146 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 2769 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1149 "dpic.y" /* yacc.c:1646  */
    { With1 = &(yyvsp[0]);
		  (yyval).state = 1;
		  bswitch = false;
		  if (With1->prim != NULL) {
			if (With1->prim->textp == NULL) { markerror(861); }
			else if ((yyvsp[-1]).lexval != XGT) { markerror(869); }
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
#line 2790 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1167 "dpic.y" /* yacc.c:1646  */
    { With1 = &(yyvsp[0]);
		  (yyval).state = 1;
		  bswitch = false;
		  if (With1->prim != NULL) {
			if (With1->prim->textp == NULL) { markerror(861); }
			else if (((yyvsp[-2]).lexval != XGT) || ((yyvsp[-1]).lexval != XGT)) {
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
#line 2812 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1187 "dpic.y" /* yacc.c:1646  */
    { resetenv((yyvsp[0]).lexval, envblock); }
#line 2818 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1190 "dpic.y" /* yacc.c:1646  */
    { resetenv((yyvsp[0]).lexval, envblock); }
#line 2824 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1194 "dpic.y" /* yacc.c:1646  */
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
#line 2850 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1218 "dpic.y" /* yacc.c:1646  */
    { dosprintf( &(yyval), &(yyvsp[0]), &(yyvsp[0]), 0 ); }
#line 2856 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1221 "dpic.y" /* yacc.c:1646  */
    { dosprintf( &(yyval), &(yyvsp[-2]), &(yyvsp[0]), (yyvsp[0]).state ); }
#line 2862 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1225 "dpic.y" /* yacc.c:1646  */
    { (yyval).state = 1; }
#line 2868 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1228 "dpic.y" /* yacc.c:1646  */
    { (yyval).state = (yyvsp[0]).state + 1; }
#line 2874 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1234 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			switch (With2->ptype) {
			  case XLbox:
			  case XBLOCK:
			    if (With2->ptype == XBLOCK) {
			      r = 0.5 * ((yyvsp[0]).xval - With2->blockheight_);
			      With2->blockheight_ = (yyvsp[0]).xval; }
			    else {
			      r = 0.5 * ((yyvsp[0]).xval - With2->boxheight_);
			      With2->boxheight_ = (yyvsp[0]).xval; }
			    if (!teststflag((yyvsp[-2]).state, XLat)) {
			      switch (With2->direction) {
			        case XLleft:
			        case XLright:
				      break; /* blank case */
			        case XLup:
				      shift((yyvsp[-2]).prim, 0.0, r);
				      break;
			        case XLdown:
				      shift((yyvsp[-2]).prim, 0.0, -r);
				      break;
			        }
			      }
			    break;
			  case XLstring:
	  			With2->boxheight_ = (yyvsp[0]).xval;
	  			if ((drawmode == PDF) && (With2->textp != NULL)) {
	      		  With2->boxwidth_ = With2->boxheight_ *
					With2->textp->len * 0.6;
	  			  }
	  			break;
			  case XLcircle:
			    if (!teststflag((yyvsp[-2]).state, XLat)) {
			      switch (With2->direction) {
			        case XLleft:
			        case XLright:
				      break; /* blank case */
			        case XLup:
				      With2->aat.ypos += (0.5 * (yyvsp[0]).xval) - With2->circleradius_;
				      break;
			        case XLdown:
				      With2->aat.ypos += With2->circleradius_ - (0.5 * (yyvsp[0]).xval);
				      break;
			        }
			      }
			    With2->circleradius_ = (yyvsp[0]).xval * 0.5;
			    break;
			  case XLellipse:
			    if (!teststflag((yyvsp[-2]).state, XLat)) {
			      switch (With2->direction) {
			        case XLleft:
			        case XLright:
				      break; /* blank case */
			        case XLup:
				      With2->aat.ypos +=
				        0.5 * ((yyvsp[0]).xval - With2->ellipseheight_);
				      break;
			        case XLdown:
				      With2->aat.ypos +=
				        0.5 * (With2->ellipseheight_ - (yyvsp[0]).xval);
				      break;
			        }
			      }
			    With2->ellipseheight_ = (yyvsp[0]).xval;
			    break;
			  case XLline:
			  case XLarrow:
			  case XLmove:
			  case XLarc:
			  case XLspline:
			    prp = (yyvsp[-2]).prim;
			    while (prp != NULL) {
			      prp->lineheight_ = (yyvsp[0]).xval;
			      if (isthen(prp)) { prp = prp->parent; } else { prp = NULL; }
			      }
			    break;
			  case XLabel:
			  case XLaTeX:
			    markerror(858);
			    break;
			    }
		      }
			}
#line 2963 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1320 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			switch (With2->ptype) {
			  case XLbox:
			  case XBLOCK:
			    if (With2->ptype == XBLOCK) {
			      r = 0.5 * ((yyvsp[0]).xval - With2->blockwidth_);
			      With2->blockwidth_ = (yyvsp[0]).xval; }
			  else {
			      r = 0.5 * ((yyvsp[0]).xval - With2->boxwidth_);
			      With2->boxwidth_ = (yyvsp[0]).xval; }
			  if (!teststflag((yyvsp[-2]).state, XLat)) {
			    switch (With2->direction) {
			      case XLup:
			      case XLdown:
				    break; /* blank case */
			      case XLright:
				    shift((yyvsp[-2]).prim, r, 0.0);
				    break;
			      case XLleft:
				    shift((yyvsp[-2]).prim, -r, 0.0);
				    break;
			      }
			    }
			  break;
			case XLstring:
			  With2->boxwidth_ = (yyvsp[0]).xval;
			  break;
			case XLcircle:
			  if (!teststflag((yyvsp[-2]).state, XLat)) {
			    switch (With2->direction) {
			      case XLup:
			      case XLdown:
				    break; /* blank case */
			      case XLright:
				    With2->aat.xpos += (0.5 * (yyvsp[0]).xval) - With2->circleradius_;
				    break;
			      case XLleft:
				    With2->aat.xpos += With2->circleradius_ - (0.5 * (yyvsp[0]).xval);
				    break;
			      }
			    }
			  With2->circleradius_ = (yyvsp[0]).xval * 0.5;
			  break;
			case XLellipse:
			  if (!teststflag((yyvsp[-2]).state, XLat)) {
			    switch (With2->direction) {
			      case XLup:
			      case XLdown:
				    break; /* blank case */
			      case XLright:
				    With2->aat.xpos += 0.5 * ((yyvsp[0]).xval - With2->ellipsewidth_);
				    break;
			      case XLleft:
				    With2->aat.xpos += 0.5 * (With2->ellipsewidth_ - (yyvsp[0]).xval);
				    break;
			      }
			    }
			  With2->ellipsewidth_ = (yyvsp[0]).xval;
			  break;
			case XLline:
			case XLarrow:
			case XLmove:
			case XLarc:
			case XLspline:
			  prp = (yyvsp[-2]).prim;
			  while (prp != NULL) {
			    prp->linewidth_ = (yyvsp[0]).xval;
			    if (isthen(prp)) { prp = prp->parent; } else { prp = NULL; }
			    }
			  break;
			case XLabel:
			case XLaTeX:
			  markerror(858);
			  break;
			  }
		    }
	 	  }
#line 3046 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1400 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			switch (With2->ptype) {
			  case XLbox:
			    With2->boxradius_ = (yyvsp[0]).xval;
			    break;
			  case XLarc:
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
			      setstflag(&(yyvsp[-2]).state, XLradius);
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
			      setstflag(&(yyval).state, XLradius);
				  }
			    break;
			  case XLcircle:
			    if (!teststflag((yyvsp[-2]).state, XLat)) {
			      switch (With2->direction) {
			        case XLleft:
				      With2->aat.xpos += With2->circleradius_ - (yyvsp[0]).xval;
				      break;
			        case XLright:
				      With2->aat.xpos += (yyvsp[0]).xval - With2->circleradius_;
				      break;
			        case XLup:
				      With2->aat.ypos += (yyvsp[0]).xval - With2->circleradius_;
				      break;
			        case XLdown:
				      With2->aat.ypos += With2->circleradius_ - (yyvsp[0]).xval;
				      break;
			        }
			      }
			    With2->circleradius_ = (yyvsp[0]).xval;
			    setstflag(&(yyvsp[-2]).state, XLradius);
			    break;
			  default:
			    markerror(858);
			    break;
			  }
		    }
		  }
#line 3111 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1462 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			if (With2->ptype == XLcircle) {
			  r = 0.5 * (yyvsp[0]).xval;
			  if (!teststflag((yyvsp[-2]).state, XLat)) {
				switch (With2->direction) {
				  case XLleft:
				    With2->aat.xpos += With2->circleradius_ - r;
				    break;
				  case XLright:
				    With2->aat.xpos += r - With2->circleradius_;
				    break;
				  case XLup:
				    With2->aat.ypos += r - With2->circleradius_;
				    break;
				  case XLdown:
				    With2->aat.ypos += With2->circleradius_ - r;
				    break;
				  }
			    }
			  With2->circleradius_ = r;
			  }
			else { markerror(858); }
		    }
		  }
#line 3141 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1489 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			if ((yyvsp[0]).xval < 0.0) {
			  eb = findenv(envblock);
			  With2->lthick = eb->envinx(XLlinethick);
			  }
			else { With2->lthick = (yyvsp[0]).xval; }
		    }
		  }
#line 3155 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1500 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).prim != NULL) && ((yyvsp[0]).lexval != XEMPTY)) {
			With2 = (yyval).prim;
			r = (yyvsp[0]).xval - 1;
			corner((yyvsp[-2]).prim, XDc, &x1, &z1);
			switch (With2->ptype) {
			  case XLbox:
			  case XBLOCK:
			  case XLstring:
			    if (teststflag((yyvsp[-2]).state, XLat)) {
			      dx = 0.0;
			      dy = 0.0;
			      }
			    else if (With2->ptype == XBLOCK) {
			      dx = With2->blockwidth_ * r / 2;
			      dy = With2->blockheight_ * r / 2;
			      }
			    else {
			      dx = With2->boxwidth_ * r / 2;
			      dy = With2->boxheight_ * r / 2;
			      }
			    scaleobj((yyval).prim, (yyvsp[0]).xval);
			    switch (With2->direction) {
			      case XLright: shift(
                    (yyval).prim, x1 - With2->aat.xpos + dx, z1 - With2->aat.ypos);
			        break;
			      case XLleft: shift(
                    (yyval).prim, x1 - With2->aat.xpos - dx, z1 - With2->aat.ypos);
			        break;
			      case XLup: shift(
                    (yyval).prim, x1 - With2->aat.xpos, z1 - With2->aat.ypos + dy);
			        break;
			      case XLdown: shift(
                    (yyval).prim, x1 - With2->aat.xpos, z1 - With2->aat.ypos - dy);
			        break;
			      }
			    break;
			  case XLcircle:
			    With2->circleradius_ = (yyvsp[0]).xval * With2->circleradius_;
			    if (!teststflag((yyvsp[-2]).state, XLat)) {
			      switch (With2->direction) {
			        case XLup:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 + With2->circleradius_;
				      break;
			        case XLdown:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 - With2->circleradius_;
				      break;
			        case XLright:
				      With2->aat.xpos = x1 + With2->circleradius_;
				      With2->aat.ypos = z1;
				      break;
			        case XLleft:
				      With2->aat.xpos = x1 - With2->circleradius_;
				      With2->aat.ypos = z1;
				      break;
			        }
			      }
			    break;
			  case XLellipse:
			    With2->ellipsewidth_ *= (yyvsp[0]).xval;
			    With2->ellipseheight_ *= (yyvsp[0]).xval;
			    if (!teststflag((yyvsp[-2]).state, XLat)) {
			      switch (With2->direction) {
			        case XLup:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 + (With2->ellipseheight_ / 2);
				      break;
			        case XLdown:
				      With2->aat.xpos = x1;
				      With2->aat.ypos = z1 - (With2->ellipseheight_ / 2);
				      break;
			        case XLright:
				      With2->aat.xpos = x1 + (With2->ellipsewidth_ / 2);
				      With2->aat.ypos = z1;
				      break;
			        case XLleft:
				      With2->aat.xpos = x1 - (With2->ellipsewidth_ / 2);
				      With2->aat.ypos = z1;
				      break;
			        }
			      }
			    break;
			  case XLline:
			  case XLarrow:
			  case XLmove:
			  case XLarc:
			  case XLspline:
			    scaleobj((yyval).prim, (yyvsp[0]).xval);
			    corner((yyval).prim, XDc, &r, &s);
			    shift((yyval).prim, x1 - r, z1 - s);
			    break;
			  case XLabel:
			  case XLaTeX:
			    markerror(858);
			    break;
			  }
		    }
		  }
#line 3259 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1601 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			With2 = (yyval).prim;
			if ((With2->ptype == XLspline) || (With2->ptype == XLarrow) ||
			    (With2->ptype == XLmove) || (With2->ptype == XLline) ||
			    (With2->ptype == XLarc)) {
			  i = (yyvsp[-1]).lexval;
			  envblock->direction = i;
			  eb = findenv(envblock);
			  switch (With2->ptype) {
			    case XLarc:
			      r = cos(With2->startangle_);
			      s = sin(With2->startangle_);
			      With2->aat.xpos += With2->aradius_ * r;
			      With2->aat.ypos += With2->aradius_ * s;
				  nwi = With2->direction;
			      if (((nwi == XLup) && (i == XLleft)) ||
				      ((nwi == XLdown) && (i == XLright)) ||
				      ((nwi == XLright) && (i == XLup)) ||
				      ((nwi == XLleft) && (i == XLdown))) {
				    With2->arcangle_ = pi * 0.5; }
			      else if (((nwi == XLup) && (i == XLright)) ||
				      ((nwi == XLdown) && (i == XLleft)) ||
				      ((nwi == XLright) && (i == XLdown)) ||
				      ((nwi == XLleft) && (i == XLup))) {
				    With2->arcangle_ = (-pi) * 0.5; }
			      if ((yyvsp[0]).lexval != XEMPTY) {
				    With2->aradius_ = (yyvsp[0]).xval; }
			      With2->aat.xpos -= With2->aradius_ * r;
			      With2->aat.ypos -= With2->aradius_ * s;
			      With2->direction = i;
			      break;
			    case XLline:
			    case XLmove:
			    case XLarrow:
			    case XLspline:
			      With2->direction = i;
			      if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; s = r; }
			      else { switch (With2->ptype) {
				    case XLline:
				    case XLarrow:
				    case XLspline:
				      r = eb->envinx(XLlineht);
				      s = eb->envinx(XLlinewid);
				      break;
				    case XLmove:
				      r = eb->envinx(XLmoveht);
				      s = eb->envinx(XLmovewid);
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
#line 3324 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1663 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			setspec(&(yyval).prim->spec, (yyvsp[-1]).lexval);
			if ((yyvsp[0]).lexval == XEMPTY) {
              if ((yyvsp[-1]).lexval == XLdashed) {
				eb = findenv(envblock);
                (yyval).prim->lparam = eb->envinx(XLdashwid); }
              }
            else if ((((yyvsp[-1]).lexval == XLsolid) || ((yyvsp[-1]).lexval == XLinvis))
               && (((yyvsp[-2]).prim->ptype == XLmove) || ((yyvsp[-2]).prim->ptype == XLspline)
                || ((yyvsp[-2]).prim->ptype == XLarrow) || ((yyvsp[-2]).prim->ptype == XLline))) {
			  lineardir((yyval).prim, (yyvsp[0]).xval, (yyvsp[0]).xval, &(yyval).state); }
			else if (((yyvsp[-1]).lexval == XLsolid) || ((yyvsp[-1]).lexval == XLinvis)) {
			  markerror(858); }
			else { (yyval).prim->lparam = (yyvsp[0]).xval; }
		    }
#ifdef DDEBUG
	    if (debuglevel > 0) { printobject((yyval).prim); }
#endif
		  }
#line 3348 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1684 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			if (((yyvsp[-2]).prim->ptype != XLspline) &&
			    ((yyvsp[-2]).prim->ptype != XLmove) &&
			    ((yyvsp[-2]).prim->ptype != XLarrow) && ((yyvsp[-2]).prim->ptype != XLline)) {
			  markerror(858); }
			else {
			  With2 = (yyvsp[-2]).prim;
			  if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; }
			  else {
				eb = findenv(envblock);
				r = eb->envinx(XLcirclerad);
			    }
			  if (teststflag((yyval).state, XLchop)) { (yyval).endchop = r; }
			  else {
				(yyval).startchop = r;
				(yyval).endchop = r;
				setstflag(&(yyval).state, XLchop);
			    }
			  }
		    }
		  }
#line 3374 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1707 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyvsp[-2]).prim;
			if ((yyvsp[0]).lexval != XEMPTY) { s = (yyvsp[0]).xval; }
			else {
			  eb = findenv(envblock);
			  s = eb->envinx(XLfillval);
			  }
			prp = (yyval).prim;
			while (prp != NULL) {
			  switch (With2->ptype) {
			    case XLbox:
			      prp->boxfill_ = s;
			      break;
			    case XLcircle:
			      prp->circlefill_ = s;
			      break;
			    case XLellipse:
			      prp->ellipsefill_ = s;
			      break;
			    default:
                  if ((drawmode == TeX) || (drawmode == tTeX) ||
                      (drawmode == Pict2e)) { markerror(858); }
			      else {
				    switch (With2->ptype) {
				      case XLline:
				      case XLarrow:
				      case XLmove:
				      case XLspline:
				      case XLarc:
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
#line 3422 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1752 "dpic.y" /* yacc.c:1646  */
    { if ((yyval).prim != NULL) {
			With2 = (yyval).prim;
			if ((With2->ptype != XLspline) && (With2->ptype != XLarc) &&
			    (With2->ptype != XLarrow) && (With2->ptype != XLline)) {
			  markerror(858); }
			else {
			  With2->lineatype_ = pahlex(With2->lineatype_,(yyvsp[-1]).lexval);
			  if ((yyvsp[0]).lexval != XEMPTY) { lj = Rnd((yyvsp[0]).xval); }
			  else {
				eb = findenv(envblock);
				lj = (long)floor(eb->envinx(XLarrowhead)+0.5);
			    }
			  With2->lineatype_ = pahnum(With2->lineatype_, lj);
			  }
		    }
		  }
#line 3443 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1770 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
#ifdef DDEBUG
		    if (debuglevel > 0) {
	          fprintf(log_, "lexical \"then\" found, ");
	          prtstval((yyvsp[-1]).state); putc('\n', log_); }
#endif
			appendthen(&(yyval).prim);
			if ((yyvsp[-1]).prim->ptype != XLarc) { setstflag(&(yyval).state, XEMPTY); }
		    }
		  }
#line 3458 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1782 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			With2 = (yyvsp[-1]).prim;
			if (With2->ptype != XLarc) { markerror(858); }
			else {
			  if ((With2->arcangle_ > 0.0) && (With2->direction == 0)) {
				With2->arcangle_ = -fabs(
				  principal((2.0 * pi) - With2->arcangle_,2.0*pi));}
			  else if (With2->direction != 0) {
				With2->aat = arcstart((yyval).prim);
				switch (With2->direction) {
				  case XLup:
				    With2->aat.xpos += With2->aradius_;
				    break;
				  case XLdown:
				    With2->aat.xpos -= With2->aradius_;
				    break;
				  case XLleft:
				    With2->aat.ypos += With2->aradius_;
				    break;
				  case XLright:
				    With2->aat.ypos -= With2->aradius_;
				    break;
				  }
				if (With2->arcangle_ > 0.0) {
				  With2->startangle_ =
                    principal(With2->startangle_ + pi, pi); }
				  With2->arcangle_ = -fabs(With2->arcangle_);
			    }
			  setstflag(&(yyval).state, XLcw);
			  }
		    }
		  }
#line 3495 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1816 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			With2 = (yyvsp[-1]).prim;
			if (With2->ptype != XLarc) { markerror(858); }
			else {
			  if ((With2->arcangle_ < 0.0) && (With2->direction == 0)) {
				With2->arcangle_ =
                  fabs(principal(With2->arcangle_ - (2.0 * pi),2.0*pi)); }
			  else if (With2->direction != 0) {
				With2->aat = arcstart((yyvsp[-1]).prim);
				switch (With2->direction) {
				  case XLup: With2->aat.xpos -= With2->aradius_; break;
				  case XLdown: With2->aat.xpos += With2->aradius_; break;
				  case XLleft: With2->aat.ypos -= With2->aradius_; break;
				  case XLright: With2->aat.ypos += With2->aradius_; break;
				  }
				if (With2->arcangle_ < 0.0) {
				  With2->startangle_ =
                    principal( With2->startangle_ + pi, pi); }
				  With2->arcangle_ = fabs(With2->arcangle_);
			    }
			  setstflag(&(yyvsp[-1]).state, XLccw);
			  }
		    }
		  }
#line 3524 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1842 "dpic.y" /* yacc.c:1646  */
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
			    case XLbox:
			    case XLstring:
			      if (With2->ptype == XLbox) {
				    switch (With2->direction) {
				      case XLup:
				        With2->aat.ypos += 0.5 *
					      (prp->boxheight_ - With2->boxheight_);
				        break;
				      case XLdown:
				        With2->aat.ypos -= 0.5 *
					      (prp->boxheight_ - With2->boxheight_);
				        break;
				      case XLleft:
				        With2->aat.xpos -=
				          0.5 * (prp->boxwidth_ - With2->boxwidth_);
				        break;
				      case XLright:
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
			    case XBLOCK:
			      markerror(858);
			      break;
			    case XLcircle:
			      switch (With2->direction) {
			        case XLup:
				      With2->aat.ypos +=
                        prp->circleradius_ - With2->circleradius_;
				      break;
			        case XLdown:
				      With2->aat.ypos +=
                        With2->circleradius_ - prp->circleradius_;
				      break;
			        case XLleft:
				      With2->aat.xpos +=
                        With2->circleradius_ - prp->circleradius_;
				      break;
			        case XLright:
				      With2->aat.xpos +=
                        prp->circleradius_ - With2->circleradius_;
				      break;
			        }
			      With2->circlefill_ = prp->circlefill_;
			      With2->circleradius_ = prp->circleradius_;
			      break;
			    case XLellipse:
			      switch (With2->direction) {
			        case XLup:
				      With2->aat.ypos +=
				        0.5 * (prp->ellipseheight_ - With2->ellipseheight_);
				      break;
			        case XLdown:
				      With2->aat.ypos -=
				        0.5 * (prp->ellipseheight_ - With2->ellipseheight_);
				      break;
			        case XLleft:
				      With2->aat.xpos -=
				        0.5 * (prp->ellipsewidth_ - With2->ellipsewidth_);
				      break;
			        case XLright:
				      With2->aat.xpos +=
				        0.5 * (prp->ellipsewidth_ - With2->ellipsewidth_);
				      break;
			        }
			      With2->ellipsefill_ = prp->ellipsefill_;
			      With2->ellipseheight_ = prp->ellipseheight_;
			      With2->ellipsewidth_ = prp->ellipsewidth_;
			      break;
			    case XLarc:
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
			    case XLline:
			    case XLarrow:
			    case XLmove:
			    case XLspline:
			      With2->endpos_.xpos =
				    With2->aat.xpos + prp->endpos_.xpos-prp->aat.xpos;
			      With2->endpos_.ypos =
				    With2->aat.ypos + prp->endpos_.ypos-prp->aat.ypos;
			      With2->lineheight_ = prp->lineheight_;
			      With2->linewidth_ = prp->linewidth_;
			      With2->lineatype_ = prp->lineatype_;
			      break;
			    case XLabel:
			    case XLaTeX:
			      markerror(858);
			      break;
			    }
			  }
		    }
		  }
#line 3654 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1969 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).prim != NULL) {
			if ((yyvsp[-1]).prim != NULL) {
			  With2 = (yyvsp[-1]).prim;
			  if (With2->textp == NULL) { With2->textp = (yyvsp[0]).prim->textp; }
			  else {
				namptr = With2->textp;
				i = 1;
				while (namptr->nextname != NULL) { namptr = namptr->nextname; i++; }
				namptr->nextname = (yyvsp[0]).prim->textp;
				if (With2->ptype == XLstring) {
				  if (drawmode == SVG) {
					eb = findenv(envblock);
					if (eb != NULL) {
					  r = findvar("dptextratio", 11);
					  if (r == 0) { r = 1.0; }
					  With2->boxheight_ += eb->envinx(XLtextht) / r;
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
#line 3689 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 2001 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval)  = (yyvsp[-2]);
			if (((yyvsp[-2]).prim->ptype == XLmove) || ((yyvsp[-2]).prim->ptype == XLspline) ||
			  ((yyvsp[-2]).prim->ptype == XLarrow) || ((yyvsp[-2]).prim->ptype == XLline) ||
			  ((yyvsp[-2]).prim->ptype == XLarc)) {
			    With2 = (yyvsp[-2]).prim;
			    x1 = (yyvsp[0]).xval + With2->aat.xpos;
			    z1 = (yyvsp[0]).yval + With2->aat.ypos;
			    if (With2->ptype == XLarc) {
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
#line 3713 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 2022 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			With2 = (yyval).prim;
			if ((With2->ptype == XLmove) || (With2->ptype == XLspline) ||
			  (With2->ptype == XLarrow) || (With2->ptype == XLline) ||
              (With2->ptype == XLarc)) {
			    if (With2->ptype == XLarc) {
				 r = (yyvsp[0]).xval;
				 s = (yyvsp[0]).yval;
				if (teststflag((yyvsp[-2]).state, XLto)) {
				  (yyvsp[0]).xval = With2->aat.xpos + (With2->aradius_ *
                    cos( With2->startangle_ + With2->arcangle_));
				  (yyvsp[0]).yval = With2->aat.ypos + (With2->aradius_ *
                    sin( With2->startangle_ + With2->arcangle_));
				  }
				With2->aat.xpos = r -
                  (With2->aradius_ * cos(With2->startangle_));
				With2->aat.ypos = s -
                  (With2->aradius_ * sin(With2->startangle_));
				if (teststflag((yyvsp[-2]).state, XLto)) { goto object_xx; }
			    }
			  else if (!teststflag((yyvsp[-2]).state, XLto)) {
				prp = (yyvsp[-2]).prim;
				while (isthen(prp)) { prp = prp->parent; }
				shift(prp, (yyvsp[0]).xval - prp->aat.xpos, (yyvsp[0]).yval - prp->aat.ypos);
			    }
			  else {
				With2->aat.xpos = (yyvsp[0]).xval;
				With2->aat.ypos = (yyvsp[0]).yval; }
			  setstflag(&(yyvsp[-2]).state, XLfrom);
			  }
			else { markerror(858); }
		    }
		  }
#line 3751 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 2057 "dpic.y" /* yacc.c:1646  */
    {
          object_xx:
    	    if ((yyvsp[-2]).prim != NULL) {
    	      if (((yyvsp[-2]).prim->ptype == XLmove) || ((yyvsp[-2]).prim->ptype == XLspline) ||
    	        ((yyvsp[-2]).prim->ptype == XLarrow) || ((yyvsp[-2]).prim->ptype == XLline) ||
    	        ((yyvsp[-2]).prim->ptype == XLarc)) {
    	        if (((yyvsp[-2]).prim->ptype != XLarc) & teststflag((yyvsp[-2]).state, XLto)) {
#ifdef DDEBUG
    	    	  if (debuglevel > 0) {
    	    	    fprintf(log_, "\"then\" inserted, \n");
    	    	    prtstval((yyvsp[-2]).state); putc('\n', log_); }
#endif
    	    	  appendthen(&(yyval).prim);
    	    	  setstflag(&(yyval).state, XEMPTY);
    	          }
    	        With2 = (yyval).prim;
    	        if (With2->ptype != XLarc) {
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
    	    	    case XLup:
    	    	      if (With2->arcangle_ * ((-dx) - (t * dy)) < 0.0) {t= -t; }
    	    	      break;
    	    	    case XLdown:
    	    	      if (With2->arcangle_ * ((-dx) - (t * dy)) > 0.0) { t=-t; }
    	    	      break;
    	    	    case XLright:
    	    	      if (With2->arcangle_ * (dy - (t * dx)) < 0.0) { t = -t; }
    	    	      break;
    	    	    case XLleft:
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
    	        setstflag(&(yyval).state, XLto);
#ifdef DDEBUG
    	        if (debuglevel > 0) { printobject((yyval).prim); }
#endif
    	        }
    	      else { markerror(858); }
    	      }
		   }
#line 3850 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2153 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			if ((drawmode != SVG) || (getstval((yyvsp[-2]).state) == 0)) {
			    setstval(&(yyval).state, XDc); }
			setstflag(&(yyval).state, XLat);
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
#line 3871 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2171 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			namptr = (yyval).prim->textp;
			if (namptr != NULL) {
			  while (namptr->nextname != NULL) { namptr = namptr->nextname; }
			  setjust(namptr, (yyvsp[0]).lexval);
			  if (drawmode == SVG) {
				With2 = (yyval).prim;
				if ((!teststflag((yyval).state, XLat)) &&
                    (With2->ptype == XLstring)) {
				  (yyval).xval = With2->aat.xpos;
				  (yyval).yval = With2->aat.ypos;
				  setstflag(&(yyval).state, XLat); }
				setstflag(&(yyval).state, XLcw);
				i = getstval((yyval).state);
				if ((With2->ptype != XLmove) && (With2->ptype != XLspline) &&
				    (With2->ptype != XLarrow) && (With2->ptype != XLline)) {
				  switch ((yyvsp[0]).lexval) {
				    case XLljust:
				      if (i == XDn) { setstval(&(yyval).state, XDnw); }
				      else if (i == XDs) { setstval(&(yyval).state, XDsw); }
				      else { setstval(&(yyval).state, XDw); }
				      break;
				    case XLrjust:
				      if (i == XDn) { setstval(&(yyval).state, XDne); }
				      else if (i == XDs) { setstval(&(yyval).state, XDse); }
				      else { setstval(&(yyval).state, XDe); }
				      break;
				    case XLbelow:
				      if (i == XDe) { setstval(&(yyval).state, XDne); }
				      else if (i == XDw) { setstval(&(yyval).state, XDnw); }
				      else { setstval(&(yyval).state, XDn); }
				      break;
				    case XLabove:
				      if (i == XDe) { setstval(&(yyval).state, XDse); }
				      else if (i == XDw) { setstval(&(yyval).state, XDsw); }
				      else { setstval(&(yyval).state, XDs); }
				      break;
				    }
				  }
			    }
			  }
			else { markerror(861); }
		    }
		  }
#line 3920 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2217 "dpic.y" /* yacc.c:1646  */
    { if ((drawmode == Pict2e) || (drawmode == TeX) ||
		      (drawmode == tTeX) || (drawmode == xfig)) { markerror(858); }
		  else if (((yyvsp[0]).prim != NULL) && ((yyvsp[-2]).prim != NULL)) {
			With2 = (yyval).prim;
			switch ((yyvsp[-1]).lexval) {
			case XLshaded:
			  if (hasshade((yyvsp[-2]).lexval, true)) {
			    deletename(&With2->shadedp);
			    With2->shadedp = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
			    }
			  break;
			case XLoutlined:
			  if (hasoutline((yyvsp[-2]).lexval, true)) {
			    deletename(&With2->outlinep);
			    With2->outlinep = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
			    }
			  break;
			case XLcolour:
			  if (hasoutline((yyvsp[-2]).lexval, true)) {
			    deletename(&With2->outlinep);
			    With2->outlinep = (yyvsp[0]).prim->textp;
			    (yyvsp[0]).prim->textp = NULL;
				i = With2->ptype;
			    if (((i != XLspline) && (i != XLarrow) && (i != XLline) &&
				   (i != XLarc)) & hasshade((yyvsp[-2]).lexval, false)) {
				  deletename(&With2->shadedp);
				  copystr(&With2->shadedp, With2->outlinep);
			      }
			    }
			  break;
			  }
		    }
		    deletestringbox(&(yyvsp[0]).prim);
		  }
#line 3961 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2255 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			setstval(&(yyval).state, XEMPTY);
			setstflag(&(yyval).state, XLat);
		    }
		  }
#line 3973 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2264 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
			setstval(&(yyval).state, (yyvsp[-2]).lexval);
			setstflag(&(yyval).state, XLat);
		    }
		  }
#line 3985 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2273 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).xval = (yyvsp[0]).xval;
			(yyval).yval = (yyvsp[0]).yval;
            i = (yyval).prim->ptype;
			if ((i != XLarc) && (i != XLellipse) && (i != XLcircle) &&
			  (i != XBLOCK) && (i != XLstring) && (i != XLbox)){markerror(858);}
			else {
			  (yyval).startchop = (yyvsp[-2]).xval;
			  (yyval).endchop = (yyvsp[-2]).yval;
			  setstval(&(yyval).state, XLfloat);
			  }
			setstflag(&(yyval).state, XLat);
		    }
		  }
#line 4004 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2289 "dpic.y" /* yacc.c:1646  */
    { primp = NULL;
	      prp = envblock->son;
	      while (prp != NULL) { i = prp->ptype;
		    if ( (i != XLaTeX) && (i != XLstring) && (i != XBLOCK)
			  && (i != XLabel) ) { primp = prp; }
		    prp = prp->nextname; }
	      if (primp == NULL) { markerror(857); }
	      else {
		    while (primp->son != NULL) { primp = primp->son; }
		    (yyval).prim = primp;
		    if ((yyval).prim != NULL) {
			  appendthen(&(yyval).prim);
			  if ((yyval).prim->ptype != XLarc) { setstflag(&(yyval).state, XEMPTY); }
		      }
		    }
		  }
#line 4025 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2308 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, XBLOCK, envblock);
		  (yyval).prim->here_.xpos = 0.0;
		  (yyval).prim->here_.ypos = 0.0;
		  envblock = (yyval).prim;
		  tail = NULL;
		  (yyval).lexval = 0;
		  }
#line 4037 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2319 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-1]).lexval > XLprimitiv) && ((yyvsp[-1]).lexval < XLenvvar)) {
			newprim(&(yyval).prim, (yyvsp[-1]).lexval, envblock);
			eb = findenv(envblock);
			if (( ((yyvsp[-1]).lexval != XLmove) && ((drawmode == MPost) ||
			      (drawmode == Pict2e) || (drawmode == PDF) ||
			      (drawmode == PS) || (drawmode == SVG) ||
			      (drawmode == PSfrag)) ) || ((yyvsp[-1]).lexval == XLarc)) {
			  (yyval).prim->lthick = eb->envinx(XLlinethick); }
			if (((yyvsp[0]).lexval != XEMPTY) &&               /* check expr allowed */
			    ((yyvsp[-1]).lexval != XLmove) &&
			    ((yyvsp[-1]).lexval != XLspline) &&
			    ((yyvsp[-1]).lexval != XLarrow) &&
			    ((yyvsp[-1]).lexval != XLline)) { markerror(858); }
			With2 = (yyval).prim;
			switch ((yyvsp[-1]).lexval) {
			  case XLbox:
			    With2->boxheight_ = eb->envinx(XLboxht);
			    With2->boxwidth_ = eb->envinx(XLboxwid);
			    With2->boxradius_ = eb->envinx(XLboxrad);
			    switch (With2->direction) {
			      case XLup:
			        With2->aat.ypos += With2->boxheight_ * 0.5;
			        break;
			      case XLdown:
			        With2->aat.ypos -= With2->boxheight_ * 0.5;
			        break;
			      case XLleft:
			        With2->aat.xpos -= With2->boxwidth_ * 0.5;
			        break;
			      case XLright:
			        With2->aat.xpos += With2->boxwidth_ * 0.5;
			        break;
			      }
			    break;
			  case XLcircle:
			    With2->circleradius_ = eb->envinx(XLcirclerad);
			    switch (With2->direction) {
			      case XLup:
			        With2->aat.ypos += With2->circleradius_;
			        break;
			      case XLdown:
			        With2->aat.ypos -= With2->circleradius_;
			        break;
			      case XLleft:
			        With2->aat.xpos -= With2->circleradius_;
			        break;
			      case XLright:
			        With2->aat.xpos += With2->circleradius_;
			        break;
			      }
			    break;
			  case XLellipse:
			    With2->ellipseheight_ = eb->envinx(XLellipseht);
			    With2->ellipsewidth_ = eb->envinx(XLellipsewid);
			    switch (With2->direction) {
			      case XLup:
			        With2->aat.ypos += With2->ellipseheight_ * 0.5;
			        break;
			      case XLdown:
			        With2->aat.ypos -= With2->ellipseheight_ * 0.5;
			        break;
			      case XLleft:
			        With2->aat.xpos -= With2->ellipsewidth_ * 0.5;
			        break;
			      case XLright:
			        With2->aat.xpos += With2->ellipsewidth_ * 0.5;
			        break;
			      }
			    break;
			  case XLarc:
			    With2->aradius_ = eb->envinx(XLarcrad);
			    switch (With2->direction) {
			      case XLup:
			        With2->startangle_ = 0.0;
			        With2->aat.xpos -= With2->aradius_;
			        break;
			      case XLdown:
			        With2->startangle_ = pi;
			        With2->aat.xpos += With2->aradius_;
			        break;
			      case XLleft:
			        With2->startangle_ = 0.5 * pi;
			        With2->aat.ypos -= With2->aradius_;
			        break;
			      case XLright:
			        With2->startangle_ = (-0.5) * pi;
			        With2->aat.ypos += With2->aradius_;
			        break;
			      }
			    With2->lineheight_ = eb->envinx(XLarrowht);
			    With2->linewidth_ = eb->envinx(XLarrowwid);
			    With2->lineatype_ = pahnum(pahlex(0, XEMPTY),
			      Rnd(eb->envinx(XLarrowhead)));
			    With2->arcangle_ = pi * 0.5;
			    break;
			  case XLline:
			  case XLarrow:
			  case XLspline:
			  case XLmove:
			    With2->endpos_ = With2->aat;
			    if ((With2->ptype == XLspline) && ((yyvsp[0]).lexval != XEMPTY)) {
			      With2->aradius_ = (yyvsp[0]).xval;
			      (yyvsp[0]).lexval = XEMPTY; }
			    if ((yyvsp[0]).lexval != XEMPTY) { r = (yyvsp[0]).xval; }
			    else if (With2->ptype == XLmove) {
			      switch (With2->direction) {
			        case XLup:
			        case XLdown:
				      r = eb->envinx(XLmoveht);
				      break;
			        case XLleft:
			        case XLright:
				      r = eb->envinx(XLmovewid);
				      break;
			        }
			      }
			    else {
			      switch (With2->direction) {
			        case XLup:
			        case XLdown:
				      r = eb->envinx(XLlineht);
				      break;
			        case XLleft:
			        case XLright:
				      r = eb->envinx(XLlinewid);
				      break;
			        }
			      }
			    switch (With2->direction) {
			      case XLup:
			        With2->endpos_.ypos = With2->aat.ypos + r;
			        break;
			      case XLdown:
			        With2->endpos_.ypos = With2->aat.ypos - r;
			        break;
			      case XLleft:
			        With2->endpos_.xpos = With2->aat.xpos - r;
			        break;
			      case XLright:
			        With2->endpos_.xpos = With2->aat.xpos + r;
			        break;
			      }
			    With2->lineheight_ = eb->envinx(XLarrowht);
			    With2->linewidth_ = eb->envinx(XLarrowwid);
			    if (With2->ptype == XLarrow) {
			      With2->lineatype_ = pahlex(0, XRIGHTHEAD); }
			    else { With2->lineatype_ = pahlex(0, XEMPTY); }
			  With2->lineatype_ = pahnum(With2->lineatype_,
			    Rnd(eb->envinx(XLarrowhead)));
			  break;
			  }
		    }
#ifdef DDEBUG
			if (debuglevel > 0) { printobject((yyval).prim); }
#endif
		  }
#line 4198 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2477 "dpic.y" /* yacc.c:1646  */
    { if ((drawmode == PS) || (drawmode == PDF) || (drawmode == PSfrag)) {
			printstate = ((printstate >> 1) * 2) + 1; }
		  }
#line 4206 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2482 "dpic.y" /* yacc.c:1646  */
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
			  case XLright: dx += With2->blockwidth_ * 0.5; break;
			  case XLleft: dx -= With2->blockwidth_ * 0.5; break;
			  case XLup: dy += With2->blockheight_ * 0.5; break;
			  case XLdown: dy -= With2->blockheight_ * 0.5; break;
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
#line 4261 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2534 "dpic.y" /* yacc.c:1646  */
    { newprim(&(yyval).prim, XBLOCK, envblock);
		  (yyval).prim->here_.xpos = 0.0;
		  (yyval).prim->here_.ypos = 0.0;
		  (yyval).lexval = 0;
		  }
#line 4271 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2542 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XEMPTY; }
#line 4277 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2548 "dpic.y" /* yacc.c:1646  */
    { if (envblock->blockparms.env != NULL) {
			eb = findenv(envblock->parent);
			if (envblock->envinx(XLlinethick) != eb->envinx(XLlinethick)) {
		      newprim(&prp, XLaTeX, envblock);
			  prp->lthick = eb->envinx(XLlinethick);
              queueprim( prp, envblock );
              }
		    }
		  }
#line 4291 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2562 "dpic.y" /* yacc.c:1646  */
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
#line 4310 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2578 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[-3]).internal == NULL) { prp = (yyvsp[-3]).prim; }
			else { prp = (yyvsp[-3]).internal; }
			(yyval).internal = nthprimobj(prp->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
			if ((yyval).internal == NULL) { markerror(857); deletetree(&(yyval).prim); }
		    }
		  }
#line 4322 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2588 "dpic.y" /* yacc.c:1646  */
    { (yyval).yval = (yyvsp[0]).xval;
#ifdef DDEBUG
			if (debuglevel>1) prattribute("pair1",&(yyval));
#endif
			}
#line 4332 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2595 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) {
			(yyval).xval += (yyvsp[0]).xval;
			(yyval).yval += (yyvsp[0]).yval; }
		  }
#line 4341 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2602 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).xval <= 0.0) { markerror(856); }
		  else { (yyval).toklen = Rnd((yyvsp[-1]).xval); }
		  }
#line 4349 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2607 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval <= 0.0) { markerror(856); }
		  else { (yyval).toklen = -Rnd((yyvsp[-2]).xval); }
		  }
#line 4357 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2612 "dpic.y" /* yacc.c:1646  */
    { (yyval).toklen = 0; }
#line 4363 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 2622 "dpic.y" /* yacc.c:1646  */
    { (yyval).lexval = XBLOCK; }
#line 4369 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2626 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = 0.0;
		  (yyval).yval = 0.0;
		  (yyval).lexval = XEMPTY;
		  }
#line 4378 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2632 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval += (yyvsp[0]).xval;
		  (yyval).yval += (yyvsp[0]).yval;
		  (yyval).lexval = XLfloat;
		  }
#line 4387 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2638 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval -= (yyvsp[0]).xval;
		  (yyval).yval -= (yyvsp[0]).yval;
		  (yyval).lexval = XLfloat;
		  }
#line 4396 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2645 "dpic.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 4402 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2648 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-3]).xval;
		  (yyval).yval = (yyvsp[-1]).yval;
		  }
#line 4410 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2655 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval *= (yyvsp[0]).xval;
		  (yyval).yval *= (yyvsp[0]).xval;
		  }
#line 4418 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2660 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { markerror(852); }
		  else {
			(yyval).xval /= (yyvsp[0]).xval;
			(yyval).yval /= (yyvsp[0]).xval;
		    }
		  }
#line 4429 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2669 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, XEMPTY, &(yyval).xval, &(yyval).yval); }
#line 4435 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2672 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[-1]).prim, (yyvsp[0]).lexval, &(yyval).xval, &(yyval).yval); }
#line 4441 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2675 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, (yyvsp[-1]).lexval, &(yyvsp[0]).xval, &(yyvsp[0]).yval);
 		  (yyval) = (yyvsp[0]); }
#line 4448 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2679 "dpic.y" /* yacc.c:1646  */
    { corner((yyvsp[0]).prim, (yyvsp[-2]).lexval, &(yyvsp[0]).xval, &(yyvsp[0]).yval);
 		  (yyval) = (yyvsp[0]); }
#line 4455 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2683 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = envblock->here_.xpos;
		  (yyval).yval = envblock->here_.ypos;
		  }
#line 4463 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 2691 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).xval == 0.0) { (yyval).xval = 1.0; }
    	  else { (yyval).xval = 0.0; }
		  }
#line 4471 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2696 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval == 0.0) && ((yyvsp[0]).xval < 0.0)) { markerror(852); }
		  else {
			j = Rnd((yyvsp[0]).xval);
			r = j;
			if (r == (yyvsp[0]).xval) { (yyval).xval = intpow((yyvsp[-2]).xval, j); }
			else if ((yyvsp[-2]).xval < 0.0) { markerror(863); (yyval).xval = 0.0; }
			else if ((yyvsp[-2]).xval != 0.0) { (yyval).xval = exp((yyvsp[0]).xval * log((yyvsp[-2]).xval));}
			}
    	  }
#line 4485 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2708 "dpic.y" /* yacc.c:1646  */
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
#line 4504 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2724 "dpic.y" /* yacc.c:1646  */
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
#line 4519 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2736 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf, &(yyvsp[-1]).chbufx,
              &(yyvsp[-1]).toklen, (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
			primp = findplace((yyval).prim->son, chbuf, (yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
			if (primp == NULL) { marknotfound(855, chbuf, (yyvsp[-1]).chbufx,(yyvsp[-1]).toklen);}
			(yyval).prim = primp;
		    }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4533 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2747 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-3]).prim != NULL) {
			(yyval).prim = nthprimobj((yyvsp[-3]).prim->son, (yyvsp[-1]).toklen, (yyvsp[0]).lexval);
			if ((yyval).prim == NULL) { markerror(857); }
		    }
		  }
#line 4543 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 2757 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4549 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 2760 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4555 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 2766 "dpic.y" /* yacc.c:1646  */
    { if (((yyvsp[-2]).xval == 0.0) || ((yyvsp[0]).xval == 0.0)) { (yyval).xval = 0.0; }
		  else { (yyval).xval = 1.0; }
		  }
#line 4563 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 2772 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval == XLstring) {
			markerror(869);
			(yyval).lexval = XLfloat;
			deletestringbox(&(yyvsp[0]).prim);
		    }
		  }
#line 4574 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 2780 "dpic.y" /* yacc.c:1646  */
    { i = cmpstring((yyvsp[-2]).prim, (yyvsp[0]).prim);
		  if (i < 0) { (yyval).xval = 1.0; }
		  else { (yyval).xval = 0.0; }
		  (yyval).lexval = XLfloat;
		  deletestringbox(&(yyvsp[0]).prim);
		  deletestringbox(&(yyvsp[-2]).prim);
		  }
#line 4586 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 2789 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).xval < (yyvsp[0]).xval) { (yyval).xval = 1.0; }
		  else { (yyval).xval = 0.0; }
		  }
#line 4594 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 2799 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval == XLstring) {
			markerror(869);
			bswitch = false;
			deletestringbox(&(yyvsp[-2]).prim);
		    }
		  else {
#ifdef DDEBUG
			if (debuglevel > 0) { fprintf(log_," compare %g %d %g\n",
              (yyvsp[-2]).xval,(yyvsp[-1]).lexval-XLcompare,(yyvsp[0]).xval); }
#endif
			switch ((yyvsp[-1]).lexval - XLcompare) {
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
#line 4621 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2823 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-2]).lexval != XLstring) { markerror(869); bswitch = false; }
		  else {
			i = cmpstring((yyvsp[-2]).prim, (yyvsp[0]).prim);
			switch ((yyvsp[-1]).lexval - XLcompare) {
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
		  (yyval).lexval = XLfloat;
		  deletestringbox(&(yyvsp[0]).prim);
		  }
#line 4644 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2844 "dpic.y" /* yacc.c:1646  */
    { if (envblock != NULL) {
			eb = findenv(envblock);
			(yyval).xval = eb->envinx((yyvsp[0]).lexval);
		    }
		  }
#line 4654 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2851 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).lexval != XEMPTY) { addsuffix(chbuf,
		    &(yyvsp[-1]).chbufx, &(yyvsp[-1]).toklen, (yyvsp[0]).xval,(yyvsp[0]).lexval,(yyvsp[0]).yval); }
    	  namptr = glfindname(envblock,chbuf,(yyvsp[-1]).chbufx,(yyvsp[-1]).toklen, &lastvar, &k);
    	  if (namptr == NULL) { (yyval).xval = 0.0; }
    	  else { (yyval).xval = namptr->val; }
		  clearchbuf((yyvsp[-1]).chbufx, (yyvsp[-1]).toklen);
		  }
#line 4666 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2862 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4672 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2867 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).yval; }
#line 4678 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2870 "dpic.y" /* yacc.c:1646  */
    { if ((yyvsp[-1]).prim != NULL) {
			switch ((yyvsp[0]).lexval) {
			  case XLheight:
			    (yyval).xval = pheight((yyval).prim);
			    break;
			  case XLwidth:
			    (yyval).xval = pwidth((yyval).prim);
			    break;
			  case XLradius:
			    With2 = (yyval).prim;
			    if (With2->ptype == XLcircle) {(yyval).xval = With2->circleradius_; }
			    else if (With2->ptype == XLarc) {(yyval).xval = With2->aradius_; }
			    else if (With2->ptype == XLbox) {(yyval).xval = With2->boxradius_; }
			    else {
			      (yyval).xval = 0.0;
			      markerror(858); }
			    break;
			case XLdiameter:
			  With2 = (yyvsp[-1]).prim;
			  if (With2->ptype == XLcircle) {(yyval).xval = With2->circleradius_*2; }
			  else if (With2->ptype == XLarc) {(yyval).xval = With2->aradius_*2; }
			  else {
			    (yyval).xval = 0.0;
			    markerror(858); }
			  break;
			case XLthickness:
			  With2 = (yyvsp[-1]).prim; j = With2->ptype;
			  if ((j == XLarc) || (j == XLspline) || (j == XLarrow) ||
                (j == XLline) || (j == XLcircle) || (j == XLellipse) ||
			      (j == XLbox)) { (yyval).xval = With2->lthick; }
			  else {
			    (yyval).xval = 0.0;
			    markerror(858); }
			  break;
			case XLlength:
			  With2 = (yyvsp[-1]).prim; j = With2->ptype;
			  if ((j == XLspline) || (j == XLmove) || (j == XLarrow) ||
                (j == XLline)) {
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
#line 4736 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2925 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = ((double)random()) / randmax; }
#line 4742 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2928 "dpic.y" /* yacc.c:1646  */
    { srandom(Rnd((yyvsp[-1]).xval));
		  (yyval).xval = ((double)random()) / randmax;
		  }
#line 4750 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2933 "dpic.y" /* yacc.c:1646  */
    { switch ((yyval).lexval) {
		    case XLabs: (yyval).xval = fabs((yyvsp[-1]).xval);
		      break;
		    case XLacos:
		      t = (yyvsp[-1]).xval;
		      if (fabs(t) > 1.0) { markerror(868); }
		      else { (yyval).xval = datan(sqrt(1 - (t * t)), t); }
		      break;
		    case XLasin:
		      t = (yyvsp[-1]).xval;
		      if (fabs(t) > 1.0) { markerror(868); }
		      else { (yyval).xval = datan(t, sqrt(1 - (t * t))); }
		      break;
		    case XLcos: (yyval).xval = cos((yyvsp[-1]).xval);
		      break;
		    case XLexp: (yyval).xval = exp(log(10.0) * (yyvsp[-1]).xval);
		      break;
		    case XLexpe: (yyval).xval = exp((yyvsp[-1]).xval);
		      break;
		    case XLint: (yyval).xval = (long)(yyvsp[-1]).xval;
		      break;
		    case XLlog:
		      if ((yyvsp[-1]).xval <= 0.0) { markerror(867); }
		      else { (yyval).xval = log((yyvsp[-1]).xval) / log(10.0); }
		      break;
		    case XLloge:
		      if ((yyvsp[-1]).xval <= 0.0) { markerror(867); }
		      else { (yyval).xval = log((yyvsp[-1]).xval); }
		      break;
		    case XLsign:
		      if ((yyvsp[-1]).xval >= 0.0) { (yyval).xval = 1.0; }
		      else { (yyval).xval = -1.0; }
		      break;
		    case XLsin: (yyval).xval = sin((yyvsp[-1]).xval);
		      break;
		    case XLsqrt:
		      if ((yyvsp[-1]).xval < 0.0) { markerror(867); }
		      else { (yyval).xval = sqrt((yyvsp[-1]).xval); }
		      break;
		    case XLtan:
		      t = cos((yyvsp[-1]).xval);
		      if (t == 0.0) { markerror(868); (yyval).xval = distmax; }
		      else { (yyval).xval = sin((yyvsp[-1]).xval) / t; }
		      break;
		    case XLfloor: (yyval).xval = Floor((yyvsp[-1]).xval);
		      break;
		    }
		  }
#line 4803 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2983 "dpic.y" /* yacc.c:1646  */
    { switch ((yyvsp[-5]).lexval) {
		    case XLatan2: (yyval).xval = datan((yyvsp[-3]).xval, (yyvsp[-1]).xval);
		      break;
		    case XLmax: (yyval).xval = Max((yyvsp[-3]).xval, (yyvsp[-1]).xval);
		      break;
		    case XLmin: (yyval).xval = Min((yyvsp[-3]).xval, (yyvsp[-1]).xval);
		      break;
		    case XLpmod:
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
#line 4826 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 3003 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4832 "dpic.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 3006 "dpic.y" /* yacc.c:1646  */
    { (yyval).xval = (yyvsp[-1]).xval; }
#line 4838 "dpic.tab.c" /* yacc.c:1646  */
    break;


#line 4842 "dpic.tab.c" /* yacc.c:1646  */
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
#line 3009 "dpic.y" /* yacc.c:1906  */
 /* start of programs */

int
yyerror(char *s)
{
  markerror(799);
  return 0;
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
  newprim(&envblock, XBLOCK, NULL);
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
    if (envblock != NULL) { envblock->direction = XLright; }
    inlogic = false;
    inbuf = NULL;
    break;
  }
}

							/* Compute integer power of x */
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

							/* error message strings for lexical terminals */
static const char *const lexterms[] = {
" EOF",
#include "lxerr.h"
};

							/* Write error message with symbol found
							   and symbol expected if possible */
void
markerror(int emi) {
  int inx, j, k;
  fbuffer *thisbuf, *lastbuf;
							/* Do not count warnings */
  if (emi < 900) { errcount++; }
#ifdef DDEBUG
  fbuffer *With;
  if (debuglevel > 0) {
    fprintf(log_, "*** markerror");
    wrbufaddr(inbuf, 0);
    fprintf(log_, " emi=%d, lexsymb=%d:\n", emi, lexsymb);
    if (currentmacro == NULL) {}
	else if (currentmacro->argbody == NULL) { }
	else if (currentmacro->argbody->carray != NULL) {
	  With = currentmacro->argbody;
	  fprintf(errout, "In macro ");
	  FORLIM = -With->attrib;
	  for (j = 1; j <= FORLIM; j++) { wchar(&errout, With->carray[j]); }
      fprintf(errout, ":\n");
	  }
    }
#endif

  fprintf(errout, "\n*** dpic ");
  if (emi < 900) { fprintf(errout, "ERROR"); }
  else { fprintf(errout, "WARNING"); }
  fprintf(errout, " line %d:\n", lineno);

  if (emi < 903) {          /* Write out the input buffer */
      thisbuf = inbuf;
      lastbuf = NULL;
      inx = 1;
      while (thisbuf != NULL) { /* Skip back over white space */
	    lastbuf = thisbuf;
	    j = 0;
	    if (thisbuf->readx > thisbuf->savedlen) { inx = thisbuf->savedlen; }
	    else { inx = thisbuf->readx - 1; }
	    if (thisbuf->readx - 1 < thisbuf->savedlen) { j = thisbuf->readx - 1; }
	    else { j = thisbuf->savedlen; }
	    while (inx > j) {
	      if ( (thisbuf->carray[inx] == etxch)
            || (thisbuf->carray[inx] == tabch)
            || (thisbuf->carray[inx] == ' ')
            || (thisbuf->carray[inx] == crch)
            || (thisbuf->carray[inx] == nlch) ) { inx--; }
	      else { j = inx; }
	      }
	    j = 0;              /* Skip back over code or tabs */
	    while (inx > j) {
	      if (isprint_(thisbuf->carray[inx])
		    || (thisbuf->carray[inx] == tabch)) { inx--; }
	      else { j = inx; }
	      }
	    if (inx == 0) { thisbuf = thisbuf->prevb; }
	    else { thisbuf = NULL; }
        }
      while (lastbuf != NULL) { /* Write out the line or lines */
	    if (lastbuf == inbuf) { k = lastbuf->readx - 1; }
	    else { k = lastbuf->savedlen; }
	  if (inx < 1) { inx = 1; }
	  for (j = inx; j <= k; j++) { wchar(&errout, lastbuf->carray[j]); }
	  if (lastbuf != inbuf) { lastbuf = lastbuf->nextb; }
	  else { lastbuf = NULL; }
	  if (lastbuf != NULL) { inx = lastbuf->readx; }
      }
    putc('\n',errout);
    }

  switch (emi) {
  case 799:                                           /* syntax error */
    fprintf(errout, "Syntax error at or before");
    if ((lexsymb < 0) || (lexsymb > lxmax)) {
      fprintf(errout, " unknown symbol\n"); }
      else { fprintf(errout, " %s\n",lexterms[lexsymb]); }
    if ((newsymb == XLname) || (newsymb == XLabel)) {
      for (i=yylval.chbufx; i<(yylval.chbufx+yylval.toklen); i++) {
        wchar(&errout, chbuf[i]); } }
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
    fprintf(errout, "Bad sprintf format; only e, f, g allowed\n");
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
  if (errcount > MAXERRCOUNT) { fatal(3); }
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
  fprintf(errout, "\nSearch failure");
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
	  fprintf(log_, "[%d", odp(r));
	  if (difa) { fprintf(log_, ":%d", r->attrib); }
	  r = r->nextb; }
    }
  fprintf(log_, "[%d:%d]", odp(q), q->attrib);
  if (job < 0) { return; }
  while (q->nextb != NULL) {
    q = q->nextb;
    fprintf(log_, "%d", odp(q));
    if (difa) { fprintf(log_, ":%d", q->attrib); }
    putc(']', log_);
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
      case 1: fprintf(log_, ",XLto"); break;
      case 2: fprintf(log_, ",XLfrom"); break;
      case 3: fprintf(log_, ",XLat"); break;
      }
    }
  if ((st >> 2) & 1) { fprintf(log_, ",XLchop"); }
  if ((st >> 3) & 1) { fprintf(log_, ",XLdirecton"); }
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
    case XLbox: fprintf(*iou, "<box>"); break;
    case XBLOCK: fprintf(*iou, "<[]>"); break;
    case XLellipse: fprintf(*iou, "<ellipse>"); break;
    case XLcircle: fprintf(*iou, "<circle>"); break;
    case XLline: fprintf(*iou, "<line>"); break;
    case XLarrow: fprintf(*iou, "<arrow>"); break;
    case XLmove: fprintf(*iou, "<move>"); break;
    case XLspline: fprintf(*iou, "<spline>"); break;
    case XLarc: fprintf(*iou, "<arc>"); break;
    case XLstring: fprintf(*iou, "<<string>>"); break;
    case XLaTeX: fprintf(*iou, "<<LaTeX>>"); break;
    case XLabel: fprintf(*iou, "<<Label>>"); break;
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
      case XBLOCK: i = 4; break;
      case XLbox:
      case XLarc: i = 5; break;
      case XLline:
      case XLmove: i = 6; break;
      case XLarrow: i = 7; break;
      case XLcircle:
      case XLspline: i = 8; break;
      case XLellipse:
      case XLaTeX: i = 9; break;
      case XLstring: i = 10; break;
      case XLabel: i = 12; break;
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
	      case XLup: fprintf(log_, " <up>"); break;
	      case XLdown: fprintf(log_, " <down>"); break;
	      case XLleft: fprintf(log_, " <left>"); break;
	      case XLright: fprintf(log_, " <right>"); break;
	      default: fprintf(log_, " dir =%d", With->direction); break;
	      }
	    fprintf(log_, " spec=%d\n", With->spec);
	    fflush(log_);
	    switch (With->ptype) {
	      case XLbox:
	      case XLstring:
		    wlogfl("boxfill", With->boxfill_, 0);
		    wlogfl("boxheight", With->boxheight_, 0);
		    wlogfl("boxwidth", With->boxwidth_, 0);
		    wlogfl("boxrad", With->boxradius_, 0);
		    break;
	      case XBLOCK:
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
	      case XLcircle:
		    wlogfl("cfill", With->circlefill_, 0);
		    wlogfl("radius", With->circleradius_, 0);
		    break;
	      case XLellipse:
		    wlogfl("efill", With->ellipsefill_, 0);
		    wlogfl("elheight", With->ellipseheight_, 0);
		    wlogfl("elwidth", With->ellipsewidth_, 0);
		    break;
	      case XLline:
	      case XLarrow:
	      case XLmove:
	      case XLspline:
		    fprintf(log_, " endpos=");
		    wpair(&log_, With->endpos_.xpos, With->endpos_.ypos);
		    wlogfl("height", With->lineheight_, 0);
		    wlogfl("width", With->linewidth_, 0);
		    wlogfl("lfill", With->linefill_, 0);
		    wlogfl("aradius", With->aradius_, 0);
		    fprintf(log_, "\n ahlex(atype)=%d", ahlex(With->lineatype_));
		    fprintf(log_, " ahnum(atype)=%d", ahnum(With->lineatype_));
		    break;
	      case XLarc:
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
	      case XLabel:
			/* blank case */
		    break;
	      default:
		    fprintf(log_, " Bad case in printobject; this cannot happen\n");
		    break;
	      }
	    putc('\n', log_);
	    fflush(log_);
	    if (With->ptype == XBLOCK) { primp = NULL; }
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
    if ((With->ptype) == XBLOCK) {
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
  case XEQ:
  case XLcoloneq:
    *x = y;
    break;
  case XLpluseq:
    *x += y;
    break;
  case XLminuseq:
    *x -= y;
    break;
  case XLmulteq:
    *x *= y;
    break;
  case XLdiveq:
    if (y == 0) { markerror(852); }
    else { *x /= y; }
    break;
  case XLremeq:
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
  case XLto:
    *st = (((*st) >> 1) * 2) + 1;
    break;
  case XLfrom:
    *st = (((*st) >> 2) * 4) + ((*st) & 1) + 2;
    break;
  case XLat:
    *st = (((*st) >> 3) * 8) + ((*st) & 3) + 4;
    break;
  case XLradius:
    *st = (((*st) >> 4) * 16) + ((*st) & 7) + 8;
    break;
  case XLcw:
    *st = (((*st) >> 5) * 32) + ((*st) & 15) + 16;
    break;
  case XLccw:
    *st = (((*st) >> 6) * 64) + ((*st) & 31) + 32;
    break;
  case XLchop:
    *st = (((*st) >> 7) * 128) + ((*st) & 63) + 64;
    break;
  case XLdirecton:
    *st = (((*st) >> 8) * 256) + ((*st) & 127) + 128;
    break;
  }
}


							/* Test if attribute has been applied */
boolean
teststflag(int st, int value)
{ boolean b = false;

  switch (value) {
  case XLto:
    b = st & 1;
    break;
  case XLfrom:
    b = (st >> 1) & 1;
    break;
  case XLat:
    b = (st >> 2) & 1;
    break;
  case XLradius:
    b = (st >> 3) & 1;
    break;
  case XLcw:
    b = (st >> 4) & 1;
    break;
  case XLccw:
    b = (st >> 5) & 1;
    break;
  case XLchop:
    b = (st >> 6) & 1;
    break;
  case XLdirecton:
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
{ if (!(teststflag(*state, XLto) | teststflag(*state, XLdirecton))) {
      pr->endpos_ = pr->aat; }
  switch (pr->direction) {
  case XLup:
    pr->endpos_.ypos += dy;
    break;
  case XLdown:
    pr->endpos_.ypos -= dy;
    break;
  case XLleft:
    pr->endpos_.xpos -= dx;
    break;
  case XLright:
    pr->endpos_.xpos += dx;
    break;
  }
  setstflag(state, XLdirecton);
}

							/* Test for outline for outlined "string" */
boolean
hasoutline(int lx, boolean warn)
{ boolean hs;
  hs = ((lx == XLspline) || (lx == XLarrow) || (lx == XLline) ||
	(lx == XLarc) || (lx == XLellipse) ||
	(lx == XLcircle) || (lx == XLbox));
  if (drawmode == SVG) { hs = (hs || (lx == XLstring)); }
  if ((!hs) && warn) { markerror(858); }
  return hs;
}


							/* Test for shade for shaded "string" */
boolean
hasshade(int lx, boolean warn)
{ boolean hs;
  if ((lx == XLellipse) || (lx == XLcircle) || (lx == XLbox)) { hs = true; }
  else if ((drawmode == Pict2e) || (drawmode == TeX) || (drawmode == tTeX) ||
           (drawmode == xfig)) { hs = false; }
  else { hs = ((lx == XLspline) || (lx == XLarrow) || (lx == XLline) ||
	    (lx == XLarc)); }
  if (drawmode == SVG) { hs = (hs || (lx == XLstring)); }
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
  case XLbox:
    ph = pr->boxheight_;
    break;
  case XLstring:
    ph = pr->boxheight_;
    break;
  case XBLOCK:
    ph = pr->blockheight_;
    break;
  case XLellipse:
    ph = pr->ellipseheight_;
    break;
  case XLcircle:
    ph = 2.0 * pr->circleradius_;
    break;
  case XLline:
  case XLarrow:
  case XLmove:
  case XLspline:
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

  case XLbox:
  case XLstring:
    pw = pr->boxwidth_;
    break;

  case XBLOCK:
    pw = pr->blockwidth_;
    break;

  case XLellipse:
    pw = pr->ellipsewidth_;
    break;

  case XLcircle:
    pw = 2.0 * pr->circleradius_;
    break;

  case XLline:
  case XLarrow:
  case XLmove:
  case XLspline:
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
    if (ptm->ptype != XBLOCK) { neswrec(ptm->son); }
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
{ /* if ((n div 16) mod 2) <> 0 then lspec := XLsolid
  else */
  return ((n & 7) + XLlinetype);
}

							/* Find the lowest block with environment
							   variables defined */
primitive *(
findenv(primitive *p))
{ primitive *q = NULL;

  while (p != q) {
    if (p->ptype != XBLOCK) { p = p->parent; }
    else if (p->blockparms.env == NULL) { p = p->parent; }
    else { q = p; }
    }
  return p;
}


							/* Get the value of an environment variable */
double
venv(primitive *p, int ind)
{ double v = 0.0;
  if ((ind <= XXenvvar) || (ind > XLlastenv)) { return v; }
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
  case XLfillval: noval = -1.0; break;
  case XLlinethick: noval = mdistmax; break;
  case XLdashwid: noval = mdistmax; break;
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
  offst = venv(pmp, XLtextoffset);
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
  if ((TEMP == XLEFTHEAD) || (TEMP == XDOUBLEHEAD)) {
    cs = affang(pmp->endpos_, pmp->aat);
    awd = qenv(pmp, XLarrowht, pmp->linewidth_);
    aht = qenv(pmp, XLarrowwid, pmp->lineheight_);
    cc = affine(aht, awd / 2, pmp->aat, cs);
    cd = affine(aht, awd / (-2), pmp->aat, cs);
    west = Min(west, Min(cc.xpos, cd.xpos));
    east = Max(east, Max(cc.xpos, cd.xpos));
    south = Min(south, Min(cc.ypos, cd.ypos));
    north = Max(north, Max(cc.ypos, cd.ypos));
    }
  TEMP = ahlex(pmp->lineatype_);
  if (!((TEMP == XRIGHTHEAD) || (TEMP == XDOUBLEHEAD))) { return; }
  cs = affang(pmp->aat, pmp->endpos_);
  awd = qenv(pmp, XLarrowht, pmp->linewidth_);
  aht = qenv(pmp, XLarrowwid, pmp->lineheight_);
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
    case XLstring:
      hight = ptmp->boxheight_;
      wdth = ptmp->boxwidth_;
      break;
    case XLbox:
      hight = ptmp->boxheight_;
      wdth = ptmp->boxwidth_;
      break;
    case XBLOCK:
      hight = ptmp->blockheight_;
      wdth = ptmp->blockwidth_;
      break;
    case XLcircle:
      hight = 2.0 * ptmp->circleradius_;
      wdth = hight;
      break;
    case XLellipse:
      hight = ptmp->ellipseheight_;
      wdth = ptmp->ellipsewidth_;
      break;
    default:
      hight = 0.0;
      wdth = 0.0;
      break;
    }
  switch (ptmp->ptype) {
  case XLbox:
  case XBLOCK:
  case XLcircle:
  case XLellipse:
    north = Max(north, ptmp->aat.ypos + (hight * 0.5));
    south = Min(south, ptmp->aat.ypos - (hight * 0.5));
    west = Min(west, ptmp->aat.xpos - (wdth * 0.5));
    east = Max(east, ptmp->aat.xpos + (wdth * 0.5));
    break;
  case XLstring:
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
  case XLline:
  case XLarrow:
  case XLmove:
  case XLspline:
    neswline(ptmp);
    break;
  case XLaTeX:
  case XLabel:
	/* blank case */
    break;
  case XLarc:
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
  if ((pr->ptype != XBLOCK) && (pr->son != NULL)) {
      FindExitPoint(pr->son, pe);
      return;
  }
  *pe = pr->aat;
  switch (pr->ptype) {
  case XLbox:
    switch (pr->direction) {
    case XLup:
      pe->ypos = pr->aat.ypos + (pr->boxheight_ * 0.5);
      break;
    case XLdown:
      pe->ypos = pr->aat.ypos - (pr->boxheight_ * 0.5);
      break;
    case XLleft:
      pe->xpos = pr->aat.xpos - (pr->boxwidth_ * 0.5);
      break;
    case XLright:
      pe->xpos = pr->aat.xpos + (pr->boxwidth_ * 0.5);
      break;
    }
    break;

  case XLstring:
    switch (pr->direction) {
    case XLup:
      pe->ypos = pr->aat.ypos + (pr->boxheight_ * 0.5);
      break;
    case XLdown:
      pe->ypos = pr->aat.ypos - (pr->boxheight_ * 0.5);
      break;
    case XLleft:
      pe->xpos = pr->aat.xpos - (pr->boxwidth_ * 0.5);
      break;
    case XLright:
      pe->xpos = pr->aat.xpos + (pr->boxwidth_ * 0.5);
      break;
    }
    break;

  case XBLOCK:
    switch (pr->direction) {
    case XLup:
      pe->ypos = pr->aat.ypos + (pr->blockheight_ * 0.5);
      break;
    case XLdown:
      pe->ypos = pr->aat.ypos - (pr->blockheight_ * 0.5);
      break;
    case XLleft:
      pe->xpos = pr->aat.xpos - (pr->blockwidth_ * 0.5);
      break;
    case XLright:
      pe->xpos = pr->aat.xpos + (pr->blockwidth_ * 0.5);
      break;
    }
    break;

  case XLcircle:
    switch (pr->direction) {
    case XLup:
      pe->ypos = pr->aat.ypos + pr->circleradius_;
      break;
    case XLdown:
      pe->ypos = pr->aat.ypos - pr->circleradius_;
      break;
    case XLleft:
      pe->xpos = pr->aat.xpos - pr->circleradius_;
      break;
    case XLright:
      pe->xpos = pr->aat.xpos + pr->circleradius_;
      break;
    }
    break;

  case XLellipse:
    switch (pr->direction) {
    case XLup:
      pe->ypos = pr->aat.ypos + (pr->ellipseheight_ * 0.5);
      break;
    case XLdown:
      pe->ypos = pr->aat.ypos - (pr->ellipseheight_ * 0.5);
      break;
    case XLleft:
      pe->xpos = pr->aat.xpos - (pr->ellipsewidth_ * 0.5);
      break;
    case XLright:
      pe->xpos = pr->aat.xpos + (pr->ellipsewidth_ * 0.5);
      break;
    }
    break;

  case XLarc:
    *pe = arcend(pr);
    break;

  case XLline:
  case XLarrow:
  case XLmove:
  case XLspline:
    *pe = pr->endpos_;
    break;

  case XLabel:
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
{ *specv = (((*specv) >> 3) * 8) + svalue - XLlinetype;
							/* if svalue = XLsolid then
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
    case XLbox:
    case XLstring:
      *pr = malloc(sizeof(XLboxprimitive));
      break;
    case XBLOCK:
      *pr = malloc(sizeof(primitive));
      break;
    case XLcircle:
      *pr = malloc(sizeof(XLcircleprimitive));
      break;
    case XLellipse:
      *pr = malloc(sizeof(XLellipseprimitive));
      break;
    case XLline:
    case XLarc:
    case XLarrow:
    case XLmove:
    case XLspline:
      *pr = malloc(sizeof(XLlineprimitive));
      break;
    case XLabel:
    case XLaTeX:
      *pr = malloc(sizeof(XLabelprimitive));
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
    With->direction = XLright;
    }
  else {
    With->parent = envblk;
    With->aat = envblk->here_;
    With->direction = envblk->direction;
    }
  With->lparam = mdistmax;
  With->lthick = mdistmax;
  if ((primtype == XLstring) || (primtype == XLspline) ||
    (primtype == XLarc) || (primtype == XLarrow) || (primtype == XLline) ||
    (primtype == XLellipse) || (primtype == XLcircle) ||
    (primtype == XLbox)) { resetspec(&With->spec, XLsolid); }
  else { resetspec(&With->spec, XLinvis); }
  With->ptype = primtype;
  switch (primtype) {
    case XLbox:
    case XLstring:
      With->boxfill_ = -1.0;
      With->boxheight_ = 0.0;
      With->boxwidth_ = 0.0;
      With->boxradius_ = 0.0;
      break;
    case XBLOCK:
      With->blockheight_ = 0.0;
      With->blockwidth_ = 0.0;
      With->here_ = With->aat;
      for (i = 0; i <= HASHLIM; i++) {
	    With->blockparms.vars[i]   = NULL;
	    With->blockparms.nvars[i]   = 0; }
      With->blockparms.env = NULL;
      break;
    case XLcircle:
      With->circlefill_ = -1.0;
      With->circleradius_ = 0.0;
      break;
    case XLellipse:
      With->ellipsefill_ = -1.0;
      With->ellipseheight_ = 0.0;
      With->ellipsewidth_ = 0.0;
      break;
    case XLline:
    case XLarrow:
    case XLmove:
    case XLarc:
    case XLspline:
      With->endpos_.xpos = 0.0;
      With->endpos_.ypos = 0.0;
      With->lineheight_ = 0.0;
      With->linewidth_ = 0.0;
      With->linefill_ = -1.0;
      With->aradius_ = mdistmax;
      With->lineatype_ = pahlex(0, XEMPTY);
      break;
    case XLabel:
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
    case XLup:
	  envblock->direction = XLleft;
	  break;
    case XLdown:
	  envblock->direction = XLright;
	  break;
    case XLleft:
	  envblock->direction = XLdown;
	  break;
    case XLright:
	  envblock->direction = XLup;
	  break;
    }
    return;
  }
  switch (pr->direction) {
  case 0: /* blank case */
    break;
  case XLup:
    envblock->direction = XLright;
    break;
  case XLdown:
    envblock->direction = XLleft;
    break;
  case XLleft:
    envblock->direction = XLup;
    break;
  case XLright:
    envblock->direction = XLdown;
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
    if ((pr->ptype == XLspline) || (pr->ptype == XLmove) ||
	    (pr->ptype == XLarrow) || (pr->ptype == XLline)) {
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
    if (With->ptype == XLbox) {
	  With->boxheight_ *= s;
	  With->boxwidth_ *= s;
	  With->boxradius_ *= s;
      }
    else if (With->ptype == XBLOCK) {
	  With->blockheight_ *= s;
	  With->blockwidth_ *= s;
      }
    else if (With->ptype == XLcircle) {
	  With->circleradius_ *= s;
      }
    else if (With->ptype == XLellipse) {
	  With->ellipseheight_ *= s;
	  With->ellipsewidth_ *= s;
      }
    else if (With->ptype == XLarc) {
	  With->aradius_ *= s;
      }
    else if ((With->ptype == XLspline) || (With->ptype == XLmove) ||
	       (With->ptype == XLarrow) || (With->ptype == XLline)) {
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
      ((pr->ptype == XLspline) || (pr->ptype == XLmove) ||
       (pr->ptype == XLarrow) || (pr->ptype == XLline))) {
    while (pe->son != NULL) { pe = pe->son; }
    *x = 0.5 * (pr->aat.xpos + pe->endpos_.xpos);
    *y = 0.5 * (pr->aat.ypos + pe->endpos_.ypos);
    return;
    }
  if ((lexv == XEMPTY) && (pr->ptype != XLstring) && (pr->ptype != XLaTeX)) {
      return; }
  switch (pr->ptype) {
    case XLbox:
    case XLstring:
    case XBLOCK:
    case XLcircle:
    case XLellipse:
    case XLarc:
      *x = pr->aat.xpos;
      *y = pr->aat.ypos;
      initnesw();
      nesw(pr);
							/* Compass corners of justified strings not
							   implemented: */
		/* if ptype = XLstring then begin
         checkjust(textp,A,B,L,R);
         offst := venv(pr,XLtextoffset);
         if L then x := x+boxwidth/2 + offst
         else if R then x := x-boxwidth/2 - offst;
         if A then y := y+boxheight/2 + offst
         else if B then y := y-boxheight/2 - offst;
         end; */
      if ((pr->ptype == XLstring) && (drawmode == SVG)) {
	    switch (lexv) {
	      case XDn: *y = north; break;
	      case XDs: *y = south; break;
	      case XDe: *x = east; break;
	      case XDw: *x = west; break;
	      case XDne: *y = north; *x = east; break;
	      case XDse: *y = south; *x = east; break;
	      case XDsw: *y = south; *x = west; break;
	      case XDnw: *y = north; *x = west; break;
	      case XDc: *y = pr->aat.ypos; *x = pr->aat.xpos; break;
	      case XDstart:
	      case XDend: markerror(858); break;
	      }
	    checkjust(pr->textp, &A, &B, &L, &R);
	    if (L) { pr->boxradius_ = (west - east) / 2; }
	    else if (R) { pr->boxradius_ = (east - west) / 2; }
        }
      else if (((pr->ptype == XLarc) || (pr->ptype == XLcircle) ||
	      (pr->ptype == XLellipse) || (pr->ptype == XLbox)) &&
	     ((lexv == XDnw) || (lexv == XDsw) || (lexv == XDse) ||
	      (lexv == XDne))) {
	    switch (pr->ptype) {
	    case XLbox:
	      *y = Min(pr->boxradius_, Min(fabs(pr->boxheight_),
		       fabs(pr->boxwidth_)) / 2) * (1 - (1 / sqrt(2.0)));
	      *x = (pr->boxwidth_ / 2) - (*y);
	      *y = (pr->boxheight_ / 2) - (*y);
	      break;
	    case XLellipse:
	      *x = pr->ellipsewidth_ * (0.5 / sqrt(2.0));
	      *y = pr->ellipseheight_ * (0.5 / sqrt(2.0));
	      break;
	    case XLarc:
	      *x = pr->aradius_ / sqrt(2.0);
	      *y = *x;
	      break;
	    case XLcircle:
	      *x = pr->circleradius_ / sqrt(2.0);
	      *y = *x;
	      break;
	    }
	    switch (lexv) {
	    case XDne: /* blank case */ break;
	    case XDse: *y = -*y; break;
	    case XDnw: *x = -*x; break;
	    case XDsw: *x = -*x; *y = -*y; break;
	    }
	    *x = pr->aat.xpos + (*x);
	    *y = pr->aat.ypos + (*y);
        }
      else if (pr->ptype == XLarc) {
	    switch (lexv) {
	    case XDn: *y = pr->aat.ypos + pr->aradius_; break;
	    case XDs: *y = pr->aat.ypos - pr->aradius_; break;
	    case XDe: *x = pr->aat.xpos + pr->aradius_; break;
	    case XDw: *x = pr->aat.xpos - pr->aradius_; break;
	    case XDc: /* blank case */ break;
	    case XDstart:
	      *x = pr->aat.xpos + (pr->aradius_ * cos(pr->startangle_));
	      *y = pr->aat.ypos + (pr->aradius_ * sin(pr->startangle_));
	      break;
	    case XDend:
	      *x = pr->aat.xpos +
                 (pr->aradius_ * cos(pr->startangle_+pr->arcangle_));
	      *y = pr->aat.ypos +
                 (pr->aradius_ * sin(pr->startangle_+pr->arcangle_));
	      break;
	    } }
      else {
	    switch (lexv) {
	    case XDn: *y = north; break;
	    case XDs: *y = south; break;
	    case XDe: *x = east; break;
	    case XDw: *x = west; break;
	    case XDne: *y = north; *x = east; break;
	    case XDse: *y = south; *x = east; break;
	    case XDsw: *y = south; *x = west; break;
	    case XDnw: *y = north; *x = west; break;
	    case XDc: *y = pr->aat.ypos; *x = pr->aat.xpos; break;
	    case XDstart:
	    case XDend: markerror(858); break;
	    } }
      break;

    case XLline:
    case XLarrow:
    case XLmove:
    case XLspline:
      if (lexv != XDstart) {
	if (lexv == XDend) {
	    while (pe->son != NULL) { pe = pe->son; }
	    *x = pe->endpos_.xpos;
	    *y = pe->endpos_.ypos; }
	else if (lexv == XDc) {
	    while (pe->son != NULL) { pe = pe->son; }
	    *x = 0.5 * ((*x) + pe->endpos_.xpos);
	    *y = 0.5 * ((*y) + pe->endpos_.ypos); }
	else {
	    do {
		  sb = false;
		  switch (lexv) {
		  case XDn:
		    sb = (pe->endpos_.ypos > (*y));
		    break;
		  case XDs:
		    sb = (pe->endpos_.ypos < (*y));
		    break;
		  case XDe:
		    sb = (pe->endpos_.xpos > (*x));
		    break;
		  case XDw:
		    sb = (pe->endpos_.xpos < (*x));
		    break;
		  case XDne:
		    sb = (((pe->endpos_.ypos > (*y)) && (pe->endpos_.xpos >= (*x))) ||
			  ((pe->endpos_.ypos >= (*y)) && (pe->endpos_.xpos > (*x))));
		    break;
		  case XDse:
		    sb = (((pe->endpos_.ypos < (*y)) && (pe->endpos_.xpos >= (*x))) ||
			  ((pe->endpos_.ypos <= (*y)) && (pe->endpos_.xpos > (*x))));
		    break;
		  case XDsw:
		    sb = (((pe->endpos_.ypos < (*y)) && (pe->endpos_.xpos <= (*x))) ||
			  ((pe->endpos_.ypos <= (*y)) && (pe->endpos_.xpos < (*x))));
		    break;
		  case XDnw:
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

  case XLabel:
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
    last = XLlastenv;
    }
  else if (envval < 0) {
    envval = XXenvvar + 1;
    last = XLlastsc;
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
      case XLarcrad: envbl->blockparms.env[i - XXenvvar] = 0.25;
	    break;
      case XLarrowht: envbl->blockparms.env[i - XXenvvar] = 0.1;
	    break;
      case XLarrowwid: envbl->blockparms.env[i - XXenvvar] = 0.05;
	    break;
      case XLboxht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLboxrad: envbl->blockparms.env[i - XXenvvar] = 0.0;
	    break;
      case XLboxwid: envbl->blockparms.env[i - XXenvvar] = 0.75;
	    break;
      case XLcirclerad: envbl->blockparms.env[i - XXenvvar] = 0.25;
	    break;
      case XLdashwid: envbl->blockparms.env[i - XXenvvar] = 0.05;
	    break;
      case XLellipseht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLellipsewid: envbl->blockparms.env[i - XXenvvar] = 0.75;
	    break;
      case XLlineht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLlinewid: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLmoveht: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLmovewid: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLtextht:
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
      case XLtextoffset: envbl->blockparms.env[i - XXenvvar] = 2.0 / 72;
	    break;
      case XLtextwid: envbl->blockparms.env[i - XXenvvar] = 0.0;
	    break;
							/* The following are unscaled */
      case XLarrowhead: envbl->blockparms.env[i - XXenvvar] = 1.0;
	    break;
      case XLfillval: envbl->blockparms.env[i - XXenvvar] = 0.5;
	    break;
      case XLlinethick: envbl->blockparms.env[i - XXenvvar] = 0.8;
	    break;
      case XLmaxpsht: envbl->blockparms.env[i - XXenvvar] = 11.0;
	    break;
      case XLmaxpswid: envbl->blockparms.env[i - XXenvvar] = 8.5;
	    break;
      case XLscale: envbl->blockparms.env[i - XXenvvar] = 1.0;
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
  for (i = XXenvvar; i <= (XLlastenv - 1); i++) {
      envbl->blockparms.env[i - XXenvvar] = pr->blockparms.env[i - XXenvvar];
  }
}


							/* Execute scale = x */
void
resetscale(double x, int opr, primitive *envbl)
{ double r, s;
  int i;

  resetenv(-1, envbl);
  r = envbl->blockparms.env[XLscale - XXenvvar - 1];
  eqop(&envbl->blockparms.env[XLscale - XXenvvar - 1], opr, x);
  s = envbl->blockparms.env[XLscale - XXenvvar - 1];
  if (s == 0.0) {
      envbl->blockparms.env[XLscale - XXenvvar - 1] = r;
      s = 1.0;
      markerror(870);
  }
  else if (r == 0.0) {
      markerror(852);
  }
  else {
      s /= r;
  }
  for (i = XXenvvar; i < XLlastsc; i++) {
      eqop(&envbl->blockparms.env[i - XXenvvar], XLmulteq, s);
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
      if (lp->ptype == XBLOCK) {
	  qp = findenv(lp);
	  if (qp->blockparms.env[XLscale - XXenvvar - 1] > 0.0) {
	      *sfact = qp->blockparms.env[XLscale - XXenvvar - 1];
	  }
	  if ((east > west) &&
	      ((east - west) / (*sfact) >
	       qp->blockparms.env[XLmaxpswid - XXenvvar - 1]) &&
	      (qp->blockparms.env[XLmaxpswid - XXenvvar - 1] > 0.0)) {
	      erno = 903;
	      gs = (east - west) / qp->blockparms.env[XLmaxpswid - XXenvvar - 1];
	  }
	  if ((north > south) &&
	      ((north - south) / (*sfact) >
	       qp->blockparms.env[XLmaxpsht - XXenvvar - 1]) &&
	      (qp->blockparms.env[XLmaxpsht - XXenvvar - 1] > 0.0)) {
	      erno = 904;
	      gs = Max(gs,
		  (north - south) / qp->blockparms.env[XLmaxpsht - XXenvvar - 1]);
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
  case XLbox:
  case XLstring:
    (*prout)->boxfill_ = prin->boxfill_;
    (*prout)->boxheight_ = prin->boxheight_;
    (*prout)->boxwidth_ = prin->boxwidth_;
    (*prout)->boxradius_ = prin->boxradius_;
    break;
  case XBLOCK:
    (*prout)->blockheight_ = prin->blockheight_;
    (*prout)->blockwidth_ = prin->blockwidth_;
    (*prout)->here_ = prin->here_;
    for (i = 0; i <= HASHLIM; i++) {
	  (*prout)->blockparms.vars[i] = prin->blockparms.vars[i];
	  (*prout)->blockparms.nvars[i] = prin->blockparms.nvars[i]; }
    if (prin->blockparms.env != NULL) {
	  (*prout)->blockparms.env = malloc(sizeof(envarray));
	  for (i = XXenvvar; i < XLlastenv; i++) {
	    (*prout)->blockparms.env[i - XXenvvar] =
          prin->blockparms.env[i - XXenvvar];
	    }
      }
    break;
  case XLcircle:
    (*prout)->circlefill_ = prin->circlefill_;
    (*prout)->circleradius_ = prin->circleradius_;
    break;
  case XLellipse:
    (*prout)->ellipsefill_ = prin->ellipsefill_;
    (*prout)->ellipseheight_ = prin->ellipseheight_;
    (*prout)->ellipsewidth_ = prin->ellipsewidth_;
    break;
  case XLline:
  case XLarrow:
  case XLmove:
  case XLarc:
  case XLspline:
    (*prout)->endpos_ = prin->endpos_;
    (*prout)->lineheight_ = prin->lineheight_;
    (*prout)->linewidth_ = prin->linewidth_;
    (*prout)->linefill_ = prin->linefill_;
    (*prout)->aradius_ = prin->aradius_;
    (*prout)->lineatype_ = prin->lineatype_;
    break;
  case XLabel:
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
	if (a1->prim->ptype == XLarc) { arcenddir(prp); }
	if (teststflag(a1->state, XLat)) {    /* deferred shift */
	    With2 = a1->prim;
	    i = getstval(a1->state);
	    if (i == XLfloat) {  /* pair at */
		  getnesw(a1->prim);
		  dx = west + a1->startchop;
		  dy = south + a1->endchop;
	      }
	    else if (a1->internal != NULL) { corner(a1->internal, i, &dx, &dy); }
	    else { corner(a1->prim, i, &dx, &dy); }
	    a1->internal = NULL;
	    if ((drawmode == SVG) && (With2->ptype == XLstring)) {
		  ts = venv(a1->prim, XLtextoffset);
		  if (teststflag(a1->state, XLcw)) {    /* shift by arg2,arg3 */
		    switch (i) {                                   /* textpos */
		      case XDe:  dx += ts; break;
		      case XDne: dx += ts; dy += ts; break;
		      case XDn:  dy += ts; break;
		      case XDnw: dx -= ts; dy += ts; break;
		      case XDw:  dx -= ts; break;
		      case XDsw: dx -= ts; dy -= ts; break;
		      case XDs:  dy -= ts; break;
		      case XDse: dx += ts; dy -= ts; break;
		      }
		    }
		  shift(a1->prim, a1->xval - dx, a1->yval - dy);
	      }
	    else if (With2->ptype != XLarc) {
		  shift(a1->prim, a1->xval - dx, a1->yval - dy); }
	    else {
		  x1 = With2->aat.xpos +
		     (With2->aradius_ * cos(With2->startangle_));
							/* from */
		  z1 = With2->aat.ypos +
		     (With2->aradius_ * sin(With2->startangle_));
		  if (teststflag(a1->state, XLto)) {
							/* to X from Here|Y implied */
		    if ((i != XEMPTY) && (i != XDc)) { markerror(858); }
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
		  else if (teststflag(a1->state, XLfrom)) {
		    if ((i != XEMPTY) && (i != XDc)) { markerror(858); }
		    With2->aat.xpos = a1->xval;
		    With2->aat.ypos = a1->yval;
		    t = datan(z1 - With2->aat.ypos, x1 - With2->aat.xpos);
		    r = With2->aat.xpos + (With2->aradius_ * cos(t + With2->arcangle_));
		    s = With2->aat.ypos + (With2->aradius_ * sin(t + With2->arcangle_));
		    With2->aradius_ = linlen(x1 - With2->aat.xpos,z1 - With2->aat.ypos);
		    setangles(&With2->startangle_, &With2->arcangle_, With2->aat,
               x1, z1, r, s);
			}
		  else { shift(a1->prim, With->xval - dx, With->yval - dy); }
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
{ newprim(&a0->prim, XLstring, envblock);
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
  With2->boxheight_ = eb->envinx(XLtextht);
  With2->boxwidth_ = eb->envinx(XLtextwid);
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
		  0.1 * eb->envinx(XLscale); }
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
