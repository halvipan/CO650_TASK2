#include "CreateSocketException.h"

CreateSocketException::CreateSocketException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *CreateSocketException::what() const _NOEXCEPT {
    return "CreateSocketException: Socket Creation Failed";
}

const char *CreateSocketException::why() const noexcept {
    return errors.at(errNumber);
}

const map<int, const char*> CreateSocketException::errors = {
    {EAFNOSUPPORT, "The implementation does not support the specified address family."},
    {EMFILE, "No more file descriptors are available for this process."},
    {ENFILE, "No more file descriptors are available for the system."},
    {EPROTONOSUPPORT, "The protocol is not supported by the address family, or the protocol is not supported by the implementation."},
    {EPROTOTYPE, "The socket type is not supported by the protocol."},
    {EACCES, "The process does not have appropriate privileges."},
    {ENOBUFS, "Insufficient resources were available in the system to perform the operation."},
    {ENOMEM, "Insufficient memory was available to fulfill the request."},
    {ENOSR, "There were insufficient STREAMS resources available for the operation to complete."}
};