/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Templario.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:14
 */

#ifndef TEMPLARIO_H
#define TEMPLARIO_H
#include "Personaje.h"
class Escena;
class Templario : public Personaje {
public:
    Templario(Escena*, SDL_Renderer*);
    Templario(const Templario& orig);
    int getProperty(const char*);
    void draw(SDL_Renderer*);
    virtual ~Templario();
private:

};

#endif /* TEMPLARIO_H */

