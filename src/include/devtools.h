/*********************************************************
 * devtools.h
 *
 * contains prototypes and declarations for the datagenerator
 * library.
 * *******************************************************/
#ifndef __DEVTOOLS__
#define __DEVTOOLS__
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
typedef struct string_list {
   int size;
   char **items;
} StringList;

int randint(int max_int);
char randalpha(void);
char *mkalpha(int len);
char *mkalphanum(int len);
char *mknumeric(int len);
char **split(char *s,char *delim);
int strllen(char **sl);
char *join(char **strlist,char *sep);
int inlist(char *str,char **list);
char *randomstring(char **list);
char **makelist(int capacity);
int list_insert(char **sl,char *s,int pos);
int list_append(char **sl,char *s);
int grow_list(char **sl,int added_slots);
char **list_copy(char **sl);
char *list_pop(char **sl);
#endif
