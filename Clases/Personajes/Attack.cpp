#include "Attack.h"
#include "Personaje.h"
#include <SDL2/SDL.h>

Attack::Attack(Personaje* personaje) : State(personaje) {
    this->_personaje = personaje;
    this->reset();
}

Attack::Attack(const Attack& orig) : State(orig) {}
Attack::~Attack() {}
bool Attack::update(double ticks){
    this->_ticks +=ticks;
    if(this->_ticks >= this->_time_durante && this->_done == false){
        this->_done = true;
        SDL_Log("Atacando");
        this->_enemy->recibirAtaque(this->_personaje);
    }else if(this->_ticks >= this->_time_post){
        this->_personaje->stateToIdle();
    }
    return true;
}
void Attack::start(){
    this->_ticks = 0;
}
bool Attack::atacar(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToAttack(enemy);
        this->_personaje->animarAtaque();
        return true;
    }
    return false;
}
bool Attack::bloquear(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToBlock(enemy);
        this->_personaje->animarBloqueo();
        return true;
    }
    return false;
}
bool Attack::parry(Personaje* enemy){
    if(this->_ticks >= this->_time_post){
        this->_personaje->stateToParry(enemy);
        this->_personaje->animarParry();
        return true;
    }
    return false;
}
void Attack::recibirAtaque(Personaje* enemy){
    this->_personaje->stateToDeath(enemy);
}
void Attack::reset(){
    this->_ticks = 0;
    this->_time_pre = this->_personaje->getProperty("AtaquePre");
    this->_time_durante = this->_time_pre + this->_personaje->getProperty("AtaqueDurante");
    this->_time_post = this->_time_durante + this->_personaje->getProperty("AtaquePost");
}