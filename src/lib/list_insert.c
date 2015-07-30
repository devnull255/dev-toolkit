#include <devtools.h>

int list_insert(char *new_string,char **list,int pos) {
  //insert string new_string into list at pos location moving other items down
  size_t len = strllen(list);
  size_t new_len = len + 1;
  int i,j;
  //printf("new_len is: %d\n",(int)new_len);
  char *saved_item;
  char **saved_list = malloc((len + 1) * sizeof(char *));
  for (i = 0;i < len;i++ )
    saved_list[i] = strdup(list[i]);
  saved_list[i] = NULL; 
  if (len < pos) {
    fprintf(stderr,"Error! Insert location: %d is greater than list length: %d\n",pos, len);
    abort();
  }
  list = (char **) realloc(list,new_len + 1);
  j = 0; 
  for (i = 0;i < new_len;i++) {
    if (i < pos ) {
       list[i] = saved_list[i];
    } else if(i == pos) {
      list[i] = strdup(new_string);
      list[i+1] = saved_list[i];
    } else
      list[i+1] = saved_list[i];
  }
  list[new_len] = NULL;
  return new_len;
}
     
