#ifndef HUMAN_PLAYER_
#define HUMAN_PLAYER_

#include "player.h"
#include "board.h"

class Human : public Player {
public:
    Human (int color);
<<<<<<< HEAD
    bool makeMove(int row, int col, int newRow, int newCol, vector<vector <Piece*>> board) override;
=======
    bool makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn) override;
    Move makeMove(vector<vector <Piece*>> board, bool turn) override;

>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
};

#endif 
