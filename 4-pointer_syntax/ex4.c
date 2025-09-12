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

int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    // TODO: Call your function
    // TODO: Print the value you searched for along with its address

    return 0;
}