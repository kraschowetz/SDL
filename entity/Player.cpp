#include "Player.h"

#include <iostream>

void Player::pollEvents(SDL_Event ev){
    switch (ev.type){
    case SDL_KEYDOWN:
        std::cout << "key pressed\n";
        break;
    case SDL_KEYUP:
        std::cout << "key released\n";
    default:
        break;
    }
}

void Player::update(float delta){
    position += Vector2(32.f, 0.f) * delta;

    rect.x = position.x;
    rect.y = position.y;
}

void Player::render(SDL_Renderer *r){
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawRect(r, &rect);
}