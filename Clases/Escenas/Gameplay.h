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
class Director;
class Gameplay : public Escena {
public:
    Gameplay();
    Gameplay(Director*);
    Gameplay(const Gameplay& orig);
    void draw(SDL_Renderer*);
    virtual ~Gameplay();
private:
    Fondo* _medio;
    Fondo* _fondo;
    Fondo* _frente;
    Demonio* _demonio;
    Templario* _templario;
};

#endif /* GAMEPLAY_H */

