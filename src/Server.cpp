#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Server.h"
#include "BindException.h"
#include "ListenException.h"
#include "AcceptException.h"

void Server::Bind(int sock) {
    int bindRes = bind(sock, (sockaddr*)&service, sizeof(service));
    if (bindRes == -1) throw BindException(errno);
}

void Server::Listen(int sock) {
    int listenRes = listen(sock, SOMAXCONN);
    if (listenRes == -1) throw ListenException(errno);
}

int Server::Accept(int sock) {
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);
    if (clientSocket == -1) throw AcceptException(errno);
    return clientSocket;
}