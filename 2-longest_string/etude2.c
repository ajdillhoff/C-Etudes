#include <stdio.h>
#include <string.h>

#include "utils.h"

#define MAX_STRINGS 32
#define MAX_LEN 128

int read_strings(char strings[][MAX_LEN], int *num_strings) {
    if (*num_strings == MAX_STRINGS) {
        return 0;
    }

    int num_read = 0;

    while (*num_strings < MAX_STRINGS) {
        printf("(%2d/%2d) Enter a string: ", *num_strings, MAX_STRINGS);
        fgets(strings[*num_strings], MAX_LEN, stdin);
        trim(strings[*num_strings]);

        // Exit the loop if the user enters an empty string.
        if (strlen(strings[*num_strings]) == 0) {
            break;
        }

        num_read++;  // Increment the number of strings read during this call.
        (*num_strings)++;  // Increment the number of strings in memory.
    }


    return num_read;
}

int main() {
    char strings[MAX_STRINGS][MAX_LEN] = { 0 };
    int num_strings = 0;

    read_strings(strings, &num_strings);

    return 0;
}
