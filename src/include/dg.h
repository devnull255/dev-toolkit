/*********************************************************
 * dg.h
 * Header for datagenerator functions, variables and 
 * constants
 * *******************************************************/
#include <devtools.h>

char *firstNames[] = {"Michael","Paul","Amy","Heidi","Cheryl","David",
    "Dan","Madison","Meryl","Keegan","Foster"};

char *lastNames[] = {"Anderson","Baker","Carlson","DeCamp","Edwards",
    "Fritz","Gay","Howards","Iverson","Jackson","Keyes","Lundeen",
    "Mabin","Nickerson","O'Reilley","Peterson","Quaid","Rhodes",
    "Stark","Uhura","Vedders","Williams","Yeats","Zane"};

char *firstName(void);
char *lastName(void);
char *gen_rec(char *spec_str_list);


