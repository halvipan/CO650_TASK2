#include <unistd.h>
#include "Client.h"

using namespace std;

int main()
{
    Client* client = new Client();

    int sock = client->CreateSocket();
    sockaddr_in service = client->CreateAddress();
    client->Connect(sock, service);
    client->SendAndReceive(sock);
    close(sock);

    return 0;
}
