#include <devtools.h>
#include <unistd.h>


int randint(int max_int) {
/*********************************************************************
 * Returns a random integer from 0 to max_int
 * *******************************************************************/

  int i = 0;
  static int times_called = 0;
  time_t t;
  //sleep(1);

  if (times_called == 0) {
    time(&t);
    srandom((unsigned)t);
    times_called++;
  }

  i = random() % (max_int + 1);

  return(i);
} 
