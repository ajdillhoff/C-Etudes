#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 * Convert a `number` in its given `base` to one in base 10.
 */
int to_base10(int number, int base) {
    // TODO: Convert number from given base to base 10
    return 0;
}

/*
 * Convert a `number` in base 10 to one in the given `base`.
 */
int from_base10(int number, int base) {
    // TODO: Convert number from base 10 to the given base
    return 0;
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number> <base> <new base>\n", argv[0]);
        return 1;
    }

    // Convert string inputs to integers as needed using the `atoi` function
    int number = atoi(argv[1]);
    int base = atoi(argv[2]);
    int new_base = atoi(argv[3]);

    // If the number is already in base 10, we can just convert it to the new base
    if (base == 10) {
        printf("%d\n", from_base10(number, new_base));
    } else {
        // Convert the number to base 10 first, then to the new base
        printf("%d\n", from_base10(to_base10(number, base), new_base));
    }

    return 0;
}