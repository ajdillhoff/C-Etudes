#include <stdio.h>

void modify(int *a) {
    *a = 100;
}

int main() {
    int a = 0;

    // TODO: Create a function that returns `void` which modifies the value of `a`.
    modify(&a);

    printf("a = %d\n", a);

    return 0;
}
