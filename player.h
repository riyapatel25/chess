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
    int color;
public:
    Player(int color);
    virtual bool makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn) = 0 ;
    virtual Move makeMove(vector<vector <Piece*>> board, bool turn) = 0 ;
};

#endif
