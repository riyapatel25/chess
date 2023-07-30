#include "human.h"
#include "piece.h"
#include "board.h"

Human::Human (int color) : Player{color} {}

bool Human::makeMove(int row, int col, int newRow, int newCol,  vector<vector <Piece*>> board)  {
    
    if(board[row][col]->playerMove(row, col, newRow, newCol, board)){
        return true;
    } else {
        return false;
    }
}
