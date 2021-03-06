#include <hashtable.h>
#include <stdio.h>

int main() {

  HASHTBL *hashtbl;
  char *spain, *italy;
  char *key;
  struct hashnode_s *entry;
  int index;
  if (! (hashtbl = hashtbl_create(16, NULL))) {
       fprintf(stderr, "ERROR: hashtbl_create() failed\n");
        exit(EXIT_FAILURE);

  }

  hashtbl_insert(hashtbl, "France", "Paris");
  hashtbl_insert(hashtbl, "England","London");
  hashtbl_insert(hashtbl, "Sweden","Stockholm");
  hashtbl_insert(hashtbl, "Germany","Berlin");
  hashtbl_insert(hashtbl, "Norway", "Oslo");
  hashtbl_insert(hashtbl, "Italy", "Rome");
  hashtbl_insert(hashtbl, "Spain", "Madrid");
  hashtbl_insert(hashtbl, "Estonia", "Tallinn");
  hashtbl_insert(hashtbl, "Netherlands", "Amsterdam");
  hashtbl_insert(hashtbl, "Ireland", "Dublin");

  printf("Listing keys by moving through hashtbl->nodes\n");
 
  for (index = 0;index < hashtbl->size;index++) {
    if (hashtbl->nodes[index]) {
        entry = hashtbl->nodes[index];
        while (entry) {
           key = entry->key;
           printf("%s\n",entry->key);
           entry = entry->next;
           if (entry)
             printf("Found key %s as next for hash %d, which also had key: %s\n",entry->key,(int)index,key);
        }
    }
  }
       
  printf("Listing keys retrieved with hashtbl_keys\n");
  char **keys = hashtbl_keys(hashtbl);
  hash_size count = hashtbl_count(hashtbl);
  printf("hashtable contains %d entries\n",(int)count);
  for (index = 0; index < count;index++)
     printf("%s\n",keys[index]);

       
  printf("After insert:\n");
  italy = hashtbl_get(hashtbl, "Italy");
  printf("Italy: %s\n",italy?italy:"-");
  spain = hashtbl_get(hashtbl,"Spain");
  printf("Spain: %s\n",spain?spain:"-");

  hashtbl_remove(hashtbl, "Spain");

  printf("After remove:\n");
  spain = hashtbl_get(hashtbl,"Spain");
  printf("Spain: %s\n",spain?spain:"-");

  hashtbl_resize(hashtbl, 8);

  printf("After resize:\n");
  italy = hashtbl_get(hashtbl,"Italy");
  printf("Italy: %s\n", italy?italy:"-");

  hashtbl_destroy(hashtbl);

  return 0;

}
