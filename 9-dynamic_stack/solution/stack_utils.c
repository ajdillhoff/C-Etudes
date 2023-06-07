#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_utils.h"

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

/*
 * Add an item to the top of the stack.
 * We must reallocate and increase the data array BEFORE adding the item.
 */
void push(void *val, mystack_t *stack) {
    stack->data = realloc(stack->data, (stack->num_items + 1) * sizeof(void *));
    stack->data[stack->num_items++] = val;
}

/*
 * Remove the item from the top of the stack (end of the array) and return it.
 * The data array size is reduced by 1 to account for this.
 */
void *pop(mystack_t *stack) {
    void *str = stack->data[stack->num_items - 1];
    stack->data = realloc(stack->data, --stack->num_items * sizeof(void *));

    return str;
}

/*
 * Print the contents of the stack.
 *
 * Since the underlying data is an array of pointers, this function
 * cannot possibly know what type they need to be converted to and
 * how each element should be printed.
 *
 * The solution for this is then to accept a pointer to a function
 * which can print the underlying type. We will define the actual
 * function in a different file.
 */
void print_stack(mystack_t *stack, void (*print_fn)(void *)) {
    for (int i = stack->num_items - 1; i >= 0; i--) {
        print_fn(stack->data[i]);
    }
    printf("\n");
}

/*
 * Reads a string from the user.
 *
 * This function handles all the regular work we have to do to
 * read a string, allocate memory, and copy it over.
 *
 * REMEBER THAT THIS POINTER SHOULD EVENTUALLY BE FREED.
 */
char *read_string() {
    char buffer[BUF_SIZE] = { 0 };
    printf("Enter a string: ");
    fgets(buffer, BUF_SIZE, stdin);
    trim(buffer);

    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}
