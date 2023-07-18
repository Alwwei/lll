#include <stdio.h>
#include <string.h>
#include "hash_table.h"
#include "max_heap.h"

int
main(int argc, char **argv) {
    char buf[1024];
    char *ip = NULL;

    HashTable *table = ht_create();
    Node *item_node = NULL;
    MaxHeap heap;

    FILE *file = fopen("/Users/angela/Desktop/api.access.log.1","r");

    while (!feof(file)) {
        fgets(buf, 1024, file);
//        printf("LINE: %s", buf);

        ip = strtok(buf, " \t");
        if (ip == NULL) {
            continue;
        }

//        printf("IP: %s\n", ip);
        item_node = ht_get_item(table, ip);
        if (item_node) {
            item_node->v++;
        } else {
            ht_put_item(table, ip, 1);
        }
    }

    // Dump hash table
    for (int i = 0; i < 20; i++) {
        if (table->items[i] != NULL) {
//            ll_dump_list(table->items[i]);
        }
    }

    for (int i = 0; i < 20; i++) {
        if (table->items[i] != NULL) {
            Node *current = table->items[i];

            while (current != NULL) {
                mh_add(&heap, current->v, current->k);
//                printf("%s -> %d\n", current->k, current->v);
                current = current->next;
            }
        }
    }

    printf("Top 1 IP %s => %d\n", heap.nodes[0].ip, heap.nodes[0].value);
    printf("Top 2 IP %s => %d\n", heap.nodes[1].ip, heap.nodes[1].value);
    printf("Top 3 IP %s => %d\n", heap.nodes[2].ip, heap.nodes[2].value);

//    ht_dump(table);
    ht_destroy(table);

    fclose(file);

    return 0;
}