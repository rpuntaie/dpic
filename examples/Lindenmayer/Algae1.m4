.PS
# Algae1.m4
include(Lsys.conf)

# axiom = aF
# a -> FFFFFv[+++h][---q]fb
# b -> FFFFFv[+++h][---q]fc
# c -> FFFFFv[+++fa]fd
# d -> FFFFFv[+++h][---q]fe
# e -> FFFFFv[+++h][---q]fg
# g -> FFFFFv[---fa]fa
# h -> ifFF
# i -> fFFF[--m]j
# j -> fFFF[--n]k
# k -> fFFF[--o]l
# l -> fFFF[--p]
# m -> fFn
# n -> fFo
# o -> fFp
# p -> fF
# q -> rfF
# r -> fFFF[++m]s
# s -> fFFF[++n]t
# t -> fFFF[++o]u
# u -> fFFF[++p]
# v -> Fv
# angle = 12

define(`a',``F F F F F v psh P P P h pop psh M M M q pop f b'')
define(`b',``F F F F F v psh P P P h pop psh M M M q pop f c'')
define(`c',``F F F F F v psh P P P f a pop f d'')
define(`d',``F F F F F v psh P P P h pop psh M M M q pop f e'')
define(`e',``F F F F F v psh P P P h pop psh M M M q pop f g'')
define(`g',``F F F F F v psh M M M f a pop f a'')
define(`h',``i f F F'')
define(`i',``f F F F psh M M m pop j'')
define(`j',``f F F F psh M M n pop k'')
define(`k',``f F F F psh M M o pop l'')
define(`l',``f F F F psh M M p pop'')
define(`m',``f F n'')
define(`n',``f F o'')
define(`o',``f F p'')
define(`p',``f F'')
define(`q',``r f F'')
define(`r',``f F F F psh P P m pop s'')
define(`s',``f F F F psh P P n pop t'')
define(`t',``f F F F psh P P o pop u'')
define(`u',``f F F F psh P P p pop'')
define(`v',``F v'')

`define a {}'
`define b {}'
`define c {}'
`define d {}'
`define e {}'
`define g {}'
`define h {}'
`define i {}'
`define j {}'
`define k {}'
`define l {}'
`define m {}'
`define n {}'
`define o {}'
`define p {}'
`define q {}'
`define r {}'
`define s {}'
`define t {}'
`define u {}'
`define v {}'

  L_init(linelen=0.012; phi=12)
  Algae1: [ Produce(0,20,``a F'') ]
 `"Algae1" at last [].s below'
.PE
