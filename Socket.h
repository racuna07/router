//
// Created by racuna07 on 01/09/17.
//
#ifndef SOCKET_H
#define SOCKET_H


#include <netdb.h>

class Socket {

private:
    int socketDescriptor;
    int socketType;
    bool ipv6;
public:
    Socket();
    Socket(char t, bool ipv6);
    Socket(int socketDescriptor,int socketType,bool ipv6);
    ~Socket();
    //Metodos de Servidor.
    int Listen(int queue);
    int Bind(int port);
    Socket* Accept();
    //Metodos Cliente.
    int Connect(char* host, int port);
    //Metodos Compartidos
    int Read(char* text, int len);
    int Write(char* text, int len);
    int Shutdown(int);
    int Close();

};


#endif //SOCKET_H
