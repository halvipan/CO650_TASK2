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
            cout << "CLIENT DISCONNECT" << endl;
            break;
        } else {
            cout << "\033[1A" << "\033[2K";
            cout << "\rClient: " << "\033[31m" << buffer << "\033[0m" << endl;
            cout << "> ";
            cout.flush();
        }
    }

    terminate();
}

int main()
{
    Server* server = new Server();

    int sock = server->CreateSocket();
    sockaddr_in service = server->CreateAddress();
    server->Bind(sock, service);
    server->Listen(sock);
    int clientSocket = server->Accept(sock);


    pthread_t thread;
    pthread_create(&thread, nullptr, receiver, &clientSocket);
    pthread_detach(thread);

    while (true) {
        char message[200];
        cout << "> ";
        cout.flush();
        cin.getline(message,200);

        int sendRes = send(clientSocket, message, 200, 0);
        if (sendRes == -1)
            cout << "Server: send() error" << endl;
    }

    // STEP 7 - DISCONNECT

    close(sock);

    return 0;
}