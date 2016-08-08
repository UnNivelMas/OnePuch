#ifndef IDLE_H
#define IDLE_H
#include "State.h"
class Idle : public State {
    public:
        Idle(Personaje*);
        Idle(const Idle& orig);
        void setPersonaje(Personaje*);
        void update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        virtual ~Idle();
    protected:

};
#endif