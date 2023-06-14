#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

// int f(int);

int
main() {

    int input,n = 0;
    cin >> input;
    int x = input;

    while(1)
    {
        if(pow(2,n) > input){

            n--;
            break;
        }
        n++;
    }

    int *p;
    p = (int*)malloc(sizeof(int) * n + 1);
    for(int i = 0;i <= n;i++){
        *(p + i) = 0;
    }

    *(p + n) = 1;
    x -= pow(2,n);

    while(x > 0){
        
        for(int i = 0;i <= n;i++){
            if(pow(2,i) > x){
                *(p + i - 1) = 1;
                x -= pow(2,i - 1);
                break;
            }
        }
        
    };

    for(int i = n;i >= 0;i--){
        cout << *(p + i);
    }

    free(p);
    return 0;
}

// int f(){
//     return 0;
// }