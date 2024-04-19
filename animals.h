#ifndef animals_h
#define animals_h
#include <string>
<<<<<<< HEAD
#include <vector>
#include "config.h"
=======
#include <array>

const int GAME_WIDTH = 640;
const int GAME_HEIGHT = 480;
>>>>>>> 0f19e05209db1496c45f015ae0ad9dace4f75343

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
    void setHP(int hp);
    int getHP();
    void setSP(int anim);
    int getSP();
<<<<<<< HEAD
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
=======
    void setHung(int anim);
    int getHung();
    void setAtt(int anim);
    int getAtt();
    void setRep(int anim);
    bool getRep();
    bool isAlive(std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH>
                 & game,const int x,const int y);

>>>>>>> 0f19e05209db1496c45f015ae0ad9dace4f75343
};


#endif



