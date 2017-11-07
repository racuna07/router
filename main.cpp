#include <iostream>
#include <thread>
#include <mutex>

#include "LegosInterface.h"
#include "LucesInterface.h"
#include "Router.h"
using namespace std;



int main(){
    std::cout << "Hello, World!" << std::endl;
    Router* router = new Router();
    RoutingTable* routingTable = router->getRoutingTable();
    TableEntry* tableEntry = routingTable->getTableEntry("12.0.0.0");
    for (int i = 0; i < 4; ++i) {
        cout<<(int)tableEntry->network[i]<<" ";
    }

    cout<<"\n"<<tableEntry->distance<<endl;
    cout<<tableEntry->interface<<endl;


    //router->run();
    return 0;
}
