#include <iostream>

using namespace std;

int f(int,int,int);

int
main() {
    int input = 10;
//    cout << "input:";
//    cin >> input;

    f(0,1,input - 1);

    return 0;
}

int f(int n1,int n2,int i){
    cout << n1 << " ";
    
    int temp = n2;
    n2 += n1;
    n1 = temp;

    if(i == 0){
    //    cout << n2;
        return 0;
    }

    return f(n1,n2,i - 1);
}