#include <devtools.h>
#include <string.h>
#include <stdlib.h>

char **makelist(size_t capacity,...) {
  char **list = calloc(capacity + 1,sizeof(char *));
  va_list ap;
  int index =0;
  char *s;
  va_start(ap,capacity);
  s = va_arg(ap,char *);
  while (index < capacity) {
     if (s) {
        list[index] = strdup(s);
        s = va_arg(ap,char *);
     }
     else
       list[index] = "empty";

     index++;
  }
  va_end(ap);

  list[capacity] = NULL;
  return list;
} 


