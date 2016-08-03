/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fondo.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:20
 */

#ifndef FONDO_H
#define FONDO_H
#include <SDL2/SDL.h>
#include "SDL_image.h"

//#include "SDL2/SDL_image.h"

class Fondo {
    public:
        Fondo();
        Fondo(const Fondo& orig);
        virtual ~Fondo();
        void loadImage(char*, SDL_Renderer*, SDL_Surface*);
        void draw();
    private:
//        SDL_Texture* _imagen;
        SDL_Surface* _imagen;
    
};

#endif /* FONDO_H */

