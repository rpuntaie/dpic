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
  if (lth == gslinethick) {
    return;
  }
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
  if (fll == 0.0) {
    printf ("black");
  } else if (fll == 0.25) {
    printf ("darkgray");
  } else if (fll == 0.5) {
    printf ("gray");
  } else if (fll == 0.75) {
    printf ("lightgray");
  } else if (fll == 1.0) {
    printf ("white");
  } else {
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
  double param;

  if (node->lthick >= 0.0) {
    svgsetstroke (node->lthick);
  }
  if (soutline != NULL) {
    svgsoutline (soutline);
  }
  if (node->ptype == XBLOCK) {
    lnspec = XLinvis;
  }
  switch (lnspec) {

  case XLdashed:
    param = qenv (node, XLdashwid, node->lparam) / fsc;
    printf (" stroke-dasharray=\"");
    wfloat (&output, param * 7 / 6);
    putchar (',');
    wfloat (&output, param * 5 / 6);
    printf ("\"\n");
    break;

  case XLdotted:
    /* if ismdistmax(lparam) then param := 5/72*scale
       else param := lparam; */
    if (!ismdistmax (node->lparam)) {
      param = node->lparam;
    } else {
      param = (qenv (node, XLlinethick, node->lthick) / 72) * 5 * scale;
    }
    printf (" stroke-linecap=\"round\"");
    printf (" stroke-dasharray=\"0.5,");
    wfloat (&output, param / fsc);
    printf ("\"\n");
    break;

  case XLinvis:
    printf (" stroke=\"none\"\n");
    break;
  }
}

void
svgfilloptions (primitive * node, double fill, nametype * sh, int lnspec,
		boolean poly) {
  fill = ((long) floor ((fill * 1000000L) + 0.5)) / 1000000.0;
  switch (node->ptype) {

  case XLbox:
  case XBLOCK:
    printf ("<rect");
    break;

  case XLellipse:
    printf ("<ellipse");
    break;

  case XLcircle:
    printf ("<circle");
    break;

  case XLspline:
    printf ("<path");
    break;

  case XLline:
  case XLarrow:
    if (poly) {
      printf ("<polyline");
    } else {
      printf ("<line");
    }
    break;

  case XLarc:
    printf ("<path");
    break;
  }
  if (sh != NULL) {
    printf (" fill=\"");
    wstring (&output, sh);
    putchar ('"');
  } else if ((fill >= 0.0) && (fill <= 1.0)) {
    fillgray (fill);
  } else if (node->ptype == XLstring) {
    fillgray (0.0);
  }
  svglineoptions (node, lnspec);
}

void
svgendpath (void) {
  printf (" />\n");
}

void
svgparam (Char * p, double x) {
  printf (" %s=\"", p);
  wfloat (&output, x / fsc);
  quote ();
}

void
svgcoord (Char * s1, Char * s2, double x, double y) {
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
      putchar (c);
    }
    waswhite = iswhite;
  }
}

void
svgwtext (primitive * node, nametype * tp, double x, double y) {
  int nstr = 0;
  nametype *tx;
  boolean L, R, A, B;
  double v, lineskip, xheight, dx, dy;

  if ((tp == NULL) || (node == NULL)) {
    return;
  }
  tx = tp;
  while (tx != NULL) {
    nstr++;
    tx = tx->next_;
  }
  v = nstr - 1 + dptextratio;
  if ((node->ptype == XLstring) && (nstr > 0) && (v != 0)) {
    lineskip = node->Upr.Ubox.boxheight / v;
  } else {
    lineskip = venv (node, XLtextht) / dptextratio;
  }
  xheight = lineskip * dptextratio;
  y += (v * lineskip / 2) - xheight;	/* string bottom */
  do {
    printf ("<text font-size=\"");
    wfloat (&output, (lineskip / scale) * 72);
    printf ("pt\"");
    if (node->ptype != XLstring) {
      printf (" stroke-width=\"0.2pt\" fill=\"black\"");
    } else {
      if (node->lthick < 0) {
	svgsetstroke (0.2);
      }
      svgfilloptions (node, node->Upr.Ubox.boxfill, node->shadedp,
		      lspec (node->spec), false);
    }
    v = venv (node, XLtextoffset);
    if (node->ptype == XLstring) {
      dx = node->Upr.Ubox.boxradius;
    } else {
      dx = 0.0;
    }
    checkjust (tp, &A, &B, &L, &R);
    if (L) {
      printf (" text-anchor=\"start\"\n");
      dx += v;
    } else if (R) {
      printf (" text-anchor=\"end\"\n");
      dx -= v;
    }
    dy = 0.0;
    if (node->ptype != XLstring) {
      if (A) {
	dy = (xheight / 2) + v;
      } else if (B) {
	dy = (xheight / (-2)) - v;
      }
    }
    svgcoord ("x", "y", Max (0.0, x + dx), Max (0.0, y + dy));
    if (tp->len > 40) {
      putchar ('\n');
    }
    putchar ('>');
    svgwstring (tp);
    printf ("</text>\n");
    y -= lineskip;
    tp = tp->next_;
  } while (tp != NULL);
}

void
svgwarc (postype E, double r, double angle, double ccw) {
  printf (" A ");
  wfloat (&output, fabs (r) / fsc);
  space ();
  wfloat (&output, fabs (r) / fsc);
  printf (" 0 ");
  if (fabs (angle) > pi) {
    putchar ('1');
  } else {
    putchar ('0');
  }
  if (ccw > 0) {
    printf (" 0 ");
  } else {
    printf (" 1 ");
  }
  svgwpos (E);
  if (angle == 0) {
    putchar ('\n');
  }
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
    printf ("\"\n");
  } else {
    printf (" fill=\"black\"\n");
  }
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    printf (" d=\"M ");
    svgwpos (P);
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
    svgwarc (P, radius - lwi, 1.0, -ccw);
  } else if ((atyp == 3) && (lwi < ((wid - lwi) / 2))) {
    printf (" d=\"M ");
    svgwpos (Px);
    putchar ('\n');
    svgwarc (Ai, radius, 0.0, ccw);
    svgwarc (*point, radius, 0.0, -ccw);
    svgwarc (Ao, radius, 0.0, ccw);
    svgwarc (Px, radius, 1.0, -ccw);
  } else {
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
    if (lth > 0.0) {
      svgsetstroke (lth);
    }
    if (sou != NULL) {
      svgsoutline (sou);
    }
    printf (" points=\"");
    svgwprop (P, L, x - y, y, x);
    space ();
    svgwpos (P);
    putchar ('\n');
    svgwprop (P, R, x - y, y, x);
  } else if (atyp == 3) {
    printf ("<polygon stroke-width=\"0\"");
    if (sou != NULL) {
      svgsoutline (sou);
      printf (" fill=\"");
      wstring (&output, sou);
      printf ("\"\n");
    } else if ((fill >= 0.0) && (fill <= 1.0)) {
      fillgray (fill);
    } else {
      printf (" fill=\"black\"\n");
    }
    printf (" points=\"");
    svgwpos (Px);
    space ();
    svgwpos (Lx);
    putchar ('\n');
    svgwpos (*point);
    space ();
    svgwpos (Rx);
  } else {
    printf ("<polygon stroke-width=\"0\"");
    if (sou != NULL) {
      svgsoutline (sou);
      printf (" fill=\"");
      wstring (&output, sou);
      printf ("\"\n");
    } else if ((fill >= 0.0) && (fill <= 1.0)) {
      fillgray (fill);
    } else {
      printf (" fill=\"black\"\n");
    }
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
    wfloat (&output, tv->Upr.Uline.endpos.xpos / fsc);
    printf ("\" y2=\"");
    wfloat (&output, tv->Upr.Uline.endpos.ypos / fsc);
    svgendpath ();
    return;
  }
  if (ismdistmax (tv->Upr.Uline.aradius)) {
    if (splc == splt) {		/* 1st seg */
      printf (" d=\"M ");
      svgwpos (tv->aat);
      printf ("\n C ");
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
      space ();
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 2.0, 1.0, 3.0);
      space ();
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      space ();
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      putchar ('\n');
      return;
    }
    if (splc > 1) {		/* interior segment */
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
      space ();
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      space ();
      svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      putchar ('\n');
      return;
    }
    svgwprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
    space ();
    svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
    space ();
    svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 2.0, 3.0);
    space ();
    svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
    putchar ('\n');
    svgwpos (tv->Upr.Uline.endpos);
    quote ();
    svgendpath ();
    /* last segment */
    return;
  }
  if ((splc == splt) && (splc > 1)) {
    printf (" d=\"M ");
    svgwpos (tv->aat);
    printf ("\n C ");
    svgwprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	      tv->Upr.Uline.aradius, 1.0);
    space ();
    return;
  }
  if (splc > 1) {
    svgwprop (tv->aat, tv->Upr.Uline.endpos,
	      0.5 + (tv->Upr.Uline.aradius / 2),
	      0.5 - (tv->Upr.Uline.aradius / 2), 1.0);
    space ();
    svgwprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
    space ();
    svgwprop (tv->aat, tv->Upr.Uline.endpos,
	      0.5 - (tv->Upr.Uline.aradius / 2),
	      0.5 + (tv->Upr.Uline.aradius / 2), 1.0);
    space ();
    return;
  }
  svgwprop (tv->aat, tv->Upr.Uline.endpos, tv->Upr.Uline.aradius,
	    1 - tv->Upr.Uline.aradius, 1.0);
  space ();
  svgwpos (tv->Upr.Uline.endpos);
  quote ();
  svgendpath ();
}

/* node is always <> nil */
void
svgdraw (primitive * node) {
  int lsp;
  postype X1, X2;
  primitive *tn, *tx;
  double h, w, lth;
  int TEMP;
  primitive *With1;

  getlinespec (node, &lsp, &tn);
  sshade = node->shadedp;
  soutline = node->outlinep;
  lth = qenv (node, XLlinethick, node->lthick);	/* printobject(node); */
  switch (node->ptype) {

  case XLbox:
    initnesw ();
    nesw (node);
    if (drawn (node, lsp, node->Upr.Ubox.boxfill)) {
      svgfilloptions (node, node->Upr.Ubox.boxfill, node->shadedp, lsp,
		      false);
      svgcoord ("x", "y",
		node->aat.xpos - (fabs (node->Upr.Ubox.boxwidth) / 2),
		node->aat.ypos + (fabs (node->Upr.Ubox.boxheight) / 2));
      if (node->Upr.Ubox.boxradius > 0.0) {
	svgparam ("rx", node->Upr.Ubox.boxradius);
	svgparam ("ry", node->Upr.Ubox.boxradius);
      }
      svgparam ("width", fabs (node->Upr.Ubox.boxwidth));
      svgparam ("height", fabs (node->Upr.Ubox.boxheight));
      svgendpath ();
    }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XBLOCK:
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLellipse:
    if (drawn (node, lsp, node->Upr.Uellipse.efill)) {
      svgfilloptions (node, node->Upr.Uellipse.efill, node->shadedp, lsp,
		      false);
      svgcoord ("cx", "cy", node->aat.xpos, node->aat.ypos);
      svgparam ("rx", 0.5 * fabs (node->Upr.Uellipse.elwidth));
      svgparam ("ry", 0.5 * fabs (node->Upr.Uellipse.elheight));
      svgendpath ();
    }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLcircle:
    if (drawn (node, lsp, node->Upr.Ucircle.cfill)) {
      svgfilloptions (node, node->Upr.Ucircle.cfill, node->shadedp, lsp,
		      false);
      svgcoord ("cx", "cy", node->aat.xpos, node->aat.ypos);
      svgparam ("r", fabs (node->Upr.Ucircle.radius));
      svgendpath ();
    }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLline:
  case XLarrow:
  case XLmove:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill) {
	printf ("<polyline stroke-width=\"0\"");
	if (soutline != NULL) {
	  svgsoutline (soutline);
	}
	if ((vfill >= 0) && (vfill <= 1)) {
	  fillgray (vfill);
	} else {
	  printf (" fill=\"");
	  wstring (&output, sshade);
	  printf ("\"\n");
	}
	printf (" points=\"");
	svgwpos (node->aat);
	tx = node;
	while (tx != NULL) {
	  putchar ('\n');
	  svgwpos (tx->Upr.Uline.endpos);
	  tx = tx->son;
	}
	printf ("\" />\n");
	vfill = -1.0;
	sshade = NULL;
      }
      if (lsp != XLinvis) {
	lth = qenv (tn, XLlinethick, tn->lthick);
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  svgahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos, soutline,
		    qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth, vfill);
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  svgahead (ahnum (tn->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, soutline,
		    qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth, vfill);
	}
	if (node->son == NULL) {
	  svgfilloptions (tn, vfill, sshade, lsp, false);
	  svgcoord ("x1", "y1", node->aat.xpos, node->aat.ypos);
	  svgcoord ("x2", "y2", node->Upr.Uline.endpos.xpos,
		    node->Upr.Uline.endpos.ypos);
	  svgendpath ();
	} else {
	  svgfilloptions (tn, vfill, sshade, lsp, true);
	  printf (" points=\"");
	  svgwpos (node->aat);
	  space ();
	}
      }
    } else if (lsp != XLinvis) {
      svgwpos (node->aat);
      putchar ('\n');
      if (node->son == NULL) {
	svgwpos (node->Upr.Uline.endpos);
	quote ();
	svgendpath ();
      }
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	With1 = snode;
	if (With1->textp != NULL) {
	  svgwtext (node, With1->textp,
		    0.5 * (With1->Upr.Uline.endpos.xpos + With1->aat.xpos),
		    0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case XLspline:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      node->lthick = tn->lthick;
      node->lparam = tn->lparam;
      if (bfill) {
	printf ("<path stroke-width=\"0\"");
	if (soutline != NULL) {
	  svgsoutline (soutline);
	}
	if ((vfill >= 0) && (vfill <= 1)) {
	  fillgray (vfill);
	} else {
	  printf (" fill=\"");
	  wstring (&output, sshade);
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
	vfill = -1.0;
	sshade = NULL;
      }
      if (lsp != XLinvis) {
	lth = qenv (tn, XLlinethick, tn->lthick);
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  svgahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos, soutline,
		    qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth,
		    node->Upr.Uline.lfill);
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  svgahead (ahnum (tn->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, soutline,
		    qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth,
		    node->Upr.Uline.lfill);
	}
	spltot = primdepth (node);
	splcount = spltot;
	svgfilloptions (node, vfill, sshade, lsp, false);
      }
    }
    if (lsp != XLinvis) {
      svgsplinesegment (node, splcount, spltot);
    }
    splcount--;
    break;

  case XLarc:
    X1 = arcstart (node);
    X2 = arcend (node);
    getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
    if (bfill) {
      printf ("<path stroke-width=\"0\"");
      if ((vfill >= 0) && (vfill <= 1)) {
	fillgray (vfill);
      } else {
	printf (" fill=\"");
	wstring (&output, sshade);
	printf ("\"\n");
      }
      printf (" d=\"M ");
      svgwpos (X1);
      putchar ('\n');
      svgwarc (X2, node->Upr.Uline.aradius, node->Upr.Uline.endpos.ypos,
	       node->Upr.Uline.endpos.ypos);
      quote ();
      svgendpath ();
      vfill = -1.0;
      sshade = NULL;
    }
    if (lsp != XLinvis) {
      lth = qenv (tn, XLlinethick, tn->lthick);
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	startarc (node, X1, lth, &h, &w);
	svgarcahead (node->aat, ahnum (node->Upr.Uline.atype), &X1, soutline,
		     h, w, lth, fabs (node->Upr.Uline.aradius),
		     node->Upr.Uline.endpos.ypos);
      }
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	endarc (node, X2, lth, &h, &w);
	svgarcahead (node->aat, ahnum (node->Upr.Uline.atype), &X2, soutline,
		     h, w, lth, -fabs (node->Upr.Uline.aradius),
		     node->Upr.Uline.endpos.ypos);
      }
      printf ("<path");
      svglineoptions (node, lsp);
      printf (" d=\"M ");
      svgwpos (X1);
      putchar ('\n');
      svgwarc (X2, node->Upr.Uline.aradius, node->Upr.Uline.endpos.ypos,
	       node->Upr.Uline.endpos.ypos);
      quote ();
      svgendpath ();
    }
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLstring:
    svgwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
    }
    break;
  }
}				/* svgdraw */
