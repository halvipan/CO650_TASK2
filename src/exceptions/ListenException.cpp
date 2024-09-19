#include "ListenException.h"

ListenException::ListenException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *ListenException::what() const _NOEXCEPT {
    return "ListenException: Socket Listen Failed";
}

const char *ListenException::why() const noexcept {
    return errors.at(errNumber);
}

const std::map<int, const char*> ListenException::errors = {
        {EBADF,"The socket argument is not a valid file descriptor."},
        {EDESTADDRREQ, "The socket is not bound to a local address, and the protocol does not support listening on an unbound socket."},
        {EINVAL, "The socket is already connected."},
        {ENOTSOCK, "The socket argument does not refer to a socket."},
        {EOPNOTSUPP, "The socket protocol does not support listen()."},
        {EACCES, "The calling process does not have the appropriate privileges."},
        {EINVAL, "The socket has been shut down."},
        {ENOBUFS, "Insufficient resources are available in the system to complete the call."},
};