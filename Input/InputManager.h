#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class Command;

class InputManager {
public:
    InputManager();
    virtual ~InputManager();

    void checkInput();

private:

	Command* methodMap[512];
};

#endif