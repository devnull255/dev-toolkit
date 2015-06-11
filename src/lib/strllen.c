#include <devtools.h>
int strllen(char **strlist) {
 // returns the length of a strlist
 int i = 0;
 while (strlist[i] != NULL)
   i++;
 return i;
} 
