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

#include "Escena.h"
#include "../Director/Director.h"
Escena::Escena() {}
Escena::Escena(Director* dir){
    this->_dir = dir;
}
Escena::Escena(const Escena& orig) {}
Escena::~Escena() {}
void Escena::setDirector(Director* dir){
    this->_dir = dir;
}
void Escena::draw(SDL_Renderer* renderer){}
void Escena::update(double ticks){}
void Escena::onKeyDown(SDL_Event* event){}
void Escena::onKeyUp(SDL_Event* event){}
void Escena::onMouseButtonDown(SDL_Event* event){}
void Escena::reset(){}
int Escena::getProperty(const char* key){
    return this->_dir->getProperty(key);
}
