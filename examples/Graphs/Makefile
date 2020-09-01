# Produce tgraph.svg for viewing in a browser:
tgraph.svg:
	dpic -v tgraph.pic > tgraph.svg

# put your test file in test.pic and type `make tst.pdf'
tst.pdf:
	if test -f test.pic ; then dpic -g test.pic > test.tex ; \
    else dpic -g tgraph.pic > test.tex ; fi
	pdflatex tst

clean:
	rm -f *.svg *.aux *.log *.pdf test.tex
