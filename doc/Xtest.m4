.PS
#
# Xtest.pic derived from Xtest.m4 (Uses Circuit_macros library)
# To produce Xtest.svg (the sed filter deletes the external latex lines):
#   sed -e '/^\\/d' Xtest.pic | dpic -v > Xtest.svg
s_init(Xtest)sinclude(dpic-doc.dim)

scale = 72                      # set the scale to points (bp)

  define grid { [
    for x=0 to $1 by 50 do { line from (x,$2) down $2 
            sprintf("%g",x) below
      if x < $1 then {
        for dx = 10 to 40 by 10 do { line thick 0.4 from (x+dx,$2) down $2 } }
      }
    for y=0 to $2 by 50 do { line from (0,y) right $1 
            sprintf("%g",y) ljust
      if y < $2 then {
        for dy = 10 to 40 by 10 do { line thick 0.4 from (0,y+dy) right $1 } }
      }
    S: ($1/2,0)
    W: (0,$2/2)
    ] }

  B: box invis wid 6*scale ht 6*scale
  Grid: grid(100,100) with .W at B.w+(50,00)

# textoffset = 0
if dpicopt == optPGF then {
  command "\font\testfont=ptmr at 100bp"
# command "s_init(Xtest)sinclude(dpic-doc.dim)"
  X: s_box(\testfont X) with .s at Grid.S
  }
if dpicopt == optSVG then { textht = 100
  X: "X" wid 72 with .s at Grid.S
  textht = 11
  }
# box wid X.wid ht X.ht at X
.PE
