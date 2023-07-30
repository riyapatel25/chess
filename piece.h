#ifndef PIECE_H
#define PIECE_H
#include "board.h"
#include "playerMove.h"
#include <vector>

class Piece {

protected:
    bool color;
    string name;

public:
    // pure virtual
    Piece(bool color, string name);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) = 0;
    virtual bool canPlayerKill (int row, int col) = 0;
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) = 0;
    int getColor();
    string getName();
    virtual bool isCheck(Move move, vector<vector <Piece*>> board) = 0;
    // bool isCheck (int row, int col, int newRow, int newCol);
    // void getPlayerMove (int row, int col, int newRow, int newCol, const Board& chessBoard);
    // virtual ~Piece();
};

#endif
