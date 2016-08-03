/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escena.cpp
 * Author: betoio
 * 
 * Created on 25 de julio de 2016, 08:13
 */

#include "Gameplay.h"
#include "../Director/Director.h"

Gameplay::Gameplay() {}
Gameplay::Gameplay(Director* dir)  :  Escena( dir) {
    this->_fondo = new Fondo();
    this->_fondo->loadImage("../Resources/Images/Backgrounds/Gameplay/fondo.png", 
                            dir->getRenderer(),
                            dir->getSurfaceWindow()
                           );
}
Gameplay::Gameplay(const Gameplay& orig) {}
Gameplay::~Gameplay() {}
void Escena::draw(){
    
}