#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

using namespace std;

struct node{
    int value;
    char *key;
    struct node *next;
};
struct hash_table{
    node *arr[20];
};

int hash_f(char*);
void initial_arr(hash_table*);
node* create_node(void);
void keyinValue(node*,char*,int);
node* add_node(node*,char*,int);
void put_data(hash_table*,char*,int);
void hash_dump(hash_table*);
void linked_list_dump(node*);
void count(node*,int);

char *key_arr[3] = {};
int value_arr[3] = {};

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

// int
// main(){
//     node* root = NULL;
//     struct hash_table table;
//     struct hash_table* table_root = &table;
//     initial_arr(table_root);

    // int k[3] = {1,2,3};
    // int v[3] = {10,20,30};
    // for(int i = 0;i < 3;i++){
    //     put_data(table_root,k[i],v[i]);
    // }
    // hash_dump(table_root);

    // for(int i = 0;i < 20;i++){
    //     cout << table_root->arr[i] << endl;
    // }

//     return 0;
// }
void
hash_dump(hash_table *table_root){
    int j = 0;
    while(j < 20){
        count(table_root->arr[j],3);
        j++;
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
void
count(node *root,int nums){
    node *current = root;
    while(current != NULL){
        for(int i = 0;i < nums;i++){
            if(current->value > value_arr[i]){
                key_arr[i] = current->key;
                value_arr[i] = current->value;
                // cout << *(key_arr[i]) << "." << value_arr[i] << endl;
                break;
            }
        }
        current = current->next;
    }
    return;
}