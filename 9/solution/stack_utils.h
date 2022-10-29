#ifndef STACK_UTILS_H_
#define STACK_UTILS_H_

#define BUF_SIZE 128

typedef struct {
    // data is a dynamic array of pointers -- they simply store addresses
    void **data;
    int num_items;
} mystack_t;

void push(void *val, mystack_t *stack);
void *pop(mystack_t *stack);
void print_stack(mystack_t *stack, void (*print_fn)(void *));
char *read_string();
void trim(char *);

#endif
