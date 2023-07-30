#ifndef PIECE_H
#define PIECE_H
#include "board.h"

class Piece {

protected:
    // Black = 0, White = 1, Empty = 2
    int color;
    

public:
    // pure virtual
    Piece(int color);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) = 0;
    virtual bool canPlayerKill (int row, int col) = 0;
    virtual bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard) = 0;
    // void getPlayerMove (int row, int col, int newRow, int newCol, const Board& chessBoard);
    // virtual ~Piece();
};

#endif
