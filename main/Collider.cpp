#include "Collider.h"

//default constructor
Collider::Collider(){
    this->shape.x = 0;
    this->shape.y = 0;
    this->shape.w = 32;
    this->shape.h = 32;
    this->size = Vector2(32.f, 32.f);
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

//custom position constructor
Collider::Collider(Vector2 _pos){
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    this->shape.w = 32;
    this->shape.h = 32;
    this->size = Vector2(32.f, 32.f);
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

//custom position & size constructor
Collider::Collider(Vector2 _pos, Vector2 _size){
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    this->shape.w = _size.x;
    this->shape.h = _size.y;
    this->size = _size;
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

//entity collider constructor
Collider::Collider(Vector2 _pos, Vector2 _size, Entity* _p){
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    this->shape.w = _size.x;
    this->shape.h = _size.y;
    this->size = _size;
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->parent = _p;
    this->isStatic = false;
}

void Collider::updatePosition(Vector2 _pos){
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
}

void Collider::setIsTrigger(bool _t){
    this->isTrigger = _t;
}

void Collider::setIsStatic(bool _s){
    this->isStatic = _s;
}

void Collider::setData(std::string _d){
    this->data = _d;
}

std::string Collider::getData(){
    return this->data;
}

//coliision detection
bool Collider::isColliding(Collider *other){
    //get collision via SDL_Rect HasIntersection()
    bool r = SDL_HasIntersection(
            this->getShape(), other->getShape()
        );
    /*
        if the collider that called the isColliding function
        is not static (i.e. is an entity) the calling collider
        gets pushed away from the static collisder
    */
    if(r && !this->isStatic && !this->isTrigger){
        Vector2 force = (
                centerPosition - other->getCenter()
            );
        parent->applyForce(force.normalized() * 16.f);
    }
    return r;
}

//render method is used only for debugging
void Collider::render(SDL_Renderer* r){
    //set renderShape
    SDL_Rect renderShape {
        shape.x - offset.x,
        shape.y - offset.y,
        shape.w,
        shape.h
    };

    // draws the collider in a transparent blue shade
    SDL_SetRenderDrawColor(r, 123, 128, 255, 128);
    SDL_RenderFillRect(r, &renderShape);
    // draws the bounds of the collider
    SDL_SetRenderDrawColor(r, 64, 64, 255, 255);
    SDL_RenderDrawRect(r, &renderShape);
    // draws the center point of the collider in red
    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
    SDL_RenderDrawPoint(
        r,
        centerPosition.x - offset.x,
        centerPosition.y - offset.y
    );
}

Vector2 Collider::getCenter(){
    return this->centerPosition;
}

SDL_Rect* Collider::getShape(){
    return &this->shape;
}

void Collider::setOffset(Vector2 of){
    this->offset = of;
}