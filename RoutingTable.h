//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_ROUTINGTABLE_H
#define ROUTER_ROUTINGTABLE_H
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

struct TableEntry{
    char* network;
    unsigned int distance;
    char* interface;
};
//Obtenido de stackoverflow
struct cmp_str {
    bool operator()(char const *a, char const *b)
    {
        return strcmp(a, b) < 0;
    }
};

class RoutingTable{
private:
    bool isTableSet;
    map<char*,TableEntry*,cmp_str> table;
public:
    RoutingTable();
    TableEntry* getTableEntry(char*ip);
    void putTableEntry(TableEntry*);
    virtual void setRoutingTable();

};


#endif //ROUTER_ROUTINGTABLE_H
