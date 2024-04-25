#include <iostream>

#include "memorySource.h"


int main() {

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
    char *board[][];
    int rowLen;
    int colLen;
    int currentRound = 0;



    displayInstructions(currentRound);
    currentRound++;
    displayInstructions(currentRound);
    // createBoard();

    return 0;
}
