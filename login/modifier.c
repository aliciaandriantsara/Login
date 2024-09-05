#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char firstname[100];
    char gender[20];
}student_information;

void changing_plus_in_space(char *text);
void head(char *title);
void head_of_body();
int counter_of_tr(FILE* file);
student_information* recovery_student_information(FILE* file, int number_of_student);
void writting_the_foot_of_the_file(FILE* file);
void foot_of_body();
void writting_the_list_with_modifications(FILE* file, student_information* student, int number_of_student, int number_of_student_modified, char* name_of_student_modified, char* firstname_of_student_modified, char* gender_of_student_modified);
void error_of_openning_file(FILE* file);
void display_the_list_with_modification(student_information* student, int number_of_student, int number_of_student_modified, char* name_of_student_modified, char *firstname_of_student_modified, char *gender_of_student_modified);


int main()
{
    //Declaration des variables
    char *title="Inscription";
    char recovery[100];
    // char name_student[100];
    // char firstname_student[100];
    // char gender_student[20];
    FILE* file=NULL;
    student_information *student=NULL;
    int number_of_student=0;
    char name_of_student_modified[100];
    char firstname_of_student_modified[100];
    char gender_of_student_modified[100];
    char number_of_student_to_modify[3];
    int number_of_student_modified=0;
    //Zavatra hafa mitsy
    strcpy(recovery, getenv("QUERY_STRING"));
    // student_name=Y&student_firstname=B&student_gender=Masculin
    // student_name=A&student_firstname=C&student_gender=Masculin
    sscanf(recovery, "student_name=%[^&]&student_firstname=%[^&]&student_gender=%[^&]&number_of_student_to_modify=%s", name_of_student_modified, firstname_of_student_modified, gender_of_student_modified, number_of_student_to_modify);
    changing_plus_in_space(name_of_student_modified);
    changing_plus_in_space(firstname_of_student_modified);
    number_of_student_modified=atoi(number_of_student_to_modify);
    // strcpy(name_of_student_modified, name_student);
    // strcpy(firstname_of_student_modified, firstname_student);
    // strcpy(gender_of_student_modified, gender);

    head(title);//titre de la page qui affichera si l'inscrption a reussi ou non
    head_of_body();//en tete de la page    
    file=fopen("test2.html", "r");
    error_of_openning_file(file);
    number_of_student=counter_of_tr(file);
    student=(student_information*)malloc(number_of_student*sizeof(student_information));
    student=recovery_student_information(file, number_of_student);
    fclose(file);
    file=fopen("test2.html", "w+");
    writting_the_list_with_modifications(file, student, number_of_student, number_of_student_modified, name_of_student_modified, firstname_of_student_modified, gender_of_student_modified);

    writting_the_foot_of_the_file(file);
    
    display_the_list_with_modification(student, number_of_student, number_of_student_modified, name_of_student_modified, firstname_of_student_modified, gender_of_student_modified);
    
    foot_of_body();
    fclose(file);
    free(student);
    return (0);
}

void display_the_list_with_modification(student_information* student, int number_of_student, int number_of_student_modified, char* name_of_student_modified, char *firstname_of_student_modified, char *gender_of_student_modified)
{
    int i;
    printf("        <table>\n");
    for(i=0;i<=number_of_student ;i++)
    {
        
        if(i>0)
        {
            if(i==number_of_student_modified)
            {
                printf("        <tr>\n");
                printf("            <form action=\"supprimer.cgi\" method=\"get\">\n");
                printf("            <td><input type=\"text\" name=\"student_name\" value=\"%s\"/></td>", name_of_student_modified);
                printf("            <td><input type=\"text\" name=\"student_firstname\" value=\"%s\"/></td>", firstname_of_student_modified);
                printf("            <td><input type=\"text\" name=\"student_gender\" value=\"%s\"/></td>", gender_of_student_modified);        
                printf("            <td><input type=\"submit\" value=\"Supprimer\"/></td>\n");
                printf("            </form>\n");


                printf("            <form action=\"modifier.cgi\" method=\"get\">\n");
                printf("            <td><input type=\"hidden\" name=\"student_name\" value=\"%s\"/></td>", student[i].name);
                printf("            <td><input type=\"hidden\" name=\"student_firstname\" value=\"%s\"/></td>", student[i].firstname);
                printf("            <td><input type=\"hidden\" name=\"student_gender\" value=\"%s\"/></td>", student[i].gender);        
                printf("            <td><input type=\"submit\" value=\"Modifier\"/></td>\n");
                printf("            </form>\n");
                printf("        </tr>\n"); 
            }
            else
            {
                printf("        <tr>\n");
                printf("            <form action=\"supprimer.cgi\" method=\"get\">\n");
                printf("            <td><input type=\"text\" name=\"student_name\" value=\"%s\"/></td>", student[i].name);
                printf("            <td><input type=\"text\" name=\"student_firstname\" value=\"%s\"/></td>", student[i].firstname);
                printf("            <td><input type=\"text\" name=\"student_gender\" value=\"%s\"/></td>", student[i].gender);        
                printf("            <td><input type=\"submit\" value=\"Supprimer\"/></td>\n");
                printf("            </form>\n");


                printf("            <form action=\"modifier.cgi\" method=\"get\">\n");
                printf("            <td><input type=\"hidden\" name=\"student_name\" value=\"%s\"/></td>", student[i].name);
                printf("            <td><input type=\"hidden\" name=\"student_firstname\" value=\"%s\"/></td>", student[i].firstname);
                printf("            <td><input type=\"hidden\" name=\"student_gender\" value=\"%s\"/></td>", student[i].gender);        
                printf("            <td><input type=\"submit\" value=\"Modifier\"/></td>\n");
                printf("            </form>\n");
            }
        }
        else
        {
            printf("        <tr>\n");
            printf("            <td>%s</td>\n", student[i].name);
            printf("            <td>%s</td>\n", student[i].firstname);
            printf("            <td>%s</td>\n", student[i].gender);
            printf("            <td colspan=\"2\">Options</td>\n"); 
            printf("        </tr>\n");       
        }
        
    }
    printf("        </table>\n");
}


void writting_the_list_with_modifications(FILE* file, student_information* student, int number_of_student, int number_of_student_modified, char* name_of_student_modified, char* firstname_of_student_modified, char* gender_of_student_modified)
{
    int i;
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html>\n");
    fprintf(file, " <head>\n");
    fprintf(file, "     <title>Liste des inscrits</title>\n");
    fprintf(file, "     <meta charset=\"utf-8\"/>\n");
    fprintf(file, "     <link rel=\"stylesheet\" href=\"test2.css\"/>\n");

    fprintf(file, " </head>\n");
    fprintf(file, " <body>\n");
    fprintf(file, "     <h1>Liste des etudiants inscrits</h1>\n");
    fprintf(file, "     <table>\n");
    
    for(i=0;i<=number_of_student;i++)
    {
        if(i==number_of_student_modified)
        {
            fprintf(file, "     <tr>\n");
            fprintf(file, "         <td>%s</td>\n", name_of_student_modified);
            fprintf(file, "         <td>%s</td>\n", firstname_of_student_modified);
            fprintf(file, "         <td>%s</td>\n", gender_of_student_modified);
            fprintf(file, "     </tr>\n");
            
        }
        else
        {
            fprintf(file, "     <tr>\n");
            fprintf(file, "         <td>%s</td>\n", student[i].name);
            fprintf(file, "         <td>%s</td>\n", student[i].firstname);
            fprintf(file, "         <td>%s</td>\n", student[i].gender);
            fprintf(file, "     </tr>\n");
        }
    }

}

void foot_of_body()
{
    printf("        <p>\n");
    printf("            Cliquez le lien suivant pour voir la liste que vous venez de modifier\n");
    printf("            <a href=\"test2.html\">Liste des etudiants inscrits a jour</a>\n");
    printf("        </p>\n");
    printf("    </body>\n");
    printf("</html>\n");
}


void writting_the_foot_of_the_file(FILE* file)
{
    fprintf(file, "     </table>");
    fprintf(file, " </body>\n");
    fprintf(file, "</html>\n");

}


student_information* recovery_student_information(FILE* file, int number_of_student)
{
    student_information *student=NULL;
    int i=0,j=0;
    char recovery_line[100];
    student=(student_information*)malloc(number_of_student*sizeof(student_information));    
    rewind(file);  
    while(fgets(recovery_line, 100, file) != 0)
    {
        if(strstr(recovery_line, "<td>"))
        {
            i++;
            if(i%3 == 1)
            {
                sscanf(recovery_line, "         <td>%[^<]</td>", student[j].name);
            }
            else if(i%3 == 2)
            {
                sscanf(recovery_line, "         <td>%[^<]</td>", student[j].firstname);
            }
            else
            {
                sscanf(recovery_line, "         <td>%[^<]</td>", student[j].gender);
                j++;
            }
            
        }
    }
    return (student);

}

int counter_of_tr(FILE* file)
{
    int counter=0;
    char sentence[100];
    rewind(file);
    while(fgets(sentence, 100, file) != 0)
    {
        if(strstr(sentence, "<tr>"))
            counter++;
    }
    return (counter-1);
}


void error_of_openning_file(FILE* file)
{
    if(file==NULL)
    {
        printf("        <p>\n");
        printf("            Erreur d'ouverture du fichier\n");
        printf("        </p>\n");
    }
}


void head_of_body()
{
    printf("    <body>\n");
    printf("        <h1>Inscription</h1>\n");
}


void head(char *title)
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>%s</title>\n", title);
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"modifier.css\"/>\n");

    printf("    </head>\n");
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


