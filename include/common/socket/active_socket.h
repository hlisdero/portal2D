#ifndef ACTIVE_SOCKET_H
#define ACTIVE_SOCKET_H

#include <cstdint>
#include <arpa/inet.h>
#include <string>
#include "common/socket/socket.h"

class ActiveSocket : public Socket {
public:
    explicit ActiveSocket(int fd);

    ActiveSocket(const std::string& hostname, const std::string& port);

    /* Conecta el socket al hostname y puerto especificado al crearlo.
     * Lanza una excepción si hubo error */
    void connect();

    /* Envía un arreglo de char a través del socket.
     * Lanza una excepción si hubo error */
    void send(const char *buf, int size);

    /* Recibe un arreglo de char a través del socket.
     * Lanza una excepción si hubo error */
    void receive(char *buf, int size);

    void receive(std::string& str, int size);

    /* Operadores sobrecargados para enviar y recibir ciertos tipos
     * Lanzan excepciones si hubo error */
    ActiveSocket& operator<<(double num);
    ActiveSocket& operator<<(float num);
    ActiveSocket& operator<<(uint32_t num);
    ActiveSocket& operator<<(uint16_t num);
    ActiveSocket& operator<<(uint8_t num);
    ActiveSocket& operator<<(const std::string& str);

    ActiveSocket& operator>>(double& num);
    ActiveSocket& operator>>(float& num);
    ActiveSocket& operator>>(uint32_t& num);
    ActiveSocket& operator>>(uint16_t& num);
    ActiveSocket& operator>>(uint8_t& num);
};

#endif  // ACTIVE_SOCKET_H
