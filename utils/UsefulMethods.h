//
// Created by tomas on 11/01/2022.
//

#ifndef FINALCHECKERS_USEFULMETHODS_H
#define FINALCHECKERS_USEFULMETHODS_H
#include <GL/glut.h>

class UsefulMethods {
public:
    static void displayRasterText(float x, float y, float z, char *stringToDisplay){
        glRasterPos3f(x,y,z);
        for(char* c = stringToDisplay; *c != '\0'; c++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
        }
    }
};


#endif //FINALCHECKERS_USEFULMETHODS_H
