#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "Comms.h"
#include "Client.h"

using namespace std;

// adapted from Jasmin Martin's research (thank you!)

void *receiver(void *sock)
{
    int server = *(int *)sock;

    while(true)
    {
        char buffer[200] = "";
        int recvRes = recv(server, buffer, 200, 0);
        if (recvRes == -1) {
            cout << "RECV ERROR" << endl;
            break;
        } else if (recvRes == 0) {
            cout << "SERVER DISCONNECT" << endl;
            break;
        } else {
            cout << "\033[1A" << "\033[2K";
            cout << "\rServer: " << "\033[31m" << buffer << "\033[0m" << endl;
            cout << "> ";
            cout.flush();
        }
    }
}

int main()
{
    Client* client = new Client();

    int sock = client->CreateSocket();
    sockaddr_in service = client->CreateAddress();
    client->Connect(sock, service);
    client->SendAndReceive(sock);

    // STEP 5 - CLEANUP / DISCONNECT
    close(sock);

    return 0;
}
