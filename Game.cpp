//
// Created by tomas on 11/01/2022.
//

#include "Game.h"
#include "glutconfigurations/GlutConfig.h"


void Game::runGame(){
glutConfig = new GlutConfig(repository);
glutConfig->basicConfiguration();
}
