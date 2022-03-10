/* display.h
*  Header file that displays game menus and statistics. These *functions will be used to provide text interface for game
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display {
  public:
    // Constructors
    Display();

    // Display functions
    void displayGuesses(std::string guess, std::string answer);
    void displayStartMenu(); // display menu function
    void displayStatistics(); // print report
    void displayEndGame(bool isCorrect, std::string answer); // win or lose
    void displayPlayAgain();
    int letterInWord(int letterIndex, char guessChar, std::string answer);
    void resetStringOfGuesses();
    void incrNumOfGuesses(int numOfGueses);
    void incrTotalGames();
    void incrStreak();
    void resetStreak();

    // Define colors
    static const std::string RESET;
    static const std::string BOLD;
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string GREY;

  private:
    // Running numbers throughout program

    static int mTotalGames; // num of calculations
    static int mStreak; // track running sum

    // number of times user guessed in x amount of gueses
    static int mNumOfGuessesIn1; 
    static int mNumOfGuessesIn2;
    static int mNumOfGuessesIn3;
    static int mNumOfGuessesIn4;
    static int mNumOfGuessesIn5;
    static int mNumOfGuessesIn6;
    static int mNumOfNoGuesses; // user used up all guesses and didn't get answer

    // Member variables
    std::string mStringOfGuesses;
};

#endif 

