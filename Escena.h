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

#ifndef ESCENA_H
#define ESCENA_H
#include "Fondo.h"
#include "Demonio.h"
#include "AudioManager.h"
#include "Templario.h"
class Escena {
public:
    Escena();
    Escena(const Escena& orig);
    virtual ~Escena();
private:
    Fondo fondo;
    Demonio demonio;
    Templario templario;
    AudioManager audio;
};

#endif /* ESCENA_H */

