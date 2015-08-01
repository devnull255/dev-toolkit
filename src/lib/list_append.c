#include <devtools.h>
/*********************************************************************************
 * list_append
 * appends a new string to a NULL-terminated string list
 *********************************************************************************/
int list_append(char *new_string, char **list) {
   size_t len = strllen(list);
   size_t pos = len;

   return list_insert(new_string, list,pos);
}
