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
//    cout << " GAME SCREEN " << endl;
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0,0,1);
//    UsefulMethods::displayRasterText(-250,-300,0,"Game Screen");
//    glFlush();
//    glutSwapBuffers();
}