#include <hashtable.h>
#include <string.h>
#include <superhash.h>
/*********************************************************************
 * Private Implementation of strdup
 *********************************************************************/

static char *mystrdup(const char *s) {
   char *b;
   if (! (b = malloc(strlen(s)+1)))
      return NULL;
   strcpy(b,s);
   return b;
}

/********************************************************************
 * def_hashfunc is a default, simple hashfunction used by hashtbl_create
 * when a user hashfunc is not provided.
 * Just adds keys ASCII values and is likely to generate lots of collisions
 * on large hash tables
 * ******************************************************************/

static hash_size def_hashfunc(const char *key) {
     const int ret_size = 32;
     hash_size hash = 0x555555;
     const int per_char = 7;

     while (*key) {
        hash ^= (unsigned char)*key++;
        hash = ( hash << per_char ) | ( hash >> (ret_size - per_char));
     }

     return hash;
}

static hash_size def_hashfunc2(const char *key) {
   const int ret_size = 32;
   return SuperFastHash(key,ret_size);
}

/********************************************************************* 
 * Initialization                                        
 * hashtbl_create sets up the initial structure of the hash table.
 *********************************************************************/

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc) (const char *)) {
   HASHTBL *hashtbl;

   if (!(hashtbl = malloc(sizeof(HASHTBL))))
       return NULL;

   if (!(hashtbl->nodes = calloc(size,sizeof(struct hashnode_s*)))) {
       free(hashtbl);
       return NULL;
   }

   hashtbl->size = size;
   
   if (hashfunc)
       hashtbl->hashfunc = hashfunc;
   else
       hashtbl->hashfunc = def_hashfunc2;

   return hashtbl;
}

/*****************************************************************************
 * hash_destroy() walks through linked lists for each possible hash value
 * and releases the elements.  It also releases the nodes array and the
 * HASHTBL.
 * ***************************************************************************/

void hashtbl_destroy(HASHTBL *hashtbl) {
      hash_size n;
      struct hashnode_s *node, *oldnode;

      for (n=0; n < hashtbl->size; ++n) {
        node = hashtbl->nodes[n];
        while(node) {
            free(node->key);
            oldnode = node;
            node = node->next;
            free(oldnode);
        }
      }
      free(hashtbl->nodes);
      free(hashtbl);
}

/*****************************************************************************
 * int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data)
 *
 * Adds a new element to the hashtbl.  To makesure the hash value is not
 * bigger than size, the result of the user provider hash function is used
 * modulo size 
 * ***************************************************************************/
int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data) {

      struct hashnode_s *node;
      hash_size hash = hashtbl->hashfunc(key) % hashtbl->size;
      fprintf(stderr, "hashtbl_insert() key=%s, hash=%d, data=%s\n", key, (int)hash, (char*)data);
      
     node = hashtbl->nodes[hash];
     while(node) {
        if (!strcmp(node->key,key)) {
          node->data = data;
          return 0;
        }
        node = node->next;
     }
     if (! (node = malloc(sizeof(struct hashnode_s))))
          return -1;
     if (! (node->key = mystrdup(key))) {
           free(node);
           return -1;
     }

     node->data = data;
     node->next = hashtbl->nodes[hash];
     hashtbl->nodes[hash] = node;
     return 0;
}

/**************************************************************************
 * int hashtbl_remove(HASHTBL *hashtbl, const char *key)
 * Removes an element from the hashtbl if found.
 * Return -1 if not found.
 * ***********************************************************************/
int hashtbl_remove(HASHTBL *hashtbl, const char *key) {
  
        struct hashnode_s *node, *prevnode = NULL;
        hash_size hash = hashtbl->hashfunc(key) % hashtbl->size;
 
        node = hashtbl->nodes[hash];
        while (node) {
           if (!strcmp(node->key,key)) {
                 free(node->key);
                 if (prevnode) 
                    prevnode->next = node->next;
                 else
                    hashtbl->nodes[hash] = node->next;
                 free(node);
                 return 0;
           }
           prevnode = node;
           node = node->next;
        }
        return -1;
}

void *hashtbl_get(HASHTBL *hashtbl,const char *key) {

         struct hashnode_s *node;
         hash_size hash = hashtbl->hashfunc(key) % hashtbl->size;

/*	fprintf(stderr, "hashtbl_get() key=%s, hash=%d\n", key, hash);*/

         node = hashtbl->nodes[hash];
         while (node) {
                if (! strcmp(node->key,key))
                   return node->data;
                node = node->next;
         }
         return NULL;
}

int hashtbl_resize(HASHTBL *hashtbl, hash_size size) {

     HASHTBL newtbl;
     hash_size n;
     struct hashnode_s *node, *nextnode;

     newtbl.size = size;
     newtbl.hashfunc = hashtbl->hashfunc;

     if (! (newtbl.nodes = calloc(size, sizeof(struct hashnode_s*))))
        return -1;

     for (n=0;n < hashtbl->size; ++n) {
         for (node = hashtbl->nodes[n]; node;node = nextnode) {
                nextnode = node->next;
                hashtbl_insert(&newtbl, node->key, node->data);
                hashtbl_remove(hashtbl,node->key);
         }
     }
     free(hashtbl->nodes);
     hashtbl->size = newtbl.size;
     hashtbl->nodes = newtbl.nodes;
     return 0;
} 

hash_size hashtbl_count(HASHTBL *hashtbl) {
/* returns count of items in hashtbl */
  /* printf("entered hashtbl_count\n"); */
  hash_size count = 0, i = 0;
  struct hashnode_s *current_node;
  for (i = 0;i < hashtbl->size;i++) 
      if (hashtbl->nodes[i]) {
         current_node = hashtbl->nodes[i];
         while (current_node) {
           count++;
           current_node = current_node->next;
         }
       }
  /* printf("hashtable contains %d items\n", (int)count); */
  return count;
}

char **hashtbl_keys(HASHTBL *hashtbl) {
  /* returns list of keys terminated by a NULL entry */
   char **keys;
   struct hashnode_s *current_node;  
   int i,keycount=0;
   //printf("Trying to get count of items\n");
   hash_size count = hashtbl_count(hashtbl);
   if (count) {
      if (!( keys = calloc(count + 1,sizeof(char *))))
        return NULL;
      for (i=0;i < hashtbl->size;i++)
         if (hashtbl->nodes[i]) {
            current_node = hashtbl->nodes[i];
            keys[keycount] = current_node->key;
            keycount++;
            while (current_node) {
               current_node = current_node->next;
               if (current_node) {
                   keys[keycount] = current_node->key;
                   keycount++;
               }
              } 
         }
      keys[count] = NULL;
      return keys;
   }
   else
     return NULL;
} 
       
           

