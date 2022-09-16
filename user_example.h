#ifndef USER_EXAMPLE_H_
#define USER_EXAMPLE_H_

#define MAX_STR 1024
#define NUM_ATTR 3

typedef struct {
    int id;
    char *name;
    char *email;
} user_s;

void free_user(user_s *u);
user_s *parse_user(char *csv_line);
user_s *add_user();
void trim(char *str);

#endif