#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

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
    sockaddr_in service{};
    string address = "127.0.0.1";

    // STEP 2  - CREATE THE SOCKET
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        cout << "error with creating socket" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "socket created" << endl;

    // STEP 3 - CONNECT ON CLIENT SOCKET
    service.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &service.sin_addr);
    service.sin_port = htons(5400);

    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) {
        cout << "error with connection" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "connection okay - now connected to Server" << endl;

    // STEP 4 - SEND & RECV

    // setup receiver thread
    int *SockPtr = (int *)malloc(sizeof(int));
    *SockPtr = sock;
    pthread_t thread;
    pthread_create(&thread, nullptr, receiver, (void *)SockPtr);
    pthread_detach(thread);

    while (true) {
        char message[200];
        cout << "> ";
        cout.flush();
        cin.getline(message,200);

        if (strcmp(message, "SHUTDOWN") == 0)
            break;

        int sendRes = send(sock, message, 200, 0);
        if (sendRes == -1)
            cout << "Client: send() error" << endl;
    }

    // STEP 5 - CLEANUP / DISCONNECT
    close(sock);

    return 0;
}
