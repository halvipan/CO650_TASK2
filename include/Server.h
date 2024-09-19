#ifndef CO650_TASK2_SERVER_H
#define CO650_TASK2_SERVER_H

#include "Comms.h"

class Server : public Comms {
public:
    void Bind(int sock);
    void Listen(int sock);
    int Accept(int sock);
    void SendAndReceive(int socket) override;
private:
    static void* sender(void *sock);
};

#endif //CO650_TASK2_SERVER_H
