#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void upload_json(void){
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

}
   