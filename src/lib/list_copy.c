/*************************************************************************
 * list_copy.c 
 * list_copy
 * Returns a copy of string list
 *************************************************************************/
#include <devtools.h>
char **list_copy(char **sl) {
  size_t index;
  size_t len = strllen(sl);
  char **new_list = malloc(sizeof(char *) * (len + 1));
  for (index = 0; index < len;index++)
     new_list[index] = strdup(sl[index]);
  new_list[index] = NULL;
  return new_list;
} 
