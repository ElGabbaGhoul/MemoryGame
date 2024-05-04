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
const char SPACE = ' ';
const char UNKNOWN = 'X';
const int EASY_SIZE = EASY_COL * EASY_ROW;
const int HARD_SIZE = HARD_COL * HARD_ROW;


void displayInstructions(int currentRound);
char** createBoard(int difficulty);
// 1 overloaded getMove
void getMove(char **board, int move1[2], int difficulty);
void getMove(char **board, int move1[2], int move2[2], int difficulty);
// 2 overloaded showBoard
void showBoard(char **board, int difficulty);
bool checkMatch(char **board, int move1[2], int move2[2]);
void updateBoard();
bool playAgain();



#endif //MEMORYGAME_MEMORYSOURCE_H
