.PS
# Sticks.m4
include(Lsys.conf)

# axiom = X
# F -> FF
# X -> F[+X]F[-X]+X
# angle = 20

  pushdef(`F',``F F'')
  pushdef(`X',``F psh P X pop F psh M X pop P X'')
 `define X {}'
  L_init(linelen=0.02; phi=20; llsf=0.6)
  Sticks: [ Produce(0,7,``X'') ]
  "Sticks" at last [].s below
  popdef(`X')
  popdef(`F')
.PE
