#define _POSIX_C_SOURCE 200112L
#include "socket.h"
#include <string>

Socket::Socket(const char* hostname, const char* port,
           int socket_family, int socket_type, int flags) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = socket_family;
    hints.ai_socktype = socket_type;
    hints.ai_flags = flags;

    struct addrinfo *result;
    int ret_code = getaddrinfo(hostname, port, &hints, &result);
    if (ret_code) {
        std::string error_message("Error en getaddrinfo: ");
        error_message += std::string(gai_strerror(ret_code));
        throw std::runtime_error(error_message);
    }
    addrinfo_ = result;
}

Socket::Socket(Socket&& other) {
    this->fd_ = other.fd_;
    other.fd_ = -1;
    this->addrinfo_ = other.addrinfo_;
    other.addrinfo_ = nullptr;
}

Socket& Socket::operator=(Socket&& other) {
    this->fd_ = other.fd_;
    other.fd_ = -1;
    this->addrinfo_ = other.addrinfo_;
    other.addrinfo_ = nullptr;
    return *this;
}

void Socket::shutdown(int how) {
    ::shutdown(fd_, how);
}

void Socket::shutdown_read() {
    shutdown(SHUT_RD);
}

void Socket::shutdown_write() {
    shutdown(SHUT_WR);
}

bool Socket::isValid() {
    return (fd_ != -1);
}

Socket::~Socket() {
    if (fd_ != -1) {
        ::shutdown(fd_, SHUT_RDWR);
        close(fd_);
    }
    if (addrinfo_) {
        freeaddrinfo(addrinfo_);
    }
}
