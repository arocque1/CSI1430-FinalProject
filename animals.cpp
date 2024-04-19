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


bool Animals::isAlive(std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH>& game,
             const int x,
             const int y)
{
    
    int alive = 0;
    
    //testing the left position
    if(x>0 && game[x-1][y] == 1) alive += 1;
    //testing the right
    if(x<GAME_WIDTH && game[x+1][y] == 1) alive += 1;
    //testing the top
    if(y>0 && game[x][y-1] == 1) alive += 1;
    //testing the bottom
    if(y<GAME_HEIGHT && game[x][y+1] == 1) alive += 1;
    
    //testing top left
    if(y > 0 && x > 0 && game[x-1][y-1] == 1) alive += 1;
    //testing top right
    if(y > 0 && x < GAME_WIDTH && game[x+1][y-1] == 1) alive += 1;
    //testing bottom left
    if(y < GAME_HEIGHT && x > 0 && game[x-1][y+1] == 1) alive += 1;
    //testing bottom right
    if(y < GAME_HEIGHT && x < GAME_WIDTH && game[x+1][y+1] == 1) alive += 1;
    
    //live and fewer than 2 die
    if(game[x][y] == 1 && alive < 2) return false;
    //alive and 2 or 3 then live
    if(game[x][y] == 1 && (alive == 2 || alive == 3)) return true;
    //more than 3 alive then die
    if(alive > 3) return false;
    //3 alive and point is dead, come to life
    if(game[x][y] == 0 && alive == 3) return true;
    
    return false;
}

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

void Animals::setHung(int anim){
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

int Animals::getHung(){
    return hunger;
}

void Animals::setAtt(int anim){
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

int Animals::getAtt(){
    return attack;
}

void Animals::setRep(int anim){
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

bool Animals::getRep(){
    return reproduce;
}
