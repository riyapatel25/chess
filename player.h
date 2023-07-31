#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "playerMove.h"
#include "piece.h"
class Board;
class Piece;
using namespace std;

// Abstract class definition
class Player {
protected:
    // 0 : black, 1 : white
    int color;
public:
    Player(int color);
<<<<<<< HEAD
    virtual bool makeMove(int row, int col, int newRow, int newCol,  vector<vector <Piece*>> board) = 0;
    virtual Move makeMove(vector<vector <Piece*>> board) = 0;
=======
    virtual bool makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn);
    // virtual void levelOne() const ;
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
    // virtual ~Player();
    virtual Move makeMove(vector<vector <Piece*>> board, bool turn);
};

#endif
