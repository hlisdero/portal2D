#define _POSIX_C_SOURCE 200112L
#include "common/socket/active_socket.h"
#include <string>
#include <vector>

ActiveSocket::ActiveSocket(int fd): Socket(fd) {}

ActiveSocket::ActiveSocket(const std::string& hostname,
                           const std::string& port) :
    Socket(hostname.c_str(), port.c_str(), AF_INET, SOCK_STREAM, 0) {}

void ActiveSocket::connect() {
    int ret_code = -1;
    struct addrinfo *ptr;

    for (ptr = addrinfo_; ptr && (ret_code == -1); ptr = ptr->ai_next) {
        fd_ = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (fd_ == -1) {
            std::string error_message("Error al crear el socket: ");
            error_message += std::string(strerror(errno));
            throw std::runtime_error(error_message);
        }

        ret_code = ::connect(fd_, ptr->ai_addr, ptr->ai_addrlen);
        if (ret_code == -1) {
            std::string error_message("Error al intentar conectar: ");
            error_message += std::string(strerror(errno));
            throw std::runtime_error(error_message);
        }
    }
}

void ActiveSocket::send(const char *buf, int size) {
    int total_sent = 0;

    while (total_sent < size) {
        int sent = ::send(fd_, &buf[total_sent],
                        size-total_sent, MSG_NOSIGNAL);
        if (sent <= 0) {
            std::string error_message("Error en el envío de datos "
                                      "a través del socket: ");
            error_message += std::string(strerror(errno));
            throw std::runtime_error(error_message);
        }
        total_sent += sent;
    }
}

void ActiveSocket::receive(char *buf, int size) {
    int total_received = 0;

    while (total_received < size) {
        int received = recv(fd_, &buf[total_received],
                            size-total_received, 0);
        if (received <= 0) {
            std::string error_message("Error en la recepción de datos "
                                      "a través del socket: ");
            error_message += std::string(strerror(errno));
            throw std::runtime_error(error_message);
        }
        total_received += received;
   }
}

void ActiveSocket::receive(std::string& str, int size) {
    std::vector<char> buffer(size + 1, 0);   // '\0'
    receive(&buffer[0], size);
    buffer[size] = '\0';
    str = std::string(&buffer[0]);
}

ActiveSocket& ActiveSocket::operator<<(double num) {
    send(reinterpret_cast<char*>(&num), sizeof(double));
    return *this;
}

ActiveSocket& ActiveSocket::operator<<(float num) {
    send(reinterpret_cast<char*>(&num), sizeof(float));
    return *this;
}

ActiveSocket& ActiveSocket::operator<<(uint32_t num) {
    uint32_t net_num = htonl(num);
    send(reinterpret_cast<char*>(&net_num), 4);
    return *this;
}

ActiveSocket& ActiveSocket::operator<<(uint16_t num) {
    uint32_t net_num = htons(num);
    send(reinterpret_cast<char*>(&net_num), 2);
    return *this;
}

ActiveSocket& ActiveSocket::operator<<(uint8_t num) {
    send(reinterpret_cast<char*>(&num), 1);
    return *this;
}

ActiveSocket& ActiveSocket::operator<<(const std::string& str) {
    send(str.c_str(), str.length());
    return *this;
}

ActiveSocket& ActiveSocket::operator>>(double& num) {
    receive(reinterpret_cast<char*>(&num), sizeof(double));
    return *this;
}

ActiveSocket& ActiveSocket::operator>>(float& num) {
    receive(reinterpret_cast<char*>(&num), sizeof(float));
    return *this;
}

ActiveSocket& ActiveSocket::operator>>(uint32_t& num) {
    uint32_t net_num;
    receive(reinterpret_cast<char*>(&net_num), 4);
    num = ntohl(net_num);
    return *this;
}

ActiveSocket& ActiveSocket::operator>>(uint16_t& num) {
    uint16_t net_num;
    receive(reinterpret_cast<char*>(&net_num), 2);
    num = ntohs(net_num);
    return *this;
}

ActiveSocket& ActiveSocket::operator>>(uint8_t& num) {
    uint32_t net_num;
    receive(reinterpret_cast<char*>(&net_num), 1);
    num = net_num;
    return *this;
}
