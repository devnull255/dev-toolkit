#include <datagenerator.h>
int randint(int max_int) {
/*********************************************************************
 * Returns a random integer from 0 to max_int
 * *******************************************************************/

  int i = 0;
  time_t t;

  srand((unsigned) time(&t));

  i = rand() % (max_int + 1);

  return(i);
} 
