#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char * strlist[] = {"Four",
       "score",
       "and",
       "seven",
       "years",
       "ago",
       NULL}; 
        
  int i;
  
  for (i=0; strlist[i] != NULL;i++)
     printf("%s\n",strlist[i]);

  int sl_len = strllen(strlist);
  printf("strllen(): %d\n",sl_len);
  assert(sl_len == i);
  exit(0);
} 
