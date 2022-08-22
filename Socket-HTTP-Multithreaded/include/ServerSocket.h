#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <sys/socket.h>//Biblioteca para criação de socket
#include <arpa/inet.h>//Biblioteca para configuração de endereços de socket

class ServerSocket
{
    public:
        ServerSocket();
        ServerSocket(int);
        virtual ~ServerSocket();
        int Start_Connection();
    protected:

    private:
        void Open_Socket(int);
        struct sockaddr server_address;
        int socket_identy;
};

#endif // SERVERSOCKET_H
