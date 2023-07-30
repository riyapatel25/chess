#ifndef __EMPTY_H__
#define __EMPTY_H__
#include "piece.h"

class Empty: public Piece {
    public:
    Empty(int playerWhiteOrBlack);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};
#endif