#include <iostream>
#include "Game.h"
#include "dto/ObjectsRepository.h"
#include "utils/ScreenFabric.h"
#include <GL/glut.h>
using namespace std;
void display();

ObjectsRepository *repository;

int main(int argc, char **argv) {
    cout << "MAIN" << endl;
    glutInit(&argc, argv);
    repository = new ObjectsRepository();
    Game *game = new Game(repository);
    game->runGame();



    return 0;
}

