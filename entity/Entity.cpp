#include "Entity.h"

Entity::Entity(){
    rect.x = position.x;
    rect.y = position.y;
    rect.w = 32.f;
    rect.h = 32.f;
}

Vector2 Entity::getPosition(){
    return position;
}

SDL_Rect& Entity::getRect(){
    return rect;
}