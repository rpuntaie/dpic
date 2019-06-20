/* postprod.c debugging code inserted into dpic.tab.c if debug is activated */
#ifdef DDEBUG
extern void prvars (primitive *);

/* #include "parscst.h" */
if (debuglevel > 0) {
  attribute *With;
  int p;
  p = yyn;
  With = &(yyval);		/*&attstack[newp]; */
  if (((p >= primary1) && (p <= primary11)) ||
      (p == lcompare4) ||
      (p == lcompare3) ||
      (p == logval3) ||
      (p == logval2) ||
      (p == logprod2) ||
      (p == factor3) ||
      (p == factor2) ||
      ((p >= term2) && (p <= term4)) ||
      (p == ncount2) ||
      (p == logexpr2) ||
      ((p >= expression1) && (p <= expression5)) ||
      ((p >= assignment1) && (p <= assignment2))) {
    fprintf (log_, "(After prod p=%d)", p);
    fprintf (log_, " value=");
    wfloat (&log_, With->xval);
    fprintf (log_, " chbufx=");
    wfloat (&log_, With->chbufx);
    fprintf (log_, " chbufi=");
    wfloat (&log_, chbufi);
    putc ('\n', log_);
    /* prvars(envblock); */
  } else if (((p >= place1) && (p <= place5)) ||
	     ((p >= placename1) && (p <= placename4)) ||
	     (p == shift3) || (p == shift2) ||
	     (p == location2) || (p == location1) ||
	     ((p >= position1) && (p <= position3))) {
    fprintf (log_, "\n location:");
    wpair (&log_, With->xval, With->yval);
    putc ('\n', log_);
    fflush (log_);
  }
  /* if (yyn>8) prattstack(&yyvsp[0]); */
/*
  if (chbufi > 0) {
    fprintf(log_,"Xchbuf(0:%d)|",chbufi);
    for (i=0; i<chbufi; i++) { putc(chbuf[i], log_); }
    fprintf(log_,"|\n");
    }
*/
}
#endif
