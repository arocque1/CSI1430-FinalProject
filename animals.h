//Jack Fontenot
//Lademi Aromolaran
//Alex Rocque
//Mason Crippen
//Jody Spikes
//Alejandra Castro
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
    int reproduce = 2;
    objType type;
    enum moveDir {POS, NEG, NA};


public:

    int getHP();
    int getSP();
    int getHunger();
    int getAttack();
    int getReproduction();
    void setType(objType);
    int moveX(int col, int dim);
    int moveY(int row, int dim);
    void setStats();
    void clear();
    void incrimentHunger();
    void addHunger();
    void setHP(int);
};


#endif



