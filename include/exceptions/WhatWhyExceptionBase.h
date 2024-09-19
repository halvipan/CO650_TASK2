#ifndef CO650_TASK2_WHATWHYEXCEPTIONBASE_H
#define CO650_TASK2_WHATWHYEXCEPTIONBASE_H

#include <exception>

class WhatWhyExceptionBase : public std::exception {
public:
    explicit WhatWhyExceptionBase(int errNumber) : errNumber(errNumber) {}
    virtual const char* why() const _NOEXCEPT = 0;

protected:
    int errNumber;
};

#endif //CO650_TASK2_WHATWHYEXCEPTIONBASE_H
