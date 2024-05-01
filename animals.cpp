//Jack Fontenot
//Lademi Aromolaran
//Alex Rocque
//Mason Crippen
//Jody Spikes
//Alejandra Castro
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

int Animals::getHP(){
    return health;
}


int Animals::getHunger(){
    return hunger;
}

int Animals::getAttack(){
    return attack;
}

int Animals::getReproduction() {
    return reproduce;
}


void Animals::setType(objType t){
    type = t;
}

int Animals::moveX(int col, int dim){
    int newX;
    do {
        moveDir dir = moveDir(rand() % 3);
        int xmag = (rand() % speed) + 1;

        switch (dir) {
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
    }while(newX >= dim || newX <= 0);
    return newX;
}

int Animals::moveY(int row, int dim){
    int newY;
    do {
        moveDir dir = moveDir(rand() % 3);
        int ymag = (rand() % speed) + 1;

        switch (dir) {
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
    }while(newY >= dim || newY <= 0);
    return newY;
}

void Animals::setStats() {
    switch(type) {
        case RABBIT:
            health = 4;
            speed = 5;
            hunger = 10;
            attack = 1;
            reproduce = 6;
            break;
        case FOX:
            health = 8;
            speed = 4;
            hunger = 14;
            attack = 8;
            reproduce = 2;
            break;
        case SNAKE:
            health = 8;
            speed = 3;
            hunger = 24;
            attack = 5;
            reproduce = 3;
            break;
        case DEER:
            health = 12;
            speed = 2;
            hunger = 12;
            attack = 1;
            reproduce = 5;
            break;
        case WOLF:
            health = 12;
            speed = 4;
            hunger = 14;
            attack = 7;
            reproduce = 2;
            break;
        case EAGLE:
            health = 16;
            speed = 5;
            hunger = 12;
            attack = 6;
            reproduce = 3;
            break;
        case BEAR:
            health = 30;
            speed = 2;
            hunger = 16;
            attack = 12;
            reproduce = 1;
            break;
        default:
            health = 2;
            speed = 2;
            hunger = 2;
            attack = 2;
            reproduce = 2;
            break;
    }
}

void Animals::clear(){
    health = 0;
    speed = 0;
    hunger = 0;
    attack = 0;
    reproduce = 0;
    type = EMPTY;
}

void Animals::incrimentHunger(){
    hunger--;
}

void Animals::addHunger(){
    hunger++;
}

void Animals::setHP(int newHP){
    health = newHP;
}



