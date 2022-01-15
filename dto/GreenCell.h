//
// Created by tomas on 13/01/2022.
//

#ifndef FINALCHECKERS_GREENCELL_H
#define FINALCHECKERS_GREENCELL_H
#include <vector>
#include "State.h"

using namespace std;

class GreenCell {
public:
    int xDown,xUp,yLeft,yRight;
    bool hasPawn;
    bool forBottomQueen;
    bool forUpQueen;
    int  positionX {};
    int  positionY {};
    vector<GreenCell> neighbourGreenCells;
    State *state = new State;
};


#endif //FINALCHECKERS_GREENCELL_H
