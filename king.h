#include "piece.h"

class King: public Piece {
    public:
    King(bool playerWhiteOrBlack, string name);
    virtual bool playerMove (int row, int col, int newRow, int newCol,const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) override;
    virtual bool isCheck(Move move, vector<vector <Piece*>> board) override;
};