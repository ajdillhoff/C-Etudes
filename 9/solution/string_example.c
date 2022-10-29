#include <stdio.h>
#include <stdlib.h>

#include "stack_utils.h"

void print_string(void *str_ptr) {
    char *str = str_ptr;
    printf("%s\n", str);
}

int main() {
    char choice = 0;
    mystack_t stack = { 0 };
    char *str = NULL;
    while (choice != '4') {
        printf("1. Add String (push)\n");
        printf("2. Remove String (pop)\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("> ");

        scanf("%c", &choice);
        while (getchar() != '\n'); // flush the buffer

        switch (choice) {
            case '1':
                push(read_string(), &stack);
                break;
            case '2':
                str = pop(&stack);
                printf("%s removed.\n", str);
                free(str);
                break;
            case '3':
                print_stack(&stack, print_string);
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
