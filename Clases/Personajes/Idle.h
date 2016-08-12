#ifndef IDLE_H
#define IDLE_H
#include "State.h"
class Idle : public State {
    public:
        Idle(Personaje*);
        Idle(const Idle& orig);
        void setPersonaje(Personaje*);
        bool update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        void recibirAtaque(Personaje*);
        void reset();
        virtual ~Idle();
    protected:

};
#endif