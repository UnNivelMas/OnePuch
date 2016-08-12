#include "Parry.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

Parry::Parry(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
    this->reset();
}
Parry::Parry(const Parry& orig) : State(orig){}
Parry::~Parry() {}

void Parry::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
bool Parry::update(double ticks){
    this->_ticks +=ticks;
    return true;
}
void Parry::start(){}
bool Parry::atacar(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToAttack(enemy);
        this->_personaje->animarAtaque();
        return true;
    }
    return false;
}
bool Parry::bloquear(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToBlock(enemy);
        this->_personaje->animarBloqueo();
        return true;
    }
    return false;
}
bool Parry::parry(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToParry(enemy);
        this->_personaje->animarParry();
        return true;
    }
    return false;
}
void Parry::recibirAtaque(Personaje* enemy){
    if(this->_ticks >= this->_time_pre && this->_ticks <= this->_time_durante){
        this->_personaje->atacar(enemy);
    }else{
        this->_personaje->stateToDeath(enemy);
    }
}
void Parry::reset(){
    this->_ticks = 0;
    this->_time_pre = this->_personaje->getProperty("ParryPre");
    this->_time_durante = this->_time_pre + this->_personaje->getProperty("ParryDurante");
    this->_time_post = this->_time_durante + this->_personaje->getProperty("ParryPost");
}