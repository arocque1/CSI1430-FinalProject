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

void Square::update(int Nrow, int Ncol){
    row = Nrow;
    col = Ncol;
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
}

bool Square::interact(Square other){
    bool reproduce;
    bool attack;
    int newHP;
    if(other.type == type){
        do {
            //Roll a chance if the animals will reproduce or attack eachother(2 separate functions)
            //The while loop makes it so that it keeps rolling a chance until
            //They are both not true

            /*
            if(The chance of reproduction is > than something)){
                reproduce = true;
            }
            if(The chance of attacking is > than something)){
                attack = true;
            }
            */
        }while(reproduce && attack);
    }
    else{
        if(other.type > GRASS){
            attack = true;
        }
        else{
            switch(other.type){
                case WATER:
                    //Do something with adding health or hydration
                    break;
                case GRASS:
                    //Do something with adding health
                    break;

            }
        }
    }

    if(attack){
        newHP = animal.getHP() - other.animal.getAttack();
        if(newHP < 0){
            type = other.type;
            _color = other._color;
            animal = other.animal;
            newHP = other.animal.getHP() - animal.getAttack();
        }
        animal.setHP(newHP);
    }


    return reproduce;
}
