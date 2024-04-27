#include <iostream>
#include <ctime>
#include <cstdlib>

#include "memorySource.h"


int main() {

    // Initialize RNG
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    /*move1,
     *move2,
     *board (a pointer),
     *rowLength,
     *colLength,
     *counter of how many matches*/
    char move1;
    char move2;
    // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
    // A - H for Easy
    // A - O for Hard
    char *board = nullptr;
    int rowLen;
    int colLen;
    int currentRound = 0;



    displayInstructions(currentRound);
    currentRound++;
    displayInstructions(currentRound);
    createBoard(board, EASY_COL);

    return 0;
}
