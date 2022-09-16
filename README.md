In music, etudes are designed to focus on a particular technical difficulty that may be found in standard repertoire.
Although they focus on specific challenges, they are sometimes musical and bring about an artistic quality.
The following collection of "etudes" serve a similar purpose.

# Etude 1

Write a program that swaps the values of two integers.
The base of the program has already been started in `etude1.c`.
It should prompt the user to enter two integers, store them in memory, and then call `swap_int` to swap the values.

In its current definition, `swap_int` does not swap the values contained in the variables defined in the calling function (`main` in this case).
Modify `swap_int` so that it accepts two `pointer-to-int` objects and swaps their reference values.
This will require dereferencing the pointers in the function itself.
Make sure you update the declaration in `utils.h` to match the modified definition.
If successful, your output should follow the example run below.

**Example Run**
```
Enter two integers: 1 4
a = 4, b = 1
```

# Etude 2

Start by creating a function named `get_longest` which has the following parameters:
- `char strings[][]`: a 2D array of `char` representing a collection of strings.
- `int num_strings`: The number of strings in the array.

The function should loop through the array and find the longest string determined by `strlen`.
Return a `char *` pointing to the longest string.
In `main`, call your function after the call to `read_strings`.
Use the returned `char *` to print the longest string as shown in the example run.

The file `etude2.c` already includes a function to read several strings until either the maximum number of strings has been read OR the user enters an empty string.
Note how the function `read_strings` accepts an `int *`. This allows the function to dereference the pointer and modify the value. This modification will persist even after the function returns back to `main`.

**Example Run**
```
( 0/32) Enter a string: testing
( 1/32) Enter a string: one two three
( 2/32) Enter a string: how many are there
( 3/32) Enter a string: 
The longest string is "how many are there"
```
