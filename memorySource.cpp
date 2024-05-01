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

char** createBoard(const int EASY_COL) {
    // dynamically creates a board of the proper size of characters.
    char** board = new char*[EASY_COL];
    // init empty board
    for (int i = 0; i < EASY_COL; ++i){
        board[i] = new (char)(' ');
    }

    // 2 of each letter from A - H (easy) A - O (hard)
    for (int i = 0; i < EASY_COL; i++){
        for (int j = 0; j < EASY_COL; j++){
            int index = (i * EASY_COL) + j;
            board[i][j] = (char)('A' + (index / 2) % (EASY_COL * 2));
        }
    }


    showBoard(board, EASY_COL);
    // for (int i = 0; i < EASY_COL; i++){
    //     for (int j = 0; j < EASY_COL; j++){
    //         std::cout << board[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // calls shuffle, passing the board, to randomize the location
        shuffle(board, EASY_COL);
    // returns the board
    showBoard(board, EASY_COL);
    for (int i = 0; i < EASY_COL; i++){
        delete [] board[i];
    }

    return board;
}

void showBoard(char** board, int col){
    for (int i = 0; i < col; i++){
        for (int j = 0; j < col; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
