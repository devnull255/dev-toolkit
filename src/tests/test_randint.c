#include <datagenerator.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = randint(100);
  assert(x >= 0);
  assert(x <= 100);
  printf("randint(100): %d\n",x);
  exit(0);
} 
