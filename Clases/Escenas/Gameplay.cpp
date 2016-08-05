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
    SDL_Rect* pos = new SDL_Rect();
    pos->x = 4480 / -1.8; pos->y = 0;
    pos->w = 4480; pos->h = 720;
    SDL_Log( "Gameplay::Gameplay(Director*)\n");
    
    this->_fondo = new Fondo();
    this->_fondo->loadImage("../Resources/Images/Backgrounds/Gameplay/fondo.png", dir->getRenderer());
    this->_fondo->setPosition(pos);
    
    this->_medio = new Fondo();
    this->_medio->loadImage("../Resources/Images/Backgrounds/Gameplay/medio.png", dir->getRenderer());
    this->_medio->setPosition(pos);
    
    this->_frente = new Fondo();
    this->_frente->loadImage("../Resources/Images/Backgrounds/Gameplay/frente.png", dir->getRenderer());
    this->_frente->setPosition(pos);
    
    this->_demonio = new Demonio(dir->getRenderer());
    this->_templario = new Templario(dir->getRenderer());
}
Gameplay::Gameplay(const Gameplay& orig) {}
Gameplay::~Gameplay(){}
void Gameplay::update(){
    
}
void Gameplay::draw(SDL_Renderer* render){
    this->_fondo->draw(render);
    
    this->_demonio->draw(render);
    this->_templario->draw(render);
    
    this->_medio->draw(render);
    this->_frente->draw(render);
}