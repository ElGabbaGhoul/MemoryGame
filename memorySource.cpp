//
// Created by Scooter on 4/24/2024.
//

#include <iostream>

#include "memorySource.h"
#include "memoryHelper.h"

void displayInstructions(int currentRound) {
    if (currentRound == 0) {
        std::cout << "There are 2 of each letter hidden on this board." << std::endl;
        std::cout << "(A - H for Easy, A - O for Hard.)" << std::endl;
        std::cout << "Enter your guess one (or two!) numbers at a time." << std::endl;
        std::cout << "For example, (1 2) for the second spot in the first row. " << std::endl;
        std::cout << "Match all the letters to win!" << std::endl;
    } else {
        std::cout << "Enter your guess one (or two!) numbers at a time." << std::endl;
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

void showBoard(char **board, int row, int col){
    for (int i=0; i < row; i++) {
        for (int j = 0; j < col; j++ ) {
            if (board[i][j] == SPACE) {
                std::cout << SPACE << " ";
            } else {
                std::cout << UNKNOWN << " ";
            }
        }
        std::cout << std::endl;
    }
}

// show move1
void showBoard(char **board, int row, int col, int move1[2]) {
    for (int i=0; i < row; i++) {
        for (int j = 0; j < col; j++ ) {
            if (i == move1[0] && j == move1[1] ) {
                std::cout << board[i][j] << " ";
            } else if (board[i][j] == SPACE) {
                std::cout << SPACE << " ";
            } else {
                std::cout << UNKNOWN << " ";
            }
        }
        std::cout << std::endl;
    }
}

// show move1 & move2
void showBoard(char **board, int row, int col, int move1[2], int move2[2]) {
    for (int i=0; i < row; i++) {
        for (int j = 0; j < col; j++ ) {
            if ((i == move1[0] && j == move1[1]) || (i == move2[0] && j == move2[1])) {
                    std::cout << board[i][j] << " ";
                } else if (board[i][j] == SPACE) {
                    std::cout << SPACE << " ";
                } else {
                    std::cout << UNKNOWN << " ";
                }
            }
            std::cout << std::endl;
        }
    }

void getMove(char **board, int move1[2], int difficulty){
    getMoveInteger(move1, difficulty);
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



    if (x == xOld && y == yOld){
        std::cout << "Moves are the same. Please try again." << std::endl;
        getMove(board, move1, move2, difficulty);
    } else {
        char position2 = board[x][y];
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

        return true;
    }
    return false;
}

void updateBoard(char **board, int row, int col, int move1[2], int move2[2]) {

    int x1 = move1[0];
    int y1 = move1[1];
    int x2 = move2[0];
    int y2 = move2[1];

    if (checkMatch(board, move1, move2) == true) {
        std::cout << "MATCH: (" << x1 + 1 << ", " << y1 + 1 <<") = " << board[x1][y1] <<", ";
        std::cout << "(" << x2 + 1 <<", " << y2 + 1 << ") = " << board[x2][y2] << "!" << std::endl;
        board[x1][y1] = SPACE;
        board[x2][y2] = SPACE;
    }
}
