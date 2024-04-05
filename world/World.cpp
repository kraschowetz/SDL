#include "world.h"

#include <cstring>

void World::setRenderer(SDL_Renderer *r){
    this->renderer = r;
}

void World::loadWorld(std::string img_p, std::string data_p){
    //load world image
    image = IMG_Load(img_p.c_str());
    //load world data
    std::fstream data;
    data.open(data_p, std::ios::in);
    //error check
    if(!data.is_open()){
        std::cout<<"ERR: cant open world data file1";
    }
    std::string t;
    //foreach line i data file
    while(std::getline(data, t)){
        char op = t.c_str()[0];
        switch(op){
            case 'c':
                float xx = std::strtof(split(t).at(1).c_str(), nullptr);
                float yy = std::strtof(split(t).at(2).c_str(), nullptr);
                float ww = std::strtof(split(t).at(3).c_str(), nullptr);
                float hh = std::strtof(split(t).at(4).c_str(), nullptr);
                collision.push_back(
                    Collider(
                        Vector2(xx, yy),
                        Vector2(ww, hh)
                    )
                );
                break;
        }
    }
       
    data.close();
}

void World::interpretWorldDataLine(std::string l){

}

//this method loads the map image
void World::initGraphics(){
    texture = SDL_CreateTextureFromSurface(
        nullptr, image);
}

void World::render(){
    if(texture == nullptr){
        texture = SDL_CreateTextureFromSurface(
            renderer, image
        );
    }
    SDL_Rect bounds = {
        0, 0, image->w, image->h
    };
    SDL_RenderCopy(
        renderer,
        texture, 
        nullptr,
        &bounds
    );
    for(Collider c : collision){
        c.render(renderer);
    }
}

std::vector<Collider> World::getCollision(){
    return this->collision;
}

//custom string.split method
//may make this method its own separate class
std::vector<std::string> World::split(std::string in){
    std::vector<std::string> result;
    int startID = 0; int endID = 0;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == '-' || i == in.size()){
            endID = i;
            std::string temp;
            temp.append(in, startID, endID - startID);
            result.push_back(temp);
            startID = endID + 1;
        }
    }
    return result;
}