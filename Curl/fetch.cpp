#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>


static size_t callback(void *data, size_t size, size_t nmemb, FILE *file)
{
    fwrite(data,size,nmemb,file);
    return nmemb;
}

void get1(CURL *curl){
    FILE *file;
    file = fopen("/Users/angela/file/f.txt","wb");
    CURLcode res;
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        res = curl_easy_perform(curl);
    }
    fclose(file);
return ;
}
   