/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: betoio
 *
 * Created on 25 de julio de 2016, 08:12
 */

#include <cstdlib>
#include <SDL2/SDL.h>

SDL_Window *window;
int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2
    window = SDL_CreateWindow( 
        "An SDL2 window",                  //    window title
        SDL_WINDOWPOS_UNDEFINED,           //    initial x position
        SDL_WINDOWPOS_UNDEFINED,           //    initial y position
        800,                               //    width, in pixels
        600,                               //    height, in pixels
        SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL //    flags - see below
    );

    return 0;
}

