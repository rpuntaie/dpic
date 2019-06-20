/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_DPIC_TAB_H_INCLUDED
# define YY_YY_DPIC_TAB_H_INCLUDED
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

#endif /* !YY_YY_DPIC_TAB_H_INCLUDED  */
