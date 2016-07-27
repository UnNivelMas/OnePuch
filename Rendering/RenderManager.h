#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <SDL2/SDL.h>

class RenderManager {
public:
    RenderManager();
    virtual ~RenderManager();

    void startSDL();

private:

	SDL_Window* main_window;
};

#endif