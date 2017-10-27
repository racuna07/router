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
    router->run();
    return 0;
}
