#include "../Escenas/Escena.h"
#include "Personaje.h"
#include "Idle.h"
#include "Attack.h"
#include "Block.h"
#include "Parry.h"

Personaje::Personaje(Escena* escena, const char* nombre) {
    strcpy(this->_nombre, nombre);
    this->_escena = escena;
    this->_state_idle = new Idle(this);
    this->_state_idle = dynamic_cast<Idle*>(this->_state_idle);
    this->_state_attack = new Attack(this);
    this->_state_attack = dynamic_cast<Attack*>(this->_state_attack);
    this->_state_block = new Block(this);
    this->_state_block = dynamic_cast<Block*>(this->_state_block);
    this->_state_parry = new Parry(this);
    this->_state_parry = dynamic_cast<Parry*>(this->_state_parry);
    this->_state = this->_state_idle;
}
Personaje::Personaje(const Personaje& orig) {}
Personaje::~Personaje() {}
void Personaje::draw(SDL_Renderer* renderer){}
void Personaje::atacar(Personaje* enemy){
    if(this->_state->atacar(enemy)){
        this->animarAtaque();
//        _enemy->recibirAtaque(this);
    }
}
void Personaje::bloquear(Personaje* enemy){
    if(this->_state->bloquear(enemy)){
        this->animarBloqueo();
//        _enemy->recibirBloqueo(this);
    }
}
void Personaje::parry(Personaje* enemy){
    if(this->_state->parry(enemy)){
        this->animarParry();
//        _enemy->recibirParry(this);
    }
}
void Personaje::recibirEvento(){}
void Personaje::animarAtaque(){
    this->_anim_actual = this->_golpear;
    this->_anim_actual->start();
}
void Personaje::animarBloqueo(){
    this->_anim_actual = this->_bloquear;
    this->_anim_actual->start();
}
void Personaje::animarMorir(){
    this->_anim_actual = this->_morir;
    this->_anim_actual->start();
}
void Personaje::animarParry(){
    this->_anim_actual = this->_caminar;
    this->_anim_actual->start();
}
void Personaje::recibirAtaque(Personaje* enemy){
    /*if(this->state == 'b'){
        this->animarBloqueo();
    }else if(this->state == 'p'){
        this->animarParry();
    }else if(this->state == 'a' || this->state == 'i'){
        this->animarMorir();
    }*/
}
void Personaje::recibirBloqueo(Personaje* _enemy){
}
void Personaje::recibirParry(Personaje* _enemy){
}
void Personaje::update(double ticks){
    this->_ticks +=ticks;
    this->_anim_actual->update(ticks);
}
int Personaje::getProperty(const char* key){
    char aux[40] = "";
    strcat(aux, this->_nombre);
    strcat(aux, key);
    return this->_escena->getProperty(aux);
}
void Personaje::stateToIdle(){
    this->_state = this->_state_idle;
    this->_state->start();
}
void Personaje::stateToAttack(Personaje* enemy){
    this->_state = this->_state_attack;
    this->_state->setEnemy(enemy);
}
void Personaje::stateToBlock(Personaje* enemy){
    this->_state = this->_state_block;
    this->_state->setEnemy(enemy);
}
void Personaje::stateToParry(Personaje* enemy){
    this->_state = this->_state_parry;
    this->_state->setEnemy(enemy);
}