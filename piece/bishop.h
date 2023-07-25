#include "piece.h"

class Bishop: public Piece {
    virtual void playerMove (int row, int col, int newRow, int newCol) override;
    virtual bool canPlayerKill (int row, int col) override;


};