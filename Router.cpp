//
// Created by rodrigo on 24/10/17.
//
#include "Router.h"
#include "LegosInterface.h"
#include "LucesInterface.h"

Router::Router() {
    this->routerOn = true;
    this->routingTable = new RoutingTable();
    this->routerInterfaces["legos3"] = new LegosInterface("legos3",this);
    this->routerInterfaces["luces"] = new LucesInterface("luces", this);
}

RoutingTable *Router::getRoutingTable() {
    return this->routingTable;
}


void Router::setRouterOff() {
    this->routerOn = false;
}

void Router::run() {
    while(routerOn){
        map<char*,RouterInterface*>::iterator it = routerInterfaces.begin();
        while (it != routerInterfaces.end()) {
            RouterInterface* interface = routerInterfaces[(it++)->first];
            thread interfaceThread(&RouterInterface::run,interface);
            interfaceThread.join();
        }
    }

}

