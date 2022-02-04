#include "Game.h"
#include "dto/ObjectsRepository.h"
#include <GL/glut.h>
using namespace std;
void display();

ObjectsRepository *repository;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    repository = new ObjectsRepository();
    Game *game = new Game(repository);
    game->runGame();
    return 0;
}

