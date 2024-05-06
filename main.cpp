/*
Lab 4
Name: Scott "Marble" Nideffer
Date: 04/25/2024
IDE: Clion
Version: 1.0
Description: A Memory Game where you match letters. 1 for easy, 2 for hard, match all matches!
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "memorySource.h"
#include "memoryHelper.h"


int main() {

    // Initialize RNG
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    int col;
    int row;
    int move1[2];
    int move2[2];
    int matches = 0;
    bool match;
    bool replay;
    int currentRound = 0;


    do {
        int difficulty = getDifficultyInteger();
        char **ptr = createBoard(difficulty);
        if (difficulty == 1 ) {
            row = EASY_ROW;
            col = EASY_COL;
        } else {
            col = HARD_COL;
            row = HARD_ROW;
        }
        showBoard(ptr, row, col);
        do {
            displayInstructions(currentRound);
            currentRound++;
            getMove(ptr, move1, difficulty);
            showBoard(ptr, row, col, move1);
            getMove(ptr, move1, move2, difficulty);
            showBoard(ptr, row, col, move1, move2);
            std::cout << "Guess was: " << move1[0] + 1 << " " << move1[1] + 1 << ", " << move2[0] + 1 << " " << move2[1] + 1 << "." << std::endl;
            match = checkMatch(ptr, move1, move2);

            if (match){
                updateBoard(ptr, move1, move2);
                matches++;
                std::cout << "Matches: " << matches << std:: endl;
                showBoard(ptr, row, col);
            }
        } while (matches <= 8);
        replay = playAgain();
    } while (replay);
    return 0;
}
