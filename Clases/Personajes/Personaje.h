/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:13
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "../Managers/Animacion.h"

class Personaje {
public:
    Personaje();
    Personaje(const Personaje& orig);
    void atacar(Personaje);
    void bloquear(Personaje);
    void parry(Personaje);
    void recibirAtaque(Personaje*);
    void recibirBloqueo(Personaje*);
    void recibirParry(Personaje*);
    void animarAtaque();
    void animarBloqueo();
    void animarMorir();
    void animarParry();
    void recibirEvento();
    virtual ~Personaje();
private:
    Animacion animacionGolpear;
    Animacion animacionBloquear;
    Animacion animacionMorir;
    char state;/*i=idle; a=atacando; b=bloqueando; p=parryando(?)*/
};

#endif /* PERSONAJE_H */

