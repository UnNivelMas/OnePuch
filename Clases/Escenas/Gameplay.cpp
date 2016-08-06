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
    this->_fondo->loadImage("Resources/Images/Backgrounds/Gameplay/fondo.png", dir->getRenderer());
    this->_fondo->setPosition(pos);
    
    this->_medio = new Fondo();
    this->_medio->loadImage("Resources/Images/Backgrounds/Gameplay/medio.png", dir->getRenderer());
    this->_medio->setPosition(pos);
    
    this->_frente = new Fondo();
    this->_frente->loadImage("Resources/Images/Backgrounds/Gameplay/frente.png", dir->getRenderer());
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
void Gameplay::onKeyDown(SDL_Event* event){
//    SDL_Log("Gameplay::onKeyDown");
    switch (event->key.keysym.sym) {
        case SDLK_j: //Player 1 - Ataque
            SDL_Log("Gameplay::onKeyDown -> Templario::atacar");
            this->_templario->atacar(this->_demonio);
            break;
        case SDLK_k: //Player 1 - Bloqueo
            SDL_Log("Gameplay::onKeyDown -> Templario::bloquear");
            this->_templario->bloquear(this->_demonio);
            break;
        case SDLK_l: //Player 1 - Parry
            SDL_Log("Gameplay::onKeyDown -> Templario::parry");
            this->_templario->parry(this->_demonio);
            break;
        case SDLK_w: //Player 1 - Arriba
            SDL_Log("Gameplay::onKeyDown -> Templario::arriba");
            break;
        case SDLK_s: //Player 1 - Abajo
            SDL_Log("Gameplay::onKeyDown -> Templario::abajo");
            break;
        case SDLK_d: //Player 1 - Derecha
            SDL_Log("Gameplay::onKeyDown -> Templario::derecha");
            break;
        case SDLK_a: //Player 1 - Izquierda
            SDL_Log("Gameplay::onKeyDown -> Templario::izquierda");
            break;
        case SDLK_KP_4: //Player 2 - Ataque
            SDL_Log("Gameplay::onKeyDown -> Demonio::atacar");
            this->_demonio->atacar(this->_templario);
            break;
        case SDLK_KP_5: //Player 2 - Bloqueo
            SDL_Log("Gameplay::onKeyDown -> Demonio::bloquear");
            this->_demonio->bloquear(this->_templario);
            break;
        case SDLK_KP_6: //Player 2 - Parry
            SDL_Log("Gameplay::onKeyDown -> Demonio::parry");
            this->_demonio->parry(this->_templario);
            break;
        case SDLK_UP: //Player 1 - Arriba
            SDL_Log("Gameplay::onKeyDown -> Demonio::arriba");
            break;
        case SDLK_DOWN: //Player 1 - Abajo
            SDL_Log("Gameplay::onKeyDown -> Demonio::abajo");
            break;
        case SDLK_RIGHT: //Player 1 - Derecha
            SDL_Log("Gameplay::onKeyDown -> Demonio::derecha");
            break;
        case SDLK_LEFT: //Player 1 - Izquierda
            SDL_Log("Gameplay::onKeyDown -> Demonio::izquierda");
            break;
        default:break;
    }
}
void Gameplay::onKeyUp(SDL_Event* event){
//    SDL_Log("Gameplay::onKeyUp");
    switch (event->key.keysym.sym) {
        case SDLK_j: //Player 1 - Ataque
            break;
        case SDLK_k: //Player 1 - Bloqueo
            break;
        case SDLK_l: //Player 1 - Parry
            break;
        case SDLK_w: //Player 1 - Arriba
            break;
        case SDLK_s: //Player 1 - Abajo
            break;
        case SDLK_d: //Player 1 - Derecha
            break;
        case SDLK_a: //Player 1 - Izquierda
            break;
        case SDLK_KP_4: //Player 2 - Ataque
            break;
        case SDLK_KP_5: //Player 2 - Bloqueo
            break;
        case SDLK_KP_6: //Player 2 - Parry
            break;
        case SDLK_UP: //Player 1 - Arriba
            break;
        case SDLK_DOWN: //Player 1 - Abajo
            break;
        case SDLK_RIGHT: //Player 1 - Derecha
            break;
        case SDLK_LEFT: //Player 1 - Izquierda
            break;
        default:break;
    }
}
void Gameplay::onMouseButtonDown(SDL_Event* event){
    SDL_Log("Gameplay::onMouseButtonDown");
//    SDL_Log(event->key);
    /*switch (event.type) {
        case SDL_KEYDOWN: 
            SDL_Log("SDL_KEYDOWN\n");
            this->_dir->onKeyDown(event);
            break;
        case SDL_KEYUP: 
            SDL_Log("SDL_KEYUP\n");
            this->_dir->onKeyUp(event);
            break;
        case SDL_MOUSEBUTTONDOWN: 
            this->_dir->onMouseButtonDown(event);
            break;
        case SDL_QUIT:
            SDL_Log("SDL_KEYUP\n");
            this->_dir->onQuit();
        break;
        default:break;
    }*/
}