#include <iostream>

using namespace std;

int f(int);

int
main() {
    int input = 10;
    cout << "input:";
    cin >> input;

    f(input);

    return 0;
}

int f(int input){
    int a;
    int b = 1;
    for(int i = 0;i < input;i++){
        cout << a << " ";
        int temp;
        temp = b;
        b += a;
        a = temp;
    }

    return 0;
}