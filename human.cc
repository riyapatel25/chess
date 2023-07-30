#include "human.h"
#include "piece.h"
#include "board.h"

Human::Human (int color) : Player{color} {}

bool Human::makeMove(int row, int col, int newRow, int newCol,  Board&  board)  {
    
    vector<vector<Piece*>> currBoard = board.getCurrBoard();
    if(currBoard[row][col]->playerMove(row, col, newRow, newCol, board)){
        board.setTurn(!color); 
        return true;
    } else {
        return false;
    }
}
