
/^[ 	]*$/ { next }

/^ *[0-9][0-9]* [a-zA-Z]/ {
     prod = substr($2,0,length($2)-1);
     subprod = 1;
     print sprintf("#define %s%d 	%d", prod,subprod,($1)+1);
     subprod++;
     next
     }

{    print sprintf("#define %s%d 	%d", prod,subprod++,($1)+1); next }
