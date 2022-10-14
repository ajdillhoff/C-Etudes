#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queue_utils.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

char *get_string() {
    char buffer[128] = { 0 };

    fgets(buffer, 128, stdin);
    trim(buffer);

    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}

void print_menu() {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    printf("> ");
}

int main() {

    int selection = 0;
    array_s queue = { 0 };
    char *temp = NULL;

    while (selection != 3) {
        // Print menu
        print_menu();
        // Get our selection
        scanf("%d", &selection);
        while (getchar() != '\n');
        switch (selection)
        {
        case 1:
            // add string
            enqueue(get_string(), &queue);
            break;
        case 2:
            // remove string
            temp = dequeue(&queue);
            if (temp != NULL) {
                printf("Dequeued \"%s\"\n", temp);
            } else {
                printf("Nothing in the queue.\n");
            }
            break;
        case 3:
            // exit
            break;
        }
    }

    return 0;
}