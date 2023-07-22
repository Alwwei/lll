#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

#include "fetch.h"


static size_t callback(void *data, size_t size, size_t nmemb, FILE *file)
{
    fwrite(data,size,nmemb,file);
    return nmemb;
}

void get1(void){
    FILE *file;
    file = fopen("/Users/angela/file/f.txt","wb");
    CURL *curl = curl_easy_init();
    CURLcode res;
    
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://counter.lig.com.tw");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    fclose(file);
return ;
}
   