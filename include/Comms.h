#ifndef CO650_TASK2_COMMS_H
#define CO650_TASK2_COMMS_H

class Comms {
public:
    int CreateSocket();
    sockaddr_in CreateAddress();
    void SendAndReceive(int socket);
private:
    static void* receiver(void *sock);
};

#endif //CO650_TASK2_COMMS_H
