#include "GlutConfig.h"
#include "../utils/ScreenFabric.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <random>

using namespace std;
typedef pair<int, int> Pos;
typedef pair<Pos, Pos> Step;
typedef vector<Step> Move;
const char windowName[] = "Warcaby";
ObjectsRepository *repo;

void refresh();
void mouseClick();
void move(int x, int y);
void display();
bool blackMove(int level = 6);
int getRandomNumber(int min, int max);
void mouseClick(int, int, int, int);
void getListOfLegalMoves(Side side, vector<Move> &vector1);
void getListOfLegalMoves_Queen(Side side, vector<Move> &listOfLegalJumps, vector<Move> &listOfLegalMoves);
void findAllJumps(int x, int y, Side side, Move move, vector<Move> &listOfLegalMoves);
void findAllJumps_Queen(int x, int y, Side side, Move move, vector<Move> &listOfLegalJumps, vector<Move> &listOfLegalMoves);

void GlutConfig::basicConfiguration() {
    repo = repository;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(repo->windowWidth, repo->windowHeight);
    glutCreateWindow(windowName);
    glClearColor(0.0, 0.0, 0.0, 1);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, repo->windowWidth, repo->windowHeight, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutIdleFunc(refresh);
    glutMouseFunc(mouseClick);
    glGetIntegerv(GL_VIEWPORT, viewPort);
    glutDisplayFunc(display);
    glutMainLoop();
}


void refresh() {
    glutPostRedisplay();
}

void display() {
    ScreenFabric *screenFabric = new ScreenFabric(repo);
    screenFabric->display();
}

void mouseClick(int buttonPressed, int state, int x, int y) {
    int newClickX = x / (repo->windowWidth / 8);
    int newClickY = y / (repo->windowHeight / 8);
    if (state == 0)
        repo->paintSelectedCell = true;

    if (repo->cellSelected && repo->mouseY == newClickY && repo->mouseX == newClickX) {

    } else if (repo->cellSelected) {
        repo->paintSelectedCell = false;
        move(newClickX, newClickY);
    }

    if (*(repo->viewPage) == INTRO) {
        *(repo->viewPage) = GAME;
    }

    repo->mouseState = state;
    repo->mouseY = newClickY;
    repo->mouseX = newClickX;

}

void move(int x, int y) {
    vector<Move> listOfLegalMoves;
    vector<Move> listOfLegalJumps_Queen;
    vector<Move> listOfLegalMoves_Queen;

    if (repo->board_[repo->mouseX][repo->mouseY] == WHITE_QUEEN) {
        getListOfLegalMoves_Queen(Side::WHITE_SIDE_QUEEN, listOfLegalJumps_Queen, listOfLegalMoves_Queen);
        if (!listOfLegalJumps_Queen.empty()) {
            listOfLegalMoves = listOfLegalJumps_Queen;
        } else {
            listOfLegalMoves = listOfLegalMoves_Queen;
        }
    } else {
        getListOfLegalMoves(Side::WHITE_SIDE, listOfLegalMoves);
    }

    if (listOfLegalMoves.empty()) {
        repo = new ObjectsRepository;
        return;
    }

    Step step = Step(Pos(repo->mouseX, repo->mouseY), Pos(x, y));
    bool moved = false;
    bool queen;

    for (auto const &value1: listOfLegalMoves) {
        for (auto const &value2: value1) {

            pair<int, int> xc = step.first;
            pair<int, int> xs = step.second;
            bool currentStep = step == value2;
            pair<int, int> c = step.first;
            pair<int, int> s = step.second;
            pair<int, int> cc = value2.first;
            pair<int, int> ss = value2.second;
            if (currentStep && (!repo->isAfterJump || (repo->isAfterJump && abs(repo->mouseX - x) == 2))
                    ) {
                moved = true;
                queen = repo->board_[repo->mouseX][repo->mouseY] == WHITE_QUEEN;
                repo->board_[repo->mouseX][repo->mouseY] = EMPTY;
                if (y == 0 || queen) {
                    repo->board_[x][y] = WHITE_QUEEN;
                } else {
                    repo->board_[x][y] = WHITE;
                }

                if (abs(repo->mouseX - x) >= 2) {
                    int dx = repo->mouseX > x ? 1 : -1;
                    int dy = repo->mouseY > y ? 1 : -1;

                    int newX = x + dx, newY = y + dy;
                    for (int i = 0; i < abs(repo->mouseX - x); i++) {
                        repo->board_[newX][newY] = EMPTY;
                        newX += dx;
                        newY += dy;
                    }
                    repo->mouseX = x;
                    repo->mouseY = y;
                    repo->isAfterJump = true;
                } else
                    repo->isAfterJump = false;
                break;
            }
        }
    }

    if (repo->isAfterJump == true) {
        vector<Move> listOfLegalJumps;
        vector<Move> listOfLegalJumps_Q;
        Move move;
        if (queen) {
            findAllJumps_Queen(x, y, WHITE_SIDE_QUEEN, move, listOfLegalJumps_Q,
                               listOfLegalMoves_Queen);
        } else {
            Move move;
            findAllJumps(x, y, WHITE_SIDE, move, listOfLegalJumps);
        }

        if (!listOfLegalJumps.empty() || !listOfLegalJumps_Q.empty()) {
            repo->isAfterJump = false;
            moved = false;
        }
    }
    if (repo->isAfterJump || moved) {
        repo->isAfterJump = false;
        blackMove();
    }
    repo->mouseX = -1;
    repo->mouseY = -1;
}


void getListOfLegalMoves(Side side, vector<Move> &listOfLegalMoves) {
    auto board_ = repo->board_;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (board_[x][y] == static_cast<State>(side)) {
                Move move;
                findAllJumps(x, y, side, move, listOfLegalMoves);
            }
        }
    }

    if (listOfLegalMoves.empty()) {
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (board_[x][y] == static_cast<State>(side)) {
                    int yy = y + ((side == Side::WHITE_SIDE || side == Side::WHITE_SIDE_QUEEN) ? -1 : 1);
                    if (yy >= 0 && yy < 8)
                        for (int xx = x - 1; xx <= x + 1; xx += 2) {
                            if (xx < 0)
                                continue;
                            if (xx >= 8)
                                continue;
                            if (board_[xx][yy] == EMPTY) {
                                Move move;
                                move.push_back(Step(Pos(x, y), Pos(xx, yy)));
                                listOfLegalMoves.push_back(move);
                            }
                        }
                }
            }
        }
    }
}

void findAllJumps(int x, int y, Side side, Move move, vector<Move> &listOfLegalMoves) {
    const int dx[] = {-1, 1, 1, -1};
    const int dy[] = {-1, -1, 1, 1};

    for (int d = 0; d < 4; ++d) {
        const int neighbourX = x + dx[d];
        const int neighbourY = y + dy[d];

        const int jumpX = x + 2 * dx[d];
        const int jumpY = y + 2 * dy[d];

        Side queenSide = side == WHITE_SIDE ? WHITE_SIDE_QUEEN : BLACK_SIDE_QUEEN;

        bool outOfBoard = (neighbourX < 0 || neighbourX >= 8 || neighbourY < 0 || neighbourY >= 8);
        bool emptyOrSamePawn = (repo->board_[neighbourX][neighbourY] == EMPTY ||
                                repo->board_[neighbourX][neighbourY] == static_cast<State>(side) ||
                                repo->board_[neighbourX][neighbourY] == static_cast<State>(queenSide)
        );
        bool attackOutOfRange = (jumpX < 0 || jumpX >= 8 || jumpY < 0 || jumpY >= 8);

        if (outOfBoard || attackOutOfRange || emptyOrSamePawn) {
            continue;
        }

        if (repo->board_[jumpX][jumpY] == EMPTY) {
            bool samePlace = false;

            for (auto const &step: move) {
                if (step.second == Pos(jumpX, jumpY)) {
                    samePlace = true;
                    break;
                }
            }

            if (!samePlace) {
                move.push_back(Step(Pos(x, y), Pos(jumpX, jumpY)));
                listOfLegalMoves.push_back(move);
                findAllJumps(jumpX, jumpY, side, move, listOfLegalMoves);
            }
        }
    }
}

void getListOfLegalMoves_Queen(Side side, vector<Move> &listOfLegalJumps, vector<Move> &listOfLegalMoves) {
    auto board_ = repo->board_;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (board_[x][y] == static_cast<State>(side)) {
                Move move;
                findAllJumps_Queen(x, y, side, move, listOfLegalJumps, listOfLegalMoves);

            }
        }
    }
}

void
findAllJumps_Queen(int x, int y, Side side, Move move, vector<Move> &listOfLegalJumps, vector<Move> &listOfLegalMoves) {

    const int dx[] = {-1, 1, 1, -1};
    const int dy[] = {-1, -1, 1, 1};

    for (int d = 0; d < 4; ++d) {
        int newX = x;
        int newY = y;

        bool outOfBoard = false;
        bool jump = false;
        bool blocked = false;
        while (!outOfBoard && !jump && !blocked) {

            int neighbourX = newX + dx[d];
            int neighbourY = newY + dy[d];

            const int jumpX = newX + 2 * dx[d];
            const int jumpY = newY + 2 * dy[d];

            outOfBoard = (neighbourX < 0 || neighbourX >= 8 || neighbourY < 0 || neighbourY >= 8);

            bool outOfBoard = (neighbourX < 0 || neighbourX >= 8 || neighbourY < 0 || neighbourY >= 8);
            Side sameSide = side == WHITE_SIDE_QUEEN ? WHITE_SIDE : BLACK_SIDE;
            bool emptyOrSamePawn = (repo->board_[neighbourX][neighbourY] == EMPTY ||
                                    repo->board_[neighbourX][neighbourY] == static_cast<State>(side) ||
                                    repo->board_[neighbourX][neighbourY] == static_cast<State>(sameSide)
            );
            bool attackOutOfRange = (jumpX < 0 || jumpX >= 8 || jumpY < 0 || jumpY >= 8);
            bool attackPossible = repo->board_[jumpX][jumpY] == EMPTY;
            blocked = repo->board_[neighbourX][neighbourY] == static_cast<State>(side);

            if (!outOfBoard && repo->board_[neighbourX][neighbourY] == EMPTY) {
                move.push_back(Step(Pos(x, y), Pos(neighbourX, neighbourY)));
                listOfLegalMoves.push_back(move);
            }

            if (!(outOfBoard || attackOutOfRange || emptyOrSamePawn)) {
                if (!attackPossible) {
                    blocked = true;
                    continue;
                }
                jump = true;
                move.clear();
                move.push_back(Step(Pos(x, y), Pos(jumpX, jumpY)));
                listOfLegalJumps.push_back(move);
                for (auto const &value1: listOfLegalJumps) {
                    for (auto const &value2: value1) {
                        pair<int, int> c = value2.first;
                        pair<int, int> s = value2.second;
                    }
                }

                neighbourX = jumpX + dx[d];
                neighbourY = jumpY + dy[d];
                outOfBoard = (neighbourX < 0 || neighbourX >= 8 || neighbourY < 0 || neighbourY >= 8);
                bool empty = repo->board_[neighbourX][neighbourY] == EMPTY;

                while (!outOfBoard && empty) {
                    move.push_back(Step(Pos(x, y), Pos(neighbourX, neighbourY)));
                    listOfLegalJumps.push_back(move);
                    for (auto const &value1: listOfLegalJumps) {
                        for (auto const &value2: value1) {
                            pair<int, int> c = value2.first;
                            pair<int, int> s = value2.second;
                        }
                    }
                    neighbourX = neighbourX + dx[d];
                    neighbourY = neighbourY + dy[d];
                    outOfBoard = (neighbourX < 0 || neighbourX >= 8 || neighbourY < 0 || neighbourY >= 8);
                    empty = repo->board_[neighbourX][neighbourY] == EMPTY;
                }

            }

            newX = neighbourX;
            newY = neighbourY;
        }
    }
}

bool blackMove(int level) {
    bool moved = false;
    vector<Move> listOfLegalMoves;
    vector<Move> listOfLegalJumps_Queen;
    vector<Move> listOfLegalMoves_Queen;

    getListOfLegalMoves_Queen(Side::BLACK_SIDE_QUEEN, listOfLegalJumps_Queen, listOfLegalMoves_Queen);
    if (!listOfLegalJumps_Queen.empty()) {
        listOfLegalMoves = listOfLegalJumps_Queen;
    } else if (!listOfLegalMoves_Queen.empty()) {
        listOfLegalMoves = listOfLegalMoves_Queen;
    } else {
        getListOfLegalMoves(Side::BLACK_SIDE, listOfLegalMoves);
    }

    if (listOfLegalMoves.empty()) {
        repo = new ObjectsRepository;
        return false;
    }
    for (auto const &value1: listOfLegalMoves) {
        for (auto const &value2: value1) {

            pair<int, int> xc = value2.first;
            pair<int, int> xs = value2.second;
        }
    }
    int randomNumber = getRandomNumber(0, listOfLegalMoves.size() - 1);
    Move randomMove = listOfLegalMoves.at(randomNumber);
    Step step = randomMove.at(0);
    Pos pos1 = step.first;
    Pos pos2 = step.second;
    bool queen = repo->board_[pos1.first][pos1.second] == BLACK_QUEEN;
    repo->board_[pos1.first][pos1.second] = EMPTY;

    if (pos2.second == 7 || queen) {
        repo->board_[pos2.first][pos2.second] = BLACK_QUEEN;
    } else {
        repo->board_[pos2.first][pos2.second] = BLACK;
    }

    if (abs(pos2.first - pos1.first) >= 2) {
        int dx = pos1.first > pos2.first ? 1 : -1;
        int dy = pos1.second > pos2.second ? 1 : -1;
        int newX = pos2.first + dx, newY = pos2.second + dy;
        for (int i = 0; i < abs(pos2.first - pos1.first); i++) {
            repo->board_[newX][newY] = EMPTY;
            newX += dx;
            newY += dy;
        }

        vector<Move> listOfLegalJumps;
        vector<Move> listOfLegalJumps_Q;
        getListOfLegalMoves_Queen(Side::BLACK_SIDE_QUEEN, listOfLegalJumps_Q, listOfLegalMoves_Queen);
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (repo->board_[x][y] == static_cast<State>(Side::BLACK_SIDE)) {
                    Move move;
                    findAllJumps(x, y, Side::BLACK_SIDE, move, listOfLegalJumps);
                }
            }
        }

        if (!listOfLegalJumps.empty() || !listOfLegalJumps_Q.empty()) {
            blackMove();
        }
    }
    return true;
}

int getRandomNumber(int min, int max) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(min, max); // distribution in range [1, 6]
    return dist6(rng);
}
