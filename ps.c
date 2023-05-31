/* Output routines for Postscript, PSfrag */
void
pswfloat (FILE ** iou, double x) {
  putc (' ', *iou);
  wfloat (iou, x);
}

void
psprelude (double n, double s, double e, double w, double lth) {
  double wx, ex, nx, sx;

  /* writeln('%!PS'); */
  /* writeln('%!PS-Adobe-3.0 EPSF-3.0'); */
  printf ("%%!PS-Adobe-3.0\n");
  wx = (w / fsc) - (lth / 2);
  ex = (e / fsc) + (lth / 2);
  nx = (n / fsc) + (lth / 2);
  sx = (s / fsc) - (lth / 2);
  printf ("%%%%BoundingBox: %d %d %d %d\n",
	  Floor (((long) floor ((wx * 1000000L) + 0.5)) / 1000000.0),
	  Floor (((long) floor ((sx * 1000000L) + 0.5)) / 1000000.0),
	  Ceil (((long) floor ((ex * 1000000L) + 0.5)) / 1000000.0),
	  Ceil (((long) floor ((nx * 1000000L) + 0.5)) / 1000000.0));
  printf ("%%%%HiResBoundingBox:");
  pswfloat (&output, wx);
  pswfloat (&output, sx);
  pswfloat (&output, ex);
  pswfloat (&output, nx);
  printf ("\n%%%%Creator: dpic version %s option ",VERSIONDATE);
  switch (drawmode) {

  case PSfrag:
    printf ("-f (psfrag strings)");
    break;

  case PS:
    printf ("-r");
    break;
  }
  printf (" for Postscript\n");
  printf ("%%%%Pages: 1\n");
  printf ("%%%%EndComments\n");
  /* writeln('%%EndProlog'); */
  printf ("%%%%Page: 1 1\n");
  /* writeln('userdict begin'); */
  printf ("/DpicDict 100 dict def DpicDict begin\n");
  /* writeln('/setlinewid {0 exch 72.27 div 72 mul');
     writeln(' dtransform truncate idtransform setlinewidth pop} def'); */
  /* write('/setlineparms { [] 0 setdash 0 setlinecap 1 setlinejoin'); */
  printf ("/setlineparms { [] 0 setdash 0 setlinecap 0 setlinejoin");
  printf (" 10 setmiterlimit} def\n");
  printf ("/ostroke { stroke setlineparms } def\n");
  printf ("/endstroke { ostroke } def /npath { newpath } def\n");
  printf (" setlineparms\n");
  if ((printstate & 1) != 1) { return; }
  if (drawmode == PS) {
    printf ("/strsiz\n");
    printf (" {newpath 0 0 moveto true charpath flattenpath");
    printf (" pathbbox 4 1 roll pop pop pop}def\n");
    printf ("/setcapht {gsave (I) strsiz /capht exch def grestore} def\n");
    printf (
   "/postext {1 add baselineskip mul 1 sub 2 div capht mul add moveto} def\n");
    printf ("/strwidth { dup stringwidth pop } def\n");
    printf ("/ljust { labelsep } def\n");
    printf ("/rjust { strwidth labelsep add neg } def\n");
    printf ("/cjust { strwidth 2 div neg } def\n");
    printf ("/above { capht 2 div labelsep add } def\n");
    printf ("/below { capht 2 div neg labelsep sub } def\n");
    printf ("/vjust {0 capht baselineskip mul neg rmoveto\n");
    printf (" currentpoint /y exch def /x exch def} def\n"); }
  else {
    printf ("/ljust { labelsep } def /rjust { labelsep neg } def ");
    printf ("/cjust { 0 } def\n");
    printf ("/above { labelsep } def /below { labelsep neg } def ");
    }
  printf ("/vcenter { 0 } def\n");
  printf ("/basefont {/Times-Roman findfont} def\n");
  printf (" basefont 11 scalefont setfont\n");
  printf ("/labelsep 2 def\n");
  printf ("/baselineskip 1.4 def\n");
}

void
pspostlude (void) {
  printf ("showpage end\n");
  printf ("%%%%EOF\n");
}

void
psnewpath (void) {
  printf ("npath\n");
}

void
pswcoord (FILE ** iou, double x, double y) {
  pswfloat (iou, x / fsc);
  pswfloat (iou, y / fsc);
}

void
pswpos (postype pos) {
  pswcoord (&output, pos.xpos, pos.ypos);
}

void
pswstring (nametype * p) {
  int i;
  Char c;
  boolean waswhite = false;
  boolean iswhite;

  if (p == NULL) { return; }
  if (p->segmnt == NULL) { return; }
  for (i = 0; i < p->len; i++) {
    c = p->segmnt[p->seginx + i];
    iswhite = ((c == etxch) || (c == nlch) || (c == tabch) || (c == ' '));
    if ((!iswhite) || (!waswhite)) {
      if ((c == bslch) || (c == ')') || (c == '(')) { putchar (bslch); }
      putchar (c);
      }
    waswhite = iswhite;
    }
}

void
pswtext (primitive * np, nametype * tp, double x, double y) {
  int i;
  nametype *tx;
  boolean L, R, A, B;
  double toff, theight;

  if ((tp != NULL) && (drawmode == PS)) {
    tx = tp;
    i = 0;
    do {
      i++;
      tx = tx->nextname;
    } while (tx != NULL);
    printf (" setcapht");
    pswcoord (&output, x, y);
    printf (" %d postext\n", i);
    do {
      printf (" vjust (");
      checkjust (tp, &A, &B, &L, &R);
      pswstring (tp);
      printf (")\n");
      if (L) { printf (" ljust"); }
      else if (R) { printf (" rjust"); }
      else { printf (" cjust"); }
      if (A) { printf (" above"); }
      else if (B) { printf (" below"); }
      else { printf (" vcenter"); }
      printf (" rmoveto show x y moveto\n");
      tp = tp->nextname;
    } while (tp != NULL);
    return;
    }
  if (tp == NULL) { return; }
  toff = (venv (np, Xtextoffset) / scale) * 72;
  theight = (venv (np, Xtextht) / scale) * 72;
  printf ("(\\\\tex[");
  checkjust (tp, &A, &B, &L, &R);
  if (L) { putchar ('l'); }
  else if (R) { putchar ('r'); }
  else { putchar ('c'); }
  if (A) { putchar ('b'); }
  else if (B) { putchar ('t'); }
  else { putchar ('c'); }
  printf ("][lB]");
  if (theight != 0) {
    putchar ('[');
    wfloat (&output, theight / 11);
    putchar (']');
    }
  putchar ('{');
  if (tp->nextname != NULL) { printf ("\\\\shortstack{"); }
  tx = tp;
  do {
    if (L) {
      printf ("\\\\rlap{\\\\hbox to ");
      wfloat (&output, toff);
      printf ("bp{}");
      }
    else if (R) { printf ("\\\\llap{"); }
    pswstring (tx);
    if (R) {
      printf ("\\\\hbox to ");
      wfloat (&output, toff);
      printf ("bp{}");
      }
    if (L || R) { putchar ('}'); }
    tx = tx->nextname;
    if (tx != NULL) {
      printf ("\\\\\\\\ ");
      checkjust (tx, &A, &B, &L, &R);
      }
    } while (tx != NULL);
  if (tp->nextname != NULL) { printf ("}})\n"); }
  else { printf ("})\n"); }
  pswcoord (&output, x, y);
  printf (" moveto");
  checkjust (tp, &A, &B, &L, &R);
  if (L) { printf (" ljust"); }
  else if (R) { printf (" rjust"); }
  else { printf (" cjust"); }
  if (A) { printf (" above"); }
  else if (B) { printf (" below"); }
  else { printf (" vcenter"); }
  printf (" rmoveto show\n");
}

void
pswprop (postype p1, postype p2, double a, double b, double c) {
  pprop (p1, &p2, a, b, c);
  pswpos (p2);
}

void
pssetthick (double lthk) {
  if ((lthk < 0.0) || (lthk == gslinethick)) { return; }
  pswfloat (&output, lthk);
  printf (" setlinewidth\n");
  gslinethick = lthk;
}

void
pslinearfill (double f, nametype * ss) {
  if ((f >= 0.0) && (f <= 1.0)) {
    printf (" currentrgbcolor");
    pswfloat (&output, f);
    printf (" setgray fill setrgbcolor\n");
    return;
    }
  if (ss == NULL) { return; }
  printf (" currentrgbcolor");
  putchar (' ');
  wstring (&output, ss);
  printf (" setrgbcolor fill setrgbcolor\n");
}

void
pssetcolor (nametype * op) {
  if (op == NULL) { return; }
  printf (" currentrgbcolor ");
  wstring (&output, op);
  printf (" setrgbcolor\n");
}

void
psdashdot (int lspec, double param) {
  if (lspec == Xdashed) {
    if (ismdistmax (param)) { param = 3 * fsc; }
    printf (" [");
    pswfloat (&output, param / fsc);
    pswfloat (&output, param / fsc);
    printf (" ] 0 setdash\n");
    return;
    }
  if (lspec != Xdotted) { return; }
  if (ismdistmax (param)) { param = 5 * fsc; }
  printf (" [ 0");
  pswfloat (&output, param / fsc);
  printf (" ] 0 setdash 1 setlinecap\n");
}

void
psendline (nametype * op) {
  printf (" endstroke");
  if (op != NULL) { printf (" setrgbcolor\n"); }
  else { putchar ('\n'); }
}

void
pswarc (postype Ctr, postype Start, postype En, double radjust, double ccw) {
  double y, radius;

  radius = distance(Ctr,En) + radjust;
  pswpos (Ctr); pswfloat (&output, radius / fsc);
  y = datan (Start.ypos - Ctr.ypos, Start.xpos - Ctr.xpos);
  pswfloat (&output, (180.0 / pi) * y);
  y = datan (En.ypos - Ctr.ypos, En.xpos - Ctr.xpos);
  pswfloat (&output, (180.0 / pi) * y);
  if (ccw >= 0.0) { printf (" arc\n"); } else { printf (" arcn\n"); }
}

void
psarcahead (postype C, int atyp, postype * point, double ht, double wid,
	    double lth, double radius, double angle) {
  postype P, Q, Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi, ds;
  boolean startarrow;

  arcahead (C, *point, atyp, ht, wid, lth, radius, angle, &P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  /* Trace arrowhead outline */
  psnewpath ();
  pswarc (Ci, Ai, *point, 0.0, -ccw);
  pswarc (Co, *point, Ao, 0.0, ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
      ds = distance(Co, Ao);
      Q = Co; pprop(Ao, &Q, ds - lwi, lwi, ds);
      pswpos(Q); printf(" lineto\n");
      pswarc(Co, Q, Px, 0.0, -ccw);
      pswarc(Ci, Px, Ai, lwi, ccw); }
  if (atyp == 3) {
      pswarc(Cox, Ao, Px, 0.0, -ccw);
      pswarc(Cix, Px, Ai, 0.0, ccw); }
  else {
      pswpos(Ai);
      printf(" lineto\n"); }
  printf (" fill\n");
  *point = P;
}

void
psahead (int atyp, postype * point, postype shaft, double ht, double wid,
	 double lth) {
  postype P, L, R, Px, Lx, Rx, Q;
  double x, y;

  dahead (*point, shaft, ht, wid, (lth / 72) * scale, &P, &L, &R, &Px, &Lx,
	  &Rx, &Q, &x, &y);
  psnewpath ();
  if (atyp == 0) {
    pswprop (P, R, x - y, y, x);
    printf (" moveto");
    pswpos (P);
    printf (" lineto\n");
    pswprop (P, L, x - y, y, x);
    printf (" lineto");
    psendline (NULL); }
  else {
    pswpos (Rx);
    printf (" moveto\n");
    pswpos (*point);
    printf (" lineto");
    pswpos (Lx);
    printf (" lineto\n");
    if (atyp == 3) {
      pswpos (Px);
      printf (" lineto\n"); }
    printf (" closepath fill\n");
    }
  *point = P;
}

void
psbox (postype aat, double halfwid, double halfht, double rad) {
  int i;
  postype corner[4];

  psnewpath ();
  corner[0].xpos = aat.xpos + halfwid;
  corner[0].ypos = aat.ypos + halfht;
  corner[1].xpos = aat.xpos - halfwid;
  corner[1].ypos = aat.ypos + halfht;
  corner[2].xpos = aat.xpos - halfwid;
  corner[2].ypos = aat.ypos - halfht;
  corner[3].xpos = aat.xpos + halfwid;
  corner[3].ypos = aat.ypos - halfht;
  pswcoord (&output, aat.xpos + halfwid, aat.ypos);
  printf (" moveto 0 setlinejoin\n");
  rad = Min (Min (fabs (rad), fabs (halfht)), fabs (halfwid));
  if (rad == 0.0) {
    for (i = 0; i <= 3; i++) {
      pswpos (corner[i]);
      printf (" lineto");
      if ((i == 1) || (i == 3)) { putchar ('\n'); }
      }
    }
  else {
    for (i = 0; i <= 3; i++) {
      pswpos (corner[i]);
      pswpos (corner[(i + 1) & 3]);
      pswfloat (&output, rad / fsc);
      printf (" arcto 4 {pop} repeat\n");
      }
    }
  printf (" closepath");
}

void
pscircle (double rd) {
  psnewpath ();
  printf (" 0 0");
  pswfloat (&output, fabs (rd) / fsc);
  printf (" 0 360 arc closepath");
}

void
psellipse (double x, double y) {
  x = fabs (x) / 2;
  y = fabs (y) / 2;
  psnewpath ();
  pswcoord (&output, x, 0.0);
  printf (" moveto\n");
  pswcoord (&output, x, y * SPLT);
  pswcoord (&output, x * SPLT, y);
  pswcoord (&output, 0.0, y);
  printf (" curveto\n");
  pswcoord (&output, -x * SPLT, y);
  pswcoord (&output, -x, y * SPLT);
  pswcoord (&output, -x, 0.0);
  printf (" curveto\n");
  pswcoord (&output, -x, -y * SPLT);
  pswcoord (&output, -x * SPLT, -y);
  pswcoord (&output, 0.0, -y);
  printf (" curveto\n");
  pswcoord (&output, x * SPLT, -y);
  pswcoord (&output, x, -y * SPLT);
  pswcoord (&output, x, 0.0);
  printf (" curveto closepath\n");
}

void
pssplinesegment (primitive * tv, int splc, int splt) {
  if (tv == NULL) { return; }
  if (splt == 1) {
    pswpos (tv->aat);
    printf (" moveto");
    pswpos (tv->endpos_);
    printf (" lineto\n");
    return;
  }
  if (ismdistmax (tv->aradius_)) {
    if ((splc == splt) && (splc > 1)) {	/* 1st seg */
      pswpos (tv->aat);
      printf (" moveto\n");
      pswprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      printf (" lineto\n");
      pswprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
      return;
    }
    if (splc > 1) {		/* interior segment */
      pswprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
      pswprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      printf (" curveto\n");
      pswprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
      return;
    }
    pswprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
    pswprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    printf (" curveto\n");
    pswpos (tv->endpos_);
    printf (" lineto\n");
    /* last segment */
    return;
  }
  if ((splc == splt) && (splc > 1)) {
    pswpos (tv->aat);
    printf (" moveto\n");
    pswprop (tv->aat, tv->endpos_, 1 - tv->aradius_,
	     tv->aradius_, 1.0);
    return;
  }
  if (splc > 1) {
    pswprop (tv->aat, tv->endpos_, 1 + tv->aradius_, 1-tv->aradius_,2.0);
    pswprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    printf (" curveto\n");
    pswprop (tv->aat, tv->endpos_, 1 - tv->aradius_, 1+tv->aradius_,2.0);
    return;
  }
  pswprop (tv->aat, tv->endpos_, tv->aradius_, 1-tv->aradius_, 1.0);
  pswpos (tv->endpos_);
  printf (" curveto\n");
}

/* node is always <> nil */
void
psdraw (primitive * node) {
  int lsp;
  postype X1, X2;
  primitive *lastseg, *tx;
  double lth, fill;
  int TEMP;

  getlinespec (node, &lsp, &lastseg);
  lth = qenv (node, Xlinethick, node->lthick);	/* printobject(node); */
  switch (node->ptype) {

  case Xbox:
    if (((node->boxfill_ >= 0.0) && (node->boxfill_ <= 1.0))
	  || (node->shadedp != NULL)) {
      psbox (node->aat, node->boxwidth_ / 2,
	     node->boxheight_ / 2, node->boxradius_);
      pssetthick (lth);
      if (lsp != Xinvis) { printf (" gsave\n"); }
      if (node->shadedp == NULL) {
	    printf (" currentrgbcolor");
	    pswfloat (&output, node->boxfill_);
	    printf (" setgray");
        }
      else { pssetcolor (node->shadedp); }
      printf (" fill");
      if (lsp != Xinvis) { printf (" grestore\n"); } else { putchar ('\n'); }
      psdashdot (lsp, node->lparam);
      pssetcolor (node->outlinep);
      psendline (node->outlinep);
      printf (" setrgbcolor");
      printf (" setlineparms\n");
      }
    else if (lsp != Xinvis) {
      psbox (node->aat, node->boxwidth_ / 2,
	     node->boxheight_ / 2, node->boxradius_);
      pssetthick (lth);
      psdashdot (lsp, node->lparam);
      pssetcolor (node->outlinep);
      psendline (node->outlinep);
      printf (" setlineparms\n");
      }
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xblock:
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xellipse:
  case Xcircle:
    if (node->ptype == Xellipse) { fill = node->ellipsefill_; }
    else { fill = node->circlefill_; }
    if (((fill >= 0.0) && (fill <= 1.0)) || (node->shadedp != NULL)) {
      pssetthick (lth);
      printf (" gsave ");
      pswpos (node->aat);
      printf (" translate\n");
      if (node->ptype == Xellipse) {
	    psellipse (node->ellipsewidth_, node->ellipseheight_); }
      else { pscircle (node->circleradius_); }
      printf (" gsave ");
      if (node->shadedp == NULL) {
	    pswfloat (&output, fill);
	    printf (" setgray"); }
      else {
	    wstring (&output, node->shadedp);
	    printf (" setrgbcolor");
        }
      printf (" fill grestore\n");
      if (lsp != Xinvis) {
	    psdashdot (lsp, node->lparam);
	    pssetcolor (node->outlinep);
	    psendline (node->outlinep);
	    printf (" setlineparms\n");
        }
      printf (" grestore\n");
      }
    else if (lsp != Xinvis) {
      pssetthick (lth);
      printf (" gsave ");
      pswpos (node->aat);
      printf (" translate\n");
      if (node->ptype == Xellipse) {
	    psellipse (node->ellipsewidth_, node->ellipseheight_); }
      else { pscircle (node->circleradius_); }
      psdashdot (lsp, node->lparam);
      pssetcolor (node->outlinep);
      psendline (node->outlinep);
      printf (" setlineparms\n");
      printf (" grestore\n");
      }
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xline:
  case Xarrow:
  case Xspline:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill) {
	    psnewpath ();
	    if (node->ptype != Xspline) {
	      pswpos (node->aat);
	      printf (" moveto\n");
	      }
	    spltot = primdepth (node);
	    splcount = spltot;
	    tx = node;
	    while (tx != NULL) {
	      if (node->ptype == Xspline) {
	        pssplinesegment (tx, splcount, spltot);
	        splcount--; }
          else {
	        pswpos (tx->endpos_);
	        printf (" lineto\n");
	        }
	      tx = tx->son;
	      }
	    pssetthick (0.0);
	    pslinearfill (fillfrac, shadestr);
	    fillfrac = -1.0;
	    shadestr = NULL;
        }
      if (lsp != Xinvis) {
	    lth = qenv (lastseg, Xlinethick, lastseg->lthick);
	    spltot = primdepth (node);
	    splcount = spltot;
	    pssetthick (lth);
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      pssetcolor (outlinestr);
	      psahead (ahnum (lastseg->lineatype_), &node->aat, node->endpos_,
		    qenv (lastseg, Xarrowht, lastseg->lineheight_),
		    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth);
	      if (outlinestr != NULL) { printf (" setrgbcolor\n"); }
	      }
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      pssetcolor (outlinestr);
	      psahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
		    lastseg->aat, qenv (lastseg, Xarrowht, lastseg->lineheight_),
		    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth);
	      if (outlinestr != NULL) { printf (" setrgbcolor\n"); }
	      }
	    if (node->ptype != Xspline) {
	      psnewpath ();
	      pswpos (node->aat);
	      printf (" moveto\n");
	      }
        }
      }
    if (lsp != Xinvis) {
      if (node->ptype == Xspline) { pssplinesegment (node, splcount, spltot);}
      else {
	    pswpos (node->endpos_);
	    printf (" lineto\n");
        }
      if (node->son == NULL) {
	    psdashdot (lsp, node->lparam);
	    pssetcolor (outlinestr);
	    psendline (outlinestr);
        }
      }
    splcount--;
    if (node->son == NULL) {
      while (snode != NULL) {
	    if (snode->textp != NULL) {
	      pswtext (node, snode->textp,
		    0.5 * (snode->endpos_.xpos + snode->aat.xpos),
		    0.5 * (snode->endpos_.ypos + snode->aat.ypos));
	      }
	    snode = snode->son;
        }
      }
    break;

  case Xmove:
    if (firstsegment (node)) { snode = node; }
    if (node->son == NULL) {
      while (snode != NULL) {
	    if (snode->textp != NULL) {
	      pswtext (node, snode->textp,
		    0.5 * (snode->endpos_.xpos + snode->aat.xpos),
		    0.5 * (snode->endpos_.ypos + snode->aat.ypos));
	      }
	    snode = snode->son;
        }
      }
    break;

  case Xarc:
    if (drawn (node, lsp, node->linefill_)) {
      pssetthick (lth);
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      X1 = arcstart (node);
      X2 = arcend (node);
      if (hasfill) {
	    printf (" currentrgbcolor\n");
	    psnewpath ();
	    pswarc (node->aat, X1, X2, 0.0, node->arcangle_);
	    pssetthick (0.0);
	    pslinearfill (fillfrac, shadestr);
	    fillfrac = -1.0;
	    shadestr = NULL;
	    printf (" setrgbcolor\n");
        }
      if (lsp != Xinvis) {
	    pssetthick (lth);
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      pssetcolor (outlinestr);
	      psarcahead (node->aat, ahnum (node->lineatype_), &X1,
          qenv(node, Xarrowht, node->lineheight_),
          qenv(node, Xarrowwid, node->linewidth_),
		      lth, fabs(node->aradius_), node->arcangle_);
          node->startangle_ =
            datan(X1.ypos - node->aat.ypos,X1.xpos - node->aat.xpos);
	      if (outlinestr != NULL) { printf (" setrgbcolor\n"); }
	      }
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      pssetcolor (outlinestr);
	      psarcahead (node->aat, ahnum (node->lineatype_), &X2,
          qenv(node, Xarrowht, node->lineheight_),
          qenv(node, Xarrowwid, node->linewidth_),
		      lth, -fabs (node->aradius_), node->arcangle_);
          setangles(&node->startangle_, &node->arcangle_,
            node->aat, X1.xpos, X1.ypos, X2.xpos, X2.ypos);
	      if (outlinestr != NULL) { printf (" setrgbcolor\n"); }
	      }
	    psnewpath ();
	    pswarc (node->aat, X1, X2, 0.0, node->arcangle_);
	    psdashdot (lsp, node->lparam);
	    pssetcolor (outlinestr);
	    psendline (outlinestr);
        }
      printf (" setlineparms\n");
      }
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xstring:
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
      }
    else if (node->lthick >= 0.0) { pssetthick (node->lthick); }
    break;
  }
}				/* psdraw */
