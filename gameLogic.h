// gameLogic.h

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>

#include "display.h"

class GameLogic {
  public:
    // Constructors
    GameLogic();

    // Member functions
    void playGame();
    void startMenu();

  private:
    // Member variables
    Display display; // display object for displaying game
    int numOfGuesses;

    // Helper functions
    std::string generateAnswer();

    // Helpers
    bool isValidGuess(std::string guess);


};

#endif 

