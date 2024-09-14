#include <iostream>
#include <arpa/inet.h>
#include "Client.h"

using namespace std;

void Client::Connect(int sock) {
    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) {
        cout << "error with connection" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "connection okay - now connected to Server" << endl;
}