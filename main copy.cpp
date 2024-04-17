#include <iostream>
#include <cmath>
#include <vector>
#include "config.h"
#include "SDL_Plotter.h"
#include "square.h"
#include "grid.h"
using namespace std;

int main(int argc, char** argv) {

    SDL_Plotter g(SIZE, SIZE);
    
    int dim = SIZE/SIDE;
    Square data[dim][dim];
    //Init Data
    for(int r = 0; r < dim; r++){
        for(int c = 0; c < dim; c++){
            data[r][c].setRow(r);
            data[r][c].setCol(c);
        }
    }
    
    cout << "WELCOME TO CONWAY'S GAME OF LIFE!" << endl;

    //Initialize based on mouseclicks
    while (!g.kbhit())
    {
        if (g.mouseClick()) {
            point p = g.getMouseClick();
            cout << p.x/SIDE << " " << p.y/SIDE << endl;
            data[p.y/SIDE][p.x/SIDE].click();
        }
        for(int r = 0; r < dim; r++){
            for(int c = 0; c < dim; c++){
                data[r][c].draw(g);
            }
        }
        
        drawGrid(g);
        g.update();


    }

    while(!g.getQuit()){
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                //call the updated object
                //objType newType
                //data[i][j].updateType(newType)
                //data[i][j].draw(g)
            }
        }


    }



    
    return 0;
}
