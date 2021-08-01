/* Output routines for xfig */

void
xfigprelude (void) {
  printf ("#FIG 3.2\n");
  printf ("Landscape\n");
  printf ("Center\n");
  printf ("Inches\n");
  printf ("Letter\n");
  printf ("100.00\n");
  printf ("Single\n");
  printf ("-2\n");
  printf ("# dpic version %s option -x for Fig 3.2\n",VERSIONDATE);
  printf ("%ld 2\n", (long) xfigres);

}

void
wfigpt (double x) {
  printf (" %ld", (long) floor (((x / fsc) * xfigres) + 0.5));
}

void
wfigcoord (double x, double y) {
  wfigpt (x);
  wfigpt (xfheight - y);
}

void
xfarrowline (int atype, double wid, double ht, double lth) {
  if (ahnum (atype) == 0) { printf ("%c0 0 ", tabch); }
  else { printf ("%c1 1 ", tabch); }
  wfloat (&output, lth * xdispres / pointd);
  putchar (' ');
  wfloat (&output, wid * xfigres);
  putchar (' ');
  wfloat (&output, ht * xfigres);
  putchar ('\n');
}

int
linstyle (int i) {
  if (i == Xsolid) { i = 0; }
  else if (i == Xdashed) { i = 1; }
  else if (i == Xdotted) { i = 2; }
  else { i = -1; }
  return i;
}

void
hdrline (int object_code, int sub_type, int line_style, double lth, double gfill) {	/* first 10 values object_code .. style_val */
  printf ("%d %d %d ", object_code, sub_type, linstyle (line_style));

  if (line_style == Xinvis) { printf ("0 "); }
  else { printf ("%ld ", (long) floor ((lth * xdispres / pointd) + 0.5)); }
  printf ("0 -1 0 -1 ");	/* pencolor, fillcolor, depth, penstyle */
  if (gfill == (-1.0)) { printf ("-1 "); } /* area fill */
  else { printf ("%ld ", (long) floor (((1.0 - gfill) * 20) + 0.5)); }

  /* style_val */
  if (line_style == Xdashed) { wfloat (&output, 5.0 * xdispres / pointd); }
  else if (line_style == Xdotted) { wfloat (&output, 3.0*xdispres / pointd); }
  else { putchar ('0'); }
  putchar (' ');
}

int
fwdarrow (int i) {
  if ((ahlex (i) == Xrighthead) | (ahlex (i) == Xdoublehead)) { return 1; }
  else { return 0; }
}

int
bckarrow (int i) {
  if ((ahlex (i) == Xlefthead) | (ahlex (i) == Xdoublehead)) { return 1; }
  else { return 0; }
}

void
polyline (int object_code, int sub_type, int line_style, double lth,
	  double gfill, double lrad, int atype, double lwid, double lht,
	  int npoints) {
  hdrline (object_code, sub_type, line_style, lth, gfill);
  if (object_code == 3) {
    printf ("0 ");		/* cap_style = butt for splines */
    /* join_style = miter, cap_style = butt, radius */
    }
  else { printf ("0 0 %ld ", (long) floor ((lrad * xdispres) + 0.5)); }
  printf ("%d %d %d\n", fwdarrow (atype), bckarrow (atype), npoints);
  if (fwdarrow (atype) == 1) { xfarrowline (atype, lwid, lht, lth); }
  if (bckarrow (atype) == 1) { xfarrowline (atype, lwid, lht, lth); }
}

void
xfigwrtext (primitive * np, nametype * tp, double bxht, double bxwid,
	    double x, double y) {
  double ydisp;
  int istr, nstr, figjust, i;
  boolean A, B, L, R;
  nametype *p;
  int FORLIM;

  if (bxht == 0.0) { bxht = venv (np, Xtextht); }
  if (tp != NULL) {
    nstr = 0;
    p = tp;
    do {
      nstr++;
      p = p->nextname;
    } while (p != NULL);
    checkjust (tp, &A, &B, &L, &R);
    istr = 0;
    }
  while (tp != NULL) {
    istr++;
    printf ("4 ");
    if (L) { figjust = 0; }
    else if (R) { figjust = 2; }
    else { figjust = 1; }
    printf ("%d ", figjust);
    printf ("-1 0 -1 ");	/* color, depth, penstyle */
    printf ("0 10 0.0 2");	/* font, font_size, angle, font_flags */
    wfigpt (bxht);
    if (bxwid == 0) { wfigpt (tp->len * bxht * 2 / 3); }
    else { wfigpt (bxwid); }
    if (A) { ydisp = (bxht / 5) + venv (np, Xtextoffset); }
    else if (B) { ydisp = (-bxht) - venv (np, Xtextoffset); }
    else { ydisp = bxht / (-3); }
    wfigcoord (x, y + ydisp + ((((nstr + 1.0) / 2) - istr) * bxht));
    putchar (' ');
    FORLIM = tp->len;
    for (i = 0; i < FORLIM; i++) {
      if (tp->segmnt[tp->seginx + i] == bslch) { putchar (bslch); }
      putchar (tp->segmnt[tp->seginx + i]);
      }
    printf ("\\001\n");
    tp = tp->nextname;
  }
}

void
xfarc (int object_code, int sub_type, int line_style, double lth, double gfill,
      int atype, double radius, double strtang, double arcang, double x,
      double y, double lwid, double lht) {
  hdrline (object_code, sub_type, line_style, lth, gfill);
  printf ("0 ");
  if (arcang < 0.0) { printf ("0 "); }
  else { printf ("1 "); }
  printf ("%d %d ", fwdarrow (atype), bckarrow (atype));
  wfigcoord (x, y);
  wfigcoord (x + (radius * cos (strtang)), y + (radius * sin (strtang)));
  wfigcoord (x + (radius * cos (strtang + (arcang / 2))),
	     y + (radius * sin (strtang + (arcang / 2))));
  wfigcoord (x + (radius * cos (strtang + arcang)),
	     y + (radius * sin (strtang + arcang)));
  putchar ('\n');
  if (fwdarrow (atype) == 1) { xfarrowline (atype, lwid, lht, lth); }
  if (bckarrow (atype) == 1) { xfarrowline (atype, lwid, lht, lth); }
}

void
fellipse (int object_code, int sub_type, int line_style, double lth,
	  double gfill, double center_x, double center_y, double radius_x,
	  double radius_y) {
  hdrline (object_code, sub_type, line_style, lth, gfill);
  printf ("1 0.0");
  wfigcoord (center_x, center_y);
  wfigpt (radius_x);
  wfigpt (radius_y);
  wfigcoord (center_x + radius_x, center_y);
  wfigcoord (center_x + radius_x, center_y);
  putchar ('\n');
}

boolean
rdrawn (primitive * np) {
  boolean rv = false;
  boolean v;

  while ((rv == false) && (np != NULL)) {
    if (np->ptype == Xbox) {
      v = drawn (np, lspec (np->spec), np->boxfill_); }
    else if (np->ptype == Xcircle) {
      v = drawn (np, lspec (np->spec), np->circlefill_); }
    else if (np->ptype == Xellipse) {
      v = drawn (np, lspec (np->spec), np->ellipsefill_); }
    else if ((np->ptype == Xspline) || (np->ptype == Xarrow) ||
	       (np->ptype == Xline) || (np->ptype == Xarc)) {
      v = drawn (np, lspec (np->spec), np->linefill_); }
    else { v = false; }
    if (v || (np->textp != NULL)) {
      rv = true;
      break;
    }
    if (rdrawn (np->son)) { rv = true; }
    else { np = np->nextname; }
  }
  return rv;
}

void
xfigdraw (primitive * node) {
  int i, lsp;
  double fill;
  primitive *lastseg;
  int FORLIM;

  getlinespec (node, &lsp, &lastseg);
  if (ismdistmax(node->lthick)) { node->lthick = venv(node,Xlinethick); }
  else { node->lthick = fabs(node->lthick); }
  switch (node->ptype) {
  case Xarc:
    if (drawn (node, lsp, node->linefill_)) {
      xfarc (5, 1, lsp, node->lthick, node->linefill_,
	    node->lineatype_, node->aradius_, node->startangle_, node->arcangle_,
	    node->aat.xpos, node->aat.ypos, node->linewidth_, node->lineheight_);
    }
    xfigwrtext (node, node->textp, 0.0, 0.0, node->aat.xpos, node->aat.ypos);
    break;

  case Xline:
  case Xarrow:
  case Xspline:
    if (firstsegment(node)) {
	  isdrawn = drawn(node, lsp, node->linefill_); }
    if (isdrawn) {
      if (firstsegment (node)) {
	    spltot = primdepth (node);
	    if (node->ptype == Xspline) {
	      polyline (3, 0, lsp, node->lthick, node->linefill_, 0.0,
		    node->lineatype_, node->linewidth_,
		    node->lineheight_, spltot + 1);
	      }
        else { polyline (2, 1, lsp, node->lthick, node->linefill_, 0.0,
		    node->lineatype_, node->linewidth_,
		    node->lineheight_, spltot + 1);
	      }
	    putchar (tabch);
	    wfigcoord (node->aat.xpos, node->aat.ypos);
        }
      wfigcoord (node->endpos_.xpos, node->endpos_.ypos);
      if ((node->son == NULL) && (node->ptype == Xspline)) {
	    printf ("\n%c 0.0", tabch);
	    FORLIM = spltot;
	    for (i = 2; i <= FORLIM; i++) { printf (" 1.0"); }
	    printf (" 0.0\n");
        }
      else if (node->son == NULL) { putchar ('\n'); }
      }
    xfigwrtext (node, node->textp, 0.0, 0.0,
		0.5 * (node->endpos_.xpos + node->aat.xpos),
		0.5 * (node->aat.ypos + node->endpos_.ypos));
    break;

  case Xbox:
  case Xblock:
    initnesw ();
    nesw (node);
    if ((node->ptype == Xblock) &
        ((node->textp != NULL) | drawn(node,lsp,-1.0) | rdrawn(node->son))) {
      node->direction = -1;
      printf ("6 ");
      wfigcoord (west, north);
      wfigcoord (east, south);
      putchar ('\n');
      }
    if (node->ptype == Xblock) { fill = -1.0; }
    else { fill = node->boxfill_; }
    if (drawn (node, lsp, fill)) {
      polyline (2, 2, lsp, node->lthick, fill, 0.0, -1, 0.0, 0.0, 6);
      putchar (tabch);
      wfigcoord (west, (south + north) / 2);
      wfigcoord (west, south);
      wfigcoord (east, south);
      wfigcoord (east, north);
      wfigcoord (west, north);
      wfigcoord (west, (south + north) / 2);
      putchar ('\n');
      }
    xfigwrtext (node, node->textp, 0.0, 0.0, node->aat.xpos, node->aat.ypos);
    break;

  case Xmove:
    xfigwrtext (node, node->textp, 0.0, 0.0,
		0.5 * (node->endpos_.xpos + node->aat.xpos),
		0.5 * (node->aat.ypos + node->endpos_.ypos));
    break;

  case Xellipse:
    if (drawn (node, lsp, node->ellipsefill_)) {
      fellipse (1, 1, lsp, node->lthick, node->ellipsefill_,
		node->aat.xpos, node->aat.ypos,
		0.5 * node->ellipsewidth_, 0.5 * node->ellipseheight_);
      }
    xfigwrtext (node, node->textp, 0.0, 0.0, node->aat.xpos, node->aat.ypos);
    break;

  case Xcircle:
    if (drawn (node, lsp, node->circlefill_)) {
      fellipse (1, 3, lsp, node->lthick, node->circlefill_,
		node->aat.xpos, node->aat.ypos, node->circleradius_,
		node->circleradius_);
      }
    xfigwrtext (node, node->textp, 0.0, 0.0, node->aat.xpos, node->aat.ypos);
    break;

  case Xstring:
    xfigwrtext (node, node->textp, node->boxheight_,
		node->boxwidth_, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
      }
    break;
  }
}				/* xfigdraw */
