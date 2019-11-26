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
  if ((printstate & 1) != 1) {
    return;
  }
  if (drawmode == PS) {
    printf ("/strsiz\n");
    printf (" {newpath 0 0 moveto true charpath flattenpath");
    printf (" pathbbox 4 1 roll pop pop pop}def\n");
    printf ("/setcapht {gsave (I) strsiz /capht exch def grestore} def\n");
    printf
      ("/postext {1 add baselineskip mul 1 sub 2 div capht mul add moveto} def\n");
    printf ("/strwidth { dup stringwidth pop } def\n");
    printf ("/ljust { labelsep } def\n");
    printf ("/rjust { strwidth labelsep add neg } def\n");
    printf ("/cjust { strwidth 2 div neg } def\n");
    printf ("/above { capht 2 div labelsep add } def\n");
    printf ("/below { capht 2 div neg labelsep sub } def\n");
    printf ("/vjust {0 capht baselineskip mul neg rmoveto\n");
    printf (" currentpoint /y exch def /x exch def} def\n");
  } else {
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
  int FORLIM;

  if (p == NULL) {
    return;
  }
  if (p->segmnt == NULL) {
    return;
  }
  FORLIM = p->len;
  for (i = 0; i < FORLIM; i++) {
    c = p->segmnt[p->seginx + i];
    iswhite = ((c == etxch) || (c == nlch) || (c == tabch) || (c == ' '));
    if ((!iswhite) || (!waswhite)) {
      if ((c == bslch) || (c == ')') || (c == '(')) {
	putchar (bslch);
      }
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
      tx = tx->next_;
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
      tp = tp->next_;
    } while (tp != NULL);
    return;
    }
  if (tp == NULL) { return; }
  toff = (venv (np, XLtextoffset) / scale) * 72;
  theight = (venv (np, XLtextht) / scale) * 72;
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
  if (tp->next_ != NULL) { printf ("\\\\shortstack{"); }
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
    tx = tx->next_;
    if (tx != NULL) {
      printf ("\\\\\\\\ ");
      checkjust (tx, &A, &B, &L, &R);
      }
    } while (tx != NULL);
  if (tp->next_ != NULL) { printf ("}})\n"); }
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
  if ((lthk < 0.0) || (lthk == gslinethick)) {
    return;
  }
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
  if (ss == NULL) {
    return;
  }
  printf (" currentrgbcolor");
  putchar (' ');
  wstring (&output, ss);
  printf (" setrgbcolor fill setrgbcolor\n");
}

void
pssetcolor (nametype * op) {
  if (op == NULL) {
    return;
  }
  printf (" currentrgbcolor ");
  wstring (&output, op);
  printf (" setrgbcolor\n");
}

void
psdashdot (int lspec, double param) {
  if (lspec == XLdashed) {
    if (ismdistmax (param)) {
      param = 3 * fsc;
    }
    printf (" [");
    pswfloat (&output, param / fsc);
    pswfloat (&output, param / fsc);
    printf (" ] 0 setdash\n");
    return;
  }
  if (lspec != XLdotted) {
    return;
  }
  if (ismdistmax (param)) {
    param = 5 * fsc;
  }
  printf (" [ 0");
  pswfloat (&output, param / fsc);
  printf (" ] 0 setdash 1 setlinecap\n");
}

void
psendline (nametype * op) {
  printf (" endstroke");
  if (op != NULL) {
    printf (" setrgbcolor\n");
  } else {
    putchar ('\n');
  }
}

void
pswarc (postype C, postype S, postype E, double r, double ccw) {
  double y;

  pswpos (C);
  pswfloat (&output, r / fsc);
  y = datan (S.ypos - C.ypos, S.xpos - C.xpos);
  pswfloat (&output, (180.0 / pi) * y);
  y = datan (E.ypos - C.ypos, E.xpos - C.xpos);
  pswfloat (&output, (180.0 / pi) * y);
  if (ccw >= 0.0) {
    printf (" arc\n");
  } else {
    printf (" arcn\n");
  }
}

void
psarcahead (postype C, int atyp, postype * point, double ht, double wid,
	    double lth, double radius, double angle) {
  postype P, Q, Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi;
  boolean startarrow;

  arcahead (C, *point, atyp, ht, wid, lth, radius, angle, &P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  /* Trace arrowhead outline */
  psnewpath ();
  pswarc (Ci, Ai, *point, radius, -ccw);
  pswarc (Co, *point, Ao, radius, ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    Q = Co;
    pprop (Ao, &Q, radius - lwi, lwi, radius);
    pswpos (Q);
    printf (" lineto\n");
    pswarc (Co, Q, P, radius - lwi, -ccw);
    Q = Ci;
    pprop (Ai, &Q, radius + lwi, -lwi, radius);
    pswarc (Ci, P, Q, radius + lwi, ccw);
  }
  if ((atyp == 3) && (lwi < ((wid - lwi) / 2))) {
    pswarc (Cox, Ao, Px, radius, -ccw);
    pswarc (Cix, Px, Ai, radius, ccw);
  } else {
    pswpos (Ai);
    printf (" lineto\n");
  }
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
    psendline (NULL);
  } else {
    pswpos (Rx);
    printf (" moveto\n");
    pswpos (*point);
    printf (" lineto");
    pswpos (Lx);
    printf (" lineto\n");
    if (atyp == 3) {
      pswpos (Px);
      printf (" lineto\n");
    }
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
      if ((i == 1) || (i == 3)) {
	putchar ('\n');
      }
    }
  } else {
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
  if (tv == NULL) {
    return;
  }
  if (splt == 1) {
    pswpos (tv->aat);
    printf (" moveto");
    pswpos (tv->Upr.Uline.endpos);
    printf (" lineto\n");
    return;
  }
  if (ismdistmax (tv->Upr.Uline.aradius)) {
    if ((splc == splt) && (splc > 1)) {	/* 1st seg */
      pswpos (tv->aat);
      printf (" moveto\n");
      pswprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      printf (" lineto\n");
      pswprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      return;
    }
    if (splc > 1) {		/* interior segment */
      pswprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
      pswprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      printf (" curveto\n");
      pswprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      return;
    }
    pswprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
    pswprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
    printf (" curveto\n");
    pswpos (tv->Upr.Uline.endpos);
    printf (" lineto\n");
    /* last segment */
    return;
  }
  if ((splc == splt) && (splc > 1)) {
    pswpos (tv->aat);
    printf (" moveto\n");
    pswprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	     tv->Upr.Uline.aradius, 1.0);
    return;
  }
  if (splc > 1) {
    pswprop (tv->aat, tv->Upr.Uline.endpos, 1 + tv->Upr.Uline.aradius,
	     1 - tv->Upr.Uline.aradius, 2.0);
    pswprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
    printf (" curveto\n");
    pswprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	     1 + tv->Upr.Uline.aradius, 2.0);
    return;
  }
  pswprop (tv->aat, tv->Upr.Uline.endpos, tv->Upr.Uline.aradius,
	   1 - tv->Upr.Uline.aradius, 1.0);
  pswpos (tv->Upr.Uline.endpos);
  printf (" curveto\n");
}

/* node is always <> nil */
void
psdraw (primitive * node) {
  int lsp;
  postype X1, X2;
  primitive *tn, *tx;
  double h, w, lth, fill;
  int TEMP;
  primitive *With1;

  getlinespec (node, &lsp, &tn);
  lth = qenv (node, XLlinethick, node->lthick);	/* printobject(node); */
  switch (node->ptype) {

  case XLbox:
    if (((node->Upr.Ubox.boxfill >= 0.0) && (node->Upr.Ubox.boxfill <= 1.0))
	|| (node->shadedp != NULL)) {
      psbox (node->aat, node->Upr.Ubox.boxwidth / 2,
	     node->Upr.Ubox.boxheight / 2, node->Upr.Ubox.boxradius);
      pssetthick (lth);
      if (lsp != XLinvis) { printf (" gsave\n"); }
      if (node->shadedp == NULL) {
	    printf (" currentrgbcolor");
	    pswfloat (&output, node->Upr.Ubox.boxfill);
	    printf (" setgray");
        }
      else { pssetcolor (node->shadedp); }
      printf (" fill");
      if (lsp != XLinvis) { printf (" grestore\n"); } else { putchar ('\n'); }
      psdashdot (lsp, node->lparam);
      pssetcolor (node->outlinep);
      psendline (node->outlinep);
      printf (" setrgbcolor");
      printf (" setlineparms\n");
      }
    else if (lsp != XLinvis) {
      psbox (node->aat, node->Upr.Ubox.boxwidth / 2,
	     node->Upr.Ubox.boxheight / 2, node->Upr.Ubox.boxradius);
      pssetthick (lth);
      psdashdot (lsp, node->lparam);
      pssetcolor (node->outlinep);
      psendline (node->outlinep);
      printf (" setlineparms\n");
      }
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XBLOCK:
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLellipse:
  case XLcircle:
    if (node->ptype == XLellipse) { fill = node->Upr.Uellipse.efill; }
    else { fill = node->Upr.Ucircle.cfill; }
    if (((fill >= 0.0) && (fill <= 1.0)) || (node->shadedp != NULL)) {
      pssetthick (lth);
      printf (" gsave ");
      pswpos (node->aat);
      printf (" translate\n");
      if (node->ptype == XLellipse) {
	    psellipse (node->Upr.Uellipse.elwidth, node->Upr.Uellipse.elheight); }
      else { pscircle (node->Upr.Ucircle.radius); }
      printf (" gsave ");
      if (node->shadedp == NULL) {
	    pswfloat (&output, fill);
	    printf (" setgray"); }
      else {
	    wstring (&output, node->shadedp);
	    printf (" setrgbcolor");
        }
      printf (" fill grestore\n");
      if (lsp != XLinvis) {
	    psdashdot (lsp, node->lparam);
	    pssetcolor (node->outlinep);
	    psendline (node->outlinep);
	    printf (" setlineparms\n");
        }
      printf (" grestore\n");
      }
    else if (lsp != XLinvis) {
      pssetthick (lth);
      printf (" gsave ");
      pswpos (node->aat);
      printf (" translate\n");
      if (node->ptype == XLellipse) {
	    psellipse (node->Upr.Uellipse.elwidth, node->Upr.Uellipse.elheight); }
      else { pscircle (node->Upr.Ucircle.radius); }
      psdashdot (lsp, node->lparam);
      pssetcolor (node->outlinep);
      psendline (node->outlinep);
      printf (" setlineparms\n");
      printf (" grestore\n");
      }
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLline:
  case XLarrow:
  case XLspline:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill) {
	    psnewpath ();
	    if (node->ptype != XLspline) {
	      pswpos (node->aat);
	      printf (" moveto\n");
	      }
	    spltot = primdepth (node);
	    splcount = spltot;
	    tx = node;
	    while (tx != NULL) {
	      if (node->ptype == XLspline) {
	        pssplinesegment (tx, splcount, spltot);
	        splcount--; }
          else {
	        pswpos (tx->Upr.Uline.endpos);
	        printf (" lineto\n");
	        }
	      tx = tx->son;
	      }
	    pssetthick (0.0);
	    pslinearfill (vfill, sshade);
	    vfill = -1.0;
	    sshade = NULL;
        }
      if (lsp != XLinvis) {
	    lth = qenv (tn, XLlinethick, tn->lthick);
	    spltot = primdepth (node);
	    splcount = spltot;
	    pssetthick (lth);
	    TEMP = ahlex (tn->Upr.Uline.atype);
	    if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	      pssetcolor (soutline);
	      psahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos,
		    qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth);
	      if (soutline != NULL) { printf (" setrgbcolor\n"); }
	      }
	    TEMP = ahlex (tn->Upr.Uline.atype);
	    if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	      pssetcolor (soutline);
	      psahead (ahnum (tn->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth);
	      if (soutline != NULL) { printf (" setrgbcolor\n"); }
	      }
	    if (node->ptype != XLspline) {
	      psnewpath ();
	      pswpos (node->aat);
	      printf (" moveto\n");
	      }
        }
      }
    if (lsp != XLinvis) {
      if (node->ptype == XLspline) { pssplinesegment (node, splcount, spltot);}
      else {
	    pswpos (node->Upr.Uline.endpos);
	    printf (" lineto\n");
        }
      if (node->son == NULL) {
	    psdashdot (lsp, node->lparam);
	    pssetcolor (soutline);
	    psendline (soutline);
        }
      }
    splcount--;
    if (node->son == NULL) {
      while (snode != NULL) {
	    With1 = snode;
	    if (With1->textp != NULL) {
	      pswtext (node, With1->textp,
		    0.5 * (With1->Upr.Uline.endpos.xpos + With1->aat.xpos),
		    0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	      }
	    snode = snode->son;
        }
      }
    break;

  case XLmove:
    if (firstsegment (node)) { snode = node; }
    if (node->son == NULL) {
      while (snode != NULL) {
	    With1 = snode;
	    if (With1->textp != NULL) {
	      pswtext (node, With1->textp,
		    0.5 * (With1->Upr.Uline.endpos.xpos + With1->aat.xpos),
		    0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	      }
	    snode = snode->son;
        }
      }
    break;

  case XLarc:
    if (drawn (node, lsp, node->Upr.Uline.lfill)) {
      pssetthick (lth);
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      X1 = arcstart (node);
      X2 = arcend (node);
      if (bfill) {
	    printf (" currentrgbcolor\n");
	    psnewpath ();
	    pswarc (node->aat, X1, X2, node->Upr.Uline.aradius,
		    node->Upr.Uline.endpos.ypos);
	    pssetthick (0.0);
	    pslinearfill (vfill, sshade);
	    vfill = -1.0;
	    sshade = NULL;
	    printf (" setrgbcolor\n");
        }
      if (lsp != XLinvis) {
	    pssetthick (lth);
	    TEMP = ahlex (node->Upr.Uline.atype);
	    if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	      pssetcolor (soutline);
	      startarc (node, X1, lth, &h, &w);
	      psarcahead (node->aat, ahnum (node->Upr.Uline.atype), &X1, h, w,
		      lth, fabs (node->Upr.Uline.aradius),
		      node->Upr.Uline.endpos.ypos);
	      if (soutline != NULL) { printf (" setrgbcolor\n"); }
	      }
	    TEMP = ahlex (node->Upr.Uline.atype);
	    if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	      pssetcolor (soutline);
	      endarc (node, X2, lth, &h, &w);
	      psarcahead (node->aat, ahnum (node->Upr.Uline.atype), &X2, h, w,
		      lth, -fabs (node->Upr.Uline.aradius),
		      node->Upr.Uline.endpos.ypos);
	      if (soutline != NULL) { printf (" setrgbcolor\n"); }
	      }
	    psnewpath ();
	    pswarc (node->aat, X1, X2, node->Upr.Uline.aradius,
		    node->Upr.Uline.endpos.ypos);
	    psdashdot (lsp, node->lparam);
	    pssetcolor (soutline);
	    psendline (soutline);
        }
      printf (" setlineparms\n");
      }
    pswtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLstring:
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
