#include "Attack.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

Attack::Attack(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
    this->_time_pre = personaje->getProperty("AtaquePre");
    this->_time_durante = this->_time_pre + personaje->getProperty("AtaqueDurante");
    this->_time_post = this->_time_durante + personaje->getProperty("AtaquePost");
}

Attack::Attack(const Attack& orig) : State(orig) {}
Attack::~Attack() {}
void Attack::update(double ticks){
    this->_ticks +=ticks;
    if(this->_ticks >= this->_time_durante && this->_done == false){
        this->_done = true;
        this->_enemy->recibirAtaque(this->_personaje);
    }else if(this->_ticks >= this->_time_post){
        this->_personaje->stateToIdle();
    }
}
void Attack::start(){
    this->_ticks = 0;
}
bool Attack::atacar(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToAttack(enemy);
        return true;
    }
    return false;
}
bool Attack::bloquear(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToBlock(enemy);
        return true;
    }
    return false;
}
bool Attack::parry(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToParry(enemy);
        return true;
    }
    return false;
}