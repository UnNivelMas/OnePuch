/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escena.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:13
 */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Escena.h"
#include "../Personajes/Demonio.h"
#include "../Personajes/Templario.h"

class Gameplay : public Escena {
public:
    Gameplay();
    Gameplay(const Gameplay& orig);
    virtual ~Gameplay();
private:
    Fondo fondo;
    Demonio demonio;
    Templario templario;
};

#endif /* GAMEPLAY_H */

