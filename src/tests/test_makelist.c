/***********************************************
 *  test_makelist
 *  tests the makelist function
 ***********************************************/
#include <devtools.h>
#include <assert.h>
int main(int argc, char **argv) {

    char **l = makelist(12,"dog","cat","bird","pig","dog");
    int len = strllen(l);
    printf("len is: %d\n",len);
    int i;
    for (i = 0; i < len; i++) {
       printf("%d:%s\n",i,l[i]);
    }
    exit(0);
}
