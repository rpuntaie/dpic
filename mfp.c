/* Output routines for mfpic */
void
mfpprelude (double n, double s, double e, double w) {
  printf ("\\begin{mfpic}[72]");
  wbrace (w / fsc);
  wbrace (e / fsc);
  wbrace (s / fsc);
  wbrace (n / fsc);
  printf ("\n%% dpic version %s option -m for mfpic\n",VERSIONDATE);
  printf ("\\dashlen=4bp\\dashspace=4bp\\dotspace=3bp\\pen{0.8bp}\n");
  printf ("\\def\\mfpdefaultcolor{black}\\drawcolor{\\mfpdefaultcolor}\n");
  gslinethick = 0.8;
}

void
mfppostlude (void) {
  printf ("\\end{mfpic}\n");
}

void
mfpwrtext (primitive * np, nametype * tp, double x, double y) {
  boolean A, B, L, R;

  if (tp == NULL) {
    return;
  }
  if (tp->next_ != NULL) {
    printf ("\\tlabel[cc]");
    wcoord (&output, x, y);
    putchar ('{');
    texstacktext (np, tp);
    printf ("}\n");
    return;
  }
  printf ("\\tlabel[");
  checkjust (tp, &A, &B, &L, &R);
  if (A) {
    putchar ('b');
  } else if (B) {
    putchar ('t');
  } else {
    putchar ('c');
  }
  if (L) {
    putchar ('l');
  } else if (R) {
    putchar ('r');
  } else {
    putchar ('c');
  }
  putchar (']');
  wcoord (&output, x, y);
  putchar ('{');
  if (A) {
    printf ("\\raisebox{");
    wfloat (&output,
	    (venv (np, XLtextoffset) / scale / 12) +
	    (0.5 * venv (np, XLtextht)));
    printf ("ex}{");
  } else if (B) {
    printf ("\\raisebox{");
    wfloat (&output,
	    (venv (np, XLtextoffset) / scale / (-12)) -
	    (0.5 * venv (np, XLtextht)));
    printf ("ex}{");
  }
  wstring (&output, tp);
  if (A || B) {
    putchar ('}');
  }
  printf ("}\n");
}

void
comma (void) {
  putchar (',');
}

void
commacr (void) {
  printf (",\n");
}

void
mfpsetshade (double fill, nametype * shade) {
  if (shade != NULL) {
    printf ("\\gfill[");
    wstring (&output, shade);
    putchar (']');
    return;
  }
  if (fill <= 0.0) {
    printf ("\\gfill");
    return;
  }
  if (fill >= 0.99) {
    return;
  }
  printf ("\\shadespace=");
  wfloat (&output, 0.44 / sqrt (1 - fill));
  printf ("bp\\shade");
}

void
mfpellipse (postype aat, double elwidth, double elheight) {
  printf ("\\ellipse{");
  wpos (aat);
  comma ();
  wfloat (&output, 0.5 * elwidth / fsc);
  comma ();
  wfloat (&output, 0.5 * elheight / fsc);
  printf ("}\n");
}

void
mfpcircle (postype aat, double radius) {
  printf ("\\circle{");
  wpos (aat);
  comma ();
  wfloat (&output, radius / fsc);
  printf ("}\n");
}

void
mfpsetdash (double dash) {
  if (dash < 0.0) {
    return;
  }
  printf ("\\dashlen=");
  wfloat (&output, dash);
  printf ("in");
  printf ("\\dashspace=");
  wfloat (&output, dash);
  printf ("in");
}

void
mfsetthick (double lthk) {
  if ((lthk < 0.0) || (lthk == gslinethick)) {
    return;
  }
  printf ("\\pen{");
  wfloat (&output, lthk);
  printf ("bp}");
  gslinethick = lthk;
}

void
mfpdashdot (int lsp, double param, double lth) {
  if (lsp == XLdashed) {
    mfpsetdash (param / fsc);
    printf ("\\dashed");
    return;
  }
  if (lsp != XLdotted) {
    return;
  }
  printf ("\\dotted[");
  wfloat (&output, lth);
  printf ("pt,");
  if (param >= 0.0) {
    wfloat (&output, param / fsc);
    printf ("in]");
  } else {
    wfloat (&output, lth * 3);
    printf ("pt]");
  }
}

void
mfplineopts (double lth, double param, int lsp, nametype * sou) {
  if (sou != NULL) {
    printf ("\\drawcolor{");
    wstring (&output, sou);
    printf ("}\n");
  }
  mfsetthick (lth);
  mfpdashdot (lsp, param, lth);
}

void
mfpahead (int atyp, postype * point, postype shaft, double ht, double wid,
	  double lth, nametype * sou) {
  postype P, L, R, Px, Lx, Rx, Q;
  double lwu, x, y, cs, ss, d;

  lwu = (lth / 72) * scale;
  dahead (*point, shaft, ht, wid, lwu, &P, &L, &R, &Px, &Lx, &Rx, &Q, &x, &y);
  mfsetthick (0.0);
  printf ("\\draw\\gfill");
  if (sou != NULL) {
    putchar ('[');
    wstring (&output, sou);
    putchar (']');
  }
  printf ("\\polygon{");
  d = sqrt ((ht * ht) + (wid * wid / 4));
  if (d == 0) {
    cs = 1.0;
    ss = 0.0;
  } else {
    cs = ht / d;
    ss = wid / 2 / d;
  }
  wpos (Rx);
  commacr ();
  wpos (*point);
  comma ();
  wpos (Lx);
  if ((atyp == 0) && (lwu < ((wid - lwu) / 2))) {
    comma ();
    putchar ('\n');
    wpos (affine (ss * lwu, cs * lwu, Lx, Q));
    comma ();
    wprop (*point, P, -1.0, 2.0, 1.0);
    comma ();
    wpos (affine (ss * lwu, (-cs) * lwu, Rx, Q));
  } else if ((atyp == 3) && (lwu < ((wid - lwu) / 2))) {
    comma ();
    putchar ('\n');
    wpos (Px);
  }
  printf ("}\n");
  *point = P;
}

void
mfpwarc (postype Ctr, double radius, double startangle, double endangle,
	 double ccw) {
  printf ("\\arc[p]{");
  wpos (Ctr);
  comma ();
  if ((ccw > 0) && (endangle < startangle)) {
    endangle += 2 * pi;
  } else if ((ccw < 0) && (endangle > startangle)) {
    endangle -= 2 * pi;
  }
  wfloat (&output, (180.0 / pi) * startangle);
  comma ();
  wfloat (&output, (180.0 / pi) * endangle);
  comma ();
  wfloat (&output, fabs (radius) / fsc);
  printf ("}\n");
}

void
mfparcahead (postype C, postype point, int atyp, nametype * sou, double ht,
	     double wid, double lth, double radius, double arcangle,
	     postype * P) {
  postype Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi;
  boolean startarrow;

  arcahead (C, point, atyp, ht, wid, lth, radius, arcangle, P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  mfsetthick (0.0);
  printf ("\\draw\\gfill");
  if (sou != NULL) {
    putchar ('[');
    wstring (&output, sou);
    putchar (']');
  }
  printf ("\\lclosed\\begin{connect}\n");
  mfpwarc (Ci, radius, posangle (Ai, Ci), posangle (point, Ci), -ccw);
  mfpwarc (Co, radius, posangle (point, Co), posangle (Ao, Co), ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    mfpwarc (Co, radius - lwi, posangle (Ao, Co), posangle (*P, Co), -ccw);
    mfpwarc (Ci, radius + lwi, posangle (*P, Ci), posangle (Ai, Ci), ccw);
  } else if ((atyp == 3) && (lwi < ((wid - lwi) / 2))) {
    mfpwarc (Cox, radius, posangle (Ao, Cox), posangle (Px, Cox), -ccw);
    mfpwarc (Cix, radius, posangle (Px, Cix), posangle (Ai, Cix), ccw);
  }
  printf ("\\end{connect}\n");
}

void
mfpsplinesegment (primitive * tv, int splc, int splt) {
  if (tv == NULL) {
    return;
  }
  if (splt == 1) {
    printf ("\\polyline{");
    wpos (tv->aat);
    comma ();
    wpos (tv->Upr.Uline.endpos);
    printf ("}\n");
    return;
  }
  if (ismdistmax (tv->Upr.Uline.aradius)) {
    if (splc == splt) {		/* 1st seg */
      printf ("\\cbeziers{");
      wpos (tv->aat);
      comma ();
      wprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
      comma ();
      wprop (tv->aat, tv->Upr.Uline.endpos, 2.0, 1.0, 3.0);
      comma ();
      wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      commacr ();
      wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      comma ();
      return;
    }
    if (splc > 1) {		/* interior segment */
      wprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
      comma ();
      wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      comma ();
      wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      commacr ();
      return;
    }
    wprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
    comma ();
    wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
    comma ();
    wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 2.0, 3.0);
    comma ();
    wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
    commacr ();
    wpos (tv->Upr.Uline.endpos);
    printf ("}\n");
    /* last segment */
    return;
  }
  if ((splc == splt) && (splc > 1)) {
    printf ("\\cbeziers{");
    wpos (tv->aat);
    comma ();
    wprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	   tv->Upr.Uline.aradius, 1.0);
    commacr ();
    return;
  }
  if (splc > 1) {
    wprop (tv->aat, tv->Upr.Uline.endpos, 0.5 + (tv->Upr.Uline.aradius / 2),
	   0.5 - (tv->Upr.Uline.aradius / 2), 1.0);
    comma ();
    wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
    comma ();
    wprop (tv->aat, tv->Upr.Uline.endpos, 0.5 - (tv->Upr.Uline.aradius / 2),
	   0.5 + (tv->Upr.Uline.aradius / 2), 1.0);
    commacr ();
    return;
  }
  wprop (tv->aat, tv->Upr.Uline.endpos, tv->Upr.Uline.aradius,
	 1 - tv->Upr.Uline.aradius, 1.0);
  comma ();
  wpos (tv->Upr.Uline.endpos);
  printf ("}\n");
}

void
mfpbox (double x, double y, double n, double s, double e, double w,
	double rad) {
  double h, v, rr;

  rad = Min (Min (fabs (rad), fabs ((n - s) / 2)), fabs ((e - w) / 2));
  if (rad == 0.0) {
    printf ("\\rect{");
    wcoord (&output, w, s);
    comma ();
    wcoord (&output, e, n);
  } else {
    rr = (1 - SPLT) * rad;
    h = ((e - w) / 2) - rad;
    v = ((n - s) / 2) - rad;
    printf ("\\lclosed\\cbeziers{");
    wcoord (&output, e, y + v);
    comma ();
    wcoord (&output, e, n - rr);
    comma ();
    wcoord (&output, e - rr, n);
    comma ();
    wcoord (&output, x + h, n);
    commacr ();
    wcoord (&output, x + (h / 3), n);
    comma ();
    wcoord (&output, x - (h / 3), n);
    comma ();
    wcoord (&output, x - h, n);
    comma ();
    wcoord (&output, w + rr, n);
    comma ();
    wcoord (&output, w, n - rr);
    comma ();
    wcoord (&output, w, y + v);
    commacr ();
    wcoord (&output, w, y + (v / 3));
    comma ();
    wcoord (&output, w, y - (v / 3));
    comma ();
    wcoord (&output, w, y - v);
    comma ();
    wcoord (&output, w, s + rr);
    comma ();
    wcoord (&output, w + rr, s);
    comma ();
    wcoord (&output, x - h, s);
    commacr ();
    wcoord (&output, x - (h / 3), s);
    comma ();
    wcoord (&output, x + (h / 3), s);
    comma ();
    wcoord (&output, x + h, s);
    comma ();
    wcoord (&output, e - rr, s);
    comma ();
    wcoord (&output, e, s + rr);
    comma ();
    wcoord (&output, e, y - v);
    commacr ();
    wcoord (&output, e, y - (v / 3));
    comma ();
    wcoord (&output, e, y + (v / 3));
  }
  printf ("}\n");
}

/* node is always <> nil: */
void
mfpdraw (primitive * node) {
  int lsp;
  postype X0, X1;
  primitive *tn, *tx;
  double lth;
  int TEMP;
  primitive *With1;

  getlinespec (node, &lsp, &tn);
  lth = qenv (node, XLlinethick, node->lthick);
  switch (node->ptype) {

  case XLbox:
  case XBLOCK:
    initnesw ();
    nesw (node);
    if (node->ptype == XLbox) {
      if (((node->Upr.Ubox.boxfill >= 0.0) && (node->Upr.Ubox.boxfill <= 1.0))
	  || (node->shadedp != NULL)) {
	mfpsetshade (node->Upr.Ubox.boxfill, node->shadedp);
	mfpbox (node->aat.xpos, node->aat.ypos, north, south, east, west,
		node->Upr.Ubox.boxradius);
      }
      if (lsp != XLinvis) {
	mfplineopts (lth, node->lparam, lsp, node->outlinep);
	mfpbox (node->aat.xpos, node->aat.ypos, north, south, east, west,
		node->Upr.Ubox.boxradius);
	if (node->outlinep != NULL) {
	  printf ("\\drawcolor{\\mfpdefaultcolor}\n");
	}
      }
    }
    mfpwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLellipse:
    if (((node->Upr.Uellipse.efill >= 0.0)
	 && (node->Upr.Uellipse.efill <= 1.0)) || (node->shadedp != NULL)) {
      mfpsetshade (node->Upr.Uellipse.efill, node->shadedp);
      mfpellipse (node->aat, node->Upr.Uellipse.elwidth,
		  node->Upr.Uellipse.elheight);
    }
    if (lsp != XLinvis) {
      mfplineopts (lth, node->lparam, lsp, node->outlinep);
      mfpellipse (node->aat, node->Upr.Uellipse.elwidth,
		  node->Upr.Uellipse.elheight);
      if (node->outlinep != NULL) {
	printf ("\\drawcolor{\\mfpdefaultcolor}\n");
      }
    }
    mfpwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLcircle:
    if (((node->Upr.Ucircle.cfill >= 0.0) && (node->Upr.Ucircle.cfill <= 1.0))
	|| (node->shadedp != NULL)) {
      mfpsetshade (node->Upr.Ucircle.cfill, node->shadedp);
      mfpcircle (node->aat, node->Upr.Ucircle.radius);
    }
    if (lsp != XLinvis) {
      mfplineopts (lth, node->lparam, lsp, node->outlinep);
      mfpcircle (node->aat, node->Upr.Ucircle.radius);
      if (node->outlinep != NULL) {
	printf ("\\drawcolor{\\mfpdefaultcolor}\n");
      }
    }
    mfpwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLspline:
    if (firstsegment (node)) {
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill) {
	mfsetthick (0.0);
	printf ("\\draw");
	mfpsetshade (vfill, sshade);
	printf ("%%\n");
	printf ("\\lclosed");
	spltot = primdepth (node);
	splcount = spltot;
	tx = node;
	while (tx != NULL) {
	  mfpsplinesegment (tx, splcount, spltot);
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
	  mfpahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos,
		    qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth,
		    soutline);
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  mfpahead (ahnum (node->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, qenv (tn, XLarrowht, tn->Upr.Uline.height),
		    qenv (tn, XLarrowwid, tn->Upr.Uline.width), lth,
		    soutline);
	}
	spltot = primdepth (node);
	splcount = spltot;
	mfplineopts (lth, node->lparam, lsp, soutline);
      }
    }
    if (lsp != XLinvis) {
      mfpsplinesegment (node, splcount, spltot);
    }
    splcount--;
    if ((node->son == NULL) && (node->outlinep != NULL)) {
      printf ("\\drawcolor{\\mfpdefaultcolor}\n");
    }
    break;

  case XLline:
  case XLarrow:
  case XLmove:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill) {
	mfsetthick (0.0);
	printf ("\\draw");
	mfpsetshade (vfill, sshade);
	printf ("%%\n");
	printf ("\\lclosed\\polyline{");
	wpos (node->aat);
	tx = node;
	while (tx != NULL) {
	  commacr ();
	  wpos (tx->Upr.Uline.endpos);
	  tx = tx->son;
	}
	printf ("}\n");
	vfill = -1.0;
	sshade = NULL;
      }
      if (lsp != XLinvis) {
	lth = qenv (tn, XLlinethick, tn->lthick);
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  mfpahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos,
		    qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width), lth,
		    soutline);
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  mfpahead (ahnum (tn->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width), lth,
		    soutline);
	}
	mfplineopts (lth, node->lparam, lsp, soutline);
	printf ("\\polyline{");
	wpos (node->aat);
      }
    }
    if (lsp != XLinvis) {
      commacr ();
      wpos (node->Upr.Uline.endpos);
      if (node->son == NULL) {
	printf ("}\n");
	if (soutline != NULL) {
	  printf ("\\drawcolor{\\mfpdefaultcolor}\n");
	}
      }
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	With1 = snode;
	if (With1->textp != NULL) {
	  mfpwrtext (snode, With1->textp,
		     0.5 * (With1->aat.xpos + With1->Upr.Uline.endpos.xpos),
		     0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case XLarc:
    X0 = arcstart (node);
    X1 = arcend (node);
    getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
    if (bfill) {
      mfsetthick (0.0);
      printf ("\\draw");
      mfpsetshade (vfill, sshade);
      printf ("%%\n");
      printf ("\\lclosed");
      mfpwarc (node->aat, node->Upr.Uline.aradius, posangle (X0, node->aat),
	       posangle (X1, node->aat), node->Upr.Uline.endpos.ypos);
      vfill = -1.0;
      sshade = NULL;
    }
    if (lsp != XLinvis) {
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	mfparcahead (node->aat, X0, ahnum (node->Upr.Uline.atype), soutline,
		     qenv (node, XLarrowht, node->Upr.Uline.height),
		     qenv (node, XLarrowwid, node->Upr.Uline.width), lth,
		     fabs (node->Upr.Uline.aradius),
		     node->Upr.Uline.endpos.ypos, &X0);
      }
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	mfparcahead (node->aat, X1, ahnum (node->Upr.Uline.atype), soutline,
		     qenv (node, XLarrowht, node->Upr.Uline.height),
		     qenv (node, XLarrowwid, node->Upr.Uline.width), lth,
		     -fabs (node->Upr.Uline.aradius),
		     node->Upr.Uline.endpos.ypos, &X1);
      }
      mfplineopts (lth, node->lparam, lsp, soutline);
      mfpwarc (node->aat, node->Upr.Uline.aradius, posangle (X0, node->aat),
	       posangle (X1, node->aat), node->Upr.Uline.endpos.ypos);
      if (soutline != NULL) {
	printf ("\\drawcolor{\\mfpdefaultcolor}\n");
      }
    }
    mfpwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLstring:
    mfpwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
    } else if (lth >= 0.0) {
      mfsetthick (lth);
    } else if (node->lparam >= 0.0) {
      mfpsetdash (node->lparam);
      putchar ('\n');
    }
    break;
  }
}				/* mfpdraw */