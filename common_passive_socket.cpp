#define _POSIX_C_SOURCE 200112L
#include "common_passive_socket.h"
#include <string>

PassiveSocket::PassiveSocket(const std::string& port) :
    Socket(NULL, port.c_str(), AF_INET, SOCK_STREAM, AI_PASSIVE) {}

void PassiveSocket::bind() {
    fd_ = socket(addrinfo_->ai_family,
            addrinfo_->ai_socktype, addrinfo_->ai_protocol);
    if (fd_ == -1) {
        std::string error_message("Error al crear el socket: ");
        error_message += std::string(strerror(errno));
        throw std::runtime_error(error_message);
    }

    int val = 1;
    int ret_code = setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (ret_code == -1) {
        std::string error_message("Error al setear SO_REUSEADDR: ");
        error_message += std::string(strerror(errno));
        throw std::runtime_error(error_message);
    }

    ret_code = ::bind(fd_, addrinfo_->ai_addr, addrinfo_->ai_addrlen);
    if (ret_code == -1) {
        std::string error_message("Error al llamar a bind(): ");
        error_message += std::string(strerror(errno));
        throw std::runtime_error(error_message);
    }
}

void PassiveSocket::listen(int max_waiting_clients) {
    int ret_code = ::listen(fd_, max_waiting_clients);
    if (ret_code == -1) {
        std::string error_message("Error al llamar a listen(): ");
        error_message += std::string(strerror(errno));
        throw std::runtime_error(error_message);
    }
}

ActiveSocket PassiveSocket::accept() {
    int peerskt = ::accept(fd_, NULL, NULL);
    return std::move(ActiveSocket(peerskt));
}
