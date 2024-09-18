#include <iostream>
#include <unistd.h>
#include "Server.h"
#include "CreateSocketException.h"

using namespace std;

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
    catch (CreateSocketException &e) {
        cout << e.what() << endl;
        cout << e.why() << endl;
    }

    return 0;
}