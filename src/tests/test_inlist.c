#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char * strlist[] = {"alpha",
       "numeric",
       "alpha",
       "lastName",
       "firstName",
       "ssn",
       NULL}; 
        
  char *present = "numeric";
  char *absent = "absent"; 
  printf("Testing inlist():present value:%s\n",present);
  assert(inlist(present,strlist) == 1);
  printf("Testing inlist():absent value: %s\n",absent);
  assert(inlist(absent,strlist) == 0);
  exit(0);
} 
