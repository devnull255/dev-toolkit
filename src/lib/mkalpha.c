#include <devtools.h>
#include <string.h>
char *mkalpha(int len) {
 //returns an alphabetic string of len length
  int size = len + 1;
  char *s = malloc(sizeof(char) * size);
  char c;
  s[size] = 0;
  for (int i = 0; i < size;i++) {
    c = randalpha(); 
    s[i] = c;
  }
  s[size] = '\0';
  return s;
}
