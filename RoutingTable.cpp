//
// Created by rodrigo on 24/10/17.
//


#include <cassert>
#include "RoutingTable.h"

RoutingTable::RoutingTable() {
    this->setRoutingTable();
}

TableEntry* RoutingTable::getTableEntry(char *ip) {
    assert(this->isTableSet) ;
    return table[ip];
}


/**
 * Initital hardwired ip-table.
 */
void RoutingTable::setRoutingTable() {
    this->isTableSet = true;
    char* red0 = new char[4]{(char)12,(char)0,(char)0,(char)0};
    char* red1 = new char[4]{(char)165,(char)8,(char)0,(char)0};
    char* red2 = new char[4]{(char)200,(char)5,(char)0,(char)0};
    char* red3 = new char[4]{(char)140,(char)90,(char)0,(char)0};
    char* red4 = new char[4]{(char)25,(char)0,(char)0,(char)0};
    char* red5 = new char[4]{(char)201,(char)6,(char)0,(char)0};

    TableEntry* entries = new TableEntry[6];
    entries[0].network = red0; entries[0].distance = 2; entries[0].interface = "luces";
    entries[1].network = red1; entries[1].distance = 1; entries[1].interface = "luces";
    entries[2].network = red2; entries[2].distance = 2; entries[2].interface = "legos";
    entries[3].network = red3; entries[3].distance = 1; entries[3].interface = "legos";
    entries[4].network = red4; entries[4].distance = 0; entries[4].interface = "luces";
    entries[5].network = red5; entries[5].distance = 0; entries[5].interface = "legos";

    this->table["12.0.0.0"] = &entries[0];
    this->table["165.8.0.0"] = &entries[1];
    this->table["200.5.0.0"] = &entries[2];
    this->table["140.90.0.0"] = &entries[3];
    this->table["25.0.0.0"] = &entries[4];
    this->table["201.6.0.0"] = &entries[5];



}

void RoutingTable::putTableEntry(TableEntry* tableEntry) {
    this->table[tableEntry->network] = tableEntry;
}


