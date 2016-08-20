#include "Home.h"
#include "../Director/Director.h"
Home::Home() {}
Home::Home(Director* dir){
    this->_dir = dir;
}
Home::Home(const Home& orig) {}
Home::~Home() {}
void Home::setDirector(Director* dir){
    this->_dir = dir;
}
void Home::draw(SDL_Renderer* renderer){}
void Home::update(double ticks){}
void Home::onKeyDown(SDL_Event* event){}
void Home::onKeyUp(SDL_Event* event){}
void Home::onMouseButtonDown(SDL_Event* event){}
void Home::onJoyButtonDown(SDL_Event* event){}
void Home::onJoyAxysMove(SDL_Event* event){}
void Home::onJoyBallMove(SDL_Event* event){}
void Home::reset(){}
int Home::getProperty(const char* key){
    return Escena::getProperty(key);
}
