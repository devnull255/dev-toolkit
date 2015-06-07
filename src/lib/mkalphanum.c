#include <devtools.h>
#include <string.h>
char *mkalphanum(int len) {
 //returns an alphanumeric string of len length
  int size = len + 1;
  char *s = malloc(sizeof(char) * size);
  char c;
  s[size] = 0;
  for (int i = 0; i < size;i++) {
    int typeflag = randint(1);
    if (typeflag == 0)
       s[i] = randalpha();
    else
       s[i] = randint(9) + '0';
  }
  s[size] = '\0';
  return s;
}
