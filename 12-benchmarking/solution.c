#include <stdio.h>
#include <time.h>

int main() {
    int num_seconds = 0;
    int resolution = 0;
    clock_t start = 0;
    clock_t elapsed_time = 0;

    printf("Enter the time limit (in seconds): ");
    scanf("%d", &num_seconds);

    printf("Enter the resolution (in fps): ");
    scanf("%d", &resolution);

    // This is the official starting point.
    start = clock();

    // Loop while the elapsed time has not reach the desired limit.
    while (elapsed_time < num_seconds * CLOCKS_PER_SEC) {
        elapsed_time = clock() - start;
        if (elapsed_time % (CLOCKS_PER_SEC / resolution) == 0) {
            printf("%ld\n", elapsed_time * 1000 / CLOCKS_PER_SEC);
        }
    }
}