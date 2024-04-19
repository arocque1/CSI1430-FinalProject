//
//  square.h
//  ClassNotes 3.20
//
//  Created by Jody Spikes on 4/3/24.
//

#ifndef square_h
#define square_h
#include "SDL_Plotter.h"
#include "animals.h"

struct Square {
    objType type;
    color _color;
    int row, col;
    Animals animal;

    Square();
    void draw(SDL_Plotter& g);
    void setRow(int);
    void setCol(int);
    void click();
    void clear();
};

#endif /* square_h */
