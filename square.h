//Jack Fontenot
//Lademi Aromolaran
//Alex Rocque
//Mason Crippen
//Jody Spikes
//Alejandra Castro

#ifndef square_h
#define square_h
#include "SDL_Plotter.h"
#include "config.h"
#include "animals.h"

struct Square {

    objType type;
    color _color;
    int row, col;
    Animals animal;


    //Constructor
    Square();

    /*
    * description: Draws the square on an SDL_Plotter window.
    * return: void
    * precondition: SDL_Plotter object is initialized and valid.
    * postcondition: Square is drawn on the SDL_Plotter window.
    */
    void draw(SDL_Plotter& g);

    /*
    * description: Sets the row of the square.
    * return: void
    * precondition: None
    * postcondition: Row of the square is set to the specified value.
    */
    void setRow(int);

    /*
    * description: Sets the column of the square.
    * return: void
    * precondition: None
    * postcondition: Column of the square is set to the specified value.
    */
    void setCol(int);

    /*
    * description: Simulates a click on the square, changing its type and color.
    * return: void
    * precondition: None
    * postcondition: Square's type is changed based on the current type, and its color is updated accordingly.
    */
    void click();

    /*
    * description: Clears the square to empty.
    * return: void
    * precondition: None
    * postcondition: Square is now has a empty type.
    */

    void clear();

    /*
    * description: Updates the square to current color.
    * return: void
    * precondition: The row and columns.
    * postcondition: Square is now updated to correct color.
    */

    void update(int, int);

    /*
    * description: Interacts with two squares.
    * return: bool
    * precondition: The square and the square it is landing on.
    * postcondition: returns the interaction
    */

    bool interact(Square&, bool);
};

#endif /* square_h */
