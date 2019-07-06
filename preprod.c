/* preprod.c debugging code inserted into dpic.tab.c if debug is activated */
#ifdef DDEBUG

extern void prvars (primitive *);

#include "parscst.h"

int p, newp;
p = yyn;
if (debuglevel > 0) {
  newp = 1 - yylen;

  fprintf (log_, "\nProduction(newp=%d", newp);
  if (p >= 0) {
    fprintf (log_, ",lexval=%d", yyvsp[newp].lexval);
  }
  fprintf (log_, ",p=%d)", p);
/*
    fprintf(errout, "\nProduction(newp=%d", newp);
    if (p >= 0) { fprintf(errout, ",lexval=%d", yyvsp[newp].lexval); }
    fprintf(errout, ",p=%d", p);
*/
  switch (p) {
  case primary4:
    fprintf (log_, " opr: (");
    wfloat (&log_, yyvsp[newp].xval);
    putc (')', log_);
    break;
  case term2:
    fprintf (log_, " opr: ");
    wfloat (&log_, yyvsp[newp].xval);
    fprintf (log_, " * ");
    wfloat (&log_, yyvsp[newp + 2].xval);
    break;
  case term3:
    fprintf (log_, " opr: ");
    wfloat (&log_, yyvsp[newp].xval);
    fprintf (log_, " / ");
    wfloat (&log_, yyvsp[newp + 2].xval);
    break;
  case expression4:
    fprintf (log_, " opr: ");
    wfloat (&log_, yyvsp[newp].xval);
    fprintf (log_, " + ");
    wfloat (&log_, yyvsp[newp + 2].xval);
    break;
  case expression5:
    fprintf (log_, " opr: ");
    wfloat (&log_, yyvsp[newp].xval);
    fprintf (log_, " - ");
    wfloat (&log_, yyvsp[newp + 2].xval);
    break;
  }
  putc ('\n', log_);
  fflush (log_);
}
#endif
