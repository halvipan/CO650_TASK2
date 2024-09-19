#include "ConnectException.h"

ConnectException::ConnectException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *ConnectException::what() const _NOEXCEPT {
    return "ConnectException: Connect Failed";
}

const char *ConnectException::why() const noexcept {
    return errors.at(errNumber);
}

const std::map<int, const char*> ConnectException::errors = {
        {EADDRNOTAVAIL, "The specified address is not available from the local machine."},
        {EAFNOSUPPORT, "The specified address is not a valid address for the address family of the specified socket."},
        {EALREADY, "A connection request is already in progress for the specified socket."},
        {EBADF, "The socket argument is not a valid file descriptor."},
        {ECONNREFUSED, "The target address was not listening for connections or refused the connection request."},
        {EFAULT, "The address parameter can not be accessed."},
        {EINPROGRESS, "O_NONBLOCK is set for the file descriptor for the socket and the connection cannot be immediately established; the connection will be established asynchronously."},
        {EINTR, "The attempt to establish a connection was interrupted by delivery of a signal that was caught; the connection will be established asynchronously."},
        {EISCONN,"The specified socket is connection-mode and is already connected."},
        {ENETUNREACH,"No route to the network is present."},
        {ENOTSOCK,"The socket argument does not refer to a socket."},
        {EPROTOTYPE,"The specified address has a different type than the socket bound to the specified peer address."},
        {ETIMEDOUT,"The attempt to connect timed out before a connection was made."},
        {EACCES,"Search permission is denied for a component of the path prefix; or write access to the named socket is denied."},
        {EADDRINUSE,"Attempt to establish a connection that uses addresses that are already in use."},
        {ECONNRESET,"Remote host reset the connection request."},
        {EHOSTUNREACH,"The destination host cannot be reached (probably because the host is down or a remote router cannot reach it)."},
        {EINVAL,"The address_len argument is not a valid length for the address family; or invalid address family in sockaddr structure."},
        {ENAMETOOLONG,"Pathname resolution of a symbolic link produced an intermediate result whose length exceeds {PATH_MAX}."},
        {ENETDOWN,"The local interface used to reach the destination is down."},
        {ENOBUFS,"No buffer space is available."},
        {ENOSR,"There were insufficient STREAMS resources available to complete the operation."},
        {EOPNOTSUPP,"The socket is listening and can not be connected."},
};