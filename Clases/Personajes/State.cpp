#include "State.h"
#include <SDL2/SDL.h>
#include "Personaje.h"
State::State(Personaje* personaje) {
    this->_personaje = personaje;
}
State::State(const State& orig) {}
State::~State() {}
void State::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
void State::setEnemy(Personaje* enemy){
    this->_enemy = enemy;
    this->start();
}
bool State::update(double ticks){
    this->_ticks +=ticks;
    return true;
}
void State::start(){}
bool State::atacar(Personaje* enemy){
    return false;
}
bool State::bloquear(Personaje* enemy){
    return false;
}
bool State::parry(Personaje* enemy){
    return false;
}
void State::recibirAtaque(Personaje* enemy){}
void State::reset(){}