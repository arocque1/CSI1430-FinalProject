#ifndef animals_h
#define animals_h
#include <string>
#include <vector>
#include "config.h"

class Animals{
private:
    int health = 2;
    int speed = 2;
    int hunger = 2;
    int attack = 2;
    bool reproduce = false;
    objType type;
    enum moveDir {POS, NEG, NA};


public:
    void setHP(int anim);
    int getHP();
    void setSP(int anim);
    int getSP();
    void setHunger(int anim, int clock);
    int getHunger();
    void setAttack(int anim);
    int getAttack();
    void setReproduction(int anim);
    bool getReproduction();
    void setType(objType);
    int moveX(int col, int dim);
    int moveY(int row, int dim);
    void setStats();
    void clear();
};


#endif



