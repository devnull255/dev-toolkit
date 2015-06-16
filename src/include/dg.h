/*********************************************************
 * dg.h
 * Header for datagenerator functions, variables and 
 * constants
 * *******************************************************/
#include <devtools.h>

char *firstNames[] = {"Michael","Paul","Amy","Heidi","Cheryl","David",
    "Dan","Madison","Meryl","Keegan","Foster",NULL};

char *lastNames[] = {"Anderson","Baker","Carlson","DeCamp","Edwards",
    "Fritz","Gay","Howards","Iverson","Jackson","Keyes","Lundeen",
    "Mabin","Nickerson","O'Reilley","Peterson","Quaid","Rhodes",
    "Stark","Uhura","Vedders","Williams","Yeats","Zane",NULL};

char *specTypes[] = {"alpha",
    "numeric",
    "alphanum",
    "lastName",
    "firstName",
    "streetName",
    "streetType",
    "state",
    "city",
    "ssn",
    "email",
    NULL
};

char *firstName(void);
char *lastName(void);
char *gen_rec(char *spec_str_list);


