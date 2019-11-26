.PS
# FractalPlant.m4
include(Lsys.conf)

#efine(`X',``F-[[X]+X]+F[+FX]-X'')
  pushdef(`X',``F P psh psh X pop M X pop M F psh M F X pop P X'')
  pushdef(`F',``F F'')
  `define X {}'
  L_init(linelen = linewid/20; phi = 22.5; angle=90-phi)
  [ Produce(0,6,``X'') ]
  "Fractal plant" at last [].s below
  popdef(`F')
.PE
