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
  printf ("\\end{picture}\n");
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

  if (x < 0) {
    x = -x;
  }
  if (y < 0) {
    y = -y;
  }
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
  if (x == 0) {
    return 1;
  } else {
    return x;
  }
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
  if (drawmode == Pict2e) {
    i = 1000;			/*4096 */
  } else if (drawmode == tTeX) {
    i = 453;
  } else if (arrow) {
    i = 4;
  } else {
    i = 6;
  }
  iy = (long) floor (((i + 0.49999) * yp / r) + 0.5);
  ix = (long) floor (((i + 0.49999) * xp / r) + 0.5);
  i = hcf (ix, iy);
  iy /= i;
  ix /= i;
  printf ("(%d,%d)", ix, iy);
  if (ix == 0) {
    wbrace (fabs (yp) / fsc);
  } else {
    wbrace (fabs (xp) / fsc);
  }
}

void
arrowhead (double pointx, double pointy, double tailx, double taily) {
  double x, y, r, ct;

  r = linlen (pointx - tailx, pointy - taily);
  if (r == 0.0) {
    return;
  }
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

  if (tp == NULL) {
    return;
  }
  printf ("\\put");
  checkjust (tp, &A, &B, &L, &R);
  if (A) {
    wcoord (&output, x, y + 0.1);
  } else if (B) {
    wcoord (&output, x, y - 0.05);
  } else {
    wcoord (&output, x, y);
  }
  checkjust (tp, &A, &B, &L, &R);
  putchar ('{');
  printf ("\\makebox(0,0)");
  if (L) {
    printf ("[l]");
  } else if (R) {
    printf ("[r]");
  }
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
  if ((lt < 0.0) || (lt == gslinethick)) {
    return;
  }
  printf ("\\linethickness{");
  wfloat (&output, lt);
  printf ("pt}\n");
  gslinethick = lt;
}

void
texdraw (primitive * node) {
  int i, npts, lsp;
  double r, x, y, x1, y1, ct, st, lgth, lth;
  primitive *tn, *p;
  postype tmpat, X0, X3;
  int TEMP;

  getlinespec (node, &lsp, &tn);
  lth = qenv (node, XLlinethick, node->lthick);
  switch (node->ptype) {

  case XLbox:
  case XBLOCK:
    if (drawn (node, lsp, -1.0) || (node->textp != NULL)) {
      initnesw ();
      nesw (node);
      if (drawmode == Pict2e) {
	p2setthick (lth);
      }
      printf ("\\put");
      wcoord (&output, west, south);
      if (node->ptype == XBLOCK) {
	printf ("{\\makebox");
      } else if (lsp == XLsolid) {
	printf ("{\\framebox");
      } else if (lsp == XLinvis) {
	printf ("{\\makebox");
      } else if (lsp == XLdashed) {
	printf ("{\\dashbox");
	if (!ismdistmax (node->lparam)) {
	  wbrace (node->lparam / fsc);
	} else {
	  wbrace (venv (node, XLdashwid) / fsc);
	}
      } else if (lsp == XLdotted) {
	printf ("{\\dashbox");
	printf ("{0.01}");
      }
      if (node->ptype == XLbox) {
	wcoord (&output, node->Upr.Ubox.boxwidth, node->Upr.Ubox.boxheight);
      } else {
	wcoord (&output, node->Upr.UBLOCK.blockwidth,
		node->Upr.UBLOCK.blockheight);
      }
      putchar ('{');
      texstacktext (node, node->textp);
      printf ("}}\n");
    }
    break;

  case XLline:
  case XLarrow:
    if (drawn (node, lsp, -1.0)) {
      if (firstsegment (node)) {	/* first segment */
	if (drawmode == Pict2e) {
	  p2setthick (lth);
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  p2ahead (&node->aat, node->Upr.Uline.endpos,
		   qenv (node, XLarrowht, tn->Upr.Uline.height));
	}
      }
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((node->son == NULL) & ((TEMP == XDOUBLEHEAD) ||
				 (TEMP == XRIGHTHEAD))) {
	p2ahead (&node->Upr.Uline.endpos, node->aat,
		 qenv (node, XLarrowht, tn->Upr.Uline.height));
      }
      lgth = linlen (node->Upr.Uline.endpos.xpos - node->aat.xpos,
		     node->Upr.Uline.endpos.ypos - node->aat.ypos);
      if ((drawmode == Pict2e) ||
	  ((lsp == XLsolid) && ((lgth > 0.18) || (drawmode == tTeX)))) {
	if (lgth > 0) {
	  printf ("\\put");
	  wpos (node->aat);
	  printf ("{\\line");
	  wrslope (node->Upr.Uline.endpos.xpos - node->aat.xpos,
		   node->Upr.Uline.endpos.ypos - node->aat.ypos, false);
	  printf ("}\n");
	}
      } else if (lsp == XLsolid) {
	npts = (long) floor ((lgth / 0.005) + 0.5);
	if (npts == 0) {
	  npts = 1;
	}
	printf ("\\multiput");
	wpos (node->aat);
	wcoord (&output,
		(node->Upr.Uline.endpos.xpos - node->aat.xpos) / npts,
		(node->Upr.Uline.endpos.ypos - node->aat.ypos) / npts);
	printf ("{%d}", npts + 1);
	printf ("{\\makebox(0.005555,0.00825){\\tiny .}}\n");
      } else if (lsp == XLdashed) {
	printf ("\\put");
	wpos (node->aat);
	printf ("{\\dashline[50]");
	if (!ismdistmax (node->lparam)) {
	  wbrace (node->lparam / fsc);
	} else {
	  wbrace (venv (node, XLdashwid) / fsc);
	}
	printf ("(0,0)");
	wcoord (&output, node->Upr.Uline.endpos.xpos - node->aat.xpos,
		node->Upr.Uline.endpos.ypos - node->aat.ypos);
	printf ("}\n");
      } else if (lsp == XLdotted) {
	printf ("\\dottedline{");
	wfloat (&output, 0.05 / fsc);
	putchar ('}');
	wpos (node->aat);
	wpos (node->Upr.Uline.endpos);
	putchar ('\n');
      }
    }
    texwrtext (node, node->textp,
	       0.5 * (node->Upr.Uline.endpos.xpos + node->aat.xpos),
	       0.5 * (node->aat.ypos + node->Upr.Uline.endpos.ypos));
    break;

  case XLspline:
    if ((drawmode == Pict2e) & drawn (node, lsp, -1.0)) {
      if (firstsegment (node)) {	/* first spline */
	spltot = primdepth (node);
	splcount = spltot;
	tmpat = node->aat;
	p2setthick (lth);
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  p2ahead (&node->aat, node->Upr.Uline.endpos,
		   qenv (node, XLarrowht, tn->Upr.Uline.height));
	}
	/* p2lineopts(lsp,lparam,outlinep); */
	if ((spltot > 1) & ismdistmax (node->Upr.Uline.aradius)) {
	  printf ("\\put");
	  wcoord (&output, node->aat.xpos, node->aat.ypos);
	  printf ("{\\line");
	  wrslope ((node->Upr.Uline.endpos.xpos - node->aat.xpos) / 2,
		   (node->Upr.Uline.endpos.ypos - node->aat.ypos) / 2, false);
	  printf ("}\n");
	  printf ("\\cbezier");
	  wprop (node->Upr.Uline.endpos, node->aat, 1.0, 1.0, 2.0);
	  wprop (node->aat, node->Upr.Uline.endpos, 1.0, 5.0, 6.0);
	} else if (spltot > 1) {
	  printf ("\\cbezier");
	  wpos (node->aat);
	  node->aat = tmpat;
	  wprop (node->aat, node->Upr.Uline.endpos,
		 1 - node->Upr.Uline.aradius, node->Upr.Uline.aradius, 1.0);
	}
      } else if ((splcount > 1) & ismdistmax (node->Upr.Uline.aradius)) {
	wprop (node->aat, node->Upr.Uline.endpos, 5.0, 1.0, 6.0);
	wprop (node->aat, node->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	printf ("%%\n");
	printf ("\\cbezier");
	wprop (node->aat, node->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	wprop (node->aat, node->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      } else if (splcount > 1) {
	wprop (node->aat, node->Upr.Uline.endpos,
	       0.5 + (node->Upr.Uline.aradius / 2),
	       0.5 - (node->Upr.Uline.aradius / 2), 1.0);
	wprop (node->aat, node->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	printf ("%%\n");
	printf ("\\cbezier");
	wprop (node->aat, node->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	wprop (node->aat, node->Upr.Uline.endpos,
	       0.5 - (node->Upr.Uline.aradius / 2),
	       0.5 + (node->Upr.Uline.aradius / 2), 1.0);
      }
      if (splcount == 1) {
	tmpat = node->Upr.Uline.endpos;
	TEMP = ahlex (node->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  x = linlen (node->Upr.Uline.endpos.xpos - node->aat.xpos,
		      node->Upr.Uline.endpos.ypos - node->aat.ypos);
	  y = qenv (node, XLarrowht, tn->Upr.Uline.height);
	  pprop (node->aat, &node->Upr.Uline.endpos, y, x - y, x);
	}
	if ((spltot > 1) & ismdistmax (node->Upr.Uline.aradius)) {
	  wprop (node->aat, node->Upr.Uline.endpos, 5.0, 1.0, 6.0);
	  wprop (node->aat, node->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	  printf ("%%\n");
	  printf ("\\put");
	  wprop (node->aat, node->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	  printf ("{\\line");
	  wrslope ((node->Upr.Uline.endpos.xpos - node->aat.xpos) / 2,
		   (node->Upr.Uline.endpos.ypos - node->aat.ypos) / 2, false);
	  printf ("}\n");
	} else if (spltot > 1) {
	  wprop (node->aat, node->Upr.Uline.endpos, node->Upr.Uline.aradius,
		 1 - node->Upr.Uline.aradius, 1.0);
	  wpos (node->Upr.Uline.endpos);
	  printf ("%%\n");
	}
	TEMP = ahlex (node->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  p2ahead (&tmpat, node->aat,
		   qenv (node, XLarrowht, tn->Upr.Uline.height));
	}
      }
      splcount--;
    } else if ((lsp == XLdotted) || (lsp == XLdashed) || (lsp == XLsolid)) {
      if (firstsegment (node) & ((ahlex (node->Upr.Uline.atype) == XDOUBLEHEAD) | (ahlex (node->Upr.Uline.atype) == XLEFTHEAD))) {	/* first spline */
	arrowhead (node->aat.xpos, node->aat.ypos,
		   node->Upr.Uline.endpos.xpos, node->Upr.Uline.endpos.ypos);
      }
      printf ("\\spline");
      wpos (node->aat);
      wpos (node->Upr.Uline.endpos);
      if (node->son == NULL) {
	putchar ('\n');
      } else if (node->son->son == NULL) {
	wpos (node->son->Upr.Uline.endpos);
	if ((ahlex (node->Upr.Uline.atype) == XRIGHTHEAD) |
	    (ahlex (node->Upr.Uline.atype) == XDOUBLEHEAD)) {
	  arrowhead (node->son->Upr.Uline.endpos.xpos,
		     node->son->Upr.Uline.endpos.ypos, node->son->aat.xpos,
		     node->son->aat.ypos);
	}
	node->ptype = XLline;
	putchar ('\n');
	/* son := nil */
	deletetree (&node->son);
      } else {
	pprop (node->son->Upr.Uline.endpos, &node->son->aat, 1.0, 1.0, 2.0);
	wpos (node->son->aat);
	node->ptype = XLline;
	putchar ('\n');
      }
    }
    break;

  case XLmove:
    texwrtext (node, node->textp,
	       0.5 * (node->Upr.Uline.endpos.xpos + node->aat.xpos),
	       0.5 * (node->aat.ypos + node->Upr.Uline.endpos.ypos));
    break;

  case XLellipse:
    if (drawmode == Pict2e) {
      p2setthick (lth);
    }
    printf ("\\put");
    wpos (node->aat);
    if (drawmode == TeX) {
      printf ("{\\ellipse");
      wbrace (node->Upr.Uellipse.elwidth / fsc);
      wbrace (node->Upr.Uellipse.elheight / fsc);
      printf ("}\n");
    } else {
      printf ("{\\oval");
      wcoord (&output, node->Upr.Uellipse.elwidth,
	      node->Upr.Uellipse.elheight);
      printf ("}\n");
    }
    texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLcircle:
    if (lsp != XLinvis) {
      if (drawmode == Pict2e) {
	p2setthick (lth);
      }
      printf ("\\put");
      wpos (node->aat);
      printf ("{\\circle");
      wbrace (2.0 * node->Upr.Ucircle.radius / fsc);
      printf ("}\n");
    }
    texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLarc:
    if ((drawmode == Pict2e) & drawn (node, lsp, -1.0)) {
      p2setthick (node->lthick);	/* p2linecap(lsp); */
      X0 = arcstart (node);
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	if (node->Upr.Uline.aradius == 0.0) {
	  x = 0.0;
	} else {
	  x = atan (qenv (node, XLarrowht, node->Upr.Uline.height) /
		    node->Upr.Uline.aradius);
	}
	if (node->Upr.Uline.endpos.ypos >= 0.0) {
	  node->Upr.Uline.endpos.xpos += x;
	  node->Upr.Uline.endpos.ypos -= x;
	} else {
	  node->Upr.Uline.endpos.xpos -= x;
	  node->Upr.Uline.endpos.ypos += x;
	}
	tmpat = X0;
	X0 = arcstart (node);
	p2ahead (&tmpat, X0, qenv (node, XLarrowht, node->Upr.Uline.height));
      }
      X3 = arcend (node);
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	if (node->Upr.Uline.aradius == 0.0) {
	  x = 0.0;
	} else {
	  x = atan (qenv (node, XLarrowht, node->Upr.Uline.height) /
		    node->Upr.Uline.aradius);
	}
	if (node->Upr.Uline.endpos.ypos >= 0.0) {
	  node->Upr.Uline.endpos.ypos -= x;
	} else {
	  node->Upr.Uline.endpos.ypos += x;
	}
	tmpat = X3;
	X3 = arcend (node);
	p2ahead (&tmpat, X3, qenv (node, XLarrowht, node->Upr.Uline.height));
      }
      npts = (long) (1.0 + (fabs (node->Upr.Uline.endpos.ypos) / pi));
      node->Upr.Uline.endpos.ypos /= npts;
      while (npts > 0) {
	printf ("\\cbezier");
	wpos (X0);
	x = cos (node->Upr.Uline.endpos.ypos / 2);
	y = sin (node->Upr.Uline.endpos.ypos / 2);
	x1 = (4 - x) / 3;
	if (y != 0.0) {
	  y1 = (1.0 - (x * x1)) / y;
	} else {
	  y1 = 0.0;
	}
	tmpat.xpos = cos (node->Upr.Uline.endpos.xpos +
			  (node->Upr.Uline.endpos.ypos / 2.0));
	tmpat.ypos = sin (node->Upr.Uline.endpos.xpos +
			  (node->Upr.Uline.endpos.ypos / 2.0));
	wpos (affine (node->Upr.Uline.aradius * x1,
		      -node->Upr.Uline.aradius * y1, node->aat, tmpat));
	wpos (affine (node->Upr.Uline.aradius * x1,
		      node->Upr.Uline.aradius * y1, node->aat, tmpat));
	if (npts > 1) {
	  node->Upr.Uline.endpos.xpos += node->Upr.Uline.endpos.ypos;
	  X0 = arcstart (node);
	  wpos (X0);
	  printf ("%%\n");
	}
	npts--;
      }
      wpos (X3);
      printf ("%%\n");		/*; p2dashdot(lsp,lparam,outlinep) */
    } else if (iscorner (principal (node->Upr.Uline.endpos.xpos, 0.5 * pi)) &&
	       (fabs (fabs (node->Upr.Uline.endpos.ypos) - (pi / 2.0)) <
		0.001)) {
      if (drawmode == Pict2e) {
	p2setthick (lth);
      }
      printf ("\\put");
      wpos (node->aat);
      printf ("{\\oval");
      wcoord (&output, 2 * node->Upr.Uline.aradius / fsc,
	      2 * node->Upr.Uline.aradius / fsc);
      if ((node->direction != XLdown) && (node->direction != XLup) &&
	  (node->direction != XLright) && (node->direction != XLleft)) {
	p = findenv (node);
	if (p != NULL) {
	  node->direction = p->direction;
	}
      }
      if (((node->direction == XLleft) && (node->Upr.Uline.endpos.ypos < 0.0))
	  || ((node->direction == XLdown)
	      && (node->Upr.Uline.endpos.ypos > 0.0))) {
	printf ("[bl]}\n");
      } else if (((node->direction == XLleft) &&
		  (node->Upr.Uline.endpos.ypos > 0.0)) ||
		 ((node->direction == XLup) &&
		  (node->Upr.Uline.endpos.ypos < 0.0))) {
	printf ("[tl]}\n");
      } else if (((node->direction == XLright) &&
		  (node->Upr.Uline.endpos.ypos < 0.0)) ||
		 ((node->direction == XLup) &&
		  (node->Upr.Uline.endpos.ypos > 0.0))) {
	printf ("[tr]}\n");
      } else {
	printf ("[br]}\n");
      }
      texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    } else if ((drawmode >= 0) && (drawmode < 32) &&
	       (((1L << drawmode) & ((1L << TeX) | (1L << Pict2e))) != 0) &&
	       (node->Upr.Uline.aradius > 0.0)) {
      if (node->Upr.Uline.aradius >= (0.05 / sin (pi / 18.0))) {
	npts = (long) floor ((fabs (node->Upr.Uline.endpos.ypos) /
			      (pi / 18.0)) + 0.5);
      } else if (node->Upr.Uline.aradius == 0.0) {
	npts = 4;
      } else {
	npts =
	  (long)
	  floor ((fabs (node->Upr.Uline.endpos.ypos) /
		  atan (0.05 / node->Upr.Uline.aradius)) + 0.5);
      }
      if (npts < 4) {
	npts = 4;
      }
      r = node->Upr.Uline.endpos.ypos / npts;
      ct = cos (r);
      st = sin (r);
      x = node->Upr.Uline.aradius * cos (node->Upr.Uline.endpos.xpos);
      y = node->Upr.Uline.aradius * sin (node->Upr.Uline.endpos.xpos);
      for (i = 1; i <= npts; i++) {
	x1 = (ct * x) - (st * y);
	y1 = (st * x) + (ct * y);
	printf ("\\put");
	wcoord (&output, node->aat.xpos + x, node->aat.ypos + y);
	printf ("{\\line");
	wcoord (&output, x1 - x, y1 - y);
	if (fabs (x1 - x) != 0.0) {
	  wbrace (fabs (x1 - x) / fsc);
	} else {
	  wbrace (fabs (y1 - y) / fsc);
	}
	printf ("}\n");
	if ((i == 1) & ((ahlex (node->Upr.Uline.atype) == XDOUBLEHEAD) |
			(ahlex (node->Upr.Uline.atype) == XLEFTHEAD))) {
	  arrowhead (node->aat.xpos + x, node->aat.ypos + y,
		     node->aat.xpos + x1, node->aat.ypos + y1);
	} else if ((i == npts) &
		   ((ahlex (node->Upr.Uline.atype) ==
		     XDOUBLEHEAD) | (ahlex (node->Upr.Uline.atype) ==
				     XRIGHTHEAD))) {
	  arrowhead (node->aat.xpos + x1, node->aat.ypos + y1,
		     node->aat.xpos + x, node->aat.ypos + y);
	}
	x = x1;
	y = y1;
      }
      texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    }
    break;

  case XLstring:
    texwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
    }
    break;
  }
}				/* texdraw */
