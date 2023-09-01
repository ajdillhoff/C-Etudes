# Split Matrix

Create a program that prompts the user to enter the following information:
- The size of the matrix (number of rows and columns)
- The number of blocks to split the matrix into

After collecting the information, you should verify that the number of blocks is valid. To keep things simple, the matrix and the blocks should be square. If not, you should print an error message and exit the program. The maximum size a matrix can be is $100 \times 100$. The maximum number of blocks is 10.

Before splitting the blocks, write a function called `fill_matrix` which takes a matrix and fills it with the numbers 0 to n where n is the number of elements in the matrix. The numbers should be filled in row-major order. For example, if the user enters 4 rows and 4 columns, the matrix should be filled as follows:
```
0 1 2 3
4 5 6 7
8 9 10 11
12 13 14 15
```

For example, if the user enters 4 rows, 4 columns, and 4 blocks, the program should print the following:
```
0 1
4 5

2 3
6 7

 8  9
12 13

10 11
14 15
```

