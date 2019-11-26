.PS
# Algae2.m4
include(Lsys.conf)

# axiom = aF
# a -> FFFFFy[++++n][----t]fb
# b -> +FFFFFy[++++n][----t]fc
# c -> FFFFFy[++++n][----t]fd
# d -> -FFFFFy[++++n][----t]fe
# e -> FFFFFy[++++n][----t]fg
# g -> FFFFFy[+++fa]fh
# h -> FFFFFy[++++n][----t]fi
# i -> +FFFFFy[++++n][----t]fj
# j -> FFFFFy[++++n][----t]fk
# k -> -FFFFFy[++++n][----t]fl
# l -> FFFFFy[++++n][----t]fm
# m -> FFFFFy[---fa]fa
# n -> ofFFF
# o -> fFFFp
# p -> fFFF[-s]q
# q -> fFFF[-s]r
# r -> fFFF[-s]
# s -> fFfF
# t -> ufFFF
# u -> fFFFv
# v -> fFFF[+s]w
# w -> fFFF[+s]x
# x -> fFFF[+s]
# y -> Fy
# angle = 12

define(`a',``F F F F F y psh P P P P n pop psh M M M M t pop f b'')
define(`b',``P F F F F F y psh P P P P n pop psh M M M M t pop f c'')
define(`c',``F F F F F y psh P P P P n pop psh M M M M t pop f d'')
define(`d',``M F F F F F y psh P P P P n pop psh M M M M t pop f e'')
define(`e',``F F F F F y psh P P P P n pop psh M M M M t pop f g'')
define(`g',``F F F F F y psh P P P f a pop f h'')
define(`h',``F F F F F y psh P P P P n pop psh M M M M t pop f i'')
define(`i',``P F F F F F y psh P P P P n pop psh M M M M t pop f j'')
define(`j',``F F F F F y psh P P P P n pop psh M M M M t pop f k'')
define(`k',``M F F F F F y psh P P P P n pop psh M M M M t pop f l'')
define(`l',``F F F F F y psh P P P P n pop psh M M M M t pop f m'')
define(`m',``F F F F F y psh M M M f a pop f a'')
define(`n',``o f F F F '')
define(`o',``f F F F p'')
define(`p',``f F F F psh M s pop q'')
define(`q',``f F F F psh M s pop r'')
define(`r',``f F F F psh M s pop '')
define(`s',``f F f F '')
define(`t',``u f F F F '')
define(`u',``f F F F v'')
define(`v',``f F F F psh P s pop w'')
define(`w',``f F F F psh P s pop x'')
define(`x',``f F F F psh P s pop '')
define(`y',``F y'')

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
`define w {}'
`define x {}'
`define y {}'

  L_init(linelen=0.005; phi=12)
  Algae2: [ Produce(0,40,``a F'') ]
 `"Algae2" at last [].s below'
.PE
