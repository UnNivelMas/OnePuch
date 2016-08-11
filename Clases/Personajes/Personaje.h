/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:13
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SDL2/SDL.h>
#include "../Managers/Animacion.h"
#include "State.h"

class Escena;
class Personaje {
public:
    Personaje(Escena*, const char *);
    Personaje(const Personaje& orig);
    void atacar(Personaje*);
    void bloquear(Personaje*);
    void parry(Personaje*);
    void recibirAtaque(Personaje*);
    void recibirBloqueo(Personaje*);
    void recibirParry(Personaje*);
    void animarAtaque();
    void animarBloqueo();
    void animarMorir();
    void animarParry();
    void recibirEvento();
    void update(double);
    void stateToIdle();
    void stateToAttack(Personaje*);
    void stateToBlock(Personaje*);
    void stateToParry(Personaje*);
    void stateToDeath(Personaje*);
    void setAnimLoop(bool);
    char* getNombre();
    int getProperty(const char*);
    virtual ~Personaje();
    virtual void draw(SDL_Renderer*);
protected:
    Escena* _escena;
    Animacion* _golpear;
    Animacion* _caminar;
    Animacion* _bloquear;
    Animacion* _morir;
    Animacion* _defensa_rota;
    Animacion* _anim_actual;
    Animacion* _idle;
    double _ticks = 0.0;
    SDL_Rect* _position;
    State* _state;
    State* _state_idle;
    State* _state_attack;
    State* _state_block;
    State* _state_parry;
    State* _state_death;
    char _nombre[30];
};

#endif /* PERSONAJE_H */

