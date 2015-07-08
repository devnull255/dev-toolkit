#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sortlist.h>

int main() {
  char *strlist[] = {"alpha",
       "numeric",
       "alpha",
       "lastName",
       "firstName",
       "ssn",
       NULL}; 

  char *s;
  int i;
        
  printf("strlist before sort:\n");
  for (i = 0; i < 6; i++)
     printf("%s\n",strlist[i]);
  sortlist(strlist);
  printf("\n");
  printf("strlist after sort:\n");
  for (i = 0;i < 6; i++)
    printf("%s\n",strlist[i]);

  exit(0);
} 
