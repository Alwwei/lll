#include <iostream>

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int
main() {
    
    int status;
    pid_t pid = fork();

    if(pid == 0){
        cout << "i'm child f" << endl;
        cout << getpid() << endl;
    }else{
        cout << "i'm parent" << endl;
        cout << getpid() << endl;
        wait(&status);
        cout << "exit_status:" << status << endl << WEXITSTATUS(status);
    }

    return 0;
}