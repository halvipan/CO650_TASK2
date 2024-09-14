#include <iostream>
#include "Client.h"

using namespace std;

void Client::Connect(int sock, sockaddr_in service) {
    int connectRes = connect(sock, (sockaddr*)&service, sizeof(service));
    if (connectRes == -1) {
        cout << "error with connection" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "connection okay - now connected to Server" << endl;
}