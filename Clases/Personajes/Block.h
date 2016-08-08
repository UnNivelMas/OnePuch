#ifndef BLOCK_H
#define BLOCK_H
#include "State.h"
class Block : public State {
    public:
        Block(Personaje*);
        Block(const Block& orig);
        void setPersonaje(Personaje*);
        void update(double);
        void start();
        bool atacar(Personaje*);
        bool bloquear(Personaje*);
        bool parry(Personaje*);
        virtual ~Block();
    protected:

};
#endif