divert(-1)
#nclude(svg.m4)dnl
#ivert(-1)

#Adjust scale and default lengths
define(`scaledefaults',`
 scale = 1/($1)
 arcrad = arcrad*($1)
 arrowht = arrowht*($1)
 arrowwid = arrowwid*($1)
 boxht = boxht*($1)
 boxrad = boxrad*($1)
 boxwid = boxwid*($1)
 circlerad = circlerad*($1)
 dashwid = dashwid*($1)
 ellipseht = ellipseht*($1)
 ellipsewid = ellipsewid*($1)
 lineht = lineht*($1)
 linewid = linewid*($1)
 moveht = moveht*($1)
 movewid = movewid*($1)
 textht = textht*($1)
 textoffset = textoffset*($1)
 textwid = textwid*($1)
 linethick = linethick*($1)
 maxpsht = maxpsht*($1)
 maxpswid = maxpswid*($1)
')

# Possible defaults for diagrams in mm
define(`SIdefaults',`
 scale = scale*25.4
 arcrad = 5
 arrowht = 2.5
 arrowwid = arrowht/2
 boxht = 12
 boxrad = 0
 boxwid = 18
 circlerad = 5
 dashwid = 1.5
 ellipseht = 12
 ellipsewid = 18
 lineht = 12
 linewid = 12
 moveht = 12
 movewid = 12
 textht = ifsvg(4,0)
 textoffset = 3
 textwid = 0
')

define(`local_init',`
 scaledefaults(1.1)
')

# If the variable dptextratio is not found you don't have
# dpic version 2018.05.15 or later.  In that case, change
# dptextratio to 1 in the following (or delete *dptextrario ).
define(`svg_font',`
command "<g patsubst(ifelse(`$1',,,
index(`$1',font),0,`$1',
index(`$1',style),0,`$1',
style="font-family:`$1'")
,",\\")>"
  ifelse(`$2',,,`textht=(`$2')*dptextratio')
  ifelse(`$3',,,`textoffset=`$3'')
  `$4'
  ifelse(`$4',,,`command "</g>"')')

divert(0)dnl
