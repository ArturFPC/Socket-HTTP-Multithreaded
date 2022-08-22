#ifndef SERVERWEB_H
#define SERVERWEB_H

#include <ServerSocket.h>//Socket
#include <ServerFile.h>//Arquivo
#include <iostream>//std::cout
#include <time.h>//std::time
#include <sstream>//std::ostringstream
#include <thread>

class ServerWeb: public ServerSocket
{
    public:
        ServerWeb();
        ServerWeb(int);
        virtual ~ServerWeb();
        static void Conection_Socket(int,char*,int);
    protected:

    private:
        static string Response_HTTP(int,string);
};

#endif // SERVERWEB_H
