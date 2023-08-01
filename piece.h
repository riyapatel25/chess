#ifndef PIECE_H
#define PIECE_H
#include "board.h"

class Piece {

protected:
    
    

public:
    int color; 
    string pieceType;
    // pure virtual
    Piece(int color, string pieceType);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, bool turn) = 0;
    virtual bool isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) = 0;
    virtual ~Piece();
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) = 0;
    // bool checkable(const vector<vector<Piece*>>& chessBoard);

};

#endif
