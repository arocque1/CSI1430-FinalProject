#include "animals.h"

/*
rabbit = 1 ////
squirrel = 2 ////
snake = 3 ///\/
deer = 4 ////
wolf = 5 ///\
fox = 6 ///\
eagle = 7 ///\/
bear = 8 ///\
*/

void Animals::setHP(int anim){
    if(anim == 1 || anim == 2){
        health = 4;
    }
    if(anim == 3 || anim == 6){
        health = 8;
    }
    else if(anim == 4 || anim == 5){
        health = 12;
    }
    else if(anim == 7){
        health = 16;
    }
    else if(anim == 8){
        health = 30;
    }
}

int Animals::getHP(){
    return health;
}

void Animals::setSP(int anim){
    if(anim == 1 || anim == 2 || anim == 7){
        speed = 5;
    }
    else if(anim == 5 || anim == 7 || anim == 4){
        speed = 4;
    }
    else if(anim == 3 || anim == 6){
        speed = 3;
    }
    else{
        speed = 2;
    }
}

int Animals::getSP(){
    return speed;
}

void Animals::setHunger(int anim){
    if(anim == 3){
        hunger = 12;
    }
    else if(anim == 1 || anim == 2){
        hunger = 3;
    }
    else if(anim == 4 || anim == 6 || anim == 7){
        hunger = 6;
    }
    else if(anim == 5){
        hunger = 7;
    }
    else if(anim == 8){
        hunger = 8;
    }
}

int Animals::getHunger(){
    return hunger;
}

void Animals::setAttack(int anim){

    if(anim == 8){
        attack = 12;
    }
    else if(anim == 7 || anim == 5){
        attack = 8;
    }
    else if(anim == 3 || anim == 6){
        attack = 5;
    }
    else{
        attack = 1;
    }
}

int Animals::getAttack(){
    return attack;
}

void Animals::setReproduction(int anim) {
    int chance;

    if(anim == 1 || anim == 2 || anim == 4){
        chance = rand() % 2;
        if(chance == 1){
            reproduce = true;
        }
    }
    else if(anim == 3 || anim == 7){
        chance = rand() % 4;
        if(chance == 1){
            reproduce = true;
        }
    }
    else if(anim == 5 || anim == 6){
        chance = rand() % 5;
        if(chance == 1){
            reproduce = true;
        }
    }
    else if(anim == 8){
        chance = rand() % 7;
        if(chance == 1){
            reproduce = true;
        }
    }
}

bool Animals::getReproduction() {
    return reproduce;
}

void Animals::setType(objType t){
    type = t;
}

int Animals::moveX(int col){
    int newX;
    moveDir dir = moveDir(rand() % 3);
    int xmag = (rand() % speed) + 1;

    switch(dir) {
        case POS:
            xmag *= 1;
            break;
        case NEG:
            xmag *= -1;
            break;
        case NA:
            xmag = 0;
            break;
    }
    newX = col + xmag;
    return newX;
}

int Animals::moveY(int row){
    int newY;
    moveDir dir = moveDir(rand() % 3);
    int ymag = (rand() % speed) + 1;

    switch(dir) {
        case POS:
            ymag *= 1;
            break;
        case NEG:
            ymag *= -1;
            break;
        case NA:
            ymag = 0;
            break;
    }
    newY = row + ymag;
    return newY;
}

void Animals::clear(){
    health = -1;
    speed = -1;
    hunger = -1;
    attack = -1;
    reproduce = false;
    type = EMPTY;
}
