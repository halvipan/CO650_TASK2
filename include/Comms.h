#ifndef CO650_TASK2_COMMS_H
#define CO650_TASK2_COMMS_H

#include <arpa/inet.h>

class Comms {
public:
    Comms();
    int CreateSocket();
    virtual void SendAndReceive(int socket) = 0;

protected:
    static void* receiver(void *sock);

protected:
    sockaddr_in service;
    static const char* ADDRESS;
};

#endif //CO650_TASK2_COMMS_H
