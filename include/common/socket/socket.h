#ifndef SOCKET_H
#define SOCKET_H

#include <cerrno>
#include <cstring>  // memset()

#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <string>
#include <stdexcept>

class Socket {
public:
    /* Abre un socket. Lanza una excepción si hubo error */
    Socket(const char* hostname, const char* port,
                   int socket_family, int socket_type, int flags);

    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    Socket(Socket&& other);

    Socket& operator=(Socket&& other);

    ~Socket();

    void shutdown(int how = SHUT_RDWR);

    void shutdown_read();

    void shutdown_write();

    bool isValid();

protected:
    int fd_ = -1;
    struct addrinfo *addrinfo_ = nullptr;

    static constexpr int default_max_waiting_clients = 10;

    explicit Socket(int fd): fd_(fd) {}
};

#endif /* SOCKET_H */
