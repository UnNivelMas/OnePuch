#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
class Director;
class Input {
    public:
        Input();
        Input(const Input& orig);
        virtual ~Input();
        void setDirector(Director*);
        void start();
        void pause();
        int checkEvents();
    private:
        SDL_Event* _last;
        int _pause;
        Director* _dir;
};
#endif

