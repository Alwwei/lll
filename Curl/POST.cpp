#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <iostream>

using namespace std;

struct memory
{
    char *response;
    size_t size;
};


static size_t cb(void *data, size_t size, size_t nmemb, void *chunk){
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)chunk;
    char *ptr;
    ptr = (char*)realloc(mem->response, mem->size + realsize + 1);
    if(ptr == NULL)
    return 0;

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;
 
    return realsize;
}

void post_request(void){
    CURLcode res;
    CURL *curl = curl_easy_init();
    curl_mime *mime;
    curl_mimepart *field;
    char data[10] = "gooday";

    struct memory chunk = {0};

    if(curl) {
        mime = curl_mime_init(curl);
        curl_easy_setopt(curl, CURLOPT_URL, "https://counter.lig.com.tw/post");
        field = curl_mime_addpart(mime);
        curl_mime_name(field,"name");
        curl_mime_type(field,"text/plain");
        curl_mime_data(field,data,CURL_ZERO_TERMINATED);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        
        res = curl_easy_perform(curl);
        cout << chunk.response;
        free(chunk.response);
        curl_easy_cleanup(curl);
        return;
    }else{
        cout << "fail";
        return;
    }

}
   