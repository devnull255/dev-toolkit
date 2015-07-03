#include <hashtable.h>
#include <string.h>

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
     hash_size hash = 0;
     while (*key) 
        hash+= (unsigned char)*key++;

     return hash;
}


/********************************************************************* 
 * Initialization                                        
 * hashtbl_create sets up the initial structure of the hash table.
 *********************************************************************/

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc) (const char *)) {
   HASHTBL *hashtbl;

   if (!(hashtbl = malloc(sizeof(HASHTBL))) return NULL;

   if (!(hashtbl->node = calloc(size,sizeof(struct hashnode_s*)))) {
       free(hashtbl);
       return NULL;
   }

   hashtbl->size = size;
   
   if (hashfunc)
       hashtbl->hashfunc = hashfunc;
   else
       hashtbl->hashfunc = def_hashfunc;

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
      /*	fprintf(stderr, "hashtbl_insert() key=%s, hash=%d, data=%s\n", key, hash, (char*)data);*/
      
     node = hashtbl->nodes[hash]
     while(node) {
        if (!strcmp(node->key,key)) {
          node->data = data;
          return 0;
        }
        node = node->next;
     }
     if (! (node = malloc(sizeof(struct hashnode_s))) 
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

