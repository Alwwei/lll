#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "fetch.cpp"

void get(CURL *);

int main(){
   
   
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "https://counter.lig.com.tw");
        get1(curl);
        curl_easy_cleanup(curl);
    }

    return 0;
}