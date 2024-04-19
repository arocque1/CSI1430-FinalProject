#ifndef animals_h
#define animals_h
#include <string>
#include <vector>
#include "config.h"

class Animals{
private:
    int health;
    int speed = 2;
    int hunger;
    int attack;
    bool reproduce = false;
    objType type;
    enum moveDir {POS, NEG, NA};


public:
    void setHP(int anim);
    int getHP();
    void setSP(int anim);
    int getSP();
    void setHunger(int anim);
    int getHunger();
    void setAttack(int anim);
    int getAttack();
    void setReproduction(int anim);
    bool getReproduction();
    void setType(objType);
    int moveX(int col);
    int moveY(int row);
    void clear();
};


#endif



