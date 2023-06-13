#include <iostream>
#include<cmath>

using namespace std;

// int f();

int
main() {

    int x,flag = 0;
    int array[7] = {137,1829047,162761,12,5169,327781,5161};
    cout << "nums:" << endl;
    for(int i = 0;i < 7;i++){
        x = array[i];
        for(int j = 2;j <= sqrt(x);j++){
            if(x % j == 0){
                flag = 1;
                // cout << x << "," << j << endl;
                break;
            }
        }
        if(flag == 0){
            cout << x << " ";
        }
        flag = 0;
    }

    return 0;
}

// int f(){
//     return 0;
// }