#include <iostream>
#ifndef D
#define D
#include "hash_table.h"
#include "linked_list.h"

using namespace std;

int
hash_f(char *key){
    return (int)(*key) % 20;
}

void
initial_arr(hash_table *table_root){
    for(int i = 0;i < 20;i++){
        table_root->arr[i] = 0;
    }
    return;
}

void
put_data(hash_table *table_root,char* key,int value){
    node *new_root = NULL;
    int index = hash_f(key);
//if arr[index]==NULL,create a new root
    if(table_root->arr[index] == 0){
        new_root = add_node(new_root,key,value);
        table_root->arr[index] = new_root; 
        return;
    }
//if already exist,append
    table_root->arr[index] = add_node(table_root->arr[index],key,value);
    return;
}

void
hash_dump(hash_table *table_root){
    char *key_arr[3] = {};
    int value_arr[3] = {};
    int j = 0;
    while(j < 20){
        count(table_root->arr[j],3, key_arr, value_arr);
        j++;
    }
    for(int i = 0;i < 3;i++){
        cout << key_arr[i] << "," << value_arr[i] << endl;
    }
    return;
}

void
linked_list_dump(node *root){
    node *current = root;
    while(current != NULL){
        cout << "key: " << current->key << " value: " << current->value << endl;
        current = current->next;
    }
    return;
}

#endif //D