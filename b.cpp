#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

using namespace std;

struct node{
    int value;
    int key;
    struct node *next;
};
struct hash_table{
    node *arr[20];
};

int hash_f(int);
void initial_arr(hash_table*);
node* create_node(void);
void keyinValue(node*,int,int);
node* add_node(node*,int,int);
void put_data(hash_table*,int,int);
void hash_dump(hash_table*);
void linked_list_dump(node*);

int
hash_f(int key){
    return key % 20;
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
keyinValue(node* node,int k,int v){
    node->key = k;
    node->value = v;
}
node*
add_node(node *root, int k,int v){
    node *current,*new_node;
    if(root == NULL){
        root = create_node();
        keyinValue(root,k,v);
        root->next = NULL;
        return root;
    }
    current = root;
    while(current != NULL){
        if(current->next == NULL){
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
put_data(hash_table *table_root,int key,int value){
    node *new_root = NULL;
    int index = hash_f(key);
//if arr[index]==NULL
    if(table_root->arr[index] == 0){
        new_root = add_node(new_root,key,value);
        table_root->arr[index] = new_root; 
        return;
    }
//if already exist,append
    table_root->arr[index] = add_node(table_root->arr[index],key,value);
    return;
}

int
main(){
    node* root = NULL;
    struct hash_table table;
    struct hash_table* table_root = &table;
    initial_arr(table_root);
    int k[3] = {1,2,3};
    int v[3] = {10,20,30};
    for(int i = 0;i < 3;i++){
        put_data(table_root,k[i],v[i]);
    }
    hash_dump(table_root);

    for(int i = 0;i < 20;i++){
        cout << table_root->arr[i] << endl;
    }

    return 0;
}
void
hash_dump(hash_table *table_root){
    int i = 0;
    while(i < 20){
        linked_list_dump(table_root->arr[i]);
        i++;
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