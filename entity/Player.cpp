#include "Player.h"

#include <iostream>

Player::Player(){
    position = Vector2(400, 300);
    Collider c = Collider(
        position,
        Vector2(32.f, 32.f),
        this
    );
    collider = c;
}

void Player::setWorld(World* w){
    this->world = w;
    world->setPlayer(&collider);
}

void Player::setInputHandler(InputHandler* in){
    this->inputHandler = in;
}

Collider Player::getCol(){
    return collider;
}

void Player::update(float delta){
    move();
    
    //set velocity
    velocity = (dir.normalized() * speed * delta);
    velocity += externalForce * delta;
    //apply velocity
    position += velocity;

    //apply velocity in drawable rect
    rect.x = position.x - world->getCamera().x;
    rect.y = position.y - world->getCamera().y;
    collider.updatePosition(position);
    externalForce = Vector2(0.f, 0.f);

    for(int i = 0; i < world->getPortals().size(); i++){
        if (collider.isColliding(&world->getPortals().at(i))){
            world->interpretPortalPass(i);
            break;
        }
    }

    world->setCameraPos(
        collider.getCenter()
    );
    collider.setOffset(world->getCamera());
}

void Player::render(SDL_Renderer *r){
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawRect(r, &rect);
    collider.render(r);
}

void Player::move(){
    //detect collision
    dir = Vector2(0.f, 0.f);
    for(int i = 0; i < world->getCollision().size(); i++){
        if (collider.isColliding(&world->getCollision().at(i)))
        {
            return;
        }
    }
    /*
        read inputStorage;
        convert data in inputStorage to direction Vector2
    */
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
}