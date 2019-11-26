.PS
# Bush1.m4
include(Lsys.conf)

# axiom = Y
# X -> X[-FFF][+FFF]FX
# Y -> YFX[+Y][-Y]
# angle = 25.7


  pushdef(`X',``X psh M F F F pop psh P F F F pop F X'')
  pushdef(`Y',``Y F X psh P Y pop psh M Y pop'')
 `define X {}'
 `define Y {}'
  L_init(linelen=0.05; phi=25.7)
  Leaf: [ Produce(0,6,``Y'') ]
  "Bush1" at last [].s below
  popdef(`X')
  popdef(`Y')
.PE
