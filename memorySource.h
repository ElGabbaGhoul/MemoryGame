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


void displayInstructions(int currentRound);
char** createBoard(int EASY_COL);
void getMove();
// Showboard should be Overloaded
void showBoard(char **board, int col);
bool checkMatch();
void updateBoard();



#endif //MEMORYGAME_MEMORYSOURCE_H
