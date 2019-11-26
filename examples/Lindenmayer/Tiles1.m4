.PS
# Tiles1.m4
include(Lsys.conf)

#efine(`F',``FF+F-F+F+FF'')
  L_init(linelen = 0.25/2; angle = 0)
  define(`F',``F F P F M F P F P F F'')
  Tiles1: [ Produce(0,3,``F P F P F P F'') ]
  "Example 2" at last [].s below
  popdef(`F')
.PE
