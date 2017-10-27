//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_MENSAJERED_H
#define ROUTER_MENSAJERED_H


class MensajeRed {
private:
    char* ipFuente;
    char* ipDestino;
    int accion;
    char* ipAccion;
    char mensaje[1500];

public:
    MensajeRed(char*ipFuente,char*ipDestino,int accion, char* ipAccion);
    void setMensaje(char* mensaje,int length);
    char *getIpFuente();
    char *getIpDestino();
    char *getIpAccion();
    char *getMensaje();
    int getAcccion();



};


#endif //ROUTER_MENSAJERED_H
