#include "queue_utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int roll;
    int position;
} player_s;

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

char *get_string() {
    char buffer[128] = { 0 };
    printf("Enter a string: ");
    fgets(buffer, 128, stdin);
    trim(buffer);

    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}

void print_menu() {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print Queue\n");
    printf("4. Roll\n");
    printf("5. Exit\n");
    printf("> ");
}

int rolld20() {
    return rand() % 20 + 1;
}

void print_queue(array_s *queue) {
    for (int i = 0; i < queue->numel; i++) {
        player_s *p = queue->data[i];
        printf("%d. %s\n", p->position, p->name);
    }
}

int compare(const void *elem1, const void *elem2) {
    player_s *p1 = *(player_s **)elem1;
    player_s *p2 = *(player_s **)elem2;

    return p1->roll - p2->roll;
}

int main() {
    int selection = 0;
    array_s queue = { 0 };
    char *temp = NULL;

    while (selection != 5) {
        // display the menu
        print_menu();
        // prompt the user to enter a selection
        int result = scanf("%d", &selection);
        while (getchar() != '\n');
        if (result == 0) {
            selection = -1;
        }
        // execute selection
        switch (selection) {
        case 1: {
            // enqueue
            player_s *p = calloc(1, sizeof(player_s));
            p->name = get_string();
            enqueue(p, &queue);
            break;
        }
        case 2:
            // dequeue
            temp = dequeue(&queue);
            if (temp != NULL) {
                printf("Removed \"%s\" from the queue.\n", temp);
                free(temp);
            } else {
                printf("There are no items in the queue.\n");
            }
            break;
        case 3:
            // print
            print_queue(&queue);
            break;
        case 4:
            // roll initiative
            for (int i = 0; i < queue.numel; i++) {
                player_s *p = queue.data[i];
                p->roll = rolld20();
            }

            // Call qsort
            qsort(queue.data, queue.numel, sizeof(player_s *), compare);

            // roll initiative
            for (int i = 0; i < queue.numel; i++) {
                player_s *p = queue.data[i];
                p->position = i + 1;
            }
            break;
        case 5:
            // exit
            for (int i = 0; i < queue.numel; i++) {
                free(queue.data[i]);
            }

            free(queue.data);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}