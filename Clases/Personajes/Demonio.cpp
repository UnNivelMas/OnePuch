/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Demonio.cpp
 * Author: betoio
 * 
 * Created on 25 de julio de 2016, 08:14
 */
#include "Personaje.h"
#include "Demonio.h"

Demonio::Demonio(Escena* escena, SDL_Renderer* renderer) : Personaje(escena, "Demonio"){
    this->_position = new SDL_Rect();
    this->_position->x = 500;
    this->_position->y = 250;
    this->_position->w = 480;
    this->_position->h = 384;
    this->_caminar = new Animacion("Resources/Images/Animations/Demonio/Caminata/", 8, this->_position, renderer);
    this->_bloquear = new Animacion("Resources/Images/Animations/Demonio/Bloqueo/", 8, this->_position, renderer);
    this->_morir = new Animacion("Resources/Images/Animations/Demonio/Muerte/", 18, this->_position, renderer);
    this->_golpear = new Animacion("Resources/Images/Animations/Demonio/Golpe/", 7, this->_position, renderer);
    this->_defensa_rota = new Animacion("Resources/Images/Animations/Demonio/DefensaRota/", 6, this->_position, renderer);
    this->_idle = new Animacion("Resources/Images/Animations/Demonio/Idle/", 1, this->_position, renderer);
    this->_anim_actual = this->_idle;
/*    
    this->_state_idle->setPersonaje(this);
    this->_state_attack->setPersonaje(this);
    this->_state_block->setPersonaje(this);
    this->_state_parry->setPersonaje(this);*/
}
Demonio::Demonio(const Demonio& orig) : Personaje(orig){}
Demonio::~Demonio() {}
void Demonio::draw(SDL_Renderer* renderer) {
    this->_anim_actual->draw(renderer);
}
int Demonio::getProperty(const char* key){
    char* aux = "Templario";
    strcat(aux, key);
    return Personaje::getProperty(aux);
}