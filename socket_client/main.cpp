#include<iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#define serverPort 8080
#define serverIP "127.0.0.1"

using namespace std;

int
main()
{
    int status;
    struct in_addr addr;
    if (inet_pton(AF_INET, serverIP, &addr.s_addr) == 1)
    {
        printf("Ip address: %u\n", addr.s_addr);
    }
    char ip_addr[20];
    if (inet_ntop(AF_INET, &addr.s_addr, ip_addr, sizeof(ip_addr)))
    {
        printf("After inet_ntop function, ip address: %s\n", ip_addr);
    }

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    char buf[1024] = {0};
    char recvbuf[1024] = {0};

    if(sockfd < 0)
    {
        perror("failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in serverAddr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(serverIP),
        .sin_port = htons(serverPort)
    };
    socklen_t len = sizeof(serverAddr);

    if(connect(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr)) < 0)
    {
        perror("connect failed");
        close(sockfd);
        exit(1);
    }

    while (1)
    {
        gets(buf);
        status = send(sockfd,buf,sizeof(buf),0);
        if(status < 0)
        {
            cout << "send failed";
            break;
        }
        if(strcmp(buf,"exit") == 0){
            break;
        }
        memset(buf,0,sizeof(buf));
        if(recv(sockfd,recvbuf,sizeof(recvbuf),0) < 0)
        {
            cout << "recieve failed" << endl;
            break;
        }
        memset(buf,0,sizeof(buf));
        memset(recvbuf,0,sizeof(recvbuf));
    }
    if(close(sockfd) < 0)
    {
        perror("close failed");
    }

    return 0;
}