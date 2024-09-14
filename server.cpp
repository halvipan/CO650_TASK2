#include <unistd.h>
#include "Server.h"

using namespace std;

int main()
{
    Server* server = new Server();

    int sock = server->CreateSocket();
    sockaddr_in service = server->CreateAddress();
    server->Bind(sock, service);
    server->Listen(sock);
    int clientSocket = server->Accept(sock);
    server->SendAndReceive(clientSocket);
    close(sock);

    return 0;
}