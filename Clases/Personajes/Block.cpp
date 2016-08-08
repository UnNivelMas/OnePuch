#include "Block.h"
#include "Personaje.h"

Block::Block(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
    this->_time_pre = personaje->getProperty("DefensaPre");
    this->_time_durante = this->_time_pre + personaje->getProperty("DefensaDurante");
    this->_time_post = this->_time_durante + personaje->getProperty("DefensaPost");
}
Block::Block(const Block& orig) : State(orig){}
Block::~Block() {}

void Block::setPersonaje(Personaje* personaje){
    this->_personaje = personaje;
}
void Block::update(double ticks){
    this->_ticks +=ticks;
}
void Block::start(){}
bool Block::atacar(Personaje* enemy){
     if(this->_ticks >= this->_time_post){
        this->_personaje->stateToAttack(enemy);
        return true;
    }
    return false;
}
bool Block::bloquear(Personaje* enemy){
     if(this->_ticks >= this->_time_post){
        this->_personaje->stateToBlock(enemy);
        return true;
    }
    return false;
}
bool Block::parry(Personaje* enemy){
     if(this->_ticks >= this->_time_post){
        this->_personaje->stateToParry(enemy);
        return true;
    }
    return false;
}