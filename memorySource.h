//
// Created by Scooter on 4/24/2024.
//

#ifndef MEMORYGAME_MEMORYSOURCE_H
#define MEMORYGAME_MEMORYSOURCE_H

//Recommended constants
const int HARD_ROW = 5;
const int HARD_COL = 6;
const int EASY_ROW = 4;
const int EASY_COL = 4;
const char SPACE = '_';
const char UNKNOWN = 'X';
const int EASY_SIZE = EASY_COL * EASY_ROW;
const int HARD_SIZE = HARD_COL * HARD_ROW;


void displayInstructions(int currentRound);
char** createBoard(int difficulty);
// 1 overloaded getMove
void getMove(char **board, int move1[2], int difficulty);
void getMove(char **board, int move1[2], int move2[2], int difficulty);
//show board before guess
void showBoard(char **board, int row, int col);
// show board guess 1
void showBoard(char **board, int row, int col, int move1[2]);
// show board guess 2
void showBoard(char **board, int row, int col, int move1[2], int move2[2]);
bool checkMatch(char **board, int move1[2], int move2[2]);
void updateBoard(char **board, int move1[2], int move2[2]);
bool playAgain();



#endif //MEMORYGAME_MEMORYSOURCE_H
