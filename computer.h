#ifndef COMPUTER_H_
#define COMPUTER_H_
#include <iostream>
#include "player.h"
#include "playerMove.h"
#include <vector>

using namespace std;

class Computer : public Player {
    int level;
public:
    Computer(int color, int level);
    bool makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn) override;
    Move makeMove(vector<vector <Piece*>> board, bool turn) override;


private:
    vector<Move> getAllValidMoves(vector<vector <Piece*>> board, bool turn);
    Move levelOne(vector<vector <Piece*>> board, bool turn);
    Move levelTwo(vector<vector <Piece*>> board, bool turn);
    Move levelThree(vector<vector <Piece*>> board, bool turn);
    bool isAttacked(int row, int col, int currMove, const vector<vector<Piece*>>  board);

};

#endif