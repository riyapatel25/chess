#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include "player.h"

using namespace std;

class computer : player {
public:
    void makeMove(string input);
    void levelOne();
};

#endif
