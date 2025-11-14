#include <stdio.h>
#include <stdlib.h>

#include "hash_map_utils.h"

#define BUF_SIZE 128

int main() {
    char buffer[BUF_SIZE] = { 0 };
    hash_map_t *map = calloc(1, sizeof(hash_map_t));

    init_map(map, 20);

    // Add 10 elements that are guaranteed to cause a collision
    for (int i = 0; i < 10; i++) {
        snprintf(buffer, BUF_SIZE, "key%d", i * 9);
        hash_element_t *elem = calloc(1, sizeof(hash_element_t));
        elem->key = strdup(buffer);
        elem->value = NULL;

        insert(map, elem);
    }
}