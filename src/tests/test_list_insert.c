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
   printf("Length of list before insert: %d\n",len);
   printf("Elements of list before insert:\n");
   for (i = 0;i < len;i++)
     printf("%s\n",list[i]);
   printf("\n");
   list_insert("dog",list,2);
   len = strllen(list);
   printf("Length of list after insert: %d\n",len);
   printf("Elements of list after insert:\n");
   for (i = 0;i < len;i++)
     printf("%s\n",list[i]);

   printf("\n");
   printf("names list before insert:\n");
   len = strllen(names);
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);

   printf("\n");
   names = sortlist(names);
   len = strllen(names);
   printf("sorted names list before insert:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);

   printf("\n");
   list_insert("Ted",names,1);
   len = strllen(names);
   printf("names list after insert:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);
  
   printf("\n");
   names = sortlist(names);
   len = strllen(names);
   printf("sorted names list after insert:\n");
   for (i = 0; i < len; i++)
      printf("%s\n",names[i]);
 
   exit(0);
}

   
