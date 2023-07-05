
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "max_heap.h"

MaxHeapNode *mh_create_node() {
    MaxHeapNode *new_node = (MaxHeapNode *) malloc(sizeof(MaxHeapNode));
    new_node->ip = NULL;
    new_node->value = 0;
    return new_node;
}

void mh_add(MaxHeap *heap, int value, const char *ip) {
    int index = 0;
    int previous_index = 0;

    if (heap == NULL) {
        return;
    }

    // Append value-ip to the tail
    heap->nodes[heap->count].value = value;
    heap->nodes[heap->count].ip = strdup(ip);

    index = heap->count;
    // Heapify
    while (index > 0) {
        previous_index = index;
        if (index % 2 == 0) {
            index = (index - 2) / 2;
        } else {
            index = (index - 1) / 2;
        }

        if (heap->nodes[previous_index].value > heap->nodes[index].value) {
            // Swap position
            MaxHeapNode tmp;

            tmp.value = heap->nodes[previous_index].value;
            tmp.ip = heap->nodes[previous_index].ip;

            heap->nodes[previous_index].value = heap->nodes[index].value;
            heap->nodes[previous_index].ip = heap->nodes[index].ip;

            heap->nodes[index].value = tmp.value;
            heap->nodes[index].ip = tmp.ip;
        }
    }

    heap->count++;
}
