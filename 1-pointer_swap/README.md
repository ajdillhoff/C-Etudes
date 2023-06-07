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
