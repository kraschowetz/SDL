#include "world.h"

#include <cstring>

void World::setRenderer(SDL_Renderer *r){
    this->renderer = r;
}

void World::loadWorld(std::string img_p, std::string data_p){
    //clear world
    collision.clear();
    portals.clear();

    //clear surface
    SDL_FreeSurface(image);
    //load world image
    image = IMG_Load(img_p.c_str());
    //load world data
    std::fstream data;
    data.open(data_p, std::ios::in);
    //error check

    //refresh image
    initGraphics();

    if(!data.is_open()){
        std::cout<<"ERR: cant open world data file1";
    }
    std::string t;
    //foreach line i data file
    while(std::getline(data, t)){
        char op = t.c_str()[0];
        switch(op){
            case 'c': //coliision
            {
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
            case 'p': //portal
            {
                float xx = std::strtof(split(t).at(1).c_str(), nullptr);
                float yy = std::strtof(split(t).at(2).c_str(), nullptr);
                float ww = std::strtof(split(t).at(3).c_str(), nullptr);
                float hh = std::strtof(split(t).at(4).c_str(), nullptr);
                std::string iPath = split(t).at(5);
                std::string dPath = split(t).at(6);
                std::string xoff = split(t).at(7);
                std::string yoff = split(t).at(8);
                Collider portal(
                    Vector2(xx, yy),
                    Vector2(ww, hh)
                );
                portal.setData(
                    iPath + '-' +
                    dPath + '-' +
                    xoff + '-' +
                    yoff + '-'
                );
                portal.setIsTrigger(true);
                portals.push_back(portal);
            }
        }
    }
       
    data.close();
}

void World::interpretPortalPass(int i){
    std::string i_p = split(portals.at(i).getData()).at(0);
    std::string d_p = split(portals.at(i).getData()).at(1);
    std::string x_o = split(portals.at(i).getData()).at(2);
    std::string y_o = split(portals.at(i).getData()).at(3);
    offset = Vector2(
        std::strtof(x_o.c_str(), nullptr),
        std::strtof(y_o.c_str(), nullptr)
    );
    loadWorld(i_p, d_p);
}

//this method loads the map image
void World::initGraphics(){
    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(
        nullptr, image);
}

void World::setPlayer(Collider *p){
    this->player = p;
}

void World::render(){
    if(texture == nullptr){
        texture = SDL_CreateTextureFromSurface(
            renderer, image
        );
    }   
    SDL_Rect bounds = {
        (int)(offset.x /*- player->getCenter().x*/), (int)(offset.y /*- player->getCenter().y*/), image->w, image->h
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
    for (Collider p : portals){
        p.render(renderer);
        //std::cout << p.getCol().getShape()->w;
    }
}

std::vector<Collider> World::getCollision(){
    return this->collision;
}

std::vector<Collider> World::getPortals(){
    return this->portals;
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