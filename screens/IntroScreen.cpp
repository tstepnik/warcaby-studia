//
// Created by tomas on 11/01/2022.
//

#include "IntroScreen.h"
#include "../utils/UsefulMethods.h"
#include <GL/glut.h>

void IntroScreen::createIntroScreen(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    UsefulMethods::displayRasterText(250,300,0,"Wcisnij Enter by rozpoczac");
    glFlush();
    glutSwapBuffers();
}