#include <devtools.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char c = randalpha();
  assert((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')  );
  printf("randalpha(): %c\n",c);
  exit(0);
} 
