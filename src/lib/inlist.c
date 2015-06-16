#include <devtools.h>

int inlist(char *str,char **list) {
  //returns 1 if str is in the list
 //0 if it is not
  int i = 0;
  int result = 0;
  int len = strllen(list);
  if (len == 0)
     return 0;
  for (i = 0; i < len; i++) 
      if (strcmp(str,list[i]) == 0)
         result = 1;
  return result;
} 

