							/* Output routines for MetaPost */
void
mpoprelude (void) {
  printstate++;
  printf ("%% dpic version %s option -s for MetaPost\n",VERSIONDATE);
  printf ("beginfig(%d)\n", printstate);
  printf ("def lcbutt=linecap:=butt enddef;\n");
  printf ("def lcsq=linecap:=squared enddef;\n");
  printf ("def lcrnd=linecap:=rounded enddef;\n");
  printf ("def ljmit=linejoin:=mitered enddef;\n");
  printf ("def lcolr= enddef; def drw=draw enddef; def X=;enddef;\n");
  printf ("lcbutt; ljmit;\n");
}

void
mpopostlude (void) {
  printf ("endfig;\n");
}

void
mpowrtext (primitive * np, nametype * tp, double x, double y) {
  boolean A, B, L, R;

  if (tp == NULL) { return; }
  if (tp->nextname != NULL) {
    printf ("label");
    printf ("(btex ");
    texstacktext (np, tp);
    printf (" etex,");
    wcoord (&output, x, y);
    printf (") X\n");
    return;
    }
  printf ("label");
  checkjust (tp, &A, &B, &L, &R);
  if (A && L) { printf (".urt"); }
  else if (A && R) { printf (".ulft"); }
  else if (B && L) { printf (".lrt"); }
  else if (B && R) { printf (".llft"); }
  else if (A) { printf (".top"); }
  else if (B) { printf (".bot"); }
  else if (L) { printf (".rt"); }
  else if (R) { printf (".lft"); }
  printf ("(btex ");
  wstring (&output, tp);
  printf (" etex,");
  wcoord (&output, x, y);
  printf (") X\n");
}

void
mposetthick (double lthk) {
  if (ismdistmax (lthk)) {
    if (!ismdistmax (gslinethick)) { lthk = gslinethick; }
    else { lthk = 0.8; }
    }
  if ((lthk < 0.0) || (lthk == gslinethick)) { return; }
  printf ("pickup pencircle scaled ");
  wfloat (&output, lthk);
  printf ("bp;\n");
  gslinethick = lthk;
}

void
mpolinecap (int lsp) {
  switch (lsp) {

  case Xdashed:
    printf ("lcsq;\n");
    break;

  case Xdotted:
    printf ("lcrnd;\n");
    break;
  }
}

void
addcolor (nametype * sp, double fillv) {
  printf (" withcolor ");
  if (sp != NULL) { wstring (&output, sp); }
  else {
    wfloat (&output, fillv);
    printf ("white");
    }
}

void
mpodashdot (int lsp, double param, nametype * op) {
  if (lsp == Xdashed) {
    printf (" dashed evenly");
    if (param > 0) {
      printf (" scaled ");
      wfloat (&output, param / fsc / 3);
      }
    if (op != NULL) { addcolor (op, -1.0); }
    printf (" X lcbutt;\n");
    return;
  }
  if (lsp == Xdotted) {
    printf (" dashed withdots scaled ");
    if (param <= 0) { printf ("0.8"); }
    else { wfloat (&output, param / fsc / 5); }
    if (op != NULL) { addcolor (op, -1.0); }
    printf (" X lcbutt;\n");
    return;
  }
  if (op != NULL) { addcolor (op, -1.0); printf (" X\n"); }
  else { printf (" X\n"); }
}

void
mpocorner (postype ctr, double x, double y, double r, double ct, double st) {
  wcoord (&output, ctr.xpos + x + (ct * r), ctr.ypos + y + (st * r));
  controls ();
  wcoord (&output, ctr.xpos + x + (ct * r) - (st * r * SPLT),
	  ctr.ypos + y + (st * r) + (ct * r * SPLT));
  wrand ();
  wcoord (&output, ctr.xpos + x + (ct * r * SPLT) - (st * r),
	  ctr.ypos + y + (st * r * SPLT) + (ct * r));
  ddot ();
  wcoord (&output, ctr.xpos + x - (st * r), ctr.ypos + y + (ct * r));
  ddash ();
}

void
mpobox (char * initial, postype ctr, double halfwid, double halfht,
	double rad) {
  double r, h, v;

  fputs (initial, stdout);
  if (rad == 0.0) {
    wcoord (&output, ctr.xpos - halfwid, ctr.ypos + halfht);
    ddash ();
    wcoord (&output, ctr.xpos + halfwid, ctr.ypos + halfht);
    ddash ();
    wcoord (&output, ctr.xpos + halfwid, ctr.ypos - halfht);
    ddash ();
    wcoord (&output, ctr.xpos - halfwid, ctr.ypos - halfht);
    ddash (); }
  else {
    r = Min (Min (rad, halfht), halfwid);
    h = halfwid - r;
    v = halfht - r;
    mpocorner (ctr, h, v, r, 1.0, 0.0);
    mpocorner (ctr, -h, v, r, 0.0, 1.0);
    mpocorner (ctr, -h, -v, r, -1.0, 0.0);
    mpocorner (ctr, h, -v, r, 0.0, -1.0);
    }
  printf ("cycle");
}

void
mpoellipse (char * initial, postype ctr, double halfwid, double halfht) {
  fputs (initial, stdout);
  wcoord (&output, ctr.xpos + halfwid, ctr.ypos);
  controls ();
  wcoord (&output, ctr.xpos + halfwid, ctr.ypos + (halfht * SPLT));
  wrand ();
  wcoord (&output, ctr.xpos + (halfwid * SPLT), ctr.ypos + halfht);
  ddot ();
  wcoord (&output, ctr.xpos, ctr.ypos + halfht);
  controls ();
  wcoord (&output, ctr.xpos - (halfwid * SPLT), ctr.ypos + halfht);
  wrand ();
  wcoord (&output, ctr.xpos - halfwid, ctr.ypos + (halfht * SPLT));
  ddot ();
  wcoord (&output, ctr.xpos - halfwid, ctr.ypos);
  controls ();
  wcoord (&output, ctr.xpos - halfwid, ctr.ypos - (halfht * SPLT));
  wrand ();
  wcoord (&output, ctr.xpos - (halfwid * SPLT), ctr.ypos - halfht);
  ddot ();
  wcoord (&output, ctr.xpos, ctr.ypos - halfht);
  controls ();
  wcoord (&output, ctr.xpos + (halfwid * SPLT), ctr.ypos - halfht);
  wrand ();
  wcoord (&output, ctr.xpos + halfwid, ctr.ypos - (halfht * SPLT));
  ddot ();
  printf ("cycle");
}

void
mpoahead (int atyp, postype * point, postype shaft, double ht, double wid,
	  double lth, nametype * sou) {
  postype P, L, R, Px, Lx, Rx, Q;
  double x, y;

  dahead (*point, shaft, ht, wid, (lth / 72) * scale, &P, &L, &R, &Px, &Lx,
	  &Rx, &Q, &x, &y);
  if (atyp == 0) {
    printf ("drw ");
    wprop (P, L, x - y, y, x);
    ddash ();
    wpos (P);
    ddash ();
    wprop (P, R, x - y, y, x);
    if (sou != NULL) { addcolor (sou, -1.0); }
    printf (" X\n"); }
  else {
    printf ("fill ");
    wpos (Rx);
    ddash ();
    wpos (*point);
    ddash ();
    wpos (Lx);
    if (atyp == 3) { ddash (); wpos (Px); }
    printf ("\n --cycle");
    if (sou != NULL) { addcolor (sou, -1.0); }
    printf (" X\n");
    }
  *point = P;
}

void
mpoarcahead (postype C, postype point, int atyp, nametype * sou, double ht,
	     double wid, double lth, double radius, double arcangle,
	     postype * P) {
  postype Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi;
  boolean startarrow;

  arcahead (C, point, atyp, ht, wid, lth, radius, arcangle, P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  printf ("fill ");
  wpos (Ai);
  popgwarc (Ci, Ai,point, 0,-ccw);
  popgwarc (Co, point,Ao, 0, ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    ddash ();
    wprop (Co, Ao, lwi, radius-lwi, radius);
    popgwarc (Co, Ao, Px, 0, -ccw);
    popgwarc (Ci, Px, Ai, lwi, ccw); }
  else if (atyp == 3) {
    popgwarc (Cox, Ao,Px, 0, -ccw);
    popgwarc (Cix, Px,Ai, 0,  ccw);
    }
  printf (" --cycle");
  addcolor (sou, 0.0);
  printf (" X\n");
}

void
splinesegment (primitive * tv, int splc, int splt) {
  if (tv == NULL) { return; }
  if (splt == 1) {
    wpos (tv->aat);
    ddash ();
    wpos (tv->endpos_);
    return;
    }
  if (ismdistmax (tv->aradius_)) {
    if (splc == splt) {		/* 1st seg */
      wpos (tv->aat);
      ddash ();
      wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      controls ();
      wprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
      return;
      }
    if (splc > 1) {		/* interior segment */
      wrand ();
      wprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
      ddot ();
      wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
      controls ();
      wprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
      return;
      }
    wrand ();
    wprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
    ddot ();
    wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    ddash ();
    wpos (tv->endpos_);
							    /* last segment */
    return;
    }
  if ((splc == splt) && (splc > 1)) {
    wpos (tv->aat);
    controls ();
    wprop (tv->aat, tv->endpos_, 1 - tv->aradius_, tv->aradius_, 1.0);
    return;
  }
  if (splc > 1) {
    wrand ();
    wprop (tv->aat, tv->endpos_, 1 + tv->aradius_, 1 - tv->aradius_, 2.0);
    ddot ();
    wprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    controls ();
    wprop (tv->aat, tv->endpos_, 1 - tv->aradius_, 1 + tv->aradius_, 2.0);
    return;
    }
  wrand ();
  wprop (tv->aat, tv->endpos_, tv->aradius_, 1 - tv->aradius_, 1.0);
  ddot ();
  wpos (tv->endpos_);
}

							/* node is always <> nil: */
void
mpodraw (primitive * node) {
  int lsp;
  postype X0, X1;
  primitive *lastseg, *tx, *primp;
  double lth;
  int TEMP;

  getlinespec (node, &lsp, &lastseg);
  lth = qenv (node, Xlinethick, node->lthick);
  switch (node->ptype) {

  case Xbox:
  case Xblock:
    if (node->ptype == Xbox) {
      if ((node->shadedp != NULL) || ((node->boxfill_ >= 0.0) &&
	    (node->boxfill_ <= 1.0))) {
	    mpobox ("fill ", node->aat, node->boxwidth_ / 2,
		  node->boxheight_ / 2, node->boxradius_);
	    addcolor (node->shadedp, node->boxfill_);
	    printf (" X\n");
        }
      if (lsp != Xinvis) {
	    mposetthick (node->lthick);
	    mpolinecap (lsp);
	    mpobox ("drw ", node->aat, node->boxwidth_ / 2,
		    node->boxheight_ / 2, node->boxradius_);
	    mpodashdot (lsp, node->lparam, node->outlinep);
        }
      }
    mpowrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xellipse:
    if ((node->shadedp != NULL) ||
	((node->ellipsefill_ >= 0.0)
	 && (node->ellipsefill_ <= 1.0))) {
      mpoellipse ("fill ", node->aat, node->ellipsewidth_ / 2,
		  node->ellipseheight_ / 2);
      addcolor (node->shadedp, node->ellipsefill_);
      printf (" X\n");
      }
    if (lsp != Xinvis) {
      mposetthick (node->lthick);
      mpolinecap (lsp);
      mpoellipse ("drw ", node->aat, node->ellipsewidth_ / 2,
		  node->ellipseheight_ / 2);
      mpodashdot (lsp, node->lparam, node->outlinep);
      }
    mpowrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xcircle:
    if ((node->shadedp != NULL) ||
	((node->circlefill_ >= 0.0)
	 && (node->circlefill_ <= 1.0))) {
      printf ("fill fullcircle scaled ");
      wfloat (&output, node->circleradius_ * 2 / fsc);
      printf (" shifted ");
      wpos (node->aat);
      addcolor (node->shadedp, node->circlefill_);
      printf (" X\n");
      }
    if (lsp != Xinvis) {
      mposetthick (node->lthick);
      mpolinecap (lsp);
      printf ("drw fullcircle scaled ");
      wfloat (&output, node->circleradius_ * 2 / fsc);
      printf (" shifted ");
      wpos (node->aat);
      mpodashdot (lsp, node->lparam, node->outlinep);
      }
    mpowrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xarc:
    X0 = arcstart (node);
    X1 = arcend (node);
    getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
    if (hasfill) {
      mposetthick (0.0);
      printf ("fill ");
      wpos (X0);
      popgwarc(node->aat, X0, X1, 0, node->arcangle_);
      printf (" --cycle");
      addcolor (shadestr, fillfrac);
      printf (" X\n");
      fillfrac = -1.0;
      shadestr = NULL;
      }
    if (lsp != Xinvis) {
      mposetthick (lth);
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	    mpoarcahead (node->aat, X0, ahnum (node->lineatype_), outlinestr,
		     qenv (node, Xarrowht, node->lineheight_),
		     qenv (node, Xarrowwid, node->linewidth_), lth,
		     fabs (node->aradius_), node->arcangle_, &X0);
        }
      TEMP = ahlex (node->lineatype_);
      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	    mpoarcahead (node->aat, X1, ahnum (node->lineatype_), outlinestr,
		     qenv (node, Xarrowht, node->lineheight_),
		     qenv (node, Xarrowwid, node->linewidth_), lth,
		     -fabs (node->aradius_), node->arcangle_, &X1);
        }
      mpolinecap (lsp);
      printf ("drw ");
      wpos (X0);
      popgwarc (node->aat, X0, X1, 0, node->arcangle_);
      mpodashdot (lsp, node->lparam, node->outlinep);
      }
    mpowrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xline:
  case Xarrow:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill) {
	mposetthick (0.0);
	printf ("fill ");
	wpos (node->aat);
	tx = node;
	while (tx != NULL) {
	  ddash ();
	  wpos (tx->endpos_);
	  tx = tx->son;
	}
	printf (" --cycle");
	addcolor (shadestr, fillfrac);
	printf (" X\n");
	fillfrac = -1.0;
	shadestr = NULL;
      }
      lth = qenv (node, Xlinethick, lastseg->lthick);
      if (lsp != Xinvis) {
	mposetthick (lth);
	TEMP = ahlex (lastseg->lineatype_);
	if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	  mpoahead (ahnum (lastseg->lineatype_), &node->aat,
		    node->endpos_,
		    qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_), lth,
		    outlinestr);
	}
	TEMP = ahlex (lastseg->lineatype_);
	if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	  mpoahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
		    lastseg->aat, qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_), lth,
		    outlinestr);
	}
	mpolinecap (lsp);
	printf ("drw ");
	wpos (node->aat);
      }
    }
    if (lsp != Xinvis) {
      ddash ();
      wpos (node->endpos_);
      if (node->son == NULL) {
	mpodashdot (lsp, node->lparam, node->outlinep);
      }
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	primp = snode;
	if (primp->textp != NULL) {
	  mpowrtext (node, primp->textp,
		     0.5 * (primp->endpos_.xpos + primp->aat.xpos),
		     0.5 * (primp->endpos_.ypos + primp->aat.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case Xmove:
    if (firstsegment (node)) {
      snode = node;
    }
    if (node->son == NULL) {
      while (snode != NULL) {
	primp = snode;
	if (primp->textp != NULL) {
	  mpowrtext (node, primp->textp,
		     0.5 * (primp->endpos_.xpos + primp->aat.xpos),
		     0.5 * (primp->endpos_.ypos + primp->aat.ypos));
	}
	snode = snode->son;
      }
    }
    break;

  case Xspline:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill) {
	spltot = primdepth (node);
	splcount = spltot;
	mposetthick (0.0);
	printf ("fill ");
	tx = node;
	while (tx != NULL) {
	  splinesegment (tx, splcount, spltot);
	  splcount--;
	  tx = tx->son;
	}
	printf (" --cycle");
	addcolor (shadestr, fillfrac);
	printf (" X\n");
	fillfrac = -1.0;
	shadestr = NULL;
      }
      lth = qenv (lastseg, Xlinethick, lastseg->lthick);
      if (lsp != Xinvis) {
	spltot = primdepth (node);
	splcount = spltot;
	mposetthick (lth);
	TEMP = ahlex (lastseg->lineatype_);
	if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	  mpoahead (ahnum (lastseg->lineatype_), &node->aat,
		    node->endpos_,
		    qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_), lth,
		    outlinestr);
	}
	TEMP = ahlex (lastseg->lineatype_);
	if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	  mpoahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
		    lastseg->aat, qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_), lth,
		    outlinestr);
	}
	deletename (&node->shadedp);
	shadestr = NULL;
	node->linefill_ = -1.0;
	fillfrac = -1.0;
	mpolinecap (lsp);
	printf ("drw ");
      }
    }
    if (lsp != Xinvis) {
      splinesegment (node, splcount, spltot);
      if (splcount == 1) {
	mpodashdot (lsp, node->lparam, node->outlinep);
	while (snode != NULL) {
	  primp = snode;
	  if (primp->textp != NULL) {
	    mpowrtext (node, primp->textp,
		       0.5 * (primp->endpos_.xpos + primp->aat.xpos),
		       0.5 * (primp->endpos_.ypos + primp->aat.ypos));
	  }
	  snode = snode->son;
	}
      }
    }
    splcount--;
    break;

  case Xstring:
    mpowrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n');
    } else if (node->lthick >= 0.0) {
      mposetthick (node->lthick);
    }
    break;
  }
}				/* mpodraw */
