/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fondo.cpp
 * Author: betoio
 * 
 * Created on 25 de julio de 2016, 08:20
 */

#include "Fondo.h"
#include <SDL_image.h>

Fondo::Fondo() {
    this->_position = new SDL_Rect();
    this->_position->x = 0;
    this->_position->y = 0;
    this->_position->w = 1280;
    this->_position->h = 720;
}
Fondo::Fondo(const Fondo& orig) {}
Fondo::~Fondo() {}
void Fondo::setPosition(SDL_Rect* position){
    this->_position = position;
}
void Fondo::loadImage(char file[], SDL_Renderer* renderer/*, SDL_Surface* gScreenSurface*/){
    this->_texture = IMG_LoadTexture(renderer, file);
    if( this->_texture == NULL ){
        SDL_Log( "error cargando imagen\n");
    }else{
        SDL_Log( "imagen cargada: \n");
    }
}
void Fondo::draw(SDL_Renderer* render){
    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    SDL_RenderCopy(render, this->_texture, NULL, this->_position);
}