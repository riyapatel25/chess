#include "piece.h"

class Rook: public Piece {
    public:
    Rook(int PlayerWhiteOrBlack, string pieceType);
    bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, bool turn) override;
    // virtual bool isCheck (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard) override;

};