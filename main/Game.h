#pragma once

#include <SDL2/SDL.h>

class Game {   
    //varibles
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running = true;
        float deltaTime;
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