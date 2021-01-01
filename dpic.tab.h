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

#endif /* !YY_YY_DPIC_TAB_H_INCLUDED  */
