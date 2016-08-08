#include "Parry.h"
#include "Personaje.h"

Parry::Parry(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
    this->_time_pre = personaje->getProperty("ParryPre");
    this->_time_durante = this->_time_pre + personaje->getProperty("ParryDurante");
    this->_time_post = this->_time_durante + personaje->getProperty("ParriPost");
}
Parry::Parry(const Parry& orig) : State(orig){}
Parry::~Parry() {}

void Parry::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
void Parry::update(double ticks){
    this->_ticks +=ticks;
}
void Parry::start(){}
bool Parry::atacar(Personaje* enemy){
    return false;
}
bool Parry::bloquear(Personaje* enemy){
    return false;
}
bool Parry::parry(Personaje* enemy){
    return false;
}