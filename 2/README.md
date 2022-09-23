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
