#include "piece.h"

class Rook: public Piece {
    public:
    Rook(bool PlayerWhiteOrBlack);
    virtual void playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};