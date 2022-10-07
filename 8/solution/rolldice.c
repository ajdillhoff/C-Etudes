#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFSIZE 1024

int rolld6() {
    return rand() % 6 + 1;
}

int main() {
    char buffer[BUFSIZE] = { 0 };
    printf("Press ENTER to roll. Input Q to quit.");

    while (fgets(buffer, BUFSIZE, stdin)) {
        if (buffer[0] == 'Q') {
            break;
        }

        printf("Rolling d6: %d\n", rolld6());
    }

    printf("Good bye! Nice to know you.\n");

    return 0;
}
