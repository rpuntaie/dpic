.PS
# KochCurve.m4
include(Lsys.conf)

# Koch curve
  pushdef(`F',``F P F M F M F P F'')
  L_init(linelen = 0.03; angle = 0)
  Koch: [ Produce(0,5,``F'') ]
  "Koch curve" at last [].s below
  popdef(`F')
.PE
