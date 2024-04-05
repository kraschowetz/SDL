#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "InputHandler.h"
#include "../entity/Entity.h"
#include "../entity/Player.h"
#include "../ui/FpsCounter.h"
#include "../world/World.h"
#include "Collider.h"

class Game {   
    //varibles
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running = true;
        float deltaTime;
        std::vector<Entity> entities;
        World w;
        Player player;
        FpsCounter fpsCounter;
        Collider col;
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