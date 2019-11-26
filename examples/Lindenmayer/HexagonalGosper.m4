.PS
# HexagonalGosper.m4
include(Lsys.conf)

#efine(`X',``X+YF++YF-FX--FXFX-YF+'')
#efine(`Y',``-FX+YFYF++YF+FX--FX-Y'')
  define(`X',``X P Y F P P Y F M F X M M F X F X M Y F P'')
  define(`Y',``M F X P Y F Y F P P Y F P F X M M F X M Y'')
  `define X {}'
  `define Y {}'
  L_init(angle=0; phi=60; linelen=linewid/6)
  [ Produce(0,4,``X F'') ]
  "Hexagonal gosper" at last [].s below
.PE
