
/^[ 	]*$/ { next }

/^ *[0-9][0-9]* [a-zA-Z]/ {
     prod = $2;
     subprod = 1;
     print sprintf("#define %s%d 	%d", prod,subprod,($1)+1);
     subprod++;
     next
     }

{    print sprintf("#define %s%d 	%d", prod,subprod++,($1)+1); next }
