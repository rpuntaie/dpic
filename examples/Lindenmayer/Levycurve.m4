.PS
# Levycurve.m4
include(Lsys.conf)

#efine(`F',``-F++F-'')
  pushdef(`F',``M F P P F M'')
  L_init(angle=0; phi=45; linelen=0.04)
  [ Produce(0,12,``F'') ]
  "Levy curve" at last [].s below
  popdef(`F')
.PE
