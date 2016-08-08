#ifndef PARRY_H
#define PARRY_H
#include "State.h"
class Parry : public State {
    public:
        Parry(Personaje*);
        Parry(const Parry& orig);
        void setPersonaje(Personaje*);
        void update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        virtual ~Parry();
    protected:

};
#endif