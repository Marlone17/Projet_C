#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "database2.h"

#define PORT 8080
#define SA struct sockaddr
#define MAXVALUE 100

void bddSearch(node* root, int socketo, int connsock){
    char buff[MAXVALUE];

    bzero(buff, sizeof(buff));
    read(connsock, buff, sizeof(buff));

    int idSearch = atoi(buff);
    node* result = searchUser(root, idSearch);

    bzero(buff, sizeof(buff));
    if (result != NULL){
        snprintf(buff, sizeof(buff), 
        "User Found: ID=%d, Name=%s, Age=%d, Role=%s", 
        result->row.id, result->row.name, result->row.age, result->row.role);
    }
    else{
        snprintf(buff, sizeof(buff), "User with ID %d not found.", idSearch);
    }

    write(connsock, buff, sizeof(buff));
}



int main(){
    int socketo, connsock, len; 
    struct sockaddr_in servaddr, cli;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    socketo = socket(AF_INET, SOCK_STREAM, 0); 
    if (socketo == -1) { 
        printf("socket creation failed\n");
        exit(0); 
    } 
    else
        printf("Socket created\n");
 

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

    node* root = init_database();
    bddSearch(root, socketo, connsock);
    
}