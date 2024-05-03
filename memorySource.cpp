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

char** createBoard(int difficulty) {
    // dynamically creates a board of the proper size of characters.
    char** board;
    int rows, cols;

    if (difficulty == 1) {
        //create easy board, 4x4
        rows = EASY_ROW;
        cols = EASY_COL;

    } else {
        //create hard board, 5x6
        rows = HARD_ROW;
        cols = HARD_COL;
    }
    std::cout << "Creating board with difficulty: " << difficulty << "." << std::endl;
    // allocate memory for board
    board = new char*[rows];
    for (int i = 0; i < rows; ++i){
        board[i] = new char[cols];
    }

    // Fill board with letters
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            board[i][j] = 'A' + (i * cols + j) / 2;
        }
    }
    std::cout << "Displaying non-shuffled board..." << std::endl;
    showBoard(board, difficulty);
    // calls shuffle, passing the board to randomize element locations
        shuffle(board, difficulty);
    // returns board
    return board;
}

void showBoard(char **board, int difficulty){
    if (difficulty == 1) {
        for (int i = 0; i < EASY_ROW; i++){
            for (int j = 0; j < EASY_COL; j++){
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 0; i < HARD_ROW; i++){
            for (int j = 0; j < HARD_COL; j++){
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

void getMove(char *board, int EASY_COL, int EASY_ROW, int move1[2], int difficulty){
    //get two integers, validate they are in range (0-3)
    getMoveInteger(move1, difficulty);
    //verify that the location is not a space
    std::cout << "Player move: " << move1[0] << ", " << move1[1] << "." << std::endl;
    int x = move1[0];
    int y = move1[1];

    int idx = y * EASY_COL + x;
    char position = board[idx];

    std::cout << "Character at position " << x << ", " << y <<": " << position << "." << std::endl;
}

void getMove(char *board, int row, int col, int move1[2], int move2[2], int difficulty){
    getMoveInteger(move2, difficulty);
    int a = move1[0];
    int b = move1[1];

    int x = move2[0];
    int y = move2[1];

    if (a == x && b == y){
        std::cout << "Moves are the same." << std::endl;
    }

    int idx = y * EASY_COL + x;
    char position = board[idx];

    std::cout << "Character at position " << x << ", " << y <<": " << position << "." << std::endl;


}