//
// Created by rodrigo on 24/10/17.
//

#include "MensajeFisico.h"

MensajeFisico::MensajeFisico(char * direccionFuente, char * direccionDestino, bool broadcast) {
    this->direccionFuente = direccionFuente;
    this->direccionDestino = direccionDestino;
    this->broadcast = broadcast;

}

void MensajeFisico::setBroadcast(bool isBrodadcast) {
    this->broadcast = isBrodadcast;

}

void MensajeFisico::setMensajeRed(MensajeRed* mensaje) {
    this->mensajeRed = mensaje;
}

char *MensajeFisico::getDireccionFuente() {
    return this->direccionFuente;
}

char *MensajeFisico::getDireccionDestino() {
    return this->direccionDestino;
}

MensajeRed* MensajeFisico::getMensajeRed() {
    return this->mensajeRed;
}
