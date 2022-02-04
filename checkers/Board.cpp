#include <GL/glut.h>
#include "Board.h"
#include <cmath>

using namespace std;

int *c;
int *counter;
ObjectsRepository *obj_repo;

void Board::creatBoard() {
    obj_repo = repository;
    c = new int;
    counter = new int;
    *c = 0;
    *counter = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    for (int x = 0; x <= 8; x++) {
        for (int y = 0; y <= 8; y++) {
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
    bool cellColored = false;
    for (int x = 0; x < 8; ++x)
        for (int y = 0; y < 8; ++y)
        {
            switch (obj_repo->board_[x][y])
            {
                case State::EMPTY:
                    break;
                case State::BLACK:
                    glColor3f(0.5f, 0.5f, 0.9f);
                    glBegin(GL_POLYGON);
                    for (int a = 0; a < 9; ++a)
                    {
                        float xx = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) + (x + 0.5f) * obj_repo->windowWidth / 8;
                        float yy =  obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) + (y + 0.5f) * obj_repo->windowHeight / 8;
                        glVertex2f(xx, yy);
                    }
                    glEnd();
                    break;
                case State::WHITE:
                    if (obj_repo->mouseX == x && obj_repo->mouseY == y && obj_repo->paintSelectedCell){
                        glColor3f(1.0f, 0.0f, 0.0f);
                        cellColored = true;
                    }
                    else {
                        glColor3f(0.3f, 0.3f, 0.3f);
                    }
                        glBegin(GL_POLYGON);
                    for (int a = 0; a < 9; ++a)
                    {
                        float xx = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) + (x + 0.5f) * obj_repo->windowWidth / 8;
                        float yy =  obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) + (y + 0.5f) * obj_repo->windowHeight / 8;
                        glVertex2f(xx, yy);
                    }
                    glEnd();
                    break;
                case State::WHITE_QUEEN:
                    if (obj_repo->mouseX == x && obj_repo->mouseY == y && obj_repo->paintSelectedCell){
                        glColor3f(1.0f, 0.0f, 0.0f);
                        cellColored = true;
                    }
                    else {
                        glColor3f(1.5f, 0.8f, 1.0f);
                    }
                    glBegin(GL_POLYGON);
                    for (int a = 0; a < 9; ++a)
                    {
                        float xx = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) + (x + 0.5f) * obj_repo->windowWidth / 8;
                        float yy =  obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) + (y + 0.5f) * obj_repo->windowHeight / 8;
                        glVertex2f(xx, yy);
                    }
                    glEnd();
                break;
                case State::BLACK_QUEEN:
                    if (obj_repo->mouseX == x && obj_repo->mouseY == y && obj_repo->paintSelectedCell){
                        glColor3f(1.0f, 0.0f, 0.0f);
                        cellColored = true;
                    }
                    else {
                        glColor3f(0.1f, 0.9f, 0.2f);
                    }
                    glBegin(GL_POLYGON);
                    for (int a = 0; a < 9; ++a)
                    {
                        float xx = obj_repo->windowWidth / 8 / 2 * cos(2 * 3.1415926 * a / 9) + (x + 0.5f) * obj_repo->windowWidth / 8;
                        float yy =  obj_repo->windowHeight / 8 / 2 * sin(2 * 3.1415926 * a / 9) + (y + 0.5f) * obj_repo->windowHeight / 8;
                        glVertex2f(xx, yy);
                    }
                    glEnd();
                    break;
            }

            if(cellColored){
                obj_repo->cellSelected = true;
            }else{
                obj_repo->cellSelected = false;
            }
        }
}
