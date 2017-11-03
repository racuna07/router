//
// Created by rodrigo on 24/10/17.
//
#ifndef ROUTER_LEGOSTHREAD_H
#define ROUTER_LEGOSTHREAD_H
#include <iostream>
#include "Router.h"
#include "RouterInterface.h"

using namespace std;


class LegosInterface : public RouterInterface {
private:
    Router* routerUtils;
    char *id;
    list<MensajeRed> messageQueue;

public:
    LegosInterface(char* id,Router* routerUtils);
    void run();
    char* getId();
    list<MensajeRed>* getInterfaceQueue();
};
#endif //ROUTER_LEGOSTHREAD_H
