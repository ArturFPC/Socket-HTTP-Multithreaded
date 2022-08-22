#include <ServerFile.h>

ServerFile::ServerFile()
{
    //ctor
}

ServerFile::ServerFile(string file_name, int socket_starter)
{

}

ServerFile::~ServerFile()
{
    //dtor
}
//Função para retornar o conteúdo do arquivo
string ServerFile::Send_File(string file_name, int socket_starter)
{
    //variavel utilizada para abrir o arquivo
    ifstream file;
    string line;
    file_name=Useful_Name(file_name);
    //Abrindo o arquivo de nome file_ext no diretório definido
    file.open(Return_Directory() + file_name);

    //Coletando o conteúdo do arquivo
    string response = "";
    while(getline(file, line)){
        response += line;
    }
    return response;
}
//Função para retornar o diretório raiz do projeto
string ServerFile::Return_Directory()
{
    char dir[256];
    //Função que retorna o diretório atual da variável dir
    getcwd(dir,256);
    string directory_current(dir);

    return directory_current;
}
string ServerFile::Useful_Name(string file_name){
    //Pegando apenas nome do arquivo requisitado da mensagem retornada do navegador
    string file_ext = "";
    int i =4;
    while (file_name[i]!=' '){
        file_ext+=file_name[i];
        i++;
    }
    return file_ext;
}
