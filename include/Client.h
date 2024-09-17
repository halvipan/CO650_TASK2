#ifndef CO650_TASK2_CLIENT_H
#define CO650_TASK2_CLIENT_H

#include "Comms.h"

class Client : public Comms {
public:
    void Connect(int sock);
    bool ShutdownCondition(char *message) override;
};

#endif //CO650_TASK2_CLIENT_H
