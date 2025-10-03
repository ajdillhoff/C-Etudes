#include <stdio.h>

int main() {
    int a = 10;

    // TODO: Create a pointer variable and initialize it with the address of a.
    int *p = &a;
    // TODO: Change the value of `a` using the pointer variable.
    *p = 100;

    printf("a = %d\n", a);

    return 0;
}
