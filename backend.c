							/* Output routines */
#include "dpic.h"
#include "lxcst.h"

extern boolean ismdistmax (double);
extern boolean isdistmax (double);
extern int ahlex (int);
extern int ahnum (int);
extern int Ceil (double);
extern int envinx (double);
extern int Floor (double);
extern double datan (double, double);
extern double linlen (double, double);
extern double Max (double, double);
extern double Min (double, double);
extern double principal (double, double);
extern double qenv (primitive *, int, double);
extern double venv (primitive *, int);
extern int lspec (int);
extern postype affang (postype, postype);
extern postype affine (double, double, postype, postype);
extern void checkjust (nametype *, boolean *, boolean *, boolean *,
		       boolean *);
extern void controls (void);
extern void ddash (void);
extern void deletename (nametype **);
extern void deletetree (primitive **);
extern void ddot (void);
extern void popgwarc (postype, double, double, double, double);
extern void pprop (postype, postype *, double, double, double);
extern void wcoord (FILE **, double, double);
extern void wfloat (FILE **, double);
extern void initnesw (void);
extern void newstr (nametype **);
extern void nesw (primitive *);
extern void wrand (void);
extern void wstring (FILE **, nametype *);

extern primitive *(findenv (primitive *));

							/* Test (bit 4) if this segment has no parent */
boolean
firstsegment (primitive * pr) {
  if (pr == NULL) {
    return false;
  } else {
    return (((pr->spec >> 3) & 1) == 0);
  }
}

							/* Test shaded, filled, dashed, dotted, solid */
boolean
drawn (primitive * node, int linesp, double fill) {
  if (node == NULL) {
    return false;
  } else if (node->shadedp != NULL) {
    return true;
  } else if ((linesp == XLdotted) || (linesp == XLdashed) ||
	     (linesp == XLsolid) || ((fill >= 0.0) && (fill <= 1.0))) {
    return true;
  } else {
    return false;
  }
}

							/* Shading parameters for linear objects */
void
getlinshade (primitive * nod, primitive ** tn, nametype ** ss, nametype ** so,
	     double *fillval, boolean * hshade) {
  primitive *With;
  *tn = nod;
  *ss = NULL;
  *so = NULL;
  *fillval = -1.0;
  while ((*tn) != NULL) {
    With = *tn;
    if (With->outlinep != NULL) {
      *so = With->outlinep;
    }
    *tn = (*tn)->son;
  }
  *tn = nod;
  if (*hshade) {
    *hshade = false;
  } else {
    while (nod != NULL) {
      With = nod;
      if (With->shadedp != NULL) {
	*ss = With->shadedp;
      }
      if ((With->Upr.Uline.lfill >= 0.0) && (With->Upr.Uline.lfill <= 1.0)) {
	*fillval = With->Upr.Uline.lfill;
      }
      *tn = nod;
      nod = nod->son;
    }
  }
  if (((*ss) != NULL) || ((*fillval) >= 0.0)) {
    *hshade = true;
  }
}

							/* Count the number of spline segments */
int
primdepth (primitive * ptmp) {
  int dep = 0;
  while (ptmp != NULL) {
    dep++;
    ptmp = ptmp->son;
  }
  return dep;
}

							/* Linespec from tail of a multisegment line */
void
getlinespec (primitive * nd, int *lsp, primitive ** lastnd) {
  primitive *tn = nd;

  if ((nd->ptype == XLarc) || (nd->ptype == XLarrow) ||
      (nd->ptype == XLline) || (nd->ptype == XLspline)) {
    while (tn->son != NULL) {
      tn = tn->son;
    }
  }
  *lastnd = tn;
  *lsp = lspec (tn->spec);
}

							/* Distance to P control point */
double
ahoffset (double ht, double wid, double lti) {
  if (wid == 0.0) {
    return 0.0;
  } else {
    return (lti * sqrt ((ht * ht) + (wid * wid / 4)) / wid);
  }
}

							/* Arrowhead control points */
void
dahead (postype point, postype shaft, double ht, double wid, double ltu, postype * P, postype * L, postype * R, postype * Px, postype * Lx, postype * Rx, postype * C, double *x, double *y) {	/* arrowhead ht and wid, user units */
							/* line thickness in diagram units */
							/* adj point, left, right pts, dir cosines */
  double h, v, po, t;

  *C = affang (shaft, point);	/* shaft direction cosines */
  po = ahoffset (ht, wid, ltu);
  if (po > ht) {
    po = ht;
  }
  *P = affine (po, 0.0, point, *C);	/* point adjusted by line thickness */
  h = ht - (ltu / 2);
  *x = h - po;
  if (ht == 0.0) {
    v = 0.0;
  } else {
    v = (wid / 2) * (*x) / ht;
  }
  *R = affine (h, v, point, *C);
  *L = affine (h, -v, point, *C);
  if ((*x) == 0.0) {
    t = 1.0;
  } else {
    t = ht / (*x);
  }
  Rx->xpos = point.xpos + ((R->xpos - P->xpos) * t);	/* right corner */
  Rx->ypos = point.ypos + ((R->ypos - P->ypos) * t);
  Lx->xpos = point.xpos + ((L->xpos - P->xpos) * t);	/* left corner  */
  Lx->ypos = point.ypos + ((L->ypos - P->ypos) * t);
  Px->xpos = (point.xpos + Lx->xpos + Rx->xpos) / 3;	/* type 3 center pt */
  Px->ypos = (point.ypos + Lx->ypos + Rx->ypos) / 3;
  if (ht == 0.0) {
    *y = 0.0;
  } else {
    *y = ht - po + (ltu * wid / ht / 4);
  }
}

							/* Parameters and positions for traced arrows*/
void
arcahead (postype C, postype point, int atyp, double ht, double wid,
	  double lth, double radius, double angle, postype * P, postype * Co,
	  postype * Ci, postype * Px, postype * Cox, postype * Cix,
	  postype * Ao, postype * Ai, double *ccw, double *lwi,
	  boolean * startarrow) {
  double lw, aa, bb, cc, s, v, d, b, t;
  postype Q;
  double TEMP, TEMP1;

  if (radius * angle > 0) {
    *ccw = 1.0;
  } else {
    *ccw = -1.0;
  }
  *startarrow = (radius >= 0);
  ht = fabs (ht);
  wid = fabs (wid);
  *lwi = (lth / 72) * scale;	/* line thickness in diagram units */
  lw = Min (fabs (*lwi), Min (wid / 2, ht / 2));
  wid = Max (wid, lw);
  radius = fabs (radius);
  d = sqrt ((ht * ht) + (wid * wid / 4));
							/* Centres of the wing arcs */
  if (d == 0) {
    Q.xpos = 1.0;
    Q.ypos = 0.0;
  } else {
    Q.xpos = ht / d;
    Q.ypos = (*ccw) * wid / 2 / d;
  }
  *Ci = affine (C.xpos - point.xpos, C.ypos - point.ypos, point, Q);
  Q.ypos = -Q.ypos;
  *Co = affine (C.xpos - point.xpos, C.ypos - point.ypos, point, Q);
							/* Outer corner */
  if (radius == 0) {
    t = 0.0;
  } else {
    t = Min (pi / 2, d / radius);
  }
  Q.xpos = cos (t);
  Q.ypos = (*ccw) * sin (t);
  *Ao = affine (point.xpos - Co->xpos, point.ypos - Co->ypos, *Co, Q);
  TEMP = Ao->xpos - C.xpos;
  TEMP1 = Ao->ypos - C.ypos;
							/* Make angle(C to Ai) = angle(C to Ao) */
  aa = (TEMP * TEMP) + (TEMP1 * TEMP1);
  bb = 2 * (((Ao->xpos - C.xpos) * (C.xpos - Ci->xpos)) +
	    ((Ao->ypos - C.ypos) * (C.ypos - Ci->ypos)));
  TEMP = C.xpos - Ci->xpos;
  TEMP1 = C.ypos - Ci->ypos;
  cc = (TEMP * TEMP) + (TEMP1 * TEMP1) - (radius * radius);
  s = (bb * bb) - (4 * aa * cc);
  if (s < 0) {
    v = aa;
  } else {
    v = (sqrt (s) - bb) / 2;
  }
  *Ai = *Ao;
  pprop (C, Ai, aa - v, v, aa);
							/* Point adjusted for line thickness */
  if (d == 0) {
    *P = point;
  } else if (radius == 0) {
    *P = C;
  } else if (ht == d) {
    *P = *Ao;
  } else {
    b = 2 * radius * sqrt ((1 - (ht / d)) / 2);	/* distance C to Co */
							/* Angle from Co-C to P, center C */
    Q.xpos = ((b * b) - (lw * lw) + (2 * lw * radius)) / (2 * b * radius);
    if (fabs (Q.xpos) > 1) {
      P->xpos = (Ao->xpos + Ai->xpos) / 2;
      P->ypos = (Ao->ypos + Ai->ypos) / 2;
    } else {
      Q.ypos = -(*ccw) * sqrt (1 - (Q.xpos * Q.xpos));
      *P = affine (radius * (Co->xpos - C.xpos) / b,
		   radius * (Co->ypos - C.ypos) / b, C, Q);
    }
  }
							/* Type 3 center and corners */
  if (radius == 0) {
    t = 0.0;
  } else {
    t = Min (pi / 2, (ht / radius) * 2 / 3);
  }
  Q.xpos = cos (t);
  Q.ypos = (*ccw) * sin (t);
  *Px = affine (point.xpos - C.xpos, point.ypos - C.ypos, C, Q);

  v = radius * radius;
  TEMP = Ao->xpos - Px->xpos;
  TEMP1 = Ao->ypos - Px->ypos;
  d = (TEMP * TEMP) + (TEMP1 * TEMP1);
  if (d == 0) {
    s = sqrt (v);
  } else if (v / d < 0.25) {
    s = 0.0;
  } else {
    s = sqrt ((v / d) - 0.25);
  }
  Cox->xpos =
    ((Px->xpos + Ao->xpos) / 2) - ((*ccw) * (Ao->ypos - Px->ypos) * s);
  Cox->ypos =
    ((Px->ypos + Ao->ypos) / 2) + ((*ccw) * (Ao->xpos - Px->xpos) * s);

  TEMP = Ai->xpos - Px->xpos;
  TEMP1 = Ai->ypos - Px->ypos;
  d = (TEMP * TEMP) + (TEMP1 * TEMP1);
  if (d == 0) {
    s = sqrt (v);
  } else if (v / d < 0.25) {
    s = 0.0;
  } else {
    s = sqrt ((v / d) - 0.25);
  }
  Cix->xpos =
    ((Px->xpos + Ai->xpos) / 2) - ((*ccw) * (Ai->ypos - Px->ypos) * s);
  Cix->ypos =
    ((Px->ypos + Ai->ypos) / 2) + ((*ccw) * (Ai->xpos - Px->xpos) * s);
}

							/* Start of arc when there is an initial arrowhead */
void
startarc (primitive * n, postype X0, double lth, double *h, double *w) {
  double x, y;

  *h = qenv (n, XLarrowht, n->Upr.Uline.height);
  *w = qenv (n, XLarrowwid, n->Upr.Uline.width);
  y = ahoffset (*h, *w, (lth / 72) * scale);
  if ((n->Upr.Uline.aradius * n->Upr.Uline.aradius) - (y * y) <= 0.0) {
    x = 0.0;
  } else {
    x =
      2 * atan (y /
		sqrt ((n->Upr.Uline.aradius * n->Upr.Uline.aradius) -
		      (y * y)));
  }
  if (n->Upr.Uline.endpos.ypos >= 0.0) {
    n->Upr.Uline.endpos.xpos += x;
    n->Upr.Uline.endpos.ypos -= x;
  } else {
    n->Upr.Uline.endpos.xpos -= x;
    n->Upr.Uline.endpos.ypos += x;
  }
}

							/* End of arc when there is a final arrowhead*/
void
endarc (primitive * n, postype X0, double lth, double *h, double *w) {
  double x, y;

  *h = qenv (n, XLarrowht, n->Upr.Uline.height);
  *w = qenv (n, XLarrowwid, n->Upr.Uline.width);
  y = ahoffset (*h, *w, (lth / 72) * scale);
  if ((n->Upr.Uline.aradius * n->Upr.Uline.aradius) - (y * y) <= 0.0) {
    x = 0.0;
  } else {
    x =
      2 * atan (y /
		sqrt ((n->Upr.Uline.aradius * n->Upr.Uline.aradius) -
		      (y * y)));
  }
  if (n->Upr.Uline.endpos.ypos >= 0.0) {
    n->Upr.Uline.endpos.ypos -= x;
  } else {
    n->Upr.Uline.endpos.ypos += x;
  }
}

							/* Arc start point */
postype
arcstart (primitive * n) {
  postype X;

  X.xpos =
    n->aat.xpos + (n->Upr.Uline.aradius * cos (n->Upr.Uline.endpos.xpos));
  X.ypos =
    n->aat.ypos + (n->Upr.Uline.aradius * sin (n->Upr.Uline.endpos.xpos));
  return X;
}

							/* Arc end point */
postype
arcend (primitive * n) {
  postype X;

  X.xpos =
    n->aat.xpos +
    (n->Upr.Uline.aradius *
     cos (n->Upr.Uline.endpos.xpos + n->Upr.Uline.endpos.ypos));
  X.ypos =
    n->aat.ypos +
    (n->Upr.Uline.aradius *
     sin (n->Upr.Uline.endpos.xpos + n->Upr.Uline.endpos.ypos));
  return X;
}

							/* Output \shortstack{line1\\ line2 ...}
							   if more than one text line, otherwise line1*/
void
texstacktext (primitive * np, nametype * tp) {
  nametype *tx;
  boolean A, B, L, R;
  double toff;

  if (tp == NULL) {
    return;
  }
  tx = tp->next_;
  if (tx != NULL) {
    printf ("\\shortstack{");
  }
  toff = (venv (np, XLtextoffset) / scale) * 72;
  do {
    checkjust (tp, &A, &B, &L, &R);
    if (L) {
      printf ("\\rlap{\\hbox to ");
      wfloat (&output, toff);
      printf ("bp{}");
    } else if (R) {
      printf ("\\llap{");
    }
    wstring (&output, tp);
    if (R) {
      printf ("\\hbox to ");
      wfloat (&output, toff);
      printf ("bp{}");
    }
    if (L || R) {
      putchar ('}');
    }
    tp = tp->next_;
    if (tp != NULL) {
      printf ("\\\\%%\n");
    }
  } while (tp != NULL);
  if (tx != NULL) {
    putchar ('}');
  }
}

							/* Output leftbrace x rightbrace */
void
wbrace (double x) {
  putchar ('{');
  wfloat (&output, x);
  putchar ('}');
}

							/* Output (x,y) */
void
wpair (FILE ** iou, double x, double y) {
  putc ('(', *iou);
  wfloat (iou, x);
  putc (',', *iou);
  wfloat (iou, y);
  putc (')', *iou);
}

							/* Output (x,y) with final scaling */
void
wcoord (FILE ** iou, double x, double y) {
  putc ('(', *iou);
  wfloat (iou, x / fsc);
  putc (',', *iou);
  wfloat (iou, y / fsc);
  putc (')', *iou);
}

							/* Output position as (x,y) with final scaling*/
void
wpos (postype pos) {
  wcoord (&output, pos.xpos, pos.ypos);
}

							/* Output P2 = (a*P1 + b*P2)/c (for arrows) */
void
wprop (postype p1, postype p2, double a, double b, double c) {
  pprop (p1, &p2, a, b, c);	/* Note: p2 is not var */
  wpos (p2);
}

							/* Angle of the line from C to V */
double
posangle (postype V, postype C) {
  return (datan (V.ypos - C.ypos, V.xpos - C.xpos));
}

/*
void
resetgs(primitive *node)
{ double x;
  if (gsocolor) {
      pdfwln(" 0 0 0 RG", 9, &cx);
      gsocolor = false; }
  if (gsfcolor) {
      pdfwln(" 0 0 0 rg", 9, &cx);
      gsfcolor = false; }
  if (gsgcolor) {
      pdfwln(" 0 g", 4, &cx);
      gsgcolor = false; }
  x = venv(node, XLlinethick);
  if (gslinethick != x) {
      pdfwfloat(x);
      pdfwln(" w", 2, &cx);
      gslinethick = x; }
  if (gslinecap != 0) {
      pdfwln(" 0 J", 4, &cx);
      gslinecap = 0; }
  if (gslinejoin != 0) {
      pdfwln(" 0 j", 4, &cx);
      gslinejoin = 0; }
  if ((gsdashw == 0) && (gsdashs == 0)) { return; }
  pdfwln(" [] 0 d", 7, &cx);
  gsdashw = 0.0;
  gsdashs = 0.0;
}
*/

/*--------------------------------------------------------------------*/

#include "ps.c"
#include "pst.c"
#include "pdf.c"
#include "svg.c"
#include "mfp.c"
#include "mpo.c"
#include "pgf.c"
#include "tex.c"
#include "xfig.c"

							/* Recursive output of the drawing-tree nodes*/
void
treedraw (primitive * node) {
  while (node != NULL) {
    switch (drawmode) {
    case TeX:
    case tTeX:
    case Pict2e:
      texdraw (node);
      break;
    case PDF:
      pdfdraw (node);
      break;
    case PGF:
      pgfdraw (node);
      break;
    case PSTricks:
      pstdraw (node);
      break;
    case MFpic:
      mfpdraw (node);
      break;
    case PS:
    case PSfrag:
      psdraw (node);
      break;
    case MPost:
      mpodraw (node);
      break;
    case SVG:
      svgdraw (node);
      break;
    case xfig:
      xfigdraw (node);
      break;
    }
    if (node->son != NULL) {
      treedraw (node->son);
    }
    if (drawmode == PDF) {
      resetgs (node);
    } else if ((drawmode == xfig) && (node->ptype == XBLOCK) &&
	       (node->direction == (-1))) {
      printf ("-6\n");
    }
    bfill = false;
    sshade = NULL;
    soutline = NULL;
    node = node->next_;
  }
}

							/* Set up scale parameters and draw the tree */
void
drawtree (double n, double s, double e, double w, primitive * eb) {
  double fsctmp;

  bfill = false;
  sshade = NULL;
  soutline = NULL;
  switch (drawmode) {
  case SVG:
    fsctmp = fsc;
    fsc /= dpPPI;
    svgprelude (n, s, e, w, (venv (eb, XLlinethick) / 72) * scale);
    treedraw (eb);
    svgpostlude ();
    fsc = fsctmp;
    break;
  case PGF:
    pgfprelude ();
    treedraw (eb);
    pgfpostlude ();
    break;
  case PSTricks:
    pstprelude (n, s, e, w);
    treedraw (eb);
    pstpostlude ();
    break;
  case MFpic:
    mfpprelude (n, s, e, w);
    treedraw (eb);
    mfppostlude ();
    break;
  case PS:
  case PSfrag:
    fsctmp = fsc;
    fsc /= 72;
    psprelude (n, s, e, w, venv (eb, XLlinethick));
    treedraw (eb);
    pspostlude ();
    fsc = fsctmp;
    break;
  case PDF:
    fsctmp = fsc;
    fsc /= 72;
    pdfprelude (n, s, e, w, venv (eb, XLlinethick));
    treedraw (eb);
    pdfpostlude ();
    fsc = fsctmp;
    break;
  case MPost:
    fsctmp = fsc;
    fsc /= 72;
    mpoprelude ();
    treedraw (eb);
    mpopostlude ();
    fsc = fsctmp;
    break;
  case xfig:
    xfigprelude ();
    treedraw (eb);
    break;
  case TeX:
  case tTeX:
  case Pict2e:
    if (!isdistmax (s)) {
      texprelude (n, s, e, w);
      treedraw (eb);
      texpostlude ();
    }
    break;
  }
}

/* End. */
