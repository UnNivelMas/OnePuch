#include "Input.h"
#include "../Director/Director.h"

Input::Input(){
    this->_pause = false;   
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
    while (SDL_PollEvent(&this->_last)) {
        switch (this->_last.type) {
            case SDL_KEYDOWN: break;
            case SDL_KEYUP: break;
            case SDL_TEXTEDITING: break;
            case SDL_TEXTINPUT: break;
            case SDL_MOUSEBUTTONDOWN: 
                break;
            case SDL_QUIT:
                this->_dir->onQuit();
                break;
            default:break;
        }
    }
    return 0;
}