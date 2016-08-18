#include "../Escenas/Escena.h"
#include "Personaje.h"
#include "Idle.h"
#include "Attack.h"
#include "Block.h"
#include "Death.h"
#include "Parry.h"

Personaje::Personaje(Escena* escena, const char* nombre) {
    strcpy(this->_nombre, nombre);
    this-> _ticks = 0.0;
    this->_escena = escena;
    this->_state_idle = new Idle(this);
    this->_state_idle = dynamic_cast<Idle*>(this->_state_idle);
    this->_state_attack = new Attack(this);
    this->_state_attack = dynamic_cast<Attack*>(this->_state_attack);
    this->_state_block = new Block(this);
    this->_state_block = dynamic_cast<Block*>(this->_state_block);
    this->_state_parry = new Parry(this);
    this->_state_parry = dynamic_cast<Parry*>(this->_state_parry);
    this->_state_death = new Death(this);
    this->_state_death = dynamic_cast<Death*>(this->_state_death);
    this->_state = this->_state_idle;
}
void Personaje::reset(){
    this->_state_idle->reset();
    this->_state_attack->reset();
    this->_state_block->reset();
    this->_state_parry->reset();
    this->_state_death->reset();
    this->_state = this->_state_idle;
    this->_idle->reset();
    this->_anim_actual->reset();
    this->_golpear->reset();
    this->_defensa_rota->reset();
    this->_morir->reset();
    this->_bloquear->reset();
    this->_caminar->reset();
}
Personaje::Personaje(const Personaje& orig){}Personaje::~Personaje(){}
void Personaje::draw(SDL_Renderer* renderer){}
void Personaje::atacar(Personaje* enemy){
    this->_state->atacar(enemy);
}
void Personaje::bloquear(Personaje* enemy){
    this->_state->bloquear(enemy);
}
void Personaje::parry(Personaje* enemy){
    this->_state->parry(enemy);
}
char* Personaje::getNombre(){return &(this->_nombre[0]);}
void Personaje::recibirEvento(){}
void Personaje::animarAtaque(){
    this->_anim_actual->start();
    this->_anim_actual = this->_golpear;
    this->_anim_actual->start();
}
void Personaje::animarBloqueo(){
    this->_anim_actual->start();
    this->_anim_actual = this->_bloquear;
    this->_anim_actual->start();
}
void Personaje::animarMorir(){
    this->_anim_actual->start();
    this->_anim_actual = this->_morir;
    this->_anim_actual->setLoop(false);
    this->_anim_actual->start();
}
void Personaje::animarParry(){
    this->_anim_actual->start();
    this->_anim_actual = this->_caminar;
    this->_anim_actual->start();
}
void Personaje::recibirAtaque(Personaje* enemy){
    this->_state->recibirAtaque(enemy);
}
void Personaje::recibirBloqueo(Personaje* _enemy){
}
void Personaje::recibirParry(Personaje* _enemy){
}
void Personaje::update(double ticks){
    this->_ticks +=ticks;
    this->_state->update(ticks);
    this->_anim_actual->update(ticks);
}
int Personaje::getProperty(const char* key){
    char aux[40] = "";
    strcat(aux, this->_nombre);
    strcat(aux, key);
    return this->_escena->getProperty(aux);
}
void Personaje::stateToIdle(){
    this->_state->start();
    this->_state = this->_state_idle;
    this->_state->start();
}
void Personaje::stateToAttack(Personaje* enemy){
    this->_state->start();
    this->_state = this->_state_attack;
    this->_state->start();
    this->_state->setEnemy(enemy);
}
void Personaje::stateToBlock(Personaje* enemy){
    this->_state->start();
    this->_state = this->_state_block;
    this->_state->start();
    this->_state->setEnemy(enemy);
}
void Personaje::stateToParry(Personaje* enemy){
    this->_state->start();
    this->_state = this->_state_parry;
    this->_state->start();
    this->_state->setEnemy(enemy);
}
void Personaje::stateToDeath(Personaje* enemy){
    this->_state->start();
    this->_state = this->_state_death;
    this->_state->start();
    this->_state->setEnemy(enemy);
    this->animarMorir();
}
void Personaje::setAnimLoop(bool loop){
    this->_anim_actual->setLoop(loop);
}
