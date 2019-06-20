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

  if (tp == NULL) {
    return;
  }
  if (tp->next_ != NULL) {
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
    wfloat (&output, (venv (np, XLtextoffset) / scale) * 72);
    printf ("bp}[");
    if (B) {
      putchar ('d');
    } else if (A) {
      putchar ('u');
    }
    if (L) {
      putchar ('r');
    } else if (R) {
      putchar ('l');
    }
    putchar (']');
  } else {
    printf ("\\rput");
  }
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
  if (node->ptype == XBLOCK) {
    lsp = XLinvis;
  }
  if ((lsp == XLinvis) || (lsp == XLdotted) || (lsp == XLdashed)) {	/* XLsolid, */
    printf ("%c%%\n", sep);
    printf ("linestyle=");
    switch (lsp) {

      /* XLsolid: write('solid'); */
      /* solid is the default */
    case XLdashed:
      printf ("dashed");
      if (node->lparam >= 0) {
	printf (",dash=");
	wfloat (&output, node->lparam / fsc);
	putchar (' ');
	wfloat (&output, node->lparam / fsc);
      }
      break;

    case XLdotted:
      printf ("dotted");
      if (node->lparam >= 0) {
	printf (",dotsep=");
	wfloat (&output, node->lparam / fsc);
      }
      break;

    case XLinvis:
      printf ("none");
      break;
    }
    sep = ',';
  }
  if ((node->ptype == XLspline) || (node->ptype == XLline) ||
      (node->ptype == XLarrow)) {
    if ((ahlex (node->Upr.Uline.atype) != XEMPTY) &
	(ahnum (node->Upr.Uline.atype) !=
	 0) & (ahnum (node->Upr.Uline.atype) != 3)) {
      printf ("%c%%\n", sep);
      printf ("arrowsize=");
      wfloat (&output, node->Upr.Uline.width / scale);
      printf ("in 0,arrowlength=");
      if (node->Upr.Uline.width == 0.0) {
	wfloat (&output, 0.0);
      } else {
	wfloat (&output, node->Upr.Uline.height / node->Upr.Uline.width);
      }
      printf (",arrowinset=0");
      sep = ',';
    }
  }
  if (sep == ',') {
    putchar (']');
  }
}

void
pstfilloptions (primitive * node, int lsp, double a) {
  Char sep;
  double fill = -1.0;

  switch (node->ptype) {

  case XBLOCK:
    /* blank case */
    break;

  case XLbox:
    fill = node->Upr.Ubox.boxfill;
    break;

  case XLcircle:
    fill = node->Upr.Ucircle.cfill;
    break;

  case XLellipse:
    fill = node->Upr.Uellipse.efill;
    break;

  case XLarc:
  case XLline:
  case XLarrow:
  case XLmove:
  case XLspline:
    fill = node->Upr.Uline.lfill;
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

  case XLbox:
  case XBLOCK:
    printf ("\\psframe");
    break;

  case XLellipse:
    printf ("\\psellipse");
    break;

  case XLcircle:
    printf ("\\pscircle");
    break;

  case XLspline:
    printf ("\\psbezier");
    break;

  case XLline:
  case XLarrow:
    printf ("\\psline");
    break;

  case XLarc:
    if (a >= 0.0) {
      printf ("\\psarc");
    } else {
      printf ("\\psarcn");
    }
    break;
  }
  if (sshade != NULL) {
    printf ("[fillstyle=solid,fillcolor=");
    wstring (&output, sshade);
    sep = ',';
  } else if ((fill >= 0.0) && (fill <= 1.0)) {
    printf ("[fillstyle=solid,fillcolor=");
    if (fill == 0.0) {
      printf ("black");
    } else if (fill == 0.25) {
      printf ("darkgray");
    } else if (fill == 0.5) {
      printf ("gray");
    } else if (fill == 0.75) {
      printf ("lightgray");
    } else if (fill == 1.0) {
      printf ("white");
    } else {
      printf ("fillval");
    }
    sep = ',';
  } else {
    sep = '[';
  }
  if (node->ptype == XLbox) {
    if (node->Upr.Ubox.boxradius != 0.0) {
      printf ("%clinearc=", sep);
      wfloat (&output, node->Upr.Ubox.boxradius / fsc);
      sep = ',';
    }
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
    if (sou != NULL) {
      wstring (&output, sou);
    } else {
      printf ("black");
    }
    printf ("]{%%\n");
    printf ("\\psline");
    wprop (P, L, x - y, y, x);
    wpos (P);
    wprop (P, R, x - y, y, x);
    printf ("}\n");
  } else {
    printf ("\\pscustom[linewidth=0pt,fillstyle=solid,fillcolor=");
    if (sou != NULL) {
      wstring (&output, sou);
    } else {
      printf ("black");
    }
    printf (",linecolor=");
    if (sou != NULL) {
      wstring (&output, sou);
    } else {
      printf ("black");
    }
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
pstwarc (postype C, double r, double startangle, double endangle, double ccw) {
  wpos (C);
  if ((ccw > 0) && (endangle < startangle)) {
    endangle += 2 * pi;
  } else if ((ccw < 0) && (endangle > startangle)) {
    endangle -= 2 * pi;
  }
  wbrace (r / fsc);
  wbrace ((180.0 / pi) * startangle);
  wbrace ((180.0 / pi) * endangle);
  putchar ('\n');
}

void
pstarc (double ccw) {
  if (ccw >= 0.0) {
    printf ("\\psarc");
  } else {
    printf ("\\psarcn");
  }
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
  if (sou != NULL) {
    wstring (&output, sou);
  } else {
    printf ("black");
  }
  printf (",linecolor=");
  if (sou != NULL) {
    wstring (&output, sou);
  } else {
    printf ("black");
  }
  printf ("]{%%\n");
  pstarc (-ccw);
  pstwarc (Ci, radius, posangle (Ai, Ci), posangle (point, Ci), -ccw);
  pstarc (ccw);
  pstwarc (Co, radius, posangle (point, Co), posangle (Ao, Co), ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    pstarc (-ccw);
    pstwarc (Co, radius - lwi, posangle (Ao, Co), posangle (*P, Co), -ccw);
    pstarc (ccw);
    pstwarc (Ci, radius + lwi, posangle (*P, Ci), posangle (Ai, Ci), ccw);
  } else if ((atyp == 3) && (lwi < ((wid - lwi) / 2))) {
    pstarc (-ccw);
    pstwarc (Cox, radius, posangle (Ao, Cox), posangle (Px, Cox), -ccw);
    pstarc (ccw);
    pstwarc (Cix, radius, posangle (Px, Cix), posangle (Ai, Cix), ccw);
  }
  printf ("\\closepath}%%\n");
}

void
pstsplinesegment (primitive * tv, int splc, int splt) {
  if (tv != NULL) {
    if (ismdistmax (tv->Upr.Uline.aradius)) {
      if ((splc == splt) && (splc > 1)) {	/* 1st seg */
	wpos (tv->aat);
	wprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
	/* 1/6 from 1st to 2nd */
	wprop (tv->aat, tv->Upr.Uline.endpos, 4.0, 2.0, 6.0);
	/* 1/3 from 1st to 2nd */
	wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	/* 1/2 from 1st to 2nd */
	/* 5/6 from 1st to 2nd */
	wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      } else if (splc > 1) {	/* interior segment */
	wprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
	/* 1/6 from 1st to 2nd */
	wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	/* 1/2 from 1st to 2nd */
	/* 5/6 from 1st to 2nd */
	wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
      } else {			/* 1/2 along */
	wprop (tv->aat, tv->Upr.Uline.endpos, 5.0, 1.0, 6.0);
	/* 1/6 along */
	wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
	wprop (tv->aat, tv->Upr.Uline.endpos, 2.0, 4.0, 6.0);
	/* 2/3 along */
	wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 5.0, 6.0);
	/* 5/6 along */
	wpos (tv->Upr.Uline.endpos);
	/* last segment */
      }
    } else if ((splc == splt) && (splc > 1)) {
      wpos (tv->aat);
      wprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	     tv->Upr.Uline.aradius, 1.0);
    } else if (splc > 1) {
      wprop (tv->aat, tv->Upr.Uline.endpos, 1 + tv->Upr.Uline.aradius,
	     1 - tv->Upr.Uline.aradius, 2.0);
      wprop (tv->aat, tv->Upr.Uline.endpos, 1.0, 1.0, 2.0);
      wprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	     1 + tv->Upr.Uline.aradius, 2.0);
    } else if (splt == 1) {
      wprop (tv->aat, tv->Upr.Uline.endpos, tv->Upr.Uline.aradius,
	     1 - tv->Upr.Uline.aradius, 1.0);
      wprop (tv->aat, tv->Upr.Uline.endpos, 1 - tv->Upr.Uline.aradius,
	     tv->Upr.Uline.aradius, 1.0);
      wpos (tv->Upr.Uline.endpos);
    } else {
      wprop (tv->aat, tv->Upr.Uline.endpos, tv->Upr.Uline.aradius,
	     1 - tv->Upr.Uline.aradius, 1.0);
      wpos (tv->Upr.Uline.endpos);
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
  primitive *tn, *tx;
  nametype *sx;
  int TEMP;
  primitive *With1;

  getlinespec (node, &lsp, &tn);
  sshade = node->shadedp;
  lth = qenv (node, XLlinethick, tn->lthick);
  switch (node->ptype) {

  case XLbox:
  case XBLOCK:
    initnesw ();
    nesw (node);
    if (node->ptype == XBLOCK) {
      v = drawn (node, lsp, -1.0);
    } else {
      v = drawn (node, lsp, node->Upr.Ubox.boxfill);
    }
    if (v) {
      pstfilloptions (node, lsp, 0.0);
      wcoord (&output, west, south);
      wcoord (&output, east, north);
      putchar ('\n');
    }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLellipse:
    if (drawn (node, lsp, node->Upr.Uellipse.efill)) {
      pstfilloptions (node, lsp, 0.0);
      wpos (node->aat);
      wcoord (&output, 0.5 * node->Upr.Uellipse.elwidth,
	      0.5 * node->Upr.Uellipse.elheight);
      putchar ('\n');
    }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLcircle:
    if (drawn (node, lsp, node->Upr.Ucircle.cfill)) {
      pstfilloptions (node, lsp, 0.0);
      wpos (node->aat);
      putchar ('{');
      wfloat (&output, node->Upr.Ucircle.radius / fsc);
      printf ("}\n");
    }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLarc:
    if (drawn (node, lsp, node->Upr.Uline.lfill)) {
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill && (vfill >= 0.0)) {
	node->Upr.Uline.lfill = vfill;
      }
      X0 = arcstart (node);
      X1 = arcend (node);
      if (bfill) {
	s = node->lthick;
	node->lthick = 0.0;
	pstfilloptions (node, lsp, node->Upr.Uline.endpos.ypos);
	pstwarc (node->aat, fabs (node->Upr.Uline.aradius),
		 posangle (X0, node->aat), posangle (X1, node->aat),
		 node->Upr.Uline.endpos.ypos);
	node->lthick = s;
      }
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	pstarcahead (node->aat, X0, ahnum (node->Upr.Uline.atype), soutline,
		     qenv (node, XLarrowht, node->Upr.Uline.height),
		     qenv (node, XLarrowwid, node->Upr.Uline.width), lth,
		     fabs (node->Upr.Uline.aradius),
		     node->Upr.Uline.endpos.ypos, &X0);
      }
      TEMP = ahlex (node->Upr.Uline.atype);
      if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	pstarcahead (node->aat, X1, ahnum (node->Upr.Uline.atype), soutline,
		     qenv (node, XLarrowht, node->Upr.Uline.height),
		     qenv (node, XLarrowwid, node->Upr.Uline.width), lth,
		     -fabs (node->Upr.Uline.aradius),
		     node->Upr.Uline.endpos.ypos, &X1);
      }
      sx = sshade;
      sshade = NULL;
      c = node->Upr.Uline.lfill;
      node->Upr.Uline.lfill = -1.0;
      pstfilloptions (node, lsp, node->Upr.Uline.endpos.ypos);
      sshade = sx;
      node->Upr.Uline.lfill = c;
      pstwarc (node->aat, fabs (node->Upr.Uline.aradius),
	       posangle (X0, node->aat), posangle (X1, node->aat),
	       node->Upr.Uline.endpos.ypos);
    }
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLline:
  case XLarrow:
    if (firstsegment (node)) {
      snode = node;
    }
    if (drawn (node, lsp, node->Upr.Uline.lfill)) {
      if (firstsegment (node)) {
	getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
	if (bfill && (vfill >= 0.0)) {
	  node->Upr.Uline.lfill = vfill;
	}
	if (bfill) {
	  s = tn->lthick;
	  tn->lthick = 0.0;
	  pstfilloptions (tn, lsp, 0.0);
	  tn->lthick = s;
	  wpos (node->aat);
	  tx = node;
	  while (tx != NULL) {
	    wpos (tx->Upr.Uline.endpos);
	    putchar ('\n');
	    tx = tx->son;
	  }
	}
	ahn = ahnum (tn->Upr.Uline.atype);
	if ((ahn == 0) || (ahn == 3)) {
	  TEMP = ahlex (tn->Upr.Uline.atype);
	  if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	    pstahead (&node->aat, node->Upr.Uline.endpos,
		      qenv (node, XLarrowht, tn->Upr.Uline.height),
		      qenv (node, XLarrowwid, tn->Upr.Uline.width),
		      qenv (node, XLlinethick, tn->lthick),
		      ahnum (tn->Upr.Uline.atype), soutline);
	  }
	  TEMP = ahlex (tn->Upr.Uline.atype);
	  if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	    pstahead (&tn->Upr.Uline.endpos, tn->aat,
		      qenv (node, XLarrowht, tn->Upr.Uline.height),
		      qenv (node, XLarrowwid, tn->Upr.Uline.width),
		      qenv (node, XLlinethick, tn->lthick),
		      ahnum (tn->Upr.Uline.atype), soutline);
	  }
	}
	sx = sshade;
	sshade = NULL;
	pstfilloptions (tn, lsp, 0.0);
	sshade = sx;
	if ((ahn != 0) && (ahn != 3)) {
	  switch (ahlex (tn->Upr.Uline.atype)) {

	  case XLEFTHEAD:
	    printf ("{<-}");
	    break;

	  case XDOUBLEHEAD:
	    printf ("{<->}");
	    break;

	  case XRIGHTHEAD:
	    printf ("{->}");
	    break;
	  }
	}
	bfill = false;
	wpos (node->aat);
      }
      wpos (node->Upr.Uline.endpos);
      putchar ('\n');
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	With1 = snode;
	if (With1->textp != NULL) {
	  pstwrtext (snode, With1->textp,
		     0.5 * (With1->Upr.Uline.endpos.xpos + With1->aat.xpos),
		     0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case XLmove:
    if (firstsegment (node)) {
      snode = node;
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	With1 = snode;
	if (With1->textp != NULL) {
	  pstwrtext (snode, With1->textp,
		     0.5 * (With1->Upr.Uline.endpos.xpos + With1->aat.xpos),
		     0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case XLspline:
    if (firstsegment (node)) {	/* first spline */
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill && (vfill >= 0.0)) {
	node->Upr.Uline.lfill = vfill;
      }
      if (bfill) {
	s = tn->lthick;
	tn->lthick = 0.0;
	pstfilloptions (tn, lsp, 0.0);
	tn->lthick = s;
	spltot = primdepth (node);
	splcount = spltot;
	printf ("%%\n");
	tx = node;
	while (tx != NULL) {
	  pstsplinesegment (tx, splcount, spltot);
	  splcount--;
	  tx = tx->son;
	}
	bfill = false;
      }
      spltot = primdepth (node);
      splcount = spltot;
      ahn = ahnum (tn->Upr.Uline.atype);
      if ((ahn == 0) || (ahn == 3)) {
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  pstahead (&tn->Upr.Uline.endpos, tn->aat,
		    qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width),
		    qenv (node, XLlinethick, tn->lthick),
		    ahnum (tn->Upr.Uline.atype), soutline);
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  pstahead (&node->aat, node->Upr.Uline.endpos,
		    qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width),
		    qenv (node, XLlinethick, tn->lthick),
		    ahnum (tn->Upr.Uline.atype), soutline);
	}
      }
      if (lsp != XLinvis) {
	sx = sshade;
	sshade = NULL;
	pstfilloptions (tn, lsp, 0.0);
	sshade = sx;
	if ((ahn != 0) && (ahn != 3)) {
	  switch (ahlex (tn->Upr.Uline.atype)) {

	  case XLEFTHEAD:
	    printf ("{<-}");
	    break;

	  case XDOUBLEHEAD:
	    printf ("{<->}");
	    break;

	  case XRIGHTHEAD:
	    printf ("{->}");
	    break;
	  }
	}
	printf ("%%\n");
      }
    }
    if (lsp != XLinvis) {
      pstsplinesegment (node, splcount, spltot);
    }
    splcount--;
    break;

  case XLstring:
    pstwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
    } else if (node->lthick >= 0.0) {
      printf ("\\psset{linewidth=");
      wfloat (&output, node->lthick);
      printf ("pt}%%\n");
    }
    break;
  }
}				/* pstdraw */
