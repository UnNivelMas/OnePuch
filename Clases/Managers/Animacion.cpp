/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.cpp
 * Author: betoio
 * 
 * Created on 25 de julio de 2016, 08:13
 */

#include "Animacion.h"

Animacion::Animacion(char* path, int cant, SDL_Rect* position, SDL_Renderer* renderer) {
    int i;
    this->_path = path;
    this->_cant = cant;
    this->_actual = 0;
    this->_position = position;
    this->_texture = (SDL_Texture**)malloc(sizeof(SDL_Texture*)*cant);
    char str[5];
    SDL_Log(str);
    for(i = 0; i < cant; i++){
        char result[100];
        strcpy(result, path);
        sprintf(str, "%d", i);
        strcat(result, str);
        strcat(result,".png");
        this->_texture[i] = IMG_LoadTexture(renderer, result);
        if( this->_texture[i] == NULL ){
            SDL_Log(result);
            SDL_Log( "Animacion::Animacion -> error cargando imagen\n");
        }else{
            SDL_Log(result);
            SDL_Log( "Animacion::Animacion -> imagen cargada: \n");
        }
    }
}
Animacion::Animacion(const Animacion& orig) {}
Animacion::~Animacion() {}
void Animacion::resetCounter() {
    this->_actual = 0;
}
void Animacion::draw(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, this->_texture[this->_actual], NULL, this->_position);
    this->_actual = (this->_actual+1)%this->_cant;
}