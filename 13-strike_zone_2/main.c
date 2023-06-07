#include <time.h>
#include <stdio.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    // TODO: Verify command line arguments

    // TODO: Parse command line arguments
    int limit = 0;
    int fps = 0;
    int bar_size = 0;
    int strike_zone = 0;

    clock_t start = clock();
    clock_t elapsed_time = clock() - start;

    while (elapsed_time < limit * CLOCKS_PER_SEC) {
        elapsed_time = clock() - start;
        if (elapsed_time % (CLOCKS_PER_SEC / fps) == 0) {
            printf("%ld\n", elapsed_time * 1000 / CLOCKS_PER_SEC);
        }
    }
}