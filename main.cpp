#include <iostream>
#include <ctime>
#include <cstdlib>

#include "memorySource.h"
#include "memoryHelper.h"


int main() {

    // Initialize RNG
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    int move1[2];
    int move2[2];
    int matches = 0;
    bool match;
    bool gameOver = false;
    bool replay;
    int currentRound = 0;


    do {
        displayInstructions(currentRound);
        do {
            int difficulty = getDifficultyInteger();
            char **ptr = createBoard(difficulty);
            showBoard(ptr, difficulty);
            getMove(ptr, move1, difficulty);
            getMove(ptr, move1, move2, difficulty);
            match = checkMatch(ptr, move1, move2);
            if (match){
                matches++;
            }
        } while (matches < 9);
        replay = playAgain();
    } while (replay);
    return 0;
}
