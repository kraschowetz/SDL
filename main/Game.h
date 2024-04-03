#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "InputHandler.h"
#include "../entity/Entity.h"
#include "../entity/Player.h"
#include "../ui/FpsCounter.h"

class Game {   
    //varibles
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running = true;
        float deltaTime;
        std::vector<Entity> entities;
        Player player;
        FpsCounter fpsCounter;
    public:
        InputHandler inputHandler;
    //functions
    public:
        void start();
        void stop();
    private:
        void run();
        void pollEvents();
        void update(float delta);
        void render();
        void initObjects();

};