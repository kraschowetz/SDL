#include "Player.h"

#include <iostream>

void Player::pollEvents(SDL_Event ev){
    switch (ev.type){
        //get key down
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym){
                case SDLK_d:    /////////////////////
                case SDLK_a:    //      case       //    
                case SDLK_s:    //  input events:  //   
                case SDLK_w:    /////////////////////

                    /*check if pressed event is present
                       in input storage             */
                    bool canInsert = true;
                    for(int i = 0; i < inputStorage.size(); i++){
                        if (inputStorage.at(i) 
                            == ev.key.keysym.sym){
                                canInsert = false;
                            }
                    }
                    //if event is nor present: insert event
                    if(canInsert){
                        inputStorage.push_back(
                            ev.key.keysym.sym
                        );
                    }
                    break;
                    
            }
        break;
        //get key up
        case SDL_KEYUP:
            switch (ev.key.keysym.sym){
            case SDLK_d:    /////////////////////
            case SDLK_a:    //      case       //
            case SDLK_s:    //  input events:  //
            case SDLK_w:    /////////////////////

                /*check if pressed event is present
                       in input storage             */
                for (int i = 0; i < inputStorage.size(); i++){
                    if (inputStorage.at(i) == ev.key.keysym.sym)
                    {   
                        //if event exists in storage: remove
                        inputStorage.erase(
                            inputStorage.begin() + i);
                    }
                }
            }
            break;
    }
}

void Player::update(float delta){
    move();
    
    //set velocity
    velocity = dir.normalized() * speed * delta;
    //apply velocity
    position += velocity;

    //apply velocity in drawable rect
    rect.x = position.x;
    rect.y = position.y;
}

void Player::render(SDL_Renderer *r){
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawRect(r, &rect);
}

void Player::move(){
    /*
        read inputStorage;
        convert data in inputStorage to direction Vector2
    */
    dir = Vector2(0.f, 0.f);
    for(int i = 0; i < inputStorage.size(); i++){
        if(inputStorage.at(i) == SDLK_d){
            dir.x += 1;
        }
        if (inputStorage.at(i) == SDLK_a){
            dir.x += -1;
        }
        if (inputStorage.at(i) == SDLK_s){
            dir.y += 1;
        }
        if (inputStorage.at(i) == SDLK_w){
            dir.y += -1;
        }
    }
}