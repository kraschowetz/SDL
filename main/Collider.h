#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "../entity/Entity.h"
#include "../math/Vector2.h"

class Collider{
    //variables
    private:
        SDL_Rect shape;
        bool isStatic;
        bool isTrigger = false;
        bool isActive = true;
        Vector2 centerPosition;
        Vector2 size;
        Vector2 offset;
        Entity* parent;
        std::string data;
    //getters
    public:
        SDL_Rect* getShape();
        Vector2 getCenter();
        void setData(std::string _d);
    // methods
    public:
        Collider();
        Collider(Vector2 _pos);
        Collider(Vector2 _pos, Vector2 _size);
        Collider(Vector2 _pos, Vector2 _size, Entity* _p);
        void updatePosition(Vector2 _pos);
        void setIsTrigger(bool _t);
        void setIsStatic(bool _s);
        void setOffset(Vector2 of);
        std::string getData();
        bool isColliding(Collider *other);
        void render(SDL_Renderer* r);
};