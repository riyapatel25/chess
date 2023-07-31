#include "human.h"
#include "piece.h"
#include "board.h"

Human::Human (int color) : Player{color} {}

<<<<<<< HEAD
bool Human::makeMove(int row, int col, int newRow, int newCol,  vector<vector <Piece*>> board)  {
    
    if(board[row][col]->playerMove(row, col, newRow, newCol, board)){
=======
bool Human::makeMove(int row, int col, int newRow, int newCol, vector<vector<Piece*>>  board, bool turn)  {
    
   if(board[row][col]->playerMove(row, col, newRow, newCol, board, turn)){
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
        return true;
    } else {
        return false;
    }
}
Move Human::makeMove(vector<vector <Piece*>> board, bool turn){
    return Move(1,1,1,1);
}
