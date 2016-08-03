/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Director.h
 * Author: betoio
 *
 * Created on 1 de agosto de 2016, 20:02
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <SDL2/SDL.h>
#include "../Managers/Input.h"
#include "../Escenas/Escena.h"
#include "../Escenas/Gameplay.h"

class Director {
    public:
        Director();
        Director(const Director& orig);
        virtual ~Director();
        void start();
        void onQuit();
        SDL_Renderer* getRenderer();
        SDL_Surface* getSurfaceWindow();
    private:
        void createGameplay();
        int _quit;
        Input* _inputManager;
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        Escena* _actual;
        Gameplay* _gameplay;
        unsigned int _lastTime, _currentTime;
};

#endif /* DIRECTOR_H */

