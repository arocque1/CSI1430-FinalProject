#ifndef animals_h
#define animals_h
#include <string>

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

};


#endif



