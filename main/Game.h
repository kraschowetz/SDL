#pragma once

#include <SDL2/SDL.h>
#include "../entity/Entity.h"
#include "../entity/Player.h"

class Game {   
    //varibles
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running = true;
        float deltaTime;
        Player e;
    //functions
    public:
        void start();
        void stop();
    private:
        void run();
        void pollEvents();
        void update(float delta);
        void render();

};