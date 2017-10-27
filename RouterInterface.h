//
// Created by rodrigo on 27/10/17.
//

#ifndef ROUTER_ROUTERINTERFACE_H
#define ROUTER_ROUTERINTERFACE_H

#include <list>

/**
 * RouterInterface defines method that a class should implement to work as a network interface for the router.
 * It was developed as an interface instead of an abstract class because other groups from the course are in
 * charge of different physical layer "networks" which they implement as they wish.
 */
class RouterInterface{
public:
    virtual void run() = 0;
    virtual char* getId() = 0;
    virtual list<MensajeFisico>* getInterfaceQueue() = 0;
};
#endif //ROUTER_ROUTERINTERFACE_H
