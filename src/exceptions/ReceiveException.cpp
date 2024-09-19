#include "ReceiveException.h"

ReceiveException::ReceiveException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *ReceiveException::what() const _NOEXCEPT {
    return "ReceiveException: Recieve Message Failed";
}

const char *ReceiveException::why() const noexcept {
    return errors.at(errNumber);
}

const std::map<int, const char*> ReceiveException::errors = {
        {EAGAIN,"The socket's file descriptor is marked O_NONBLOCK and no data is waiting to be received; or MSG_OOB is set and no out-of-band data is available and either the socket's file descriptor is marked O_NONBLOCK or the socket does not support blocking to await out-of-band data."},
        {EBADF,"The socket argument is not a valid file descriptor."},
        {ECONNRESET,"A connection was forcibly closed by a peer."},
        {EFAULT,"The buffer parameter can not be accessed or written."},
        {EINTR,"The recv() function was interrupted by a signal that was caught, before any data was available."},
        {EINVAL,"The MSG_OOB flag is set and no out-of-band data is available."},
        {ENOTCONN,"A receive is attempted on a connection-mode socket that is not connected."},
        {ENOTSOCK,"The socket argument does not refer to a socket."},
        {EOPNOTSUPP,"The specified flags are not supported for this socket type or protocol."},
        {ETIMEDOUT,"The connection timed out during connection establishment, or due to a transmission timeout on active connection."},
        {EIO,"An I/O error occurred while reading from or writing to the file system."},
        {ENOBUFS,"Insufficient resources were available in the system to perform the operation."},
        {ENOMEM,"Insufficient memory was available to fulfill the request."},
        {ENOSR,"There were insufficient STREAMS resources available for the operation to complete."}
};