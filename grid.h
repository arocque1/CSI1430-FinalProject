//
//  grid.h
//  ClassNotes 3.20
//
//  Created by Jody Spikes on 4/3/24.
//

#ifndef grid_h
#define grid_h

#include "SDL_Plotter.h"
#include "config.h"


void drawLine(int x1, int y1, int x2, int y2, int R, int G, int B, SDL_Plotter& g);
double slope(int x1, int y1, int x2, int y2);
double y_intercept(int x1, int y1, int x2, int y2);
void drawGrid(SDL_Plotter& g);
bool hasSlope(int x1, int y1, int x2, int y2);
void drawSquare(int x, int y, int R, int G, int B, SDL_Plotter& g);

#endif /* grid_h */
