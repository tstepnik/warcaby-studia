//
// Created by tomas on 11/01/2022.
//

#ifndef FINALCHECKERS_SCREENOBJECT_H
#define FINALCHECKERS_SCREENOBJECT_H


class ScreenObject {
public:
int minX,maxX,minY,maxY;

ScreenObject(int min_X,int max_X, int min_Y, int max_Y) : minX {min_X}, maxX {max_X}, minY {min_Y}, maxY {max_Y} {}
};


#endif //FINALCHECKERS_SCREENOBJECT_H
