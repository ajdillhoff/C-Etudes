#include <stdio.h>

#include "utils.h"

int main() {
    int a = 0;
    int b = 0;

    // Prompt the user to enter two integers
    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);

    // Call `swap_int`, provided in `utils.h` to swap the values.
    swap_int(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
