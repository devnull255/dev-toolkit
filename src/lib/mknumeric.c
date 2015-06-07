#include <devtools.h>
#include <string.h>
char *mknumeric(int len) {
 //returns a numeric string of len length
  int size = len + 1;
  char *s = malloc(sizeof(char) * size);
  char c;
  s[size] = 0;
  for (int i = 0; i < size;i++) {
    s[i] = randint(9) + '0';
  }
  s[size] = '\0';
  return s;
}
