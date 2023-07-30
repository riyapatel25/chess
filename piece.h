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
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard) = 0;
    virtual bool canPlayerKill (int row, int col) = 0;
    // bool isCheck (int row, int col, int newRow, int newCol);
    // void getPlayerMove (int row, int col, int newRow, int newCol, const Board& chessBoard);
    virtual ~Piece();
};

#endif
