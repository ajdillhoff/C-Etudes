#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFSIZE 1024

int roll(int num_die, int die_size) {
    int sum = 0;

    for (int i = 0; i < num_die; i++) {
        sum += rand() % die_size + 1;
    }
    return sum;
}

int main() {

    srand(time(NULL));

    char buffer[BUFSIZE] = { 0 };
    int num_die = 0;
    int die_size = 0;
    printf("Enter roll. Input Q to quit.");

    while (fgets(buffer, BUFSIZE, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;

        if (buffer[0] == 'Q') {
            break;
        }

        if (buffer[0] == 'd') {
            num_die = 1;
            die_size = atoi(strtok(buffer, "d"));
        } else {
            num_die = atoi(strtok(buffer, "d"));
            die_size = atoi(strtok(NULL, "d"));
        }

        // Parse input 10d100

        printf("Rolling %dd%d: %d\n", num_die, die_size, roll(num_die, die_size));
    }

    printf("Good bye! Nice to know you.\n");

    return 0;
}
