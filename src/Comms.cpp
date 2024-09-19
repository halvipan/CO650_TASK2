#include <iostream>
#include <sys/socket.h>
#include <pthread.h>
#include "Comms.h"
#include "CreateSocketException.h"

Comms::Comms() {
    std::string address = "127.0.0.1";
    inet_pton(AF_INET, address.c_str(), &service.sin_addr);
    service.sin_port = htons(5400);
}

int Comms::CreateSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        throw CreateSocketException(errno);
    }
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

        if (ShutdownCondition(message))
            break;

        int sendRes = send(socket, message, 200, 0);
        if (sendRes == -1)
            std::cout << "Server: send() error" << std::endl;
    }
}

void* Comms::receiver(void *sock) {
    int server = *(int *)sock;

    while(true)
    {
        char buffer[200] = "";
        int recvRes = recv(server, buffer, 200, 0);
        if (recvRes == -1) {
            std::cout << "RECV ERROR: " << strerror(errno) << std::endl;
            break;
        } else if (recvRes == 0) {
            std::cout << "Received 0 bytes, Disconnect" << std::endl;
            break;
        } else {
            std::cout << "\033[31m" << buffer << "\033[0m" << std::endl;
            std::cout << "> ";
            std::cout.flush();
        }
    }

    std::terminate();
}

bool Comms::ShutdownCondition(char* message) {
    return false;
}
