#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(){

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Erro ao abrir o socket");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) 
< 0) {
        perror("Erro no bind");
        exit(1);
    }
    
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Erro no accept");
        exit(1);
    }
    
    bzero(buffer, BUFFER_SIZE);
   int n = read(newsockfd, buffer, BUFFER_SIZE - 1);
if (n < 0) {
    perror("Erro ao ler do socket");
} else if (n == 0) {
    printf("Nenhum dado recebido.\n");
} else {

    printf("Teclas: \n");
	printf("len: %d",strlen(buffer));	
for(int i = 0;i < strlen(buffer);i++){

printf("%c",buffer[i]);

}

}
    
    close(newsockfd);
    close(sockfd);
    return 0;
    
}
