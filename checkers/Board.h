//
// Created by tomas on 13/01/2022.
//

#ifndef FINALCHECKERS_BOARD_H
#define FINALCHECKERS_BOARD_H


#include "../dto/ObjectsRepository.h"

class Board {
public:

    ObjectsRepository *repository;

    Board(ObjectsRepository *repo) : repository {repo} {}
    void stworzPole(GLint x1, GLint y1);

    void creatBoard();


    void gameCellsInitiation();

    void pierwszaKonfiguracja(int x1, int y1);

    void stworzPionka(int x1, int y1);

};


#endif //FINALCHECKERS_BOARD_H
