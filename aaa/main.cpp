#include <iostream>
#ifndef R
#define R

#include<string.h>
#include "linked_list.h"
#include "hash_table.h"

using namespace std;

int
main() {
    int i = 0;
    node* root = NULL;
    struct hash_table table;
    struct hash_table* table_root = &table;
    initial_arr(table_root);

    FILE *file = fopen("/Users/angela/desktop/api.access.log.1","r");
    char IP_adress,skip;
    char arr[20];
    while(!feof(file)){
        char *key = NULL;
        IP_adress = fgetc(file);
        arr[i] = IP_adress;
        i++;
//IP end
        if(IP_adress == ' '){

            arr[i] = '\0';
            key = strdup(arr);

            put_data(table_root,key,0);

            while(1){
                skip = fgetc(file);
                if(skip == '\n'){
                    i = 0;
                    break;
                }
            }
        }
    }
    fclose(file);
    hash_dump(table_root);

    return 0;
}

#endif //R