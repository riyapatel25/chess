#include "piece.h"

class Horse: public Piece {

    Horse(bool PlayerWhiteOrBlack);
    virtual void playerMove (int row, int col, int newRow, int newCol) override;
    virtual bool canPlayerKill (int row, int col) override;

};