//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_ROUTERUTILS_H
#define ROUTER_ROUTERUTILS_H
#include "RoutingTable.h"
#include "MensajeFisico.h"
#include <iostream>
#include <list>
#include <mutex>

using namespace std;

class Router {
private:
    RoutingTable* routingTable;
    //actualmente asume 2 interfaces, se puede cambiar por mapa
    list<MensajeFisico> legosQueue;
    list<MensajeFisico> lucesQueue;
    bool isRouterOn;

public:
    Router();
    RoutingTable* getRoutingTable();
    list<MensajeFisico> getLegosQueue();
    list<MensajeFisico> getLucesQueue();
    bool routerOn();
    void setRouterOff();


    int i;
};


#endif //ROUTER_ROUTERUTILS_H
