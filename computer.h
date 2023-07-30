#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include "player.h"
#include "playerMove.h"
#include <vector>

using namespace std;

class Computer : public Player {
    int level;
public:
    Computer(int color, int level);
    Move makeMove(vector<vector <Piece*>> board)  override;
private:
    vector<Move> getAllValidMoves(vector<vector <Piece*>> board);
    Move levelOne(vector<vector <Piece*>> board);
    Move levelTwo(vector<vector <Piece*>> board);
    Move levelThree(vector<vector <Piece*>> board);
    bool isAttacked()
};

#endif
