//
// Created by tomas on 11/01/2022.
//

#include "ScreenFabric.h"
#include "../dto/ViewPage.h"
#include "../screens/IntroScreen.h"
#include "../screens/GameScreen.h"
//#include "ViewPage.h"
#include <GL/glut.h>
#include <iostream>

using namespace std;

void ScreenFabric::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    ViewPage *viewPage = repository->viewPage;
        switch (*viewPage) {
            case INTRO:
                IntroScreen introScreen;
                introScreen.createIntroScreen();
                break;
            case GAME:
                GameScreen *gameScreen = new GameScreen(repository);
                gameScreen->createGameScreen();
                break;
        }

    glFlush();
    glLoadIdentity();
    glutSwapBuffers();
}
