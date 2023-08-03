#include <iostream>

#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void *
threadf1(void *argu){
    for(int i = 0;i < 2;i++){
        cout << "a";
        sleep(1);
    }
}
void *
threadf2(void *argu){
    for(int i = 0;i < 2;i++){
        cout << "b";
        sleep(1);
    }
}

int
main() {
    pthread_t t1,t2;
    int s1,s2;
    s1 = pthread_create(&t1,NULL,&threadf1,NULL);
    s2 = pthread_create(&t2,NULL,&threadf2,NULL);
    
    for(int i = 0;i < 2;i++){
        cout << endl;
        sleep(1);
    }

    return 0;
}