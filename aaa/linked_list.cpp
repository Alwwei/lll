#include <iostream>

#ifndef C
#define C

#include "linked_list.h"

using namespace std;

node*
create_node(void){
    return (node*)malloc(sizeof(node));
}

void
keyinValue(node* node,char *k,int v){
    node->key = k;
    node->value = v;
}

node*
add_node(node *root, char *k,int v){
    node *current,*new_node;
    if(root == NULL){
        root = create_node();
        keyinValue(root,k,v);
        root->next = NULL;
        return root;
    }
    current = root;
    while(current != NULL){
        if(strcmp(k,current->key) == 0){
            current->value++;
            return root;
        }
        else if(current->next == NULL){
            new_node = create_node();
            current->next = new_node;
            keyinValue(new_node,k,v);
            new_node->next = NULL;
            return root;
        }
        current = current->next;
    }
    return root;
}

void
count(node *root,int nums,char **key_arr,int *value_arr){
    node *current = root;
    while(current != NULL){
        for(int i = 0;i < nums;i++){
            if(current->value > *(value_arr + i)){
                // *(key_arr + i) = current->key;
                key_arr[i] = strdup(current->key);
                *(value_arr + i) = current->value;
                break;
            }
        }
        current = current->next;
    }
    return;
}

#endif //C