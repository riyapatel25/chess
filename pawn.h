#include "piece.h"

class Pawn: public Piece {
    public:
    Pawn(int PlayerWhiteOrBlack, string pieceType);
    bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, bool turn) override;
    // bool isCheck (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard) override;


};