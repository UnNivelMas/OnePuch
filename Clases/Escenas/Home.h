#ifndef HOME_H
#define HOME_H
#include "Escena.h"
#include "../Managers/Fondo.h"
#include "../Managers/AudioManager.h"
#include "../UI/Boton.h"
class Director;
class Home : public Escena {
    public:
        Escena();
        Escena(Director*);
        Escena(const Escena& orig);
        virtual ~Escena();
        void setDirector(Director*);
        virtual void draw(SDL_Renderer*);
        virtual void update(double);
        virtual void onKeyDown(SDL_Event*);
        virtual void onKeyUp(SDL_Event*);
        virtual void onMouseButtonDown(SDL_Event*);
        virtual void onJoyButtonDown(SDL_Event*);
        virtual void onJoyAxysMove(SDL_Event*);
        virtual void onJoyBallMove(SDL_Event*);
        virtual void reset();
        int getProperty(const char*);
protected:
    Director* _dir;
    AudioManager* _audio;
    Boton* _salir;
    Boton* _jugar;
};

#endif /* ESCENA_H */

