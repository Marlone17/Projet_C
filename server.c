#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "database.h"

#define PORT 8080
#define SA struct sockaddr



int main(){
    int socketo, conn, len; 
    struct sockaddr_in servaddr, cli;
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    socketo = socket(AF_INET, SOCK_STREAM, 0); 
    if (socketo == -1) { 
        printf("socket creation failed\n");
        printf("socketo == %s", socketo); 
        exit(0); 
    } 
    else
        printf("Socket created\n");
        printf("socketo == %s\n", socketo);
    bzero(&servaddr, sizeof(servaddr)); 

    if ((bind(socketo, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed\n"); 
        exit(0); 
    } 
    else
        printf("Socket bind\n");
    
        if ((listen(socketo, 3)) != 0) { 
            printf("Listen fail\n"); 
            exit(0); 
        } 
        else
            printf("Listen success\n"); 
    
    connsock = accept(socketo, (SA*)&cli, &len);


    
}