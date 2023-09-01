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
    // DONE: Fill in this function
    for (int i = row_start; i < row_start + num_rows; i++) {
        for (int j = col_start; j < col_start + num_cols; j++) {
            matrix[i][j] = start_value++;
        }
    }
}

// 4 x 4 matrix
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
void split_matrix(int matrix[][MAX_SIZE], int num_rows, int num_cols, int block_size) {
    if (num_rows != num_cols) {
        printf("The matrix to be split should be square.\n");
        return;
    }

    int is_valid = 0;

    // Calculate block size
    int num_blocks = num_rows / block_size;

    // Validating block size
    for (int i = 1; i <= num_rows; i++) {
        if (num_rows % i == 0) {
            if (block_size == i) {
                is_valid = 1;
                break;
            }
        }
    }

    printf("block size: %d\n", block_size);
    printf("num blocks: %d\n", num_blocks);

    if (!is_valid) {
        printf("Not a valid block size for this matrix.\n");
        return;
    }

    for (int i = 0; i < num_blocks; i++) {
        for (int j = 0; j < num_blocks; j++) {
            print_matrix(matrix, block_size, block_size, i * block_size, j * block_size);
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = { 0 };

    // This first call will fill in a 4x4 submatrix starting at (0, 0) with values starting at 1
    fill_matrix(matrix, 9, 9, 0, 0, 1);

    // This second call will print a 2x2 submatrix starting at (2, 2)
    print_matrix(matrix, 2, 2, 1, 1);

    split_matrix(matrix, 9, 9, 3);

    return 0;
}