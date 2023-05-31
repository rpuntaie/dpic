/* Output routines for TeX, tTeX (eepicemu), Pict2e */

void
texprelude (double n, double s, double e, double w) {
  printf ("\\setlength{\\unitlength}{1in}\n");
  if (!isdistmax (s)) {
    printf ("\\begin{picture}");
    wcoord (&output, e - w, n - s);
    wcoord (&output, w, s);
    printf ("\n\\thicklines\n");
  }
  printf ("%% dpic version %s option ",VERSIONDATE);
  switch (drawmode) {

  case TeX:
    printf ("(none, LaTeX picture assumed)");
    break;

  case Pict2e:
    printf ("-e (Pict2e)");
    break;

  case tTeX:
    printf ("-t (eepicemu)");
    break;
  }
  printf (" for LaTeX\n");
}

void
texpostlude (void) {
  printf ("\\end{picture}%%\n");
}

/* Test angle near 0 or pi/2 */
boolean
iscorner (double theta) {
  return ((fabs (theta) < 0.001)
	  || (fabs ((0.5 * pi) - fabs (theta)) < 0.001));
}

/* Highest common factor of abs(x), abs(y) */
int
hcf (int x, int y) {
  int i;
  if (x < 0) { x = -x; }
  if (y < 0) { y = -y; }
  if (y > x) {
    i = y;
    y = x;
    x = i;
    }
  while (y > 0) {
    i = y;
    y = x - ((x / y) * y);
    x = i;
    }
  if (x == 0) { return 1; }
  else { return x; }
}

void
wrslope (double xp, double yp, boolean arrow) {
  int i, ix, iy;
  double r;

  if ((xp == 0.0) && (yp == 0.0)) {
    xp = 1.0;
    yp = 0.0;
    }
  r = linlen (xp, yp);
  if (drawmode == Pict2e) { i = 1000; }
  else if (drawmode == tTeX) { i = 453; }
  else if (arrow) { i = 4; }
  else { i = 6; }
  iy = (long) floor (((i + 0.49999) * yp / r) + 0.5);
  ix = (long) floor (((i + 0.49999) * xp / r) + 0.5);
  i = hcf (ix, iy);
  iy /= i;
  ix /= i;
  printf ("(%d,%d)", ix, iy);
  if (ix == 0) { wbrace (fabs (yp) / fsc); }
  else { wbrace (fabs (xp) / fsc); }
}

void
arrowhead (double pointx, double pointy, double tailx, double taily) {
  double x, y, r, ct;

  r = linlen (pointx - tailx, pointy - taily);
  if (r == 0.0) { return; }
  ct = Min (0.05, 0.5 * r) / r;
  x = pointx + (ct * (tailx - pointx));
  y = pointy + (ct * (taily - pointy));
  printf ("\n\\put");
  wcoord (&output, x, y);
  printf ("{\\vector");
  wrslope (pointx - x, pointy - y, true);
  putchar ('}');
}

void
texwrtext (primitive * np, nametype * tp, double x, double y) {
  boolean A, B, L, R;
  if (tp == NULL) { return; }
  printf ("\\put");
  checkjust (tp, &A, &B, &L, &R);
  if (A) { wcoord (&output, x, y + 0.1); }
  else if (B) { wcoord (&output, x, y - 0.05); }
  else { wcoord (&output, x, y); }
  checkjust (tp, &A, &B, &L, &R);
  putchar ('{');
  printf ("\\makebox(0,0)");
  if (L) { printf ("[l]"); }
  else if (R) { printf ("[r]"); }
  putchar ('{');
  texstacktext (np, tp);
  printf ("}}\n");
}

void
p2ahead (postype * point, postype shaft, double ht) {
  postype butx;
  /* affang contains direction cosines */
  butx = affine (ht, 0.0, *point, affang (shaft, *point));
  printf ("\\put");
  wpos (butx);
  printf ("{\\vector");
  wrslope (point->xpos - butx.xpos, point->ypos - butx.ypos, true);
  printf ("}\n");
  *point = butx;
}

void
p2setthick (double lt) {
  if (ismdistmax(lt)) { return; }
  if (lt < 0.0) { lt = -lt; }
  if (lt == gslinethick) { return; }
  printf ("\\linethickness{");
  wfloat (&output, lt);
  printf ("pt}\n");
  gslinethick = lt;
}

void
texdraw (primitive * node) {
  int i, npts, lsp;
  double r, x, y, x1, y1, ct, st, lgth, lth;
  primitive *lastseg, *p;
  postype tmpat, X0, X3;
  int TEMP;

  getlinespec (node, &lsp, &lastseg);
  lth = qenv (node, Xlinethick, node->lthick);
  switch (node->ptype) {

  case Xbox:
  case Xblock:
    if (drawn (node, lsp, -1.0) || (node->textp != NULL)) {
      initnesw ();
      nesw (node);
      if (drawmode == Pict2e) { p2setthick (lth); }
      printf ("\\put");
      wcoord (&output, west, south);
      if (node->ptype == Xblock) { printf ("{\\makebox"); }
      else if (lsp == Xsolid) { printf ("{\\framebox"); }
      else if (lsp == Xinvis) { printf ("{\\makebox"); }
      else if (lsp == Xdashed) {
        printf ("{\\dashbox");
	    if (!ismdistmax (node->lparam)) { wbrace (node->lparam / fsc); }
        else { wbrace (venv (node, Xdashwid) / fsc); }
        }
      else if (lsp == Xdotted) {
	    printf ("{\\dashbox");
	    printf ("{0.01}");
        }
      if (node->ptype == Xbox) {
	    wcoord (&output, node->boxwidth_, node->boxheight_); }
      else {
	    wcoord (&output, node->blockwidth_, node->blockheight_); }
      putchar ('{');
      texstacktext (node, node->textp);
      printf ("}}\n");
      }
    break;

  case Xline:
  case Xarrow:
    if (firstsegment(node)) { isdrawn = drawn(node, lsp, -1.0); }
    if (isdrawn) {
      if (firstsegment (node)) {	/* first segment */
	    if (drawmode == Pict2e) { p2setthick (lth); }
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      p2ahead (&node->aat, node->endpos_,
		   qenv (node, Xarrowht, lastseg->lineheight_)); }
        }
      TEMP = ahlex (node->lineatype_);
      if ((node->son == NULL) & ((TEMP == Xdoublehead) ||
		 (TEMP == Xrighthead))) {
	    p2ahead (&node->endpos_, node->aat,
		 qenv (node, Xarrowht, lastseg->lineheight_)); }
         lgth = distance(node->endpos_,node->aat);
      if ((drawmode == Pict2e) ||
	    ((lsp == Xsolid) && ((lgth > 0.18) || (drawmode == tTeX)))) {
	    if (lgth > 0) {
	      printf ("\\put");
	      wpos (node->aat);
	      printf ("{\\line");
	      wrslope (node->endpos_.xpos - node->aat.xpos,
		   node->endpos_.ypos - node->aat.ypos, false);
	      printf ("}\n");
	      }
        }
      else if (lsp == Xsolid) {
	    npts = (long) floor ((lgth / 0.005) + 0.5);
	    if (npts == 0) { npts = 1; }
	    printf ("\\multiput");
	    wpos (node->aat);
	    wcoord (&output,
		  (node->endpos_.xpos - node->aat.xpos) / npts,
		  (node->endpos_.ypos - node->aat.ypos) / npts);
	    printf ("{%d}", npts + 1);
	    printf ("{\\makebox(0.005555,0.00825){\\tiny .}}\n"); }
      else if (lsp == Xdashed) {
	    printf ("\\put");
	    wpos (node->aat);
	    printf ("{\\dashline[50]");
	    if (!ismdistmax (node->lparam)) { wbrace (node->lparam / fsc); }
        else { wbrace (venv (node, Xdashwid) / fsc); }
	    printf ("(0,0)");
	    wcoord (&output, node->endpos_.xpos - node->aat.xpos,
		  node->endpos_.ypos - node->aat.ypos);
	    printf ("}\n"); }
      else if (lsp == Xdotted) {
	    printf ("\\dottedline{");
	    wfloat (&output, 0.05 / fsc);
	    putchar ('}');
	    wpos (node->aat);
	    wpos (node->endpos_);
	    putchar ('\n');
        }
      }
    texwrtext (node, node->textp,
	  0.5 * (node->endpos_.xpos + node->aat.xpos),
	  0.5 * (node->aat.ypos + node->endpos_.ypos));
    break;

  case Xspline:
    if ((drawmode == Pict2e) & drawn (node, lsp, -1.0)) {
      if (firstsegment (node)) {	/* first spline */
	    spltot = primdepth (node);
	    splcount = spltot;
	    tmpat = node->aat;
	    p2setthick (lth);
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      p2ahead (&node->aat, node->endpos_,
		   qenv (node, Xarrowht, lastseg->lineheight_));
	      }
	    if ((spltot > 1) & ismdistmax (node->aradius_)) {
	      printf ("\\put");
	      wcoord (&output, node->aat.xpos, node->aat.ypos);
	      printf ("{\\line");
	      wrslope ((node->endpos_.xpos - node->aat.xpos) / 2,
		   (node->endpos_.ypos - node->aat.ypos) / 2, false);
	      printf ("}\n");
	      printf ("\\cbezier");
	      wprop (node->endpos_, node->aat, 1.0, 1.0, 2.0);
	      wprop (node->aat, node->endpos_, 1.0, 5.0, 6.0);
	      }
        else if (spltot > 1) {
	      printf ("\\cbezier");
	      wpos (node->aat);
	      node->aat = tmpat;
	      wprop (node->aat, node->endpos_,
		    1 - node->aradius_, node->aradius_, 1.0);
	      }
        }
      else if ((splcount > 1) & ismdistmax (node->aradius_)) {
	    wprop (node->aat, node->endpos_, 5.0, 1.0, 6.0);
	    wprop (node->aat, node->endpos_, 1.0, 1.0, 2.0);
	    printf ("%%\n");
	    printf ("\\cbezier");
	    wprop (node->aat, node->endpos_, 1.0, 1.0, 2.0);
	    wprop (node->aat, node->endpos_, 1.0, 5.0, 6.0); }
      else if (splcount > 1) {
	    wprop (node->aat, node->endpos_,
	       0.5 + (node->aradius_ / 2),
	       0.5 - (node->aradius_ / 2), 1.0);
	    wprop (node->aat, node->endpos_, 1.0, 1.0, 2.0);
	    printf ("%%\n");
	    printf ("\\cbezier");
	    wprop (node->aat, node->endpos_, 1.0, 1.0, 2.0);
	    wprop (node->aat, node->endpos_,
	       0.5 - (node->aradius_ / 2),
	       0.5 + (node->aradius_ / 2), 1.0);
        }
      if (splcount == 1) {
	    tmpat = node->endpos_;
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      /* x = linlen (node->endpos_.xpos - node->aat.xpos,
		      node->endpos_.ypos - node->aat.ypos); */
          x = distance(node->endpos_,node->aat);
	      y = qenv (node, Xarrowht, lastseg->lineheight_);
	      pprop (node->aat, &node->endpos_, y, x - y, x);
	      }
	    if ((spltot > 1) & ismdistmax (node->aradius_)) {
	      wprop (node->aat, node->endpos_, 5.0, 1.0, 6.0);
	      wprop (node->aat, node->endpos_, 1.0, 1.0, 2.0);
	      printf ("%%\n");
	      printf ("\\put");
	      wprop (node->aat, node->endpos_, 1.0, 1.0, 2.0);
	      printf ("{\\line");
	      wrslope ((node->endpos_.xpos - node->aat.xpos) / 2,
		   (node->endpos_.ypos - node->aat.ypos) / 2, false);
	      printf ("}\n"); }
        else if (spltot > 1) {
	      wprop (node->aat, node->endpos_, node->aradius_,
		     1 - node->aradius_, 1.0);
	      wpos (node->endpos_);
	      printf ("%%\n");
	      }
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      p2ahead (&tmpat, node->aat,
		   qenv (node, Xarrowht, lastseg->lineheight_)); }
        }
      splcount--; }
    else if ((lsp == Xdotted) || (lsp == Xdashed) || (lsp == Xsolid)) {
      if (firstsegment (node) & ((ahlex (node->lineatype_) == Xdoublehead) |
        (ahlex (node->lineatype_) == Xlefthead))) {	/* first spline */
	    arrowhead (node->aat.xpos, node->aat.ypos,
		   node->endpos_.xpos, node->endpos_.ypos); }
      printf ("\\spline");
      wpos (node->aat);
      wpos (node->endpos_);
      if (node->son == NULL) { putchar ('\n'); }
      else if (node->son->son == NULL) {
	    wpos (node->son->endpos_);
	    if ((ahlex (node->lineatype_) == Xrighthead) |
	        (ahlex (node->lineatype_) == Xdoublehead)) {
	      arrowhead (node->son->endpos_.xpos,
		     node->son->endpos_.ypos, node->son->aat.xpos,
		     node->son->aat.ypos); }
	    node->ptype = Xline;
	    putchar ('\n');
	    deletetree (&node->son); }
      else {
	    pprop (node->son->endpos_, &node->son->aat, 1.0, 1.0, 2.0);
	    wpos (node->son->aat);
	    node->ptype = Xline;
	    putchar ('\n'); }
      }
    break;

  case Xmove:
    texwrtext (node, node->textp,
	       0.5 * (node->endpos_.xpos + node->aat.xpos),
	       0.5 * (node->aat.ypos + node->endpos_.ypos));
    break;

  case Xellipse:
    if (drawmode == Pict2e) { p2setthick (lth); }
    printf ("\\put");
    wpos (node->aat);
    if (drawmode == TeX) {
      printf ("{\\ellipse");
      wbrace (node->ellipsewidth_ / fsc);
      wbrace (node->ellipseheight_ / fsc);
      printf ("}\n"); }
    else {
      printf ("{\\oval");
      wcoord (&output, node->ellipsewidth_, node->ellipseheight_);
      printf ("}\n"); }
    texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xcircle:
    if (lsp != Xinvis) {
      if (drawmode == Pict2e) { p2setthick (lth); }
      printf ("\\put");
      wpos (node->aat);
      printf ("{\\circle");
      wbrace (2.0 * node->circleradius_ / fsc);
      printf ("}\n"); }
    texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xarc:
    if ((drawmode == Pict2e) & drawn (node, lsp, -1.0)) {
      p2setthick (node->lthick);	/* p2linecap(lsp); */
      X0 = arcstart (node);
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	    if (node->aradius_ == 0.0) { x = 0.0; }
        else {
	      x = atan(qenv (node, Xarrowht, node->lineheight_) /node->aradius_); }
	    if (node->arcangle_ >= 0.0) {
	      node->startangle_ += x;
	      node->arcangle_ -= x; }
        else {
	      node->startangle_ -= x;
	      node->arcangle_ += x; }
	    tmpat = X0;
	    X0 = arcstart (node);
	    p2ahead (&tmpat, X0, qenv (node, Xarrowht, node->lineheight_));
        }
      X3 = arcend (node);
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	    if (node->aradius_ == 0.0) { x = 0.0; }
        else {
          x = atan(qenv (node, Xarrowht, node->lineheight_)/node->aradius_); }
	    if (node->arcangle_ >= 0.0) { node->arcangle_ -= x; }
        else { node->arcangle_ += x; }
	    tmpat = X3;
	    X3 = arcend (node);
	    p2ahead (&tmpat, X3, qenv (node, Xarrowht, node->lineheight_)); }
      npts = (long) (1.0 + (fabs (node->arcangle_) / pi));
      node->arcangle_ /= npts;
      while (npts > 0) {
	    printf ("\\cbezier");
	    wpos (X0);
	    x = cos (node->arcangle_ / 2);
	    y = sin (node->arcangle_ / 2);
	    x1 = (4 - x) / 3;
	    if (y != 0.0) { y1 = (1.0 - (x * x1)) / y; }
        else { y1 = 0.0; }
	    tmpat.xpos = cos (node->startangle_ + (node->arcangle_ / 2.0));
	    tmpat.ypos = sin (node->startangle_ + (node->arcangle_ / 2.0));
	    wpos(affine (node->aradius_ * x1,-node->aradius_*y1,node->aat, tmpat));
	    wpos(affine (node->aradius_ * x1, node->aradius_*y1,node->aat, tmpat));
	    if (npts > 1) {
	      node->startangle_ += node->arcangle_;
	      X0 = arcstart (node);
	      wpos (X0);
	      printf ("%%\n"); }
	    npts--;
        }
      wpos (X3);
      printf ("%%\n"); }
    else if (iscorner (principal (node->startangle_, 0.5 * pi)) &&
	       (fabs (fabs (node->arcangle_) - (pi / 2.0)) < 0.001)) {
      if (drawmode == Pict2e) { p2setthick (lth); }
      printf ("\\put");
      wpos (node->aat);
      printf ("{\\oval");
      wcoord (&output, 2 * node->aradius_ / fsc, 2 * node->aradius_ / fsc);
      if ((node->direction != Xdown) && (node->direction != Xup) &&
	  (node->direction != Xright) && (node->direction != Xleft)) {
	    p = findenv (node);
	    if (p != NULL) { node->direction = p->direction; }
        }
      if (((node->direction == Xleft) && (node->arcangle_ < 0.0)) ||
	    ((node->direction == Xdown) && (node->arcangle_ > 0.0))) {
	    printf ("[bl]}\n"); }
      else if (((node->direction == Xleft) && (node->arcangle_ > 0.0)) ||
		((node->direction == Xup) && (node->arcangle_ < 0.0))) {
	    printf ("[tl]}\n"); }
      else if (((node->direction == Xright) && (node->arcangle_ < 0.0)) ||
		((node->direction == Xup) && (node->arcangle_ > 0.0))) {
	    printf ("[tr]}\n"); }
      else { printf ("[br]}\n"); }
      texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      }
    else if (((drawmode == TeX) || (drawmode == Pict2e)) &&
	       (node->aradius_ > 0.0)) {
      if (node->aradius_ >= (0.05 / sin (pi / 18.0))) {
	    npts = (long) floor ((fabs (node->arcangle_) / (pi / 18.0)) + 0.5); }
      else if (node->aradius_ == 0.0) { npts = 4; }
      else { npts = (long) floor ((fabs (node->arcangle_) /
		  atan (0.05 / node->aradius_)) + 0.5); }
      if (npts < 4) { npts = 4; }
      r = node->arcangle_ / npts;
      ct = cos (r);
      st = sin (r);
      x = node->aradius_ * cos (node->startangle_);
      y = node->aradius_ * sin (node->startangle_);
      for (i = 1; i <= npts; i++) {
	    x1 = (ct * x) - (st * y);
	    y1 = (st * x) + (ct * y);
	    printf ("\\put");
	    wcoord (&output, node->aat.xpos + x, node->aat.ypos + y);
	    printf ("{\\line");
	    wcoord (&output, x1 - x, y1 - y);
	    if (fabs (x1 - x) != 0.0) { wbrace (fabs (x1 - x) / fsc); }
        else { wbrace (fabs (y1 - y) / fsc); }
	    printf ("}\n");
	    if ((i == 1) & ((ahlex (node->lineatype_) == Xdoublehead) |
		  (ahlex (node->lineatype_) == Xlefthead))) {
	      arrowhead (node->aat.xpos + x, node->aat.ypos + y,
		     node->aat.xpos + x1, node->aat.ypos + y1); }
        else if ((i == npts) & ((ahlex (node->lineatype_) == Xdoublehead) |
          (ahlex (node->lineatype_) == Xrighthead))) {
	      arrowhead (node->aat.xpos + x1, node->aat.ypos + y1,
		     node->aat.xpos + x, node->aat.ypos + y); }
	    x = x1;
	    y = y1;
        }
      texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      }
    break;

  case Xstring:
    texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n'); }
    break;
  }
}				/* texdraw */
