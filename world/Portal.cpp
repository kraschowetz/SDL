#include "Portal.h"

Portal::Portal(Vector2 _pos, Vector2 _size, std::string _i_path, std::string _d_path)
{
    this->position = _pos;
    this->size = size;
    this->imgPath = _i_path;
    this->col = Collider(this->position, this->size);
}

bool Portal::getCollision(){
    return false;
}

void Portal::setCollider(Collider c){
    this->col = c;
}

Collider Portal::getCol(){
    return this->col;
}