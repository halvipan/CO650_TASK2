#ifndef CO650_TASK2_CREATESOCKETEXCEPTION_H
#define CO650_TASK2_CREATESOCKETEXCEPTION_H

#include <map>
#include "WhatWhyExceptionBase.h"

class CreateSocketException : public WhatWhyExceptionBase {
public:
    explicit CreateSocketException(int errNumber);
    const char* what() const _NOEXCEPT override;
    const char* why() const _NOEXCEPT override;

private:
    static const std::map<int, const char*> errors;
};

#endif //CO650_TASK2_CREATESOCKETEXCEPTION_H
