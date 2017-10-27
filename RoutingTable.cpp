//
// Created by rodrigo on 24/10/17.
//


#include <cassert>
#include "RoutingTable.h"

RoutingTable::RoutingTable() {
    this->setRoutingTable();
}

TableEntry RoutingTable::getTableEntry(char *ip) {
    assert(isTableSet) ;
    return this->table[ip];
}

void RoutingTable::setRoutingTable() {


    this->isTableSet = true;

}

void RoutingTable::putTableEntry(TableEntry tableEntry) {
    this->table[tableEntry.network] = tableEntry;
}


