.PS
# KochSnowflake.m4
#ifdef(`rpoint__',,`gen_init(include(Lsys.conf))')
include(Lsys.conf)

#axiom=F++F++F
#F -> F-F++F-F

define(`F',``F M F P P F M F'')

[
  for_(0,4,1,`
    L_init(linelen = linewid*3/3^m4x; angle = 0; phi=60)
    [ Produce(0,m4x,``F P P F P P F'') ] ifelse(m4x,0,,
       `with .{1}st line.start at (last [].e,last [].{1}st line) + (0.2,0) ')
    "m4x" wid 10bp__ at last [].{1}st line.start rjust
    ')
  ]
"Koch snowflake" at last [].s below
.PE
