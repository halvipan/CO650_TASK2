#ifndef CO650_TASK2_LISTENEXCEPTION_H
#define CO650_TASK2_LISTENEXCEPTION_H

#include <map>
#include "WhatWhyExceptionBase.h"

class ListenException : public WhatWhyExceptionBase {
public:
    explicit ListenException(int errNumber);
    const char* what() const _NOEXCEPT override;
    const char* why() const _NOEXCEPT override;

private:
    static const std::map<int, const char*> errors;
};


#endif //CO650_TASK2_LISTENEXCEPTION_H
