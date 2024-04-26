//
//  config.h
//  ClassNotes 3.20
//
//  Created by Jody Spikes on 4/3/24.
//

#ifndef config_h
#define config_h

const int SIZE = 500;
const int SIDE = 25;

const int NUM_TYPES = 10;
const int dim = SIZE/SIDE;
enum objType {EMPTY, WATER, GRASS, RABBIT, FOX, SNAKE, DEER, WOLF, EAGLE, BEAR};
const int attackChance[NUM_TYPES] = {0, 0, 0, 1, 4, 6, 2, 6, 3, 7};


#endif /* config_h */
