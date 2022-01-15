cmake_minimum_required(VERSION 3.21)
project(FinalCheckers)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        FinalCheckers
        main.cpp
        Game.cpp
        Game.h
        glutconfigurations/GlutConfig.cpp
        glutconfigurations/GlutConfig.h
        dto/ScreenObject.cpp
        dto/ScreenObject.h
        utils/ScreenFabric.cpp
        utils/ScreenFabric.h
        dto/ObjectsRepository.cpp
        dto/ObjectsRepository.h
        dto/ViewPage.cpp
        dto/ViewPage.h
        screens/IntroScreen.cpp
        screens/IntroScreen.h
        utils/UsefulMethods.cpp
        utils/UsefulMethods.h
        screens/GameScreen.cpp
        screens/GameScreen.h
        checkers/Board.cpp
        checkers/Board.h
        dto/GreenCell.cpp
        dto/GreenCell.h
        dto/State.h
)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp)
link_directories(${OPENGL_gl_LIBRARY})
target_link_libraries(FinalCheckers ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})