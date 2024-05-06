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
        int difficulty = getDifficultyInteger();
        char **ptr = createBoard(difficulty);
        showBoard(ptr, EASY_ROW, EASY_COL);
        do {
            getMove(ptr, move1, difficulty);
            showBoard(ptr, EASY_ROW, EASY_COL, move1);
            getMove(ptr, move1, move2, difficulty);
            showBoard(ptr, EASY_ROW, EASY_COL, move1, move2);
            std::cout << "Guess was: " << move1[0] + 1 << " " << move1[1] + 1 << ", " << move2[0] + 1 << " " << move2[1] + 1 << "." << std::endl;
            match = checkMatch(ptr, move1, move2);

            if (match){
                matches++;
            }
        } while (matches < 9);
        replay = playAgain();
    } while (replay);
    return 0;
}
