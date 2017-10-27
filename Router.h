//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_ROUTERUTILS_H
#define ROUTER_ROUTERUTILS_H
#include "RoutingTable.h"
#include "MensajeFisico.h"
#include "RouterInterface.h"
#include <iostream>
#include <list>
#include <mutex>
#include <thread>

using namespace std;

class Router {
private:
    RoutingTable* routingTable;
    map<char*,RouterInterface*> routerInterfaces;
    bool routerOn;

public:
    Router();
    RoutingTable* getRoutingTable();
    void setRouterOff();


    int i;

    void run();
};


#endif //ROUTER_ROUTERUTILS_H
