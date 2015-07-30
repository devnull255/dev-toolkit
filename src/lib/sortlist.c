#include <devtools.h>
int cstring_cmp(const void *a, const void*b) {
  /* compares two strings */
  const char **ia = (const char **)a;
  const char **ib = (const char **)b;
  return strcmp(*ia, *ib);
}

char **sortlist(char **strlist) {
  int len = strllen(strlist);
  qsort(strlist,len,sizeof(char *),cstring_cmp);
  return strlist;
}

