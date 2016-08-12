#include "Block.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

Block::Block(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
    this->reset();
}
Block::Block(const Block& orig) : State(orig){}
Block::~Block() {}

void Block::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
bool Block::update(double ticks){
    this->_ticks +=ticks;
    return true;
}
void Block::start(){}
bool Block::atacar(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToAttack(enemy);
        this->_personaje->animarAtaque();
        return true;
    }
    return false;
}
bool Block::bloquear(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToBlock(enemy);
        this->_personaje->animarBloqueo();
        return true;
    }
    return false;
}
bool Block::parry(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToParry(enemy);
        this->_personaje->animarParry();
        return true;
    }
    return false;
}
void Block::recibirAtaque(Personaje* enemy){
    //this->_personaje->stateToDeath(enemy);
}
void Block::reset(){
    this->_ticks = 0;
    this->_time_pre = this->_personaje->getProperty("DefensaPre");
    this->_time_durante = this->_time_pre + this->_personaje->getProperty("DefensaDurante");
    this->_time_post = this->_time_durante + this->_personaje->getProperty("DefensaPost");
}