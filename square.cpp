//
//  square.cpp
//  ClassNotes 3.20
//
//  Created by Jody Spikes on 4/3/24.
//

#include <stdio.h>
#include "square.h"

Square::Square(){
   row = 0;
   col = 0;
   type = EMPTY;
   _color = color(255,255,255);
};

void Square::draw(SDL_Plotter& g){
    for(int r = 0; r < SIDE; r++){
        for(int c = 0; c < SIDE; c++){
            g.plotPixel(c + SIDE*col, r + SIDE*row, _color);
        }
    }
}

void Square::setRow(int r){
    row = r;
}

void Square::setCol(int c){
    col = c;
}

void Square::click(){
    type = static_cast<objType>(static_cast<int>((type + 1) % NUM_TYPES));
    switch(type){
        case EMPTY: _color = color(255,255,255);
            break;
        case GRASS: _color = color(0,255,0);
            break;
        case WATER: _color = color(0,0,255);
            break;
        case RABBIT: _color = color(100,100,100);
            break;
        case FOX: _color = color(255,0,0);
            break;



    }
    animal.setType(type);
}

void Square::clear(){
    type = EMPTY;
    _color = color(255, 255, 255);
    animal.clear();
}
