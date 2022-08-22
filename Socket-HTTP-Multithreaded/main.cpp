/*
    0034430 - Artur Francisco Pereira Carvalho
    0034436 - Deivison Oliveira Costa
    -
*/
#include <ServerWeb.h>

using namespace std;
//Definindo a porta do socket
#define NUMBER_PORT 8857

int main()
{
    cout << "Multithreaded Web Server - Computer networks task - IFMG Campus Bambuí" << endl;
    //Iniciando o servidor com o numero da porta definido
    ServerWeb new_server(NUMBER_PORT);
    new_server.~ServerWeb();

    return 0;
}
