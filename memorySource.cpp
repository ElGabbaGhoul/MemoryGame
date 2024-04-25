//
// Created by Scooter on 4/24/2024.
//

#include <iostream>

#include "memorySource.h"
void displayInstructions(int currentRound) {
    if (currentRound == 0) {
        std::cout << "Long Instructions." << std::endl;
    } else {
        std::cout << "Short Instructions." << std::endl;
    }
}

// I think it's the required consts, so...array with [][]
// either [hard_row][hard_col] or [easy_row][easy_col] but since
// easy are both 4, could do [][easy_col]?

char createBoard(char* board[][EASY_COL]) {

    // dynamically creates a board of the proper size of characters.
    char *board = nullptr;
    // int count = 0;
    // char inChar;

    // places two of each character into the board

    // calls shuffle, passing the board, to randomize the location

    // returns the board
}
