void head(char *title);
void head_of_body();
void display_the_list(student_information *student, int number_of_student);
void foot_of_body();
void changing_plus_in_space(char *text);
void error_of_openning_file(FILE* file);
int counter_of_tr(FILE* file);
student_information* recovery_student_information(FILE* file, int number_of_student);
void writting_the_foot_of_the_file(FILE* file);
void writting_the_old_student_list_without_the_student_to_delete(FILE* file, student_information* student, int number_of_student_to_delete, int number_of_student);
void display_the_new_list(student_information* student, int number_of_student, int number_of_student_to_delete);
int control_deleting(char *name_student, char *firstname_student, char *gender_student, student_information *student, int number_of_student);

