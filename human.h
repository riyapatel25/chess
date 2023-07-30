#ifndef HUMAN_PLAYER_
#define HUMAN_PLAYER_

#include "player.h"
#include "board.h"

class Human : public Player {
public:
    Human (int color);
    bool makeMove(int row, int col, int newRow, int newCol, vector<vector<Piece*>>  board) override;
};

#endif 
