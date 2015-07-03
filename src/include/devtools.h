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
#endif
