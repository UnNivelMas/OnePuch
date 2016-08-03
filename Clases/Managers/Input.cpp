#include "Input.h"
#include "../Director/Director.h"
#include "../../Command/Command.h"

Input::Input(){
    this->_pause = false;   
    _tickEvents = new Command[50];
    _tickEventsOffset = _tickEvents;
}
Input::Input(const Input& orig) {}
Input::~Input() {}

void Input::setDirector(Director* dir){
    this->_dir = dir;
}

void Input::start(){
    this->_pause = false;
    SDL_StartTextInput();
}

void Input::pause(){
    this->_pause = true;
}

int Input::checkEvents(){
    if(this->_pause){
        return 0;
    }
    while (SDL_PollEvent(&this->event)) {
        switch (event.type) {
            case SDL_KEYDOWN: 
                SDL_Log("SDL_KEYDOWN\n");
                break;;
            case SDL_KEYUP: 
                SDL_Log("SDL_KEYUP\n");
            break;;
            case SDL_MOUSEBUTTONDOWN: 
            break;;
            case SDL_QUIT:
                SDL_Log("SDL_KEYUP\n");
                this->_dir->onQuit();
            break;;
            default:break;
        }
    }
    return 0;
}