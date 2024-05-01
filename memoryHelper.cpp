//
// Created by Scooter on 4/24/2024.
//

#include "memoryHelper.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "memorySource.h"

void shuffle(char *board, int difficulty) {
    std::cout << "Shuffling board..." << std::endl;

    if (difficulty == 1) {
        int easySize = EASY_COL * EASY_ROW;

        for (int i = 0; i < easySize; i++){
            std::swap(board[getRandomInt(difficulty)], board[getRandomInt(difficulty)]);
        }
    } else {
        for (int i = 0; i < HARD_ROW; i++){
            int j = rand() % HARD_ROW - 1;
            std::swap(board[i], board[j]);
        }
    }

}

int getRandomInt(int difficulty) {
    int randNum;
    int easySize = EASY_COL * EASY_ROW;
    int hardSize = HARD_COL * HARD_ROW;

    if (difficulty == 1) {
        randNum = rand() % easySize;
    } else {
        randNum = rand() % hardSize;
    }

    return randNum;
}


int getInteger() {
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