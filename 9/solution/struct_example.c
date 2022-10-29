#include <stdio.h>
#include <stdlib.h>

#include "stack_utils.h"

typedef struct {
    int id;
    char *name;
} user_s;

void print_user(void *user_ptr) {
    user_s *user = user_ptr;
    printf("{ \"id\": %d, \"name\": \"%s\" }\n", user->id, user->name);
}

user_s *add_user() {
    user_s *u = calloc(1, sizeof(user_s));

    printf("Enter user ID: ");
    scanf("%d", &u->id);
    while (getchar() != '\n');

    u->name = read_string();

    return u;
}

void free_user(user_s *u) {
    if (u == NULL) {
        return;
    }

    if (u->name) {
        free(u->name);
    }

    free(u);
}

int main() {
    char choice = 0;
    mystack_t stack = { 0 };
    user_s *u = NULL;
    while (choice != '4') {
        printf("1. Add User (push)\n");
        printf("2. Remove User (pop)\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("> ");

        scanf("%c", &choice);
        while (getchar() != '\n'); // flush the buffer

        switch (choice) {
            case '1':
                push(add_user(), &stack);
                break;
            case '2':
                u = pop(&stack);
                printf("%s removed.\n", u->name);
                free_user(u);
                u = NULL;
                break;
            case '3':
                print_stack(&stack, print_user);
                break;
            case '4':
                printf("Good bye!\n");
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }

    return 0;
}
