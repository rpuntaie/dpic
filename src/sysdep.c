#include <stdlib.h>

unsigned long
ordp(p) char *p; { return (p==NULL) ? (long) 0 : (long) abs((long)p); }
