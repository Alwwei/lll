#ifndef PLAIN_MAX_HEAP_H
#define PLAIN_MAX_HEAP_H

typedef struct max_heap_node {
    int value;
    char *ip;
} MaxHeapNode;

typedef struct max_heap {
    MaxHeapNode nodes[100000];
    int count;
} MaxHeap;

void mh_add(MaxHeap *heap, int value, const char *ip);

#endif //PLAIN_MAX_HEAP_H
