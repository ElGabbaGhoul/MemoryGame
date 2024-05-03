//
// Created by Scooter on 4/24/2024.
//

#ifndef MEMORYGAME_MEMORYHELPER_H
#define MEMORYGAME_MEMORYHELPER_H

void shuffle(char **board, int difficulty);
int getDifficultyInteger();
int getMoveInteger(int move1[2], int difficulty);
bool yesOrNo();

#endif //MEMORYGAME_MEMORYHELPER_H
