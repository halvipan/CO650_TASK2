#include <unistd.h>
#include "Client.h"

using namespace std;

int main()
{
    Client* client = new Client();

    int sock = client->CreateSocket();
    client->Connect(sock);
    client->SendAndReceive(sock);
    close(sock);

    return 0;
}
