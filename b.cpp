#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct node{
    int value;
    int key;
    struct node *next;
};

int search(node *,int);
void append(node *,int,int);
void add_node(node *,int,int);




int
main() {
    int k[3] = {3,5,7};
    int v[3] = {10,20,30};
    int a = 0;
    struct node *root,*nn, *c;

    root = NULL;

    nn = (node *)malloc(sizeof(node));
    nn -> key = k[a];
    nn -> value = v[a];
    nn -> next = NULL;
    root = nn;
    a++;
//add node
    while(a < 4){
        add_node(root,k[a],v[a]);
        a++;
    }
//search
    // int b;
    // cin >> b ;
    // cout << search(root,b);
//append
    int a_k,a_v;
    cin >> a_k >> a_v;
    // cout << root << endl;
    // cout << a_k << a_v << endl;
    // append(root,a_k,a_v);
    // cout << root << endl;
//print out all
    c = root;
    cout << root -> next << endl;
    do{
        cout << c -> key << "," << c -> value << "," << c -> next << endl;
        c = c -> next;
    }while(c -> next != NULL);

    return 0;
}

void
add_node(node *root, int k, int v) {
    node *cur = root;
    node *nn;
    while (cur != NULL) {
        if (cur -> next == NULL) {
            nn = (node *)malloc(sizeof(node));
            nn -> key = k;
            nn -> value = v;

            cur -> next = nn;
            nn -> next = NULL;
            return;
        }
        cur = cur -> next;
    }
}

int search(node* root,int k){
    struct node *p;
    p = root;
    while(p -> next != NULL){
        if(p -> key == k){
            return p -> value;
        }
        p = p -> next;
    }
    return 0;
}

void append(node *root,int k,int v){
    struct node *p,*new_node;
    p = root;
    while(1){
        if(p -> next == NULL){
            new_node = (node *)malloc(sizeof(node));
            p -> next = new_node;
            new_node -> key = k;
            new_node -> value = v;
            new_node -> next = NULL;
            return ;
        }
        p = p -> next;
    }
}