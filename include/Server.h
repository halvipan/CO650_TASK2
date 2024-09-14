#ifndef CO650_TASK2_SERVER_H
#define CO650_TASK2_SERVER_H

#include <arpa/inet.h>
#include "Comms.h"

class Server : public Comms {
public:
    void Bind(int sock, sockaddr_in service);
    void Listen(int sock);
    int Accept(int sock);
};

#endif //CO650_TASK2_SERVER_H
