#ifndef CO650_TASK2_SENDEXCEPTION_H
#define CO650_TASK2_SENDEXCEPTION_H

#include <map>
#include "WhatWhyExceptionBase.h"

class SendException : public WhatWhyExceptionBase {
public:
    explicit SendException(int errNumber);
    const char* what() const _NOEXCEPT override;
    const char* why() const _NOEXCEPT override;

private:
    static const std::map<int, const char*> errors;
};

#endif //CO650_TASK2_SENDEXCEPTION_H
