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
#include "Definitions.h"

using namespace std;





class LegosInterface : public RouterInterface {
public:
    LegosInterface(Router *routerUtils, char *logicalIp,char *id, char *realIp, int realPort);
    void run();
    char* getId();
    list<MensajeRed>* getInterfaceQueue();


private:
    Router* routerUtils;
    LegosUtils* legosUtils;
    char * interfaceId;
    char  logicalIp[IP_SIZE];
    list<MensajeRed> messageQueue;
    //Address of the socket that listens for messages for this interface
    char ownRealIp[IP_SIZE];
    int ownRealPort;
    //Interface registers with dispatcher so that other nodes know its physical layer address.
    void dispatcherRegistry();
    //Listener Thread
    ListenerThread* listenerThread;

    //Address Resolution Protocol Cache Table
    //map<char*,arpEntry,cmp_str> arpTable;

    void writeMessage(char*,int,char*);




};
#endif //ROUTER_LEGOSTHREAD_H
