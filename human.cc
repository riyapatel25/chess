#include "human.h"
#include "piece.h"
#include "board.h"

Human::Human (int color) : Player{color} {}

bool Human::makeMove(int row, int col, int newRow, int newCol, Board& const board) const {
    
    if(board.currBoard[row][col].getPlayerMove(row, col, newRow, newCol, board)){
        board.setTurn(!color); 
        return true;
    } else {
        return false;
    }
}
