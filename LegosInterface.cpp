//
// Created by rodrigo on 27/10/17.
//

#include "Router.h"
#include "LegosInterface.h"

void LegosInterface::run(){
    cout<<"legos: "<<routerUtils->i<<"."<<endl;

    if(routerUtils->i==1000){routerUtils->setRouterOff();}
}



LegosInterface::LegosInterface(Router *routerUtils) {
    this->routerUtils = routerUtils;

}
