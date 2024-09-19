#include <iostream>
#include <unistd.h>
#include "Server.h"
#include "WhatWhyExceptionBase.h"

int main()
{
    Server* server = new Server();

    try {
        int sock = server->CreateSocket();
        server->Bind(sock);
        server->Listen(sock);
        int clientSocket = server->Accept(sock);
        server->SendAndReceive(clientSocket);
        close(sock);
    }
    catch (WhatWhyExceptionBase &e) {
        std::cout << e.what() << std::endl;
        std::cout << e.why() << std::endl;
    }

    return 0;
}