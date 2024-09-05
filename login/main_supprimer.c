#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supprimer.h"
int main()
{
    //Declaration des variables
    char recovery[100];
    char *title="Suppression";
    char name_student[100];
    char firstname_student[100];
    char gender_student[20];
    FILE* file=NULL;
    student_information *student=NULL;
    int number_of_student=0;
    int number_of_student_to_delete=0;

    //Zavatra hafa mitsy
    strcpy(recovery, getenv("QUERY_STRING"));
    sscanf(recovery, "student_name=%[^&]&student_firstname=%[^&]&student_gender=%s", name_student, firstname_student, gender_student);
    changing_plus_in_space(name_student);
    changing_plus_in_space(firstname_student);


    head(title);//titre de la page qui affichera si l'inscrption a reussi ou non
    head_of_body();//en tete de la page 
    // printf("            <p>recovery %s</p>\n", recovery);
    // printf("            <p>%s</p>\n", name_student);
    // printf("            <p>%s</p>\n", firstname_student);
    // printf("            <p> genre %s</p>\n", gender_student);   
    file=fopen("test2.html", "r");
    error_of_openning_file(file);
    number_of_student=counter_of_tr(file);
    student=(student_information*)malloc(number_of_student*sizeof(student_information));
    student=recovery_student_information(file, number_of_student);
    // printf("        <p>Liste du tableau de structure</p>\n");
    // for(int i=0; i<=number_of_student; i++)
    // {
    //     printf("            <tr>\n");
    //     printf("                <td>%s</td>\n", student[i].name);
    //     printf("                <td>%s</td>\n", student[i].firstname);
    //     printf("                <td>%s</td>\n", student[i].gender);
    //     printf("            </tr>\n");
    // }
    // printf("        <p>hatreo ihany no voaray</p>\n");
    fclose(file);
    file=fopen("test2.html", "w+");
    number_of_student_to_delete=control_deleting(name_student, firstname_student, gender_student, student, number_of_student);
    writting_the_old_student_list_without_the_student_to_delete(file, student, number_of_student_to_delete, number_of_student);
    writting_the_foot_of_the_file(file);

    display_the_new_list(student, number_of_student, number_of_student_to_delete);
    foot_of_body();
    fclose(file);
    free(student);
    return (0);
}
