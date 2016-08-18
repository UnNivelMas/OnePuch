#ifndef ATTACK_H
#define ATTACK_H
#include "State.h"
class Attack : public State {
    public:
        Attack(Personaje*);
        Attack(const Attack& orig);
        void setPersonaje(Personaje*);
        bool update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        void recibirAtaque(Personaje*);
        void reset();
        virtual ~Attack();
    protected:
        bool _done;
};
#endif
