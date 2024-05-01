#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "config.h"
#include "SDL_Plotter.h"
#include "square.h"
#include "grid.h"
#include "animals.h"
#include "Environment.h"

#include "SDL_Plotter.cpp"
#include "square.cpp"
#include "grid.cpp"
#include "animals.cpp"
#include "Environment.cpp"

string animalNames[NUM_TYPES] = {"EMPTY", "WATER", "GRASS", "RABBIT", "FOX",
                                 "SNAKE", "DEER", "WOLF", "EAGLE","BEAR"};

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
    int totalAnimals[NUM_TYPES];
    int numReproduce = 0;
    Animals test;
    Square data[dim][dim];
    Square tempData[dim][dim];
    stringstream action;
    string actionLine;
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


    cout << "Welcome to the Environment Simulator." << endl;
    cout << "Click on a square to change it's type" << endl;
    cout << "White   = Empty"  << endl;
    cout << "Blue    = Water"  << endl;
    cout << "Green   = Grass"  << endl;
    cout << "Purple  = Rabbit" << endl;
    cout << "Orange  = Fox"    << endl;
    cout << "Yellow  = Snake"  << endl;
    cout << "Brown   = Deer"   << endl;
    cout << "Grey    = Wolf"   << endl;
    cout << "Magenta = Eagle"  << endl;
    cout << "Black   = Bear"   << endl;

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
            action.clear();

            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    for(int types = 0; types < NUM_TYPES; types++){
                        totalAnimals[types] = 0;
                    }
                }
            }

            //Move animals
            for(int i = 0; i < dim; i++){ //Rows
                for(int j = 0; j < dim; j++){ //Columns

                    if(data[i][j].type > GRASS){
                        totalAnimals[data[i][j].type]++;
                    }

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
                                numReproduce++;
                                action <<animalNames[tempData[newY][newX].type]
                                    << " Reproduced at (" << dim-newX << ", "
                                    << dim-newY << ")  ";
                            }
                        }
                        tempData[newY][newX].animal.incrimentHunger();

                        if(tempData[newY][newX].animal.getHunger() <= 0){
                            deadCount++;
                            action << animalNames[tempData[newY][newX].type]
                                << " Died at (" << dim-newX << ", " << dim-newY
                                << ")  ";

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

            cout << setw(12) << "Rabbits" << setw(12) << "Foxes"
                 << setw(12) << "Snakes"  << setw(12) << "Dears"
                 << setw(12) << "Wolfs"   << setw(12) << "Eagles"
                 << setw(12) << "Bears";
            cout << endl;
            for(int types = 3; types < NUM_TYPES; types++){
                cout << setw(12) << totalAnimals[types];
            }
            cout << endl;
            cout << "Dead Total: " << deadCount << "     Reproduced Total: " << numReproduce;
            cout << endl;
            getline(action, actionLine);
            cout << actionLine;
            for(int i = 0; i < 26; i++){
                cout << endl;
            }

            g.Sleep(2000);

        }

        drawGrid(g);
        g.update();



    }



    return 0;
}
