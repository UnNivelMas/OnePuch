#include "Input.h"
#include "../Director/Director.h"
#include "../../Command/Command.h"

Input::Input(){
    this->_pause = false;   
    _tickEvents = new Command[50];
    _tickEventsOffset = _tickEvents;
    SDL_Log("# Joysticks: %d", SDL_NumJoysticks());
    SDL_JoystickEventState(SDL_ENABLE);
    for(int i=0;i<SDL_NumJoysticks();i++){
        SDL_JoystickOpen(i);
    }
}
Input::Input(const Input& orig) {}
Input::~Input() {
    for(int i=0;i<SDL_NumJoysticks();i++){
        SDL_JoystickClose(SDL_JoystickOpen(i));
    }
}

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
                this->_dir->onKeyDown(event);
                break;
            case SDL_KEYUP: 
                this->_dir->onKeyUp(event);
                SDL_Log("Input::KeyButtonUp");
                break;
            case SDL_MOUSEBUTTONDOWN: 
                SDL_Log("Input::KeyButtonDown");
                this->_dir->onMouseButtonDown(event);
                break;
            case SDL_QUIT:
                this->_dir->onQuit();
                break;
            case SDL_JOYBUTTONDOWN:
//                SDL_Log("Input::JoyButtonDown");
                this->_dir->onJoyButtonDown(event);
                break;
            case SDL_JOYAXISMOTION:
//                SDL_Log("Input::JoyAxysMove");
                this->_dir->onJoyAxysMove(event);
                break;
            case SDL_JOYBALLMOTION:
//                SDL_Log("Input::JoyBallMove");
                this->_dir->onJoyBallMove(event);
                break;
            default:break;
        }
    }
    return 0;
}