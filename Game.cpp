#include "Game.h"
#include "glutconfigurations/GlutConfig.h"


void Game::runGame(){
glutConfig = new GlutConfig(repository);
glutConfig->basicConfiguration();
}
