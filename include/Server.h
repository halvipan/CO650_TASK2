#ifndef CO650_TASK2_SERVER_H
#define CO650_TASK2_SERVER_H

#include "Comms.h"

class Server : public Comms {
public:
    void Bind(int sock);
    void Listen(int sock);
    int Accept(int sock);
};

#endif //CO650_TASK2_SERVER_H
