Working with time is a common task in programming, whether you're benchmarking code or controlling a timed process. This etude introduces time.h and the clock() function. It also introduces the concept of a benchmarking function.

Create a program that prompts the user to enter a time in seconds. Based on their input, the program should loop for exactly that amount of time. Additionally, prompt the user to enter a number to control how many times the time is printed per second. Print the output in milliseconds.

To get the current amount of processing time since the program started, you will need to use the clock() function. This function returns the number of clock ticks that have elapsed since the program started. The number of clock ticks per second is defined by the constant CLOCKS_PER_SEC. You can use this constant to convert the number of clock ticks to seconds.

```C
// Get the number of clock ticks since the program started
clock_t ticks = clock();

// Convert the number of clock ticks to seconds
long seconds = ticks / CLOCKS_PER_SEC;
```

**Example Output**

```
Enter a time in seconds: 5
Enter the fps: 2
500
1000
1500
2000
2500
3000
3500
4000
4500
5000
```