#include <unistd.h>
#include "Client.h"

int main()
{
    Client* client = new Client();

    int sock = client->CreateSocket();
    client->Connect(sock);
    client->SendAndReceive(sock);
    close(sock);

    return 0;
}
