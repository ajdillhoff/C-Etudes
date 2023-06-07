# 3

Create a program that parses user data and prints it to `stdout`.
The data should be stored as a `struct` and dynamically allocated based on the input file.
Invalid CSV lines should be skipped.

## Techniques
- Dynamic Memory Allocation
- pointers
- `struct` usage
- File I/O

## Part 1 - Creating the `struct`

For this exercise, users are represented by an `id`, `name`, and `email`.
Create a `struct` with the following members:

- `int id`
- `char *name`
- `char *email`

Define this `struct` and `typedef` it to `user_s` in a header file.

## Part 2 - Open and read a file

The program should accept 1 command line argument representing a file name.
Verify that the user entered the correct number of command line arguments.
For example, the usage should look something like

```
$ ./a.out users.csv
```

If no file name is given, print a usage string as shown below:

```
$ ./a.out
USAGE: ./a.out CSV_FILE
```

Once the file is open, read each line from the file and print it out to `stdout`.
Now that we can read each line, we can move on to part 3.

## Part 3 - Parsing and storing the data

### `parse_user`

Create a function named `parse_user` with the following signature:

```
user_s *parse_user(char *csv_line);
```

This function should use `strtok` to parse the line of CSV and store it in a `user_s *` object.
To do this, you will need to use dynamic memory allocation.
First, allocate memory for the `user_s *` object.
**This will return an address to the struct data. It should allocate 4 bytes for an `int` and 8 bytes for each `char *`.**

The first token read from `csv_line` should represent the `id`.
Convert it to an `int` using `atoi` and assign it to `id`.

The second and third token are both strings.
Since the members of our `struct` are only `char *`, you will need to allocate space for each string.
We already know how much memory to allocate for the string read from the file.
You can use the string length of `token` to compute the allocation size.
**Remember to add 1 to the allocation size to account for the NULL byte at the end of the string.**
Once the memory for the string is allocated, the `token` can be copied to it via `strcpy`.

If the line of CSV does not have 3 attributes, you should `free` any allocated memory and return `NULL`.

### Storing multiple users

In `main`, create a variable to store the users that are read from the file.

```
user_s **users;
```

**Why is this a double pointer?**

Our function `parse_user` returns `user_s *`.
If we want to store multiple pointers, we will essentially need an array of pointers.
However, we do not know how many users will be loaded from the file when we write our program.
It could be different every time.

To account for this, we need to be able to resize our array. We can do this with `realloc`.
If we only used a single pointer, then dereferencing it would refer to a `user_s` object, which is not what was returned by our function.

Since `users` is storing pointers, we can allocate 1 pointer at a time after we parse each line.
First, check if the return value of `parse_user` is `NULL`.
If it is not, call `realloc` and increase the size of our array by 1.

```
users = realloc(users, sizeof(void *) * (num_users + 1));
```

It would also be acceptable to write `sizeof(users_s *)`.
Though it isn't necessary since a pointer type is the same size regardless of the type that it references.
After resizing the array, you can assign the pointer returned from `parse_user`.
**Don't forget to increment `num_users` to reflect the additional item.**

## Part 4 - Printing the data

Now that you can parse and load all of your data into `user_s **users`, you should write a function that prints the data.
Create a function named `void print_users(user_s **users, int num_users);` that loops through each user and prints their `id`, `name`, and `email` in the format of your choosing.

## Part 5 - Cleaning Up

It is important to clean up any data that was allocated after you are done using it.
Although the memory would be reclaimed by the OS when exiting, you should still develop the good habit of `free`ing your data.

To clean up all the data, loop through `users`.
For each user, `free` the memory for `name` and `email` before freeing the `user_s *` pointer itself.

After the loop, make sure to call `free` on `users`.
