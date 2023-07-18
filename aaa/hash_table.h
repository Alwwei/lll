#include <iostream>


using namespace std;

#ifndef A
#define A

#include "linked_list.h"

struct hash_table{
    node *arr[20];
};

int hash_f(char*);
void initial_arr(hash_table*);
void put_data(hash_table*,char*,int);
void hash_dump(hash_table*);


#endif //A