#pragma once

#include "../main/Collider.h"
#include <string>

class Portal{
    //variables
    public:
        std::string imgPath;
        std::string dataPath;
    private:
        Vector2 position;
        Vector2 size;
        Collider col;
    //methods
    public:
        Portal(
            Vector2 _pos, 
            Vector2 _size, 
            std::string _i_path,
            std::string _d_path
        );
        void setCollider(Collider c);
        bool getCollision();
        Collider getCol();
};