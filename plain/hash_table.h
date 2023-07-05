//
// Created by Plain Wu on 2023/7/5.
//

#ifndef LLL_HASH_H
#define LLL_HASH_H

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


typedef struct hash_table {
    Node *items[20];
} HashTable;

HashTable *ht_create();
void ht_destroy(HashTable *table);
Node *ht_get_item(HashTable *table, const char *key);
void ht_put_item(HashTable *table, const char *key, int value);
void ht_dump(HashTable *table);

#endif //LLL_HASH_H
