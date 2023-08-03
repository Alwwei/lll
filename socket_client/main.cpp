#include<iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
// #define PORT 8080
#define serverPort 48763
#define serverIP "127.0.0.1"

using namespace std;

int
main()
{
    int i = 0;
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

    int sockfd = socket(PF_INET,SOCK_DGRAM,0);
    char buf[1024] = {0};
    char recvbuf[1024] = {0};
//crate soket
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

    if(connect(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr)))
    {
        perror("connect failed");
        close(sockfd);
        exit(1);
    }

    while (i < 4)
    {
        strcpy(buf,"client sent success");
        send(sockfd,buf,sizeof(buf),0);
        if(strcmp(buf,"exit") == 0){
            break;
        }
        memset(buf,0,sizeof(buf));
        if(recv(sockfd,recvbuf,sizeof(recvbuf),0) < 0)
        {
            cout << "recieve failed" << endl;
        }
        memset(buf,0,sizeof(buf));
        memset(recvbuf,0,sizeof(recvbuf));
        i++;
    }
//close socket
    if(close(sockfd) < 0)
    {
        perror("close failed");
    }

    return 0;
}