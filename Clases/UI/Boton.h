#ifndef BOTON_H
#define BOTON_H
#include <SDL2/SDL.h>
class Director;
class Escena;

class Boton{
    public:
        Boton(Director*, Escena*);
        virtual void draw(SDL_Renderer*);
        virtual void update(double);
        virtual void reset();
        virtual void mouseButtonDown(SDL_Event*);
        virtual void onJoyButtonDown(SDL_Event*);
    protected:
        Director* _dir;
        Escena* _escena;
        SDL_Rect* _pos;
};
#endif