#ifndef CO650_TASK2_COMMS_H
#define CO650_TASK2_COMMS_H

class Comms {
public:
    int CreateSocket();
    sockaddr_in CreateAddress();
};

#endif //CO650_TASK2_COMMS_H
