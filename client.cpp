#include <iostream>
#include <unistd.h>
#include "Client.h"
#include "WhatWhyExceptionBase.h"

int main()
{
    Client* client = new Client();

    try {
        int sock = client->CreateSocket();
        client->Connect(sock);
        client->SendAndReceive(sock);
        close(sock);
    }
    catch (WhatWhyExceptionBase &e) {
        std::cout << e.what() << std::endl;
        std::cout << e.why() << std::endl;
    }

    return 0;
}
