#include "human.h"
#include "piece.h"
#include "board.h"

Human::Human (int color) : Player{color} {}

bool Human::makeMove(int row, int col, int newRow, int newCol, vector<vector<Piece*>>  board, bool turn)  {
    
   if(board[row][col]->playerMove(row, col, newRow, newCol, board, turn)){
        return true;
    } else {
        return false;
    }
}
Move Human::makeMove(vector<vector <Piece*>> board, bool turn){
    return Move(1,1,1,1);
}
