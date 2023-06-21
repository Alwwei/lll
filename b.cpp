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
struct hash_item{
    int value;
    int key;
};
struct hash_table{
    int size;
    int count;
};
int hash_f(int key){
    return key % 20;
}
node* index_array[20];

node*
create_node(){
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
output(node* root){
    node* current = root;
    while(current != NULL){
        cout << current->key << "," << current->value << endl;
        current = current->next;
    }
}
int
main(){
    node* root = NULL;
    memset(index_array,'/0',20);
    int k[3] = {1,2,3};
    int v[3] = {10,20,30};
    for(int i = 0;i < 5;i++){
        store_data(k[i],v[i]);
    }
    // for(int i = 0;i < 5;i++){
    //     root = add_node(root,a[i],a[i+1]);
    //     i++;
    // }
    // output(root);

    return 0;
}
node* store_data(int key,int value){
    node* root;
    int index = hash_f(key);
    root = index_array[index];
    if(index_array[index] == NULL){
        node* root = NULL;
        index_array[index] = add_node(root,key,value);
        return index_array[index];
    }
    return add_node(root,key,value);
}