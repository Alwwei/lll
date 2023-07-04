#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"b.cpp"


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
        // cout << IP_adress;
//IP end
        if(IP_adress == ' '){
            // cout << endl;
            arr[i] = '\0';
            // for(int k = 0;k < i;k++){
            //     cout << arr[i];
            // }
            key = strdup(arr);
            // cout << endl;
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
    for(int i = 0;i < 3;i++){
        cout << key_arr[i] << "," << value_arr[i] << endl;
    }

    return 0;
}