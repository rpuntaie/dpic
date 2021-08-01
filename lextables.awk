# The input file defining tokens contains lines of the form
# (# comment)
# label token
#   =  token
# label = token

# The token list for bison is generated together with the tables that
# drive the lexical analyzer.

BEGIN { 
   ORDMAXCH = 255

   for (i=0; i<=ORDMAXCH; i++){
      entryhp[i] = 0
      entrytv[i] = 0
      }
   label[0] = "<METAGOAL>"
   nlabels = 0
   ntv = 0

   ntokens = 0
   nhp = 0

# init ord_
    for (i = 0; i <= ORDMAXCH; i++) {
        t = sprintf("%c", i)
        ord_[t] = i
        }
 }

function chr(i) { return sprintf("%c", i + 0) }
function ord(c) { return ord_[c] }

# Process the lines in the file:
   /^#/ || /^ *$/ { next }

   { if ($1 != "=") {
       label[++nlabels] = $1
       if ($2 == "=") { tk = substr($3,2,length($3)-2) }
       else { tk = substr($2,2,length($2)-2); ntv++ }
       if ( tk !~ /^<[a-zA-Z]/ ) { token[++ntokens] = tk }
       labeltv[$1] = ntv
       tokentv[tk] = ntv
       tvtoken[ntv] = tk
       }
     else {
       tk = substr($2,2,length($2)-2)
       if ( tk !~ /^<[a-zA-Z]/ ) { token[++ntokens] = tk }
       tokentv[tk] = ntv
       tvtoken[ntv] = tk
       }
     }

END {

#                           Sort the terminals
for (i=1; i<=ntokens; i++) { stok[i] = token[i] }
do { c="";
  for(i=1; i<ntokens; i++){
    if(stok[i]>stok[i+1]){ c=stok[i]; stok[i]=stok[i+1]; stok[i+1]=c } }
} while(c!="")

  lxch[0] = "0"
#                           Add the terminals to the tree
  for (tn=1; tn<=ntokens; tn++) {
    tok = stok[tn]
    ch = substr(tok,1,1)
    och = ord(ch)
    tokln = length(tok)
    if (tokln == 1) { entrytv[och] = tokentv[tok] }
    else {
      if (entryhp[och] == 0) { entryhp[och] = ++nhp }
      lxix = entryhp[och]
      chx = 2
      while (chx <= tokln) {
        cx = substr(tok,chx,1)
        if (ord(lxch[lxix]) == 0) { # empty node
          lxch[lxix] = cx
          if (chx == tokln) { lxtv[lxix] = tokentv[tok] }
          else { lxhp[lxix] = ++nhp; lxix = nhp }
          }
        else if (lxch[lxix] == cx) {
          if (chx == tokln) { lxtv[lxix] = tokentv[tok] }
          else if (lxhp[lxix] == 0) { lxhp[lxix] = ++nhp; lxix = nhp }
          else { lxix = lxhp[lxix] }
          }
        else if (lxnp[lxix] != 0) {
          lxix = lxnp[lxix]
          chx--
          }
        else {
          lxnp[lxix] = ++nhp; lxix = nhp
          lxch[lxix] = cx
          if (chx == tokln) { lxtv[lxix] = tokentv[tok] }
          else { lxhp[lxix] = ++nhp; lxix = nhp }
          }
        chx++
        } # while chx <= tokln
      } # tokln > 1
    } # for tn

  lxmax = nhp

#                           Print out the tables
   print "entryhp.h"
   print "entrytv.h"
   print "" > "entryhp.h"
   print "" > "entrytv.h"
   for (i=0; i<=ORDMAXCH; i++){ if (i<ORDMAXCH) {e = ","} else {e = " "}
      printf("%d%c\n", entryhp[i],e) >> "entryhp.h"
      printf("%d%c\n", entrytv[i],e) >> "entrytv.h"
      }

   print "lxch.h"
   print "lxhp.h"
   print "lxnp.h"
   print "lxtv.h"

   print "" > "lxch.h"
   print "" > "lxhp.h"
   print "" > "lxnp.h"
   print "" > "lxtv.h"
   for (i=0; i<=lxmax; i++) { if (i<lxmax) {e = ","} else {e = " "}
      printf("'%c'%c\n",lxch[i],e) >> "lxch.h"
      printf("%d%c\n",lxhp[i],e) >> "lxhp.h"
      printf("%d%c\n",lxnp[i],e) >> "lxnp.h"
      printf("%d%c\n",lxtv[i],e) >> "lxtv.h"
      }

#                           Special constants
   print "lxvars.h"
   print sprintf("#define	lxmax	%d",lxmax) > "lxvars.h"
   print sprintf("#define	XXenvvar	%d",labeltv["Xenvvar"]) >> "lxvars.h"
   print sprintf("#define	Xlastsc	%d",labeltv["Xtextwid"]) >> "lxvars.h"
   print sprintf("#define	Xlastenv	%d",labeltv["Xscale"]) >> "lxvars.h"

   print "lxcst.h"
   print "" > "lxcst.h"
   for (i=0; i<=nlabels; i++) { if ( label[i] !~ /^<[a-zA-Z]/ ) { 
     print sprintf("#define	%s	%d",label[i],labeltv[label[i]]) >> "lxcst.h" }
     }

#  print "terminals"
#  print "" > "terminals"
#  for (i=1; i<ntv; i++) {
#    print sprintf("\"%s\",",tvtoken[i]) >> "terminals"
#    }
#  print sprintf("\"%s\"",tvtoken[ntv]) >> "terminals"

   print "tokens.y"
   print "" > "tokens.y"
   for (i=1; i<=nlabels; i++) {
     tk = tvtoken[labeltv[label[i]]]
     if (label[i] == "Xstring") { tk = "<string>" }
     print sprintf("%%token	%s %d \"%s\"",
       label[i],labeltv[label[i]],tk ) >> "tokens.y"
     }

} # END
