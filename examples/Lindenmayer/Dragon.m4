.PS
# Dragon curve
include(Lsys.conf)

#efine(`X',``X+YF+'')
#efine(`Y',``FX-Y'')
  define(`X',``X P Y F P'')
  define(`Y',``M F X M Y'')
  `define X {}'
  `define Y {}'
  L_init(angle=0; phi=90; linelen=linewid/14)
  Produce(0,14,``F X'')
.PE
