#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "authentification.h"

typedef struct 
{
    char name[50];
    char password[20];
}user_data;




void body_of_body_for_no_user()
{
    printf("        <p>le nom d'utilisateur et le mot de passe ne correpondent pas veuillez reessayer</p>\n");
    printf("        <h1>Login</h1>\n");
    printf("        <center>\n");
    printf("            <form action=\"authentification.cgi\" method=\"get\">\n");
    printf("                Username : <input type=\"text\" name=\"user_name\"/>\n");
    printf("                </br>\n");
    printf("                Password :<input type=\"password\" name=\"user_password\"/>\n");
    printf("                <input type=\"submit\" value=\"Login\"/>\n");
    printf("            </form>\n");
    printf("        </center>\n");
    
}

void head_of_body_for_no_user()
{
    printf("    <body>\n");
    printf("        <h1>Failure</h1>\n");

}

void foot_of_body()
{
    printf("    </body>\n");
    printf("</html>\n");
}

void head_of_body(user_data* users, int number_of_user)
{
    printf("    <body>\n");
    printf("        <h1>Adresse IP</h1>\n");
    printf("        <p>Beinvenue dans votre compte %s</p>\n", users[number_of_user].name);
}

void body_of_body()
{
    printf("        <p>Entrez une adresse IP sous la forme XXX.XXX.XXX.XXX</p>\n");
    printf("        <center>\n");
    printf("            <form action=\"adresseip.cgi\" method=\"get\">\n");
    printf("                <input type=\"text\" name=\"ip\"/>\n");
    printf("                <input type=\"submit\" value=\"Send\"/>\n");
    printf("            </form>\n");
    printf("            <form action=\"logout.cgi\" method=\"get\">\n");
    printf("                <input type=\"submit\" value=\"Logout\"/>\n");
    printf("            </form>\n");
    printf("        </center>\n");

}

void head(char *title)
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>%s</title>\n", title);
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"authentification.css\"/>\n");
    printf("    </head>\n");
}

int searching_user(char *user_name, char* user_password, user_data* users, int number_of_users, int *pnumber_of_user)
{
    int i;
    int verification=0;
    for(i=1; i<=number_of_users;i++)
    {
        if(strcmp(users[i].name, user_name) == 0 && strcmp(users[i].password, user_password) == 0)
        {
            verification=1;
            *pnumber_of_user=i;
        }
    }
    return (verification);
}

user_data* recovering_data(FILE* file, int number_of_users)
{
    int i=0;
    char line[100];
    user_data* users=NULL;
    users=(user_data*)malloc(number_of_users*sizeof(user_data));
    rewind(file);
    while(fgets(line, 100, file) != 0)
    {
        i++;
        sscanf(line, "%[^;];%[^;]", users[i].name, users[i].password);
    }
    return (users);
}



int counter_of_users(FILE* file)
{
    int number_of_users=0;
    char line[100];
    rewind(file);
    while(fgets(line, 100, file) != 0)
    {
        number_of_users++;
    }
    return (number_of_users);
}


void openning_file(FILE* file)
{
    if(file == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
    }
}

