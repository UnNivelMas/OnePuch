/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.h
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:13
 */

#ifndef ANIMACION_H
#define ANIMACION_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_stdinc.h>

class Animacion {
    public:
        Animacion();
        Animacion(char*, int, SDL_Rect*, SDL_Renderer*);
        Animacion(const Animacion& orig);
        virtual ~Animacion();
        void draw(SDL_Renderer*);
        void resetCounter();
        void update(double);
        void setFPS(int);
        void start();
        void stop();
        bool isRuning();
    private:
        bool _pause;
        char* _path;
        double _ticks, _fps;
        int _cant, _actual;
        SDL_Texture** _texture;
        SDL_Rect* _position;
};

#endif /* ANIMACION_H */