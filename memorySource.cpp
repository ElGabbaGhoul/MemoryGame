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

void getMove(char **board, int move1[2], int difficulty){
    //get two integers, validate they are in range (0-3)
    getMoveInteger(move1, difficulty);
    //verify that the location is not a space
    int x = move1[0];
    int y = move1[1];

    char position = board[x][y];

    std::cout << "Character at position " << x + 1 << ", " << y + 1 <<": " << position << "." << std::endl;
}

void getMove(char **board, int move1[2], int move2[2], int difficulty){
    getMoveInteger(move2, difficulty);

    int xOld = move1[0];
    int yOld = move1[1];

    int x = move2[0];
    int y = move2[1];

    char position1 = board[xOld][yOld];
    char position2 = board[x][y];

    if (x == xOld && y == yOld){
        std::cout << "Moves are the same. Please try again." << std::endl;
    } else {
        std::cout << "Character at position: " << x + 1 << ", " << y + 1 <<": " << position2 << "." << std::endl;
    }



}

bool playAgain() {
    char playAgain;

    while (true) {
        std::cout << "Would you like to play again? (Y/N)" << std::endl;
        std::cin >> playAgain;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(500, '\n');
            std::cerr << "Invalid input, please enter a single character, Y or N."
                      << std::endl;
        } else {
            playAgain = char(toupper(playAgain));
            if (playAgain == 'Y' || playAgain == 'N') {
                std::cout << "Thank you for playing!" << std::endl;
                return playAgain == 'Y';
            }
        }
    }
}

bool checkMatch(char **board, int move1[2], int move2[2]){
    int x1 = move1[0];
    int y1 = move1[1];

    int x2 = move2[0];
    int y2 = move2[1];

    if (board[x1][y1] == board[x2][y2]){
        std::cout << "MATCH: (" << x1 + 1 << ", " << y1 + 1 <<") = " << board[x1][y1] <<", ";
        std::cout << "(" << x2 + 1 <<", " << y2 + 1 << ") = " << board[x2][y2] << "!" << std::endl;
        return true;
    }
    return false;
}