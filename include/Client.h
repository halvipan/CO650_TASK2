#ifndef CO650_TASK2_CLIENT_H
#define CO650_TASK2_CLIENT_H

#include <arpa/inet.h>
#include "Comms.h"

class Client : public Comms {
public:
    void Connect(int sock);
};

#endif //CO650_TASK2_CLIENT_H
