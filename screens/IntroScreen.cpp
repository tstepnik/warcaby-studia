//
// Created by tomas on 11/01/2022.
//

#include "IntroScreen.h"
#include "../utils/UsefulMethods.h"
#include <GL/glut.h>

void IntroScreen::createIntroScreen(){
    int width = 350;
    int height = 120;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    UsefulMethods::displayRasterText(width + 20,height,0,"Start");
    UsefulMethods::displayRasterText(width,height*2,0,"Instrukcja");
    UsefulMethods::displayRasterText(width + 15,height*3,0,"Wyjście");
    glFlush();
    glutSwapBuffers();
}