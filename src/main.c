/**
 * @file main.c
 * @author Bishal Mahanta (bishalmahanta0.0.0@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define invalid -1

int gameData[9] = {[0 ... 8] = -1};

// Two players will be playing the game (0 and 1)
// activePlayer will be used to keep track of the player playing the game
int activePlayer = 1;
int playerScores[2][5] = {};
int winCondition[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                          {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

/**
 * @brief Prints empty lines to console
 *
 * @param    lines    Number of lines to print
 * @return int
 */
int printNewLines(int);

/**
 * @brief Draw a Tic Tac Toe Board
 *
 * @return true
 * @return false
 */
bool drawBoard(void);

/**
 * @brief Mark Tic Tac Toe Board and update player scores
 *
 * @return true
 * @return false
 */
bool markBoard(void);

/**
 * @brief Check if the game has been won
 *
 * @return int activePlayer
 */
int checkForWin(void);

// ANCHOR Main Function
int main(int argc, char *argv[]) {
  system("clear");  

  return true;
}

/**
 * @brief Prints empty lines to console
 *
 * @param    lines    Number of lines to print
 * @return int
 */
int printNewLines(int lines) {
  // ANCHOR printNewLines
  if (lines <= 0)
    return false;

  for (int i = 0; i < lines; i++)
    printf("\n");
  return true;
}

/**
 * @brief Draw a Tic Tac Toe Board
 *
 * @return true
 * @return false
 */
bool drawBoard(void) {
  // ANCHOR drawBoard

  return true;
}

/**
 * @brief Mark Tic Tac Toe Board and update player scores
 *
 * @return true
 * @return false
 */
bool markBoard(void) {
  // ANCHOR markBoard

  return true;
}

/**
 * @brief Check if the game has been won
 * 
 * @return true
 * @return false
 */
int checkForWin(void) {
  // ANCHOR checkForWin
  bool win = false;
  int counter = 0;

  for (int j = 0; j < 8 && win == false; j++) {
    counter = 0;
    for (int i = 0; i < 5 && win == false; i++) {
      for (int k = 0; k < 3; k++) {
        if (playerScores[activePlayer][i] == winCondition[j][k])
          counter++;
        if (counter == 3) {
          printf("Win");
          printNewLines(1);
          win = true;
          break;
        }
      }
    }
  }
  return activePlayer;
}