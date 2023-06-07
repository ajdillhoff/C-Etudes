# Description

In etude 11, we created a function that prints a bar with a strike zone. This will be the UI for our program. In etude 12, we created a program that prints the time in milliseconds. We will use this to print the progress of our bar. In this etude, we will combine these two programs to create a program that prints a bar with a strike zone that fills up as time passes.

In `utils.c`, the `print_bar` function is provided that takes in three parameters:
1. `size` - the size of the bar
2. `progress` - the progress of the bar
3. `strike_zone` - the size of the strike zone

This function can be called inside the `main` function to print the bar. Solution code from etude 12 is provided in `main` to print the time based on the time limit and fps.

Start by validating and parsing command line input. Your program should take in 4 user arguments from the command line:
1. `size` - the size of the bar
2. `progress` - the progress of the bar
3. `strike_zone` - the size of the strike zone
4. `time_limit` - the time limit in seconds

# Clearing the Screen

To clear the screen, you can use the `system` function. This function takes in a string that is a command to be executed. The command `clear` will clear the screen. You can use this function to clear the screen before printing the bar. This function is provided in the `stdlib.h` header file.

**Example:**
```C
system("clear");
```

Alternatively, you can use a special regular expression to clear the screen. This regular expression is `\033[2J\033[1;1H`. You can use this regular expression to clear the screen before printing the bar.

**Example:**
```C
printf("\033[2J\033[1;1H");
```