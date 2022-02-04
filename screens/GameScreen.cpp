//
// Created by tomas on 12/01/2022.
//

#include <GL/gl.h>
#include <iostream>
#include "GameScreen.h"
#include "../utils/UsefulMethods.h"
#include "../checkers/Board.h"

using namespace std;

void GameScreen::createGameScreen(){
    Board *board = new Board(repository);
    board->creatBoard();
}