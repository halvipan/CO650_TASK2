#ifndef CO650_TASK2_COMMS_H
#define CO650_TASK2_COMMS_H

#include <arpa/inet.h>

class Comms {
public:
    Comms();
    int CreateSocket();
    void SendAndReceive(int socket);
    virtual bool ShutdownCondition(char *message);

private:
    static void* receiver(void *sock);

protected:
    sockaddr_in service;
};

#endif //CO650_TASK2_COMMS_H
