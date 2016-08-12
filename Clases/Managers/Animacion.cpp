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
    this->_loop = true;
    this->_fps = 1000/12;
    this->_path = path;
    this->_cant = cant;
    this->_actual = 0;
    this->_pause = true;
    this->_position = position;
    this->_texture = (SDL_Texture**)malloc(sizeof(SDL_Texture*)*cant);
    char str[5];
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
            SDL_Log(IMG_GetError());
        }else{
//            SDL_Log(result);
//            SDL_Log( "Animacion::Animacion -> imagen cargada: \n");
        }
    }
}
void Animacion::setLoop(bool loop){
    this->_loop = loop;
}
void Animacion::start() {
    this->_actual = 0;
    this->_pause = false;
}
void Animacion::stop() {
    this->_pause = true;
    this->_actual = 0;
}
bool Animacion::isRuning() {
    return this->_pause;
}
void Animacion::setFPS(int fps) {
    this->_fps = 1000/fps;
}
Animacion::Animacion(const Animacion& orig) {}
Animacion::~Animacion() {}
void Animacion::resetCounter() {
    this->_actual = 0;
}
void Animacion::draw(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, this->_texture[this->_actual], NULL, this->_position);
}
void Animacion::update(double ticks){
    if(!this->_pause){
        this->_ticks += ticks;
        if(this->_ticks >= this->_fps){
            this->_ticks -= this->_fps;
            this->_actual++;
            if(this->_actual >= this->_cant){
                this->_pause = true;
                if(this->_loop){
                    this->_actual = 0;
                }else{
                    this->_actual = this->_cant-1;
                }
            }
        }
    }else{
        this->_ticks = 0;
    }
}
void Animacion::reset(){
    this->_ticks = 0;
    this->_actual = 0;
    this->_loop = true;
    this->_pause = true;
}