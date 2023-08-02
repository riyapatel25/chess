#include "piece.h"

class Bishop: public Piece {
    public:
    Bishop(int PlayerWhiteOrBlack, string pieceType);
    bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn, bool vCheck) override;
    bool isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) override;
    vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) override;

};
