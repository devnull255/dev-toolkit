#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char * strlist[] = {"alpha",
       "numeric",
       "beta",
       "lastName",
       "firstName",
       "ssn",
       NULL}; 
        
  printf("%s\n",join(strlist,"|"));
  char * rec = join(strlist,"|");
  printf("length of rec is: %d\n",strlen(rec));
  exit(0);
} 
