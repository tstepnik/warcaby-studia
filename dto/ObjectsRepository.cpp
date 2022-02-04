#include "ObjectsRepository.h"

ObjectsRepository::ObjectsRepository() : viewPage{new ViewPage()}, updateScreen{new bool}, firstConfig{new bool},
                                         isAfterJump{false}, paintSelectedCell{true}, mouseX{0}, mouseY{0} {
    *viewPage = INTRO;
    *updateScreen = true;
    *firstConfig = true;
    for (int x = 0; x < 8; ++x)
        for (int y = 0; y < 8; ++y)
            board_[x][y] = EMPTY;
    for (int y = 0; y < 3; ++y)
        for (int x = (y + 1) % 2; x < 8; x += 2) {
                board_[x][y] = BLACK;
        }
    for (int y = 5; y < 8; ++y)
        for (int x = (y + 1) % 2; x < 8; x += 2) {
            board_[x][y] = WHITE;
        }
}