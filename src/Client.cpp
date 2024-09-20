#include <iostream>
#include <arpa/inet.h>
#include "Client.h"
#include "ConnectException.h"

Client::Client() {
    Comms::breakOnQuit = true;
}

void Client::Connect(int sock) {
    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) throw ConnectException(errno);
    std::cout << "Connecting on " << ADDRESS << service.sin_port << std::endl;
}

void Client::SendAndReceive(int socket) {
    pthread_t receiverThread;
    pthread_create(&receiverThread, nullptr, receiver, &socket);

    sender(&socket);
}