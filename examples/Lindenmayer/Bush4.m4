.PS
# Bush5.m4
include(Lsys.conf)

# axiom = VZFFF
# V -> [+++W][---W]YV
# W -> +X[-W]Z
# X -> -W[+X]Z
# Y -> YZ
# Z -> [-FFF][+FFF]F
# angle = 20

  pushdef(`V',``psh P P P W pop psh M M M W pop Y V'')
  pushdef(`W',``P X psh M W pop Z'')
  pushdef(`X',``M W psh P X pop Z'') 
  pushdef(`Y',``Y Z'')
  pushdef(`Z',``psh M F F F pop psh P F F F pop F'')
 `define V {}'
 `define W {}'
 `define X {}'
 `define Y {}'
 `define Z {}'

  L_init(linelen=0.1; phi=20)
  Bush4: [ Produce(0,10,``V Z F F F'') ]
  "Bush4" at last [].s below
  popdef(`V')
  popdef(`W')
  popdef(`X')
  popdef(`Y')
  popdef(`Z')
.PE
