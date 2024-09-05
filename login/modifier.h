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


