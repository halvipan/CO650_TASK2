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