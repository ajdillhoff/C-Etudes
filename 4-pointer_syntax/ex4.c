/*
 * Aggregate data types such as arrays are referenced by their address.
 * For example, when an array such as `int arr[10]` is passed to a function via `f(arr)`,
 * only the address is passed. This allows for greater efficiency in our programs.
 * Copying every value of the array each time it was passed to a new function would
 * be catastrophic for performance.
 * 
 * In this excercise, you should use pointer arithmetic to access the elements of the array.
 */

#include <stdio.h>

// TODO: Create a search function defined by the following function header.
/*
 * get_address
 *
 * Arguments:
 *      int *arr - A pointer to the array data.
 *      int len  - The number of elements in the array.
 *      int val  - The value to search for.
 * 
 * Returns:
 *      int *address - The address of the element in the given array `arr`.
 */
int *get_address(int *arr, int len, int val) {
    for (int i = 0; i < len; i++) {
        if (*(arr + i) == val) {
            return arr + i;
        }
    }

    return NULL;
}

int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int a;

    // TODO: Call your function
    int *result = get_address(arr, 10, 8);
    // TODO: Print the value you searched for along with its address
    if (result) {
        printf("Found %d at address %p\n", *result, result);
    }

    return 0;
}