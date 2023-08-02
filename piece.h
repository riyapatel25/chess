#ifndef PIECE_H
#define PIECE_H
#include "board.h"
#include "playerMove.h"
#include <vector>

class Piece {

protected:
    int color; 
    string pieceType;
public:
    
    Piece(int color, string pieceType);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, bool turn, bool vcheck) = 0;
    virtual bool isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) = 0;
    virtual ~Piece();
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) = 0;
    string getPieceType();
    int getColor();

};

#endif