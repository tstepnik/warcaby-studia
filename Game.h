#ifndef FINALCHECKERS_GAME_H
#define FINALCHECKERS_GAME_H


#include "dto/ObjectsRepository.h"
#include "glutconfigurations/GlutConfig.h"

class Game {

public:
    ObjectsRepository *repository;
    GlutConfig *glutConfig;
    void runGame();
    Game(ObjectsRepository *repo) : repository {repo}{};

};
#endif //FINALCHECKERS_GAME_H
