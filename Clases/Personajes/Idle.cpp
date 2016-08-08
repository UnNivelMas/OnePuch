#include "Idle.h"
#include "Personaje.h"

Idle::Idle(Personaje* personaje) : State(personaje) {
}
Idle::Idle(const Idle& orig) : State(orig) {}
Idle::~Idle() {}

void Idle::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
void Idle::update(double ticks){
    this->_ticks +=ticks;
}
void Idle::start(){}
bool Idle::atacar(Personaje* enemy){
    this->_personaje->stateToAttack(enemy);
    return true;
}
bool Idle::bloquear(Personaje* enemy){
    this->_personaje->stateToBlock(enemy);
    return true;
}
bool Idle::parry(Personaje* enemy){
    this->_personaje->stateToParry(enemy);
    return true;
}