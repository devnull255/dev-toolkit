#include <devtools.h>

char *randomstring(char **list) {
  //returns a random string from a string list

  int len = strllen(list);
  int randind = randint(len - 1);
  return list[randind];
}

