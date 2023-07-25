#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include "player.h"

using namespace std;

class human : player {
    public:
        human(intstring type);
        void makeMove(string input);
};

#endif
