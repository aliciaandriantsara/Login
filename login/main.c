#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "authentification.h"


int main()
{
    char *title="Login";

    user_data* users=NULL;
    char user_name[50];
    int number_of_users=0;
    char user_password[20];
    char *recovery=NULL;
    int number_character=0;
    int verification=0;
    int number_of_user=0;
    int *pnumber_of_user=NULL;
    pnumber_of_user=&number_of_user;
    FILE* file=NULL;   
    head(title);

    number_character=strlen(getenv("QUERY_STRING"));
    recovery=(char*)malloc(number_character*sizeof(char));
    strcpy(recovery, getenv("QUERY_STRING"));
    sscanf(recovery, "user_name=%[^&]&user_password=%s", user_name, user_password);
    file=fopen("user_data.txt", "r");
    openning_file(file);
    number_of_users=counter_of_users(file);
    users=(user_data*)malloc(number_of_users*sizeof(user_data));
    users=recovering_data(file, number_of_users);
    verification=searching_user(user_name, user_password, users, number_of_users, pnumber_of_user);
    if(verification == 1)
    {
        head_of_body(users, number_of_user);
        body_of_body();
    }
    else 
    {
        head_of_body_for_no_user();
        body_of_body_for_no_user();
    }
    foot_of_body();
    free(users);
    fclose(file);
    return (0);

}
