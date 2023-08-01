#ifndef __EMPTY_H__
#define __EMPTY_H__
#include "piece.h"

class Empty: public Piece {
    public:
    Empty(int playerWhiteOrBlack, string pieceType);
    bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard , bool turn) override;
    vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) override;
    bool isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) override;


};
#endif