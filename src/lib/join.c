#include <devtools.h>
char * join(char **list,char *delim) {
  int i;
  int len = strllen(list);
  char *result;
  int total_len = 0;
  for (i=0; i < len; i++)
     total_len += strlen(list[i]);
  total_len += strlen(delim) * len - 1;
  result = malloc(sizeof(char) * total_len + 1);
  for (i = 0;i < len;i++) {
    strcat(result,list[i]);
    if (i < (len - 1))
       strcat(result,delim);
  }
  return result; 
} 
