#ifndef CO650_TASK2_COMMS_H
#define CO650_TASK2_COMMS_H

#include <arpa/inet.h>

class Comms {
public:
    Comms();
    int CreateSocket();
    virtual void SendAndReceive(int socket) = 0;

protected:
    static const char* ADDRESS;
    sockaddr_in service;
    static void* receiver(void *sock);
    static void* sender(void *sock);
    static bool breakOnQuit;
};

#endif //CO650_TASK2_COMMS_H
