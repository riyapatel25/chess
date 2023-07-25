#include "piece.h"

class Queen: public Piece {

    virtual void playerMove (int row, int col, int newRow, int newCol) override;
    virtual bool canPlayerKill (int row, int col) override;

};