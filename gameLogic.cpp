//gameLogic.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "gameLogic.h"
#include "display.h"

using namespace std;

// Constructor
GameLogic::GameLogic() {}

// Member variables
Display display; // display object for displaying game
int numOfGuesses;

// Member functions
// COMPLETED
void GameLogic::startMenu() {
  bool waitingForInput = true;
  string userSelection;

  do {
    display.displayStartMenu();

    cin >> userSelection;
    cout << endl;

    if (userSelection == "R" || userSelection == "r") {
      playGame();
      waitingForInput = false;
    } else if (userSelection == "D" || userSelection == "d") {
      display.displayStatistics();
    } else if (userSelection == "Q" || userSelection == "q") {
      cout << "Thanks for playing!\n" << endl;
      waitingForInput = false;
    } else {
      cout << "Error: Invalid selection, please try again." << endl;
    }

  } while (waitingForInput);
}

// Play the game
// COMPLETED
void GameLogic::playGame() {
  string playAgainSelection;
  int numOfGuesses = 0;
  bool ranOutOfGuesses = true;

  string answer = generateAnswer();
  //cout << answer << endl;

  string userGuess;
  
  string playAgainChoice;
  
  do {
    cout << display.BOLD;
    cout << "Enter your guess: ";
    cout << display.RESET;
    
    cin >> userGuess;

    if (!isValidGuess(userGuess)) {
      cout << "\nError: Word not in allowed guesses.\n" << endl;
      continue;
    }

    display.displayGuesses(userGuess, answer);
    numOfGuesses++;

    if (userGuess == answer) {
      display.displayEndGame(true, answer);
      display.incrNumOfGuesses(numOfGuesses);
      display.incrStreak();
      ranOutOfGuesses = false;
      numOfGuesses = 6;
    }

  } while (numOfGuesses < 6);

  if (ranOutOfGuesses) {
    display.displayEndGame(false, answer);
    display.incrNumOfGuesses(numOfGuesses);
    display.resetStreak();
  }

  display.incrTotalGames();
  display.resetStringOfGuesses();
  display.displayPlayAgain();
  cin >> playAgainSelection;
  
  if (playAgainSelection == "Y" || playAgainSelection == "y") {
    playGame();
    
  } else {
    startMenu();
  }
}

// Generate random answer from answer file
// COMPLETED
std::string GameLogic::generateAnswer() {
  std::string answer;
  std::ifstream inFile;
  srand(unsigned(time(NULL)));

  int lineNum = rand() % 2315 + 0;

  inFile.open("config/wordle-answers-alphabetical.txt");

  for (int i = 1; i <= lineNum; i++) {
    std::getline(inFile, answer);
  }
  
  inFile.close();

  return answer;
}

// Check if guess is correct length and in allowed guesses
// COMPLETED
bool GameLogic::isValidGuess(std::string guess) {
  if (guess.length() != 5) {
    return false;
  }

  ifstream inFile;
  inFile.open("config/wordle-allowed-guesses.txt");

  string temp = "";
  bool isAllowed = false;

  transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

  while (getline(inFile, temp)) {
    if (temp == guess) {
      isAllowed = true;
    }
  }

  inFile.close();

  if (isAllowed) {
    return true;
  } else {
    return false;
  }

}


