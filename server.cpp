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
}

void *client_handler(void *clientSocket)
{
    cout << "entered thread" << endl;
    int client = *(int *)clientSocket;  // Correctly dereference the pointer

    // setup receiver thread
    pthread_t thread;
    pthread_create(&thread, nullptr, receiver, (void *)clientSocket);
    pthread_detach(thread);

    while (true) {
        char message[200];
        cout << "> ";
        cout.flush();
        cin.getline(message,200);

        int sendRes = send(client, message, 200, 0);
        if (sendRes == -1)
            cout << "Server: send() error" << endl;
    }
}

int main()
{
    Server* server = new Server();

    int sock = server->CreateSocket();
    sockaddr_in service = server->CreateAddress();
    server->Bind(sock, service);

    // STEP 4 - LISTENING
    if (listen(sock, SOMAXCONN) == -1) {
        cout << "listen failed" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "listening..." << endl;

    // STEP 5 - ACCEPT
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(sock, (sockaddr*)&client, &clientSize);
    if (clientSocket == -1) cout << "accept error" << endl;
    cout << "accept successful! Now connected to the client and creating thread" << endl;

    // Allocate memory to pass the clientSocket to the thread
    int *clientSockPtr = (int *)malloc(sizeof(int));
    *clientSockPtr = clientSocket;

    pthread_t thread;
    pthread_create(&thread, nullptr, client_handler, (void *)clientSockPtr);
    pthread_join(thread, nullptr);

    // STEP 7 - DISCONNECT

    close(sock);

    return 0;
}