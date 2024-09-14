#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "Comms.h"
#include "Server.h"

using namespace std;

// adapted from Jasmin Martin's code (thank you!)

int main()
{
    Server* server = new Server();

    int sock = server->CreateSocket();
    sockaddr_in service = server->CreateAddress();
    server->Bind(sock, service);
    server->Listen(sock);
    int clientSocket = server->Accept(sock);
    server->SendAndReceive(clientSocket);

    // STEP 7 - DISCONNECT

    close(sock);

    return 0;
}