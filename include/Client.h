#ifndef CO650_TASK2_CLIENT_H
#define CO650_TASK2_CLIENT_H

#include "Comms.h"

class Client : public Comms {
public:
    void Connect(int sock);
    void SendAndReceive(int socket) override;
private:
    static void sender(int socket);
};

#endif //CO650_TASK2_CLIENT_H
