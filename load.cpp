//
//  load.cpp
//  ClassNotes 3.20
//
//  Created by Jody Spikes on 4/3/24.
//

#include <stdio.h>
#include "load.h"

bool displayLoadingScreen(SDL_Plotter& g) {
    g.clear(); // Clear the screen
    g.drawText("Welcome!", SIZE / 2 - 50, SIZE / 2 - 50, 30, 255, 255, 255); // Display welcome message
    g.drawText("Press P to Play or Q to Quit", SIZE / 2 - 150, SIZE / 2 + 50, 20, 255, 255, 255); // Display play/quit message

    g.update(); // Update the screen

    while (true) {
        if (g.kbhit()) {
            char key = g.getKey();
            if (key == 'p' || key == 'P') {
                return true; // User chose to play
            } else if (key == 'q' || key == 'Q') {
                return false; // User chose to quit
            }
        }

        if (g.mouseClick()) {
            point p = g.getMouseClick();
            // Check if the user clicked on the "Play" button
            if (p.x >= SIZE / 2 - 50 && p.x <= SIZE / 2 + 50 && p.y >= SIZE / 2 + 20 && p.y <= SIZE / 2 + 70) {
                return true; // User chose to play
            }
            // Check if the user clicked on the "Quit" button
            else if (p.x >= SIZE / 2 - 50 && p.x <= SIZE / 2 + 50 && p.y >= SIZE / 2 + 80 && p.y <= SIZE / 2 + 130) {
                return false; // User chose to quit
            }
        }
    }
}
