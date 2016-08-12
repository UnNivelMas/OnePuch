#ifndef PARRY_H
#define PARRY_H
#include "State.h"
class Parry : public State {
    public:
        Parry(Personaje*);
        Parry(const Parry& orig);
        void setPersonaje(Personaje*);
        bool update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        void recibirAtaque(Personaje*);
        virtual ~Parry();
        void reset();
    protected:

};
#endif