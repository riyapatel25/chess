#include "piece.h"

class Horse: public Piece {
    public:
    Horse(bool PlayerWhiteOrBlack);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};