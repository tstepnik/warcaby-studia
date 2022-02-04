#ifndef FINALCHECKERS_GLUTCONFIG_H
#define FINALCHECKERS_GLUTCONFIG_H

#include <GL/glut.h>
#include "../dto/ObjectsRepository.h"

class GlutConfig {
public:

    ObjectsRepository *repository;
    GLint viewPort[4];
    void basicConfiguration();
    GlutConfig(ObjectsRepository *repo) : repository {repo} {};
};

#endif //FINALCHECKERS_GLUTCONFIG_H
