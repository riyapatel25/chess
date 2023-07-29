#include "piece.h"
#include "board.h"

class Rook: public Piece {
    Rook(bool PlayerWhiteOrBlack);
    virtual void playerMove (int row, int col, int newRow, int newCol, Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};