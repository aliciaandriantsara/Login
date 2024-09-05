#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "adresseip.h"




int main()
{
    char *title="Adressse IP";
    
    
    head(title);
    head_of_body();
    int number_of_character=0;
    number_of_character=strlen(getenv("QUERY_STRING"));
    last_test(number_of_character);    
    
    foot_of_body();
    return (0);
}
