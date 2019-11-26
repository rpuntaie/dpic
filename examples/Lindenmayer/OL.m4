.PS
# OL.m4
include(Lsys.conf)

# 0L system:
#efine(`F',``F+F-F-FF+F+F-F'')
  pushdef(`F',``F P F M F M F F P F P F M F'')
  L_init(linelen = 0.25/3)
  OL: [ Produce(0,2,``F P F P F P F'') ]
  "0L system" at last [].s below
  popdef(`F')
.PE
