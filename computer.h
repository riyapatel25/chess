#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include "player.h"

using namespace std;

class Computer : Player {
public:
    Computer(int color);
    bool makeMove(string input);
    void levelOne();
};

#endif
