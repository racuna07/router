#include <iostream>
#include <thread>
#include <mutex>

#include "LegosInterface.h"
#include "LucesThread.h"
#include "Router.h"
using namespace std;

static int i = 0;
static mutex iMutex;
static mutex routerUtilsMutex;
static Router* router = new Router();

int main(){
    std::cout << "Hello, World!" << std::endl;
    LegosInterface* legosInterface = new LegosInterface(router);

    while(router->routerOn()){
        thread thread1(&LegosInterface::run,legosInterface);
        thread1.join();
        thread thread2(LucesThread::luces,router);
        thread2.join();
    }



    return 0;
}
