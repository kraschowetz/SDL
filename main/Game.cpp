#include "Game.h"

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Timer.h"
#include "../entity/Entity.h"

void Game::start()
{
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

    run();
}

void Game::stop()
{
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

void Game::run()
{
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

void Game::pollEvents()
{
    SDL_Event ev;
    SDL_PollEvent(&ev);

    switch (ev.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    }
}

void Game::update(float delta)
{
    // game logic goes here
}

void Game::render()
{
    // clear window
    SDL_RenderClear(renderer);

    // import font from file
    static TTF_Font *font = TTF_OpenFont(
        "assets/fonts/FiraCode.ttf", 12);
    // create color from rgba
    static SDL_Color c_white = {
        255, 255, 255, 255};
    // create SDL_Surface from fps string
    SDL_Surface *textSurface = TTF_RenderText_Blended(
        font, std::string("fps " + 
        std::to_string(1.f / deltaTime)).c_str(), c_white);
    // create a string from surface
    SDL_Texture *text_t = SDL_CreateTextureFromSurface(
        renderer, textSurface);
    // get surface bounds
    SDL_Rect textBounds = {
        5, 5, textSurface->w, textSurface->h};
    // copy texture to render target(Renderer*)
    SDL_RenderCopy(renderer, text_t, nullptr, &textBounds);

    //reset the color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // free the surface
    SDL_FreeSurface(textSurface);
    // destroy texture
    SDL_DestroyTexture(text_t);

    // update screen
    SDL_RenderPresent(renderer);
}