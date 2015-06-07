#include <devtools.h>
#define UPPERCASE 0
#define LOWERCASE 1

//this module includes the randchar function, which returns a random
//ASCII alphabetic character
// 'A' is 65
// 'a' is 97

/* randalpha returns a random alphabetic character */
char randalpha(void) {
  int which_case = randint(1);
  char letter = randint(25);
   
  switch(which_case) {
     case UPPERCASE :
          letter = letter + 'A';
          break;
     case LOWERCASE :
          letter = letter + 'a';
          break;
  } 
   
  return letter; 
}

