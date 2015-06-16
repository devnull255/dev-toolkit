/*****************************************************
 *  dg.c datagenerator utility
 *  Usage: dg [options] 
 *  Options:
 *     -h help
 *     -s|--spec-string <spec string>
 *     -f|--spec-file  <input spec file>
 *     -o|--outfile <output data file>
 *****************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <dg.h>

int main(int argc, char **argv) {
  int c;
  int number = 0;
  char *spec_list_string = NULL;
  char *spec_filename = NULL;
  char *outfilename = NULL;
  

  while(1) {  
    static struct option long_options[] = {
        {"spec-string",required_argument, 0, 's'},
        {"spec-file",  required_argument, 0, 'f'},
        {"outfile",    required_argument, 0, 'o'},
        {"number",     required_argument, 0, 'n'},
        {0,0,0,0}
    };

    int option_index = 0;

    c = getopt_long(argc, argv, "s:f:o:n:",
        long_options, &option_index);

    if (c == -1)
       break;

    switch(c) {
        case 's':
           spec_list_string = strdup(optarg);
           printf("spec_string_list: %s\n",spec_list_string);
           break;
        case 'f':
           spec_filename = strdup(optarg);
           printf("spec_file: %s\n",spec_filename);
           break;
        case 'o':
           outfilename = strdup(optarg);
           printf("outfilename: %s\n",outfilename);
           break;
        case 'n':
           number = atoi(optarg);
           printf("number: %d\n",number);
           break;
        case '?':
           break;
        default:
          abort();
     }
  }
  if (spec_list_string != NULL) {
    if (number == 0 )
      number = 10;
    for (int i=0;i <= number; i++) {
       printf("%s\n",gen_rec(spec_list_string));
    }        
  }
  printf("%d\n",randint(100));
  exit(0);
}

char *gen_rec(char *spec_str_list) {
//return a generated string based on the spec_str_list
 return "gen_rec stub";
}
