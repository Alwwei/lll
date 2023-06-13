#include <iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

// int f(int);

int
main() {

    int input,len = 0;
    cin >> input;
    len = log10(input) + 1;
    cout << len << endl;
    int n = input;
    int *p;
    p = (int*)malloc(sizeof(int) * len);

    for(int i = 0;i < len;i++){
        int m = n / 10;
        p[i] = n - (m * 10);
        n = m;
    }
    int flag = 0;
    for(int j = 0;j < len / 2;j++){
        if(*(p + j) != *(p + len - j - 1)){
            flag = 1;
            break;
        }
    }
    
    if(flag == 0){
        cout << "yes the number is palindrome";
    }else{
        cout << "the number isn't palindrome";
    }

    free(p);
    return 0;
}

// int f(){
//     return 0;
// }