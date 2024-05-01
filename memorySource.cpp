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

char* createBoard(int difficulty) {
    // dynamically creates a board of the proper size of characters.
    char* board;

    if (difficulty == 1) {
        //create easy board, 4x4
        int easySize = EASY_COL * EASY_ROW;
        board = new char [easySize];
        for (int i = 0; i < easySize / 2; i++){
            board[2*i] = 'A' + i;
            board[2*i+1] = 'A' + i;
            // if (!i % 2 == 0) {
            //     board[i] = 'A' ;
            // } else {
            //     board[i] = 'A' + (i);
            }

    } else {
        //create hard board, 5x6
        int hardSize = HARD_COL * HARD_ROW;
        board = new char [hardSize];
        for (int i = 0; i < hardSize; i++){
            for (int j = 0; j < hardSize; j++) {
                int index = i * HARD_COL + j;
                board[i] = (char)('A' + (index / 2) % (HARD_COL * 2));
            }
        }


    }
    std::cout << "Displaying unshuffled board..." << std::endl;
    showBoard(board, difficulty);
    // calls shuffle, passing the board, to randomize the location
        shuffle(board, difficulty);
    // returns the board
    // showBoard(board, difficulty);

    return board;
}

void showBoard(char *board, int difficulty){
    if (difficulty == 1) {
        int easySize = (EASY_ROW * EASY_COL);
        for (int i = 0; i < easySize; i++){
                std::cout << board[i] << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = 0; i < HARD_ROW * HARD_COL - 1; i++){
                std::cout << board[i] << " ";
            }
            std::cout << std::endl;
        }
    }

