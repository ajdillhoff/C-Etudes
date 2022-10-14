#include "queue_utils.h"
#include <stdlib.h>
#include <stdio.h>

int enqueue(void *elem, array_s *arr) {
    // error checking
    if (elem == NULL || arr == NULL) {
        return 1;
    }

    // realloc arr to support the new element
    arr->data = realloc(arr->data, (arr->numel + 1) * sizeof(void *));

    // add the element
    // increment the number of elements
    arr->data[arr->numel++] = elem;

    // return some error code
    return 0;
}

void *dequeue(array_s *arr) {
    // error checking
    if (arr == NULL || arr->data == NULL) {
        return NULL;
    }

    // grab item at the front of the list
    void *elem = arr->data[0];

    // shift data to the left
    for (int i = 0; i < arr->numel - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }

    // resize the array
    arr->data = realloc(arr->data, (arr->numel - 1) * sizeof(void *));
    arr->numel--;

    return elem;
}