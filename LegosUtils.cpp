//
// Created by rodrigo and david on 10/11/17.
//

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "LegosUtils.h"

char *LegosUtils::getStringAsIp(char *string) {
    char* result = new char[4];
    char* first = strtok(string,"."); result[0]= (char)atoi(first);
    char* second = strtok(NULL,"."); result[1]= (char)atoi(second);
    char* third = strtok(NULL,"."); result[2]= (char)atoi(third);
    char* forth = strtok(NULL,"."); result[3]= (char)atoi(forth);
    return result;
}

char *LegosUtils::getIpAsString(char *ip) {
    char* buffer = new char[8];
    sprintf(buffer,"%i.%i.%i.%i",ip[0],ip[1],ip[2],ip[3]);
    return buffer;
}


//Almacena un mensaje de red en
PhysicalLayerMessage *LegosUtils::unpackPhysicalMessage(char * buffer) {
    int i = 1;
    struct PhysicalLayerMessage message;
    char* ptr;
    ptr = strtok(buffer,";");//Divido el paquete en secciones
    message.messageType = atoi(ptr);
    while(ptr != NULL)
    {
        ptr = strtok(NULL, ";");
        switch (i){
            case 1:
                message.macFuente = ptr;
                break;
            case 2:
                message.macDestino = ptr;
                break;
            case 3:
                if(message.messageType==3 || message.messageType == 4){
                    message.payload = unpackNetworkMessage(ptr);
                }
                else{
                    struct DispatcherTableEntry tableEntry;
                    tableEntry.logicalIp = ptr;
                    tableEntry.macAddress = strtok(NULL, ";");
                    tableEntry.realIp = strtok(NULL,";");
                    tableEntry.port = atoi(strtok(NULL,";"));
                    message.payload = &tableEntry;
                }
                break;
            default:
                break;
        }
        i++;
    }
    return &message;
}

NetworkMessage *LegosUtils::unpackNetworkMessage(char *string) {
    NetworkMessage networkMessage;
    networkMessage.sourceIp[0]=string[0];networkMessage.sourceIp[1]=string[1];networkMessage.sourceIp[2]=string[2];networkMessage.sourceIp[3]=string[3];
    networkMessage.destinyIp[0]=string[4];networkMessage.destinyIp[1]=string[5];networkMessage.destinyIp[2]=string[6];networkMessage.destinyIp[3]=string[7];
    networkMessage.action = string[8];
    networkMessage.actionIp[0]=string[9];networkMessage.actionIp[1]=string[10];networkMessage.actionIp[2]=string[11];networkMessage.actionIp[3]=string[12];
    networkMessage.message = "";
    //strncat(networkMessage.message,string[13],15000);
    return nullptr;
}


