//Jack Fontenot
//Lademi Aromolaran
//Alex Rocque
//Mason Crippen
//Jody Spikes
//Alejandra Castro

#ifndef grid_h
#define grid_h

#include "SDL_Plotter.h"
#include "config.h"

/*
 * description: Draws a line between two points on an SDL_Plotter window.
 * return: void
 * precondition: Valid SDL_Plotter object.
 * postcondition: Draws line between (x1, y1) and (x2, y2).
*/
void drawLine(int x1, int y1, int x2, int y2, int R, int G, int B, SDL_Plotter& g);

/*
 * description: Calculates slope of a line.
 * return: double
 * precondition: Distinct points (x1 ≠ x2).
 * postcondition: Returns slope of line through (x1, y1) and (x2, y2).
*/
double slope(int x1, int y1, int x2, int y2);

/*
 * description: Calculates y-intercept of a line.
 * return: double
 * precondition: Distinct points (x1 ≠ x2).
 * postcondition: Returns y-intercept of line through (x1, y1) and (x2, y2).
*/
double y_intercept(int x1, int y1, int x2, int y2);

/*
 * description: Draws a grid on an SDL_Plotter window.
 * return: void
 * precondition: Valid SDL_Plotter object.
 * postcondition: Draws grid on window.
*/
void drawGrid(SDL_Plotter& g);

/*
 * description: Checks if points have a slope.
 * return: bool
 * precondition: None
 * postcondition: Returns true if x1 ≠ x2.
*/
bool hasSlope(int x1, int y1, int x2, int y2);

/*
 * description: Draws a square on an SDL_Plotter window.
 * return: void
 * precondition: Valid SDL_Plotter object.
 * postcondition: Draws square at specified position.
*/
void drawSquare(int x, int y, int R, int G, int B, SDL_Plotter& g);

#endif /* grid_h */
