//
// Created by rodrigo on 24/10/17.
//

#include "MensajeRed.h"




MensajeRed::MensajeRed(char *ipFuente, char *ipDestino, int accion,char* accionIp) {
    this->ipFuente = ipFuente;
    this->ipDestino = ipDestino;
    this->accion = accion;
    this->ipAccion = ipAccion;

}

void MensajeRed::setMensaje(char *mensaje, int lenght) {
    for (int i = 0; i < lenght; ++i) {
        this->mensaje[i] = mensaje[i];
    }
}

char *MensajeRed::getIpFuente() {
    return ipFuente;
}

char *MensajeRed::getIpDestino() {
    return ipDestino;
}

char *MensajeRed::getMensaje() {
    return mensaje;
}

char *MensajeRed::getIpAccion() {
    return ipAccion;
}

int MensajeRed::getAcccion() {
    return accion;
}
