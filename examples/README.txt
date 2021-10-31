The file Examples.txt contains a minimal example of each of the
different output modes of dpic.

In a Unix-like environment, the modes can be tested by typing one of
make
make epic
make pstricks
make pgf
make pdf
make mfpic
make psfrag
make postscript
make rawpdf
make svg
make overlay
make pdfoverlay
make metapost
make xfig

... or, you can type 'make all' and stand well back.  However, this may
fail at one or more steps if you don't have all required facilities installed.

Perhaps overlay and pdfoverlay require explanation.  In both cases,
the text labels are overlaid on a diagram that has been input first but
does not contain text.  In this way, pic graphics or labels can overlay
essentially any graphic.

You can also try
make man
which will produce about 15 pages of diagrams from various pic manuals
and other tests.

Further:
Typing 'make' in the Lindenmeyer directory will produce the file
examples.html of fractal images.
To see some graphs produced using a general purpose pic library derived
from Fortran sources, type `make' in the Graphs directory.

In the illusions directory, type 
m4 svg.m4 illusions.m4 | dpic -v > illusions.svg
and view the results in a browser.

In the Escher directory, type
dpic -v Escher.pic > Escher.svg
and view the results in a browser.

Typing
make clean
deletes unneeded files created in the above steps.
