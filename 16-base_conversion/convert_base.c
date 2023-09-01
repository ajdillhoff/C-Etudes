#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

/*
 * Convert a `number` in base 10 to one in the given `base`.
 */
char *from_base10(int number, int base) {
    char *converted_number = malloc(MAX_LENGTH * sizeof(char));
    // TODO: Convert number from base 10 to the given base

    return converted_number;
}

/*
 * Convert a `number` in its given `base` to one in base 10.
 */
int to_base10(char number[], int base) {
    // TODO: Convert number from given base to base 10
    return 0;
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number> <base> <new base>\n", argv[0]);
        return 1;
    }

    // Convert string inputs to integers as needed using the `atoi` function
    char number[MAX_LENGTH] = { 0 };
    strcpy(number, argv[1]);
    int base = atoi(argv[2]);
    int new_base = atoi(argv[3]);

    if (base == 10) {
        char *new_number = from_base10(atoi(number), new_base);
        printf("Converted number: %s\n", new_number);
    } else {
        int new_number = to_base10(number, base);
        printf("Converted number: %d\n", new_number);
    }

    return 0;
}