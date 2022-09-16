#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_example.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

user_s *add_user() {
    user_s *u = calloc(1, sizeof(user_s));
    char buffer[MAX_STR] = { 0 };

    printf("Enter the user's name: ");
    fgets(buffer, MAX_STR, stdin);
    trim(buffer);
    u->name = malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(u->name, buffer);

    printf("Enter the user's email: ");
    fgets(buffer, MAX_STR, stdin);
    trim(buffer);
    u->email = malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(u->email, buffer);

    return u;
}

user_s *parse_user(char *csv_line) {
    int num_tokens = 0;
    char *token = strtok(csv_line, ",");
    user_s *u = calloc(1, sizeof(user_s));

    while (token) {
        switch(num_tokens) {
        case 0:
            u->id = atoi(token);
            break;
        case 1:
            u->name = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(u->name, token);
            break;
        case 2:
            u->email = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(u->email, token);
            break;
        }

        num_tokens++;
        token = strtok(NULL, ",");
    }

    // Makes sure it is a valid line of CSV.
    if (num_tokens == NUM_ATTR) {
        return u;
    } else {
        printf("Invalid line detected!\n");
        free_user(u);
        return NULL;
    }
}

void free_user(user_s *u) {
    if (u->name != NULL) {
        free(u->name);
    }
    if (u->email != NULL) {
        free(u->email);
    }
    if (!u) {
        free(u);
    }
}

void print_users(user_s **users, int num_users) {
    for (int i = 0; i < num_users; i++) {
        printf("User %d: %s (%s)\n", users[i]->id, users[i]->name, users[i]->email);
    }
}

int main(int argc, char **argv) {
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        return 1;
    }

    char buffer[MAX_STR] = { 0 };
    user_s **users = NULL;
    int num_users = 0;

    while (fgets(buffer, MAX_STR, fp)) {
        trim(buffer);
        user_s *s = parse_user(buffer);

        if (s != NULL) {
            users = realloc(users, sizeof(void *) * (num_users + 1));
            users[num_users] = s;
            num_users++;
        }
    }

    fclose(fp);

    print_users(users, num_users);

    for (int i = 0; i < num_users; i++) {
        free_user(users[i]);
    }

    free(users);

    return 0;
}