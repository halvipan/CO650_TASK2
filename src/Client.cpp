#include <iostream>
#include <arpa/inet.h>
#include "Client.h"
#include "ConnectException.h"

void Client::Connect(int sock) {
    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) {
        throw ConnectException(errno);
    }
}

bool Client::ShutdownCondition(char *message) {
    return strcmp(message, "SHUTDOWN") == 0;
}