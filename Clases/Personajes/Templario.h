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
class Templario : public Personaje {
public:
    Templario(SDL_Renderer*);
    Templario(const Templario& orig);
    void draw(SDL_Renderer*);
    virtual ~Templario();
private:

};

#endif /* TEMPLARIO_H */

