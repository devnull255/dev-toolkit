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
void usage(void) {
/* print help usage */
printf("Usage: dg [options]\n");
printf("  Options:\n");
printf("      -h help\n");
printf("      -s|--spec-string <spec string>\n");
printf("      -f|--spec-file  <input spec file>\n");
printf("      -o|--outfile <output data file>\n");
printf("      -n|--number <number of records to generate>\n");
printf("\n");
}

char *gen_rec(char *spec_list_str,char *delim) {
//return a generated string based on the spec_str_list
  char **spec_list = split(spec_list_str,",");
  char **fields;
  int len = strllen(spec_list);
  fields = malloc(sizeof(char*) * len + 1);
  int num_chars = 0;
  char **spec_ent = NULL;
  int cmpres = -1;
  for (int i = 0; i < len; i++) {
      if (strstr(spec_list[i],"numeric") != NULL) {
           spec_ent = split(spec_list[i],":");
           num_chars = atoi(spec_ent[1]);
           fields[i] = mknumeric(num_chars);
      } else
      if (strstr(spec_list[i],"alpha") != NULL ) { 
           spec_ent = split(spec_list[i],":");
           num_chars = atoi(spec_ent[1]);
           fields[i] = mkalpha(num_chars);
      } else
      if (strstr(spec_list[i],"alphanumeric") != NULL ) { 
           spec_ent = split(spec_list[i],":");
           num_chars = atoi(spec_ent[1]);
           fields[i] = mkalphanum(num_chars);
      } else
      if (strcmp(spec_list[i],"lastName") == 0)
         fields[i] = randomstring(lastNames);
      else
        if (strcmp(spec_list[i],"firstName") == 0)
           fields[i] = randomstring(firstNames);
      else
        if (strcmp(spec_list[i],"state") == 0)
           fields[i] = randomstring(states);
      else
         fields[i] = spec_list[i];
      
   }
   fields[len] = NULL;  
   return join(fields,delim);
}
         
int main(int argc, char **argv) {
  int c;
  int number = 0;
  char *spec_list_string = NULL;
  char *spec_filename = NULL;
  char *outfilename = NULL;
  char *delim = "|"; //default delimiter
  

  while(1) {  
    static struct option long_options[] = {
        {"help",no_argument, 0, 'h'},
        {"spec-string",required_argument, 0, 's'},
        {"spec-file",  required_argument, 0, 'f'},
        {"outfile",    required_argument, 0, 'o'},
        {"number",     required_argument, 0, 'n'},
        {"delim",     required_argument, 0, 'd'},
        {0,0,0,0}
    };

    int option_index = 0;

    c = getopt_long(argc, argv, "s:f:o:n:d:h",
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
        case 'd':
           delim = optarg;
           break;
        case 'h':
           usage();
           exit(0);
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
    for (int i=1;i <= number; i++) {
       printf("%s\n",gen_rec(spec_list_string,delim));
    }        
  }
  exit(0);
}

