#include <ServerWeb.h>

ServerWeb::ServerWeb()
{
    //ctor
}

ServerWeb::ServerWeb(int port_number)
{
    const int buf_size = 4096;
    char buf[buf_size];
    ServerSocket server_socket(port_number);
    int socket_starter;
    cout << "Server hosted in folder:\n" << getcwd(buf, buf_size) << endl;
    cout << "Connected port:\n" << port_number << "\nWarning messages: " << endl;
    while(true){
        // Inicia a conexão com o socket
        socket_starter = server_socket.Start_Connection();
        // Verifica se foi estabelecida uma conexão com o socket
        if (socket_starter>=0){
            // Inicia e dispara uma thread responsável por receber as requisiçoes no socket
            thread request(Conection_Socket,socket_starter,buf,buf_size);
            request.join();
        }
    }

    server_socket.~ServerSocket();
}

ServerWeb::~ServerWeb()
{
    //dtor
}
void ServerWeb::Conection_Socket(int socket_starter,char* buf,int buf_size){
    int datagram = recv(socket_starter, buf, buf_size, 0);
    string file_name(buf, 0, datagram);
    ServerFile file_requested(file_name, socket_starter);
    // Definimos o conteúdo que ira compor o cabeçalho a ser enviado pro cliente
    string response_content = file_requested.Send_File(file_name, socket_starter);
    string response_full;
    string usefulName = file_requested.Useful_Name(file_name);
    string file_directory=file_requested.Return_Directory() + usefulName;
    // Verificamos se o arquivo existe no diretorio do servidor, retornando a resposta correspondente
    if (std::filesystem::exists(file_directory)){
        response_full = Response_HTTP(200, response_content);
        cout<<"File "<<usefulName<<" found"<<endl;
    }else{
        response_full = Response_HTTP(404,response_content);
        cout<<"File "<<usefulName<<" not found"<<endl;
    }
    send(socket_starter, response_full.c_str(), response_full.length(), MSG_CONFIRM);
    file_requested.~ServerFile();
}
// Metodo que defini o cabeçalho de resposta e o retorna
string ServerWeb::Response_HTTP(int state_line, string entity_body){
    string response("HTTP/1.1 ");
    // Pegamos data e hora atual do sistema
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    // Armazena a data e a hora em um buffer
    ostringstream oss;
    // Definimos o formato especifico desejado de date e hora
    oss << put_time(&tm, "%a, %d %b %Y %H:%M:%S GMT-3");
    auto str = oss.str();
    if (state_line == 200){
        response += "200 OK";
    } else if (state_line == 404){
        response += "404 Not Found";
    }
    response += "\nConnection: close\nDate: "+str
    +"\nServer: Apache/2.2.3 (CentOS)"
    +"\nLast-Modified: "+oss.str()
    +"\nContent-Length: "+to_string(entity_body.size())
    +"\nContent-Type: text/html"
    +"\n\n"+entity_body;

    return response;
}
