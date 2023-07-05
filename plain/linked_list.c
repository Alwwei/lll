#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void ll_set_key_n_value(Node *node, const char *k, int v) {
    if (node) {
        node->k = strdup(k);
        node->v = v;
    }
}

Node *ll_new_node() {
    Node *new_node = NULL;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->k = NULL;
    new_node->v = 0;
    new_node->next = NULL;
    return new_node;
}

Node *ll_add_node(Node *root, const char *k, int v) {
    Node *aNode;
    Node *current;

    if (root == NULL) {
        root = ll_new_node();
        ll_set_key_n_value(root, k, v);
        return root;
    }

    current = root;
    while (current != NULL) {
        if (current->next == NULL) {
            aNode = ll_new_node();
            ll_set_key_n_value(aNode, k, v);

            current->next = aNode;
            return root;
        }

        current = current->next;
    }

    return root;
}

Node *ll_find_node(Node *root, const char *k) {
    Node *current = NULL;

    if (root == NULL) {
        return NULL;
    }

    current = root;
    while (current != NULL) {
        if (strcasecmp(current->k, k) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void ll_dump_list(Node *root) {
    Node *current = root;

    while (current != NULL) {
        printf("%s -> %d\n", current->k, current->v);
        current = current->next;
    }
}

int ll_main(int argc, char** argv) {
    char *keys[] = { "14", "35", "24" };
    int values[] = { 3, 6, 6 };
    Node *root = NULL;

    for (int i = 0; i < 3; i++) {
        root = ll_add_node(root, keys[i], values[i]);
    }

    ll_dump_list(root);
    return 0;
}