//
// Created by tomas on 11/01/2022.
//

#ifndef FINALCHECKERS_SCREENFABRIC_H
#define FINALCHECKERS_SCREENFABRIC_H


#include "../dto/ObjectsRepository.h"
#include "../dto/ViewPage.h"
#include <GL/glut.h>
#include <GL/gl.h>
class ScreenFabric {
public:
    ObjectsRepository *repository;
    void display();
    ScreenFabric(ObjectsRepository *repo): repository{repo} {};
};


#endif //FINALCHECKERS_SCREENFABRIC_H
