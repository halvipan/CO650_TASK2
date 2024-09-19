#include "BindException.h"

BindException::BindException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *BindException::what() const _NOEXCEPT {
    return "BindException: Socket Bind Failed";
}

const char *BindException::why() const noexcept {
    return errors.at(errNumber);
}

const std::map<int, const char*> BindException::errors = {
    {EADDRINUSE, "The specified address is already in use."},
    {EADDRNOTAVAIL, "The specified address is not available from the local machine."},
    {EAFNOSUPPORT, "The specified address is not a valid address for the address family of the specified socket."},
    {EBADF, "The socket argument is not a valid file descriptor."},
    {EFAULT, "The address argument can not be accessed."},
    {EINVAL, "The socket is already bound to an address, and the protocol does not support binding to a new address; or the socket has been shut down."},
    {ENOTSOCK, "The socket argument does not refer to a socket."},
    {EOPNOTSUPP, "The socket type of the specified socket does not support binding to an address."},
    {EACCES,"The specified address is protected and the current user does not have permission to bind to it."},
    {EINVAL,"The address_len argument is not a valid length for the address family."},
    {EISCONN,"The socket is already connected."},
    {ENAMETOOLONG,"Pathname resolution of a symbolic link produced an intermediate result whose length exceeds {PATH_MAX}."},
    {ENOBUFS,"Insufficient resources were available to complete the call."},
    {ENOSR,"There were insufficient STREAMS resources for the operation to complete."},
};