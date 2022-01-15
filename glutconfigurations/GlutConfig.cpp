//
// Created by tomas on 11/01/2022.
//

#include "GlutConfig.h"
#include "../utils/ScreenFabric.h"
#include "../checkers/Board.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

const char windowName[] = "Warcaby";
ObjectsRepository *repo;

void refresh();

void mouseClick();
void move(int x, int y);
void display();

void mouseClick(int, int, int, int);

//void getListOfLegalMoves(Side side, vector<Move> vector1);

void GlutConfig::basicConfiguration() {
    repo = repository;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(repo->windowWidth, repo->windowHeight);
    glutCreateWindow(windowName);
    glClearColor(0.0, 0.0, 0.0, 1);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluOrtho2D(-windowWidth, windowWidth, -windowHeight, windowHeight);
    glOrtho(0, repo->windowWidth, repo->windowHeight, 0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glutIdleFunc(refresh);
    glutMouseFunc(mouseClick);
    glGetIntegerv(GL_VIEWPORT, viewPort);

    glutDisplayFunc(display);
    glutMainLoop();
}


void refresh() {
    glutPostRedisplay();
}

void display() {
    ScreenFabric *screenFabric = new ScreenFabric(repo);
    screenFabric->display();
}

void mouseClick(int buttonPressed, int state, int x, int y) {
    repo->mouseY = y / (repo->windowHeight / 8);
    repo->mouseX = x / (repo->windowWidth / 8);
    repo->mouseState = state;

    if(repo->cellSelected && repo->mouseY == y && repo->mouseX == x){

    }else{
//        move(repo->mouseX,repo->mouseY);
    }

if (*(repo->viewPage) == INTRO) {
        *(repo->viewPage) = GAME;
    }
}
//
//void move(int x, int y){
//
////    std::vector<Move> listOfLegalMoves;
////    getListOfLegalMoves(Side::WHITE_SIDE, listOfLegalMoves);
//////    if (listOfLegalMoves.empty())
//////    {
//////        *this = Game();
//////        return;
//////    }
////
////    Step step = Step(Pos(repo->mouseX, repo->mouseY), Pos(x, y));
////
////    bool moved = false;
////
////    for (std::vector<Move>::iterator i = listOfLegalMoves.begin(); i != listOfLegalMoves.end(); ++i)
////    {
////        if (step == i->front() && (!repo->isAfterJump || (repo->isAfterJump && abs(repo->mouseX - x) == 2)))
////        {
////            moved = true;
////            repo->board_[repo->mouseX][repo->mouseY] = EMPTY;
////            repo->board_[x][y] = WHITE;
////            if (abs(repo->mouseX - x) == 2)
////            {
////                repo->board_[(repo->mouseX + x) / 2][(repo->mouseY + y) / 2] = EMPTY;
////                repo->mouseX = x;
////                repo->mouseY = y;
////                repo->isAfterJump = true;
////                return;
////            }
////            else
////                repo->isAfterJump = false;
////            break;
////        }
////    }
////
////    if (repo->isAfterJump || moved)
////    {
////        repo->isAfterJump = false;
//////        blackMove();
////    }
////    repo->mouseX = -1;
////    repo->mouseY = -1;
//}


//void getListOfLegalMoves(Side side, std::vector<Move> &lolm)
//{
////    auto board_ = repo->board_;
////    // checking for jump
////    for (int x = 0; x < 8; ++x)
////        for (int y = 0; y < 8; ++y)
////            if (board_[x][y] == static_cast<State>(side))
////            {
////                Move move;
//////                findAllJumps(x, y, side, move, lolm);
////            }
////    // jumping is mandatory
////    if (lolm.empty())
////    {
////        // checking for move
////        for (int x = 0; x < 8; ++x)
////            for (int y = 0; y < 8; ++y)
////                if (board_[x][y] == static_cast<State>(side))
////                {
////                    int yy = y + (side == Side::WHITE_SIDE ? -1 : 1);
////                    if (yy >= 0 && yy < 8)
////                        for (int xx = x - 1; xx <= x + 1; xx += 2)
////                        {
////                            if (xx < 0)
////                                continue;
////                            if (xx >= 8)
////                                continue;
////                            if (board_[xx][yy] == EMPTY)
////                            {
////                                Move move;
////                                move.push_back(Step(Pos(x, y), Pos(xx, yy)));
////                                lolm.push_back(move);
////                            }
////                        }
////                }
////    }
//}




