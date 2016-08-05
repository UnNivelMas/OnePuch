/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: betoio
 * 
 * Created on 25 de julio de 2016, 08:13
 */

#include "Personaje.h"

Personaje::Personaje() {
}
Personaje::Personaje(const Personaje& orig) {
}
Personaje::~Personaje() {
}
void Personaje::draw(SDL_Renderer* renderer){}
void Personaje::atacar(Personaje* _enemy){
    this->state = 'a';
    this->animarAtaque();
    _enemy->recibirAtaque(this);
}
void Personaje::bloquear(Personaje* _enemy){
    this->state = 'b';
    this->animarBloqueo();
    _enemy->recibirBloqueo(this);
}
void Personaje::parry(Personaje* _enemy){
    this->state = 'p';
    this->animarParry();
    _enemy->recibirParry(this);
}
void Personaje::recibirEvento(){
}
void Personaje::animarAtaque(){
    this->_anim_actual = this->_golpear;
    this->_anim_actual->resetCounter();
}
void Personaje::animarBloqueo(){
    this->_anim_actual = this->_bloquear;
    this->_anim_actual->resetCounter();
}
void Personaje::animarMorir(){
    this->_anim_actual = this->_morir;
    this->_anim_actual->resetCounter();
}
void Personaje::animarParry(){
    this->_anim_actual = this->_caminar;
    this->_anim_actual->resetCounter();
}
void Personaje::recibirAtaque(Personaje* _enemy){
    if(this->state == 'b'){
        this->animarBloqueo();
    }else if(this->state == 'p'){
        this->animarParry();
    }else if(this->state == 'a' || this->state == 'i'){
        this->animarMorir();
    }
}
void Personaje::recibirBloqueo(Personaje* _enemy){
}
void Personaje::recibirParry(Personaje* _enemy){
}