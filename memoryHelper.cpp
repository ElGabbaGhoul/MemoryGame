//
// Created by Scooter on 4/24/2024.
//

#include "memoryHelper.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "memorySource.h"

void shuffle(char **board, int difficulty) {
    std::cout << "Shuffling board..." << std::endl;
    int rows = (difficulty == 1) ? EASY_ROW : HARD_ROW;
    int cols = (difficulty == 1) ? EASY_COL : HARD_COL;
    int totalElements = rows * cols;

    // Flatten the 2D board into a 1D array for easier shuffling
    char* flatBoard = new char[totalElements];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            flatBoard[i * cols + j] = board[i][j];
        }
    }

    // Shuffle the flat board
    for (int i = 0; i < totalElements; ++i) {
        int j = rand() % totalElements;
        std::swap(flatBoard[i], flatBoard[j]);
    }

    // Unflatten the shuffled flat board back into the 2D board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = flatBoard[i * cols + j];
        }
    }

    delete[] flatBoard;
}

int getDifficultyInteger() {
    int difficulty;
    bool validInput = false;

    while (!validInput) {
       std::cout << "What difficulty would you like to play? (1: Easy, 2: Hard)." << std::endl;
        std::cin >> difficulty;

        if (difficulty != 1 && difficulty != 2) {
            std::cerr << "Please press 1 for Easy, 2 for Hard." << std::endl;
            std::cin.clear();
            std::cin.ignore(50000, '\n');
        } else {
            validInput = true;
        }
    }
    return difficulty;
}

int getMoveInteger(int move[2], int difficulty) {
    int moveIn1;
    int moveIn2;
    bool validInput = false;

    while(!validInput){
        if (difficulty == 1){
            std::cout << "Choose a row (1-" << EASY_ROW << "): " << std::endl;
            std::cin >> moveIn1;
            std::cout << "Choose a column (1-" << EASY_COL << "): " << std::endl;
            std::cin >> moveIn2;
            // valid move for easy board
            if (moveIn1 > 0 && moveIn1 <= EASY_ROW){
                move[0] = moveIn1 - 1;
            }
            if (moveIn2 > 0 && moveIn2 <= EASY_COL){
                move[1] = moveIn2 - 1;
                validInput = true;
            }
        }
        if (difficulty == 2){
            std::cout << "Choose a row (1-" << HARD_ROW << "): " << std::endl;
            std::cin >> moveIn1;
            std::cout << "Choose a column (1-" << HARD_COL << "): " << std::endl;
            std::cin >> moveIn2;
            if (moveIn1 > 0 && moveIn1 <= HARD_ROW){
                move[0] = moveIn1 - 1;
            }
            if (moveIn2 > 0 && moveIn2 <= HARD_COL){
                move[1] = moveIn2 - 1;
                validInput = true;
            }
        }
    }
    return move[2];
}