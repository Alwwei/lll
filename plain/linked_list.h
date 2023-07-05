//
// Created by Plain Wu on 2023/7/5.
//

#ifndef LLL_LINKED_LIST_H
#define LLL_LINKED_LIST_H

typedef struct _node {
    char *k;
    int v;
    struct _node *next;
} Node;

void ll_set_key_n_value(Node *node, const char *k, int v);
Node *ll_new_node();
Node *ll_add_node(Node *root, const char *k, int v);
Node *ll_find_node(Node *root, const char *k);
void ll_dump_list(Node *root);

#endif //LLL_LINKED_LIST_H
