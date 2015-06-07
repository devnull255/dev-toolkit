#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char *s = mkalpha(10);
  printf("mkalpha(): %s\n",s);
  assert(strlen(s) == 11);
  for (int i=0;i <= 10;i++) {
     assert(isalpha(s[i]));
  }
  exit(0);
} 
