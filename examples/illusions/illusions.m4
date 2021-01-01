.PS
# selected from:
# https://tex.stackexchange.com/questions/129274/showcase-of-optical-illusions-made-with-tex-latex-luatex-context
# Try the following (assuming m4 and Circuit_macros have been installed):
# m4 svg.m4 illusions.m4 | dpic -v > illusions.svg
# View the result in a browser.

gen_init
NeedDpicTools
maxpsht = 30

# Circles
A: [
  bwid = 3/25.4
  bht = bwid
  box colored "grey" wid 12cm__ ht 12cm__ at (0,0)
  twist = 12
  Loopover_(`n',
   `r = 6 - m4Lx
    for m=1 to n by 2 do {
      Point_(360/n*m+twist)
      rotbox(bwid,bht,outlined "white") at (Rect_(r/2.54,360/n*m))
      }
    for m=2 to n by 2 do {
      Point_(360/n*m+twist)
      rotbox(bwid,bht,outlined "black") at (Rect_(r/2.54,360/n*m))
      }
    twist = -twist ',
    70,56,42,28)
  ]

# OpArt
B: [
  linethick = 2
  refsize = 0.9
  dsep = refsize/12
  
  define qbox { [ # size, R
    if "$2"=="" then { define m {} } else { define m {-} }
    nlines = int($1/dsep)
    if "$2"=="" then { SW: (0,0) } else { SW: (0,-nlines*dsep) }
    { box wid $1 ht $1 invis fill 1 with .sw at SW }
    for i=0 to nlines do { line outline "darkgray" \
      from (i*dsep,0) to ( nlines*dsep, m (nlines-i)*dsep)
    if i > 0 then { line outline "darkgray" \
      from (0,m i*dsep) to ((nlines-i)*dsep,m nlines*dsep) }
      } ] }
  
  B: qbox(refsize*(3+4/3),R)
  for i=1 to 3 do {
    for j=1 to 3 do {
      qbox(refsize) with .nw \
        at B.nw+ ((4*(j-1)+1)/3*refsize,-(4*(i-1)+1)/3*refsize)
      qbox(refsize/3,R) at last []
      }
    }
  ] with .nw at A.sw+(0,-0.5)

# Parallel illusion
C: [
  boxwid = 1/2
  boxht = 1/2
  nrows = 9
  ncols = 11
  gap = scale/72

  Background: box color "gray" wid (ncols+0.5)*boxwid \
    ht nrows*boxht + (nrows-1)*gap
  move to Background.nw+(0,-boxht/2)
  h = 1; dh = -1
  for i=1 to nrows do {
    { move right h * boxwid/4
      for j=1 to ncols do { box thick 0 fill (j+1)%2 } }
    move down boxht+gap
    h += dh ; if (h==0 || h==2) then { dh = -dh }
    }
  ] with .nw at B.sw+(0,-0.5)

.PE
