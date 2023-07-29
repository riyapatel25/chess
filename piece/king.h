#include "piece.h"

class King: public Piece {
    public:
    King(bool playerWhiteOrBlack);
    virtual bool playerMove (int row, int col, int newRow, int newCol,const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};