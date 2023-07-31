#ifndef PIECE_H
#define PIECE_H
#include "board.h"
#include "playerMove.h"
#include <vector>

class Piece {

protected:
<<<<<<< HEAD
    bool color;
    string name;
=======
    
    
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

public:
    int color; 
    string pieceType;
    // pure virtual
<<<<<<< HEAD
    Piece(bool color, string name);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) = 0;
    virtual bool canPlayerKill (int row, int col) = 0;
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) = 0;
    int getColor();
    string getName();
    virtual bool isCheck(Move move, vector<vector <Piece*>> board) = 0;
    bool isAttacked(int row, int col, int currMove);

    // bool isCheck (int row, int col, int newRow, int newCol);
    // void getPlayerMove (int row, int col, int newRow, int newCol, const Board& chessBoard);
    // virtual ~Piece();
=======
    Piece(int color, string pieceType);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, bool turn) = 0;
    // virtual bool isCheck (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard) = 0;
    virtual ~Piece();
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) = 0;

>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
};

#endif
