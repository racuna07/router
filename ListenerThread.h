//
// Created by rodrigo on 10/11/17.
//

#ifndef ROUTER_LISTENERTHREAD_H
#define ROUTER_LISTENERTHREAD_H
#include <iostream>
#include <list>
#include <mutex>

using namespace std;

#include "LegosUtils.h"
/**
 * This classs simulates a physical layer message listener.
 *
 */
class ListenerThread {
public:
    ListenerThread(char*,int);
    void run();
    PhysicalLayerMessage* getMessage();

private:
    LegosUtils * legosUtils;
    //Mutex for messageQueue
    mutex messageQueueMutex;

    list<PhysicalLayerMessage* > messageQueue;
    char* ip;
    int port;
    void processMessage(char *buffer);

};


#endif //ROUTER_LISTENERTHREAD_H
