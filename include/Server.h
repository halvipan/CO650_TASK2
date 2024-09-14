#ifndef CO650_TASK2_SERVER_H
#define CO650_TASK2_SERVER_H

#include <arpa/inet.h>
#include "Comms.h"

class Server : public Comms {
public:
    void Bind(int sock, sockaddr_in service);
};

#endif //CO650_TASK2_SERVER_H
