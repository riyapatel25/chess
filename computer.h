#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include "player.h"

using namespace std;

class Computer : public Player {
public:
    Computer(int color);
    bool makeMove(int row, int col, int newRow, int newCol,  vector<vector<Piece*>>  board)  override;
    // void levelOne();
};

#endif
