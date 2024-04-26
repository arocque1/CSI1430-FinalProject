#include <iostream>
#include <ctime>
#include "config.h"
#include "SDL_Plotter.h"
#include "square.h"
#include "grid.h"
#include "animals.h"
#include "Environment.h"
#include <unistd.h>


using namespace std;

int main(int argc, char** argv) {

    SDL_Plotter g(SIZE, SIZE);

    int clock = 0;
    bool setup = true;
    bool reproduce;
    int newPos;
    int newX;
    int newY;
    int spawnX;
    int spawnY;
    int checkX;
    int checkY;
    bool sameType;
    int deadCount = 0;
    int numRabbits = 0;
    Animals test;
    Square data[dim][dim];
    Square tempData[dim][dim];
    //Init Data
    for(int r = 0; r < dim; r++){
        for(int c = 0; c < dim; c++){
            data[r][c].setRow(r);
            data[r][c].setCol(c);
        }
    }
    srand(time(0));
    objType T;
    color Tcol;


    while(!g.getQuit()){
        if(g.kbhit()){
            if(g.getKey() == 'r'){
                setup = false;
            }
        }

        if(setup) {

            if (g.mouseClick()) {
                point p = g.getMouseClick();
                //cout << p.x / SIDE << " " << p.y / SIDE << endl;
                data[p.y / SIDE][p.x / SIDE].click();
                data[p.y / SIDE][p.x / SIDE].animal.setStats();

            }
            for (int r = 0; r < dim; r++) {
                for (int c = 0; c < dim; c++) {
                    data[r][c].draw(g);
                    //data[r][c].setHunger();
                }
            }

        }
        else{

            clock++;
            //Move animals
            for(int i = 0; i < dim; i++){ //Rows
                for(int j = 0; j < dim; j++){ //Columns
                    sameType = false;
                    if(data[i][j].type > GRASS){
                        newX = data[i][j].animal.moveX(j, dim);
                        newY = data[i][j].animal.moveY(i, dim);

                        tempData[newY][newX] = data[i][j];
                        tempData[newY][newX].update(newY, newX);

                        if(data[newY][newX].type != EMPTY){

                            for(int i = 0; i < 100; i++){
                                switch(rand() % 2){
                                    case 1:
                                        checkX = -1 + newX;
                                        break;
                                    case 0:
                                        checkX = 1 + newX;
                                        break;
                                }
                                switch(rand() % 2){
                                    case 1:
                                        checkY = -1 + newY;
                                        break;
                                    case 0:
                                        checkY = 1 + newY;
                                        break;
                                }

                                if(tempData[newY][newX].type == (data[checkY][checkX].type)){
                                    sameType = true;
                                    cout << newY << ":" << newX << endl;
                                    break;
                                }
                            }
                            reproduce = tempData[newY][newX].interact(data[checkY][checkX],sameType);

                            if(reproduce){
                                do{
                                    spawnX = (rand() % 3) - 1 + newX;
                                    spawnY = (rand() % 3) - 1 + newY;
                                }while((tempData[spawnY][spawnX]).type != EMPTY);
                                tempData[spawnY][spawnX] = data[newY][newX];
                                tempData[spawnY][spawnX].animal.setStats();
                                numRabbits++;
                                cout << "Reproduced. Total: " << numRabbits << endl;
                            }
                        }
                        tempData[newY][newX].animal.incrimentHunger();

                        if(tempData[newY][newX].animal.getHunger() <= 0){
                            deadCount++;
                            cout << deadCount << " DEAD" << endl;
                            tempData[newY][newX].clear();
                        }

                        data[i][j].clear();
                        data[i][j].draw(g);
                    }

                }

            }

            setGrass(data, g);
            setWater(data, g);


            //Display
            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    if(tempData[i][j].type != EMPTY){
                        data[i][j] = tempData[i][j];
                        data[i][j].draw(g);
                    }
                    tempData[i][j].clear();
                }
            }



            sleep(1);

        }

        drawGrid(g);
        g.update();



    }



    return 0;
}
