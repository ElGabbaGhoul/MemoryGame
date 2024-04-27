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

char createBoard(const int EASY_COL) {
    // dynamically creates a board of the proper size of characters.
//    char *board[col] = nullptr;
    char** board = new char*[EASY_COL];
    // places two of each character into the board
    for (int i = 0; i < EASY_COL; ++i){
        board[i] = new (char)('A' + i);
    }

    for (int i = 0; i < EASY_COL; i++){
        for (int j = 0; j < EASY_COL; j++){
            board[i][j] = (char)('A' + i);
        }
    }

    for (int i = 0; i < EASY_COL; i++){
        for (int j = 0; j < EASY_COL; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }



    // calls shuffle, passing the board, to randomize the location
        shuffle(*board, EASY_COL);
    // returns the board
    std::cout << "Board Created." << std::endl;

    for (int i = 0; i < EASY_COL; i++){
        delete [] board[i];
    }

    return **board;
}

//void showBoard(char* board, int col){
//    for (int i = 0; i < col; i++){
//        std::cout << board[i] << " ";
//    }
//    std::cout << std::endl;
//}
