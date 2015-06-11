#include <devtools.h>
char **split(char *s,char *delim) {
  char **res = NULL;
  int n_delims = 0, i;

  /* split string and append tokens to 'res' */
  char *work_s = strdup(s);  //So we don't destroy s
  char *p = strtok(work_s,delim);

  while (p) {
     res = realloc(res, sizeof(char *) * ++n_delims);
     if (res == NULL) {
        perror("Error allocating memory for res.\n");
        exit(-1);
     }
     res[n_delims - 1] = strdup(p);
     p = strtok(NULL,delim);
  }

  /* realloc one extra element for the last NULL */
  res = realloc(res, sizeof (char *) * (n_delims + 1));
  free(work_s);  //free memory of work string clobbered by strtok
  return res;
}
  


  
