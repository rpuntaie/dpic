.PS
# Bush5.m4
include(Lsys.conf)

# axiom = FX
# X -> >[-FX]+FX
# angle = 40

  pushdef(`X',``lm psh M F X pop P F X ld'')
 `define X {}'
  L_init(linelen=1.2; phi=40; llsf=0.6)
  Bush6: [ Produce(0,10,``F X'') ]
  "Bush5" at last [].s below
  popdef(`X')
.PE
