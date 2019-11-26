.PS
# Weed.m4
include(Lsys.conf)

# axiom = F
# F -> FF-[XY]+[XY]
# X -> +FY
# Y -> -FX
# angle = 22.5

define(`F',``F F M  psh X Y pop P psh X Y pop'')
define(`X',``P F Y'')
define(`Y',``M F X'')

# F -> FF-[XY]+[XY]
`define X {}'
`define Y {}'

  L_init(linelen=0.035; phi=22.5)
  Algae2: [ Produce(0,6,``F'') ]
 `"Weed" at last [].s below'
.PE
