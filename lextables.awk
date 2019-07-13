# The file defining tokens contains lines of the form
# (# comment)
# label token
#   =  token
# label = token
BEGIN { 
   debug = 0
   ORDMAXCH = 127

#  print "" >  "lexedit"  # sed commands symbolic tokens to integer

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
    for (i = 0; i <= 127; i++) {
        t = sprintf("%c", i)
        ord_[t] = i
        }
 }

function chr(i) { return sprintf("%c", i + 0) }
function ord(c) { return ord_[c] }

function visit(lxt,tt,tn,ly) {
  ttt = tt lxch[lxt]
  if (lxtv[lxt] != 0) {
    print sprintf("%d %s %d",++tn,ttt,lxtv[lxt]) >> "tabletoks"
    print sprintf("%d %s %d",  tn,ttt,lxtv[lxt])
    }
  ly = lxt
  if (lxhp[lxt] != 0) { tn = visit(lxhp[lxt],ttt,tn) }
  if (lxnp[ly] != 0) { tn = visit(lxnp[ly],  tt,tn) }
  return tn
  }

function prtr(lx){
    if (lt > 1) { print sprintf("token %s %d %c %d %d %d %s",
      tok,lx,cx,lxnp[lx],lxhp[lx],lxtv[lx],ter) }
    else { print sprintf("token %s (%d) %d %d %s",
      tok,och,entryhp[och],entrytv[och],ter)}
  }

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

if (debug){
  print sprintf("nlabels=%d ntokens=%d ntv=%d",nlabels,ntokens,ntv)

  print "\n labels > lex.list"
  print nlabels " labels" > "lex.list"
  for (i=0; i<=nlabels; i++) {
    print sprintf("%d %s",labeltv[label[i]], label[i]) >> "lex.list" }

# print "\n tokentv, tokens > tokens"
# print "\n" ntokens " tokens" > "tokens"
# for (i=1; i<=ntokens; i++) {
#   print sprintf("%d %s",tokentv[token[i]], token[i]) >> "tokens" }

# print "\n tokentv, tvtokens"
# print "tokentv, tvtoken" > "tvtokens"
# for (i=0; i<=ntv; i++) {
#   print sprintf("%d %s",i, tvtoken[i])
#   print sprintf("%d %s",i, tvtoken[i]) >> "tvtokens" }
}

#                           Sort the terminals
for (i=1; i<=ntokens; i++) { stok[i] = token[i] }
do { c="";
  for(i=1; i<ntokens; i++){
    if(stok[i]>stok[i+1]){ c=stok[i]; stok[i]=stok[i+1]; stok[i+1]=c } }
} while(c!="")

if (debug){
  print "\nunsorted tokens, tv:"
  for (i=1; i<=ntokens; i++) {
    print sprintf("%d %s %d",i,token[i],tokentv[token[i]]) }

  echo "sortedtoks"
  print "tokens, tv" > "sortedtoks"
  print "\nsorted tokens, tv:"
  for (i=1; i<=ntokens; i++){
    print sprintf("%d %s %d",i,stok[i],tokentv[stok[i]]) }
  for (i=1; i<=ntokens; i++) {
    print sprintf("%d %s %d",i,stok[i],tokentv[stok[i]]) >> "sortedtoks" }
  }

  lxch[0] = "0"
#                           Add the terminals to the tree
  for (tn=1; tn<=ntokens; tn++) {
    tok = stok[tn]
    if (debug) ter = "A"
    ch = substr(tok,1,1)
    och = ord(ch)
    lt = length(tok)
    if (lt == 1) { entrytv[och] = tokentv[tok] }
    else {
      if (entryhp[och] == 0) { entryhp[och] = ++nhp }
      lxix = entryhp[och]
      chx = 2
      while (chx <= lt) {
        cx = substr(tok,chx,1)
        if (ord(lxch[lxix]) == 0) { # empty node
          lxch[lxix] = cx
          if (chx == lt) { lxtv[lxix] = tokentv[tok]; if (debug)ter=ter "B" }
          else { if (debug)ter=ter "C"
            lxhp[lxix] = ++nhp; lxix = nhp
            }
          }
        else if (lxch[lxix] == cx) {
          if (chx == lt) { lxtv[lxix] = tokentv[tok]; if (debug)ter=ter "D" }
          else if (lxhp[lxix] == 0) { if (debug)ter=ter "E"
            lxhp[lxix] = ++nhp; lxix = nhp
            }
          else { lxix = lxhp[lxix]; if (debug)ter=ter "F" }
          }
        else if (lxnp[lxix] != 0) { if (debug)ter=ter "G"
          lxix = lxnp[lxix]
          chx--
          }
        else {
          lxnp[lxix] = ++nhp
          lxix = nhp
          lxch[lxix] = cx
          if (chx == lt) { lxtv[lxix] = tokentv[tok]; if (debug)ter=ter "H" }
          else { if (debug)ter=ter "I"
            lxhp[lxix] = ++nhp; lxix = nhp
            }
          }
        chx++
        } # while chx
      } # lt > 1
#   if (debug) prtr(lxix)
    } # for tn

  lxmax = nhp
  
if (debug){
  print sprintf("\nentries:")
  print sprintf("entries:") > "entries"
  for (i=0; i<=127; i++) {
    if ((entryhp[i] != 0) || (entrytv[i] !=0)) {
      print sprintf("%d %c %d %d",i,chr(i),entryhp[i],entrytv[i]) }
    if ((entryhp[i] != 0) || (entrytv[i] !=0)) {
      print sprintf("%d %c %d %d",i,chr(i),entryhp[i],entrytv[i]) >> "entries" }
    }
  
  print sprintf("\n%d table rows:",nhp)
  for (i=0; i<=nhp; i++) {
    print sprintf("%d %c %d %d %d",i,lxch[i],lxnp[i],lxhp[i],lxtv[i]) }
#                           Verify the tables: should be the same as sorted toks
  print "\ntabletoks"
  print "ntok, token, tv" > "tabletoks"
  tn = 0
  for (i=33; i<=126; i++) {
    tx = chr(i)
    if (entrytv[i] != 0) {
      print sprintf("%d %c %d",++tn,tx,entrytv[i]) >> "tabletoks" }
    if (entrytv[i] != 0) {
      print sprintf("%d %c %d",  tn,tx,entrytv[i]) }
    if (entryhp[i] != 0) { tn = visit(entryhp[i],tx,tn) }
    }
  print ""
  }

#                           Print out the tables
   print "entryhp.h"
   print "entrytv.h"
#  print "entry.csv"
   print "" > "entryhp.h"
   print "" > "entrytv.h"
#  print "" > "entry.csv"
   for (i=0; i<=127; i++){ if (i<127) {e = ","} else {e = " "}
      printf("%d%c\n", entryhp[i],e) >> "entryhp.h"
      printf("%d%c\n", entrytv[i],e) >> "entrytv.h"
      if ((i>32) && (i<127)) {cs = chr(i)} else {cs=" "}
#     printf("'%c',%d,%d\n", cs,entryhp[i],entrytv[i]) >> "entry.csv"
      }

   print "lxch.h"
   print "lxhp.h"
   print "lxnp.h"
   print "lxtv.h"
#  print "table.csv"

   print "" > "lxch.h"
   print "" > "lxhp.h"
   print "" > "lxnp.h"
   print "" > "lxtv.h"
#  print "" > "table.csv"
   for (i=0; i<=lxmax; i++) { if (i<lxmax) {e = ","} else {e = " "}
      printf("'%c'%c\n",lxch[i],e) >> "lxch.h"
      printf("%d%c\n",lxhp[i],e) >> "lxhp.h"
      printf("%d%c\n",lxnp[i],e) >> "lxnp.h"
      printf("%d%c\n",lxtv[i],e) >> "lxtv.h"
#     printf("%d,'%c',%d,%d,%d\n",
#       i,lxch[i],lxnp[i],lxhp[i],lxtv[i]) >> "table.csv"
      }

#                           Special constants
   print "lxvars.h"
   print sprintf("#define	lxmax	%d",lxmax) > "lxvars.h"
   print sprintf("#define	XXenvvar	%d",labeltv["XLenvvar"]) >> "lxvars.h"
   print sprintf("#define	XLlastsc	%d",labeltv["XLtextwid"]) >> "lxvars.h"
   print sprintf("#define	XLlastenv	%d",labeltv["XLscale"]) >> "lxvars.h"

#  print "lxcst.p"
   print "lxcst.h"
#  print "" > "lxcst.p"
   print "" > "lxcst.h"
   for (i=0; i<=nlabels; i++) { if ( label[i] !~ /^<[a-zA-Z]/ ) { 
#    print sprintf("%s = %d;",label[i],labeltv[label[i]]) >> "lxcst.p"
     print sprintf("#define	%s	%d",label[i],labeltv[label[i]]) >> "lxcst.h" }
     }

   print "terminals"
   print "" > "terminals"
   for (i=1; i<ntv; i++) {
     print sprintf("\"%s\",",tvtoken[i]) >> "terminals"
     }
   print sprintf("\"%s\"",tvtoken[ntv]) >> "terminals"

   print "tokens.y"
   print "" > "tokens.y"
   for (i=1; i<=nlabels; i++) {
    print sprintf("%%token	%s %d",label[i],labeltv[label[i]]) >> "tokens.y" }

} # END
