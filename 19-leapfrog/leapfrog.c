#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leapfrog.h"

/*****************************/
/* Node management functions */
/*****************************/

/*
 * Add a new player to the beginning of the linked list.
 * The name is assumed to be statically allocated or a string literal.
 * It should be copied into dynamically allocated memory.
 * 
 * Parameters:
 *  head - Pointer to the head of the linked list.
 *  name - Name of the player to add.
 * 
 * Returns: void
 */
void add_player(node_s** head, const char* name) {
    // TODO: Implement this function to add a new player to the list
}

/*
 * Display all players in the linked list along with their hop counts.
 * 
 * Parameters:
 *  head - Pointer to the head of the linked list.
 * 
 * Returns: void
 */
void display_players(const node_s* head) {
    // TODO: Implement this function to display all players and their hop counts
}

/*
 * Make the specified player hop over the next player in the list.
 * If the player is at the end of the list or there is no next player, do nothing.
 * 
 * Parameters:
 *  head - Pointer to the head of the linked list.
 *  player - Pointer to the player node that should hop.
 * 
 * Returns: void
 */
void hop(node_s** head, const node_s* player) {
    // TODO: Implement this function to make the specified player hop over the next player
}

/*
 * Free all nodes in the linked list and their associated player names.
 * 
 * Parameters:
 *  head - Pointer to the head of the linked list.
 * 
 * Returns: void
 */
void free_list(node_s* head) {
    // TODO: Implement this function to free the linked list
}

/*****************************/
/*     Utility functions     */
/*****************************/
/*
 * Trim leading and trailing whitespace from a string.
 * 
 * Parameters:
 *  str - The string to trim. It is modified in place.
 * 
 * Returns: void
 */
void trim(char* str) {
    str[strcspn(str, "\n")] = 0; // Remove newline character if present
}