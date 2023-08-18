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
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *file){
    size_t written = fwrite(ptr,size,nmemb,file);
    return written;
}
void f0(void){
    FILE *fp;
    CURL *curl;
    CURLcode res;
    char *url = "http://127.0.0.1:8080";
    curl = curl_easy_init();
    if(curl){
        fp = fopen("/Users/angela/x/x.mp3","r");
        curl_easy_setopt(curl,CURLOPT_URL,url);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return;
}
void f1(void){
    FILE *fp;
    CURL *curl;
    CURLcode res;
    char *url = "http://127.0.0.1:8080";
    curl = curl_easy_init();
    if(curl){
        fp = fopen("/Users/angela/x/x.mp4","r");
        curl_easy_setopt(curl,CURLOPT_URL,url);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return;
}
void f2(void){
    FILE *fp;
    CURL *curl;
    CURLcode res;
    char *url = "http://127.0.0.1:8080";
    curl = curl_easy_init();
    if(curl){
        fp = fopen("x.html","r");
        curl_easy_setopt(curl,CURLOPT_URL,url);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return;
}
void f3(void){
    FILE *fp;
    CURL *curl;
    CURLcode res;
    char *url = "http://127.0.0.1:8080";
    curl = curl_easy_init();
    if(curl){
        fp = fopen("x.css","r");
        curl_easy_setopt(curl,CURLOPT_URL,url);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return;
}
void f4(void){
    FILE *fp;
    CURL *curl;
    CURLcode res;
    char *url = "http://127.0.0.1:8080";
    curl = curl_easy_init();
    if(curl){
        fp = fopen("x.js","r");
        curl_easy_setopt(curl,CURLOPT_URL,url);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return;
}
void download(char* request){
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
    // cout << page << endl;
    sscanf(page, "x.%s", filename);
    // cout << filename;

    for(int i = 0;i < 5;i++){
        if(strcmp(filename,file[i]) == 0)
            f = i;
    }

    if(f == 0){
        f0();
    }else if(f == 1){
        f1();
    }else if(f == 2){
        f2();
    }else if(f == 3){
        f3();
    }else{
        f4();
    }
    // free(filename);
    return ;
}