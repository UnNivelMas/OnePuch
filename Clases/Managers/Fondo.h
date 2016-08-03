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
#include <SDL_image.h>

class Fondo {
    public:
        Fondo();
        Fondo(const Fondo& orig);
        void setPosition(SDL_Rect*);
        virtual ~Fondo();
        void loadImage(char*, SDL_Renderer*);
        //void loadImage(char*, SDL_Renderer*, SDL_Surface*);
        void draw(SDL_Renderer*);
    private:
        SDL_Surface* _imagen;
        SDL_Texture* _texture;
        SDL_Rect* _position;
};

#endif /* FONDO_H */

