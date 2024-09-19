#ifndef CO650_TASK2_WHATWHYEXCEPTIONBASE_H
#define CO650_TASK2_WHATWHYEXCEPTIONBASE_H

#include <exception>

using namespace std;

class WhatWhyExceptionBase : public exception {
public:
    explicit WhatWhyExceptionBase(int errNumber) : errNumber(errNumber) {}
    virtual const char* why() const _NOEXCEPT = 0;

protected:
    int errNumber;
};

#endif //CO650_TASK2_WHATWHYEXCEPTIONBASE_H
