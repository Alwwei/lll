#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


using namespace std;

// int f(int);

int
main() {
    FILE *file = fopen("/Users/angela/desktop/api.access.log.1","r");
    char IP_adress,skip;
    while(!feof(file)){ 
        IP_adress = fgetc(file);
        cout << IP_adress;
        if(IP_adress == ' '){
            cout << endl;
            while(1){
                skip = fgetc(file);
                if(skip == '\n'){
                    break;
                }
            }
        }
    }
    fclose(file);

    return 0;
}

// int f(){
//     return 0;
// }