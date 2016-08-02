/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Director.cpp
 * Author: betoio
 * 
 * Created on 1 de agosto de 2016, 20:02
 */

#include "Director.h"

Director::Director() {
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow("One Punch Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    this->_inputManager = new Input();
    this->_inputManager->setDirector(this);
}
Director::Director(const Director& orig) {}
Director::~Director() {
	SDL_DestroyWindow(this->_window);
    SDL_Quit();
}
void Director::createGameplay(){
    this->_gameplay = new Gameplay();
}
void Director::onQuit(){
    this->_quit = 1;
}
void Director::start(){
    this->_quit = 0;
    this->_inputManager->start();
    this->createGameplay();
    this->_actual = this->_gameplay;
    while(! this->_quit){
        
    }
}