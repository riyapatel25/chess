#include "piece.h"

class Queen: public Piece {
    public:
    Queen(bool playerWhiteOrBlack);
    virtual void playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};