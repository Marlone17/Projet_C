#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define SA struct sockaddr
#define MAXVALUE 100

void bddchat(int socketo){
    char buff[MAXVALUE];
    int n;
    while(1){
            n =  0;

            while ((buff[n++] = getchar()) != '\n')
        ;
            bzero(buff, sizeof(buff));
            write(socketo, buff, sizeof(buff));
            bzero(buff, sizeof(buff));
            read(socketo, buff, sizeof(buff));
            printf("\nFrom Server : %s\n", buff);

    }
}

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
    
    bddchat(socketo);
}