#ifndef QUEUE_UTILS_H_
#define QUEUE_UTILS_H_

typedef struct {
    void **data;
    int numel;
} array_s;

int enqueue(void *, array_s *);
void *dequeue(array_s *);

#endif