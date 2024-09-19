#include <iostream>
#include <arpa/inet.h>
#include "Client.h"
#include "ConnectException.h"
#include "SendException.h"

void Client::Connect(int sock) {
    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) throw ConnectException(errno);
}

void Client::SendAndReceive(int socket) {
    pthread_t receiverThread;
    pthread_create(&receiverThread, nullptr, receiver, &socket);

    sender(&socket);
}

void* Client::sender(void *sock) {
    int socket = *(int *)sock;

    while (true) {
        char message[200];
        std::cout << "> ";
        std::cin.getline(message,200);

        if (strcmp(message, "QUIT") == 0) break;

        int sendRes = send(socket, message, 200, 0);
        if (sendRes == -1) throw SendException(errno);
    }

    return nullptr;
}