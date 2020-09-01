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
  if ((np->ptype == Xstring) && (np->name != NULL)) {
    putchar ('(');
    wstring (&output, np->name);
    putchar (')');
    }
  if (tp->nextname != NULL) {
    putchar ('{');
    texstacktext (np, tp); }
  else {
    checkjust (tp, &A, &B, &L, &R);
    if (A || B || L || R) {
      putchar ('[');
      if (A && L) { printf ("above right"); }
      else if (A && R) { printf ("above left"); }
      else if (B && L) { printf ("below right"); }
      else if (B && R) { printf ("below left"); }
      else if (A) { printf ("above"); }
      else if (B) { printf ("below"); }
      else if (L) { printf ("right"); }
      else if (R) { printf ("left"); }
      putchar ('=');
      /* Assume pgf built-in text offset = 4 bp */
      wfloat (&output, ((venv (np, Xtextoffset) * 72 / scale) - 4.0) / fsc);
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
    if (!ismdistmax (gslinethick)) { lthick = gslinethick; }
    else { lthick = 0.8; }
  }
  if ((lthick < 0.0) || (lthick == gslinethick)) { return; }
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
    }
  else if (atyp == 3) {
    wpos (Px);
    ddash ();
    wpos (Rx);
    ddash ();
    wpos (*point);
    ddash ();
    wpos (Lx);
    printf (" --cycle");
    /* wprop(P,L,x-y,y,x); ddash; wpos(P); ddash; wprop(P,R,x-y,y,x) */
    }
  else {
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

  if (lsp == Xinvis) { printf ("\\fill"); }
  else if (initial == 0) { printf ("\\dpicdraw"); }
  else { printf ("\\filldraw");
    /* initial = 1 or 3 for filled arrowheads */
    }
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
    break; }
  fill = ((long) floor ((fill * 1000000L) + 0.5)) / 1000000.0;
  if ((node->shadedp != NULL) || (sshade != NULL)) {
    printf ("[fill=");
    if (node->shadedp != NULL) { wstring (&output, node->shadedp); }
    else { wstring (&output, sshade); }
    sep = ','; }
  else if ((fill >= 0.0) && (fill <= 1.0)) {
    printf ("[fill=");
    if (fill == 0.0) { printf ("black"); }
    else if (fill == 0.25) { printf ("darkgray"); }
    else if (fill == 0.5) { printf ("gray"); }
    else if (fill == 0.75) { printf ("lightgray"); }
    else if (fill == 1.0) { printf ("white"); }
    else {
      printf ("white!");
      wfloat (&output, fill * 100);
      printf ("!black");
      }
    sep = ','; }
  else { sep = '['; }
  if ((initial == 1) || (initial == 3)) {
    printf ("%cline width=0bp", sep);
    sep = ','; }
  else if ((node->lthick >= 0.0) && (node->lthick != gslinethick)) {
    printf ("%cline width=", sep);
    wfloat (&output, node->lthick);
    printf ("bp");
    sep = ',';
    }
  if (((node->outlinep != NULL) || (soutline != NULL)) && (lsp != Xinvis)) {
    printf ("%cdraw=", sep);
    if (node->outlinep != NULL) { wstring (&output, node->outlinep); }
    else { wstring (&output, soutline); }
    if ((initial == 1) || (initial == 3)) {
      printf (",fill=");
      if (node->outlinep != NULL) { wstring (&output, node->outlinep); }
      else { wstring (&output, soutline); }
      }
    sep = ',';
    }
  if ((lsp == Xdashed) && (initial != 1) && (initial != 3)) {
    if (node->lparam <= 0) { printf ("%cdashed", sep); }
    else {
      printf ("%cdash pattern=on ", sep);
      wfloat (&output, node->lparam / fsc);
      printf ("in off ");
      wfloat (&output, node->lparam / fsc);
      printf ("in");
      }
    sep = ',';
    }
  else if (lsp == Xdotted) {
    if (node->lparam <= 0) { printf ("%cdotted", sep); }
    else {
      printf ("%ccap=round,dash pattern=on ", sep);
      printf ("0pt off ");
      wfloat (&output, node->lparam * 72 / fsc);
      printf ("bp");
      }
    sep = ',';
    }
  if (sep == ',') { putchar (']'); }
  else { putchar (' '); }
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
    popgwarc (Co, radius - lwi, posangle (Ao, Co), posangle (*P, Co), -ccw); }
  else if ((atyp == 3) && (lwi < ((wid - lwi) / 2))) {
    wpos (Px);
    popgwarc (Cix, radius, posangle (Px, Cix), posangle (Ai, Cix), ccw);
    popgwarc (Ci, radius, posangle (Ai, Ci), posangle (point, Ci), -ccw);
    popgwarc (Co, radius, posangle (point, Co), posangle (Ao, Co), ccw);
    popgwarc (Cox, radius, posangle (Ao, Cox), posangle (Px, Cox), -ccw); }
  else {
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

  getlinespec (node, &lsp, &tn);
  lth = qenv (node, Xlinethick, node->lthick);
  switch (node->ptype) {

  case Xbox:
  case Xblock:
    if (node->ptype == Xblock) { v = drawn (node, lsp, -1.0); }
    else { v = drawn (node, lsp, node->boxfill_); }
    if (v) {
      pgfstartdraw (0, node, lsp);
      pgfbox (node->aat, node->boxwidth_ / 2,
	      node->boxheight_ / 2, node->boxradius_);
      }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xellipse:
    if (drawn (node, lsp, node->ellipsefill_)) {
      pgfstartdraw (0, node, lsp);
      wpos (node->aat);
      printf (" ellipse (");
      wfloat (&output, node->ellipsewidth_ / 2 / fsc / 2.54);
      printf ("in and ");
      wfloat (&output, node->ellipseheight_ / 2 / fsc / 2.54);
      printf ("in)");
      pgfendpath ();
      }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xcircle:
    if (drawn (node, lsp, node->circlefill_)) {
      pgfstartdraw (0, node, lsp);
      wpos (node->aat);
      printf (" circle (");
      wfloat (&output, node->circleradius_ / fsc / 2.54);
      printf ("in)");
      pgfendpath ();
      }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xarc:
    if (drawn (node, lsp, -1.0)) {
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      if (bfill && (vfill >= 0.0)) { node->linefill_ = vfill; }
      X0 = arcstart (node);
      X1 = arcend (node);
      if (bfill) {
	    s = node->lthick;
	    node->lthick = 0.0;
	    pgfstartdraw (0, node, Xinvis);
	    node->lthick = s;
	    wpos (X0);
	    popgwarc (node->aat, fabs (node->aradius_),
		  posangle(X0, node->aat), posangle(X1, node->aat), node->arcangle_);
	    printf ("--cycle\n");
	    pgfendpath ();
        }
      if (lsp != Xinvis) {
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = sshade;
	      sshade = soutline;
	      pgfarcahead(node->aat, X0, ahnum (node->lineatype_),
		       soutline,
		       qenv(node, Xarrowht, node->lineheight_),
		       qenv(node, Xarrowwid, node->linewidth_), lth,
		       fabs(node->aradius_), node->arcangle_, &X0);
	      node->shadedp = sf;
	      sshade = sg;
	      }
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = sshade;
	      sshade = soutline;
	      pgfarcahead(node->aat, X1, ahnum (node->lineatype_),
		       soutline,
		       qenv(node, Xarrowht, node->lineheight_),
		       qenv(node, Xarrowwid, node->linewidth_), lth,
		       -fabs(node->aradius_), node->arcangle_, &X1);
	      node->shadedp = sf;
	      sshade = sg;
	      }
	    sf = node->shadedp;
	    node->shadedp = NULL;
	    sg = sshade;
	    sshade = NULL;
	    c = node->linefill_;
	    node->linefill_ = -1.0;
	    pgfstartdraw (0, node, lsp);
	    wpos (X0);
	    popgwarc(node->aat, fabs (node->aradius_),
		  posangle(X0, node->aat), posangle(X1, node->aat), node->arcangle_);
	    node->shadedp = sf;
	    sshade = sg;
	    node->linefill_ = c;
	    pgfendpath ();
        }
      }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xline:
  case Xarrow:
  case Xmove:
    if (firstsegment (node)) {
      snode = node;
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      lth = qenv (node, Xlinethick, tn->lthick);
      if (bfill) {
	    s = node->lthick;
	    node->lthick = 0.0;
	    pgfstartdraw (0, node, Xinvis);
	    node->lthick = s;
	    wpos (node->aat);
	    tx = node;
	    while (tx != NULL) {
	      ddash ();
	      wpos (tx->endpos_);
	      tx = tx->son;
	      }
	    printf ("--cycle\n");
	    pgfendpath ();
        }
      if (lsp != Xinvis) {
	    TEMP = ahlex (tn->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = sshade;
	      sshade = soutline;
	      pgfstartdraw (ahnum (node->lineatype_), node, lsp);
	      pgfahead (ahnum (tn->lineatype_), &node->aat,
		    node->endpos_,
		    qenv (node, Xarrowht, tn->lineheight_),
		    qenv (node, Xarrowwid, tn->linewidth_), lth);
	      node->shadedp = sf;
	      sshade = sg;
	      }
	    TEMP = ahlex (tn->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = sshade;
	      sshade = soutline;
	      pgfstartdraw (ahnum (node->lineatype_), node, lsp);
	      pgfahead (ahnum (tn->lineatype_), &tn->endpos_,
		    tn->aat, qenv (node, Xarrowht, tn->lineheight_),
		    qenv (node, Xarrowwid, tn->linewidth_), lth);
	      node->shadedp = sf;
	      sshade = sg;
	      }
	    sf = node->shadedp;
	    node->shadedp = NULL;
	    sg = sshade;
	    sshade = NULL;
	    s = node->linefill_;
	    node->linefill_ = -1.0;
	    c = vfill;
	    vfill = -1.0;
	    pgfstartdraw (0, node, lsp);
	    node->shadedp = sf;
	    sshade = sg;
	    node->linefill_ = s;
	    vfill = c;
	    wpos (node->aat);
        }
      }
    if (lsp != Xinvis) {
      ddash ();
      wpos (node->endpos_);
      if (node->son == NULL) { pgfendpath (); }
      }
    if (node->son == NULL) {
      while (snode != NULL) {
	    if (snode->textp != NULL) {
	      pgfwrtext (snode, snode->textp,
		     0.5 * (snode->endpos_.xpos + snode->aat.xpos),
		     0.5 * (snode->aat.ypos + snode->endpos_.ypos));
	      }
	    snode = snode->son;
        }
      }
    break;

  case Xspline:
    if (firstsegment (node)) {
      getlinshade (node, &tn, &sshade, &soutline, &vfill, &bfill);
      node->lparam = tn->lparam;
      node->lthick = tn->lthick;
      if (bfill) {
	    c = node->lthick;
	    node->lthick = 0.0;
	    sg = soutline;
	    soutline = sshade;
	    pgfstartdraw (0, node, Xinvis);
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
      if (lsp != Xinvis) {
	    spltot = primdepth (node);
	    splcount = spltot;
	    TEMP = ahlex (tn->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = sshade;
	      sshade = soutline;
	      pgfstartdraw (ahnum (tn->lineatype_), node, lsp);
	      pgfahead (ahnum (tn->lineatype_), &node->aat,
		    node->endpos_,
		    qenv (node, Xarrowht, tn->lineheight_),
		    qenv (node, Xarrowwid, tn->linewidth_),
		    qenv (node, Xlinethick, tn->lthick));
	      node->shadedp = sf;
	      sshade = sg;
	      }
	    TEMP = ahlex (tn->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      sf = tn->shadedp;
	      tn->shadedp = NULL;
	      sg = sshade;
	      sshade = soutline;
	      pgfstartdraw (ahnum (tn->lineatype_), tn, lsp);
	      pgfahead (ahnum (tn->lineatype_), &tn->endpos_,
		    tn->aat, qenv (node, Xarrowht, tn->lineheight_),
		    qenv (node, Xarrowwid, tn->linewidth_),
		    qenv (node, Xlinethick, tn->lthick));
	      tn->shadedp = sf;
	      sshade = sg;
	      }
	    deletename (&node->shadedp);
	    sshade = NULL;
	    node->linefill_ = -1.0;
	    vfill = -1.0;
	    pgfstartdraw (0, node, lsp);
        }
      }
    if (lsp != Xinvis) {
      splinesegment (node, splcount, spltot);
      if (splcount == 1) { pgfendpath (); }
      }
    splcount--;
    break;

  case Xstring:
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case XLaTeX:
    if (node->textp != NULL) {
      wstring (&output, node->textp);
      putchar ('\n'); }
    else if (node->lthick >= 0.0) { pgfsetthick (node->lthick); }
    break;
  }
}				/* pgfdraw */
