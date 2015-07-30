# Developer Toolkit
This Developer Toolkit is still underdeveloped.  A work in progress.
## Overview

This is a toolkit of programs and scripts used for developing and testing in Unix and Linux environments.  It contains several command-line utilities and libraries implemented in C, some shell script packages and other components that have been helpful to me as a developer.  It is an on-going project so it will continue to grow and change as I continue to work on it. Most of these things developed from my work in all kinds of Unix and Linux environments.

## Contents 

* src/lib/devtools - library of datagenerating and text generating functions
* src/bin/dg - datagenerator command-line utility
* src/tests/test_funcs.sh - Runs test of test programs
* Makefile - used to build c-compiled binaries, including various utilities, test programs, libraries; runs tests.
* README.md - This file you are reading.

## Library Functions

### cstring_cmp
String compare function used for sortlist

```
int cstring_cmp(const void *a, const void*b);
```

### sortlist
Returns a sorted string list

```
char **sortlist(char **strlist);
```

### randint
Returns a random int

```
int randint(int max_int);
```

### randalpha
Returns a random alphabetic character

```
char randalpha(void);
```

### mkalpha
Returns a randomly generated alphabetic string of length *len*

```
char *mkalpha(int len);
```

### mkalphanum
Returns a randomly generated alphanumeric string of length *len*

```
char *mkalphanum(int len);
```

### mknumeric 
Returns a randomly generic numeric string of length *len*

```
char *mknumeric(int len);
```

### split
Returns a char** list of tokens of string *s* and using separator *delim*.
The list itself is terminated by a NULL.

```
char **split(char *s,char *delim);
```

### strllen 
Returns the length of string list *sl*.  Only `char **` lists terminated by a NULL should be used with this
function.  Using it with any other type of list is undefined.

```
int strllen(char **sl);
```

### join
Returns a c-string created from a string list *strlist* joined with separator *sep*.

```
char *join(char **strlist,char *sep);
```

### inlist
Tests if string *s* is in string list *list*. Returns non-zero for true, zero for false.

```
int inlist(char *str,char **list);
```

### randomstring
Returns a randomly selected string from *list* if *list* is a null-terminated string list.

```
char *randomstring(char **list);
```

### makelist
Returns a null-terminated string list of size *capacity*, populated by variable number of strings less than or equal to *capacity*.

```
char **makelist(size_t capacity,...);
```

### list_insert
Used to insert string *new_string* into string list *list*.  Returns new list length.

```
int list_insert(char *new_string,char **list,int pos);
```
