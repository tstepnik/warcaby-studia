//
// Created by tomas on 13/01/2022.
//

#include <GL/glut.h>
#include "Board.h"
#include "../dto/ObjectsRepository.h"
#include "../utils/UsefulMethods.h"
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

int *c;
int *counter;
ObjectsRepository *obj_repo;
vector<GreenCell> *greenCells;
bool *dodajPionka;
const int xStartingPosition = 0;
const int yStartingPosition = 0;

void Board::creatBoard() {
    obj_repo = repository;
    c = new int;
    counter = new int;
    dodajPionka = new bool;
    *c = 0;
    *counter = 0;
    glClear(GL_COLOR_BUFFER_BIT);
////    greenCells = obj_repo->greenCells;
    for (int x = 0; x <= 8; x++) {
        for (int y = 0; y <= 8; y++) {
//            GreenCell greenCell;
//            findCell(x, y, greenCell);
            stworzPole(x, y);
            stworzPionka(x, y);
        }
    }
}

void Board::stworzPole(int x1, int y1) {
    x1 = x1 * obj_repo->cellWidth;
    y1 = y1 * obj_repo->cellHeight;

    if (*c == 0) {
        glColor3f(1, 1, 1);
        *c = 1;
    } else {
        glColor3f(0, 0, 0);
        *c = 0;
    }
    glBegin(GL_QUADS);
    glVertex2f(x1, y1 + obj_repo->cellHeight);
    glVertex2f(x1 + obj_repo->cellWidth, y1 + obj_repo->cellHeight);
    glVertex2f(x1 + obj_repo->cellWidth, y1);
    glVertex2f(x1, y1);
    glEnd();

}

void Board::stworzPionka(int x1, int y1) {
    pierwszaKonfiguracja(x1, y1);
//    obj_repo->cellSelected = false;
//    for (int x = 0; x < 8; ++x)
//        for (int y = 0; y < 8; ++y)
//        {
//            if ((x + y) % 2)
//                glColor3f(0.0f, 0.0f, 0.0f);
//            else
//                glColor3f(1.0f, 1.0f, 1.0f);
//            glBegin(GL_QUADS);
//            glVertex2f(x * obj_repo->windowWidth / 8, y * obj_repo->windowHeight / 8);
//            glVertex2f((x + 1) * obj_repo->windowWidth / 8, y * obj_repo->windowHeight / 8);
//            glVertex2f((x + 1) * obj_repo->windowWidth / 8, (y + 1) * obj_repo->windowHeight / 8);
//            glVertex2f(x * obj_repo->windowWidth / 8, (y + 1) * obj_repo->windowHeight / 8);
//            glEnd();
//            switch (obj_repo->board_[x][y])
//            {
//                case State::EMPTY:
//                    break;
//                case State::BLACK:
//                    glColor3f(0.5f, 0.5f, 0.9f);
//                    glBegin(GL_POLYGON);
//                    for (int a = 0; a < 9; ++a)
//                    {
//                        float xx = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) + (x + 0.5f) * obj_repo->windowWidth / 8;
//                        float yy =  obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) + (y + 0.5f) * obj_repo->windowHeight / 8;
//                        glVertex2f(xx, yy);
//                    }
//                    glEnd();
//                    break;
//                case State::WHITE:
//                    if (obj_repo->mouseX == x && obj_repo->mouseY == y){
//                        glColor3f(1.0f, 0.0f, 0.0f);
//                        obj_repo->cellSelected = true;
//                    }
//                    else {
//                        glColor3f(0.3f, 0.3f, 0.3f);
//                    }
//                        glBegin(GL_POLYGON);
//                    for (int a = 0; a < 9; ++a)
//                    {
//                        float xx = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) + (x + 0.5f) * obj_repo->windowWidth / 8;
//                        float yy =  obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) + (y + 0.5f) * obj_repo->windowHeight / 8;
//                        glVertex2f(xx, yy);
//                    }
//                    glEnd();
//                    break;
//            }
//        }
}

void Board::pierwszaKonfiguracja(int x1, int y1) {
    gameCellsInitiation();
    int baseX = x1;
    int baseY = y1;
    x1 = x1 * obj_repo->cellWidth;
    y1 = y1 * obj_repo->cellHeight;
    *(obj_repo->firstConfig) = false;
    if (
            (((x1 / obj_repo->cellWidth) % 2 == 0 && (y1 / obj_repo->cellHeight) % 2 != 0) ||
             ((x1 / obj_repo->cellWidth) % 2 != 0 && (y1 / obj_repo->cellHeight) % 2 == 0))
            &&
            ((y1 / obj_repo->cellHeight) < 3 || (y1 / obj_repo->cellHeight) > 4)
            ) {

        if (y1 / obj_repo->cellHeight < 3) {
            glColor3f(0.5f, 0.5f, 0.9f);
        } else {
            glColor3f(0.3f, 0.3f, 0.3f);

        }

        glBegin(GL_POLYGON);
        for (int a = 0; a < 9; ++a) {
            cout << "PIERWSZA KONFIGURACJA" << endl;
            float xx1 = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) +
                        ((x1 / obj_repo->cellWidth) + 0.5f) * obj_repo->windowWidth / 8;
            float yy1 = obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) +
                        ((y1 / obj_repo->cellHeight) + 0.5f) * obj_repo->windowHeight / 8;
            glVertex2f(xx1, yy1);
        }
        glEnd();
    }
}

void Board::findCell(int x, int y, GreenCell &greenCell) {
//    bool *firstConfiguration = obj_repo->firstConfig;
//    if (!firstConfiguration) {
//        vector<GreenCell> *greenCells = obj_repo->greenCells;
//        for (auto const &value: *greenCells) {
//            if (value.positionX == x && value.positionY == y) {
//                greenCell = value;
//            }
//        }
//    }
}

void Board::updateCell(int x, int y, GreenCell &greenCell) {
//    bool *firstConfiguration = obj_repo->firstConfig;
//    if (firstConfiguration) {
//        return;
//    } else {
//        vector<GreenCell> *greenCells = obj_repo->greenCells;
//        for (int i = 0; i < greenCells->size(); i++)
//
//            if (greenCells->at(i).positionX == x && greenCells->at(i).positionY == y) {
//                greenCells->at(i) = greenCell;
//            }
//    }
}

void Board::gameCellsInitiation(){
//GreenCell greenCell;
//    for (int x = 0; x < 8; ++x)
//        for (int y = 0; y < 8; ++y){
//            greenCell.state = (State *) State::EMPTY;
//            greenCell.positionX = x;
//            greenCell.positionY = y;
//            greenCells->push_back(greenCell);
//        }
//    for (int y = 0; y < 3; ++y)
//        for (int x = (y + 1) % 2; x < 8; x += 2){
//            greenCell.state = (State *) State::BLACK;
//            greenCell.positionX = x;
//            greenCell.positionY = y;
//            greenCells->push_back(greenCell);
//        }
//    for (int y = 5; y < 8; ++y)
//        for (int x = (y + 1) % 2; x < 8; x += 2){
//            greenCell.state = (State *) State::WHITE;
//            greenCell.positionX = x;
//            greenCell.positionY = y;
//            greenCells->push_back(greenCell);
//
//        }


}

