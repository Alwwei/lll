#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int k;
    int v;
    struct _node *next;
} Node;

void setKeyNValue(Node *node, int k, int v) {
    if (node) {
        node->k = k;
        node->v = v;
    }
}

Node *newNode() {
    return (Node *)malloc(sizeof(Node));
}

Node *addNode(Node *root, int k, int v) {
    Node *aNode;
    Node *current;

    if (root == NULL) {
        root = newNode();
        setKeyNValue(root, k, v);
        root->next = NULL;
        return root;
    }

    current = root;
    while (current != NULL) {
        if (current->next == NULL) {
            aNode = newNode();
            setKeyNValue(aNode, k, v);
            aNode->next = NULL;

            current->next = aNode;
            return root;
        }

        current = current->next;
    }

    return root;
}

void dumpList(Node *root) {
    Node *current = root;

    while (current != NULL) {
        printf("%d -> %d\n", current->k, current->v);
        current = current->next;
    }
}

int
main(int argc, char** argv) {
    int data[] = { 14, 3, 35, 6, 24, 6 };
    Node *root = NULL;

    for (int i = 0; i < 3; i++) {
        root = addNode(root, data[i], data[i + 1]); 
    }

    dumpList(root);
    return 0;
}