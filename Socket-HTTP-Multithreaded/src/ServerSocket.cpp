#include <ServerSocket.h>

ServerSocket::ServerSocket()
{
    //ctor
}

ServerSocket::ServerSocket(int port_number)
{
    Open_Socket(port_number);
}

ServerSocket::~ServerSocket()
{
    //dtor
}

// Método que abre e configura um socket
void ServerSocket::Open_Socket(int port_number)
{
    // Definindo propriedades de rede do socket
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_pton(AF_INET, "0.0.0.0", &server_address.sin_addr);
    // Definindo  o protocolo de internet IPV4 e conexão TCP
    socket_identy = socket(AF_INET, SOCK_STREAM, 0);
    // Definindo as configurações do socket
    int opt_value;
    setsockopt(socket_identy, SOL_SOCKET, SO_REUSEADDR, &opt_value, sizeof(opt_value));
    // Vinculando o endereço e a porta ao socket
    bind(socket_identy, (struct sockaddr *) &server_address, sizeof(server_address));
    // Permitindo uma conexão por socket
    listen(socket_identy, 1);
}

int ServerSocket::Start_Connection()
{
    // Pegando o tamanho do endereço
    socklen_t lenght_address = sizeof(server_address);
    // Extraindo a primeira requisição de conexão da fila para o socket que foi aberto
    return accept(socket_identy, (struct sockaddr *) &server_address, &lenght_address);
}
