#ifndef PASSIVE_SOCKET_H
#define PASSIVE_SOCKET_H

#include <string>
#include "common_socket.h"
#include "common_active_socket.h"

class PassiveSocket : public Socket {
public:
    explicit PassiveSocket(const std::string& port);

    /* Conecta el socket pasivo al puerto especificado al crearlo.
     * Lanza una excepción si hubo error */
    void bind();

    /* Indica a un socket pasivo que escuche conexiones
     * Lanza una excepción si hubo error */
    void listen(int max_waiting_clients = default_max_waiting_clients);

    /* Acepta una conexión de un cliente en espera
     * Lanza una excepción si hubo error */
    ActiveSocket accept();
};

#endif  // PASSIVE_SOCKET_H
