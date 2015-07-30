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
#include <stdarg.h>
typedef struct string_list {
   int size;
   char **items;
} StringList;
int cstring_cmp(const void *a, const void*b);
char **sortlist(char **strlist);
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
char **makelist(size_t capacity,...);
int list_insert(char *new_string,char **list,int pos);
int list_append(char *new_string, char **list);
int grow_list(char **sl,int added_slots);
char **list_copy(char **sl);
char *list_pop(char **sl);
#endif
