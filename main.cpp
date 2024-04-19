#include <iostream>
#include <ctime>
#include "config.h"
#include "SDL_Plotter.h"
#include "square.h"
#include "grid.h"
#include "animals.h"
using namespace std;

int main(int argc, char** argv) {

    SDL_Plotter g(SIZE, SIZE);

    int dim = SIZE/SIDE;
    int clock = 0;
    bool setup = true;
    int newPos;
    int newX;
    int newY;
    Square data[dim][dim];
    //Init Data
    for(int r = 0; r < dim; r++){
        for(int c = 0; c < dim; c++){
            data[r][c].setRow(r);
            data[r][c].setCol(c);
        }
    }
    srand(time(0));

    cout << "WELCOME TO CONWAY'S GAME OF LIFE!" << endl;

    //Issue: when you make the while loop condition to anything but !g.getQuit(),
    //the plot instantly crashes and doesn't respond.
    while(!g.getQuit())
    {
        if(g.kbhit()){
            if(g.getKey() == 'r'){
                setup = false;
            }
        }

        if(setup) {

            if (g.mouseClick()) {
                point p = g.getMouseClick();
                cout << p.x / SIDE << " " << p.y / SIDE << endl;
                data[p.y / SIDE][p.x / SIDE].click();

            }
            for (int r = 0; r < dim; r++) {
                for (int c = 0; c < dim; c++) {
                    data[r][c].draw(g);
                }
            }

        }
        else{

            clock++;
            //Move animals
            for(int i = 0; i < dim; i++){
                cout << i;
                for(int j = 0; j < dim; j++){
                    if(data[i][j].type != EMPTY){
                        newX = data[i][j].animal.moveX(j);
                        newY = data[i][j].animal.moveY(i);
                        data[newY][newX] = data[i][j];
                        data[i][j].clear();

                    }

                    data[i][j].draw(g);
                }

            }
            cout << endl;
            //Add grass, check for attacks, reproduce, etc.
            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    //if(data[i][j].type != EMPTY){
                    //  data[i][j].animal.move(i, j);
                    //}
                    data[i][j].draw(g);
                }
            }

        }

        drawGrid(g);
        g.update();



    }



    return 0;
}
