//
// Created by rodrigo on 27/10/17.
//

#include <sstream>
#include <unistd.h>
#include "Router.h"
#include "LegosInterface.h"
#include "Socket.h"
#include "string.h"
#include "Definitions.h"

void LegosInterface::run(){
    cout<<"legos: "<<routerUtils->i<<endl;
    /*//Si hay mensajes Fisicos
    PhysicalLayerMessage* physicalLayerMessage = listenerThread->getMessage();
    if(physicalLayerMessage){

    }*/


}



LegosInterface::LegosInterface(char* id,Router *routerUtils) {
    this->routerUtils = routerUtils;
    this->interfaceId = id;
    //DispatcherAddress
    this->dispatcherAddressIp = "10.1.130.70";
    this->dispatcherAddressPort = 8080;
    //OwnAddress
    this->ownRealIp = "200.200.200.200";
    this-> ownRealPort = 8080;
    //Create Listener.
    this->listenerThread = new ListenerThread((char*)this->ownRealIp,this->ownRealPort);
    thread listener(&ListenerThread::run,listenerThread);
    listener.detach();



    //Register with Dispatcher.
    this->dispatcherRegistry();

}

char *LegosInterface::getId() {
    return interfaceId;
}

list<MensajeRed>* LegosInterface::getInterfaceQueue() {
    return &messageQueue;
}

char* LegosInterface::getIpAsString(char *ip) {
    char* buffer = new char[8];
    sprintf(buffer,"%i.%i.%i.%i",ip[0],ip[1],ip[2],ip[3]);
    return buffer;
}

char *LegosInterface::getStringAsIp(char * string) {
    char* result = new char[4];
    char* first = strtok(string,".");result[0]= (char)atoi(first);
    char* second = strtok(NULL,"."); result[1]= (char)atoi(second);
    char* third = strtok(NULL,"."); result[2]= (char)atoi(third);
    char* forth = strtok(NULL,"."); result[3]= (char)atoi(forth);
    return result;
}

void LegosInterface::dispatcherRegistry() {
    writeMessage((char*)dispatcherAddressIp,dispatcherAddressPort,"0;legos3;legos0;200.5.0.25;legos1;255.255.255.255;8080;");
}

void LegosInterface::writeMessage(char* ip,int port, char * message) {
    Socket s('s',false);
    int connectionResult = s.Connect( ip, port );
    if(connectionResult==0) {
        s.Write(message, PHYSICAL_NETWORK_MSIZE);
        cout<<"mensaje enviado"<<endl;
    }
    else{
        cout<<"No se pudo enviar el mensaje"<<endl;
    }
}



