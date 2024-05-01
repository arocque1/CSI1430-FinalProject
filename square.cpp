//Jack Fontenot
//Lademi Aromolaran
//Alex Rocque
//Mason Crippen
//Jody Spikes
//Alejandra Castro

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
        case RABBIT: _color = color(153,51,255);
            break;
        case FOX: _color = color(255,128,0);
            break;
        case SNAKE: _color = color(255,255,0);
            break;
        case DEER: _color = color(139,69,19);
            break;
        case WOLF: _color = color(150,150,150);
            break;
        case EAGLE: _color = color(204,0,102);
            break;
        case BEAR: _color = color(0,0,0);
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
        case RABBIT: _color = color(153,51,255);
            break;
        case FOX: _color = color(255,128,0);
            break;
        case SNAKE: _color = color(255,255,0);
            break;
        case DEER: _color = color(139,69,19);
            break;
        case WOLF: _color = color(150,150,150);
            break;
        case EAGLE: _color = color(204,0,102);
            break;
        case BEAR: _color = color(0,0,0);
            break;
    }
}

bool Square::interact(Square& other, bool sameType){
    bool reproduce = false;
    bool attack = false;
    int newHP;
    int randNum = rand() % 10;

    if(sameType && other.type > GRASS && other.type == type){
            cout << "reproducing" << endl;
            if(randNum <= animal.getReproduction()){
                reproduce = true;
            }
            else if(randNum <= attackChance[type]){
                attack = true;
            }
    }
    else{
        if(other.type > GRASS){
            if(randNum <= attackChance[type]){
                attack = true;
            }
        }
        else if(other.type != EMPTY){
            animal.addHunger();
        }
    }

    if(attack){
        newHP = animal.getHP() - other.animal.getAttack();
        if(newHP <= 0){
            type = other.type;
            _color = other._color;
            animal = other.animal;
            newHP = other.animal.getHP() - animal.getAttack();
            other.clear();
        }
        animal.setHP(newHP);
        cout << "attack" << endl;
    }


    return reproduce;
}
