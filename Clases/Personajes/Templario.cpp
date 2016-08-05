/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Templario.cpp
 * Author: betoio
 * 
 * Created on 25 de julio de 2016, 08:14
 */
#include "Templario.h"

Templario::Templario(SDL_Renderer* renderer) {
    this->_position = new SDL_Rect();
    this->_position->x = 175;
    this->_position->y = 250;
    this->_position->w = 480;
    this->_position->h = 384;
    this->_caminar = new Animacion("../Resources/Images/Animations/Templario/Caminata/", 8, this->_position, renderer);
    this->_bloquear = new Animacion("../Resources/Images/Animations/Templario/Bloqueo/", 1, this->_position, renderer);
    this->_morir = new Animacion("../Resources/Images/Animations/Templario/Muerte/", 6, this->_position, renderer);
    this->_golpear = new Animacion("../Resources/Images/Animations/Templario/Golpe/", 24, this->_position, renderer);
    this->_defensa_rota = new Animacion("../Resources/Images/Animations/Templario/DefensaRota/", 15, this->_position, renderer);
    this->_idle = new Animacion("../Resources/Images/Animations/Templario/Idle/", 1, this->_position, renderer);
    this->_anim_actual = this->_idle;
}

Templario::Templario(const Templario& orig) {
}

Templario::~Templario() {
}

void Templario::draw(SDL_Renderer* renderer) {
    this->_anim_actual->draw(renderer);
}