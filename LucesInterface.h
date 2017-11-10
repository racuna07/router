//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_LUCESTHREAD_H
#define ROUTER_LUCESTHREAD_H
#include <iostream>
using namespace std;


class LucesInterface:public RouterInterface {

private:
    Router* routerUtils;

public:
    LucesInterface(char* id, Router * routerUtils) {
        this->routerUtils = routerUtils;
    }

    void run(){
        cout<<"luces: "<<routerUtils->i++<<"."<<endl;
        if(routerUtils->i==1000){
            routerUtils->setRouterOff();
        }
    }
    char * getId(){return nullptr;}
    list<MensajeRed>* getInterfaceQueue(){ return nullptr;}


};
#endif //ROUTER_LUCESTHREAD_H
