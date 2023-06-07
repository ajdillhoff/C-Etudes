/*
 * Arguments in C are passed by value.
 * That means that the call to `alloc_value` will copy the local value of `p` (NULL) and the hard-coded integer 10.
 * In the function `alloc_value`, two local variables retain the copies of the values that were passed in.
 * This behavior means that the intended function of `alloc_value` does not work!
 *
 * Fix the definition of `alloc_value` and update the call to it in `main` so that the value of `p` in `main` is updated in `alloc_value`.
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: Modify this function as requested.
void alloc_value(int *p, int val) {
    p = calloc(1, sizeof(int));
    *p = val;
}

int main() {
    // NOTE: Do not change the type of this variable.
    int *p = NULL;

    // TODO: The call needs to be modified to match the new definition.
    alloc_value(p, 10);

    printf("Value = %d\n", *p);

    return 0;
}
