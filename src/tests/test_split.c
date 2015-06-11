#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char *s = "Welcome to the jungle!";
  char **strings = split(s," ");
  printf("split(): %s\n",s);
  int tokens = 0;
  for (int i = 0; i < 4; i++) {
    printf("%s\n",strings[i]);
    if (strlen(strings[i]) > 0) 
       tokens++;
  }

  assert(tokens == 4);

  exit(0);
} 
