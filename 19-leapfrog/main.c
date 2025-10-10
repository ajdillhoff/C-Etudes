#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leapfrog.h"

int main() {
    node_s* head = NULL;
    char input[BUF_SIZE];
    char name[BUF_SIZE];
    int choice;

    while (1) {
        printf("\nLeapfrog Game Menu:\n");
        printf("1. Add Player\n");
        printf("2. Display Players\n");
        printf("3. Make a Player Hop\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                if (fgets(name, sizeof(name), stdin)) {
                    trim(name);
                    add_player(&head, name);
                }
                break;
            case 2:
                display_players(head);
                break;
            case 3: {
                printf("Enter the name of the player to hop: ");
                if (fgets(name, sizeof(name), stdin)) {
                    trim(name);
                    node_s* current = head;
                    // TODO: Find the player and make them hop
                }
                break;
            }
            case 4:
                free_list(head);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free_list(head);
    return 0;
}