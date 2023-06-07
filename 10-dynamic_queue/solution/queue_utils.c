#include "queue_utils.h"

#include <stdlib.h>

int enqueue(void *elem, array_s *arr) {
    // error checking
    if (elem == NULL || arr == NULL) {
        return 1;
    }

    // resize array
    arr->data = realloc(arr->data, (arr->numel + 1) * sizeof(void *));

    // put the element in the array
    // increment numel
    arr->data[arr->numel++] = elem;

    // return an error code
    return 0;
}

void *dequeue(array_s *arr) {
    // error checking
    if (arr == NULL || arr->data == NULL) {
        return NULL;
    }

    // retrieve the desired element
    void *elem = arr->data[0];

    // shift the data
    for (int i = 0; i < arr->numel - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }

    // resize the array
    arr->data = realloc(arr->data, (arr->numel - 1) * sizeof(void *));

    // decrement numel
    arr->numel--;

    // return element
    return elem;
}