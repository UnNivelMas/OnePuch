/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Demonio.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:14
 */

#ifndef DEMONIO_H
#define DEMONIO_H
#include "Personaje.h"
class Demonio  : public Personaje {
public:
    Demonio();
    Demonio(const Demonio& orig);
    virtual ~Demonio();
private:

};

#endif /* DEMONIO_H */

