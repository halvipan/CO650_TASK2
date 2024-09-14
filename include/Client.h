#ifndef CO650_TASK2_CLIENT_H
#define CO650_TASK2_CLIENT_H

#include <arpa/inet.h>
#include "Comms.h"

class Client : public Comms {
public:
    void Connect(int sock, sockaddr_in service);
};

#endif //CO650_TASK2_CLIENT_H
