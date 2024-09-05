#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modifier.h"

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
