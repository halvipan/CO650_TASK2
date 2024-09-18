#ifndef CO650_TASK2_CREATESOCKETEXCEPTION_H
#define CO650_TASK2_CREATESOCKETEXCEPTION_H

#include <map>

using namespace std;

class CreateSocketException : public exception {
public:
    int errnumber;
    CreateSocketException(errno_t errnumber);
    const char* what() const _NOEXCEPT override;
    const char* why() const _NOEXCEPT;
    static const map<int, const char*> errors;
};

#endif //CO650_TASK2_CREATESOCKETEXCEPTION_H
