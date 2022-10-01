/*
 * Dynamic memory allocation is useful when we do not know the storage
 * requirements before the program executes.
 *
 * In this exercise, you should create a function that, given a size,
 * allocates an array of integers and returns the address given.
 *
 * The memory should be freed as well! Although the memory will be reclaimed
 * by the OS upon exit, you should develop the habit of freeing memory that was
 * allocated. Free the memory before exiting.
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: Create a function named `make_array` which accepts a single `int`
// representing the size of the requested array and returns a pointer to
// the dynamically allocated array.

int main() {
    // TODO: Call the allocation function.
    int *arr = make_array(10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    // TODO: Don't forget to free the memory.

    return 0;
}
