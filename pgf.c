/* pgf output routines */

void
pgfprelude (void) {
  printf ("\\begin{tikzpicture}[scale=2.54]\n");
  printf ("%% dpic version %s option -g for TikZ and PGF 1.01\n",VERSIONDATE);
  printf ("\\ifx\\dpiclw\\undefined\\newdimen\\dpiclw\\fi\n");
  printf ("\\global\\def\\dpicdraw{\\draw[line width=\\dpiclw]}\n");
  printf ("\\global\\def\\dpicstop{;}\n");
  printf ("\\dpiclw=0.8bp\n");
}

void
pgfpostlude (void) {
  printf ("\\end{tikzpicture}\n");
}

/* output substring */
/* np is always <> nil: */
void
pgfwrtext (primitive * np, nametype * tp, double x, double y) {
  boolean A, B, L, R;

  if (tp == NULL) {
    return;
  }
  printf ("\\draw ");
  wcoord (&output, x, y);
  printf (" node");
  if ((np->ptype == XLstring) && (np->name != NULL)) {
    putchar ('(');
    wstring (&output, np->name);
    putchar (')');
  }
  if (tp->next_ != NULL) {
    putchar ('{');
    texstacktext (np, tp);
  } else {
    checkjust (tp, &A, &B, &L, &R);
    if (A || B || L || R) {
      putchar ('[');
      if (A && L) {
	printf ("above right");
      } else if (A && R) {
	printf ("above left");
      } else if (B && L) {
	printf ("below right");
      } else if (B && R) {
	printf ("below left");
      } else if (A) {
	printf ("above");
      } else if (B) {
	printf ("below");
      } else if (L) {
	printf ("right");
      } else if (R) {
	printf ("left");
      }
      putchar ('=');
      /* Assume pgf built-in text offset = 4 bp */
      wfloat (&output, ((venv (np, XLtextoffset) * 72 / scale) - 4.0) / fsc);
      printf ("bp]");
    }
    putchar ('{');
    wstring (&output, tp);
  }
  printf ("};\n");
}

void
pgfendpath (void) {
  printf ("\\dpicstop\n");
}

void
pgfsetthick (double lthick) {
  if (ismdistmax (lthick)) {
    if (!ismdistmax (gslinethick)) {
      lthick = gslinethick;
    } else {
      lthick = 0.8;
    }
  }
  if ((lthick < 0.0) || (lthick == gslinethick)) {
    return;
  }
  printf ("\\dpiclw=");
  wfloat (&output, lthick);
  printf ("bp\n");
  gslinethick = lthick;
}

void
pgfbox (postype ctr, double halfwid, double halfht, double rad) {
  double r, h, v;

  if (rad == 0.0) {
    wcoord (&output, ctr.xpos - halfwid, ctr.ypos - halfht);
    printf (" rectangle ");
    wcoord (&output, ctr.xpos + halfwid, ctr.ypos + halfht);
    pgfendpath ();
    return;
  }
  r = Min (Min (rad, halfht), halfwid);
  h = halfwid - r;
  v = halfht - r;
  mpocorner (ctr, h, v, r, 1.0, 0.0);
  mpocorner (ctr, -h, v, r, 0.0, 1.0);
  mpocorner (ctr, -h, -v, r, -1.0, 0.0);
  mpocorner (ctr, h, -v, r, 0.0, -1.0);
  printf ("cycle");
  pgfendpath ();
}

void
pgfahead (int atyp, postype * point, postype shaft, double ht, double wid,
	  double lth) {
  postype P, L, R, Px, Lx, Rx, Q;
  double x, y;

  dahead (*point, shaft, ht, wid, (lth / 72) * scale, &P, &L, &R, &Px, &Lx,
	  &Rx, &Q, &x, &y);
  if (atyp == 0) {
    wprop (P, L, x - y, y, x);
    ddash ();
    wpos (P);
    ddash ();
    wprop (P, R, x - y, y, x);
    putchar ('\n');
  } else if (atyp == 3) {
    wpos (Px);
    ddash ();
    wpos (Rx);
    ddash ();
    wpos (*point);
    ddash ();
    wpos (Lx);
    printf (" --cycle");
    /* wprop(P,L,x-y,y,x); ddash; wpos(P); ddash; wprop(P,R,x-y,y,x) */
  } else {
    wpos (Rx);
    ddash ();
    wpos (*point);
    ddash ();
    wpos (Lx);
    printf (" --cycle");
  }
  pgfendpath ();
  *point = P;
}

void
pgfstartdraw (int initial, primitive * node, int lsp) {
  Char sep;
  double fill = -1.0;

  if (lsp == XLinvis) {
    printf ("\\fill");
  } else if (initial == 0) {
    printf ("\\dpicdraw");
  } else {
    printf ("\\filldraw");
    /* initial = 1 or 3 for filled arrowheads */
  }
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
  if ((node->shadedp != NULL) || (sshade != NULL)) {
    printf ("[fill=");
    if (node->shadedp != NULL) {
      wstring (&output, node->shadedp);
    } else {
      wstring (&output, sshade);
    }
    sep = ',';
  } else if ((fill >= 0.0) && (fill <= 1.0)) {
    printf ("[fill=");
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
      printf ("white!");
      wfloat (&output, fill * 100);
      printf ("!black");
    }
    sep = ',';
  } else {
    sep = '[';
  }
  if ((initial == 1) || (initial == 3)) {
    printf ("%cline width=0bp", sep);
    sep = ',';
  } else if ((node->lthick >= 0.0) && (node->lthick != gslinethick)) {
    printf ("%cline width=", sep);
    wfloat (&output, node->lthick);
    printf ("bp");
    sep = ',';
  }
  if (((node->outlinep != NULL) || (soutline != NULL)) && (lsp != XLinvis)) {
    printf ("%cdraw=", sep);
    if (node->outlinep != NULL) {
      wstring (&output, node->outlinep);
    } else {
      wstring (&output, soutline);
    }
    if ((initial == 1) || (initial == 3)) {
      printf (",fill=");
      if (node->outlinep != NULL) {
	wstring (&output, node->outlinep);
      } else {
	wstring (&output, soutline);
      }
    }
    sep = ',';
  }
  if ((lsp == XLdashed) && (initial != 1) && (initial != 3)) {
    if (node->lparam <= 0) {
      printf ("%cdashed", sep);
    } else {
      printf ("%cdash pattern=on ", sep);
      wfloat (&output, node->lparam / fsc);
      printf ("in off ");
      wfloat (&output, node->lparam / fsc);
      printf ("in");
    }
    sep = ',';
  } else if (lsp == XLdotted) {
    if (node->lparam <= 0) {
      printf ("%cdotted", sep);
    } else {
      printf ("%ccap=round,dash pattern=on ", sep);
      printf ("0pt off ");
      wfloat (&output, node->lparam * 72 / fsc);
      printf ("bp");
    }
    sep = ',';
  }
  if (sep == ',') {
    putchar (']');
  } else {
    putchar (' ');
  }
}

void
pgfarcahead (postype C, postype point, int atyp, nametype * sou, double ht,
	     double wid, double lth, double radius, double arcangle,
	     postype * P) {
  postype Q, Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi;
  boolean startarrow;

  arcahead (C, point, atyp, ht, wid, lth, radius, arcangle, P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  printf ("\\filldraw[line width=0bp");
  if (sou != NULL) {
    printf (",draw=");
    wstring (&output, soutline);
    printf (",fill=");
    wstring (&output, soutline);
  }
  putchar (']');
  /* Trace arrowhead outline */
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    wpos (*P);
    popgwarc (Ci, radius + lwi, posangle (*P, Ci), posangle (Ai, Ci), ccw);
    ddash ();
    wpos (Ai);
    popgwarc (Ci, radius, posangle (Ai, Ci), posangle (point, Ci), -ccw);
    popgwarc (Co, radius, posangle (point, Co), posangle (Ao, Co), ccw);
    ddash ();
    wprop (Ao, Co, radius - lwi, lwi, radius);
    popgwarc (Co, radius - lwi, posangle (Ao, Co), posangle (*P, Co), -ccw);
  } else if ((atyp == 3) && (lwi < ((wid - lwi) / 2))) {
    wpos (Px);
    popgwarc (Cix, radius, posangle (Px, Cix), posangle (Ai, Cix), ccw);
    popgwarc (Ci, radius, posangle (Ai, Ci), posangle (point, Ci), -ccw);
    popgwarc (Co, radius, posangle (point, Co), posangle (Ao, Co), ccw);
    popgwarc (Cox, radius, posangle (Ao, Cox), posangle (Px, Cox), -ccw);
  } else {
    Q.xpos = (Ao.xpos + Ai.xpos) / 2;
    Q.ypos = (Ao.ypos + Ai.ypos) / 2;
    wpos (Q);
    ddash ();
    wpos (Ai);
    popgwarc (Ci, radius, posangle (Ai, Ci), posangle (point, Ci), -ccw);
    popgwarc (Co, radius, posangle (point, Co), posangle (Ao, Co), ccw);
    ddash ();
    wpos (Q);
  }
  pgfendpath ();
}

void
pgfdraw (primitive * node) {
  int lsp;
  postype X0, X1;
  primitive *tn, *tx;
  double s, c, lth;
  boolean v;
  nametype *sf, *sg;
  int TEMP;
  primitive *With1;

  getlinespec (node, &lsp, &tn);
  lth = qenv (node, XLlinethick, node->lthick);
  switch (node->ptype) {

  case XLbox:
  case XBLOCK:
    if (node->ptype == XBLOCK) {
      v = drawn (node, lsp, -1.0);
    } else {
      v = drawn (node, lsp, node->Upr.Ubox.boxfill);
    }
    if (v) {
      pgfstartdraw (0, node, lsp);
      pgfbox (node->aat, node->Upr.Ubox.boxwidth / 2,
	      node->Upr.Ubox.boxheight / 2, node->Upr.Ubox.boxradius);
    }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLellipse:
    if (drawn (node, lsp, node->Upr.Uellipse.efill)) {
      pgfstartdraw (0, node, lsp);
      wpos (node->aat);
      printf (" ellipse (");
      wfloat (&output, node->Upr.Uellipse.elwidth / 2 / fsc / 2.54);
      printf ("in and ");
      wfloat (&output, node->Upr.Uellipse.elheight / 2 / fsc / 2.54);
      printf ("in)");
      pgfendpath ();
    }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLcircle:
    if (drawn (node, lsp, node->Upr.Ucircle.cfill)) {
      pgfstartdraw (0, node, lsp);
      wpos (node->aat);
      printf (" circle (");
      wfloat (&output, node->Upr.Ucircle.radius / fsc / 2.54);
      printf ("in)");
      pgfendpath ();
    }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLarc:
    if (drawn (node, lsp, -1.0)) {
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill && (vfill >= 0.0)) {
	node->Upr.Uline.lfill = vfill;
      }
      X0 = arcstart (node);
      X1 = arcend (node);
      if (bfill) {
	s = node->lthick;
	node->lthick = 0.0;
	pgfstartdraw (0, node, XLinvis);
	node->lthick = s;
	wpos (X0);
	popgwarc (node->aat, fabs (node->Upr.Uline.aradius),
		  posangle (X0, node->aat), posangle (X1, node->aat),
		  node->Upr.Uline.endpos.ypos);
	printf ("--cycle\n");
	pgfendpath ();
      }
      if (lsp != XLinvis) {
	TEMP = ahlex (node->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  sf = node->shadedp;
	  node->shadedp = NULL;
	  sg = sshade;
	  sshade = soutline;
	  pgfarcahead (node->aat, X0, ahnum (node->Upr.Uline.atype),
		       soutline,
		       qenv (node, XLarrowht, node->Upr.Uline.height),
		       qenv (node, XLarrowwid, node->Upr.Uline.width), lth,
		       fabs (node->Upr.Uline.aradius),
		       node->Upr.Uline.endpos.ypos, &X0);
	  node->shadedp = sf;
	  sshade = sg;
	}
	TEMP = ahlex (node->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  sf = node->shadedp;
	  node->shadedp = NULL;
	  sg = sshade;
	  sshade = soutline;
	  pgfarcahead (node->aat, X1, ahnum (node->Upr.Uline.atype),
		       soutline,
		       qenv (node, XLarrowht, node->Upr.Uline.height),
		       qenv (node, XLarrowwid, node->Upr.Uline.width), lth,
		       -fabs (node->Upr.Uline.aradius),
		       node->Upr.Uline.endpos.ypos, &X1);
	  node->shadedp = sf;
	  sshade = sg;
	}
	sf = node->shadedp;
	node->shadedp = NULL;
	sg = sshade;
	sshade = NULL;
	c = node->Upr.Uline.lfill;
	node->Upr.Uline.lfill = -1.0;
	pgfstartdraw (0, node, lsp);
	wpos (X0);
	popgwarc (node->aat, fabs (node->Upr.Uline.aradius),
		  posangle (X0, node->aat), posangle (X1, node->aat),
		  node->Upr.Uline.endpos.ypos);
	node->shadedp = sf;
	sshade = sg;
	node->Upr.Uline.lfill = c;
	pgfendpath ();
      }
    }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLline:
  case XLarrow:
  case XLmove:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      lth = qenv (node, XLlinethick, tn->lthick);
      if (bfill) {
	s = node->lthick;
	node->lthick = 0.0;
	pgfstartdraw (0, node, XLinvis);
	node->lthick = s;
	wpos (node->aat);
	tx = node;
	while (tx != NULL) {
	  ddash ();
	  wpos (tx->Upr.Uline.endpos);
	  tx = tx->son;
	}
	printf ("--cycle\n");
	pgfendpath ();
      }
      if (lsp != XLinvis) {
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  sf = node->shadedp;
	  node->shadedp = NULL;
	  sg = sshade;
	  sshade = soutline;
	  pgfstartdraw (ahnum (node->Upr.Uline.atype), node, lsp);
	  pgfahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos,
		    qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width), lth);
	  node->shadedp = sf;
	  sshade = sg;
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  sf = node->shadedp;
	  node->shadedp = NULL;
	  sg = sshade;
	  sshade = soutline;
	  pgfstartdraw (ahnum (node->Upr.Uline.atype), node, lsp);
	  pgfahead (ahnum (tn->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width), lth);
	  node->shadedp = sf;
	  sshade = sg;
	}
	sf = node->shadedp;
	node->shadedp = NULL;
	sg = sshade;
	sshade = NULL;
	s = node->Upr.Uline.lfill;
	node->Upr.Uline.lfill = -1.0;
	c = vfill;
	vfill = -1.0;
	pgfstartdraw (0, node, lsp);
	node->shadedp = sf;
	sshade = sg;
	node->Upr.Uline.lfill = s;
	vfill = c;
	wpos (node->aat);
      }
    }
    if (lsp != XLinvis) {
      ddash ();
      wpos (node->Upr.Uline.endpos);
      if (node->son == NULL) {
	pgfendpath ();
      }
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	With1 = snode;
	if (With1->textp != NULL) {
	  pgfwrtext (snode, With1->textp,
		     0.5 * (With1->Upr.Uline.endpos.xpos + With1->aat.xpos),
		     0.5 * (With1->aat.ypos + With1->Upr.Uline.endpos.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case XLspline:
    if (firstsegment (node)) {
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      node->lparam = tn->lparam;
      node->lthick = tn->lthick;
      if (bfill) {
	c = node->lthick;
	node->lthick = 0.0;
	sg = soutline;
	soutline = sshade;
	pgfstartdraw (0, node, XLinvis);
	node->lthick = c;
	soutline = sg;
	spltot = primdepth (node);
	splcount = spltot;
	tx = node;
	while (tx != NULL) {
	  splinesegment (tx, splcount, spltot);
	  splcount--;
	  tx = tx->son;
	}
	printf (" --cycle");
	pgfendpath ();
      }
      if (lsp != XLinvis) {
	spltot = primdepth (node);
	splcount = spltot;
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XLEFTHEAD)) {
	  sf = node->shadedp;
	  node->shadedp = NULL;
	  sg = sshade;
	  sshade = soutline;
	  pgfstartdraw (ahnum (tn->Upr.Uline.atype), node, lsp);
	  pgfahead (ahnum (tn->Upr.Uline.atype), &node->aat,
		    node->Upr.Uline.endpos,
		    qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width),
		    qenv (node, XLlinethick, tn->lthick));
	  node->shadedp = sf;
	  sshade = sg;
	}
	TEMP = ahlex (tn->Upr.Uline.atype);
	if ((TEMP == XDOUBLEHEAD) || (TEMP == XRIGHTHEAD)) {
	  sf = tn->shadedp;
	  tn->shadedp = NULL;
	  sg = sshade;
	  sshade = soutline;
	  pgfstartdraw (ahnum (tn->Upr.Uline.atype), tn, lsp);
	  pgfahead (ahnum (tn->Upr.Uline.atype), &tn->Upr.Uline.endpos,
		    tn->aat, qenv (node, XLarrowht, tn->Upr.Uline.height),
		    qenv (node, XLarrowwid, tn->Upr.Uline.width),
		    qenv (node, XLlinethick, tn->lthick));
	  tn->shadedp = sf;
	  sshade = sg;
	}
	deletename (&node->shadedp);
	sshade = NULL;
	node->Upr.Uline.lfill = -1.0;
	vfill = -1.0;
	pgfstartdraw (0, node, lsp);
      }
    }
    if (lsp != XLinvis) {
      splinesegment (node, splcount, spltot);
      if (splcount == 1) {
	pgfendpath ();
      }
    }
    splcount--;
    break;

  case XLstring:
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
    } else if (node->lthick >= 0.0) {
      pgfsetthick (node->lthick);
    }
    break;
  }
}				/* pgfdraw */
