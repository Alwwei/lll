#include <stdio.h>
#include <string.h>
#include <iostream>
#include <curl/curl.h>

using namespace std;

void statuscode_po(void){
    CURLcode res;
    CURL *curl = curl_easy_init();
    long code = 0;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://counter.lig.com.tw/404");
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE, &code);
        cout << "status code: " << code << endl;
        curl_easy_cleanup(curl);
        return;
    }
    else{
        cout << "fail";
        return;
    }
}
   