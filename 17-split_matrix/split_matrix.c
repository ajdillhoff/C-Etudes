#include <stdio.h>
#include <math.h> // don't forget to compile with -lm

#define MAX_SIZE 100
#define MAX_BLOCKS 10

void print_matrix(int matrix[][MAX_SIZE], int num_rows, int num_cols, int row_start, int col_start) {
    // Get number of digits in the largest number in the matrix
    int max_digits = 0;
    for (int i = row_start; i < row_start + num_rows; i++) {
        for (int j = col_start; j < col_start + num_cols; j++) {
            int digits = (int) log10(matrix[i][j]) + 1;
            if (digits > max_digits) {
                max_digits = digits;
            }
        }
    }

    for (int i = row_start; i < row_start + num_rows; i++) {
        for (int j = col_start; j < col_start + num_cols; j++) {
            printf("%-*d ", max_digits, matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = { 0 };

    return 0;
}