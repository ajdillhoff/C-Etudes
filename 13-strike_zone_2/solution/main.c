#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    // DONE: Verify command line arguments
    if (argc != 5) {
        printf("Usage: %s <limit> <fps> <bar_size> <strike_zone>\n", argv[0]);
        return 1;
    }

    // DONE: Parse command line arguments
    int limit = atoi(argv[1]);
    int fps = atoi(argv[2]);
    int bar_size = atoi(argv[3]);
    int strike_zone = atoi(argv[4]);

    clock_t start = clock();
    clock_t elapsed_time = clock() - start;

    while (elapsed_time < limit * CLOCKS_PER_SEC) {
        elapsed_time = clock() - start;
        if (elapsed_time % (CLOCKS_PER_SEC / fps) == 0) {
            // Clear screen
            printf("\033[2J\033[1;1H");
            // system("clear"); // Slower than ANSI escape codes

            // Print progress bar
            print_bar(bar_size, (float) elapsed_time / (limit * CLOCKS_PER_SEC), strike_zone);
        }
    }
}