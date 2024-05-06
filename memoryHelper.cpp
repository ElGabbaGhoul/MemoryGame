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
    int moveIn1, moveIn2;
    bool move1Valid = false;
    bool move2Valid = false;

    // while input invalid
    // same case for diff = 1 || 2
        // ask question 1
        // cin input
            // if cin fails type check, throw err
        // otherwise, it is checked for range
            // if it fails range check, throw err
        // otherwise, it is within range and right type so save it
        // ask question 2
        // cin input
            // if cin fails type check, throw err
        // otherwise, it is checked for range
            // if it fails range check, throw err
        // otherwise, it is within range and right type so save it

// do not ask question 2 until question 1 has valid input.

    // input is valid, return input

    // neither move valid
    while (!move1Valid || !move2Valid) {
        // move1 invalid, true for both difficulties?
        if (difficulty == 1) {
            if (!move1Valid) {
                std::cout << "Choose a row (1-" << EASY_ROW << "): " << std::endl;
                std::cin >> moveIn1;
                // question
                if (std::cin.fail()){
                    // type validation failure
                    std::cerr << "Invalid Type" << std::endl;
                    std::cerr << "Do not enter any other inputs (letters, 2-digit numbers, etc.)" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(50000,'\n');
                } else if (!(moveIn1 > 0 && moveIn1 <= EASY_ROW)) {
                    // range validation failure
                    std::cerr << "Move 1 out of range. " << std::endl;
                    std::cerr << "Range is: 1 - " << EASY_ROW << "." << std::endl;
                } else {
                    // type & range pass
                    move1Valid = true;
                }
            }
                if (!move2Valid && move1Valid) {
                    // valid first move, get second
                    std::cout << "Choose a column (1-" << EASY_COL << "): " << std::endl;
                    std::cin >> moveIn2;

                    if (std::cin.fail()){
                        // type failure
                        std::cerr << "Invalid Type." << std::endl;
                        std::cerr << "Do not enter any other inputs (letters, 2-digit numbers, etc.)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(50000,'\n');
                    } else if (!(moveIn2 > 0 && moveIn2 <= EASY_COL)) {
                        // range failure
                        std::cerr << "Move 2 out of range. " << std::endl;
                        std::cerr << "Range is: 1 - " << EASY_COL << "." << std::endl;
                    } else {
                        // type & range pass
                        move2Valid = true;
                    }
                }
        }
        if (difficulty == 2) {
            if (!move1Valid){
                // question
                std::cout << "Choose a row (1-" << HARD_ROW << "): " << std::endl;
                std::cin >> moveIn1;
                // type failure
                if (std::cin.fail()){
                    std::cerr << "Invalid Type" << std::endl;
                    std::cerr << "Do not enter any other inputs (letters, 2-digit numbers, etc.)" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(50000,'\n');
                    // range failure
                } else if (!(moveIn1 > 0 && moveIn1 <= EASY_ROW)) {
                    std::cerr << "Move 1 out of range. " << std::endl;
                    std::cerr << "Range is: 1 - " << HARD_ROW << "." << std::endl;
                } else {
                    // type and range pass
                    move1Valid = true;
                }
                if (!move2Valid && move1Valid){
                    // valid first move, get second
                    std::cout << "Choose a column (1-" << HARD_COL << "): " << std::endl;
                    std::cin >> moveIn2;
                    // type failure
                    if (std::cin.fail()) {
                        std::cerr << "Invalid Type." << std::endl;
                        std::cerr << "Do not enter any other inputs (letters, 2-digit numbers, etc.)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(50000,'\n');
                        // range failure
                    } else if (!(moveIn2 > 0 && moveIn2 <= HARD_COL)) {
                        std::cerr << "Move 2 out of range. " << std::endl;
                        std::cerr << "Range is: 1 - " << HARD_COL << "." << std::endl;
                        // type and range pass, save
                    } else {
                        move2Valid = true;
                    }
                }
            }
        }
    }
    move[0] = moveIn1 - 1;
    move[1] = moveIn2 - 1;

    return move[2];
}