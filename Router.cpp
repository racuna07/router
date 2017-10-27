//
// Created by rodrigo on 24/10/17.
//

#include "Router.h"

Router::Router() {
    this->isRouterOn = true;
}

RoutingTable *Router::getRoutingTable() {
    return this->routingTable;
}

list<MensajeFisico> Router::getLegosQueue() {
    return this->legosQueue;

}

list<MensajeFisico> Router::getLucesQueue() {
    return this->lucesQueue;
}

bool Router::routerOn() {
    return isRouterOn;
}

void Router::setRouterOff() {
    this->isRouterOn = false;
}

