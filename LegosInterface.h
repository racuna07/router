//
// Created by rodrigo on 24/10/17.
//
#ifndef ROUTER_LEGOSTHREAD_H
#define ROUTER_LEGOSTHREAD_H
#include <iostream>
#include "Router.h"
#include "RouterInterface.h"
#include "RoutingTable.h"
#include "ListenerThread.h"

using namespace std;





class LegosInterface : public RouterInterface {
public:
    LegosInterface(char* id,Router* routerUtils);
    void run();
    char* getId();
    list<MensajeRed>* getInterfaceQueue();
    char* getIpAsString(char ip[]);
    char* getStringAsIp(char*);

    struct DispatcherMessage{
        char messageType;
        char macAddress[7];
        char* realIp;
        int realPort;
    };
    struct arpEntry{
        char ipMentira[4];
        char macAddress[7];
        char* ipAddress;
        char* realIp;
        int realPort;
    };
private:
    Router* routerUtils;
    char * interfaceId;
    const char * logicalIp;
    list<MensajeRed> messageQueue;
    //Interface registers with dispatcher so that other nodes know its physical layer address.
    const char* dispatcherAddressIp;
    int dispatcherAddressPort;
    void dispatcherRegistry();

    //Address of the socket that listens for messages for this interface
    const char* ownRealIp;
    int ownRealPort;

    //Address Resolution Protocol Cache Table
    map<char*,arpEntry,cmp_str> arpTable;

    void writeMessage(char*,int,char*);

    //Listener Thread
    ListenerThread* listenerThread;


};
#endif //ROUTER_LEGOSTHREAD_H
