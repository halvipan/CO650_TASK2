#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Server.h"
#include "BindException.h"
#include "ListenException.h"
#include "AcceptException.h"
#include "SendException.h"

void Server::Bind(int sock) {
    int bindRes = bind(sock, (sockaddr*)&service, sizeof(service));
    if (bindRes == -1) throw BindException(errno);
}

void Server::Listen(int sock) {
    int listenRes = listen(sock, SOMAXCONN);
    if (listenRes == -1) throw ListenException(errno);
    std::cout << "Now Listening on " << ADDRESS << service.sin_port << std::endl;
}

int Server::Accept(int sock) {
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);
    if (clientSocket == -1) throw AcceptException(errno);
    return clientSocket;
}

void Server::SendAndReceive(int socket) {
    pthread_t sendThread;
    pthread_create(&sendThread, nullptr, sender, &socket);

    receiver(&socket);
}

void* Server::sender(void *sock) {
    int socket = *(int *)sock;

    while (true) {
        char message[200];
        std::cout << "> ";
        std::cin.getline(message,200);

        int sendRes = send(socket, message, 200, 0);
        if (sendRes == -1) throw SendException(errno);
    }

    return nullptr;
}