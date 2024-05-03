#include <iostream>
#include <ctime>
#include <cstdlib>

#include "memorySource.h"
#include "memoryHelper.h"


int main() {

    // Initialize RNG
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    /*move1,
     *move2,
     *counter of how many matches*/
    int move1[2];
    int move2[2];
    int matches;
    int currentRound = 0;



    displayInstructions(currentRound);
    // currentRound++;
    // displayInstructions(currentRound);
    int difficulty = getDifficultyInteger();
    char **ptr = createBoard(difficulty);
    showBoard(ptr, difficulty);
//    getMove(*ptr, EASY_ROW, EASY_COL, move1, difficulty);
//    getMove(*ptr, EASY_ROW, EASY_COL, move1, move2, difficulty);

    return 0;
}
