#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(){

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[256];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Erro ao abrir o socket");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
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
    
    bzero(buffer, 256);
    read(newsockfd, buffer, 255);
    printf("Mensagem recebida: %s\n", buffer);
    
    close(newsockfd);
    close(sockfd);
    return 0;
    
}