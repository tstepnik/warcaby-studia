//
// Created by tomas on 12/01/2022.
//

#ifndef FINALCHECKERS_GAMESCREEN_H
#define FINALCHECKERS_GAMESCREEN_H


#include "../dto/ObjectsRepository.h"

class GameScreen {

public:
    ObjectsRepository *repository;
    void createGameScreen();

    GameScreen(ObjectsRepository *repo) : repository {repo} {}
};


#endif //FINALCHECKERS_GAMESCREEN_H
