#include "piece.h"

class Pawn: public Piece {
    public:
    Pawn(bool PlayerWhiteOrBlack);
    virtual void playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};