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
// FIXME: Change the values of x and o to ASCII values
int x = 88, o = 79, intToChar = 49;
bool isGameRunning = true;

// Two players will be playing the game (0 and 1)
// activePlayer will be used to keep track of the player playing the game
int activePlayer = 1;
int playerMarker[2];
int playerScores[2][5] = {[0 ... 1][0 ... 4] = -1};
// int winCondition[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
//                           {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
int winCondition[8][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7},
                          {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};

/**
 * @brief Prints empty lines to console
 *
 * @param    lines    Number of lines to print
 * @return int
 */
int printNewLines(int);

/**
 * @brief Initialize the game
 *
 * @return true
 * @return false
 */
bool init(void);

/**
 * @brief Switch the active player
 *
 * @return true
 * @return false
 */
bool switchPlayer(void);

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
bool checkForWin(void);

int main(int argc, char *argv[]) {
  // ANCHOR Main Function
  system("clear");

  init();
  while (isGameRunning) {
    markBoard();
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
 * @brief Initialize the game
 *
 * @return true
 * @return false
 */
bool init(void) {
  // ANCHOR init
  // Initialize gameData array

  for (int i = 0; i < 9; i++)
    gameData[i] = i + intToChar;

  // Initialize playerMarker array
  for (int i = 0; i < 2; i++)
    playerMarker[i] = o;

  // Press Enter to initiate the toss
  printf("Press [Enter] to initiate the toss");
  char startGame;
  scanf("%c", &startGame);
  printNewLines(1);

  // Simulate a toss to decide who decides first
  time_t t;
  srand((unsigned)time(&t));
  const int toss = rand() % 2;
  activePlayer = toss;

  printf("Player %d will go first", toss);
  printNewLines(1);

  // Display marker menu
  printf("Choose your marker: \n");
  printf("0. X\n");
  printf("1. O\n");
  printNewLines(1);

  // Ask Player to choose marker
  int marker;
  bool isValidMarker = false;
  do {
    printf("Enter your choice: ");
    scanf("%d", &marker);

    if (marker != 1 && marker != 0) {
      printf("Invalid marker");
      printNewLines(1);
    }

    if (marker == 1 || marker == 0)
      isValidMarker = true;

  } while (!isValidMarker);

  // Assign marker to player i.e, store values in playerMarker array
  playerMarker[activePlayer] = x;

  drawBoard();

  return true;
}

/**
 * @brief Switch the active player
 *
 * @return true
 * @return false
 */
bool switchPlayer(void) {
  // ANCHOR switchPlayer
  activePlayer = !activePlayer;

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

  system("clear");

  // Display the marker chosen by the player
  printNewLines(1);
  for (int i = 0; i < 2; i++)
    printf("Player %d: %c\t", i, playerMarker[i]);
  printNewLines(2);

  // Display the Tic Tac Toe Board
  printf("\t   |   |   \n");
  printf("\t %c | %c | %c \n", gameData[0], gameData[1], gameData[2]);
  printf("\t---+---+---\n");
  printf("\t %c | %c | %c \n", gameData[3], gameData[4], gameData[5]);
  printf("\t---+---+---\n");
  printf("\t %c | %c | %c \n", gameData[6], gameData[7], gameData[8]);
  printf("\t   |   |   \n");

  printNewLines(2);

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
  printf("Player %d's turn", activePlayer);
  printNewLines(1);

  printf("Enter the position to mark: ");
  int position;
  scanf("%d", &position);

  if (position < 1 || position > 9) {
    printf("Invalid position");
    printNewLines(1);
    return false;
  }

  if (gameData[position-1] == x && gameData[position-1] == o) {
    printf("Position already marked");
    printNewLines(1);
    return false;
  }

  gameData[position-1] = playerMarker[activePlayer];
  playerScores[activePlayer][position-1] = position;

  checkForWin();

  if (isGameRunning) {
    switchPlayer();
    drawBoard();
  }

  return true;
}

/**
 * @brief Check if the game has been won
 *
 * @return true
 * @return false
 */
bool checkForWin(void) {
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
          printf("Player %d Wins 🥳", activePlayer);
          printNewLines(1);
          win = true;
          isGameRunning = false;
          break;
        }
      }
    }
  }
  return true;
}