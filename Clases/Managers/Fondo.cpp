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

#include <SDL2/SDL_image.h>


Fondo::Fondo() {}
Fondo::Fondo(const Fondo& orig) {}
Fondo::~Fondo() {}
void Fondo::loadImage(char file[], SDL_Renderer* renderer, SDL_Surface* gScreenSurface){
	SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load(file);
    if( loadedSurface == NULL ){
        SDL_Log( "error cargando imagen\n");
    }else{
        SDL_Log( "imagen cargada: \n");
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        if( optimizedSurface == NULL ){
			SDL_Log( "Unable to optimize image %s! SDL Error: %s\n", file, SDL_GetError() );
		}
        this->_imagen = optimizedSurface;
		SDL_FreeSurface( loadedSurface );
    }
}
void Fondo::draw(){
    
}