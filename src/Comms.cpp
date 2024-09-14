#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Comms.h"

using namespace std;

int Comms::CreateSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        cout << "error with creating socket" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "socket created" << endl;
    return sock;
}

sockaddr_in Comms::CreateAddress() {
    sockaddr_in service{};
    string address = "127.0.0.1";
    service.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &service.sin_addr);
    service.sin_port = htons(5400);
    return service;
}