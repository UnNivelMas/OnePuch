#ifndef DEATH_H
#define DEATH_H
#include "State.h"
class Death : public State {
    public:
        Death(Personaje*);
        Death(const Death& orig);
        void setPersonaje(Personaje*);
        bool update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        void recibirAtaque(Personaje*);
        virtual ~Death();
    protected:

};
#endif