#include <stdio.h>
#include <iostream>
#include <string.h>
#include <curl/curl.h>
#include "funcs.h"

using namespace std;

char* get_uri(char *request){
    const char s1[] = "\n";
    const char s2[] = "/";
    const char s4[] = " ";
    char s3[15];
    strcpy(s3,"GET ");
    char *token;
    char *buf;
    char *url;
    char* page;
    url = (char*)malloc(100 * sizeof(char));
    buf = (char*)malloc(4 * sizeof(char));
    page = (char*)malloc(10 * sizeof(char));
    token = strtok(request,s1); 
    while(token != NULL){
        strncpy(buf,token,4);
        if(strcmp(buf,s3) == 0){
            url = token;
            break;
        }
        memset(buf,0,strlen(buf));
        token = strtok(NULL,s1);
    }
    sscanf(url,"GET /%s HTTP/1.1", page);

    // free(url);
    // free(buf);
    // free(page);

    return page;

}
int f0(void){
    FILE *fd = fopen("/Users/angela/x/x.mp3","r");
    int a = fileno(fd);
    return a;
}
int f1(void){
    FILE *fd = fopen("/Users/angela/x/x.mp4","r");
    int a = fileno(fd);
    return a;
}
int f2(void){
    FILE *fd = fopen("x.html","r");
    int a = fileno(fd);
    return a;
}
int f3(void){
    FILE *fd = fopen("x.css","r");
    int a = fileno(fd);
    return a;
}
int f4(void){
    FILE *fd = fopen("x.js","r");
    int a = fileno(fd);
    return a;
}
int download(char* request){
    char buf[1024] = "accept success\nserver litsening\nGET /a.mp3 HTTP/1.1\nHost: 127.0.0.1:8080\nConnection: keep-alive";
    char* page;
    char* filename;
    char* file[] = {
        "mp3",
        "mp4",
        "html",
        "css",
        "js"
    };
    int f;
    filename = (char*)malloc(10 * sizeof(char));
    page = get_uri(request);
    sscanf(page, "x.%s", filename);

    for(int i = 0;i < 5;i++){
        if(strcmp(filename,file[i]) == 0)
            f = i;
    }

    free(filename);
    return f;
}