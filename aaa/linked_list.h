#include <iostream>
using namespace std;

#ifndef B
#define B

struct node{
    int value;
    char *key;
    struct node *next;
};

node* create_node(void);
void keyinValue(node*,char*,int);
node* add_node(node*,char*,int);
void linked_list_dump(node*);
void count(node*,int,char **,int *);

#endif //B