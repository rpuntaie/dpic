/* Output routines for PSTricks */
void
pstprelude (double n, double s, double e, double w) {
  printf ("\\psset{unit=1in,cornersize=absolute,dimen=middle}%%\n");
  printf ("\\begin{pspicture}");
  wcoord (&output, w, s);
  wcoord (&output, e, n);
  printf ("%%\n");
  printf
    ("%% dpic version %s option -p for PSTricks 0.93a or later\n",VERSIONDATE);
}

void
pstpostlude (void) {
  printf ("\\end{pspicture}%%\n");
}

void
pstwrtext (primitive * np, nametype * tp, double x, double y) {
  boolean A, B, L, R;

  if (tp == NULL) { return; }
  if (tp->nextname != NULL) {
    printf ("\\rput");
    wcoord (&output, x, y);
    putchar ('{');
    texstacktext (np, tp);
    printf ("}\n");
    return;
    }
  checkjust (tp, &A, &B, &L, &R);
  if (A || B || L || R) {
    printf ("\\uput{");
    wfloat (&output, (venv (np, Xtextoffset) / scale) * 72);
    printf ("bp}[");
    if (B) { putchar ('d'); }
    else if (A) { putchar ('u'); }
    if (L) { putchar ('r'); }
    else if (R) { putchar ('l'); }
    putchar (']'); }
  else { printf ("\\rput"); }
  wcoord (&output, x, y);
  putchar ('{');
  wstring (&output, tp);
  printf ("}\n");
}

void
pstlineoptions (primitive * node, int lsp, Char sep) {
  if (node->lthick >= 0.0) {
    printf ("%clinewidth=", sep);
    wfloat (&output, node->lthick);
    printf ("pt");
    sep = ',';
    }
  if (node->outlinep != NULL) {
    printf ("%clinecolor=", sep);
    wstring (&output, node->outlinep);
    sep = ',';
    }
  if (node->ptype == Xblock) { lsp = Xinvis; }
  if ((lsp == Xinvis) || (lsp == Xdotted) || (lsp == Xdashed)) {
    printf ("%c%%\n", sep);
    printf ("linestyle=");
    switch (lsp) {
    case Xdashed:
      printf ("dashed");
      if (node->lparam >= 0) {
	    printf (",dash=");
	    wfloat (&output, node->lparam / fsc);
	    putchar (' ');
	    wfloat (&output, node->lparam / fsc);
        }
      break;

    case Xdotted:
      printf ("dotted");
      if (node->lparam >= 0) {
	    printf (",dotsep=");
	    wfloat (&output, node->lparam / fsc);
        }
      break;

    case Xinvis:
      printf ("none");
      break;
    }
    sep = ',';
    }
  if ((node->ptype == Xspline) || (node->ptype == Xline) ||
      (node->ptype == Xarrow)) {
    if ((ahlex (node->lineatype_) != XEMPTY) &&
	  (ahnum (node->lineatype_) != 0) && (ahnum (node->lineatype_) != 3)) {
      printf ("%c%%\n", sep);
      printf ("arrowsize=");
      wfloat (&output, node->linewidth_ / scale);
      printf ("in 0,arrowlength=");
      if (node->linewidth_ == 0.0) { wfloat (&output, 0.0); }
      else { wfloat (&output, node->lineheight_ / node->linewidth_); }
      printf (",arrowinset=0");
      sep = ',';
      }
    }
  if (sep == ',') { putchar (']'); }
}

void
pstfilloptions (primitive * node, int lsp, double a) {
  Char sep;
  double fill = -1.0;

  switch (node->ptype) {

  case Xblock:
    /* blank case */
    break;

  case Xbox:
    fill = node->boxfill_;
    break;

  case Xcircle:
    fill = node->circlefill_;
    break;

  case Xellipse:
    fill = node->ellipsefill_;
    break;

  case Xarc:
  case Xline:
  case Xarrow:
  case Xmove:
  case Xspline:
    fill = node->linefill_;
    break;
  }
  fill = ((long) floor ((fill * 1000000L) + 0.5)) / 1000000.0;
  if ((fill > 0.0) && (fill < 1.0) && (fill != lastfillval) &&
      (fill != 0.25) && (fill != 0.5) && (fill != 0.75)) {
    lastfillval = fill;
    printf ("\\newgray{fillval}");
    wbrace (fill);
    putchar ('\n');
    }
  switch (node->ptype) {

  case Xbox:
  case Xblock:
    printf ("\\psframe");
    break;

  case Xellipse:
    printf ("\\psellipse");
    break;

  case Xcircle:
    printf ("\\pscircle");
    break;

  case Xspline:
    printf ("\\psbezier");
    break;

  case Xline:
  case Xarrow:
    printf ("\\psline");
    break;

  case Xarc:
    if (a >= 0.0) { printf ("\\psarc"); }
    else { printf ("\\psarcn"); }
    break;
  }
  if (shadestr != NULL) {
    printf ("[fillstyle=solid,fillcolor=");
    wstring (&output, shadestr);
    sep = ','; }
  else if ((fill >= 0.0) && (fill <= 1.0)) {
    printf ("[fillstyle=solid,fillcolor=");
    if (fill == 0.0) { printf ("black"); }
    else if (fill == 0.25) { printf ("darkgray"); }
    else if (fill == 0.5) { printf ("gray"); }
    else if (fill == 0.75) { printf ("lightgray"); }
    else if (fill == 1.0) { printf ("white"); }
    else { printf ("fillval"); }
    sep = ','; }
  else { sep = '['; }
  if (node->ptype == Xbox) {
    if (node->boxradius_ != 0.0) {
      printf ("%clinearc=", sep);
      wfloat (&output, node->boxradius_ / fsc);
      sep = ','; }
    }
  pstlineoptions (node, lsp, sep);
}

void
pstahead (postype * point, postype shaft, double ht, double wid, double lth,
	  int typ, nametype * sou) {
  postype P, L, R, Px, Lx, Rx, Q;
  double x, y;

  dahead (*point, shaft, ht, wid, (lth / 72) * scale, &P, &L, &R, &Px, &Lx,
	  &Rx, &Q, &x, &y);
  if (typ == 0) {
    printf ("\\pscustom[linewidth=");
    wfloat (&output, lth);
    printf ("pt,linecolor=");
    if (sou != NULL) { wstring (&output, sou); }
    else { printf ("black"); }
    printf ("]{%%\n");
    printf ("\\psline");
    wprop (P, L, x - y, y, x);
    wpos (P);
    wprop (P, R, x - y, y, x);
    printf ("}\n"); }
  else {
    printf ("\\pscustom[linewidth=0pt,fillstyle=solid,fillcolor=");
    if (sou != NULL) { wstring (&output, sou); }
    else { printf ("black"); }
    printf (",linecolor=");
    if (sou != NULL) { wstring (&output, sou); }
    else { printf ("black"); }
    printf ("]{%%\n");
    printf ("\\psline");
    wpos (Px);
    wpos (Rx);
    wpos (*point);
    wpos (Lx);
    printf ("\\closepath}%%\n");
    }
  *point = P;
}

void
pstwarc(postype Ctr, postype A, postype B, double radjust, double ccw) {
  double radius, startangle, endangle;
  radius = distance(B, Ctr) + radjust;
  startangle = posangle(A, Ctr);
  endangle = posangle(B, Ctr);
  wpos(Ctr);
  if ((ccw > 0) && (endangle < startangle)) { endangle += 2 * pi; }
  else if ((ccw < 0) && (endangle > startangle)) { endangle -= 2 * pi; }
  wbrace(radius / fsc);
  wbrace((180.0 / pi) * startangle);
  wbrace((180.0 / pi) * endangle);
  putchar('\n');
#ifdef DDEBUG
  if (debuglevel > 0) {
  fprintf(log_, " pstwarc:");
  logpos(" C", Ctr);
  fprintf(log_, " radius=");
  wfloat(&log_, radius);
  fprintf(log_, " startangle=");
  wfloat(&log_, startangle * 180 / pi);
  fprintf(log_, " endangle=");
  wfloat(&log_, endangle * 180 / pi);
  fprintf(log_, " ccw=");
  wfloat(&log_, ccw);
  putc('\n', log_);
  }
#endif
}

void
pstarc (double ccw) {
  if (ccw >= 0.0) { printf ("\\psarc"); }
  else { printf ("\\psarcn"); }
}

void
pstarcahead (postype C, postype point, int atyp, nametype * sou, double ht,
	     double wid, double lth, double radius, double arcangle,
	     postype * P) {
  postype Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi;
  boolean startarrow;

  arcahead (C, point, atyp, ht, wid, lth, radius, arcangle, P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  printf ("\\pscustom[linewidth=0pt,fillstyle=solid,fillcolor=");
  if (sou != NULL) { wstring (&output, sou); }
  else { printf ("black"); }
  printf (",linecolor=");
  if (sou != NULL) { wstring (&output, sou); }
  else { printf ("black"); }
  printf ("]{%%\n");
  pstarc (-ccw);
  pstwarc (Ci, Ai, point, 0.0, -ccw);
  pstarc (ccw);
  pstwarc (Co, point, Ao, 0.0, ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    pstarc (-ccw);
    pstwarc (Co, Ao, Px, 0.0, -ccw);
    pstarc (ccw);
    pstwarc (Ci, Px, Ai, lwi, ccw); }
  else if (atyp == 3) {
    pstarc (-ccw);
    pstwarc (Cox, Ao, Px, 0.0, -ccw);
    pstarc (ccw);
    pstwarc (Cix, Px, Ai, 0.0, ccw); }
  printf ("\\closepath}%%\n");
}

void
pstsplinesegment (primitive * tv, int splc, int splt) {
  if (tv != NULL) {
    if (ismdistmax (tv->aradius_)) {
      if ((splc == splt) && (splc > 1)) {	/* 1st seg */
	    wpos (tv->aat);
	    wprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
	    /* 1/6 from 1st to 2nd */
	    wprop (tv->aat, tv->endpos_, 4.0, 2.0, 6.0);
	    /* 1/3 from 1st to 2nd */
	    wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
	    /* 1/2 from 1st to 2nd */
	    /* 5/6 from 1st to 2nd */
	    wprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0); }
      else if (splc > 1) {	/* interior segment */
	    wprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
	    /* 1/6 from 1st to 2nd */
	    wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
	    /* 1/2 from 1st to 2nd */
	    /* 5/6 from 1st to 2nd */
	    wprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0); }
      else {			/* 1/2 along */
	    wprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
	    /* 1/6 along */
	    wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
	    wprop (tv->aat, tv->endpos_, 2.0, 4.0, 6.0);
	    /* 2/3 along */
	    wprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
	    /* 5/6 along */
	    wpos (tv->endpos_);
	    /* last segment */
        }
      }
    else if ((splc == splt) && (splc > 1)) {
      wpos (tv->aat);
      wprop (tv->aat, tv->endpos_, 1 - tv->aradius_, tv->aradius_, 1.0); }
    else if (splc > 1) {
      wprop (tv->aat, tv->endpos_, 1 + tv->aradius_, 1-tv->aradius_,2.0);
      wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      wprop (tv->aat, tv->endpos_, 1-tv->aradius_, 1+tv->aradius_,2.0); }
    else if (splt == 1) {
      wprop (tv->aat, tv->endpos_, tv->aradius_, 1 - tv->aradius_, 1.0);
      wprop (tv->aat, tv->endpos_, 1 - tv->aradius_, tv->aradius_, 1.0);
      wpos (tv->endpos_); }
    else {
      wprop (tv->aat, tv->endpos_, tv->aradius_, 1 - tv->aradius_, 1.0);
      wpos (tv->endpos_);
      }
    }
  putchar ('\n');
}

void
pstdraw (primitive * node) {
  int lsp, ahn;
  postype X0, X1;
  boolean v;
  double s, c, lth;
  primitive *lastseg, *tx;
  nametype *sx;
  int TEMP;

  getlinespec (node, &lsp, &lastseg);
  shadestr = node->shadedp;
  lth = qenv (node, Xlinethick, lastseg->lthick);
  switch (node->ptype) {

  case Xbox:
  case Xblock:
    initnesw ();
    nesw (node);
    if (node->ptype == Xblock) {
      v = drawn (node, lsp, -1.0); }
    else { v = drawn (node, lsp, node->boxfill_); }
    if (v) {
      pstfilloptions (node, lsp, 0.0);
      wcoord (&output, west, south);
      wcoord (&output, east, north);
      putchar ('\n');
      }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xellipse:
    if (drawn (node, lsp, node->ellipsefill_)) {
      pstfilloptions (node, lsp, 0.0);
      wpos (node->aat);
      wcoord (&output, 0.5 * node->ellipsewidth_, 0.5 * node->ellipseheight_);
      putchar ('\n');
      }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xcircle:
    if (drawn (node, lsp, node->circlefill_)) {
      pstfilloptions (node, lsp, 0.0);
      wpos (node->aat);
      putchar ('{');
      wfloat (&output, node->circleradius_ / fsc);
      printf ("}\n");
      }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xarc:
    if (drawn (node, lsp, node->linefill_)) {
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill && (fillfrac >= 0.0)) { node->linefill_ = fillfrac; }
      X0 = arcstart (node);
      X1 = arcend (node);
      if (hasfill) {
	    s = node->lthick;
	    node->lthick = 0.0;
	    pstfilloptions (node, lsp, node->arcangle_);
	    pstwarc(node->aat, X0, X1, 0.0, node->arcangle_);
	    node->lthick = s;
        }
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	    pstarcahead(node->aat, X0, ahnum (node->lineatype_), outlinestr,
		     qenv(node, Xarrowht, node->lineheight_),
		     qenv(node, Xarrowwid, node->linewidth_), lth,
		     fabs(node->aradius_), node->arcangle_, &X0);
        }
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	    pstarcahead(node->aat, X1, ahnum (node->lineatype_), outlinestr,
		     qenv(node, Xarrowht, node->lineheight_),
		     qenv(node, Xarrowwid, node->linewidth_), lth,
		     -fabs(node->aradius_), node->arcangle_, &X1);
        }
      sx = shadestr;
      shadestr = NULL;
      c = node->linefill_;
      node->linefill_ = -1.0;
      pstfilloptions (node, lsp, node->arcangle_);
      shadestr = sx;
      node->linefill_ = c;
      pstwarc (node->aat, X0, X1, 0.0, node->arcangle_);
      }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xline:
  case Xarrow:
    if (firstsegment(node)) {
	  snode = node;
	  isdrawn = drawn(node, lsp, node->linefill_); }
    if (isdrawn) {
      if (firstsegment (node)) {
	    getlinshade (node, &lastseg,&shadestr,&outlinestr,&fillfrac,&hasfill);
	    if (hasfill && (fillfrac >= 0.0)) { node->linefill_ = fillfrac; }
	    if (hasfill) {
	      s = lastseg->lthick;
	      lastseg->lthick = 0.0;
	      pstfilloptions (lastseg, lsp, 0.0);
	      lastseg->lthick = s;
	      wpos (node->aat);
	      tx = node;
	      while (tx != NULL) {
	        wpos (tx->endpos_);
	        putchar ('\n');
	        tx = tx->son;
	        }
	      }
	    ahn = ahnum (lastseg->lineatype_);
	    if ((ahn == 0) || (ahn == 3)) {
	      TEMP = ahlex (lastseg->lineatype_);
	      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	        pstahead (&node->aat, node->endpos_,
		      qenv (node, Xarrowht, lastseg->lineheight_),
		      qenv (node, Xarrowwid, lastseg->linewidth_),
		      qenv (node, Xlinethick, lastseg->lthick),
		      ahnum (lastseg->lineatype_), outlinestr);
	        }
	      TEMP = ahlex (lastseg->lineatype_);
	      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	        pstahead (&lastseg->endpos_, lastseg->aat,
		      qenv (node, Xarrowht, lastseg->lineheight_),
		      qenv (node, Xarrowwid, lastseg->linewidth_),
		      qenv (node, Xlinethick, lastseg->lthick),
		      ahnum (lastseg->lineatype_), outlinestr);
	        }
	      }
	    sx = shadestr;
	    shadestr = NULL;
	    pstfilloptions (lastseg, lsp, 0.0);
	    shadestr = sx;
	    if ((ahn != 0) && (ahn != 3)) {
	      switch (ahlex (lastseg->lineatype_)) {
	      case Xlefthead:
	        printf ("{<-}");
	        break;
	      case Xdoublehead:
	        printf ("{<->}");
	        break;
	      case Xrighthead:
	        printf ("{->}");
	        break;
	      } }
	    hasfill = false;
	    wpos (node->aat);
        }
      wpos (node->endpos_);
      putchar ('\n');
      }
    if (node->son == NULL) {
      while (snode != NULL) {
	    if (snode->textp != NULL) {
	      pstwrtext (snode, snode->textp,
		     0.5 * (snode->endpos_.xpos + snode->aat.xpos),
		     0.5 * (snode->aat.ypos + snode->endpos_.ypos));
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
	      pstwrtext (snode, snode->textp,
		     0.5 * (snode->endpos_.xpos + snode->aat.xpos),
		     0.5 * (snode->aat.ypos + snode->endpos_.ypos));
	      }
	    snode = snode->son;
        }
      }
    break;

  case Xspline:
    if (firstsegment (node)) {	/* first spline */
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill && (fillfrac >= 0.0)) { node->linefill_ = fillfrac; }
      if (hasfill) {
	    s = lastseg->lthick;
	    lastseg->lthick = 0.0;
	    pstfilloptions (lastseg, lsp, 0.0);
	    lastseg->lthick = s;
	    spltot = primdepth (node);
	    splcount = spltot;
	    printf ("%%\n");
	    tx = node;
	    while (tx != NULL) {
	      pstsplinesegment (tx, splcount, spltot);
	      splcount--;
	      tx = tx->son;
	      }
	    hasfill = false;
        }
      spltot = primdepth (node);
      splcount = spltot;
      ahn = ahnum (lastseg->lineatype_);
      if ((ahn == 0) || (ahn == 3)) {
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      pstahead (&lastseg->endpos_, lastseg->aat,
		    qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_),
		    qenv (node, Xlinethick, lastseg->lthick),
		    ahnum (lastseg->lineatype_), outlinestr);
	      }
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      pstahead (&node->aat, node->endpos_,
		    qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_),
		    qenv (node, Xlinethick, lastseg->lthick),
		    ahnum (lastseg->lineatype_), outlinestr);
	      }
        }
      if (lsp != Xinvis) {
	    sx = shadestr;
	    shadestr = NULL;
	    pstfilloptions (lastseg, lsp, 0.0);
	    shadestr = sx;
	    if ((ahn != 0) && (ahn != 3)) {
	      switch (ahlex (lastseg->lineatype_)) {

	      case Xlefthead:
	        printf ("{<-}");
	        break;

	      case Xdoublehead:
	        printf ("{<->}");
	        break;

	      case Xrighthead:
	        printf ("{->}");
	        break;
	      }
	    }
	  printf ("%%\n");
      }
    }
    if (lsp != Xinvis) { pstsplinesegment (node, splcount, spltot); }
    splcount--;
    break;

  case Xstring:
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
      }
    else if (node->lthick >= 0.0) {
      printf ("\\psset{linewidth=");
      wfloat (&output, node->lthick);
      printf ("pt}%%\n");
    }
    break;
  }
}				/* pstdraw */
