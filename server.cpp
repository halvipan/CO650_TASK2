#include <unistd.h>
#include "Server.h"

using namespace std;

int main()
{
    Server* server = new Server();

    int sock = server->CreateSocket();
    server->Bind(sock);
    server->Listen(sock);
    int clientSocket = server->Accept(sock);
    server->SendAndReceive(clientSocket);
    close(sock);

    return 0;
}