void openning_file(FILE* file);
int counter_of_users(FILE* file);
user_data* recovering_data(FILE* file, int number_of_users);
int searching_user(char *user_name, char* user_password, user_data* users, int number_of_users, int *pnumber_of_user);
void being_a_user_or_no(int verification);
void foot_of_body();
void head_of_body(user_data* users, int number_of_user);
void head(char *title);
void body_of_body();
void body_of_body_for_no_user();
void head_of_body_for_no_user();
void being_a_user_or_no(int verification);



