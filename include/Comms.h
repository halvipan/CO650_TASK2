#ifndef CO650_TASK2_COMMS_H
#define CO650_TASK2_COMMS_H

class Comms {
public:
    Comms();
    int CreateSocket();
    void SendAndReceive(int socket);

private:
    static void* receiver(void *sock);

protected:
    sockaddr_in service;
};

#endif //CO650_TASK2_COMMS_H
