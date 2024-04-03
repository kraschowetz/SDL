#pragma once

#include <SDL2/Sdl.h>
#include <vector>

class InputHandler{
    //variables
    private:
        std::vector<int> keysPressed;
        std::vector<int> keysJustPressed;
        std::vector<int> keysJustReleased;
    //functions
    public:
        void update();
        void pollEvents(SDL_Event ev);
    // getters
    public : 
        bool getKeyPressed(int k);
        bool getKeyJustPressed(int k);
        bool getKeyJustReleased(int k);
};