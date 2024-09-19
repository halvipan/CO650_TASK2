#ifndef CO650_TASK2_ACCEPTEXCEPTION_H
#define CO650_TASK2_ACCEPTEXCEPTION_H

#include <map>
#include "WhatWhyExceptionBase.h"

class AcceptException : public WhatWhyExceptionBase {
public:
    explicit AcceptException(int errNumber);
    const char* what() const _NOEXCEPT override;
    const char* why() const _NOEXCEPT override;

private:
    static const std::map<int, const char*> errors;
};

#endif //CO650_TASK2_ACCEPTEXCEPTION_H
