#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "playerMove.h"
using namespace std;

// Abstract class definition
class player {
public:
    
    virtual void makeMove(string input) const = 0;
    virtual void levelOne() const = 0;
    virtual ~player();
};

#endif
