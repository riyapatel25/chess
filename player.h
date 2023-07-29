#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "playerMove.h"
#include "board.h"
using namespace std;

// Abstract class definition
class Player {
protected:
    // 0 : black, 1 : white
    int color;
public:
    Player(int color);
    virtual bool makeMove(int row, int col, int newRow, int newCol, Board& const board) const = 0;
    virtual void levelOne() const = 0;
    virtual ~Player();
};

#endif
