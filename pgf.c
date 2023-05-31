/* pgf output routines */

void
pgfprelude (void) {
  printf ("\\begin{tikzpicture}[scale=2.54]%%\n");
  printf ("%% dpic version %s option -g for TikZ and PGF 1.01\n",VERSIONDATE);
  printf ("\\ifx\\dpiclw\\undefined\\newdimen\\dpiclw\\fi\n");
  printf ("\\global\\def\\dpicdraw{\\draw[line width=\\dpiclw]}\n");
  printf ("\\global\\def\\dpicstop{;}\n");
  printf ("\\dpiclw=0.8bp\n");
}

void
pgfpostlude(void)
{ printf("\\end{tikzpicture}%%\n");
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, "pgfpostlude done\n"); }
#endif
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
      wfloat (&output, (venv (np, Xtextoffset) * 72 / scale) - 4.0);
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
pgfsetthick (double lthk) {
  if (!ismdistmax (lthk)) { if (lthk < 0.0) { lthk = -lthk; } }
  else if (!ismdistmax (gslinethick)) { lthk = gslinethick; }
  else { lthk = 0.8; }
  if ((lthk < 0.0) || (lthk == gslinethick)) { return; }
  printf ("\\dpiclw=");
  wfloat (&output, lthk);
  printf ("bp\n");
  gslinethick = lthk;
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
#ifdef DDEBUG
  if (debuglevel > 0) {
      fprintf(log_, " dahead values: point:");
      wcoord(&log_, point->xpos, point->ypos);
      fprintf(log_, " ;shaft:"); wcoord(&log_, shaft.xpos, shaft.ypos);
      fprintf(log_, "\n ht="); wfloat(&log_, ht);
      fprintf(log_, " ;wid="); wfloat(&log_, wid);
      fprintf(log_, " ;lth="); wfloat(&log_, lth);
      fprintf(log_, " ;fsc="); wfloat(&log_, fsc);
      fprintf(log_, "\n P:"); wcoord(&log_, P.xpos, P.ypos);
      fprintf(log_, " ;L:"); wcoord(&log_, L.xpos, L.ypos);
      fprintf(log_, " ;R:"); wcoord(&log_, R.xpos, R.ypos);
      fprintf(log_, "\n x="); wfloat(&log_, x);
      fprintf(log_, " y="); wfloat(&log_, y);
      putc('\n', log_);
  }
#endif
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
pgfstartdraw(int initial, primitive *node, int lsp, double ltk)
{ Char sep;
  double fill = -1.0;
  if (lsp == Xinvis) { printf("\\fill"); }
  else if (initial == 0) { printf("\\dpicdraw"); }
  else { printf("\\filldraw"); }
      /* initial = 1 or 3 for filled arrowheads */
  switch (node->ptype) {
  case Xblock: /* blank case */
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
    break;
  }
  fill = ((long)floor((fill * 1000000L) + 0.5)) / 1000000.0;
  if ((node->shadedp != NULL) || (shadestr != NULL)) {
      printf("[fill=");
      if (node->shadedp != NULL) { wstring(&output, node->shadedp); }
      else { wstring(&output, shadestr); }
      sep = ','; }
  else if ((fill >= 0.0) && (fill <= 1.0)) {
      printf("[fill=");
      if (fill == 0.0) { printf("black"); }
      else if (fill == 0.25) { printf("darkgray"); }
      else if (fill == 0.5) { printf("gray"); }
      else if (fill == 0.75) { printf("lightgray"); }
      else if (fill == 1.0) { printf("white"); }
      else {
	    printf("white!");
	    wfloat(&output, fill * 100);
	    printf("!black");
        }
      sep = ','; }
  else { sep = '['; }
  if ((initial == 1) || (initial == 3)) {
      printf("%cline width=0bp", sep);
      sep = ','; }
  else if ((ltk >= 0.0) && (ltk != gslinethick)) {
      printf("%cline width=", sep);
      wfloat(&output, ltk);
      printf("bp");
      sep = ','; }
  if (((node->outlinep != NULL) || (outlinestr != NULL)) && (lsp != Xinvis)) {
      printf("%cdraw=", sep);
      if (node->outlinep != NULL) { wstring(&output, node->outlinep); }
      else { wstring(&output, outlinestr); }
      if ((initial == 1) || (initial == 3)) {
	    printf(",fill=");
	    if (node->outlinep != NULL) { wstring(&output, node->outlinep); }
	    else { wstring(&output, outlinestr); }
        }
      sep = ',';
      }
  if ((lsp == Xdashed) && (initial != 1) && (initial != 3)) {
      if (node->lparam <= 0) { printf("%cdashed", sep); }
      else {
	    printf("%cdash pattern=on ", sep);
	    wfloat(&output, node->lparam / fsc);
	    printf("in off ");
	    wfloat(&output, node->lparam / fsc);
	    printf("in");
        }
      sep = ',';
    }
  else if (lsp == Xdotted) {
      if (node->lparam <= 0) {
	  printf("%cdotted", sep);
      }
      else {
	  printf("%ccap=round,dash pattern=on ", sep);
	  printf("0pt off ");
	  wfloat(&output, node->lparam * 72 / fsc);
	  printf("bp");
      }
      sep = ',';
    }
  if (sep == ',') { putchar(']'); } else { putchar(' '); }
}

void
pgfarcahead (postype C, postype point, int atyp, nametype * sou, double ht,
	     double wid, double lth, double radius, double arcangle,
	     postype * P) {
  postype Q, Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi, t;
  boolean startarrow;

  arcahead (C, point, atyp, ht, wid, lth, radius, arcangle, P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
  printf ("\\filldraw[line width=0bp");
  if (sou != NULL) {
    printf (",draw=");
    wstring (&output, outlinestr);
    printf (",fill=");
    wstring (&output, outlinestr);
    }
  putchar (']');
                                                 /* Trace arrowhead outline */
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
      wpos(Px);
      popgwarc(Ci, Px, Ai, lwi, ccw);
      ddash(); wpos(Ai);
      popgwarc(Ci, Ai, point, 0.0, -ccw);
      popgwarc(Co, point, Ao, 0.0, ccw);
      ddash();
      t = distance(Co, Ao); wprop(Ao, Co, t - lwi, lwi, t);
      popgwarc(Co, Ao, Px, 0.0, -ccw); }
  else if (atyp == 3) {
      wpos(Px);
      popgwarc(Cix, Px, Ai, 0.0, ccw);
      popgwarc(Ci, Ai, point, 0.0, -ccw);
      popgwarc(Co, point, Ao, 0.0, ccw);
      popgwarc(Cox, Ao, Px, 0.0, -ccw); }
  else {
      Q.xpos = (Ao.xpos + Ai.xpos) / 2;
      Q.ypos = (Ao.ypos + Ai.ypos) / 2;
      wpos(Q); ddash(); wpos(Ai);
      popgwarc(Ci, Ai, point, 0.0, -ccw);
      popgwarc(Co, point, Ao, 0.0, ccw);
      ddash(); wpos(Q); }
  pgfendpath ();
}

void
pgfdraw (primitive * node) {
  int lsp;
  postype X0, X1;
  primitive *lastseg, *tx;
  double s, c, lth;
  boolean v;
  nametype *sf, *sg;
  int TEMP;

  getlinespec (node, &lsp, &lastseg);
  lth = qenv (node, Xlinethick, lastseg->lthick);
  switch (node->ptype) {
  case Xbox:
  case Xblock:
    if (node->ptype == Xblock) { v = drawn (node, lsp, -1.0); }
    else { v = drawn (node, lsp, node->boxfill_); }
    if (v) {
      pgfstartdraw (0, node, lsp, lth);
      pgfbox (node->aat, node->boxwidth_ / 2,
	      node->boxheight_ / 2, node->boxradius_);
      }
    pgfwrtext (node, node->textp, node->aat.xpos, node->aat.ypos);
    break;

  case Xellipse:
    if (drawn (node, lsp, node->ellipsefill_)) {
      pgfstartdraw (0, node, lsp, lth);
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
      pgfstartdraw (0, node, lsp, lth);
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
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      if (hasfill && (fillfrac >= 0.0)) { node->linefill_ = fillfrac; }
      X0 = arcstart (node);
      X1 = arcend (node);
      if (hasfill) {
	    s = node->lthick;
	    node->lthick = 0.0;
	    pgfstartdraw (0, node, Xinvis, 0.0);
	    node->lthick = s;
	    wpos (X0);
	    popgwarc (node->aat, X0, X1, 0, node->arcangle_);
	    printf ("--cycle\n");
	    pgfendpath ();
        }
      if (lsp != Xinvis) {
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = shadestr;
	      shadestr = outlinestr;
	      pgfarcahead(node->aat, X0, ahnum (node->lineatype_),
		       outlinestr,
		       qenv(node, Xarrowht, node->lineheight_),
		       qenv(node, Xarrowwid, node->linewidth_), lth,
		       fabs(node->aradius_), node->arcangle_, &X0);
	      node->shadedp = sf;
	      shadestr = sg;
	      }
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = shadestr;
	      shadestr = outlinestr;
	      pgfarcahead(node->aat, X1, ahnum (node->lineatype_),
		       outlinestr,
		       qenv(node, Xarrowht, node->lineheight_),
		       qenv(node, Xarrowwid, node->linewidth_), lth,
		       -fabs(node->aradius_), node->arcangle_, &X1);
	      node->shadedp = sf;
	      shadestr = sg;
	      }
	    sf = node->shadedp;
	    node->shadedp = NULL;
	    sg = shadestr;
	    shadestr = NULL;
	    c = node->linefill_;
	    node->linefill_ = -1.0;
	    pgfstartdraw (0, node, lsp, lth);
	    wpos (X0);
	    popgwarc(node->aat, X0, X1, 0, node->arcangle_);
	    node->shadedp = sf;
	    shadestr = sg;
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
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      lth = qenv (node, Xlinethick, lastseg->lthick);
      if (hasfill) {
	    s = node->lthick;
	    node->lthick = 0.0;
	    pgfstartdraw (0, node, Xinvis, 0.0);
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
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = shadestr;
		  if (ahnum(node->lineatype_) == 0) { shadestr = NULL; }
		  else { shadestr = outlinestr; }
	      pgfstartdraw (ahnum (node->lineatype_), node, lsp, lth);
	      pgfahead (ahnum (lastseg->lineatype_), &node->aat,
		    node->endpos_,
		    qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_), lth);
	      node->shadedp = sf;
	      shadestr = sg;
	      }
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = shadestr;
		  if (ahnum(node->lineatype_) == 0) { shadestr = NULL; }
		  else { shadestr = outlinestr; }
	      pgfstartdraw (ahnum (node->lineatype_), node, lsp, lth);
	      pgfahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
		    lastseg->aat, qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_), lth);
	      node->shadedp = sf;
	      shadestr = sg;
	      }
	    sf = node->shadedp;
	    node->shadedp = NULL;
	    sg = shadestr;
	    shadestr = NULL;
	    s = node->linefill_;
	    node->linefill_ = -1.0;
	    c = fillfrac;
	    fillfrac = -1.0;
	    pgfstartdraw (0, node, lsp, lth);
	    node->shadedp = sf;
	    shadestr = sg;
	    node->linefill_ = s;
	    fillfrac = c;
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
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      node->lparam = lastseg->lparam;
      node->lthick = lastseg->lthick;
      if (hasfill) {
	    c = node->lthick;
	    node->lthick = 0.0;
	    sg = outlinestr;
	    outlinestr = shadestr;
	    pgfstartdraw (0, node, Xinvis, 0.0);
	    node->lthick = c;
	    outlinestr = sg;
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
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      sf = node->shadedp;
	      node->shadedp = NULL;
	      sg = shadestr;
	      shadestr = outlinestr;
	      pgfstartdraw (ahnum (lastseg->lineatype_), node, lsp, lth);
	      pgfahead (ahnum (lastseg->lineatype_), &node->aat,
		    node->endpos_,
		    qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_),
		    qenv (node, Xlinethick, lastseg->lthick));
	      node->shadedp = sf;
	      shadestr = sg;
	      }
	    TEMP = ahlex (lastseg->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      sf = lastseg->shadedp;
	      lastseg->shadedp = NULL;
	      sg = shadestr;
	      shadestr = outlinestr;
	      pgfstartdraw (ahnum (lastseg->lineatype_), lastseg, lsp, lth);
	      pgfahead (ahnum (lastseg->lineatype_), &lastseg->endpos_,
		    lastseg->aat, qenv (node, Xarrowht, lastseg->lineheight_),
		    qenv (node, Xarrowwid, lastseg->linewidth_),
		    qenv (node, Xlinethick, lastseg->lthick));
	      lastseg->shadedp = sf;
	      shadestr = sg;
	      }
	    deletename (&node->shadedp);
	    shadestr = NULL;
	    node->linefill_ = -1.0;
	    fillfrac = -1.0;
	    pgfstartdraw (0, node, lsp, lth);
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
