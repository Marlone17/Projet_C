#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed\n");
        printf("sockfd == %s", sockfd); 
        exit(0); 
    } 
    else
        printf("Socket created\n");
        printf("sockfd == %s\n", sockfd);
    bzero(&servaddr, sizeof(servaddr)); 
}