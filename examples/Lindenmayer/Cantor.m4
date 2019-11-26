.PS
# Cantor.m4
include(Lsys.conf)

# Cantor set
  pushdef(`F',``F f F'')
  pushdef(`f',``f f f'')
  L_init(linelen = 4; angle = 0; llsf = 3;)
  Cantor: [ linethick = 3
    Produce(0,0,``F'')
    for_(1,6,1,`move to (0,last line.start.y-0.1); Produce(0,m4x,``ld F'')')
    ]
  "Cantor set" at last [].s below
  popdef(`F')
  popdef(`f')
.PE
