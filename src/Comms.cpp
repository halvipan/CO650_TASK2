#include <iostream>
#include <sys/socket.h>
#include <pthread.h>
#include "Comms.h"
#include "CreateSocketException.h"
#include "ReceiveException.h"
#include "SendException.h"

const char* Comms::ADDRESS = "127.0.0.1";
bool Comms::breakOnQuit = false;

Comms::Comms() {
    inet_pton(AF_INET, ADDRESS, &service.sin_addr);
    service.sin_port = htons(5400);
}

int Comms::CreateSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) throw CreateSocketException(errno);
    return sock;
}

void* Comms::receiver(void *sock) {
    int socket = *(int *)sock;

    while(true)
    {
        char buffer[200] = "";
        int recvRes = recv(socket, buffer, 200, 0);

        if (recvRes == -1) throw ReceiveException(errno);

        if (recvRes == 0) {
            std::cout << "Received 0 bytes, Disconnecting" << std::endl;
            break;
        }

        std::cout << "\033[31m" << buffer << "\033[0m" << std::endl;
        std::cout << "> ";
        std::cout.flush();
    }

    return nullptr;
}

void* Comms::sender(void *sock) {
    int socket = *(int *)sock;

    while (true) {
        char message[200];
        std::cout << "> ";
        std::cin.getline(message,200);

        if (breakOnQuit && strcmp(message, "QUIT") == 0) break;

        int sendRes = send(socket, message, 200, 0);
        if (sendRes == -1) throw SendException(errno);
    }

    return nullptr;
}