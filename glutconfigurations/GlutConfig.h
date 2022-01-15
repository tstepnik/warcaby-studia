//
// Created by tomas on 11/01/2022.
//

#ifndef FINALCHECKERS_GLUTCONFIG_H
#define FINALCHECKERS_GLUTCONFIG_H

#include <GL/glut.h>
#include "../dto/ObjectsRepository.h"



//typedef std::pair<int, int> Pos;
//typedef std::pair<Pos, Pos> Step;
//typedef std::vector<Step> Move;
class GlutConfig {
public:
    ObjectsRepository *repository;
    GLint viewPort[4];
    void basicConfiguration();
    GlutConfig(ObjectsRepository *repo) : repository {repo} {};


};


#endif //FINALCHECKERS_GLUTCONFIG_H
