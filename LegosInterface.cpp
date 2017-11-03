//
// Created by rodrigo on 27/10/17.
//

#include "Router.h"
#include "LegosInterface.h"

void LegosInterface::run(){
    cout<<"legos: "<<routerUtils->i<<"."<<endl;

    if(routerUtils->i==1000){routerUtils->setRouterOff();}
}



LegosInterface::LegosInterface(char* id,Router *routerUtils) {
    this->routerUtils = routerUtils;
    this->id = id;

}

char *LegosInterface::getId() {
    return id;
}

list<MensajeRed>* LegosInterface::getInterfaceQueue() {
    return &messageQueue;
}
