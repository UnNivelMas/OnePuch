#ifndef ATTACK_H
#define ATTACK_H
#include "State.h"
class Attack : public State {
    public:
        Attack(Personaje*);
        Attack(const Attack& orig);
        void setPersonaje(Personaje*);
        void update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        virtual ~Attack();
    protected:
        bool _done = false;
};
#endif