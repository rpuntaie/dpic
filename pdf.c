/* Output routines for PDF */

void
pdfstream (char * s, int ls, nametype ** strm)
{
  int i, ll;
  int s0 = 1;
  nametype *ns, *outbuffer;
  while (ls > 0) {
    outbuffer = *strm;
    if (outbuffer->len + ls - 1 <= CHBUFSIZ) { ll = ls; }
    else { ll = CHBUFSIZ - outbuffer->len + 1; }
    for (i = 0; i < ll; i++) {
      outbuffer->segmnt[outbuffer->len + i] = s[s0 + i - 1]; }
    s0 += ll;
    outbuffer->len += ll;
    if ((*strm)->len > CHBUFSIZ) {
	  newstr (&ns);
	  ns->segmnt = malloc (sizeof (chbufarray));
      if (ns->segmnt==NULL){ fatal(9); }
	  (*strm)->nextname = ns;
	  *strm = ns;
	  }
    ls -= ll;
    }
}

void
pdfendline (nametype ** strm)
{
  pdfstream ("\n", 1, strm);
}

void
pdfwln (char * s, int ln, nametype ** strm)
{
  pdfstream (s, ln, strm);
  pdfendline (strm);
}

void
addbytes (int n)
{
  if (pdfobjcount == 0) { pdfoffs[0] = n; }
  else { pdfoffs[pdfobjcount] = pdfoffs[pdfobjcount - 1] + n; }
  pdfobjcount++;
}

void
pdfprelude (double n, double s, double e, double w, double lth)
{
  double wx, ex, nx, sx;

  pdfobjcount = 0;
  printf ("%%PDF-1.4\n");
  printf ("%% Creator: dpic version %s option -d for PDF\n", VERSIONDATE);
  addbytes (62);		/* pdfobjcount must be 1 here */

  /*          123456789 123456789 123456789 123456789 123456789 123456789 12345 */
  /*                   1.        2.        3.        4.        5.        6.    */
  printf ("%d 0 obj << /Type /Catalog /Pages 2 0 R >> endobj\n", pdfobjcount);
  addbytes (49);

  printf ("%d 0 obj << /Type /Pages /Kids [ 3 0 R ] /Count 1 >> endobj\n",
	  pdfobjcount);
  addbytes (59);

  printf ("%d 0 obj << /Type /Page /Parent 2 0 R\n", pdfobjcount);
  wx = (w / fsc) - (lth / 2);
  ex = (e / fsc) + (lth / 2);
  nx = (n / fsc) + (lth / 2);
  sx = (s / fsc) - (lth / 2);
  printf (" /MediaBox [ ");
  printf ("%5d %5d %5d %5d ]\n",
	  Floor (((long) floor ((wx * 1000000L) + 0.5)) / 1000000.0),
	  Floor (((long) floor ((sx * 1000000L) + 0.5)) / 1000000.0),
	  Ceil (((long) floor ((ex * 1000000L) + 0.5)) / 1000000.0),
	  Ceil (((long) floor ((nx * 1000000L) + 0.5)) / 1000000.0));
  printf (" /Contents 6 0 R\n");
  printf (" /Resources <<\n");
  printf ("   /ProcSet %d 0 R\n", pdfobjcount + 1);
  printf ("   /Font << /F1 %d 0 R >>\n", pdfobjcount + 2);
  printf ("   >>\n");
  printf (" >> endobj\n");
  addbytes (168);

  printf ("%d 0 obj [/PDF /Text] endobj\n", pdfobjcount);
  addbytes (28);

  printf ("%d 0 obj << /Type /Font /Subtype /Type1\n", pdfobjcount);
  printf (" /Name /F1 /BaseFont /Courier              \n");
  printf (" /Encoding /WinAnsiEncoding\n");
  printf (" >> endobj\n");
  addbytes (122);

  /* writeln(pdfobjcount:0,
     ' 0 obj << /Type /Font /Subtype /Type1');
     writeln(' /Name /F2 /BaseFont /Helvetica-BoldOblique');
     writeln(' /Encoding /WinAnsiEncoding');
     writeln(' >> endobj');
     addbytes(39+44+28+11); */

  /*  initialize system parameters             */
  gsocolor = false;
  gsfcolor = false;
  gsgcolor = false;
  gslinecap = 0;
  gslinejoin = 0;
  gsdashw = 0.0;
  gsdashs = 0.0;
  newstr (&stream);
  stream->segmnt = malloc (sizeof (chbufarray));
  if (stream->segmnt==NULL){ fatal(9); }
  cx = stream;
  pdfwln (" 0.8 w", 6, &cx);
  gslinethick = 0.8;
}

void
pdfwfloat (double y) {
  char buf[CHBUFSIZ];
  int i,j;
  if (y < 0) { pdfstream(" -",2,&cx); y = -y; } else { pdfstream(" ",1,&cx); }
  if (y >= 10e32) { y = 10e32; markerror(902); }
  i = snprintf((char *)buf,
    CHBUFSIZ, "%33.6f", floor(y*1000000+0.5)/1000000.0 );
  for (i--; buf[i]=='0'; ) { i--; }
  if (buf[i]=='.') { i--; }
  for (j=i-1; (j>=0) && (buf[j]!=' '); ) { j--; }
  j++;
  pdfstream((char *)&buf[j],i-j+1,&cx);
}

void
resetgs (primitive * node)
{
  double x;
  if (gsocolor) {
      pdfwln (" 0 0 0 RG", 9, &cx);
      gsocolor = false; }
  if (gsfcolor) {
      pdfwln (" 0 0 0 rg", 9, &cx);
      gsfcolor = false; }
  if (gsgcolor) {
      pdfwln (" 0 g", 4, &cx);
      gsgcolor = false; }
  x = venv (node, Xlinethick);
  if (gslinethick != x) {
      pdfwfloat (x);
      pdfwln (" w", 2, &cx);
      gslinethick = x; }
  if (gslinecap != 0) {
      pdfwln (" 0 J", 4, &cx);
      gslinecap = 0; }
  if (gslinejoin != 0) {
      pdfwln (" 0 j", 4, &cx);
      gslinejoin = 0; }
  if ((gsdashw == 0) && (gsdashs == 0)) { return; }
  pdfwln (" [] 0 d", 7, &cx);
  gsdashw = 0.0;
  gsdashs = 0.0;
}

void
pdfwlz (int n)
{
  Char s[10];
  int i;
  int j = 10;
  int k;

  while (n > 0) {
    k = n / 10;
    s[j - 1] = n - (k * 10) + '0';
    j--;
    n = k; }
  for (i = 1; i <= j; i++) { putchar ('0'); }
  for (i = j; i <= 9; i++) { putchar (s[i]); }
  printf (" 00000 n \n");
}

void
pdfpostlude (void)
{
  nametype *s, *t;
  int i;
  int streamlen = 0;
  int FORLIM;

  s = stream;
  while (s != NULL) {
    streamlen += s->len;
    s = s->nextname; }
  printf ("%d 0 obj << /Length %6d >>\n", pdfobjcount, streamlen);
  printf ("stream\n");
  s = stream;
  while (s != NULL) {
      FORLIM = s->len;
      for (i = 0; i < FORLIM; i++) { putchar (s->segmnt[i]); }
      s = s->nextname; }
  printf ("endstream\n");
  printf ("endobj\n");
  addbytes (streamlen + 53);

  printf ("xref\n");
  printf ("0 %d\n", pdfobjcount);
  printf ("0000000000 65535 f \n");
  FORLIM = pdfobjcount - 2;
  for (i = 0; i <= FORLIM; i++) { pdfwlz (pdfoffs[i]); }
  printf ("trailer\n");
  printf ("   << /Size %d\n", pdfobjcount);
  printf ("      /Root 1 0 R\n");
  printf ("   >>\n");
  printf ("startxref\n");
  printf ("%d\n", pdfoffs[pdfobjcount - 1]);
  printf ("%%%%EOF\n");
  /* delete output buffers                     */
  while (stream != NULL) {
    s = stream;
    t = NULL;
    while (s->nextname != NULL) {
	  t = s;
	  s = s->nextname; }
    Free (s->segmnt);
    Free (s);
    if (t == NULL) { stream = NULL; }
    else { t->nextname = NULL; }
    }
}

void
pdfwcoord (double x, double y)
{
  pdfwfloat (x / fsc);
  pdfwfloat (y / fsc);
}

void
pdfwpos (postype pos)
{
  pdfwcoord (pos.xpos, pos.ypos);
}

void
pdfwstring (nametype * p)
{
  int i;
  Char c, CHR[1];
  boolean waswhite = false;
  boolean iswhite;
  int FORLIM;

  if (p == NULL) { return; }
  if (p->segmnt == NULL) { return; }
  FORLIM = p->len;
  for (i = 0; i < FORLIM; i++) {
    c = p->segmnt[p->seginx + i];
    iswhite = ((c == etxch) || (c == nlch) || (c == tabch) || (c == ' '));
    if ((!iswhite) || (!waswhite)) {
	  if ((c == bslch) || (c == ')') || (c == '(')) {
	    pdfstream ("\\", 1, &cx); }
	  CHR[0] = c;
	  pdfstream ((char *)CHR, 1, &cx); }
    waswhite = iswhite;
    }
}

void
pdfwtext (primitive * node, nametype * tp, double x, double y)
{
  int nstr = 0;
  nametype *tx;
  boolean L, R, A, B;
  double textht, textwid, textoff, dx, dy, ratio = 13.0 / 11;

  resetgs (node);
  if (tp == NULL) { return; }
  tx = tp;
  while (tx != NULL) {
    nstr++;
    tx = tx->nextname; }
  textht = venv (node, Xtextht);
  textwid = venv (node, Xtextwid);
  if ((node->ptype == Xstring) && (nstr > 0)) {
    textht = node->boxheight_ / nstr;
    textwid = node->boxwidth_; }
  textoff = venv (node, Xtextoffset);
  y += ((nstr / 2.0) - (4.0 / 5)) * textht;
  nstr = 1;
  do {
    if ((textwid <= 0) || (nstr > 1)) { textwid = tp->len * textht * 0.6; }
    checkjust (tp, &A, &B, &L, &R);
    pdfwln ("BT", 2, &cx);
    pdfstream ("/F1", 3, &cx);
    pdfwfloat ((textht / scale) * 72);
    pdfwln (" Tf", 3, &cx);
    if (L) { dx = textoff; }
    else if (R) { dx = (-textoff) - (tp->len * textht * 0.6); }
    else if (node->ptype == Xstring) { dx = textwid / (-2); }
    else { dx = (-tp->len) * textht * 0.6 / 2; }
    dy = textht / 10;
    if (A) { dy += textoff + (textht * 0.3); }
    else if (B) { dy += (textht * (1 - ratio) * 0.7) - textoff; }
    pdfwcoord (Max (0.0, x + dx), Max (0.0, y + dy));
    pdfwln (" Td", 3, &cx);
    pdfstream ("(", 1, &cx);
    pdfwstring (tp);
    pdfwln (") Tj", 4, &cx);
    pdfwln ("ET", 2, &cx);
    y -= textht;
    nstr++;
    tp = tp->nextname;
  } while (tp != NULL);
}

void
pdfwprop (postype p1, postype p2, double a, double b, double c)
{
  pprop (p1, &p2, a, b, c);
  pdfwpos (p2);
}

void
pdfsetthick (double lt)
{
  if ((lt < 0.0) || (lt == gslinethick)) { return; }
  pdfwfloat (lt);
  pdfwln (" w", 2, &cx);
  gslinethick = lt;
}

void
pdflinearfill (double f, nametype * ss)
{
  if ((f >= 0.0) && (f <= 1.0)) {
    pdfwfloat (f);
    pdfwln (" g", 2, &cx);
    gsgcolor = true;
    return;
    }
  if (ss == NULL) { return; }
  pdfstream (" ", 1, &cx);
  pdfwstring (ss);
  pdfwln (" rg", 3, &cx);
  gsfcolor = true;
}

void
pdfsetcolor (nametype * op, boolean f)
{
  if (op == NULL) { return; }
  pdfstream (" ", 1, &cx);
  pdfwstring (op);
  if (f) {
    pdfwln (" rg", 3, &cx);
    gsfcolor = true; }
  else {
    pdfwln (" RG", 3, &cx);
    gsocolor = true; }
}

void
pdflineopts (int lspec, double param, double thck, nametype * op)
{
  pdfsetthick (thck);
  if (lspec == Xdashed) {
    if (ismdistmax (param)) { param = 6 * fsc; }
    pdfstream (" [", 2, &cx);
    pdfwfloat (param * 7 / 6 / fsc);
    pdfwfloat (param * 5 / 6 / fsc);
    pdfwln (" ] 0 d 0 j", 10, &cx);
    gsdashw = param;
    gsdashs = param;
    }
  else if (lspec == Xdotted) {
    if (ismdistmax (param)) { param = 4 * fsc; }
    pdfstream (" [", 2, &cx);
    pdfwfloat (0.0);
    pdfwfloat (param / fsc);
    pdfwln ("] 0 d 1 J", 9, &cx);
    gsdashw = 0.0;
    gsdashs = param;
    }
  pdfsetcolor (op, false);
}

void
pdfwarc (postype Ctr, postype St, postype En, double radjust, double ccw) {
  int narcs, i;
  double c, s, cc, ss, startangle, endangle, arcangle, radius;
  postype Q;
  startangle = posangle(St,Ctr);
  endangle = posangle(En,Ctr);
  radius = distance(Ctr,En) + radjust;
  if ((ccw > 0) && (endangle < startangle)) { endangle += 2 * pi; }
  else if ((ccw < 0) && (endangle > startangle)) { endangle -= 2 * pi; }
  narcs = (long) (1.0 + (fabs (endangle - startangle) / (pi / 2)));
  arcangle = (endangle - startangle) / narcs;
  c = cos (arcangle / 2);
  s = sin (arcangle / 2);
  cc = (4 - c) / 3;
  if (s != 0.0) { ss = (1.0 - (c * cc)) / s; }
  else { ss = 0.0; }
  for (i = 1; i <= narcs; i++) {
    Q.xpos = cos (startangle + ((i - 0.5) * arcangle));
    Q.ypos = sin (startangle + ((i - 0.5) * arcangle));
    pdfwpos (affine (radius * cc, -radius * ss, Ctr, Q));
    pdfwpos (affine (radius * cc, radius * ss, Ctr, Q));
    Q.xpos = Ctr.xpos + (radius * cos (startangle + (i * arcangle)));
    Q.ypos = Ctr.ypos + (radius * sin (startangle + (i * arcangle)));
    pdfwpos (Q);
    pdfwln (" c", 2, &cx);
    }
}

void
pdfarcahead (postype C, int atyp, postype * point, double ht, double wid,
	     double lth, double radius, double angle, nametype * sou) {
  postype P, Q, Co, Ci, Px, Cox, Cix, Ao, Ai;
  double ccw, lwi, ds;
  boolean startarrow;

  arcahead (C, *point, atyp, ht, wid, lth, radius, angle, &P, &Co, &Ci, &Px,
	    &Cox, &Cix, &Ao, &Ai, &ccw, &lwi, &startarrow);
  radius = fabs (radius);
                                                 /* Trace arrowhead outline */
  pdfwpos (Ai); pdfwln (" m", 2, &cx);
  pdfwarc (Ci, Ai, *point, 0, -ccw);
  pdfwarc (Co, *point, Ao, 0, ccw);
  if ((atyp == 0) && (lwi < ((wid - lwi) / 2))) {
    ds = distance(Co,Ao);
    Q = Co; pprop (Ao, &Q, ds - lwi, lwi, ds);
    pdfwpos (Q); pdfwln (" l", 2, &cx);
    pdfwarc (Co, Q, Px, 0, -ccw);
    pdfwarc (Ci, Px, Ai, lwi, ccw);
    }
  if (atyp == 3) {
    pdfwarc (Cox, Ao, Px, 0, -ccw);
    pdfwarc (Cix, Px, Ai, 0, ccw); }
  else {
    pdfwpos (Ai);
    pdfwln (" l", 2, &cx); }
  pdfwln (" f", 2, &cx);
  *point = P;
}

void
pdfahead (int atyp, postype * point, postype shaft, double ht, double wid,
	  double lth, nametype * sou)
{
  postype P, L, R, Px, Lx, Rx, Q;
  double x, y;

  dahead (*point, shaft, ht, wid, (lth / 72) * scale, &P, &L, &R, &Px, &Lx,
	  &Rx, &Q, &x, &y);
  if (atyp == 0) {
    pdfsetthick (lth);
    pdfsetcolor (sou, false);
    pdfwprop (P, R, x - y, y, x);
    pdfstream (" m", 2, &cx);
    pdfwpos (P);
    pdfwln (" l", 2, &cx);
    pdfwprop (P, L, x - y, y, x);
    pdfstream (" l", 2, &cx);
    pdfwln (" S", 2, &cx);
    }
  else {
    pdfsetcolor (sou, true);
    pdfwpos (Rx);
    pdfwln (" m", 2, &cx);
    pdfwpos (*point);
    pdfstream (" l", 2, &cx);
    pdfwpos (Lx);
    pdfstream (" l", 2, &cx);
    if (atyp == 3) {
	  pdfwpos (Px);
	  pdfstream (" l", 2, &cx); }
    pdfwln (" h f", 4, &cx);
    }
  *point = P;
}

/* function pdfpos(x,y:real): postype;
var
  Q: postype;
begin
   Q.xpos := x; Q.ypos := y;
   pdfpos := Q
   end; */

void
pdfbox (postype aat, double halfwid, double halfht, double rad)
{
  double r = 1 - SPLT;
  double n, s, e, w;

  rad = Min (Min (fabs (rad), fabs (halfht)), fabs (halfwid));
  n = aat.ypos + halfht;
  s = aat.ypos - halfht;
  e = aat.xpos + halfwid;
  w = aat.xpos - halfwid;
  if (rad == 0.0) {
    pdfwcoord (w, s);
    pdfwcoord (2 * halfwid, 2 * halfht);
    pdfwln (" re", 3, &cx);
    return;
    }
  pdfwcoord (e, n - rad);
  pdfwln (" m", 2, &cx);
  pdfwcoord (e, n - (rad * r));
  pdfwcoord (e - (rad * r), n);
  pdfwcoord (e - rad, n);
  pdfwln (" c", 2, &cx);
  pdfwcoord (w + rad, n);
  pdfwln (" l", 2, &cx);
  pdfwcoord (w + (rad * r), n);
  pdfwcoord (w, n - (rad * r));
  pdfwcoord (w, n - rad);
  pdfwln (" c", 2, &cx);
  pdfwcoord (w, s + rad);
  pdfwln (" l", 2, &cx);
  pdfwcoord (w, s + (rad * r));
  pdfwcoord (w + (rad * r), s);
  pdfwcoord (w + rad, s);
  pdfwln (" c", 2, &cx);
  pdfwcoord (e - rad, s);
  pdfwln (" l", 2, &cx);
  pdfwcoord (e - (rad * r), s);
  pdfwcoord (e, s + (rad * r));
  pdfwcoord (e, s + rad);
  pdfstream (" c h", 4, &cx);
}

void
pdfellipse (postype Ctr, double x, double y)
{
  x = fabs (x) / 2;
  y = fabs (y) / 2;
  pdfwcoord (Ctr.xpos + x, Ctr.ypos);
  pdfwln (" m", 2, &cx);
  pdfwcoord (Ctr.xpos + x, Ctr.ypos + (y * SPLT));
  pdfwcoord (Ctr.xpos + (x * SPLT), Ctr.ypos + y);
  pdfwcoord (Ctr.xpos, Ctr.ypos + y);
  pdfwln (" c", 2, &cx);
  pdfwcoord (Ctr.xpos - (x * SPLT), Ctr.ypos + y);
  pdfwcoord (Ctr.xpos - x, Ctr.ypos + (y * SPLT));
  pdfwcoord (Ctr.xpos - x, Ctr.ypos);
  pdfwln (" c", 2, &cx);
  pdfwcoord (Ctr.xpos - x, Ctr.ypos - (y * SPLT));
  pdfwcoord (Ctr.xpos - (x * SPLT), Ctr.ypos - y);
  pdfwcoord (Ctr.xpos, Ctr.ypos - y);
  pdfwln (" c", 2, &cx);
  pdfwcoord (Ctr.xpos + (x * SPLT), Ctr.ypos - y);
  pdfwcoord (Ctr.xpos + x, Ctr.ypos - (y * SPLT));
  pdfwcoord (Ctr.xpos + x, Ctr.ypos);
  pdfstream (" c h", 4, &cx);
}

void
pdfsplinesegment (primitive * tv, int splc, int splt)
{
  if (tv == NULL) { return; }
  if (splt == 1) {
    pdfwpos (tv->aat);
    pdfwln (" m", 2, &cx);
    pdfwpos (tv->endpos_);
    pdfstream (" l", 2, &cx);
    return;
    }
  if (ismdistmax (tv->aradius_)) {
    if (splc == splt) {			/* 1st seg */
	  pdfwpos (tv->aat);
	  pdfwln (" m", 2, &cx);
	  pdfwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
	  pdfwln (" l", 2, &cx);
	  pdfwprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
	  return;
	  }
    if (splc > 1) {			/* interior segment */
	  pdfwprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
	  pdfwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
	  pdfwln (" c", 2, &cx);
	  pdfwprop (tv->aat, tv->endpos_, 1.0, 5.0, 6.0);
	  return;
	  }
    pdfwprop (tv->aat, tv->endpos_, 5.0, 1.0, 6.0);
    pdfwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    pdfwln (" c", 2, &cx);
    pdfwpos (tv->endpos_);
    pdfstream (" l", 2, &cx);
    /* last segment */
    return;
    }
  if (splc == splt) {
    pdfwpos (tv->aat);
    pdfwln (" m", 2, &cx);
    pdfwprop (tv->aat, tv->endpos_, 1 - tv->aradius_,
      tv->aradius_, 1.0);
    return;
    }
  if (splc > 1) {
    pdfwprop (tv->aat, tv->endpos_, 1 + tv->aradius_,
	  1 - tv->aradius_, 2.0);
    pdfwprop (tv->aat, tv->endpos_, 1.0, 1.0, 2.0);
    pdfwln (" c", 2, &cx);
    pdfwprop (tv->aat, tv->endpos_, 1 - tv->aradius_,
	  1 + tv->aradius_, 2.0);
    return;
    }
  pdfwprop (tv->aat, tv->endpos_, tv->aradius_,
	    1 - tv->aradius_, 1.0);
  pdfwpos (tv->endpos_);
  pdfstream (" c", 2, &cx);
}

/* node is always <> nil */
void
pdfdraw (primitive * node)
{
  int lsp;
  postype X1, X2;
  primitive *lastseg, *tx, *primp;
  double x, y, lth, fill;
  boolean fll;
  int TEMP;

  getlinespec (node, &lsp, &lastseg);	/* lsp = dotted, dashed ... */
  lth = qenv (node, Xlinethick, node->lthick);	/* printobject(node); */
  switch (node->ptype) {

    case Xblock:
      pdfwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      break;

    case Xbox:
      if (drawn (node, lsp, node->boxfill_)) {
	    fll = (((node->boxfill_ >= 0.0) &&
		  (node->boxfill_ <= 1.0))
		 || (node->shadedp != NULL));
	    pdflinearfill (node->boxfill_, node->shadedp);
	    pdflineopts (lsp, node->lparam, lth, node->outlinep);
	    pdfbox (node->aat, node->boxwidth_ / 2,
		  node->boxheight_ / 2, node->boxradius_);
	    if (fll && (lsp != Xinvis)) { pdfwln (" B", 2, &cx); }
	    else if (fll) { pdfwln (" f", 2, &cx); }
	    else { pdfwln (" S", 2, &cx); }
	    }
      pdfwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      break;

    case Xellipse:
    case Xcircle:
      if (node->ptype == Xellipse) {
	    x = node->ellipsewidth_;
	    y = node->ellipseheight_;
	    fill = node->ellipsefill_; }
      else {
	    x = 2 * node->circleradius_;
	    y = x;
	    fill = node->circlefill_; }
      if (drawn (node, lsp, fill)) {
	    fll = (((fill >= 0.0) && (fill <= 1.0)) || (node->shadedp != NULL));
	    pdflinearfill (fill, node->shadedp);
	    pdflineopts (lsp, node->lparam, lth, node->outlinep);
	    pdfellipse (node->aat, x, y);
	    if (fll && (lsp != Xinvis)) { pdfwln (" B", 2, &cx); }
	    else if (fll) { pdfwln (" f", 2, &cx); }
	    else { pdfwln (" S", 2, &cx); }
	    }
      pdfwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      break;

    case Xarc:
      getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
      X1 = arcstart (node);
      X2 = arcend (node);
      if (hasfill) {
	    pdflinearfill (fillfrac, shadestr);
	    pdfwpos (X1);
	    pdfwln (" m", 2, &cx);
	    pdfwarc (node->aat, X1, X2, 0, node->arcangle_);
	    pdfwln (" f", 2, &cx);
	    resetgs (node); }
      if (lsp != Xinvis) {
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
	      pdfsetcolor (outlinestr, true);
	      pdfarcahead (node->aat, ahnum (node->lineatype_), &X1,
            qenv(node, Xarrowht, node->lineheight_),
            qenv(node, Xarrowwid, node->linewidth_),
            lth, fabs (node->aradius_), node->arcangle_, outlinestr);
          node->startangle_ =
            datan(X1.ypos - node->aat.ypos,X1.xpos - node->aat.xpos);
	      resetgs (node); }
	    TEMP = ahlex (node->lineatype_);
	    if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
	      pdfsetcolor (outlinestr, true);
	      pdfarcahead (node->aat, ahnum (node->lineatype_), &X2,
            qenv(node, Xarrowht, node->lineheight_),
            qenv(node, Xarrowwid, node->linewidth_),
            lth, -fabs (node->aradius_), node->arcangle_, outlinestr);
          setangles(&node->startangle_, &node->arcangle_,
            node->aat, X1.xpos, X1.ypos, X2.xpos, X2.ypos);
	      resetgs (node); }
	    pdflineopts (lsp, node->lparam, lth, outlinestr);
	    pdfwpos (X1);
	    pdfwln (" m", 2, &cx);
	    pdfwarc (node->aat, X1, X2, 0, node->arcangle_);
	    pdfwln (" S", 2, &cx);
	    }
      pdfwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      break;

    case Xline:
    case Xarrow:
    case Xmove:
      if (firstsegment (node)) {
	    snode = node;
	    getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
	    if (hasfill) {
	      pdflinearfill (fillfrac, shadestr);
	      tx = node;
	      pdfwpos (node->aat);
	      pdfwln (" m", 2, &cx);
	      while (tx != NULL) {
		    pdfwpos (tx->endpos_);
		    pdfwln (" l", 2, &cx);
		    tx = tx->son;
		  }
	      pdfwln (" f", 2, &cx);
	      resetgs (node);
	      }
	    lth = qenv (lastseg, Xlinethick, lastseg->lthick);
	    if (lsp != Xinvis) {
	      TEMP = ahlex (lastseg->lineatype_);
	      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
		    pdfsetcolor (outlinestr, true);
		    pdfahead (ahnum (lastseg->lineatype_), &node->aat,
			    node->endpos_,
			    qenv (lastseg, Xarrowht, lastseg->lineheight_),
			    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth,
			    outlinestr);
		    resetgs (node);
		    }
	      TEMP = ahlex (lastseg->lineatype_);
	      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
		    pdfsetcolor (outlinestr, true);
		    pdfahead (ahnum (lastseg->lineatype_),
			    &lastseg->endpos_, lastseg->aat, qenv (lastseg,Xarrowht, lastseg->lineheight_),
			    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth, outlinestr);
		    resetgs (node);
		    }
	      pdflineopts (lsp, node->lparam, lth, outlinestr);
	      pdfwpos (node->aat);
	      pdfwln (" m", 2, &cx);
	      }
	    }
      if (lsp != Xinvis) {
	    pdfwpos (node->endpos_);
	    pdfstream (" l", 2, &cx);
	    if (node->son != NULL) { pdfendline (&cx); }
	    else { pdfwln (" S", 2, &cx); }
	    }
      if (node->son == NULL) {
	    while (snode != NULL) {
	      primp = snode;
	      if (primp->textp != NULL) { pdfwtext (snode, primp->textp,
			    0.5 * (primp->endpos_.xpos + primp->aat.xpos),
			    0.5 * (primp->aat.ypos + primp->endpos_.ypos)); }
	      snode = snode->son;
	      }
	    }
      break;

    case Xspline:
      if (firstsegment (node)) {
	    getlinshade (node, &lastseg, &shadestr, &outlinestr, &fillfrac, &hasfill);
	    if (hasfill) {
	      spltot = primdepth (node);
	      splcount = spltot;
	      pdflinearfill (fillfrac, shadestr);
	      tx = node;
	      while (tx != NULL) {
		    primp = tx;
		    pdfsplinesegment (tx, splcount, spltot);
		    splcount--;
		    tx = tx->son; }
	      pdfwln (" f", 2, &cx);
	      resetgs (node);
	      }
	    if (lsp != Xinvis) {
	      spltot = primdepth (node);
	      splcount = spltot;
	      lth = qenv (lastseg, Xlinethick, lastseg->lthick);
	      TEMP = ahlex (lastseg->lineatype_);
	      if ((TEMP == Xdoublehead) || (TEMP == Xlefthead)) {
		    pdfsetcolor (outlinestr, true);
		    pdfahead (ahnum (lastseg->lineatype_), &node->aat,
			    node->endpos_,
			    qenv (lastseg, Xarrowht, lastseg->lineheight_),
			    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth,
			    outlinestr);
		    resetgs (node); }
	      TEMP = ahlex (lastseg->lineatype_);
	      if ((TEMP == Xdoublehead) || (TEMP == Xrighthead)) {
		    pdfsetcolor (outlinestr, true);
		    pdfahead (ahnum (lastseg->lineatype_),
			    &lastseg->endpos_, lastseg->aat, qenv (lastseg,Xarrowht,
								  lastseg->lineheight_),
			    qenv (lastseg, Xarrowwid, lastseg->linewidth_), lth,
			    outlinestr);
		    resetgs (node); }
	      pdflineopts (lsp, lastseg->lparam, lth, outlinestr);
	      }
	    }
      if (lsp != Xinvis) {
	    pdfsplinesegment (node, splcount, spltot);
	    if (splcount == 1) {
	      pdfwln (" S", 2, &cx);
	      resetgs (node); }
	    }
      splcount--;
      break;

    case Xstring:
      pdfwtext (node, node->textp, node->aat.xpos, node->aat.ypos);
      break;

    case XLaTeX:
      if (node->textp != NULL) {
	    pdfwstring (node->textp);
	    pdfendline (&cx);
	    }
      break;
    }
}				/* pdfdraw */
