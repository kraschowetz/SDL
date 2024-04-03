#include "InputHandler.h"

#include <iostream>

void InputHandler::pollEvents(SDL_Event ev){
    switch (ev.type){
        case SDL_KEYDOWN: 
        {
            bool canInsert = true;
            //check if key is present in pressed vector
            for(int i = 0; i < keysPressed.size(); i++){
                if(keysPressed.at(i) == ev.key.keysym.sym){
                    canInsert = false;
                }
            }
            //if key can be inserted: insert key
            if(canInsert){
                keysPressed.push_back(ev.key.keysym.sym);
                keysJustPressed.push_back(ev.key.keysym.sym);
            }
        break;
        }

        case SDL_KEYUP:
            //get released key position in pressed vector
            for(int i = 0; i < keysPressed.size(); i++){
                if (keysPressed.at(i) == ev.key.keysym.sym){
                    // add key to just released vector
                    keysJustReleased.push_back(
                        keysPressed.at(i)
                    );
                    //remove key from pressed vector
                    keysPressed.erase(
                        keysPressed.begin() + i
                    );
                }
            }
        break;
    }
}

void InputHandler::update(){
    // empty justPressed & justReleased vectors
    if(!keysJustPressed.empty()){
        keysJustPressed.clear();
    }
    if (!keysJustReleased.empty()){
        keysJustReleased.clear();
    }
}

bool InputHandler::getKeyPressed(int k){
    for(int i = 0; i < keysPressed.size(); i++){
        if(keysPressed.at(i) == k){
            return true;
        }
    }
    return false;
}

bool InputHandler::getKeyJustPressed(int k){
    for (int i = 0; i < keysJustPressed.size(); i++){
        if (keysJustPressed.at(i) == k){
            return true;
        }
    }
    return false;
}

bool InputHandler::getKeyJustReleased(int k){
    std::cout << "size:" << keysJustReleased.size() << "\n";
    for(int i = 0; i < keysJustReleased.size(); i++){
        if(keysJustReleased.at(i) == k){
            return true;
        }
    }
    return false;
}