#include "Death.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

Death::Death(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
//    this->_time_pre = personaje->getProperty("ParryPre");
//    this->_time_durante = this->_time_pre + personaje->getProperty("ParryDurante");
//    this->_time_post = this->_time_durante + personaje->getProperty("ParryPost");
}
Death::Death(const Death& orig) : State(orig){}
Death::~Death() {}

void Death::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
bool Death::update(double ticks){
    this->_ticks +=ticks;
    return false;
}
void Death::start(){
}
bool Death::atacar(Personaje* enemy){
    SDL_Log("Death::atacar");
    return false;
}
bool Death::bloquear(Personaje* enemy){
    SDL_Log("Death::bloquear");
    return false;
}
bool Death::parry(Personaje* enemy){
    SDL_Log("Death::parry");
    return false;
}
void Death::recibirAtaque(Personaje* enemy){
    
}