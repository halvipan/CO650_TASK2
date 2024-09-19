#include <iostream>
#include <arpa/inet.h>
#include "Client.h"

void Client::Connect(int sock) {
    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) {
        std::cout << "error with connection" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "connection okay - now connected to Server" << std::endl;
}

bool Client::ShutdownCondition(char *message) {
    return strcmp(message, "SHUTDOWN") == 0;
}