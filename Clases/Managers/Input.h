#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
class Director;
class Command;
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
        SDL_Event event;
        int _pause;
        Director* _dir;

        // Array on Commands ready to run on a game loop, we need to have all these Command togheter for performance
        Command* _tickEvents;
        Command* _tickEventsOffset;     // Clock Commands offset
};
#endif

