#ifndef ENVIORONMENT_H_INCLUDED
#define ENVIORONMENT_H_INCLUDED

#include "config.h"
#include "square.h"

/*
 * description: generate grass
 * return: none
 * precondition: data and g are valid
 * postcondition: sets the grass
 *
*/
void setGrass(Square data[][dim], SDL_Plotter& g);

/*
 * description: generate water
 * return: none
 * precondition: data and g are valid
 * postcondition: sets the water
 *
*/
void setWater(Square data[][dim], SDL_Plotter& g);


#endif // ENVIORONMENT_H_INCLUDED
