#include <devtools.h>
/*
makelist(12,"dog","cat","bird","pig","dog");
*/
int main(int argc, char** argv) {
   //char *list[] = {"the","brown","jumped","over","the","fence",NULL};
   char **list = makelist(6,"the","brown","jumped","over","the","fence");
   char **names = makelist(5,"Bobby","Ann","Melinda","Carole","Linda");
   int i;
   size_t len = strllen(list);
   printf("Length of list before append: %d\n",len);
   printf("Elements of list before append:\n");
   for (i = 0;i < len;i++)
     printf("%s\n",list[i]);
   printf("\n");
   list_append("dog",list);
   len = strllen(list);
   printf("Length of list after append: %d\n",len);
   printf("Elements of list after append:\n");
   for (i = 0;i < len;i++)
     printf("%s\n",list[i]);

   printf("\n");
   printf("names list before append:\n");
   len = strllen(names);
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);

   printf("\n");
   names = sortlist(names);
   len = strllen(names);
   printf("sorted names list before append:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);

   printf("\n");
   list_append("Ted",names);
   len = strllen(names);
   printf("names list after append:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);
  
   printf("\n");
   names = sortlist(names);
   len = strllen(names);
   printf("sorted names list after append:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);
 
   exit(0);
}

   
