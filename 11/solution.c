#include <stdio.h>
#include <math.h>

void print_bar(int size, float progress, int strike_zone) {
    int i, start, end;

    start = round(size / 2.0 - strike_zone / 2.0);
    end = round(size / 2.0 + strike_zone / 2.0);

    printf("start: %d, end: %d\n", start, end);

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

int main(int argc, char *argv[]) {
    print_bar(10, 0.5, 1);
    print_bar(10, 0.5, 2);
    print_bar(15, 0.3, 4);
    return 0;
}