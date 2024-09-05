#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "changement.h"



int main()
{
    char *title="Modification";
    char recovery[100];
    char name_student[100];
    char firstname_student[100];
    char gender_student[20];
    strcpy(recovery, getenv("QUERY_STRING"));
    char i[3];
    int number_of_student_to_modify=0;
    // student_name=A&student_firstname=B&student_gender=Masculin
    sscanf(recovery, "student_name=%[^&]&student_firstname=%[^&]&student_gender=%[^&]&number_of_student_to_modify=%s", name_student, firstname_student, gender_student, i);
    changing_plus_in_space(name_student);
    changing_plus_in_space(firstname_student);
    number_of_student_to_modify=atoi(i);
    head(title);
    head_of_body();
    body_of_body(name_student, firstname_student, gender_student, number_of_student_to_modify);
    foot_of_body();

}
