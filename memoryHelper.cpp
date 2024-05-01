//
// Created by Scooter on 4/24/2024.
//

#include "memoryHelper.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

void shuffle(char** board, int col) {
    for (int i = 0; i < col; i++){
        int j = rand() % col;
        for (int k = 0; k < col; k++){
            std::swap(board[k][i], board[k][j]);
        }
    }
}