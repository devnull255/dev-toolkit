#include <stdlib.h>
#include <stdio.h>
#include <datagenerator.h>

int main(int argc,char **argv,char **env) {

  if (argc < 2) {
    printf("Usage: rand <ceiling>\n");
    exit(1);
  }
  
  int ceiling = atoi(argv[1]);

  printf("%d\n",randint(ceiling));
  exit(0);
} 
