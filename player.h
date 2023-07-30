#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "playerMove.h"
#include "piece.h"
class Board;
class Piece;
using namespace std;

// Abstract class definition
class Player {
protected:
    // 0 : black, 1 : white
    int color;
public:
    Player(int color);
    virtual bool makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board) = 0;
    // virtual void levelOne() const = 0;
    // virtual ~Player();
};

#endif
