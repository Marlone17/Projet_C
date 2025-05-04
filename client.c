#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>

#define PORT 8080
#define SA struct sockaddr

int main(){
    int socketo, connsock;
    struct sockaddr_in servaddr, cli;

    socketo = socket(AF_INET, SOCK_STREAM, 0);
    if (socketo == -1) {
        printf("socket creation failed\n");
        exit(0);
    }
    else
        printf("Socket created\n");
    
    printf("socketo == %s\n", socketo);
    bzero(&servaddr, sizeof(servaddr));


    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(socketo, (SA*)&servaddr, sizeof(servaddr))!= 0) {
        printf("connection failed\n");
        exit(0);
    }
    else
        printf("connected to server\n");
}