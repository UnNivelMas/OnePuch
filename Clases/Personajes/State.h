#ifndef STATE_H
#define STATE_H
#include <SDL2/SDL.h>

class Personaje;
class State {
public:
    State(Personaje*);
    State(const State& orig);
    void setPersonaje(Personaje*);
    void setEnemy(Personaje*);
    virtual bool update(double);
    void start();
    virtual void reset();
    virtual bool atacar(Personaje*);
    virtual bool bloquear(Personaje*);
    virtual bool parry(Personaje*);
    virtual void recibirAtaque(Personaje*);
    virtual ~State();
protected:
    double _ticks;
    double _time_pre;
    double _time_durante;
    double _time_post;
    Personaje* _personaje;
    Personaje* _enemy;
};
#endif
