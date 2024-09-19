#include "SendException.h"

SendException::SendException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *SendException::what() const _NOEXCEPT {
    return "SendException: Message Send Failed";
}

const char *SendException::why() const noexcept {
    return errors.at(errNumber);
}

const std::map<int, const char*> SendException::errors = {
        {EAGAIN,"The socket's file descriptor is marked O_NONBLOCK and the requested operation would block."},
        {EBADF, "The socket argument is not a valid file descriptor."},
        {ECONNRESET, "A connection was forcibly closed by a peer."},
        {EDESTADDRREQ, "The socket is not connection-mode and no peer address is set."},
        {EFAULT, "The buffer parameter can not be accessed."},
        {EINTR, "A signal interrupted send() before any data was transmitted."},
        {EMSGSIZE, "The message is too large be sent all at once, as the socket requires."},
        {ENOTCONN, "The socket is not connected or otherwise has not had the peer prespecified."},
        {ENOTSOCK, "The socket argument does not refer to a socket."},
        {EOPNOTSUPP, "The socket argument is associated with a socket that does not support one or more of the values set in flags."},
        {EPIPE, "The socket is shut down for writing, or the socket is connection-mode and is no longer connected. In the latter case, and if the socket is of type SOCK_STREAM, the SIGPIPE signal is generated to the calling process."},
        {EACCES, "The calling process does not have the appropriate privileges."},
        {EIO, "An I/O error occurred while reading from or writing to the file system."},
        {ENETDOWN, "The local interface used to reach the destination is down."},
        {ENETUNREACH, "No route to the network is present."},
        {ENOBUFS, "Insufficient resources were available in the system to perform the operation."},
        {ENOSR, "There were insufficient STREAMS resources available for the operation to complete."},
};