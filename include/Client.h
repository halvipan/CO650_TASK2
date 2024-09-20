#ifndef CO650_TASK2_CLIENT_H
#define CO650_TASK2_CLIENT_H

#include "Comms.h"

class Client : public Comms {
public:
    Client();
    void Connect(int sock);
    void SendAndReceive(int socket) override;
};

#endif //CO650_TASK2_CLIENT_H
