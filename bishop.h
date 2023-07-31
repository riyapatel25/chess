#include "piece.h"

class Bishop: public Piece {
    public:
    Bishop(int PlayerWhiteOrBlack, string pieceType);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn) override;
    // virtual bool isCheck (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard) override;

};