#include "Player.h"

#include <iostream>

void Player::setInputHandler(InputHandler* in){
    this->inputHandler = in;
}

void Player::update(float delta){
    move();
    
    //set velocity
    velocity = dir.normalized() * speed * delta;
    //apply velocity
    position += velocity;

    //apply velocity in drawable rect
    rect.x = position.x;
    rect.y = position.y;
}

void Player::render(SDL_Renderer *r){
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawRect(r, &rect);
}

void Player::move(){
    /*
        read inputStorage;
        convert data in inputStorage to direction Vector2
    */
    dir = Vector2(0.f, 0.f);
    if(inputHandler->getKeyPressed(SDLK_d)){
        dir.x += 1;
    }
    if(inputHandler->getKeyPressed(SDLK_a)){
        dir.x += -1;
    }
    if(inputHandler->getKeyPressed(SDLK_s)){
        dir.y += 1;
    }
    if(inputHandler->getKeyPressed(SDLK_w)){
        dir.y += -1;
    }
    /*
    for(int i = 0; i < inputStorage.size(); i++){
        if(inputStorage.at(i) == SDLK_d){
            dir.x += 1;
        }
        if (inputStorage.at(i) == SDLK_a){
            dir.x += -1;
        }
        if (inputStorage.at(i) == SDLK_s){
            dir.y += 1;
        }
        if (inputStorage.at(i) == SDLK_w){
            dir.y += -1;
        }
    }
    */
}