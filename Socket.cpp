//
// Created by racuna07 on 01/09/17.
//

#include "Socket.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

Socket::Socket(char t, bool ipv6= false) {
    socketDescriptor = -1;
    switch (t){
        case 's'://SOCK_STREAM
            if(ipv6){
                socketDescriptor = socket(AF_INET6, SOCK_STREAM, 0);
                this->ipv6 = true;
            }
            else{
                socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
                this->ipv6 = false;
            }
            socketType = SOCK_STREAM;
            break;
        case 'd'://SOCK_DGRAM
            if(ipv6){
                socketDescriptor = socket(AF_INET6, SOCK_DGRAM, 0);
                this->ipv6 = true;
            }
            else{
                socketDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
                this->ipv6 = false;
            }
            socketType = SOCK_DGRAM;
            break;
        default:
            cout<<"Tipo de socket incorrecto."<<endl;
            cout<<"Utilice 's' para SOCK_STEAM o 'd' para SOCK_GRAM"<<endl;
    }
    if(socketDescriptor == -1){
        cout<<"Error al crear el socket."<<endl;
    }
    else{
        cout<<"Socket creado con exito."<<endl;
    }

}

Socket::~Socket() {
    if(close(socketDescriptor)==-1){
        cout<<"Error cerrando el socket, vuelva a intentarlo."<<endl;
    }
    else{
        cout<<"Socket cerrado con exito."<<endl;
    }
}



int Socket::Connect(char *host, int port) {
    struct sockaddr_in host_addr;
    if(ipv6){
        host_addr.sin_family = AF_INET6;
    }
    else{
        host_addr.sin_family = AF_INET;
    }
    inet_aton(host, &host_addr.sin_addr);
    host_addr.sin_port = htons(port);
    long len = sizeof(host_addr);
    int result = connect(socketDescriptor,(sockaddr*) & host_addr,len);
    if(result == -1){
        cout<<"No se pudo establecer la conexion."<<endl;
    }
    else{
        cout<<"Conexion exitosa."<<endl;
    }
    return result;
}

int Socket::Read(char *text, int len) {
    int result;
    if((read(socketDescriptor,text,len))==0){
        Shutdown(SHUT_RD);
    }
    return result;
}

int Socket::Write(char *text, int len) {
    int result;
    if((write(socketDescriptor,text,len))==0){
        Shutdown(SHUT_WR);
    }
    return result;
}

int Socket::Shutdown(int type) {
    int result;
    if((result= shutdown(socketDescriptor,type))==-1){
        cout<<"Error de Shutdown."<<endl;
    }
    return result;
}

int Socket::Close() {
    int result = 0;
    if(close(socketDescriptor)==-1){
        cout<<"Error cerrando el socket, vuelva a intentarlo."<<endl;
        result = -1;
    }
    else{
        cout<<"Socket cerrado con exito."<<endl;
    }
    return result;
}

Socket::Socket() : Socket('s',false) {}

Socket *Socket::Accept() {
    Socket* newSocket = nullptr;
    if(socketType == SOCK_STREAM){
        struct sockaddr_storage inAddress;
        socklen_t len = sizeof(inAddress);
        int newSocketDescriptor;
        if((newSocketDescriptor = accept(socketDescriptor,(struct sockaddr *)&inAddress,&len)) ==-1){
            cout<<"Error al aceptar conexion."<<endl;
        }
        else{
            newSocket = new Socket(newSocketDescriptor,socketType,ipv6);
            cout<<"Conexion aceptada exitosamente."<<endl;
        }
    }
    else{
        cout<<"Este tipo de socket no es compatible con el metodo Accept"<<endl;
        cout<<"Utilizar socket tipo SOCK_STREAM."<<endl;
    }
    return newSocket;
}

int Socket::Listen(int queue) {
    int result = -1;
    if(socketType==SOCK_STREAM){
        if((result = listen(socketDescriptor,queue))==0){
            cout<<"Listening.."<<endl;
        }
        else{
            cout<<"Error al ejecutar listen"<<endl;
        }
    }
    else{
        cout<<"Este tipo de socket no es compatible con el metodo Listen"<<endl;
        cout<<"Utilizar socket tipo SOCK_STREAM."<<endl;
    }
    return result;
}

int Socket::Bind(int port) {
    int result = -1;
    if(socketType==SOCK_STREAM){
        struct sockaddr_in server_addr;
        if(ipv6){
            server_addr.sin_family = AF_INET6;
        }
        else{
            server_addr.sin_family = AF_INET;
        }
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(port);
        socklen_t len = sizeof(server_addr);
        if((result = bind(socketDescriptor,(const sockaddr*)&server_addr,len))==0){
            cout<<"Se ejecuto bind() con exito en el puerto "<<port<<"."<<endl;
        }
        else{
            cout<<"Error al ejecutar bind() en el puerto "<<port<<"."<<endl;
        }
    }
    else{
        cout<<"Este tipo de socket no es compatible con el metodo Bind"<<endl;
        cout<<"Utilizar socket tipo SOCK_STREAM."<<endl;
    }
    return result;
}

Socket::Socket(int socketDescriptor, int socketType, bool ipv6) {
    this->socketDescriptor = socketDescriptor;
    this->socketType = socketType;
    this->ipv6 = ipv6;
}
