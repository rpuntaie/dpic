#define EXTRN extern
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
extern double linlen(double, double);
extern double distance(postype, postype);
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
extern void fatal (int);
extern void popgwarc (postype, postype, postype, double, double);
extern void pprop (postype, postype *, double, double, double);
extern void wcoord (FILE **, double, double);
extern void wfloat (FILE **, double);
extern void initnesw (void);
extern void markerror (int);
extern void newstr (nametype **);
extern void nesw (primitive *);
extern void setangles(double *, double *, postype, double, double, double,
                      double);
extern void wrand (void);
extern void wstring (FILE **, nametype *);
#ifdef DDEBUG
extern int ordp(void *);
#endif

extern primitive *(findenv (primitive *));

							/* Test (bit 4) if this segment has no parent */
boolean
firstsegment (primitive * pr) {
  if (pr == NULL) { return false; }
  else { return (((pr->spec >> 3) & 1) == 0); }
}

#ifdef DDEBUG
void
logpos(char *lbl, postype P)
{ fprintf(log_, "\n %s:(", lbl);
  wfloat(&log_, P.xpos);
  putc(',', log_);
  wfloat(&log_, P.ypos);
  putc(')', log_);
}

void
logspec(int sp)
{ switch (sp & 7) {
  case 1: fprintf(log_, "solid"); break;
  case 2: fprintf(log_, "dotted"); break;
  case 3: fprintf(log_, "dashed"); break;
  case 4: fprintf(log_, "invis"); break;
  }
}
#endif

							/* Test shaded, filled, dashed, dotted, solid */
boolean
drawn (primitive * node, int linesp, double fill)
{ boolean dr;
  if (((fill >= 0.0) && (fill <= 1.0)) || (linesp == Xdotted) ||
      (linesp == Xdashed) || (linesp == Xsolid)) { dr = true; }
  else { dr = false;
    if ((node->ptype == Xarrow) || (node->ptype == Xline) ||
	  (node->ptype == Xspline)) {
	  while (node != NULL) {
	    if (node->shadedp != NULL) { dr = true; node = NULL; }
	    else { node = node->son; }
	    }
      }
    else { dr = (node->shadedp != NULL); }
    }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, " drawn(%d,%d(", ordp(node), linesp);
    logspec(linesp - Xlinetype);
    fprintf(log_, "),");
    wfloat(&log_, fill);
    fprintf(log_, ")=%s\n", dr ? " TRUE" : "FALSE");
    }
#endif
  return dr;
}

							/* Shading parameters for linear objects */
void
getlinshade (primitive *nod,
             primitive **tn, nametype **ss, nametype **so,
	         double *fillval, boolean *hshade) {
  primitive *primp;
  *tn = nod;
  *ss = NULL;
  *so = NULL;
  *fillval = -1.0;
  while ((*tn) != NULL) {
    primp = *tn;
    if (primp->outlinep != NULL) { *so = primp->outlinep; }
    *tn = (*tn)->son;
    }
  *tn = nod;
  if (*hshade) { *hshade = false; }
  else {
    while (nod != NULL) {
      primp = nod;
      if (primp->shadedp != NULL) { *ss = primp->shadedp; }
      if ((primp->linefill_ >= 0.0) && (primp->linefill_ <= 1.0)) {
	    *fillval = primp->linefill_; }
      *tn = nod;
      nod = nod->son;
      }
    }
  if (((*ss) != NULL) || ((*fillval) >= 0.0)) { *hshade = true; }
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

  if ((nd->ptype == Xarc) || (nd->ptype == Xarrow) ||
      (nd->ptype == Xline) || (nd->ptype == Xspline)) {
    while (tn->son != NULL) { tn = tn->son; }
  }
  *lastnd = tn;
  *lsp = lspec (tn->spec);
}

							/* Distance to P control point */
double
ahoffset (double ht, double wid, double lti) {
  if (wid == 0.0) { return 0.0; }
  else { return (lti * sqrt ((ht * ht) + (wid * wid / 4)) / wid); }
}

							/* Arrowhead control points */
void
dahead (postype point, postype shaft,
    double ht, double wid, double ltu,
    postype * P, postype * L, postype * R, postype * Px, postype * Lx,
    postype * Rx, postype * C,
    double *x, double *y) {	/* arrowhead ht and wid, user units */
							/* line thickness in diagram units */
							/* adj point, left, right pts, dir cosines */
  double h, v, po, t;
#ifdef DDEBUG
  if (debuglevel > 0) {
      fprintf(log_, " dahead input:\n");
      fprintf(log_, " ht="); wfloat(&log_, ht);
      fprintf(log_, ";wid="); wfloat(&log_, wid);
      fprintf(log_, ";ltu="); wfloat(&log_, ltu);
      fprintf(log_, ";fsc="); wfloat(&log_, fsc);
      logpos("point", point);
      logpos("shaft", shaft);
      putc('\n', log_);
  }
#endif
    *C = affang(shaft, point);                   /* shaft direction cosines */
    po = Min(ahoffset(ht, wid, ltu), ht);
    *P = affine(po, 0.0, point, *C);    /* point adjusted by line thickness */
    h = ht - (ltu / 2);
    *x = h - po;
    if (ht == 0.0) { v = 0.0; } else { v = (wid / 2) * (*x) / ht; }
    *R = affine(h, v, point, *C);
    *L = affine(h, -v, point, *C);
    if ((*x) == 0.0) { t = 1.0; } else { t = ht / (*x); }
    Rx->xpos = point.xpos + ((R->xpos - P->xpos) * t);      /* right corner */
    Rx->ypos = point.ypos + ((R->ypos - P->ypos) * t);
    Lx->xpos = point.xpos + ((L->xpos - P->xpos) * t);      /* left corner  */
    Lx->ypos = point.ypos + ((L->ypos - P->ypos) * t);
    Px->xpos = (point.xpos + Lx->xpos + Rx->xpos) / 3;  /* type 3 center pt */
    Px->ypos = (point.ypos + Lx->ypos + Rx->ypos) / 3;
    if (distance(*Px, point) < distance(*P, point)) { *Px = *P; }
    if (ht == 0.0) { *y = 0.0; } else { *y = ht - po + (ltu * wid / ht / 4); }
#ifdef DDEBUG
  if (debuglevel > 0) {
    fprintf(log_, " dahead out: po=");
    wfloat(&log_, po);
    logpos("P", *P);
    logpos("L", *L);
    logpos("R", *R);
    logpos("C", *C);
    logpos("Px", *Px);
    logpos("Lx", *Lx);
    logpos("Rx", *Rx);
    fprintf(log_, "\n x="); wfloat(&log_, *x);
    fprintf(log_, " y="); wfloat(&log_, *y);
    putc('\n', log_);
    }
#endif
}
                                            /* Intersection of two circles */
postype
Cintersect(postype C1, double r1, postype C2, double r2, double ccw)
{ postype X, R;
  double dx, dy, cls, cq, f;
  dx = C1.xpos - C2.xpos;
  dy = C1.ypos - C2.ypos;
  cls = (dx * dx) + (dy * dy);
  if (cls == 0) {
     R.xpos = C1.xpos;
     R.ypos = C1.ypos;
     }
  else {
     cq = (cls + (r1 * r1) - (r2 * r2)) / 2;
     f = cq / cls;
     X.xpos = ((1 - f) * C1.xpos) + (f * C2.xpos);
     X.ypos = ((1 - f) * C1.ypos) + (f * C2.ypos);
     f = sqrt(Max((cls * r1 * r1) - (cq * cq),0.0)) / cls;
     R.xpos = X.xpos + (dy * f * ccw);
     R.ypos = X.ypos - (dx * f * ccw);
     }
  return R;
}

postype
ArcCtr(postype AA, postype P, postype CC, double ccw) {
  postype A, C, Q, Ax, Rt;
  double asq, rsq, br;
  A.xpos = AA.xpos - P.xpos; A.ypos = AA.ypos - P.ypos;
  C.xpos = CC.xpos - P.xpos; C.ypos = CC.ypos - P.ypos;
  asq = (A.xpos * A.xpos) + (A.ypos * A.ypos);
  rsq = (C.xpos * C.xpos) + (C.ypos * C.ypos);
  if ((asq == 0) || (rsq == 0)) { Rt = CC; }
  else {
    Q.ypos = ccw * ((A.xpos * C.xpos) + (A.ypos * C.ypos)) / sqrt(asq * rsq);
    Q.xpos = sqrt(1 - (Q.ypos * Q.ypos));
    br = sqrt(Max(0.0, 1 - (asq / (rsq * 4))));
    Ax.xpos = (AA.xpos + P.xpos) / 2; Ax.ypos = (AA.ypos + P.ypos) / 2;
    Rt = affine(br * C.xpos, br * C.ypos, Ax, Q);
  }
  return Rt;
}

void                         /* Parameters and positions for traced arc arrows*/
arcahead(postype C, postype Point, int atyp, double ht, double wid,
	 double lth, double radius, double angle, postype *P, postype *Co,
	 postype *Ci, postype *Px, postype *Cox, postype *Cix,
     postype *Ao, postype *Ai, double *ccw, double *lwi,
     boolean *startarrow)
{ double t, ha;
  postype Q, Ac;
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, " arcahead input:");
      logpos("C", C);
      fprintf(log_, "\n atyp="); fprintf(log_, "%d", atyp);
      fprintf(log_, ";ht="); wfloat(&log_, ht);
      fprintf(log_, ";wid="); wfloat(&log_, wid);
      fprintf(log_, ";lth="); wfloat(&log_, lth);
      fprintf(log_, ";radius="); wfloat(&log_, radius);
      fprintf(log_, ";angle="); wfloat(&log_, angle);
      putc('(', log_); wfloat(&log_, angle * 180 / pi); fprintf(log_, ")\n"); }
#endif
  if (radius * angle > 0) { *ccw = 1.0; } else { *ccw = -1.0; }
  *startarrow = (radius >= 0);
  radius = fabs(radius);
  ht = Min( 2*radius, fabs(ht));
  if (atyp == 0) { wid = Min( radius,fabs(wid) ); } else { wid = fabs(wid); }
  *lwi = (fabs(lth) / 72) * scale;        /* line thickness in diagram units */
  wid = Max(wid, *lwi);
                                                       /* head angle, Ao, Ai */
  if (radius == 0) { ha = 0.0; } else { ha = ht / radius; }
  Q.xpos = cos(ha); Q.ypos = (*ccw) * sin(ha);
  Ac = affine(Point.xpos - C.xpos, Point.ypos - C.ypos, C, Q);
  *Ao = Ac; pprop(C, Ao, wid / (-2), radius + (wid / 2), radius);
  *Ai = Ac; pprop(C, Ai, wid / 2, radius - (wid / 2), radius);
                                                                  /* Co, Ci */
  *Co = ArcCtr(*Ao, Point, C, *ccw);
  *Ci = ArcCtr(*Ai, Point, C, *ccw);
                                       /* Point adjusted for line thickness */
  if (wid == 0) { *P = *Ao; } else if (radius == 0) { *P = C; }
  else {
    t = (Min(wid, *lwi) / wid) * ht / radius;
    Q.xpos = cos(t);
    Q.ypos = (*ccw) * sin(t);
    *P = affine(Point.xpos - C.xpos, Point.ypos - C.ypos, C, Q); }
                                                     /* Type 0 intersection */
  if (atyp == 0) {
    *Px = Cintersect(*Co, radius - (*lwi), *Ci, radius + (*lwi), *ccw);
    if (distance(*Px,Point) > distance(Ac,Point)) { *Px = Ac; }
    *Cox = *Px; *Cix = *Px; }
                                                /* Other center and corners */
  else {
    if (radius == 0) { t = 0.0; } else { t = Min( pi/2, (ht/radius)*2/3 ); }
    Q.xpos = cos(t); Q.ypos = (*ccw) * sin(t);
    *Px = affine(Point.xpos - C.xpos, Point.ypos - C.ypos, C, Q);
    if (distance(*Px,Point) < distance(*P,Point)) { *Px = *P; }
    *Cox = ArcCtr(*Px, *Ao, *Co, -(*ccw));
    *Cix = ArcCtr(*Px, *Ai, *Ci, -(*ccw));
    }
#ifdef DDEBUG
  if (debuglevel > 0) { fprintf(log_, "\n arcahead out:\n");
    fprintf(log_, " lwi="); wfloat(&log_, *lwi);
    logpos("C", C);
    logpos("Point", Point);
    logpos("Ao", *Ao);
    logpos("Ai", *Ai);
    logpos("Ac", Ac);
    logpos("Co", *Co);
    logpos("Ci", *Ci);
    logpos("P", *P);
    logpos("Px", *Px);
    logpos("Cox", *Cox);
    logpos("Cix", *Cix);
    putc('\n', log_);
    }
#endif
}
							/* Arc start point */
postype
arcstart (primitive * n) {
  postype X;
  X.xpos = n->aat.xpos + (n->aradius_ * cos (n->startangle_));
  X.ypos = n->aat.ypos + (n->aradius_ * sin (n->startangle_));
  return X;
}

							/* Arc end point */
postype
arcend (primitive * n) {
  postype X;
  X.xpos = n->aat.xpos + (n->aradius_ * cos (n->startangle_ + n->arcangle_));
  X.ypos = n->aat.ypos + (n->aradius_ * sin (n->startangle_ + n->arcangle_));
  return X;
}

							/* Output \shortstack{line1\\ line2 ...}
							   if more than one text line, otherwise line1*/
void
texstacktext (primitive * np, nametype * tp) {
  nametype *tx;
  boolean A, B, L, R;
  double toff;

  if (tp == NULL) { return; }
  tx = tp->nextname;
  if (tx != NULL) { printf ("\\shortstack{"); }
  toff = (venv (np, Xtextoffset) / scale) * 72;
  do {
    checkjust (tp, &A, &B, &L, &R);
    if (L) {
      printf ("\\rlap{\\hbox to ");
      wfloat (&output, toff);
      printf ("bp{}"); }
    else if (R) { printf ("\\llap{"); }
    wstring (&output, tp);
    if (R) {
      printf ("\\hbox to ");
      wfloat (&output, toff);
      printf ("bp{}"); }
    if (L || R) { putchar ('}'); }
    tp = tp->nextname;
    if (tp != NULL) { printf ("\\\\%%\n"); }
  } while (tp != NULL);
  if (tx != NULL) { putchar ('}'); }
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
    if (node->son != NULL) { treedraw (node->son); }
    if (drawmode == PDF) { resetgs (node); }
    else if ((drawmode == xfig) && (node->ptype == Xblock) &&
	       (node->direction == (-1))) { printf ("-6\n"); }
    hasfill = false;
    shadestr = NULL;
    outlinestr = NULL;
    node = node->nextname;
  }
}

							/* Set up scale parameters and draw the tree */
void
drawtree (double n, double s, double e, double w, primitive * eb) {
  double fsctmp;

  hasfill = false;
  shadestr = NULL;
  outlinestr = NULL;
  switch (drawmode) {
  case SVG:
    fsctmp = fsc;
    fsc /= dpPPI;
    svgprelude (n, s, e, w, (venv (eb, Xlinethick) / 72) * scale);
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
    psprelude (n, s, e, w, venv (eb, Xlinethick));
    treedraw (eb);
    pspostlude ();
    fsc = fsctmp;
    break;
  case PDF:
    fsctmp = fsc;
    fsc /= 72;
    pdfprelude (n, s, e, w, venv (eb, Xlinethick));
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
