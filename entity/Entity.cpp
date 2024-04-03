#include "Entity.h"

//Entity.cpp is currently used for debug    

Entity::Entity(){
    position = Vector2(0.f, 0.f);
    rect.x = position.x;
    rect.y = position.y;
    rect.w = 32.f;
    rect.h = 32.f;
}

void Entity::update(float delta){
   
}

void Entity::render(SDL_Renderer* r){
    
}

Vector2 Entity::getPosition(){
    return position;
}

SDL_Rect& Entity::getRect(){
    return rect;
}