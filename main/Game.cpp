#include "Game.h"

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Timer.h"
#include "../entity/Entity.h"

void Game::start(){
    std::cout << "starting game \n"; // DEBUG
    running = true;

    // initialization bug-check//

    /*
        try to init SDL
        if cant print error msg & exit
    */
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "ERR: failed to init SDL\n"
                  << "SDL ERROR:"
                  << SDL_GetError();
        stop();
    }

    /*
      try to init SDL_image
      if cant print error msg & exit
    */
    if (IMG_Init(IMG_INIT_JPG) < 0)
    {
        std::cout << "ERR: failed to init SDL_image\n"
                  << "SDL ERROR:"
                  << SDL_GetError();
        stop();
    }

    /*
       try to init SDL_ttf
       if cant print error msg & exit
    */
    if (TTF_Init() < 0)
    {
        std::cout << "ERR: failed to init SDL_ttf\n"
                  << "SDL ERROR:"
                  << SDL_GetError();
        stop();
    }

    ////

    // crete SDL window;
    window = SDL_CreateWindow(
        "SDL test",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 600,
        0);

    /*
       if cant create SDL window:
           print error msg & exit
   */
    if (!window)
    {
        std::cout << "ERR: failed to open window"
                  << "\n SDL ERROR : "
                  << SDL_GetError();
        stop();
    }

    // set openGL window atributes
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MINOR_VERSION, 3);

    // create SDL renderer
    renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED);

    /*
        if cant create renderer?
            print error msg & exit
    */
    if (!renderer)
    {
        std::cout << "ERR: failed to create renderer"
                  << "\n SDL ERROR : "
                  << SDL_GetError();
        stop();
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    initObjects();

    run();
}

void Game::stop(){
    // destroy Window & Renderer components
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = nullptr;
    renderer = nullptr;

    // call SDL quit functions
    IMG_Quit();
    SDL_Quit();

    // queue game loop close
    running = false;
}

void Game::run(){
    // delta time setup
    Timer deltaTimer;
    deltaTimer.start();

    // actual loop
    while (running)
    {
        pollEvents();
        update(deltaTime);

        // convert delta
        deltaTime = static_cast<float>(
            deltaTimer.getTicks() / 1000.f);
        // restart delta timer
        deltaTimer.start();

        render();
    }

    // call stop func after game close queue
    stop();
}

void Game::initObjects(){
    col = Collider(Vector2(128.f, 128.f), Vector2(64, 64));
    player.setInputHandler(&inputHandler);
    player.other = &col;
}

void Game::pollEvents(){
    SDL_Event ev;
    SDL_PollEvent(&ev);

    inputHandler.pollEvents(ev);

    switch (ev.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    }
}

void Game::update(float delta){

    player.update(delta);

    for(Entity e : entities){
        e.update(delta);
    }

    inputHandler.update();
}

void Game::render(){
    // clear window
    SDL_RenderClear(renderer);

    player.render(renderer);
    col.render(renderer);

    for (Entity e : entities){
        e.render(renderer);
    }

    fpsCounter.render(renderer, deltaTime);

    // reset the color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // update screen
    SDL_RenderPresent(renderer);
}