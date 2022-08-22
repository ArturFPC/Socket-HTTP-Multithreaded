#ifndef SERVERFILE_H
#define SERVERFILE_H

#include <string.h> //std::string
#include <ServerSocket.h>//Socket
#include <iostream>//std::cout
#include <fstream>//std::ifstream
#include <filesystem>//std::exists
#include <unistd.h>//std::getcwd

using namespace std;

class ServerFile
{
    public:
        ServerFile();
        ServerFile(string, int);
        virtual ~ServerFile();
        string Send_File(string, int);
        string Return_Directory();
        string Useful_Name(string);
    protected:

    private:

};

#endif // SERVERFILE_H
