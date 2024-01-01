/* Output routines for SVG */

void
svgprelude (double n, double s, double e, double w, double lth) {
  double hsize, vsize;

  gslinethick = 0.8;

  printf ("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
  printf ("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
  printf ("\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
  printf
    ("<!-- Creator: dpic version %s option -v for SVG 1.1 -->\n",VERSIONDATE);
  hsize = (e - w + (2 * lth)) / fsc;
  vsize = (n - s + (2 * lth)) / fsc;
  printf ("<!-- width=\"%d\" height=\"%d\" -->\n",
	  Ceil (hsize + 0.5), Ceil (vsize + 0.5));
  printf ("<svg\n");
  printf (" xmlns=\"http://www.w3.org/2000/svg\"");
  printf (" xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
  printf (" xml:space=\"preserve\"\n");
  printf (" style=\"shape-rendering:geometricPrecision;");
  printf (" text-rendering:geometricPrecision;\n");
  printf (" image-rendering:optimizeQuality;");
  printf (" fill-rule:evenodd; clip-rule:evenodd\"\n");
  printf (" width=\"");
  wfloat (&output, hsize);
  printf ("px\"");
  printf (" height=\"");
  wfloat (&output, vsize);
  printf ("px\"\n");
  printf (" viewBox=\"0 0 ");
  wfloat (&output, hsize);
  putchar (' ');
  wfloat (&output, vsize);
  printf ("\"\n");
  printf (" font-size=\"");
  wfloat (&output, DFONT);
  printf ("pt\" text-anchor=\"middle\"\n");
  printf (" stroke=\"black\"");
  printf (" stroke-miterlimit=\"10\"");
  printf (" stroke-width=\"");
  wfloat (&output, (0.8 / 72) * dpPPI);
  printf ("\" fill=\"none\">\n");
  printf ("<g>\n");
}

void
svgpostlude (void) {
  printf ("</g></svg>\n");
}

/* output substrings */
void
space (void) {
  putchar (' ');
}

void
quote (void) {
  putchar ('"');
}

void
svgsetstroke (double lth) {
  if (lth == gslinethick) { return; }
  printf (" stroke-width=\"");
  wfloat (&output, (lth / 72) * dpPPI);
  printf ("\"\n");
}

void
svgsoutline (nametype * so) {
  printf (" stroke=\"");
  wstring (&output, so);
  printf ("\"\n");
}

void
fillgray (double fll) {
  printf (" fill=\"");
  if (fll == 0.0) { printf ("black"); }
  else if (fll == 0.25) { printf ("darkgray"); }
  else if (fll == 0.5) { printf ("gray"); }
  else if (fll == 0.75) { printf ("lightgray"); }
  else if (fll == 1.0) { printf ("white"); }
  else {
    printf ("rgb(");
    fprintf (output, "%ld", (long) floor ((fll * 255) + 0.5));
    putchar (',');
    fprintf (output, "%ld", (long) floor ((fll * 255) + 0.5));
    putchar (',');
    fprintf (output, "%ld", (long) floor ((fll * 255) + 0.5));
    putchar (')');
  }
  printf ("\"\n");
}

void
svglineoptions (primitive * node, int lnspec) {
  double param,fact,thk;

  if (node->lthick >= 0.0) { svgsetstroke(node->lthick); }
  if (node->ptype == Xblock) { lnspec = Xinvis; }
  if ((outlinestr != NULL) && (lnspec != Xinvis)) { svgsoutline(outlinestr); }
  switch (lnspec) {

  case Xdashed:
    param = qenv (node, Xdashwid, node->lparam) / fsc;
    printf (" stroke-dasharray=\"");
    wfloat (&output, param * 7 / 6);
    putchar (',');
    wfloat (&output, param * 5 / 6);
    printf ("\"\n");
    break;

  case Xdotted:
    if (!ismdistmax(node->lparam)) { param = node->lparam; }
    else {
	  if (node->lthick >= 0) { thk = node->lthick; }
	  else { thk = qenv(node, Xlinethick, node->lthick); }
	  if (thk >= 2) { fact = 2.5; }
	  else if (thk < 1) { fact = 5.0; }
	  else { fact = 7.5 - (thk * 2.5); }
	  param = (thk / 72) * scale * fact;
      }
    printf (" stroke-linecap=\"round\"");
    printf (" stroke-dasharray=\"0.5,");
    wfloat (&output, param / fsc);
    printf ("\"\n");
    break;

  case Xinvis:
    printf (" stroke=\"none\"\n");
    break;
  }
}

void
svgfilloptions (primitive * node, double fill, nametype * sh, int lnspec,
		boolean poly) {
  fill = ((long) floor ((fill * 1000000L) + 0.5)) / 1000000.0;
  switch (node->ptype) {
  case Xbox:
  case Xblock:
    printf ("<rect");
    break;
  case Xellipse:
    printf ("<ellipse");
    break;
  case Xcircle:
    printf ("<circle");
    break;
  case Xspline:
    printf ("<path");
    break;
  case Xline:
  case Xarrow:
    if (poly) { printf ("<polyline"); }
    else { printf ("<line"); }
    break;
  case Xarc:
    printf ("<path");
    break;
  }
  if (sh != NULL) {
    printf (" fill=\"");
    wstring (&output, sh);
    putchar ('"'); }
  else if ((fill >= 0.0) && (fill <= 1.0)) { fillgray (fill); }
  else if (node->ptype == Xstring) { fillgray (0.0); }
  svglineoptions (node, lnspec);
}

void
svgendpath (void) {
  printf (" />\n");
}

void
svgparam (char * p, double x) {
  printf (" %s=\"", p);
  wfloat (&output, x / fsc);
  quote ();
}

void
svgcoord (char * s1, char * s2, double x, double y) {
  svgparam (s1, x);
  svgparam (s2, xfheight - y);
}

void
svgwpos (postype p) {
  wfloat (&output, p.xpos / fsc);
  putchar (',');
  wfloat (&output, (xfheight - p.ypos) / fsc);
}

void
svgwprop (postype p1, postype p2, double a, double b, double c) {
  pprop (p1, &p2, a, b, c);
  svgwpos (p2);
}

void
svgwstring (nametype * p) {
  int i;
  Char c;
  boolean waswhite = false;
  boolean iswhite;
  int FORLIM;

  if (p == NULL) { return; }
  if (p->segmnt == NULL) { return; }
  FORLIM = p->len;
  for (i = 0; i < FORLIM; i++) {
    c = p->segmnt[p->seginx + i];
    iswhite = ((c == etxch) || (c == nlch) || (c == tabch) || (c == ' '));
    if ((!iswhite) || (!waswhite)) { putchar (c); }
    waswhite = iswhite;
  }
}

void
svgwtext (primitive * node, nametype * tp, double x, double y) {
  int nstr = 0;
  nametype *tx;
  boolean L, R, A, B;
  double v, lineskip, xheight, dx, dy;

  if ((tp == NULL) || (node == NULL)) { return; }
  tx = tp;
  while (tx != NULL) {
    nstr++;
    tx = tx->nextname;
  }
  v = nstr - 1 + dptextratio;
  if ((node->ptype == Xstring) && (nstr > 0) && (v != 0)) {
    lineskip = node->boxheight_ / v; }
  else { lineskip = venv (node, Xtextht) / dptextratio; }
  xheight = lineskip * dptextratio;
  y += (v * lineskip / 2) - xheight;	/* string bottom */
  do {
    printf ("<text font-size=\"");
    wfloat (&output, (lineskip / scale) * 72);
    printf ("pt\"");
    if (node->ptype != Xstring) {
      printf (" stroke-width=\"0.2pt\" fill=\"black\""); }
    else {
      if (node->lthick < 0) { svgsetstroke (0.2); }
      svgfilloptions (node, node->boxfill_, node->shadedp,
		      lspec (node->spec), false);
      }
    v = venv (node, Xtextoffset);
    checkjust (tp, &A, &B, &L, &R);
    if (node->ptype == Xstring) { dx = node->boxradius_; }
    else { dx = 0.0; }
    if (L) {
	  printf(" text-anchor=\"start\"\n");
	  if (node->ptype != Xstring) { dx = v; }
      }
    else if (R) {
	  printf(" text-anchor=\"end\"\n");
	  if (node->ptype != Xstring) { dx = -v; }
      }
    dy = 0.0;
    if (node->ptype != Xstring) {
      if (A) { dy = (xheight / 2) + v; }
      else if (B) { dy = (xheight / (-2)) - v; }
      }
    svgcoord ("x", "y", Max (0.0, x + dx), Max (0.0, y + dy));
    if (tp->len > 40) { putchar ('\n'); }
    putchar ('>');
    svgwstring (tp);
    printf ("</text>\n");
    y -= lineskip;
    tp = tp->nextname;
  } while (tp != NULL);
}

void
svgwarc (postype E, double r, double angle, double ccw) {
  printf (" A ");
  wfloat (&output, fabs (r) / fsc);
  space ();
  wfloat (&output, fabs (r) / fsc);
  printf (" 0 ");
  if (fabs (angle) > pi) { putchar ('1'); }
  else { putchar ('0'); }
  if (ccw > 0) { printf (" 0 "); }
  else { printf (" 1 "); }
  svgwpos (E);
  if (angle == 0) { putchar ('\n'); }
}

void
svgarcahead (postype C, int atyp, postype * point, nametype * sou, double ht,
	     double wid, double lth, double radius, double angle) {
  postype P, Q, Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi;
  boolean startarrow;

  arcahead (C, *point, atyp, ht, wid, lth, radius, angle, &P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  /* Trace arrowhead outline */
  printf ("<path stroke-width=\"0\"");
  if (sou != NULL) {
    svgsoutline (sou);
    printf (" fill=\"");
    wstring (&output, sou);
    printf ("\"\n"); }
  else { printf (" fill=\"black\"\n"); }
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    printf (" d=\"M ");
    svgwpos (Px);
    putchar ('\n');
    Q = Ci;
    pprop (Ai, &Q, radius + lwi, -lwi, radius);
    svgwarc (Q, radius + lwi, 0.0, ccw);
    printf (" L ");
    svgwpos (Ai);
    putchar ('\n');
    svgwarc (*point, radius, 0.0, -ccw);
    svgwarc (Ao, radius, 0.0, ccw);
    printf (" L ");
    svgwprop (Ao, Co, radius - lwi, lwi, radius);
    putchar ('\n');
    svgwarc (Px, radius - lwi, 1.0, -ccw); }
  else if (atyp == 3) {
    printf (" d=\"M ");
    svgwpos (Px);
    putchar ('\n');
    svgwarc (Ai, radius, 0.0, ccw);
    svgwarc (*point, radius, 0.0, -ccw);
    svgwarc (Ao, radius, 0.0, ccw);
    svgwarc (Px, radius, 1.0, -ccw); }
  else {
    Q.xpos = (Ao.xpos + Ai.xpos) / 2;
    Q.ypos = (Ao.ypos + Ai.ypos) / 2;
    printf (" d=\"M ");
    svgwpos (Q);
    printf ("\n L ");
    svgwpos (Ai);
    putchar ('\n');
    svgwarc (*point, radius, 0.0, -ccw);
    svgwarc (Ao, radius, 0.0, ccw);
    printf (" L ");
    svgwpos (Q);
    }
  quote ();
  svgendpath ();
  *point = P;
}

void
svgahead (int atyp, postype * point, postype shaft, nametype * sou, double ht,
	  double wid, double lth, double fill) {
  postype P, L, R, Px, Lx, Rx, Q;
  double x, y;

  dahead (*point, shaft, ht, wid, (lth / 72) * scale, &P, &L, &R, &Px, &Lx,
	  &Rx, &Q, &x, &y);
  if (atyp == 0) {
    printf ("<polyline");
    if (lth > 0.0) { svgsetstroke (lth); }
    if (sou != NULL) { svgsoutline (sou); }
    printf (" points=\"");
    svgwprop (P, L, x - y, y, x);
    space ();
    svgwpos (P);
    putchar ('\n');
    svgwprop (P, R, x - y, y, x); }
  else if (atyp == 3) {
    printf ("<polygon stroke-width=\"0\"");
    if (sou != NULL) {
      svgsoutline (sou);
      printf (" fill=\"");
      wstring (&output, sou);
      printf ("\"\n"); }
    else if ((fill >= 0.0) && (fill <= 1.0)) { fillgray (fill); }
    else { printf (" fill=\"black\"\n"); }
    printf (" points=\"");
    svgwpos (Px);
    space ();
    svgwpos (Lx);
    putchar ('\n');
    svgwpos (*point);
    space ();
    svgwpos (Rx); }
  else {
    printf ("<polygon stroke-width=\"0\"");
    if (sou != NULL) {
      svgsoutline (sou);
      printf (" fill=\"");
      wstring (&output, sou);
      printf ("\"\n"); }
    else if ((fill >= 0.0) && (fill <= 1.0)) { fillgray (fill); }
    else { printf (" fill=\"black\"\n"); }
    printf (" points=\"");
    svgwpos (Lx);
    space ();
    svgwpos (*point);
    putchar ('\n');
    svgwpos (Rx);
    }
  quote ();
  svgendpath ();
  *point = P;
}

void
svgsplinesegment (primitive * tv, int splc, int splt) {
  if (tv == NULL) {
    return;
  }
  if (splt == 1) {
    printf ("<line x1=\"");
    wfloat (&output, tv->aat.xpos / fsc);
    printf ("\" y1=\"");
    wfloat (&output, tv->aat.ypos / fsc);
    printf ("\" x2=\"");
    wfloat (&output, tv->endpos_.xpos / fsc);
    printf ("\" y2=\"");
    wfloat (&output, tv->endpos_.ypos / fsc);
    svgendpath ();
    return;
  }
  if (ismdistmax (tv->aradius_)) {
    if (splc == splt) {		/* 1st seg */
      printf (" d=\"M ");
      svgwpos (tv->aat);
      printf ("\n C ");
      svgwprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
      space ();
      svgwprop (tv->aat, tv->endpos_, 2.0, 1.0, 3.0);
      space ();
      svgwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      space ();
      svgwprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
      putchar ('\n');
      return;
      }
    if (splc > 1) {		/* interior segment */
      svgwprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
      space ();
      svgwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      space ();
      svgwprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
      putchar ('\n');
      return;
      }
    svgwprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
    space ();
    svgwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    space ();
    svgwprop (tv->aat, tv->endpos_, 1.0, 2.0, 3.0);
    space ();
    svgwprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
    putchar ('\n');
    svgwpos (tv->endpos_);
    quote ();
    svgendpath ();
    /* last segment */
    return;
  }
  if ((splc == splt) && (splc > 1)) {
    printf (" d=\"M ");
    svgwpos (tv->aat);
    printf ("\n C ");
    svgwprop (tv->aat, tv->endpos_, 1 - tv->aradius_, tv->aradius_, 1.0);
    space ();
    return;
    }
  if (splc > 1) {
    svgwprop (tv->aat, tv->endpos_, 0.5 + (tv->aradius_ / 2),
	      0.5 - (tv->aradius_ / 2), 1.0);
    space ();
    svgwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    space ();
    svgwprop (tv->aat, tv->endpos_, 0.5 - (tv->aradius_ / 2),
	      0.5 + (tv->aradius_ / 2), 1.0);
    space ();
    return;
    }
  svgwprop (tv->aat, tv->endpos_, tv->aradius_, 1 - tv->aradius_, 1.0);
  space ();
  svgwpos (tv->endpos_);
  quote ();
  svgendpath ();
}

/* node is always <> nil */
void
svgdraw (primitive * node) {
  int lsp;
  postype X1, X2;
  primitive *lastseg, *tx, *primp;
  double lth;
  int TEMP;
  getlinespec (node, &lsp, &lastseg);
  shadestr = node->shadedp;
  outlinestr = node->outlinep;
  lth = qenv (node, Xlinethick, node->lthick);	/* printobject(node); */
  switch (node->ptype) {

  case Xbox:
    initnesw ();
    nesw (node);
    if (drawn (node, lsp, node->boxfill_)) {
      svgfilloptions (node, node->boxfill_, node->shadedp, lsp,
		      false);
      svgcoord ("x", "y",
		node->aat.xpos - (fabs (node->boxwidth_) / 2),
		node->aat.ypos + (fabs (node->boxheight_) / 2));
      if (node->boxradius_ > 0.0) {
	svgparam ("rx", node->boxradius_);
	svgparam ("ry", node->boxradius_);
      }
      svgparam ("width", fabs (node->boxwidth_));
      svgparam ("height", fabs (node->boxheight_));
      svgendpath ();
      }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xblock:
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xellipse:
    if (drawn (node, lsp, node->ellipsefill_)) {
      svgfilloptions (node, node->ellipsefill_, node->shadedp, lsp,
		      false);
      svgcoord ("cx", "cy", node->aat.xpos, node->aat.ypos);
      svgparam ("rx", 0.5 * fabs (node->ellipsewidth_));
      svgparam ("ry", 0.5 * fabs (node->ellipseheight_));
      svgendpath ();
      }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xcircle:
    if (drawn (node, lsp, node->circlefill_)) {
      svgfilloptions (node, node->circlefill_, node->shadedp, lsp,
		      false);
      svgcoord ("cx", "cy", node->aat.xpos, node->aat.ypos);
      svgparam ("r", fabs (node->circleradius_));
      svgendpath ();
      }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xline:
  case Xarrow:
  case Xmove:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill) {
    	printf ("<polyline stroke-width=\"0\"");
    	if (outlinestr != NULL) { svgsoutline (outlinestr); }
    	if ((fillfrac >= 0) && (fillfrac <= 1)) { fillgray (fillfrac); }
        else {
    	  printf (" fill=\"");
    	  wstring (&output, shadestr);
    	  printf ("\"\n");
    	  }
    	printf (" points=\"");
    	svgwpos (node->aat);
    	tx = node;
    	while (tx != NULL) {
    	  putchar ('\n');
    	  svgwpos (tx->endpos_);
    	  tx = tx->son;
    	  }
    	printf ("\" />\n");
    	fillfrac = -1.0;
    	shadestr = NULL;
        }
      if (lsp != Xinvis) {
    	lth = qenv (lastseg, Xlinethick, lastseg->lthick);
    	TEMP = ahlex (lastseg->lineatype_);
    	if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
    	  svgahead (ahnum (lastseg->lineatype_), &node->aat,
    		    node->endpos_, outlinestr,
    		    qenv (lastseg, Xarrowht, lastseg->lineheight_),
    		    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth, fillfrac);
    	  }
    	TEMP = ahlex (lastseg->lineatype_);
    	if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
    	  svgahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
    		    lastseg->aat, outlinestr,
    		    qenv (lastseg, Xarrowht, lastseg->lineheight_),
    		    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth, fillfrac);
    	  }
    	if (node->son == NULL) {
    	  svgfilloptions (lastseg, fillfrac, shadestr, lsp, false);
    	  svgcoord ("x1", "y1", node->aat.xpos, node->aat.ypos);
    	  svgcoord ("x2", "y2", node->endpos_.xpos,
    		    node->endpos_.ypos);
    	  svgendpath (); }
        else {
    	  svgfilloptions (lastseg, fillfrac, shadestr, lsp, true);
    	  printf (" points=\"");
    	  svgwpos (node->aat);
    	  space (); }
        } }
      else if (lsp != Xinvis) {
        svgwpos (node->aat);
        putchar ('\n');
        if (node->son == NULL) {
	      svgwpos (node->endpos_);
	      quote ();
	      svgendpath ();
          }
        }
    if (node->son == NULL) {
      while (snode != NULL) {
	    primp = snode;
	    if (primp->textp != NULL) {
	      svgwtext (node, primp->textp,
		    0.5 * (primp->endpos_.xpos + primp->aat.xpos),
		    0.5 * (primp->aat.ypos + primp->endpos_.ypos));
	        }
	    snode = snode->son;
        }
      }
    break;

  case Xspline:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      node->lthick = lastseg->lthick;
      node->lparam = lastseg->lparam;
      if (hasfill) {
	    printf ("<path stroke-width=\"0\"");
	    if (outlinestr != NULL) { svgsoutline (outlinestr); }
	    if ((fillfrac >= 0) && (fillfrac <= 1)) { fillgray (fillfrac); }
        else {
	      printf (" fill=\"");
	      wstring (&output, shadestr);
	      printf ("\"\n");
	      }
	    spltot = primdepth (node);
	    splcount = spltot;
	    tx = node;
	    while (tx != NULL) {
	      svgsplinesegment (tx, splcount, spltot);
	      splcount--;
	      tx = tx->son;
	      }
	    fillfrac = -1.0;
	    shadestr = NULL; }
      if (lsp != Xinvis) {
	    lth = qenv (lastseg, Xlinethick, lastseg->lthick);
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      svgahead (ahnum (lastseg->lineatype_), &node->aat,
		    node->endpos_, outlinestr,
		    qenv (lastseg, Xarrowht, lastseg->lineheight_),
		    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth,
		    node->linefill_); }
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      svgahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
		    lastseg->aat, outlinestr,
		    qenv (lastseg, Xarrowht, lastseg->lineheight_),
		    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth,
		    node->linefill_); }
	    spltot = primdepth (node);
	    splcount = spltot;
	    svgfilloptions (node, fillfrac, shadestr, lsp, false);
        }
      }
    if (lsp != Xinvis) { svgsplinesegment (node, splcount, spltot); }
    splcount--;
    break;

  case Xarc:
    X1 = arcstart (node);
    X2 = arcend (node);
    getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
    if (hasfill) {
      printf ("<path stroke-width=\"0\"");
      if ((fillfrac >= 0) && (fillfrac <= 1)) { fillgray (fillfrac); }
      else {
	    printf (" fill=\"");
	    wstring (&output, shadestr);
	    printf ("\"\n"); }
      printf (" d=\"M ");
      svgwpos (X1);
      putchar ('\n');
      svgwarc (X2, node->aradius_, node->arcangle_, node->arcangle_);
      quote ();
      svgendpath ();
      fillfrac = -1.0;
      shadestr = NULL;
      }
    if (lsp != Xinvis) {
      lth = qenv (lastseg, Xlinethick, lastseg->lthick);
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
        svgarcahead(node->aat, ahnum(node->lineatype_), &X1, outlinestr,
          qenv(node, Xarrowht, node->lineheight_),
          qenv(node, Xarrowwid, node->linewidth_), lth,
          fabs(node->aradius_),node->arcangle_);
        node->startangle_ =
          datan(X1.ypos - node->aat.ypos,X1.xpos - node->aat.xpos);
        }
      TEMP = ahlex(node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
        svgarcahead(node->aat, ahnum(node->lineatype_), &X2, outlinestr,
          qenv(node, Xarrowht, node->lineheight_),
          qenv(node, Xarrowwid, node->linewidth_), lth,
          -fabs(node->aradius_),node->arcangle_);
        setangles(&node->startangle_, &node->arcangle_,
          node->aat, X1.xpos, X1.ypos, X2.xpos, X2.ypos);
        }
      printf ("<path");
      svglineoptions (node, lsp);
      printf (" d=\"M ");
      svgwpos (X1);
      putchar ('\n');
      svgwarc (X2, node->aradius_, node->arcangle_, node->arcangle_);
      quote ();
      svgendpath ();
      }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xstring:
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n'); }
    break;
  }
}				/* svgdraw */
