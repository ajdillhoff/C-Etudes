#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

/*
 * Convert a `number` in base 10 to one in the given `base`.
 */
char *from_base10(int number, int base) {
    // DONE: Convert number from base 10 to the given base
    char *converted_number = calloc(sizeof(char), MAX_LENGTH);
    int index = 0;
    int quotient = number;

    while (quotient) {
        int remainder = quotient % base;
        quotient /= base;

        if (remainder > 9) {
            int value = remainder + 55;
            converted_number[index] = value;
        } else {
            converted_number[index] = remainder + 48;
        }
        index++;
    }

    // Reverse the string
    int length = strlen(converted_number);

    for (int i = 0; i < length / 2; i++) {
        char temp = converted_number[i];
        converted_number[i] = converted_number[length - i - 1];
        converted_number[length - i - 1] = temp;
    }

    return converted_number;
}

/*
 * Convert a `number` in its given `base` to one in base 10.
 */
int to_base10(char number[], int base) {
    // DONE: Convert number from given base to base 10
    int converted_number = 0;
    int num_digits = strlen(number);

    for (int i = 0; i < num_digits; i++) {
        int converted_digit = 0;
        if (number[i] > 64) {
            converted_digit = number[i] - 55;
        } else {
            converted_digit = number[i] - 48;
        }

        int value = converted_digit * pow(base, num_digits - i - 1);
        converted_number += value;
    }

    return converted_number;
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

    // If the number is already in base 10, we can just convert it to the new base
    if (base == 10) {
        printf("Converted number: %s\n", from_base10(atoi(number), new_base));
    } else {
        printf("Converted number: %d\n", to_base10(number, base));
    }

    return 0;
}