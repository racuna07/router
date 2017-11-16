//
// Created by rodrigo and david on 10/11/17.
//

#ifndef UNTITLED_LEGOSUTILS_H
#define UNTITLED_LEGOSUTILS_H
#define DISPATCHER_IP "127.0.0.1"
#define DISPATCHER_PORT 8085
#define PHYSICAL_NETWORK_MSIZE 1560
#define MAX_QUEUE_SIZE 100

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
    LegosUtils();
    char* getStringAsIp(char*);
    char* getIpAsString(char*);
    PhysicalLayerMessage* unpackPhysicalMessage(char*);
    NetworkMessage *unpackNetworkMessage(char *);
    char* getDispatcherRegistryMessage(char *logicalIp, char *macAddress, char *realIP, int realPort);

    char *getDispatcherRequestMessage(char *logicalIp, char *macAddress);
};


#endif //UNTITLED_LEGOSUTILS_H
