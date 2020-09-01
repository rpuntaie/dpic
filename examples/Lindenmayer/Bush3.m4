.PS
# Bush4.m4
include(Lsys.conf)

#axiom = F
#F -> F[+FF][-FF]F[-F][+F]F
#angle = 35


  pushdef(`F',``F psh P F F pop psh M F F pop F psh M F pop psh P F pop F'')
  L_init(linelen=0.02; phi=35; linethick=0.4)
  Bush3: [ Produce(0,5,``F'') ]
  "Bush3" at last [].s below
  popdef(`F')
.PE
