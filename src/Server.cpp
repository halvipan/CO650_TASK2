#include <iostream>
#include <sys/socket.h>
#include "Server.h"

using namespace std;

void Server::Bind(int sock, sockaddr_in service) {
    if (bind(sock, (sockaddr*)&service, sizeof(service)) == -1) {
        cout << "bind() failed: " << endl;
        exit(EXIT_FAILURE);
    }
    cout << "bind() successful" << endl;
}

void Server::Listen(int sock) {
    if (listen(sock, SOMAXCONN) == -1) {
        cout << "listen failed" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "listening..." << endl;
}

int Server::Accept(int sock) {
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);
    if (clientSocket == -1) cout << "accept error" << endl;
    return clientSocket;
}