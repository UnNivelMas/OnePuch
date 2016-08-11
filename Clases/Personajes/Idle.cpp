#include "Idle.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

Idle::Idle(Personaje* personaje) : State(personaje) {
}
Idle::Idle(const Idle& orig) : State(orig) {}
Idle::~Idle() {}

void Idle::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
bool Idle::update(double ticks){
    this->_ticks +=ticks;
    return true;
}
void Idle::start(){}
bool Idle::atacar(Personaje* enemy){
    this->_personaje->stateToAttack(enemy);
    SDL_Log("Idle::atacar");
    return true;
}
bool Idle::bloquear(Personaje* enemy){
    this->_personaje->stateToBlock(enemy);
    SDL_Log("Idle::bloquear");
    return true;
}
bool Idle::parry(Personaje* enemy){
    this->_personaje->stateToParry(enemy);
    SDL_Log("Idle::parry");
    return true;
}
void Idle::recibirAtaque(Personaje* enemy){
    this->_personaje->stateToDeath(enemy);
}