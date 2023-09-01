#include <stdio.h>
#include <math.h> // don't forget to compile with -lm

#define MAX_SIZE 100
#define MAX_BLOCKS 10

/*
 * Prints a submatrix of a matrix.
 * Args:
 *   matrix: the matrix to print
 *   num_rows: the number of rows in the submatrix
 *   num_cols: the number of columns in the submatrix
 *   row_start: the row index of the first row in the submatrix
 *   col_start: the column index of the first column in the submatrix
 */
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

/*
 * Fills a submatrix of a matrix with values starting from a given value.
 * Args:
 *   matrix: the matrix to fill
 *   num_rows: the number of rows in the submatrix
 *   num_cols: the number of columns in the submatrix
 *   row_start: the row index of the first row in the submatrix
 *   col_start: the column index of the first column in the submatrix
 *   start_value: the value to start filling the submatrix with
 */
void fill_matrix(int matrix[][MAX_SIZE], int num_rows, int num_cols, int row_start, int col_start, int start_value) {
    // TODO: Fill in this function
    return;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = { 0 };

    // This first call will fill in a 4x4 submatrix starting at (0, 0) with values starting at 1
    fill_matrix(matrix, 4, 4, 0, 0, 1);

    // This second call will print a 2x2 submatrix starting at (2, 2)
    print_matrix(matrix, 2, 2, 2, 2);

    return 0;
}