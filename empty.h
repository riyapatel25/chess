#ifndef __EMPTY_H__
#define __EMPTY_H__
#include "piece.h"

class Empty: public Piece {
    public:
    Empty(int playerWhiteOrBlack, string pieceType);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard , bool turn) override;

};
#endif