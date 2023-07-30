#include "piece.h"

class Horse: public Piece {
    public:
    Horse(bool PlayerWhiteOrBlack, string pieceType);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;

};