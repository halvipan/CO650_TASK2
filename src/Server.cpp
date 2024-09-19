#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Server.h"
#include "BindException.h"

void Server::Bind(int sock) {
    int bindRes = bind(sock, (sockaddr*)&service, sizeof(service));
    if (bindRes == -1) {
        throw BindException(errno);
    }
}

void Server::Listen(int sock) {
    if (listen(sock, SOMAXCONN) == -1) {
        std::cout << "LISTEN ERROR: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "listening..." << std::endl;
}

int Server::Accept(int sock) {
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);
    if (clientSocket == -1) {
        std::cout << "ACCEPT ERROR: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    return clientSocket;
}