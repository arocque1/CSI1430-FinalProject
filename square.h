//
//  square.h
//  ClassNotes 3.20
//
//  Created by Jody Spikes on 4/3/24.
//

#ifndef square_h
#define square_h
#include "SDL_Plotter.h"
#include "config.h"

class Square {
private:
    int row, col;
    objType type;
    color _color;

public:
    Square();
    void draw(SDL_Plotter& g);
    void setRow(int);
    void setCol(int);
    void click();
};

#endif /* square_h */
