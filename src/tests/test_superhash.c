#include <stdio.h>
#include <superhash.h>

int main(int argc, char **argv) {
  int hash;
  int bucketsize = 16;
  char *s = "Goldenrod";
  hash = SuperFastHash(s,bucketsize);
  printf("Hash value of %s is %d\n",s,hash);
  printf("Bucket for hashvalue %d is %d\n",bucketsize,hash % bucketsize);
  exit(0);
}
