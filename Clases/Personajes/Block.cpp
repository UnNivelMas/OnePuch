#include "Block.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

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
bool Block::update(double ticks){
    this->_ticks +=ticks;
    return true;
}
void Block::start(){}
bool Block::atacar(Personaje* enemy){
    SDL_Log("Block::atacar");
     if(this->_ticks >= this->_time_post){
        this->_personaje->stateToAttack(enemy);
        return true;
    }
    return false;
}
bool Block::bloquear(Personaje* enemy){
    SDL_Log("Block::bloquear");
     if(this->_ticks >= this->_time_post){
        this->_personaje->stateToBlock(enemy);
        return true;
    }
    return false;
}
bool Block::parry(Personaje* enemy){
    SDL_Log("Block::parry");
     if(this->_ticks >= this->_time_post){
        this->_personaje->stateToParry(enemy);
        return true;
    }
    return false;
}
void Block::recibirAtaque(Personaje* enemy){
    //this->_personaje->stateToDeath(enemy);
}