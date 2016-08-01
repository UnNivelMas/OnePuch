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
void Personaje::atacar(Personaje _enemy){
    this->state = 'a';
    this->animarAtaque();
    _enemy.recibirAtaque(this);
}
void Personaje::bloquear(Personaje _enemy){
    this->state = 'b';
    this->animarBloqueo();
    _enemy.recibirBloqueo(this);
}
void Personaje::parry(Personaje _enemy){
    this->state = 'p';
    this->animarParry();
    _enemy.recibirParry(this);
}
void Personaje::recibirEvento(){
}
void Personaje::animarAtaque(){
}
void Personaje::animarBloqueo(){
}
void Personaje::animarMorir(){
}
void Personaje::animarParry(){
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