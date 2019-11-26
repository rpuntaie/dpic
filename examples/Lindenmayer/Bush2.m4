.PS
# Bush2.m4
include(Lsys.conf)

# axiom = F
# F -> FF+[+F-F-F]-[-F+F+F]
# angle = 22.5


  pushdef(`F',``F F P psh P F M F M F pop M psh M F P F P F pop'')
  L_init(linelen=0.1; phi=22.5)
  Bush2: [ Produce(0,4,``F'') ]
  "Bush2" at last [].s below
  popdef(`F')
.PE
