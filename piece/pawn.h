#include "piece.h"
#include "board.h"

class Pawn: public Piece {

    virtual void playerMove (int row, int col, int newRow, int newCol, Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};