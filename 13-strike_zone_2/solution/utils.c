#include <stdio.h>
#include <math.h>

/*
 * Print a progress bar to the terminal.
 *
 * size: The number of characters in the bar.
 * progress: The progress as a float between 0 and 1.
 * strike_zone: The size of the strike zone in characters.
 */
void print_bar(int size, float progress, int strike_zone) {
    int i, start, end;

    start = round(size / 2.0 - strike_zone / 2.0);
    end = round(size / 2.0 + strike_zone / 2.0);

    printf("|");
    for (i = 0; i < size; i++) {
        if (i == start) {
            printf("[");
        }
        if (i == end) {
            printf("]");
        }
        if (i < progress * size) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("|\n");
}