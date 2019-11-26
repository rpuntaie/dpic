.PS
# Leaf.m4
include(Lsys.conf)

# Leaf system
# axiom = a
# F -> >F<
# a -> F[+x]Fb
# b -> F[-y]Fa
# x -> a
# y -> b
# angle = 45
# length factor = 1.36

  pushdef(`F',``lm F ld'')
  pushdef(`a',``F psh P x pop F b'')
  pushdef(`b',``F psh M y pop F a'')
  pushdef(`x',``a'')
  pushdef(`y',``b'')
 `define a {}'
 `define b {}'
 `define x {}'
 `define y {}'
  L_init(linelen=0.01; phi=45; llsf=1.36)
  Leaf: [ Produce(0,14,``a'') ]
  "Leaf" at last [].s below
  popdef(`F')
  popdef(`a')
  popdef(`b')
  popdef(`x')
  popdef(`y')
.PE
