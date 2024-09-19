#include <iostream>
#include <sys/socket.h>
#include <pthread.h>
#include "Comms.h"
#include "CreateSocketException.h"
#include "SendException.h"
#include "ReceiveException.h"

Comms::Comms() {
    std::string address = "127.0.0.1";
    inet_pton(AF_INET, address.c_str(), &service.sin_addr);
    service.sin_port = htons(5400);
}

int Comms::CreateSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) throw CreateSocketException(errno);
    return sock;
}

void Comms::SendAndReceive(int socket) {
    pthread_t thread;
    pthread_create(&thread, nullptr, receiver, &socket);
    pthread_detach(thread);

    while (true) {
        char message[200];
        std::cout << "> ";
        std::cin.getline(message,200);

        if (ShutdownCondition(message)) break;

        int sendRes = send(socket, message, 200, 0);
        if (sendRes == -1) throw SendException(errno);
    }
}

void* Comms::receiver(void *sock) {
    int socket = *(int *)sock;

    while(true)
    {
        char buffer[200] = "";
        int recvRes = recv(socket, buffer, 200, 0);

        if (recvRes == -1) throw ReceiveException(errno);

        if (recvRes == 0) {
            std::cout << "Received 0 bytes, Disconnect" << std::endl;
            break;
        }

        std::cout << "\033[31m" << buffer << "\033[0m" << std::endl;
        std::cout << "> ";
        std::cout.flush();
    }

    return nullptr;
}

bool Comms::ShutdownCondition(char* message) {
    return false;
}
