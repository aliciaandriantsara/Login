#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "changement.h"

void body_of_body(char *name_student, char* firstname_student, char* gender_student, int number_of_student_to_modify)
{
    printf("        <center>\n");
    printf("        <form action=\"modifier.cgi\" method=\"get\">\n");
    printf("        Name : <input type=\"text\" name=\"student_name\" value=\"%s\"/>\n", name_student);
    printf("        <br/>\n");
    printf("        Fistname : <input type=\"text\" name=\"student_firstname\" value=\"%s\"/>\n", firstname_student);
    printf("        <br/>\n");
    printf("        Genre : <input type=\"text\" name=\"student_gender\" value=\"%s\"/>\n", gender_student);
    printf("        <br/>\n");
    printf("            <input type=\"hidden\" name=\"number_of_student_to_modify\" value=\"%d\" />", number_of_student_to_modify);
    printf("            <input type=\"submit\" value=\"send\"/>\n");
    printf("        </form>\n");
    printf("        </center>\n");


}

void changing_plus_in_space(char *text)
{
    //Changer le + dans student_name par " "
    int i;
    for(i=0; i<100; i++)
    {
        if(text[i] =='+')
        {
            text[i]=' ';
        }
    }
}


void foot_of_body()
{
    // printf("        <p>\n");
    // printf("            Cliquez le lien suivant pour voir la liste que vous venez de modifier\n");
    // printf("            <a href=\"test2.html\">Liste des etudiants inscrits a jour</a>\n");
    // printf("        </p>\n");
    printf("    </body>\n");
    printf("</html>\n");
}

void head_of_body()
{
    printf("    <body>\n");
    printf("        <h1>Modification</h1>\n");
}


void head(char *title)
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>%s</title>\n", title);
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"changement.css\"/>\n");

    printf("    </head>\n");
}
