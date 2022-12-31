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

// ANCHOR Main Function
int main(int argc, char *argv[]) {
  system("clear");

  /* // ANCHOR - Print gameData
  for (int i = 0; i < 9; i++) {
    printf("%d ", gameData[i]);
  }
  printNewLines(1);

  // ANCHOR - Print playerScore
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", playerScores[i][j]);
    }
    printNewLines(1);
  } */

  int winCondition[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                            {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

  int testArr[2][5] = {{1, 2, 3, 4, 0}, {4, 5, 6, 7, 8}};
  int counter = 0;

  // printf("testArr: %d", testArr[0][i]);
  // printNewLines(2);
  bool win = false;

  for (int j = 0; j < 8 && win == false; j++) {
      counter = 0;
    for (int i = 0; i < 5 && win == false; i++) {
      for (int k = 0; k < 3; k++) {
        if (testArr[0][i] == winCondition[j][k])
          counter++;
        // printf("winCondition: %d\t", winCondition[j][k]);
        printf("i = %d\tj = %d\tk = %d\ttestArr = %d\t winCondition = %d\t", i, j, k, testArr[0][i], winCondition[j][k]);
        printf("counter: %d\n", counter);
        if (counter == 3) {
          printf("Win");
          printNewLines(1);
          win = true;
          break;
        }
        // printNewLines(1);
      }
      // printNewLines(1);
    }
  }

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