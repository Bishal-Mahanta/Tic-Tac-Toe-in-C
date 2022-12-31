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

int gameData [9] = {[0 ... 8] = -1};
int activePlayer = 1;

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
bool drawBoard (void);

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
bool drawBoard (void) {
  // ANCHOR drawBoard
  
  return true;
}