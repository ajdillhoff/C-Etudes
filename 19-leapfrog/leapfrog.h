#ifndef LEAP_FROG_H_
#define LEAP_FROG_H_

#define BUF_SIZE 256

typedef struct player_s {
    char *name;
    int hops;
} player_s;

typedef struct node_s {
    player_s player;
    struct node_s* next;
} node_s;

/* Node management functions */
void add_player(node_s** head, const char* name);
void display_players(const node_s* head);
void hop(node_s** head, const node_s* player);
void free_list(node_s* head);

/* Utility functions */
void trim(char* str);

#endif