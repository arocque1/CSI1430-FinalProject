#ifndef animals_h
#define animals_h
#include <string>
#include <array>

const int GAME_WIDTH = 640;
const int GAME_HEIGHT = 480;

class Animals{
private:
    int health;
    int speed;
    int hunger;
    int attack;
    bool reproduce = false;

public:
    void setHP(int hp);
    int getHP();
    void setSP(int anim);
    int getSP();
    void setHung(int anim);
    int getHung();
    void setAtt(int anim);
    int getAtt();
    void setRep(int anim);
    bool getRep();
    bool isAlive(std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH>
                 & game,const int x,const int y);

};


#endif



