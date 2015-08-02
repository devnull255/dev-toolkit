#include <devtools.h>
/*
makelist(12,"dog","cat","bird","pig","dog");
*/
int main(int argc, char** argv) {
   char **list = makelist(6,"the","brown","jumped","over","the","fence");
   char **names = makelist(5,"Bobby","Ann","Melinda","Carole","Linda");
   char **copy1;
   char **copy2;
   size_t i;

   size_t len = strllen(list);
   printf("Elements of list to copy:\n");
   for (i = 0;i < len;i++)
     printf("%s\n",list[i]);
   printf("\n");

   copy1 = list_copy(list);
   len = strllen(copy1);
   printf("Elements of list copy:\n");
   for (i = 0;i < len;i++)
     printf("%s\n",list[i]);

   printf("\n");
   len = strllen(names);
   printf("Elements of names\n");
   len = strllen(names);
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);

   printf("\n");
   copy2 = list_copy(names);
   len = strllen(copy2);
   printf("copy2 elements:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);
 
   exit(0);
}

   
