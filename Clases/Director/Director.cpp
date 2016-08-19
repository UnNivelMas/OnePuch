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
#include "../../File/FileManager.h"
#include <stdio.h> 

Director::Director() {
    //SDL_Init(SDL_INIT_VIDEO);
    //SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK );
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0){
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG);
    FileManager::getInstance()->openPropertiesFile("OnePunch.properties");
    _fps = 1000 / FileManager::getInstance()->getProperty("fps");
    this->_window = SDL_CreateWindow("One Punch Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    this->_renderer = SDL_CreateRenderer(this->_window,-1,SDL_RENDERER_ACCELERATED);
    this->_inputManager = new Input();
    this->_inputManager->setDirector(this);
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION|SDL_LOG_CATEGORY_SYSTEM, SDL_LOG_PRIORITY_ERROR);
}
Director::Director(const Director& orig) {}
Director::~Director() {
	SDL_DestroyWindow(this->_window);
    SDL_Quit();
}
void Director::createGameplay(){
    this->_gameplay = new Gameplay(this);
}
void Director::onQuit(){
    this->_quit = 1;
    SDL_Log("Director::onQuit");
    SDL_Quit();
}
void Director::start(){
    this->_quit = 0;
    this->_inputManager->start();
    this->createGameplay();
    this->_actual = dynamic_cast<Gameplay*>(this->_gameplay);
    SDL_Log("Director::start");
    _currentTime = SDL_GetTicks();
    while(! this->_quit){
        // _actual tiene la Scene actual y se pinta con el metodo _actual->draw();
        SDL_RenderClear(this->_renderer);
        
        this->_actual->update(SDL_GetTicks() - _lastTime);
        
        this->_actual->draw(this->_renderer);
        
        SDL_RenderPresent(this->_renderer);
        
        _lastTime = _currentTime;
        while(!this->_quit && _currentTime < (_lastTime+_fps)){
            this->_inputManager->checkEvents();
            _currentTime = SDL_GetTicks();
        }
    }
}
SDL_Renderer* Director::getRenderer(){
    return this->_renderer;
}
void Director::onKeyDown(SDL_Event event){
    if(event.key.keysym.sym == SDLK_F5){
        FileManager::getInstance()->reset();
        FileManager::getInstance()->openPropertiesFile("OnePunch.properties");
        this->_actual->reset();
    }else{
        this->_actual->onKeyDown(&event);
    }
}
void Director::onKeyUp(SDL_Event event){
    this->_actual->onKeyUp(&event);
}
void Director::onMouseButtonDown(SDL_Event event){
    this->_actual->onMouseButtonDown(&event);
}
int Director::getProperty(const char* key){
    int r = FileManager::getInstance()->getProperty(key);
    return r;
}
void Director::onJoyButtonDown(SDL_Event event){
    this->_actual->onJoyButtonDown(&event);
}
void Director::onJoyAxysMove(SDL_Event event){
    this->_actual->onJoyAxysMove(&event);
}
void Director::onJoyBallMove(SDL_Event event){
    this->_actual->onJoyBallMove(&event);
}