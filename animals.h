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

/*
 * description: accessor for hp
 * return: int
 * precondition: the animal exists
 * postcondition: returns the animal's hp
 *
*/
    int getHP();

/*
 * description: accessor for hunger
 * return: int
 * precondition: the animal exists
 * postcondition: returns the animal's hunger
 *
*/
    int getHunger();

/*
 * description: accessor for attack power
 * return: int
 * precondition: the animal exists
 * postcondition: returns the animal's attack power
 *
*/
    int getAttack();

/*
 * description: accessor for reproduction
 * return: int
 * precondition: the animal exists
 * postcondition: returns the animal's reproduction
 *
*/
    int getReproduction();

/*
 * description: mutator for animal type
 * return: none
 * precondition: the animal exists
 * postcondition: returns the animal's type
 *
*/
    void setType(objType);

/*
 * description: Mutator for x coordinate
 * return: int
 * precondition: the animal exists
 * postcondition: returns the animal's new x coordinate
 *
*/
    int moveX(int col, int dim);

/*
 * description: Mutator for y coordinate
 * return: int
 * precondition: the animal exists
 * postcondition: returns the animal's new y coordinate
 *
*/
    int moveY(int row, int dim);

//Constructor
    void setStats();

/*
 * description: clears animal
 * return: none
 * precondition: the animal existed
 * postcondition: Clears the square of any animals
 *
*/
    void clear();

/*
 * description: decrement hunger
 * return: none
 * precondition: the animal exists
 * postcondition: subtracts the animal's hunger by 1
 *
*/
    void incrimentHunger();

/*
 * description: incriment hunger
 * return: none
 * precondition: the animal exists
 * postcondition: increases the animal's hunger by 1
 *
*/
    void addHunger();

/*
 * description: sets the animal's hp
 * return: none
 * precondition: the animal exists
 * postcondition: sets the animals hp to newHP
 *
*/
    void setHP(int);
};


#endif



