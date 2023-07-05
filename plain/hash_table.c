#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TABLE_SIZE = 20;

HashTable *ht_create() {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->items[i] = NULL;
    }
    return table;
}

void ht_destroy(HashTable *table) {
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        free(table->items[i]);
    }

    free(table);
}

/**
 * Reference: https://developer.classpath.org/doc/java/lang/String-source.html#L1065-1076
 *
 * <code>s[0]*31**(n-1) + s[1]*31**(n-2) + ... + s[n-1]</code>
 *
 * @param key
 * @return int hashed value of this string; -1 otherwise
 */
long hash_code(const char *key) {
    long code = 0;
    unsigned long limit = 0;

    if (key == NULL) {
        return -1;
    }

    limit = strlen(key);
    for (int i = 0; i < limit; i++) {
        code = code * 31 + key[i];
    }

    return code;
}

int bucket_number(long hash_code) {
    return (int)(hash_code % TABLE_SIZE);
}

Node *ht_get_item(HashTable *table, const char *key) {
    int bucket = 0;
    Node *bucket_node = NULL;

    if (table == NULL) {
        return NULL;
    }

    bucket = bucket_number(hash_code(key));
    if (bucket < 0) {
        return NULL;
    }

    bucket_node = table->items[bucket];
    return ll_find_node(bucket_node, key);
}

void ht_put_item(HashTable *table, const char *key, int value) {
    int bucket = 0;
    Node *item_node = NULL;

    item_node = ht_get_item(table, key);
    if (item_node == NULL) {
        bucket = bucket_number(hash_code(key));
        table->items[bucket] = ll_add_node(table->items[bucket], key, value);
    } else {
        item_node->v = value;
    }
}

void ht_dump(HashTable *table) {
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->items[i] != NULL) {
            ll_dump_list(table->items[i]);
        }
    }
}

int ht_main(int argc, char **argv) {
    Node *a1 = NULL;
    HashTable *table = ht_create();

    ht_put_item(table, "A1", 1);
    ht_put_item(table, "A2", 2);
    ht_put_item(table, "A3", 3);
    a1 = ht_get_item(table, "A3");
    printf("Value: %d\n", a1->v);

    ht_dump(table);
    return 0;
}