//
// Created by tomas on 11/01/2022.
//

#ifndef FINALCHECKERS_OBJECTSREPOSITORY_H
#define FINALCHECKERS_OBJECTSREPOSITORY_H


#include "ViewPage.h"
#include "GreenCell.h"
#include <vector>
using namespace std;
class ObjectsRepository {
public:
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int cellWidth = 100;
    const int cellHeight = 75;

    ViewPage *viewPage;
    bool *updateScreen;
    bool *firstConfig;

    bool cellSelected;
    bool isAfterJump;
    int mouseX;
    int mouseY;
    int mouseState;
    ObjectsRepository();

//    vector<GreenCell> greenCells;

//    State board_[8][8];
//    Board board_[8][8];




};


#endif //FINALCHECKERS_OBJECTSREPOSITORY_H
