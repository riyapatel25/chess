#include "piece.h"
#include "playerMove.h"

class Pawn: public Piece {
    protected:
    bool hasMovedBefore;
    public:
    // setting default, so no additional bool param needs to be passed when constructing Pawn
    Pawn(int PlayerWhiteOrBlack, string pieceType, bool hasMovedBefore = false);
    bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, bool turn) override;
    bool isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) override;
    vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) override;

};


	