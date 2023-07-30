#include "piece.h"
#include "playerMove.h"

class Pawn: public Piece {
    public:
    Pawn(bool PlayerWhiteOrBlack, string name);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) override;
    virtual bool isCheck(Move move, vector<vector <Piece*>> board) override;
};