//
// Created by rodrigo on 24/10/17.
//

#ifndef ROUTER_MENSAJEFISICO_H
#define ROUTER_MENSAJEFISICO_H


#include "MensajeRed.h"

class MensajeFisico {
private:
    char* direccionFuente;
    char* direccionDestino;
    MensajeRed* mensajeRed;
    bool broadcast;
public:
    MensajeFisico(char[],char[], bool);
    void setBroadcast(bool);
    void setMensajeRed(MensajeRed*);
    char* getDireccionFuente();
    char* getDireccionDestino();
    MensajeRed* getMensajeRed();




};


#endif //ROUTER_MENSAJEFISICO_H
