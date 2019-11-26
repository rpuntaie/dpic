.PS
# Sierpinski arrowhead curve
include(Lsys.conf)

  pushdef(`A',``B M A M B'')
  pushdef(`B',``A P B P A'')
  `define A {F}'
  `define B {F}'
  L_init(linelen = 0.01; angle = 0; phi = 60)
  SA: [ Produce(0,8,``A'') ]
  "Sierpinski arrowhead curve" at last [].s below
  popdef(`A')
  popdef(`B')
.PE
