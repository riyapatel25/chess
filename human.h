#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include "player.h"

using namespace std;

class human : player {
    public:
        human(string turn);
        void makeMove(string input);
        void levelOne();
};

#endif
