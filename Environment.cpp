#include "Environment.h"

void setGrass(Square data[][dim], SDL_Plotter& g){
    int setGrass;

    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            if(data[r][c].type == EMPTY){
                setGrass = rand()%10;
                if(setGrass == 0){
                    data[r][c].type = GRASS;

                }

            }
            data[r][c].update(r, c);
            data[r][c].draw(g);
        }
    }

}

void setWater(Square data[][dim], SDL_Plotter& g){
    int setWater;
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            if(data[r][c].type == EMPTY){
                setWater = rand() % 50;
                if(setWater == 0){
                    data[r][c].type = WATER;

                }

            }
            data[r][c].update(r, c);
            data[r][c].draw(g);
        }
    }

}
