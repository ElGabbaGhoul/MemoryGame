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
    char move1;
    char move2;
    int matches;
    int currentRound = 0;



    displayInstructions(currentRound);
    // currentRound++;
    // displayInstructions(currentRound);
    int difficulty = getInteger();
    std::cout << "Difficulty:  " << difficulty << std::endl;
    char *ptr = createBoard(difficulty);
    showBoard(ptr, difficulty);

    return 0;
}
