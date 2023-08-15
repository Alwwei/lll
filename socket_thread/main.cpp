#include<iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#define PORT 8080

using namespace std;

void* threadf(void*);

struct socket
{
    int new_sock;
    char buf[1024] = {0};
    char* hello;
};

int
main()
{
    int i = 0;
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
    int new_sock,val_read,status;
    void* res;
    int s1;
    char hello[1024];
    strcpy(hello,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 106\n\n<!DOCTYPE html>\n<html>\n<head>\n<title>head</title>\n</head>\n<body>\n<h1>hiiiiiii</h1>\n</body>\n</html>");

    if(sockfd < 0)
    {
        perror("failed");
        exit(EXIT_FAILURE);
    }
    if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR, &opt,sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    status = bind(sockfd,(struct sockaddr*)&address,sizeof(address));
    if(status < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    struct socket sock;
    while (1)
    {
        pthread_t *t1 = (pthread_t*)malloc(sizeof(pthread_t*));
        cout << "server litsening" << endl;
        status = listen((int)sockfd,3);
        sock.new_sock = accept((int)sockfd,(struct sockaddr*)&address,(socklen_t*)&addrlen);
        sock.hello = hello;
        cout << "accept success" << endl;
        s1 = pthread_create(t1,NULL,&threadf,(void*)&sock);
        if(s1 != 0){
            perror("error");
        }
    }
    close(new_sock);
    return 0;
}

void*
threadf(void* sock)
{
    struct socket *s = (struct socket*)sock;
    while(read(s->new_sock,s->buf,sizeof(s->buf)))
    {
        cout << "recieve: " << s->buf << endl;
        if(strcmp(s->buf,"exit") == 0)
        {
            cout << "client leaved" << endl;
            memset(s->buf,0,strlen(s->buf));
            return 0;
        }
        // cout << s->hello << endl;
        write(s->new_sock,s->hello,strlen(s->hello));
        cout << "send success" << endl;
        memset(s->buf, 0, strlen(s->buf));
    }
    close(s->new_sock);
    return 0;
}