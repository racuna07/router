//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_LUCESTHREAD_H
#define ROUTER_LUCESTHREAD_H
#include <iostream>
using namespace std;


class LucesThread {
public:
    static void luces(Router* routerUtils){

        cout<<"luces: "<<routerUtils->i++<<"."<<endl;

    }


};
#endif //ROUTER_LUCESTHREAD_H
