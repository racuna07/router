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
    struct PhysicalLayerMessage* message = listenerThread->getMessage();
    if(message){
        cout<<"Tipo: "<<message->messageType<<endl;
        cout<<"MacFuente: "<<message->macFuente<<endl;
        cout<<"MacDestino: "<<message->macDestino<<endl;
        cout<<"TableEntry logicalIp: "<<((DispatcherTableEntry*)message->payload)->logicalIp<<endl;
        cout<<"TableEntry realIp: "<<((DispatcherTableEntry*)message->payload)->realIp<<endl;
        cout<<"TableEntry port: "<<((DispatcherTableEntry*)message->payload)->port<<endl;
    }
    //char* string1 = legosUtils->getDispatcherRequestMessage(logicalIp,interfaceId);
    //writeMessage(DISPATCHER_IP,DISPATCHER_PORT,string1);

}



LegosInterface::LegosInterface(Router *routerUtils, char *logicalIp,char *id, char *realIp, int realPort) {
    this->routerUtils = routerUtils;
    this->legosUtils = new LegosUtils();
    this->interfaceId = id;
    //LogicalAddress
    strncpy(this->logicalIp,logicalIp,IP_SIZE);
    //OwnAddress
    strncpy(ownRealIp,realIp,IP_SIZE);
    this-> ownRealPort = realPort;
    //Create Listener.
    this->listenerThread = new ListenerThread((char*)this->ownRealIp,this->ownRealPort);
    thread listener(&ListenerThread::run,listenerThread);
    //Keep listening to messages
    listener.detach();
    //Register with Dispatcher.
    this->dispatcherRegistry();
}

char *LegosInterface::getId() {
    return interfaceId;
}

list<MensajeRed>* LegosInterface::getInterfaceQueue() {
    //TODO limitar tamano
    return &messageQueue;
}


void LegosInterface::dispatcherRegistry() {
    char* message = legosUtils->getDispatcherRegistryMessage(logicalIp,interfaceId,ownRealIp,ownRealPort);
    writeMessage(DISPATCHER_IP,DISPATCHER_PORT,message);
}

void LegosInterface::writeMessage(char* ip,int port, char * message) {
    Socket s('s',false);
    int connectionResult = s.Connect( ip, port );
    if(connectionResult==0) {
        s.Write(message, PHYSICAL_NETWORK_MSIZE);
    }
    else{
        cout<<"Error al enviar el mensaje."<<endl;
    }
}



