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
        std::string getData();
        bool isColliding(Collider *other);
        void render(SDL_Renderer* r);
};

/*
    
    OPTIMIZING COLLISIONS:
        world is divided by chunks
        chunks are areas of 16x16* tiles
        world loads a 3x3 chunk grid for heavywheight game logic
        world loads all visible chunks for visuals & lightwheigt logic

        collision detection only happens in chuncks in this 3x3 grid
        3x3 grid is always centered on player

        collisions may have a ignoreChunk varible, that if set to true,
        make the colision always be checked, this may be used for 
        larger props or entities.
        

*/