//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_ROUTINGTABLE_H
#define ROUTER_ROUTINGTABLE_H
#include <iostream>
#include <map>

using namespace std;

struct TableEntry{
    char* network;
    unsigned int distance;
    char* interface;
};

class RoutingTable{
private:
    bool isTableSet;
    map<char*,TableEntry*> table;
public:
    RoutingTable();
    TableEntry* getTableEntry(char*ip);
    void putTableEntry(TableEntry*);
    virtual void setRoutingTable();

};


#endif //ROUTER_ROUTINGTABLE_H
