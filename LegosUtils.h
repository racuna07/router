//
// Created by rodrigo and david on 10/11/17.
//

#ifndef UNTITLED_LEGOSUTILS_H
#define UNTITLED_LEGOSUTILS_H

struct PhysicalLayerMessage{
    int messageType;
    char* macFuente;
    char* macDestino;
    void* payload;
};
struct DispatcherTableEntry{
    char*logicalIp;
    char* macAddress;
    char* realIp;
    int port;
};
struct NetworkMessage{
    char sourceIp[4];
    char destinyIp[4];
    char action;
    char actionIp[4];
    char* message;
};

class LegosUtils {
public:
    char* getStringAsIp(char*);
    char* getIpAsString(char*);
    PhysicalLayerMessage* unpackPhysicalMessage(char*);
    DispatcherTableEntry *unpackDispatcherTableEntry(char *buffer);
    NetworkMessage *unpackNetworkMessage(char *string);
};


#endif //UNTITLED_LEGOSUTILS_H
