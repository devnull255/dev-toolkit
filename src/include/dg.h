/*********************************************************
 * dg.h
 * Header for datagenerator functions, variables and 
 * constants
 * *******************************************************/
#include <devtools.h>
#ifndef __DG_H__
#define __DG_H__
char *firstNames[] = {"Michael","Paul","Amy","Heidi","Cheryl","David",
    "Dan","Madison","Meryl","Keegan","Foster",NULL};

char *lastNames[] = {"Anderson","Baker","Carlson","DeCamp","Edwards",
    "Fritz","Gay","Howards","Iverson","Jackson","Keyes","Lundeen",
    "Mabin","Nickerson","O'Reilley","Peterson","Quaid","Rhodes",
    "Stark","Uhura","Vedders","Williams","Yeats","Zane",NULL};

char *states[] = {"AL","AK","AZ","AS","CA","CO","CN",
                  "DE","FL","GA","HA","ID","IL","IN",
                  "IA","KS","KY","LA","ME","MD","MA",
                  "MI","MN","MS","MO","MT","NE","NV",
                  "NH","NJ","NM","NY","NC","ND","OH",
                  "OK","OR","PA","RI","SC","SD","TN",
                  "TX","UT","VT","VA","WA","WV","WI",
                  "WY",NULL};

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

char *state(void);
char *gen_rec(char *spec_str_list,char *delim);
char *current_ts(void);
#endif
