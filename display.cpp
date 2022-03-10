// display.cpp

#include <iostream>
#include <string>
#include <algorithm>

#include "display.h"

using namespace std;

// Constructors
// default constructor
Display::Display(){
  // empty
}

// Static variables
int Display::mTotalGames;
int Display::mStreak;
int Display::mNumOfGuessesIn1;
int Display::mNumOfGuessesIn2;
int Display::mNumOfGuessesIn3;
int Display::mNumOfGuessesIn4;
int Display::mNumOfGuessesIn5;
int Display::mNumOfGuessesIn6;
int Display::mNumOfNoGuesses;

// Colors
const std::string Display::RESET = "\x1B[0m";
const std::string Display::BOLD = "\x1B[1m";
const std::string Display::RED = "\x1B[41m";
const std::string Display::GREEN = "\x1B[42m";
const std::string Display::YELLOW = "\x1B[103m";
const std::string Display::GREY = "\x1B[100m";

// Display functions
// COMPLETED
void Display::displayStartMenu() { // start menu
  cout << endl;
  cout << "Welcome to a text based Wordle copycat in C++!" << endl;
  cout << "Based off of original game by Josh Wardle." << endl;
  cout << "https://www.nytimes.com/games/wordle/index.html" << endl;
  cout << endl;
  cout << "Start the game by slecting an option below: " << endl;
  cout << "(R)andom word" << endl;
  cout << "(D)isplay statistics" << endl;
  cout << "(Q)uit" << endl;
  cout << endl;
  cout << BOLD;
  cout << "Selection: ";
  cout << RESET;
}

// Display career user statistics
// TODO set up trackers (write to file?)
void Display::displayStatistics() { 
  cout << "Some statistics of your games..." << endl;
  cout << "Total number of games played: " << mTotalGames << endl;
  cout << "Current streak: " << mStreak << endl;
  cout << "Number of guesses in 1: " << mNumOfGuessesIn1 << endl;
  cout << "Number of guesses in 2: " << mNumOfGuessesIn2 << endl;
  cout << "Number of guesses in 3: " << mNumOfGuessesIn3 << endl;
  cout << "Number of guesses in 4: " << mNumOfGuessesIn4 << endl;
  cout << "Number of guesses in 5: " << mNumOfGuessesIn5 << endl;
  cout << "Number of guesses in 6: " << mNumOfGuessesIn6 << endl;
  cout << "Number of unsuccessful games: " << mNumOfNoGuesses << endl;
}

// Display whether user guessed correct word or if they ran out of guesses display answer
// COMPLETED
void Display::displayEndGame(bool isCorrect, std::string answer) {
  transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
  
  cout << BOLD;
  if (isCorrect) {
    cout << "\nCorrect!\n" << endl;
  } else {
    cout << "\nIncorrect, better luck next time!" << endl;
    cout << "The answer was: " << endl;
    cout << endl;
    
    cout << GREEN;
    for (int i = 0; i < answer.length(); i++) {
      cout << " " << answer[i] << " ";
    }
    cout << RESET;
    
    cout << endl;
    cout << endl;
  } 
  cout << RESET;
}

// Display guesses grid and what letters match in guess
// TODO: Says duplicate when not (if 1 e in word and 2 e in guess both are yellow in prinout)
void Display::displayGuesses(std::string guess, std::string answer) {
  int locationVal = -1;
  // convert guess and answer to uppercase
  transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
  transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

  // print letters for grid
  cout << endl;
  for (int i = 0; i < guess.length(); i++) {
    locationVal = letterInWord(i, guess[i], answer);
    if (locationVal == 0) {
      mStringOfGuesses += BOLD;
      mStringOfGuesses += GREEN;
      mStringOfGuesses += " ";
      mStringOfGuesses += guess[i];
      mStringOfGuesses += " ";
      mStringOfGuesses += RESET;
    } else if (locationVal == 1) {
      mStringOfGuesses += BOLD;
      mStringOfGuesses += YELLOW;
      mStringOfGuesses += " ";
      mStringOfGuesses += guess[i];
      mStringOfGuesses += " ";
      mStringOfGuesses += RESET;
    } else {
      mStringOfGuesses += BOLD;
      mStringOfGuesses += GREY;
      mStringOfGuesses += " ";
      mStringOfGuesses += guess[i];
      mStringOfGuesses += " ";
      mStringOfGuesses += RESET;
    }
  }
  mStringOfGuesses += "\n";
  mStringOfGuesses += "\n";
  cout << mStringOfGuesses;
}

void Display::displayPlayAgain() {
  cout << BOLD;
  cout << "Would you like to play again (y/n)?: ";
  cout << RESET;
}

void Display::resetStringOfGuesses() {
    mStringOfGuesses = "";
}

// Return int based on where letter is located in word
// Return 0 if in word and correct spot
// Return 1 if in word and not correct spot
// Return -1 if not in word
// TODO: Says duplicate when not (if 1 e in word and 2 e in guess both are yellow in prinout)
int Display::letterInWord(int letterIndex, char guessChar, string answer) {
  int returnVal = -1;
  for (int i = 0; i < answer.length(); i++) {
    if (guessChar == answer[i]) { // letter is somewhere in word
      if (letterIndex == i) { // at same index as answer
        return 0;
      } else { // in answer but not same index
        returnVal = 1;
      }
    } 
  }
  return returnVal; // not in answer
}

// COMPLETE
void Display::incrNumOfGuesses(int numOfGuesses) {
  switch (numOfGuesses) {
    case 1:
      mNumOfGuessesIn1++;
      break;
    case 2:
      mNumOfGuessesIn2++;
      break;
    case 3:
      mNumOfGuessesIn3++;
      break;
    case 4:
      mNumOfGuessesIn4++;
      break;
    case 5:
      mNumOfGuessesIn5++;
      break;
    case 6:
      mNumOfGuessesIn6++;
      break;
    case 7:
      mNumOfNoGuesses++;
      break;
  }
}

void Display::incrTotalGames() {
  mTotalGames++;
}

void Display::incrStreak() {
  mStreak++;
}

void Display::resetStreak() {
  mStreak = 0;
}
