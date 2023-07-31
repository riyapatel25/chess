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
<<<<<<< HEAD
    Move makeMove(vector<vector <Piece*>> board)  override;
private:
    vector<Move> getAllValidMoves(vector<vector <Piece*>> board);
    Move levelOne(vector<vector <Piece*>> board);
    Move levelTwo(vector<vector <Piece*>> board);
    Move levelThree(vector<vector <Piece*>> board);
=======
    Move makeMove(vector<vector <Piece*>> board, bool turn)  override;
    bool makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn) override;


private:
    vector<Move> getAllValidMoves(vector<vector <Piece*>> board, bool turn);
    Move levelOne(vector<vector <Piece*>> board, bool turn);
    Move levelTwo(vector<vector <Piece*>> board, bool turn);
    // Move levelThree(vector<vector <Piece*>> board);
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
};

#endif