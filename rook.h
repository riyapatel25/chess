#include "piece.h"

class Rook: public Piece {
    public:
    Rook(int PlayerWhiteOrBlack);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;
    virtual bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard) override;

};