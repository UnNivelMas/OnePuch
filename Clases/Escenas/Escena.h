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
#include "../Managers/Fondo.h"
#include "../Managers/AudioManager.h"
class Director;
class Escena {
public:
    Escena();
    Escena(Director*);
    Escena(const Escena& orig);
    virtual ~Escena();
    void setDirector(Director*);
    void draw();
protected:
    Director* _dir;
    Fondo* _fondo;
    AudioManager* _audio;
};

#endif /* ESCENA_H */

