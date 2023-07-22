#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <iostream>
// #include "file.txt"

using namespace std;


void upload(void){
    CURLcode res;
    curl_mime *form;
    curl_mimepart *field;
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://counter.lig.com.tw/upload");

        form = curl_mime_init(curl);
        field = curl_mime_addpart(form);
        curl_mime_filedata(field,"file.txt");
        curl_mime_type(field,"multipart/form-data");
        curl_mime_name(field,"file");
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }else{
        cout << "fail";
        return;
    }

}
   