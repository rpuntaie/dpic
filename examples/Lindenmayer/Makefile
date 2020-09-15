LIBDIR = $$HOME/lib
M4LIBS = svg.m4 SVGconfig.conf

# To process a single file, copy it to test.m4 and type "make tst"
# which will produce tstSVG.html

DPIC = dpic
#DPIC = $$HOME/dpic/bu*/p2c/ftp/dpic
#DPIC = $$HOME/dpic/bu*/test/dpic
#DPIC = ../../../dpic/bison/dpic

.SUFFIXES: .pic .svg .m4
.pic.svg:
	$(DPIC) -v $*.pic > $*.svg
	grep '<\!-- width' $*.svg | sed -e 's%<\!-- *%%' -e 's% *-->%%' > $*.siz
.m4.svg:
	m4 $(M4LIBS) $*.m4 | sed -e '/^\%/d' > $*.pic
	$(DPIC) -v $*.pic > $*.svg
	grep '<\!-- width' $*.svg | sed -e 's%<\!-- *%%' -e 's% *-->%%' > $*.siz

CCTSVG = \
  Algae1.svg Algae2.svg Bush1.svg Bush2.svg Bush3.svg Bush4.svg Bush5.svg \
  Cantor.svg Dragon.svg FractalPlant.svg HexagonalGosper.svg \
  KochCurve.svg KochSnowflake.svg \
  Leaf.svg Levycurve.svg OL.svg SierpinskiArrowhead.svg Sticks.svg \
  Tiles1.svg Weed.svg

examples.html: examples.htmx
	make $(CCTSVG)
	Version=`sed -e 's/Version //' $(LIBDIR)/doc/Version.tex` ; \
      sed -e 's/Version XXX/Version '$$Version'/' examples.htmx \
      | m4 > examples.html

SED = sed -e '/^\%/d'
TEST = test
tst: $(TEST).pic
	$(DPIC) -v $(TEST).pic > $(TEST).svg
	m4 $(M4LIBS) $(TEST).m4 | $(SED) > $(TEST).pic
	$(DPIC) -v $(TEST).pic > $(TEST).svg
	grep '<\!-- width' $(TEST).svg | sed -e 's%<\!-- *%%' -e 's% *-->%%' \
     > $(TEST).siz
	make tstSVG.html

test.pic:
	m4 $(M4LIBS) test.m4 | $(SED) > test.pic

tstSVG.html: tstSVG.htmx $(TEST).svg
	Version=`sed -e 's/Version //' $(LIBDIR)/doc/Version.tex` ; \
      sed -e 's/Version XXX/Version '$$Version'/' \
          -e 's/XXXXX/'$(TEST)'/g' \
      tstSVG.htmx | m4 > tstSVG.html
#	cp tstSVG.html $(TEST) $$HOME/public_html/svg

xst: Incleps.png

InclepsSVG.svg: InclepsSVG.m4
	m4 $(M4LIBS) $*.m4 | sed -e '/^\%/d' > $*.pic
	$(DPIC) -v $*.pic > $*.svg
	$(DPIC) -v $*.pic > $*.svg

Incleps.png:
	(cd ..; make Incleps.png); cp ../Incleps.png .

clean:
	@printf "\n svg clean:\n"
	rm -f *.svg *.dim *.ps *log *.siz *.pic examples.html Incleps.png
	rm -f tstSVG.html
	@printf "\n"

clobber: clean
	rm -f test.m4
