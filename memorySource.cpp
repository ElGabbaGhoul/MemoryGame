//
// Created by Scooter on 4/24/2024.
//

#include <iostream>

#include "memorySource.h"
#include "memoryHelper.h"

void displayInstructions(int currentRound) {
    if (currentRound == 0) {
        std::cout << "Long Instructions." << std::endl;
    } else {
        std::cout << "Short Instructions." << std::endl;
    }
}

char createBoard(char* board, int col) {
    // dynamically creates a board of the proper size of characters.
    board = new char[col];
    // places two of each character into the board
    for (int i = 0; i < col; i++){
        board[i] = (char)('A' + i);
    }
    // calls shuffle, passing the board, to randomize the location
        shuffle(board, col);
    // returns the board
    std::cout << "Board Created." << std::endl;
    return* board;
}
