#include "AcceptException.h"

AcceptException::AcceptException(int errNumber) : WhatWhyExceptionBase(errNumber) {};

const char *AcceptException::what() const _NOEXCEPT {
    return "AcceptException: Accept Connection Failed";
}

const char *AcceptException::why() const noexcept {
    return errors.at(errNumber);
}

const std::map<int, const char*> AcceptException::errors = {
        {EAGAIN, "O_NONBLOCK is set for the socket file descriptor and no connections are present to be accepted"},
        {EBADF, "The socket argument is not a valid file descriptor."},
        {ECONNABORTED, "A connection has been aborted."},
        {EFAULT, "The address or address_len parameter can not be accessed or written."},
        {EINTR, "The accept() function was interrupted by a signal that was caught before a valid connection arrived."},
        {EINVAL, "The socket is not accepting connections."},
        {EMFILE, "{OPEN_MAX} file descriptors are currently open in the calling process."},
        {ENFILE, "The maximum number of file descriptors in the system are already open."},
        {ENOTSOCK, "The socket argument does not refer to a socket."},
        {EOPNOTSUPP, "The socket type of the specified socket does not support accepting connections."},
        {ENOBUFS, "No buffer space is available."},
        {ENOMEM, "There was insufficient memory available to complete the operation."},
        {ENOSR, "There was insufficient STREAMS resources available to complete the operation."},
        {EPROTO, "A protocol error has occurred; for example, the STREAMS protocol stack has not been initialised."}
};